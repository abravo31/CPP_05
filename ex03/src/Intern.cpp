
#include "Intern.hpp"

// Constructor & Destructor
Intern::Intern( void ){

    std::cout << "Intern Constructor called" << std::endl;
}

Intern::Intern( const Intern& copy ){

    std::cout << "Intern Copy Constructor called" << std::endl;
    (void)copy;  
}

Intern::~Intern( void ){

    std::cout << "Intern Destructor called" << std::endl;
}
	
// Assignment Operator
Intern& Intern::operator = ( const Intern& src ){

    std::cout << "Intern Assignement Operator called" << std::endl;
    (void)src;
    return(*this);
}

// Static functions

static AForm*    makeShrubbery( const std::string target ){

    return (new ShrubberyCreationForm(target));
}

static AForm*   makeRobot( const std::string target ){

    return (new RobotomyRequestForm(target));
}

static AForm* makePresidential( const std::string target ){

    return (new PresidentialPardonForm(target));
}
// Members functions
AForm*    Intern::makeForm( const std::string formName, const std::string target ){
    
    AForm* (*formCreators[])(const std::string) = {
        &makeShrubbery,
        &makeRobot,
        &makePresidential
    };

    const std::string formNames[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    for (size_t i = 0; i < sizeof(formCreators) / sizeof(formCreators[0]); ++i) {
        if (formNames[i] == formName) {
            return formCreators[i](target);
        }
    }
    std::cout << target << ": " << formName << std::endl; 
    throw _badForm;
}

const char*	BadForm::what() const throw()
{
	return ("Form Does Not Exist");
}