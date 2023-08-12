
#include "../include/Bureaucrat.hpp"

// Constructor & Destructor

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade){
    if ( this->_grade < 1 ){
        std::cout << this->_name << " cannot construct" << std::endl;
        throw this->_tooHigh;
    } else if ( this->_grade > 150 ){
        std::cout << this->_name << " cannot construct" << std::endl;
        throw this->_tooLow;
    }
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ){
    std::cout << "Copy Bureaucrat Constructor called" << std::endl;
    *this = copy;
}
Bureaucrat::~Bureaucrat( void ){}

// Assignment Operator
Bureaucrat& Bureaucrat::operator = ( const Bureaucrat& src ){
    std::cout << "Assignation operator Bureaucrat called" << std::endl;
    if (this == &src)
        return *this;
    this->_grade = src._grade;
    return *this;
}

// Getters

std::string	Bureaucrat::getName( void ) const{ return (this->_name); }
int			Bureaucrat::getGrade( void ) const{ return (this->_grade); }

// Setters

// void		Bureaucrat::setGrade( int grade ){
//     if ( grade < 1 ){
//         throw this->_tooHigh;
//     } else if ( grade > 150 ){
//         throw this->_tooLow;
//     } else
//         this->_grade = grade; 
// }

// Members functions

void    	Bureaucrat::increment( void ){
    if ( this->_grade > 1 )
        this->_grade--;
    else{
        std::cout << this->_name << " cannot increment" << std::endl;
        throw this->_tooHigh;
    }
        
}

void		Bureaucrat::decrement( void ){
    if ( this->_grade < 150 )
        this->_grade++;
    else {
        std::cout << this->_name << " cannot decrement" << std::endl;
        throw this->_tooLow;
    }
}

void		Bureaucrat::signForm( AForm& form ) {
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn’t sign " << form.getName() << " beacause " << e.what() << '\n';
    }
}

void		Bureaucrat::executeForm(AForm const& form){
    try
    {
        form.execute(*this);
    	std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() \
				  << " because " << e.what() << std::endl;
	}
}

std::ostream& operator << ( std::ostream& out, const Bureaucrat& bureaucrat ){
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

const char* GradeTooHighException::what() const throw(){
    return ("grade too high");
}

const char* GradeTooLowException::what() const throw(){
    return ("grade too low");
}