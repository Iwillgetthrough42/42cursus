#include <iostream>
#include <string>

std::string	upper(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return (s);
}

int 	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string s(argv[i]);
			std::cout << upper(s);
		}
		std::cout << std::endl;
	}
}