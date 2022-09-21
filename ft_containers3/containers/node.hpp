#ifndef NODE_HPP
# define NODE_HPP

#include "pair.hpp"
#include <memory>
#include "../iterators/reverse_iterator.hpp"

enum COL {RED, BLACK};

namespace ft
{
    template <class T>
    struct Node
    {
        typedef T* pointer;
        enum COL color;
        typedef Node* Node_pointer;
        typedef Node& Node_reference;
        struct Node *left;
        struct Node *right;
        struct Node *parent;
        pointer data;
    };
}

#endif