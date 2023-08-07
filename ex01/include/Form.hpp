#ifndef FORM_HPP
# define FORM_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <exception>
# include <Bureaucrat.hpp>

class GradeTooHighException : public std::exception {
	public :
		virtual const char* what() const throw();
	private :
};

class GradeTooLowException : public std::exception {
	public :
		virtual const char* what() const throw();
	private :
};

class Form {
	public:

	// Constructor & Destructor
		Form( void );
		Form( const Form& copy );
		~Form( void );
	
	// Assignment Operator
		Form& operator = ( const Form& src );

	// Members functions

		void		beSigned( const Bureaucrat& bureaucrat );
		void		decrement( void );


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