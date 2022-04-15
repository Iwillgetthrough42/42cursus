#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>

class Array
{
	private:
		unsigned int length;
		T *arr;
	public:
		Array()
		{
			this->length = 0;
			this->arr = new T();
		}
		~Array()
		{
			delete[] this->arr;
		}
		Array(unsigned int n)
		{
			this->length = n;
			this->arr = new T[n]();

		}
		Array(Array &other)
		{
			*this = other;
		}
		Array &operator=(Array &other)
		{	
			T *tmp;
			if (this == &other)
				return (*this);
			this->length = other.getlength();
			tmp = this->arr;
			this->arr = new T[this->length];
			delete [] tmp;
			for (int i = 0; i < this->length; i++)
			{
				this->arr[i] =other[i];
			}
			return (*this);
		}
		T &operator[](unsigned int index)
		{
			if (index > this->length)
				throw std::out_of_range("index out of range");
			return (this->arr[index]);

		}
		unsigned int size() const
		{
			return (this->length);
		}
};

#endif