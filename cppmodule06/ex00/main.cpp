#include <iostream>
#include <sstream>
#include <limits>

template <typename T, typename V>

int detectoverflow(V value)
{
	T t;
	t = static_cast<T>(value);
	if (static_cast<V>(t) != value)
	{
		return (1);
	}
	return (0);
}



int isnan(std::string str)
{
	if (str == "inf" || str == "-inf" ||
		str == "+inf" || str == "nan")
	{
		std::cout << "Char:Impossible" << std::endl;
		std::cout << "Int:Impossible" << std::endl;
		std::cout << "Double:" << str << std::endl;
		std::cout << "Float:" << str << "f" << std::endl;
		return (1);
	}
	else if (str == "inff" || str == "+inff" ||
			 str == "-inff" || str == "nanf")
	{
		std::cout << "Char:Impossible" << std::endl;
		std::cout << "Int:Impossible" << std::endl;
		std::cout << "Double:" << str.substr(0, 3) << std::endl;
		std::cout << "Float:" << str << std::endl;
		return (1);
	}
	return (0);
}

void tochar(double d)
{
	char c;
	if (!(d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max()))
		std::cout << "char: Impossible " << std::endl;
	else
	{
		c = static_cast<char>(d);
		if (c > 31 && c < 127)
				std::cout << "Char:" << c << std::endl;
			else
				std::cout << "Char: non printable" << std::endl;
	}
}

void toint(double d)
{
	int i;
	if (!(d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()))
		std::cout << "int: Impossible " << std::endl;
	else
	{
		i = static_cast<int>(d);
		std::cout << "Int:" << i << std::endl;
	}
}

void todouble(double d)
{
		std::cout << "Double:" << d << std::endl;
}

void tofloat(char *str)
{
	float f;
	std::stringstream s;

	s << str;
	s >> f;
	if (s.fail())
		std::cout << "float: Impossible " << std::endl;
	else
	{
		std::cout << "float:" << f << "f" << std::endl;
	}
}

int isnumber(char *str)
{
	int i;

	std::string st = std::string(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(i == 0 && str[0] == '-') \
			&& !(i != 0 && i != (int)st.length() - 1 && str[i] == '.'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}
	if (!(isnumber(argv[1])))
	{
		std::cout << "invalid input" << std::endl;
		return (0);
	}
	double d;
	std::stringstream ss;
	ss << argv[1];
	ss >> d;
	if (ss.fail())
	{
		std::cout << "Double: impossible" << std::endl;
		std::cout << "Float impossible" << std::endl;
		std::cout << "Char impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		return (0);
	}
	if (isnan(argv[1]))
	{
		;
	}
	else
	{
		tochar(d);
		toint(d);
		todouble(d);
		tofloat(argv[1]);
	}
	return (0);
}