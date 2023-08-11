#ifndef EXCEPTIONS
# define EXCEPTIONS
# include <exception>

class GradeTooHighException : public std::exception {
	public :
		virtual const char* what() const throw();
	private :
};

class GradeTooLowException : public std::exception {
	public :
		virtual const char* what() const throw();
	private :
};

class FormNotSignedException : public std::exception{
	public:
		virtual const char *what() const throw();
	private:
};

#endif