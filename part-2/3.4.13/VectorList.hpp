#include <vector>
#include <list>
#include <iterator>

template<class T>
class VectorList {
private:
    using VectT  = std::vector<T>;
    using ListT = std::list<VectT>;
    using BaseIt = std::iterator<std::bidirectional_iterator_tag, VectorList, std::ptrdiff_t, T const *, T const &>;
    ListT data_;
public:
    using value_type = T;
    template<class It>
    void append(It p, It q) {
        if (p != q)
            data_.push_back(VectT(p, q));
    }
    bool empty() const { return size() == 0; } 
    size_t size() const {
        size_t s = 0;
        for (auto const & v : data_)
            s += v.size();
        return s; 
    }
    class const_iterator : public BaseIt {
    public:
        const_iterator() = default;
        const_iterator(const_iterator const &) = default;
        const_iterator(ListT const & data, bool beg) : data_(&data) {
            if (!data.empty())
                if (beg) {
                    _node = data_->begin();
                    _i = _node->cbegin();
                } else {
                    _node = std::prev(data_->cend());
                    _i = _node->cend();
                }
        }
        typename BaseIt::pointer operator->() const {
            return &(*_i);
        }
        typename BaseIt::reference operator*() const {
            return *_i;
        }
        bool operator==(const const_iterator & it) const {
            return data_ == it.data_ && _node == it._node && _i == it._i;
        }
        bool operator!=(const const_iterator & it) const {
            return !(*this == it);
        }
        const_iterator& operator++() {
            if (++_i == _node->cend())
                if (++_node == data_->cend())
                    *this = const_iterator(*data_, false);
                else
                    _i = _node->cbegin();
            return *this;
        }
        const_iterator operator++(int) {
            auto it = *this;
            ++(*this);
            return it;
        }
        const_iterator& operator--() {
            if (_i-- == _node->cbegin())
                if (_node-- == data_->cbegin())
                    *this = const_iterator(*data_, true);
                else 
                    _i = std::prev(_node->cend());
            return *this;
        }
        const_iterator operator--(int) {
            auto it = *this;
            --(*this);
            return it;
        }
    private:
        ListT const * data_;
        typename ListT::const_iterator _node;
        typename VectT::const_iterator _i;
    };
    const_iterator begin() const { 
        return const_iterator(data_, true); 
    }
    const_iterator end() const { 
        return const_iterator(data_, false); 
    }
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    const_reverse_iterator rbegin() const { 
        return const_reverse_iterator(end()); 
    }
    const_reverse_iterator rend() const { 
        return const_reverse_iterator(begin()); 
    }
};