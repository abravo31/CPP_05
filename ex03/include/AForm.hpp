#ifndef AFORM_HPP
# define AFORM_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"
# include "Exceptions.hpp"

class Bureaucrat;

class AForm {
	public:

	// Constructor & Destructor
		AForm( std::string name, const int toSign, const int toExecute );
		AForm( const AForm& copy );
		virtual ~AForm( void );
	
	// Assignment Operator
		AForm& operator = ( const AForm& src );

	// Members functions

		void			beSigned( const Bureaucrat& bureaucrat );
		void			execute( Bureaucrat const& executor )const;
		virtual void	executeAction( void ) const = 0;
	
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
		FormNotSignedException	_notSigned;
};

std::ostream& operator << ( std::ostream& out, const AForm& form );

#endif