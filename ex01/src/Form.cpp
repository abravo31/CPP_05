#include "Form.hpp"

// Constructor & Destructor
Form::Form( std::string name, const int toSign, const int toExecute ) : _name(name), _signed(false), _tosign(toSign), _toexecute(toExecute){
    
    if ( this->_tosign < 1 || this->_toexecute < 1 ){
        std::cout << this->_name << " cannot construct" << std::endl;
        throw this->_tooHigh;
    } else if ( this->_tosign > 150 || this->_toexecute > 150 ){
        std::cout << this->_name << " cannot construct" << std::endl;
        throw this->_tooLow;
    }
}

Form::Form( const Form& copy ) : _tosign(copy.getGradeToSign()), _toexecute(copy.getGradeToExecute()) {

    std::cout << "Copy Form Constructor called" << std::endl;
    *this = copy;
}

Form::~Form( void ){}

// Assignment Operator
Form& Form::operator = ( const Form& src ){
        std::cout << "Assignation operator Form called" << std::endl;
    if (this == &src)
        return *this;
    this->_signed = src._signed;
    return *this;
}

// Members functions

void	Form::beSigned( const Bureaucrat& bureaucrat ){
    if ( bureaucrat.getGrade() <= this->_tosign )
        this->_signed = 1;
}
	
// Getters

std::string	Form::getName( void ) const { return (this->_name); }
bool		Form::getSign( void ) const { return (this->_signed); }
int         Form::getGradeToSign( void ) const { return (this->_tosign); }
int         Form::getGradeToExecute( void ) const { return (this->_toexecute); }


std::ostream& operator << ( std::ostream& out, const Form& form ){
    out << form.getName() << std::endl <<
    "Form signed : " << form.getSign() << std::endl <<
    "To sign : " << form.getGradeToSign() << std::endl <<
    "To execute : " << form.getGradeToExecute() << std::endl;

    return out;
}