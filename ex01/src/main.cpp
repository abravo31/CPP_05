#include "../include/Bureaucrat.hpp"

int main ( void ){
    try{
        // Bureaucrat Boby( "🐕 Boby", 0 );
        Bureaucrat Nini( "🐱 Nini", 9 );
        Form Form1("Form 📝", 7, 5);
        while (Nini.getGrade() >= 6){
            std::cout << Nini;
            Form1.beSigned(Nini);
            Nini.signForm(Form1);
            std::cout << Form1;
			//Nini.decrement();
            Nini.increment();
        }
    } catch (std::exception& e){
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat a("Assistant", 5);
		Bureaucrat b("BOSS", 1);
		Form form2("Boring Form 📝", 5, 2);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << form2;

		// Assistant signs the Form
		try
		{
			a.signForm(form2);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << a.getName() << " was not able to sign the Form " << form2.getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// Boss signs the Form
        std::cout << form2;
		try
		{
			form2.beSigned(b);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << b.getName() << " was not able to sign the Form " << form2.getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << form2;

		// try signing the from again
		b.signForm(form2);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		std::cout << std::endl;
    }
    return 0;
}