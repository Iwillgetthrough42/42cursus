#ifndef NODE_HPP
# define NODE_HPP

#include "pair.hpp"
//#include "map.hpp"
#include <memory>
#include "../iterators/reverse_iterator.hpp"

enum COL {RED, BLACK};

namespace ft
{
    template <class T1, class T2>
    struct Node
    {
        typedef typename ft::pair<T1, T2>* pointer;
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