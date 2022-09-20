#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include <memory>
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator.hpp"
#include "rbt.hpp"

namespace ft
{
    template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set
    {
        typedef T key_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::map_terator<value_type> iterator;
        typedef typename ft::map_terator<const value_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef size_t size_type;

        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        {
            
        }
        protected:
            key_compare _comp;
            allocator_type _alloc;
            ft::red_black_tree<key_type, value_type, \
            key_compare, allocator_type> tree;
    };
}

# endif