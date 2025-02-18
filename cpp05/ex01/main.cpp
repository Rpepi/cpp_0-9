#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    std::cout << "=== Test 1: Création normale ===" << std::endl;
    try {
        Bureaucrat normal("Jean", 75);
        std::cout << normal << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: Grade trop haut à la création (0) ===" << std::endl;
    try {
        Bureaucrat tooHigh("Pierre", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception attendue: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: Grade trop bas à la création (151) ===" << std::endl;
    try {
        Bureaucrat tooLow("Marie", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception attendue: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 4: Incrémentation jusqu'à l'erreur ===" << std::endl;
    try {
        Bureaucrat b("Sophie", 2);
        std::cout << b << std::endl;
        std::cout << "Première incrémentation:" << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        std::cout << "Deuxième incrémentation (devrait échouer):" << std::endl;
        b.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception attendue: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 5: Décrémentation jusqu'à l'erreur ===" << std::endl;
    try {
        Bureaucrat b("Lucas", 149);
        std::cout << b << std::endl;
        std::cout << "Première décrémentation:" << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        std::cout << "Deuxième décrémentation (devrait échouer):" << std::endl;
        b.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception attendue: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Signature de formulaire ===" << std::endl;
    try {
        Bureaucrat b("Michel", 75);
        Form f("Permis", 100, 50);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Signature de formulaire (grade trop bas) ===" << std::endl;
    try {
        Bureaucrat b("Paul", 100);
        Form f("Contrat", 50, 25);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
