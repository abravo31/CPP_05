#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		AForm*	signed_shrubbery;
		AForm*	robotomy;
		AForm*	invalidForm;
		AForm*	pardon;

		std::cout << "\n-------CONSTRUCTION-------\n";
		Bureaucrat				bureaury("bureaury", 100);
		//Bureaucrat				bureaury2("bureaury", 1000);
		Intern					terny;
		
		signed_shrubbery = (terny.makeForm("ShrubberyCreationForm", "Shub"));
		std::cout << "SHRUBBERY:\n" \
			<< *signed_shrubbery << std::endl;
		bureaury.signForm(*signed_shrubbery);
		bureaury.executeForm(*signed_shrubbery);
		delete signed_shrubbery;

		std::cout << "--------------------------\n";

		robotomy = (terny.makeForm("RobotomyRequestForm", "Rob"));
		std::cout << "ROBOTOMY:\n" \
			<< *robotomy << std::endl;
		bureaury.signForm(*robotomy);
		bureaury.executeForm(*robotomy);
		delete robotomy;

		std::cout << "--------------------------\n";

		pardon = (terny.makeForm("PresidentialPardonForm", "Paola"));
		std::cout << "PARDON:\n" \
			  << *pardon << std::endl;
		bureaury.signForm(*pardon);
		bureaury.executeForm(*pardon);
		delete pardon;

		std::cout << "--------------------------\n";

		invalidForm = (terny.makeForm("WrongForm", "Wrong"));
		std::cout << "\nINVALID FORM:\n" \
			  << *invalidForm << std::endl;
		bureaury.signForm(*invalidForm);
		bureaury.executeForm(*invalidForm);
		delete invalidForm;
		
		std::cout << "--------------------------\n";

	}
	catch(const std::exception& e)
	{
		std::cerr << "\nERROR: " << e.what() << '\n';
	}
	std::cout << "--------------------------\n";
	return 0;
}

// int main ( void ){

// 	try{
// 		Bureaucrat	can_everything("can everything", 100);

// 		AForm* 		shrubberyForm;
//     	AForm*		robotomyForm;
//     	AForm*		pardonForm;
// 		AForm*		invalidForm;
// 		Intern intern;

//     	shrubberyForm = (intern.makeForm("ShrubberyCreationForm", "garden"));
//     	robotomyForm = intern.makeForm("RobotomyRequestForm", "target");
//     	pardonForm = intern.makeForm("PresidentialPardonForm", "victim");
// 		invalidForm = intern.makeForm("InvalidForm", "invalid_target");


// 		can_everything.signForm(*shrubberyForm);
//         can_everything.signForm(*robotomyForm);
//         can_everything.signForm(*pardonForm);

//         can_everything.executeForm(*pardonForm);
// 		can_everything.executeForm(*shrubberyForm);
//         can_everything.executeForm(*robotomyForm);
// 		can_everything.executeForm(*invalidForm);

// 		delete pardonForm;
// 		delete shrubberyForm;
// 		delete robotomyForm;
// 		//delete invalidForm;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "\nERROR: " << e.what() << '\n';
// 	}
// 	std::cout << "--------------------------\n";

//     return 0;
// }

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