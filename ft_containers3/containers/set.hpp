#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include <memory>
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator.hpp"
#include "node.hpp"
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
        typedef typename ft::Node<value_type> node;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::map_iterator<value_type, node> iterator;
        typedef typename ft::map_iterator<const value_type, node> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef size_t size_type;

        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        {
            this->_alloc = alloc;
            this->_comp = comp;
        }
        template <class InputIterator>  set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),\
         const allocator_type& alloc = allocator_type())
         {
            this->insert(first, last);
         }
         set (const set& x) : _compare(x._compare), _alloc(x._alloc)
         {
            this-.insert(x.begin(), x.end());
         }
         ~set()
         {

         }
        set& operator= (const set& x)
        {

        }
        iterator begin()
        {
            return (tree.begin());
        }
        const_iterator begin() const
        {
            return (const_iterator(tree.begin()));
        }
        iterator end()
        {
            return (tree.end());
        }
        const_iterator end() const
        {
            return const_iiterator(tree.end());
        }
        reverse_iterator rbegin()
        {
            return (tree.rbegin());
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(tree.rbegin()));
        }
        reverse_iterator rend()
        {
            return (tree.rend());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(tree.rend());
        }
        bool empty() const
        {
            return (tree.size() == 0);
        }
        size_type size() const
        {
            return (tree.size());
        }
        size_type max_size() const
        {
            return (tree.max_size());
        }
        pair<iterator,bool> insert (const value_type& val)
        {
            
        }
        protected:
            key_compare _comp;
            allocator_type _alloc;
            ft::red_black_tree<value_type, \
            key_compare, allocator_type> tree;
    };
}

# endif