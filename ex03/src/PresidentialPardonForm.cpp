#include "PresidentialPardonForm.hpp"

// Constructor & Destructor
PresidentialPardonForm::PresidentialPardonForm( const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target){

    std::cout << "PresidentialPardonForm Constructor for target " << this->getTarget() << " called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget()){

    std::cout << "PresidentialPardonForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << std::endl;
	
	*this = copy;
}
PresidentialPardonForm::~PresidentialPardonForm( void ){

    std::cout << "PresidentialPardonForm Destructor " << this->getName() << " called" << std::endl;
}

// Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator = ( const PresidentialPardonForm& src ){

    std::cout << "Assignation operator PresidentialPardonForm called" << std::endl;
    if (this == &src)
        return *this;
    return *this;
}

// Members functions
void		PresidentialPardonForm::executeAction( void )const{

    std::cout << this->_target << " has been  pardoned by Zaphod Beeblebrox " << std::endl; 
}
	
// Getters

std::string	PresidentialPardonForm::getTarget( void ) const{ return (this->_target); }


std::ostream& operator << ( std::ostream& out, const PresidentialPardonForm& form ){

    out << form.getName() << std::endl <<
    "Form signed : " << form.getSign() << std::endl <<
    "To sign : " << form.getGradeToSign() << std::endl <<
    "To execute : " << form.getGradeToExecute() << std::endl;

	return out;
}
