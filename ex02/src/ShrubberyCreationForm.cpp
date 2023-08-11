# include "ShrubberyCreationForm.hpp"

// Constructor & Destructor
ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget()) {
	
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << std::endl;
	
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){
	
	std::cout << "ShrubberyCreationForm Destructor " << this->getName() << " called" << std::endl;
}
	
// Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator = ( const ShrubberyCreationForm& src ){

	std::cout << "Assignation operator ShrubberyCreationForm called" << std::endl;
    if (this == &src)
        return *this;
    return *this;
}

// Members functions
void	ShrubberyCreationForm::executeAction( void )const{

	std::ofstream	outfile;
	std::string		filename = this->getTarget() + "_shrubbery";

	if (outfile.open(filename.c_str()), !outfile.is_open())
		std::cerr << "error creating outfile\n";
	outfile << TREE;
	outfile.close();	
}
	
// Getters
std::string	ShrubberyCreationForm::getTarget( void ) const{ return(this->_target); }


std::ostream& operator << ( std::ostream& out, const ShrubberyCreationForm& form ){

	out << form.getName() << std::endl <<
    "Form signed : " << form.getSign() << std::endl <<
    "To sign : " << form.getGradeToSign() << std::endl <<
    "To execute : " << form.getGradeToExecute() << std::endl;

	return out;
}