#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string newfile = filename + ".replace";
	std::ifstream ifs(filename);
	std::ofstream ofs(newfile, std::ofstream::out | std::ofstream::trunc);
	if (s1 == "" || s2 == "")
	{
		std::cout << "empty parameters" << std::endl;
		return (1);
	}	
	if (!ifs.is_open())
	{
		std::cout << "Error while openning the file" << std::endl;
		return (1);
	}
	if (!ofs.is_open())
	{
		std::cout << "Error while openning the file" << std::endl;
		return (1);
	}
	std::string buf;
	while (std::getline(ifs, buf))
	{
		int found = buf.find(s1);
		while (found != std::string::npos)
		{
			buf = buf.replace(found, s1.length(), s2);
			found = buf.find(s1, found + s1.length());
		}
		ofs << buf;
		buf.clear();
		if (ifs)
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}