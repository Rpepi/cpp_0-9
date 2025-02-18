#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat b("Jean", 139);
        ShrubberyCreationForm f("jardin");
        b.signForm(f);
        b.executeForm(f);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 2: RobotomyRequestForm ===" << std::endl;
    try
    {
        Bureaucrat b("Jean", 75);
        RobotomyRequestForm f("robot");
        b.signForm(f);
        b.executeForm(f);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 3: PresidentialPardonForm ===" << std::endl;
    try
    {
        Bureaucrat b("Jean", 1);
        PresidentialPardonForm f("Arthur Dent");
        b.signForm(f);
        b.executeForm(f);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
