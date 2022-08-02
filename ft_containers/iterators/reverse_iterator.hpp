#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
namespace ft{
    template<class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
            reverse_iterator() : iter(){}
            explicit reverse_iterator (iterator_type it) : iter(it){}
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter> &rev_it)
            {
                iter(rev_it.base());
            }
        protected:
            iterator_type iter;
    };
}



#endif