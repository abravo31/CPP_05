#include "AForm.hpp"

// Constructor & Destructor
AForm::AForm( std::string name, const int toSign, const int toExecute ) : _name(name), _signed(false), _tosign(toSign), _toexecute(toExecute){
    
    if ( this->_tosign < 1 || this->_toexecute < 1 ){
        std::cout << this->_name << " cannot construct" << std::endl;
        throw this->_tooHigh;
    } else if ( this->_tosign > 150 || this->_toexecute > 150 ){
        std::cout << this->_name << " cannot construct" << std::endl;
        throw this->_tooLow;
    }
}

AForm::AForm( const AForm& copy ) : _tosign(copy.getGradeToSign()), _toexecute(copy.getGradeToExecute()) {

    std::cout << "Copy Form Constructor called" << std::endl;
    *this = copy;
}

AForm::~AForm( void ){}

// Assignment Operator
AForm& AForm::operator = ( const AForm& src ){
        std::cout << "Assignation operator Form called" << std::endl;
    if (this == &src)
        return *this;
    this->_signed = src._signed;
    return *this;
}

// Members functions

void	AForm::beSigned( const Bureaucrat& bureaucrat ){
    if ( bureaucrat.getGrade() <= this->_tosign )
        this->_signed = 1;
    else
        throw this->_tooLow;
}

void	AForm::execute( Bureaucrat const& executor )const{

    if ( executor.getGrade() > this->getGradeToExecute() )
		throw this->_tooLow;
	else if ( this->getSign() == false )
		throw this->_notSigned;
    else
        executeAction();
}
	
// Getters

std::string	AForm::getName( void ) const { return (this->_name); }
bool		AForm::getSign( void ) const { return (this->_signed); }
int         AForm::getGradeToSign( void ) const { return (this->_tosign); }
int         AForm::getGradeToExecute( void ) const { return (this->_toexecute); }


std::ostream& operator << ( std::ostream& out, const AForm& form ){
    out << form.getName() << std::endl <<
    "Form signed : " << form.getSign() << std::endl <<
    "To sign : " << form.getGradeToSign() << std::endl <<
    "To execute : " << form.getGradeToExecute() << std::endl;

    return out;
}

const char* FormNotSignedException::what() const throw(){
    return ("Form is not signed");
}