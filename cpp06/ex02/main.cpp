#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <cstdlib>  // Pour std::rand() et std::srand()
#include <ctime>    // Pour std::time()
#include <exception> // Pour std::bad_cast

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
            std::cout << "Generated class A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated class B" << std::endl;
            return new B();
        default:
            std::cout << "Generated class C" << std::endl;
            return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}


void identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

int main() {
    Base* ptr = generate();
    
    std::cout << "Identifying by pointer: ";
    identify(ptr);
    
    std::cout << "Identifying by reference: ";
    identify(*ptr);
    
    delete ptr;
    return 0;
}
