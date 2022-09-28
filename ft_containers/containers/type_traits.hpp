#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{

    struct true_type
    {
        static const bool value = true;
        typedef bool value_type;
        typedef true_type type;
        operator bool(){return (value); }
    };

    struct false_type
    {
        static const bool value = false;
        typedef bool value_type;
        typedef false_type type;
        operator bool(){return (value); }
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
    struct is_integral< wchar_t> : public true_type{};
    template <>
    struct is_integral< signed char> : public true_type{};
    /*template <>
    struct is_integral< char16_t> : public true_type{};
    template <>
    struct is_integral< char32_t> : public true_type{};*/
    template <>
    struct is_integral< long int> : public true_type{};
    template <>
    struct is_integral< short int> : public true_type{};
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
    template<bool cond, class T>
    struct constif
    {
        typedef T type;
    };

    template <class T>
    struct constif<true, T>
    {
        typedef const T type;
    };
};

#endif