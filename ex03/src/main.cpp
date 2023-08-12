#include "../include/Bureaucrat.hpp"
#include "Intern.hpp"

int main ( void ){
	try{
		Intern intern;

    	AForm* 		shrubberyForm = intern.makeForm("ShrubberyCreationForm", "garden");
    	AForm*		robotomyForm = intern.makeForm("RobotomyRequestForm", "target");
    	AForm*		pardonForm = intern.makeForm("PresidentialPardonForm", "victim");
    	AForm*		invalidForm = intern.makeForm("InvalidForm", "invalid_target");
		Bureaucrat	can_everything("can everything", 4);

    	// Test if forms were created successfully
    	if (shrubberyForm) {
        	shrubberyForm->execute(can_everything);
        	delete shrubberyForm;
    	}

    	if (robotomyForm) {
        	robotomyForm->execute(can_everything);
        	delete robotomyForm;
    	}

    	if (pardonForm) {
        	pardonForm->execute(can_everything);
        	delete pardonForm;
    	}

    	if (invalidForm) {
        // This won't execute since the form creation failed
        	delete invalidForm;
    	}
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nERROR: " << e.what() << '\n';
	}
	std::cout << "--------------------------\n";

    return 0;
}

//    try
// 	{
// 		std::cout << "\n-------CONSTRUCTION-------\n";
// 		Bureaucrat				cannot_sign("cannot sign", 146);
// 		Bureaucrat				cannot_exec("cannot exec", 138);
// 		Bureaucrat				can_everything("can everything", 4);
// 		ShrubberyCreationForm	signed_shrubbery("signed");
// 		ShrubberyCreationForm	unsigned_shrubbery("unsigned");
// 		RobotomyRequestForm		robotomy("bob");
// 		PresidentialPardonForm	pardon("she");
// 		std::cout << "--------------------------\n";

// 		std::cout << "\n-------BUREAUCRATS--------\n";
// 		std::cout << "BUREAUCRAT THAT CANT SIGN:\n";
// 		std::cout << cannot_sign;

// 		std::cout << "\nBUREAUCRAT THAT CANT EXEC:\n";
// 		std::cout << cannot_exec;

// 		std::cout << "\nBUREAUCRAT THAT CAN EXEC:\n";
// 		std::cout << can_everything;
// 		std::cout << "--------------------------\n";

// 		// std::cout << "\n----------BROKEN----------\n";
// 		// std::cout << "--------------------------\n";
		
// 		std::cout << "\n----------SIGNING---------\n";
// 		std::cout << "UNSIGNED FORM:\n" \
// 				  << unsigned_shrubbery << std::endl;
	
// 		// signed_shrubbery.beSigned(cannot_sign);
// 		// signed_shrubbery.beSigned(cannot_exec);
// 		cannot_sign.signForm(signed_shrubbery);
// 		cannot_exec.signForm(signed_shrubbery);
// 		can_everything.signForm(robotomy);
// 		can_everything.signForm(pardon);

// 		std::cout << "\nSIGNED FORM:\n" \
// 				  << signed_shrubbery << std::endl;
// 		std::cout << "--------------------------\n";

// 		std::cout << "\n---------EXECUTING--------\n";
// 		// signed_shrubbery.execute(cannot_exec);
// 		// signed_shrubbery.execute(can_everything);
// 		// unsigned_shrubbery.execute(cannot_exec);
// 		// unsigned_shrubbery.execute(can_everything);
	
// 		cannot_exec.executeForm(signed_shrubbery);
// 		can_everything.executeForm(signed_shrubbery);
// 		cannot_exec.executeForm(unsigned_shrubbery);
// 		can_everything.executeForm(unsigned_shrubbery);
// 		can_everything.executeForm(robotomy);
// 		can_everything.executeForm(pardon);
// 		std::cout << "--------------------------\n";

// 		std::cout << "\n---------DESTRUCTION----------\n";
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "\nERROR: " << e.what() << '\n';
// 	}
// 	std::cout << "--------------------------\n";
//     return 0;
// }