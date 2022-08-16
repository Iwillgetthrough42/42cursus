#ifndef NODE_HPP
# define NODE_HPP
#include "pair.hpp"


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

};





#endif