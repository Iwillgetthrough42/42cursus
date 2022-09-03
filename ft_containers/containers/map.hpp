#ifndef MAP_HPP
# define MAP_HPP
#include<functional>
#include "pair.hpp"
#include "node.hpp"
#include <memory>
#include <stdexcept>

namespace ft
{
    template < class Key,                                     
    class T,                                      
    class Compare = std::less<Key>,         
    class Alloc = std::allocator<ft::pair<const Key,T> >
    > class map
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
            typedef typename ft::map_iterator<value_type> iterator;
            typedef typename ft::map_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;
            typedef typename allocator_type::template rebind<node>::other node_alloc_type;
            
            explicit map (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()) : \
                _compare(comp), _alloc(alloc), _node_alloc(alloc), _root(NULL), _size(0)
            {

            }
            template <class InputIterator>
            map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) : _compare(comp), _alloc(alloc), _node_alloc(alloc)\
            _size(0)
            {
                this->insert(first, last);
            }
            map (const map& x) _compare(x._compare), _alloc(x._alloc), _node_alloc(x._node_alloc), _size(0)
            {
                this->insert(x.begin(), x.end());
            }
            map& operator= (const map& x) : _compare(x._compare), _alloc(x._alloc), _node_alloc(x._node_alloc), _size(0)
            {
                this->insert(x.begin(), x.end());
                return (*this);
            }

            pair<iterator,bool> insert (const value_type& val)
            {
                return (tree.insert(val));
            }
            iterator insert (iterator position, const value_type& val)
            {
                return (tree.insert(position, val));
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                return (tree.insert(first, last));
            }
            iterator begin()
            {
                return (tree.begin());
            }
            const_iterator begin() const
            {
                return (tree.begin());
            }
            iterator end()
            {
                return (tree.end());
            }
            const_iterator end() const
            {
                return (tree.end());
            }
            reverse_iterator rbegin()
            {
                return (tree.rbegin());
            }
            const_reverse_iterator rbegin() const
            {
                return (tree.rbegin());
            }
            reverse_iterator rend()
            {
                return (tree.rend());
            }
            const_reverse_iterator rend() const
            {
                return (tree.rend());
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
            mapped_type& operator[] (const key_type& k)
            {
                return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
            }
            mapped_type& at (const key_type& k)
            {
                iterator z = tree.find(k);
                if (z == tree.end())
                {
                    throw std::out_of_range("out of range");
                }
                else
                {
                    return (*z.second);
                }
            }
            const mapped_type& at (const key_type& k) const
            {
                const_iterator z = tree.find(k);
                if (z == tree.end())
                {
                    throw std::out_of_range("out of range");
                }
                else
                {
                    return (*z.second);
                }
            }
            
        protected:
            key_compare _compare;
            value_compare _compval;
            allocator_type _alloc;
            ft::red_black_tree<key_type, mapped_type, \
            key_compare, allocator_type> tree;
        };
}

#endif