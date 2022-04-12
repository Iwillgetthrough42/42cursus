#include <iostream>
#include <sstream>
#include <limits>

template <typename T, typename V>

int detectoverflow(V value)
{
	if (!(value >= std::numeric_limits<T>::lowest() && value <= std::numeric_limits<T>::max()))
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
	if (detectoverflow<char, double>(d))
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
	if (detectoverflow<int, double>(d))
		std::cout << "int: Impossible " << std::endl;
	else
	{
		i = static_cast<int>(d);
		std::cout << "Int:" << i << std::endl;
	}
}

void todouble(double d)
{
	double dd;

	if (detectoverflow<double, double>(d))
		std::cout << "double: Impossible " << std::endl;
	else
	{
		dd = static_cast<double>(d);
		std::cout << "Double:" << dd << std::endl;
	}
}

void tofloat(double d)
{
	float f;

	if (detectoverflow<float, double>(d))
		std::cout << "float: Impossible " << std::endl;
	else
	{
		f = static_cast<float>(d);
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
			&& !(i != 0 && i != st.length() - 1 && str[i] == '.'))
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
	if (isnan(argv[1]))
	{
		;
	}
	else
	{
		tochar(d);
		toint(d);
		todouble(d);
		tofloat(d);
	}
	return (0);
}