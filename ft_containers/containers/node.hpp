#ifndef NODE_HPP
# define NODE_HPP
#include "pair.hpp"
#include "map.hpp"
#include <memory>


enum COLOR {RED, BLACK};

namespace ft
{
    template <class T1, class T2>
    struct Node
    {
        typedef typename ft::pair<T1, T2>* pointer;
        enum COLOR color;
        typedef Node* Node_pointer;
        typedef Node& Node_reference;
        struct Node *left;
        struct Node *right;
        struct Node *parent;
        pointer data;
    };
    template < class Key,                                     
    class T,                                      
    class Compare = std::less<Key>,         
    class Alloc = std::allocator<ft::pair<const Key,T> > >
    class red_black_tree
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef typename ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename ft::Node<const key_type, mapped_type> node;
            class value_compare:std::binary_function<value_type,value_type,bool>
            {  
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}
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
            typedef typename ft::map_iterator<value_type> iterator;
            typedef typename ft::map_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;
            typedef typename Alloc::template rebind<Node<const key_type, mapped_type> >::other node_alloc;


            red_black_tree() : _compare(key_compare()), _size(0)
            {
                node *nil = _node_alloc.allocate(1);
                nil->left = NULL;
                nil->right = NULL;
                nil->parent = NULL;
                nil->data = NULL;
                nil->color = BLACK;
                _nil = nil;
                _root = _nil;
            }

            ~red_black_tree()
            {
                delete_tree(_root);
                _node_alloc.destroy(_nil);
                _node.deallocate(_nil, 1);
            }

            iterator begin()
            {
                return (iterator(_min(_root), _nil));
            }
            const_iterator begin() const
            {
                return (const_iterator(_min(_root), _nil))
            }
            iterator end()
            {
                return (iterator(_nil, _nil));
            }
            const_iterator end() const
            {
                return (const_iterator(_nil, _nil));
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(this->end());
            }
            const_reverse_iterator rbegin() const
            {
                return reverse_iterator(this->end());
            }
        protected:
            size_type _size;
            key_compare _compare;
            value_compare _compval;
            node_alloc _node_alloc;
            allocator_type _alloc;
            node *_root;
            node *_nil;

            void delete_tree()
            {
                if (_root == NULL)
                    return ;
                else if (_root->left)
                    delete_tree(_root->left);
                else if (_root->right)
                    delete_tree(_root->right);
                _alloc.destroy(_root->data);
                _alloc.deallocate(_root->data, 1);
                _node_alloc.destroy(_root);
                _node_alloc.deallocate(_root, 1);
            }

            node *_createnode(const value_type &val)
            {       
                node *x;
                
                x = _node_alloc.allocate(1);
                x->left = NULL;
                x->right = NULL;
                x->parent = NULL;
                _node_alloc.construct(x->data, &val);
                return (x);
            }   
            node *_min(node *x)
            {
                while (x->left != _nil)
                {
                    x = x->left;
                }
                return (x);
            }
            node *_max(node *x)
            {
                while (x->right != _nil)
                {
                    x = x->right;
                }
                return (x);
            }
            void left_rotate(node *x)
            {
                node *y = x->right;
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
            void right_rotate(node *x)
            {
                node *y = x->left;
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
            node *_find(node *x, value_type val)
            {
                if (x == _nil || (!_compval(*(x->data), val) && !_compval(val, *(x->data))))
                {
                    return (x);
                }
                if (_compval(val, *(x->data)))
                    return (_find(x->left, val));
                else
                    return (_find(x->right, val));
            }
            ft_pair<iterator, bool> _insert(node *z)
            {
                node *y = _nil;
                node *x = _root;
                node *found;

                if (found = _find(_root,z) != _nil)
                    return (ft::make_pair(iterator(found), false));
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
                return ft::make_pair(iterator(z), true);
            }
            void insert_fixup(node *z)
            {
                node *y;

                while (z->parent->color == RED)
                {
                    if (z->parent = z->parent->parent->left)
                    {
                        y = z->parent->parent->right;
                        if (y->color == RED)
                        {
                            z->parent->color = BLACK;
                            y->color = BLACK:
                            z->parent->parent->color = RED;
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
            _   root.color = BLACK:
            }
            void transplant(node *u, node *v)
            {
                if (u->parent == _nil)
                    _root = v;
                else if (u == u->parent->left)
                    u->parent->left = v;
                else
                    u->parent->right = v;
                v->parent = u->parent;
            }
            void _delete(node *z)
            {
                node *y;
                node *x;
                int color;

                y = z;
                color = y->color;
                if (z->left == _nil)
                {
                    x = z->right;
                    transplant(z, x);
                }
                else if (z->right == _nil)
                {
                    x = z->left;
                    transplant(z, x);
                }
                else
                {
                    y = _min(z->right);
                    color = y->color;
                    x = y->right;
                    if (y->parent == z)
                        x->parent = y;
                    else
                    {
                        transplant(y, y->right);
                        y->right = z->right;
                        y->right->parent = y;
                    }
                    transplant(z, y);
                    y->left  = z->left;
                    y->left->parent = y;
                    y->color = z->color;
                }
                if (color == BLACK)
                    delete_fixup(x);

            }
            void delete_fixup(node *x)
            {
                node *w;

                while (x != _root && x->color == BLACK)
                {
                    if (x == x->parent->left)
                    {
                        w  = x->parent->right;
                        if (w->color == RED)
                        {
                            w->color = BLACK;
                            x->parent->color = RED;
                            left_rotate(x->parent);
                            w = x->parent->right;
                        }
                        if (w->left->color == BLACK &&\
                            w->right->color == BLACK)
                        {
                            w->color = RED;
                            x = x->parent;
                        }
                        else if(w->right->color == BLACK)
                        {
                            w->left->color = BLACK;
                            w->color = RED:
                            right_rotate(w);
                            w = x->parent->right;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->right->color = BLACK:
                        left_rotate(x->parent);
                        x = _root;
                    }
                    else
                    {
                        w  = x->parent->left;
                        if (w->color == RED)
                        {
                            w->color = BLACK;
                            x->parent->color = RED;
                            right_rotate(x->parent);
                            w = x->parent->left;
                        }
                        if (w->right->color == BLACK &&\
                            w->left->color == BLACK)
                        {
                            w->color = RED;
                            x = x->parent;
                        }
                        else if(w->left->color == BLACK)
                        {
                            w->right->color = BLACK;
                            w->color = RED:
                            right_rotate(w);
                            w = x->parent->left;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->left->color = BLACK:
                        left_rotate(x->parent);
                        x = _root; 
                    }
                }
                x->color = BLACK;
            }
    };

};





#endif