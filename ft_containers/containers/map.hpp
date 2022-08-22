#ifndef MAP_HPP
# define MAP_HPP
#include<functional>
#include "pair.hpp"
#include "node.hpp"
#include <memory>

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
            typedef Node<const key_type, mapped_type> node;
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
            
        protected:
            typedef typename Alloc::template rebind<Node<const key_type, mapped_type>>::other node_alloc_type;
            size_type _size;
            key_compare _compare;
            value_compare _compval;
            node_alloc_type _node_alloc;
            struct red_black_tree *node;
            Node *_root = node->root;
            Node *_nil = node->nil;
            allocator_type _alloc;
            
            Node *_min(Node *x)
            {
                while (x->left != _nil)
                {
                    x = x->left;
                }
                return (x);
            }
            Node *_max(Node *x)
            {
                while (x->right != _nil)
                {
                    x = x->right;
                }
                return (x);
            }
            void left_rotate(Node *x)
            {
                Node *y = x->right;
                x->right = y->left;
                if (y->left != _nil)
                {
                    y->left->parent = x;
                }
                y->parent = x->parent;
                if (x->parent == _nil)
                    _root = y;
                else if (x == x->parent->left)
                {
                    x->parent->left = y;
                }
                else
                {
                    x->parent->right = y;
                }
                y->left = x;
                x->parent = y;
            }
            void right_rotate(Node *x)
            {
                Node *y = x->left;
                x->left = y->right;
                if (y->right != _nil)
                {
                    y->right->parent = x;
                }
                y->parent = x->parent;
                if (x->parent == _nil)
                    _root = y;
                else if (x == x->parent->right)
                {
                    x->parent->right = y;
                }
                else
                {
                    x->parent->left = y;
                }
                y->right = x;
                x->parent = y;
            }
            Node *_find(Node *x, value_type val)
            {
               if (x == -nil || (!_compval(*(x->data), val) && !_compval(val, *(x->data))))
               {
                    return (x);
               }
               if (_compval(val, *(x->data)))
                    return (_find(x->left, val));
                else
                    return (_find(x->right, val));
            }
            void _insert(Node *z)
            {
                Node *y = _nil;
                Node *x = _root;
                while (x != _nil)
                {
                    y = x;
                    if (_compval(*(z->data), *(x->data)))
                        x = x->left;
                    else
                        x = x->right;
                }
                z->parent = y;
                if (y == _nil)
                {
                    _root = z;
                }
                else if(_compval(*(z->data), *(y->data)))
                    y->left = z;
                else
                    y->right = z;
                z->left = _nil;
                z->right = _nil;
                z->color = RED;
                _insert_fixup(z);
            }
        void insert_fixup(Node *z)
        {
            Node *y;

            while (z->parent->color == RED)
            {
                if (z->parent = z->parent->parent->left)
                {
                    y = z->parent->parent->right;
                    if (y->color == RED)
                    {
                        z->parent->color = BLACK;
                        y->color = BLACK:
                        z->parent->parent = color = RED;
                        z = z->parent->parent;
                    }
                    else if (z == z->parent->right)
                    {
                        z = z->parent;
                        left_rotate(z);
                    }
                    z->parent->color = BLACK:
                    z->parent->parent->color = RED;
                    right_rotate(z->parent->parent);
                }
                else
                {
                    y = z->parent->parent->left;
                    if (y->color == RED)
                    {
                        z->parent->color = BLACK;
                        y->color = BLACK:
                        z->parent->parent = color = RED;
                        z = z->parent->parent;
                    }
                    else if (z == z->parent->left)
                    {
                        z = z->parent;
                        left_rotate(z);
                    }
                    z->parent->color = BLACK:
                    z->parent->parent->color = RED;
                    right_rotate(z->parent->parent);
                }
            }
            _root.color = BLACK:
        }
    };
    
}

#endif