#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Exceptions.hpp"

class AForm;

class Bureaucrat {
	public:

	// Constructor & Destructor
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat& copy );
		~Bureaucrat( void );
	
	// Assignment Operator
		Bureaucrat& operator = ( const Bureaucrat& src );

	// Getters

		std::string	getName( void ) const;
		int			getGrade( void ) const;

	// Setters

		// void		setGrade( int grade );

	// Members functions

		void		increment( void );
		void		decrement( void );
		void		signForm( AForm& form );
		void		executeForm(AForm const& form);

	private:
		const std::string		_name;
		int						_grade;
		GradeTooHighException	_tooHigh;
		GradeTooLowException	_tooLow;
};

std::ostream& operator << ( std::ostream& out, const Bureaucrat& bureaucrat );

#endif