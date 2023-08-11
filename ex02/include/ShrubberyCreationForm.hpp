#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iomanip>
# include <iostream>
# include <fstream>
# include <string>
# include <exception>
# include "ASCIItree.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:

	// Constructor & Destructor
		ShrubberyCreationForm( const std::string& target);
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		~ShrubberyCreationForm( void );
	
	// Assignment Operator
		ShrubberyCreationForm& operator = ( const ShrubberyCreationForm& src );

	// Members functions

		virtual void	executeAction( void )const;
	
	// Getters

		std::string		getTarget( void ) const;

	private:
		const std::string	_target;

};

std::ostream& operator << ( std::ostream& out, const ShrubberyCreationForm& form );

#endif