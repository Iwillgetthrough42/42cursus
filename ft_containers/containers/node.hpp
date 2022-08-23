#ifndef NODE_HPP
# define NODE_HPP
#include "pair.hpp"
#include "map.hpp"


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
    template <class T1, class T2>
    struct red_black_tree : public ft::map<T1, T2>
    {
        Node *_nil;
        Node *_root;

        red_black_tree()
        {
            _nil = _node_alloc.allocate(1);
            _nil->left = NULL;
            _nil->right = NULL;
            _nil->parent = NULL;
            _nil->color = BLACK;
            _nil->data = NULL;
            _root = _nil;
        }

    };

};





#endif