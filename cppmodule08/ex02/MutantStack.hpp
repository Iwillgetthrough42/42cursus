#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        virtual ~MutantStack();
        MutantStack(MutantStack const &other);
        MutantStack & operator=(MutantStack const &other);
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        iterator begin();
        iterator end();
        typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
        const_iterator cbegin() const;
        const_iterator cend() const;
        typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin();
        reverse_iterator rend();
        typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{

}
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
    
}
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const &other) : std::stack<T, Container>(other)
{

}
template <typename T, typename Container>
MutantStack<T, Container> &  MutantStack<T, Container>::operator=(MutantStack const &other)
{
    std::stack<T, Container>::operator = (other);
    return (*this);
}
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin() const
{
    return (this->c.cbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend() const
{
    return (this->c.cend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
    return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin() const
{
    return (this->c.crbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend() const
{
    return (this->c.crend());
}

#endif