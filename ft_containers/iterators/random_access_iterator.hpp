#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
#include "iterator.hpp"
#include <iostream>

namespace ft
{
    template <class T>
    class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
        public:
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;

            random_access_iterator(pointer p = NULL)
            {
                this->p = p;
            }
            random_access_iterator(const random_access_iterator &other)
            {
                this->p = other.p;
            }
            operator random_access_iterator<const T> () const
            {
                std::cout << "hi" << std::endl;
                return (random_access_iterator<const T>(this->p));
            }
            random_access_iterator &operator=(const random_access_iterator &other)
            {
                this->p = other.p;
                return (*this);
            }
            reference operator*(){return (*p);}
            pointer operator->(){return (p);}
            random_access_iterator &operator++()
            {
                this->p++;
                return (*this);
            }
            pointer base() const
            {
                return (this->p);
            }
            random_access_iterator &operator++(int t)
            {
                (void) t;
                random_access_iterator *tmp = this;
                this->p++;
                return (*tmp);
            }
            random_access_iterator &operator--()
            {
                this->p--;
                return (*this);
            }
            random_access_iterator &operator--(int t)
            {
                (void) t;
                random_access_iterator *tmp = this;
                this->p--;
                return (*tmp);
            }
            random_access_iterator operator+(size_t n) const
            {
                return random_access_iterator(this->p + n);
            }
            random_access_iterator operator-(size_t n) const
            {
                return random_access_iterator(this->p - n);
            }
            difference_type operator-(const random_access_iterator &rhs) const
            {
                return (this->p - rhs.p);
            }
            reference operator[](size_t n){return (this->p[n]);}
            random_access_iterator &operator+=(size_t n){this->p += n; return (*this);}
            random_access_iterator &operator-=(size_t n){this->p -= n; return (*this);}
            friend random_access_iterator operator+(size_t n, random_access_iterator &rhs)
            {
                return (random_access_iterator(rhs.p + n));
            }
        protected:
            pointer p;
    };
    template<class T>
    bool operator<(const random_access_iterator<T> lhs, const random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template<class T>
    bool operator>(random_access_iterator<T> lhs, random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template<class T>
    bool operator<=(random_access_iterator<T> lhs, random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template<class T>
    bool operator>=(random_access_iterator<T> lhs, random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template<class T>
    bool operator==(const random_access_iterator<T> lhs, const random_access_iterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template<class T>
    bool operator!=(random_access_iterator<T> lhs, random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }

}


#endif
