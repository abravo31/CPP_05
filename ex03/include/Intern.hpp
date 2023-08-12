#ifndef INTERN_HPP
# define INTERN_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Exceptions.hpp"

class Intern {
	public:

	// Constructor & Destructor
		Intern( void );
		Intern( const Intern& copy );
		~Intern( void );
	
	// Assignment Operator
		Intern& operator = ( const Intern& src );

	// Members functions
		AForm*    makeForm( const std::string formName, const std::string formTarget );

    private:
        BadForm _badForm;

};

#endif
