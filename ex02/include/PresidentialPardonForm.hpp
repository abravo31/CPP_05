#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:

	// Constructor & Destructor
		PresidentialPardonForm( const std::string& target);
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		~PresidentialPardonForm( void );
	
	// Assignment Operator
		PresidentialPardonForm& operator = ( const PresidentialPardonForm& src );

	// Members functions

		virtual void			executeAction( void )const;
	
	// Getters

		std::string				getTarget( void ) const;

		private:
			const std::string	_target;

};

std::ostream& operator << ( std::ostream& out, const PresidentialPardonForm& form );

#endif