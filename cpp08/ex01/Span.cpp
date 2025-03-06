#include "Span.hpp"

Span::Span(const unsigned int N) : size(N) {
}


Span::~Span() {}


void Span::addNumber(unsigned int N) 
{
    if (span.size() == size)
        throw  Span::Spanisfull();
    span.push_back(N);
}



unsigned int Span::longestSpan()
{
    if (span.size() < 2)
        throw Span::Spanistooshort();
    std::vector<unsigned int>::iterator begin = span.begin();
    std::vector<unsigned int>::iterator end = span.end() - 1;

    std::vector<unsigned int>::iterator shortest = std::min_element(begin, end);
    std::vector<unsigned int>::iterator longest = std::max_element(begin, end);

    std::cout << "la plus longue difference est " ;
    return (*longest - *shortest);
}

unsigned int Span::shortestSpan()
{
    if (span.size() < 2)
        throw Span::Spanistooshort();
    
    std::vector<unsigned int> sortedSpan = span;
    std::sort(sortedSpan.begin(), sortedSpan.end());
    unsigned int minDiff = sortedSpan[1] - sortedSpan[0];

    for (size_t i = 1; i < sortedSpan.size() - 1; i++) {
        unsigned int diff = sortedSpan[i + 1] - sortedSpan[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    std::cout << "la plus courte difference est ";
    return (minDiff);
} 