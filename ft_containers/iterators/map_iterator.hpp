#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP


#include "iterator.hpp"
#include "../containers/node.hpp"

namespace ft
{
    template <class T>
    class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
            typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
            typedef typename value_type::first_type first;
            typedef typename value_type::second_type second;
            typedef  ft::Node<first, second> Node;
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
            reference operator*() const
            {
                return (*(node->data));
            }
            operator map_iterator<const T> () const
            {
                return (map_iterator<const T>(node, nil));
            }
            pointer operator->() const
            {
                return (node->data);
            }
            map_iterator &operator++()
            {
                node = successor();
                return (*this);
            }
            map_iterator operator++(int num)
            {
               (void) num;
               map_iterator tmp = *this;
               ++(*this);
               return (tmp);
            }
            map_iterator &operator--()
            {
                node = predecessor();
                return (*this);
            }
            map_iterator operator--(int num)
            {
               (void) num;
               map_iterator tmp = *this;
               --(*this);
               return (tmp);
            }
        private:
            Node *node;
            Node *nil;

            Node *_min(Node *x)
            {
                while (x->left != nil)
                {
                    x = x->left;
                }
                return (x);
            }
            Node *successor()
            {
                Node *y;

                if (node->right != nil)
                {
                    return (_min(node->right));
                }
                y = node->parent;
                while (y != nil && node == y->right)
                {
                    node = y;
                    y = y->parent;
                }
                return (y);

            }
            Node *predecessor()
            {
                Node *y;

                if (node->left != nil)
                {
                    return (_max(node->left));
                }
                y = node->parent;
                while (y != nil && node == y->left)
                {
                    node = y;
                    y = y->parent;
                }
                return (y);
            }
            Node *_max(Node *x)
            {
                while (x->right != nil)
                {
                    x = x->right;
                }
                return (x);
            }
    };
}

#endif