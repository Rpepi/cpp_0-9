#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Un cerveau se développe" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Une idée vide";
}

Brain::Brain(const Brain& other) {
    std::cout << "Un cerveau est cloné" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "Un cerveau cesse de fonctionner" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return "";
} 