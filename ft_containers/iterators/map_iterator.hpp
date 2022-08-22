#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "iterator.hpp"
#include "../containers/node.hpp"
#include "../containers/map.hpp"

namespace ft
{
    template <class T>
    class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category itertor_category;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::refernce reference;

            map_iterator() : node(NULL), nil(NULL){}
            map_iterator(Node *node, Node *nil)
            {
                this->node = node;
                this->nil = nil;
            }
            map_iterator(map_iterator const &other)
            {
                this->node = other.node;
                this->nil = other.nil;
            }
            map_iterator &operator=(map_iterator const &other)
            {
                this->nil = other.nil;
                this->node = other.node;
                return (*this);
            }
            template<class L>
            bool operator==(map_iterator<L> const &rhs) const
            {
                return (this->node == rhs.node);
            }
            template<class L>
            bool operator!=(map_iterator<L> const &rhs) const
            {
                return (this->node != rhs.node);
            }
            reference operator*()
            {
                return (*(node->data));
            }
            pointer operator->()
            {
                return (node->data);
            }
            iterator_map &operator++()
            {
                if (x->right != nil)
                {
                    _min(x);
                }
            }
        private:
            ft::Node *node;
            ft::Node *nil;

            ft::Node *_min(ft::Node *x)
            {
                while (x->left != _nil)
                {
                    x = x->left;
                }
                return (x);
            }
            ft::Node *_max(ft::Node *x)
            {
                while (x->right != _nil)
                {
                    x = x->right;
                }
                return (x);
            }

    };
}

#endif