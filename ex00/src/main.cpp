#include "../include/Bureaucrat.hpp"

int main ( void ){
    try{
        // Bureaucrat Boby( "🐕 Boby", 0 );
        Bureaucrat Nini( "🐱 Nini", 127 );
        while (1){
            Nini.decrement();
            //Nini.increment();
            std::cout << Nini;
        }
    } catch (std::exception& e){
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    return 0;
}