#include "Array.hpp"

int main()
{
    Array<int> arr(5);    // _size sera 5
    std::cout << arr.size() << std::endl;
    
    arr[4] = 42;         // OK car 4 < _size
    try {
        arr[6] = 42;         // Exception car 5 >= _size
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}