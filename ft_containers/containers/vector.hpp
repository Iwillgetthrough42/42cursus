#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>
#include "random_access_iterator.hpp"

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
            typedef typename ft::reverse_iterator<const iterator> reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;

            explicit vector (const allocator_type& alloc = allocator_type())
            {
                
            }
        private:
            pointer _vector;
            allocator_type _alloc;
            size_type size;
            size_type capacity;

    };
}

# endif