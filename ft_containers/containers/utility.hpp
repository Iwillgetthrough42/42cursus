#ifndef UTILITY_HPP
# define UTILITY_HPP

#include "algorithm.hpp"
#include "type_traits.hpp"



/*
namespace ft
{

    struct true_type
    {
        static const bool value = true;
        typedef bool value_type;
        typedef true_type type;
    };

    struct false_type
    {
        static const bool value = false;
        typedef bool value_type;
        typedef true_type type;
    };

    template < class T>
    struct is_integral : public false_type{};

    template <>
    struct is_integral<bool> : public true_type{};
    template <>
    struct is_integral<char> : public true_type{};
    template <>
    struct is_integral<int> : public true_type{};
    template <>
    struct is_integral<char16_t> : public true_type{};
    template <>
    struct is_integral<char32_t> : public true_type{};
    template <>
    struct is_integral< wchar_t> : public true_type{};
    template <>
    struct is_integral< signed char> : public true_type{};
    template <>
    struct is_integral< long int> : public true_type{};
    template <>
    struct is_integral< long long int> : public true_type{};
    template <>
    struct is_integral< unsigned char> : public true_type{};
    template <>
    struct is_integral< unsigned short int> : public true_type{};
    template <>
    struct is_integral< unsigned int> : public true_type{};
    template <>
    struct is_integral< unsigned long int> : public true_type{};
    template <>
    struct is_integral< unsigned long long int> : public true_type{};

    template<bool cond, class T = void>
    struct enable_if
    {

    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
    while (first1!=last1) {
        if (!(*first1 == *first2))
        return false;
        ++first1; ++first2;
    }
    return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false;
        else if (*first1<*first2) return true;
        ++first1; ++first2;
    }
    return (first2!=last2);
    }
};*/

#endif