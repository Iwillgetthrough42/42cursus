#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "type_traits.hpp"
#include "algorithm.hpp"
namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::random_access_iterator<value_type> iterator;
            typedef typename ft::random_access_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;

            explicit vector (const allocator_type& alloc = allocator_type()) : _size(0),
            _capacity(0), _alloc(alloc)
            {
                _data = _alloc.allocate(_capacity);
            }
            explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()) : _alloc(alloc),
            _size(n), _capacity(n)
            {
                _data = _alloc.allocate(_capacity);
                for(int i = 0; i < _size; i++)
                {
                    _alloc.construct(&_data[i], val);
                }
            }
            template <class InputIterator>
            vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,\
            InputIterator last,
            const allocator_type& alloc = allocator_type()) : _size(last - first),\
            _capacity(last - first), _alloc(alloc)
            {
                if (_size <= 0)
                    return ;
                _data = _alloc.allocate(_capacity);
                size_type j = 0;
                for ( InputIterator i = first; i < last; i++)
                {
                    _alloc.construct(&_data[j++], *i);
                }
            }
            virtual ~vector()
		    {
			    for (size_type i = 0; i < _size; ++i) { _alloc.destroy(&_data[i]); }
			    _alloc.deallocate(_data, _capacity);
		    }
            vector (const vector& x) : _size(x._size), _capacity(x._capacity),\
            _alloc(x._alloc) 
            {
                _data = _alloc.allocate(_capacity);
                pointer other = x._data;
                for(size_type i = 0 ; i < _size; i++)
                {
                    _alloc.construct(&_data[i], other[i]);
                }
            }
            vector& operator= (const vector& x)
            {
                if (this != &x)
                {
                    this->assign(x.begin(), x.end());
                }
                return (*this);
            }
            iterator begin()
            {
                return (iterator(_data));
            }
            const_iterator begin() const
            {
                return (const_iterator(_data));
            }
            iterator end()
            {
                return(iterator(_data + _size));
            }
            const_iterator end() const
            {
                return (const_iterator(_data + _size));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(_data + _size));
            }
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(_data + _size));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(_data));
            }
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(_data));
            }
            size_type size() const
            {
                return (_size);
            }
            size_type max_size() const
            {
                return (_alloc.max_size());
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    for (size_type i = n; i < _size; i++)
                    {
                        _alloc.destroy(&_data[i]);
                    }
                    _size = n;
                }
                else if (n > _capacity)
                {
                    reallocate(n);
                }
                if (n > _size)
                {
                    for (size_type i = _size; i < n; i++)
                    {
                        _alloc.construct(&_data[i], val);
                    }
                    _size = n;
                }
            }
            size_type capacity() const
            {
                return (_capacity);
            }
            bool empty() const
            {
                return (_size==0);
            }
            void reserve(size_type n)
            {
                if ( n > this->max_size())
                    throw std::length_error("greater then max_size");
                if (n > _capacity)
                {
                    reallocate(n);
                }
            }
            reference operator[] (size_type n)
            {
                return (_data[n]);
            }
            const_reference operator[] (size_type n) const
            {
                return (_data[n]);
            }
            reference at (size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("out of range");
                return(_data[n]);
            }
            const_reference at(size_type n) const
            {
                if (n >= _size)
                    throw std::out_of_range("out of range");
                return(_data[n]);
            }
            reference front()
            {
                return (*_data);
            }
            const_reference front() const
            {
                return (*_data);
            }
            reference back()
            {
                return (_data[_size - 1]);
            }
            const_reference back() const
            {
                return (_data[_size - 1]);
            }
            template <class InputIterator>
            void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,\
            InputIterator last)
            {
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.destroy(&_data[i]);
                }
                if (last - first > _capacity)
                {
                    pointer tmp = _alloc.allocate(last - first);
                    _alloc.deallocate(_data, _capacity);
                    _data = tmp;
                    _capacity = last - first;
                }
                size_type i = 0;
                for (; first != last; first++)
                {
                    _alloc.construct(&_data[i], *first);
                    i++;
                }
                _size = i;
            }
            void assign (size_type n, const value_type& val)
            {
                 for (size_type i = 0; i < _size; i++)
                {
                    _alloc.destroy(&_data[i]);
                }
                if ( n > _capacity)
                {
                     pointer tmp = _alloc.allocate(n);
                    _alloc.deallocate(_data, _capacity);
                    _data = tmp;
                    _capacity = n;
                }
                for (size_type i = 0; i < n; i++)
                {
                    _alloc.construct(&_data[i], val);
                }
                _size = n;
            }
            void push_back (const value_type& val)
            {
                if (_size + 1 > _capacity)
                {
                    _capacity == 0 ? reallocate(1) : reallocate(_capacity * 2);
                }
                _alloc.construct(&_data[_size++], val);
            }
            void pop_back()
            {
                if (_size)
                    _alloc.destroy(&_data[--_size]);
            }
            iterator insert (iterator position, const value_type& val)
            {
                difference_type diff = this->end() - position;
                if (_size + 1 > _capacity)
                    _capacity == 0? reallocate(1) : reallocate(_capacity * 2);
                size_type cnt = _size;
                while (diff--)
                {
                    _alloc.construct(&_data[cnt], _data[cnt - 1]);
                    _alloc.destroy(&_data[cnt - 1]);
                    cnt--;
                }
                _alloc.construct(&_data[cnt], val);
                ++_size;
                return (iterator(&_data[cnt]));
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                difference_type diff = this->end() - position;
                if (_size + n > _capacity)
                   reallocate(_capacity + n);
                size_type cnt = _size + n - 1;
                while (diff--)
                {
                    _alloc.construct(&_data[cnt], _data[cnt - n]);
                    _alloc.destroy(&_data[cnt - n]);
                    cnt--;
                }
                while (n--)
                {
                    _alloc.construct(&_data[cnt--], val);
                    ++_size;
                }
            }
            template <class InputIterator>
            void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,\
            InputIterator last)
            {
                difference_type diff = this->end() - position;
                difference_type range = last - first;
                if (_size + range > _capacity)
                   reallocate(_capacity + range);
                size_type cnt = _size + range - 1;
                while (diff--)
                {
                    _alloc.construct(&_data[cnt], _data[cnt - range]);
                    _alloc.destroy(&_data[cnt - range]);
                    cnt--;
                }
                while (first != last)
                {
                    _alloc.construct(&_data[cnt--], *first);
                    ++_size;
                    first++;
                }
            }
            iterator erase (iterator position)
            {
                iterator temp(position);
                _alloc.destroy(&(*position));
                while (position != this->end() - 1)
                {
                    *position = *(position + 1);
                    position++;
                }
                _size--;
                return (temp);
            }
            iterator erase(iterator first, iterator last)
            {
                difference_type diff = last - first;
                while (diff--)
                {
                    erase(first);
                }
                return (iterator(last));
            }
            void clear()
            {
                for (size_type i = 0; i < this->size(); i++)
                {
                    _alloc.destroy(&_data[i]);
                }
                _size = 0;
            }
            void swap (vector& x)
            {
                vector tmp = x;
                x = *this;
                *this = tmp;
            }
            allocator_type get_allocator() const
            {
                return (_alloc);
            }
        private:
            pointer _data;
            allocator_type _alloc;
            size_type _size;
            size_type _capacity;

            void reallocate(size_type new_capacity)
            {
                pointer tmp = _alloc.allocate(new_capacity);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(&tmp[i], _data[i]);
                }
                this->~vector();
                _capacity = new_capacity;
                _data = tmp;
            }

    };
    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        return (ft::equal(lhs.begin(), lhs.end(),rhs.begin()));
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }	
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        vector<T,Alloc> tmp = x;
        x = y;
        y = tmp;  
    }
};

# endif
