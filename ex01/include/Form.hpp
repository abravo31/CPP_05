#ifndef FORM_HPP
# define FORM_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"
# include "Exceptions.hpp"

class Bureaucrat;

class Form {
	public:

	// Constructor & Destructor
		Form( std::string name, const int toSign, const int toExecute );
		Form( const Form& copy );
		~Form( void );
	
	// Assignment Operator
		Form& operator = ( const Form& src );

	// Members functions

		void		beSigned( const Bureaucrat& bureaucrat );
	
	// Getters

		std::string	getName( void ) const;
		bool		getSign( void ) const;
		int			getGradeToSign( void ) const;
        int			getGradeToExecute( void ) const;

	private:
		const std::string		_name;
        bool                    _signed;
		const int				_tosign;
		const int	            _toexecute;
        GradeTooHighException	_tooHigh;
		GradeTooLowException	_tooLow;
};

std::ostream& operator << ( std::ostream& out, const Form& form );

#endif