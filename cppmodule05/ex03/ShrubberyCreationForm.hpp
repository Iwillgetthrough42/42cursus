#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
class Form;
#include <string>
#define ASCII_TREE "                               .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,  \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%; \n\
                          `@%%. `@%%    ;@@%; \n\
                            ;@%. :@%%  %@@%; \n\
                              %@bd%%%bd%%:;  \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o); \n\
                                %@@@o%;:(.,' \n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::; \n\
                                %@@(o)::; \n\
                               .%@@@@%::;  \n\
                               ;%@@@@%::;.    \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,..  "

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
		void virtual action();
		std::string getTarget() const;
		void setTarget(std::string const target);
};

#endif