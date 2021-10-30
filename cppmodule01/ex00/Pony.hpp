#ifndef PONY_HPP
# define PONY_HPP

class Pony
{
	public:
		Pony(int level);
		void run();
		void eat();
		void train();
		int getlevel() const;
		void setlevel(int level);
	private:
		int speedLevel;
};

#endif