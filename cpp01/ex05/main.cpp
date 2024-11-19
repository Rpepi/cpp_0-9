#include "Harl.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    
    std::string input(argv[1]);

    if (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR") {
        std::cerr << "Invalid level: " << input << std::endl;
        return 1;
    }

    Harl harl;
    
    harl.complain(input);
    return 0;
}
