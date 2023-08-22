#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:

	// Constructor & Destructor
		RobotomyRequestForm( const std::string& target);
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		~RobotomyRequestForm( void );
	
	// Assignment Operator
		RobotomyRequestForm& operator = ( const RobotomyRequestForm& src );

	// Members functions

		virtual void		executeAction( void )const;
	
	// Getters

		std::string			getTarget( void ) const;

	private:
			const std::string	_target;

};

std::ostream& operator << ( std::ostream& out, const RobotomyRequestForm& form );

#endif