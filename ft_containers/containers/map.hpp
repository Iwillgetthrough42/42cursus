#ifndef MAP_HPP
# define MAP_HPP
#include<functional>
#include "pair.hpp"
#include "node.hpp"

namespace ft
{
    template < class Key,                                     
    class T,                                      
    class Compare = std::less<Key>,         
    class Alloc = std::allocator<pair<const Key,T> >
    > class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef typename ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            class value_compare:std::binary_function<value_type,value_type,bool>
            {  
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
            typedef typename allocator_type::reference referenece;
            typedef typename allocator_type::const_reference const_referenece;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::rb_tree_iterator<value_type> iterator;
            typedef typename ft::rb_tree_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;
            
            explicit map (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()) : \
                _compare(comp), _alloc(alloc), _node_alloc(alloc), _root(NULL), _size(0)
            {

            }
            
        private:
            typedef typename Alloc::template rebind<Node<const key_type, mapped_type>>::other node_alloc_type;
            size_type _size;
            key_compare _compare;
            node_alloc_type _node_alloc;
            Node<key_type, value_type>* _root;
            allocator_type _alloc;

    };
    
}

#endif