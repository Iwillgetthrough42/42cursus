#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
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
            _capacity(0), alloc(_alloc)
            {
                _vector = _alloc.allocate(_capacity);
            }
            explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()) : _alloc(alloc),
            _size(n), _capacity(n)
            {
                _vector = _alloc.allocate(_capacity);
                for(int i = 0; i < _size; i++)
                {
                    _alloc.construct(&_vector[i], val);
                }
            }
            template <class InputIterator>
            vector (ft::enable_if<!ft::is_integral<InputIterator>, InputIterator> first,\
            ft::enable_if<!ft::is_integral<InputIterator>, InputIterator> last,
            const allocator_type& alloc = allocator_type()) : _size(last - first),\
            _capacity(last - first), _alloc(alloc)
            {
                if (size <= 0)
                    return ;
                _vector = _alloc.allocate(_capacity);
                for ( InputIterator i = first; i < last; i++)
                {
                    _alloc.construct(&_vec[i], *i);
                }
            }
            virtual ~vector()
		    {
			    for (size_type i = 0; i < _size; ++i) { _alloc.destroy(&_vector[i]); }
			    _alloc.deallocate(_vector, _capacity);
		    }
            vector (const vector& x) : _size(x._size), _capacity(s._capacity),
            _alloc(x._alloc) 
            {
                _vector = _alloc.allocate(_capacity);
                pointer other = x._vector;
                for(size_type i = 0 ; i < _size; i++)
                {
                    _alloc.construct(&vector[i], other[i]);
                }
            }
            iterator beigin()
            {
                return (iterator(_vector));
            }
            const_iterator begin() const
            {
                return (const_iterator(_vector));
            }
            iterator end()
            {
                return(iterator(_vector + _size));
            }
            const_iterator end() const
            {
                return (const_iterator(_vector + _size));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(_vector + _size));
            }
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(_vector + _size));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(_vector));
            }
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(_vector));
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

            }
            size_type capacity() const
            {
                return (_capacity);
            }
            
        private:
            pointer _vector;
            allocator_type _alloc;
            size_type _size;
            size_type _capacity;

    };
}

# endif