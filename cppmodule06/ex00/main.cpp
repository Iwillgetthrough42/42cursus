#include <iostream>

int ischar(std::string str)
{
	if (str.length() == 1 && std::isprint(str[0]))
		return (1);
	return (0);
}

int isnan(std::string str)
{
	if (str == "inf" || str == "-inf" ||\
		str == "+inf" || str == "inff" ||\
		str == "+inff" || str == "-inff" ||\
		str == "nan" || str == "nanf")
		return (1);
	return (0);
}

void tochar(std::string str)
{
	char c;

	if (ischar(str))
	{
		std::cout << "Char:" << str << std::endl;
		return ;
	}
	try
	{
		c = static_cast<char>(std::stod(str));
		if (c > 31 && c < 127)
			std::cout <<"Char:" << c <<std::endl;
		else
			std::cout << "non printable" << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << "Char: impossible" << std::endl;
	}
}

void toint(std::string str)
{
	int i;

	if (ischar(str))
	{
		std::cout << "Int:" << static_cast<int>(str[0]) << std::endl;
		return ;
	}
	try
	{
		i = static_cast<int>(std::stod(str));
		std::cout << "Int:" << i << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Int: impossible" << std::endl;
	}
}

void todouble(std::string str)
{
	double d;

	if (ischar(str))
	{
		std::cout << "Double:" << static_cast<double>(str[0]) << std::endl;
		return ;
	}
	try
	{
		d = std::stod(str);
		std::cout << "Double:" << d << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Double: impossible" << std::endl;
	}
}


void tofloat(std::string str)
{
	float f;

	if (ischar(str))
	{
		std::cout << "Float:" << static_cast<float>(str[0]) \
		<< "f" << std::endl;
		return ;
	}
	try
	{
		f = std::stof(str);
		std::cout << "Float:" << f << "f" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Float: Impossible" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}
	if (isnan(argv[1]))
	{
		std::cout << "Char:Impossible" << std::endl;
		std::cout << "Int:Impossible" << std::endl;
		std::cout << "Double:" << std::stod(argv[1]) << std::endl;
		std::cout << "Float:" << std::stof(argv[1]) << "f" << std::endl;
	}
	else
	{
		tochar(argv[1]);
		toint(argv[1]);
		todouble(argv[1]);
		tofloat(argv[1]);
	}
	return (0);
}