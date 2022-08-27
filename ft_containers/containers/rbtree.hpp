#ifndef RBTREE_HPP
# define RBTREE_HPP


node *_createnode(const value_type &val)
{
    node *x;
    
    x = _node_alloc.allocate(1);
    x->left = NULL;
    x->right = NULL;
    x->parent = NULL;
    x->data = val;
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


# endif