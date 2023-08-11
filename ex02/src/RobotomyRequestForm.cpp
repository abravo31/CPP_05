#include "RobotomyRequestForm.hpp"

// Constructor & Destructor
RobotomyRequestForm::RobotomyRequestForm( const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target){

	std::cout << "RobotomyRequestForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget()) {

	std::cout << "RobotomyRequestForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << std::endl;
	
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm( void ){

	std::cout << "RobotomyRequestForm Destructor " << this->getName() << " called" << std::endl;
}
	
// Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator = ( const RobotomyRequestForm& src ){

	std::cout << "Assignation operator RobotomyRequestForm called" << std::endl;
    if (this == &src)
        return *this;
    return *this;
}

// Members functions
void		RobotomyRequestForm::executeAction( void )const{
	
	std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0); // Distribution btw 0 et 1

    double random_number = distribution(rng);

	std::cout << "*** BrRrRRRrr!!! ***" << std::endl;
    if (random_number < 0.5) {
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Robotomy failed." << std::endl;
    }
}

// Getters

std::string	RobotomyRequestForm::getTarget( void ) const{ return (this->_target); }

std::ostream& operator << ( std::ostream& out, const RobotomyRequestForm& form ){

	out << form.getName() << std::endl <<
    "Form signed : " << form.getSign() << std::endl <<
    "To sign : " << form.getGradeToSign() << std::endl <<
    "To execute : " << form.getGradeToExecute() << std::endl;

	return out;
}
