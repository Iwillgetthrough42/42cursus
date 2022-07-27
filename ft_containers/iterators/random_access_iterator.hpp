#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
    template <class T>
    class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
        public:
            typedef ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
            typedef ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
            typedef ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
            typedef ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
            typedef ft::iterator<ft::random_access_iterator_tag, T>::reference reference;

            random_access_iterator(pointer p = NULL)
            {
                this->p = p;
            }
            random_access_iterator(const random_access_iterator &other)
            {
                this->p = other.p;
            }
            random_access_iterator &operator=(const random_access_iterator &other)
            {
                this->p = other.p;
            }
            reference operator*(){return (*p)}
            pointer operator->(){return (p)}
            random_access_iterator &operator++()
            {
                this->p++;
                return (*this);
            }
            random_access_iterator &operator++(int t)
            {
                random_access_iterator tmp = *this;
                this->p++;
                return (tmp);
            }
            random_access_iterator &operator--()
            {
                this->p--;
                return (*this);
            }
            random_access_iterator &operator--(int t)
            {
                random_access_iterator tmp = *this;
                this->p--;
                return (tmp);
            }
            random_access_iterator operator+(size_t n)
            {
                return random_access_iterator(this->p + n);
            }
            random_access_iterator operator-(size_t n)
            {
                return random_access_iterator(this->p - n);
            }
            difference_type operator-(const random_access_iterator &rhs)
            {
                return (this->p - rhs.p);
            }
            reference operator[](size_t n){return (this->p[n]);}
            random_access_iterator &operator+=(size_t n){this->p += n; return (*this);}
            random_access_iterator &operator-=(size_t n){this->p -= n; return (*this)}
            friend difference_type operator-(size_t n, random_access_iterator &rhs);
            friend difference_type operator+(size_t n, random_access_iterator &rhs);
        protected:
            pointer p;
    };
    template <class T>
    typename random_access_iterator<T>::difference_type operator-(size_t n, random_access_iterator<T> &rhs)
    {

    }
}


#endif