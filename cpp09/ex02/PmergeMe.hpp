#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <ctime>
# include <string>
# include <sstream>
# include <iomanip>
# include <exception>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        
        void _mergeInsertSortVector(std::vector<int>& arr);
        void _insertionSortVector(std::vector<int>& arr, int left, int right);
        void _mergeVector(std::vector<int>& arr, int left, int mid, int right);
        
        void _mergeInsertSortDeque(std::deque<int>& arr);
        void _insertionSortDeque(std::deque<int>& arr, int left, int right);
        void _mergeDeque(std::deque<int>& arr, int left, int mid, int right);

        void _displaySequence(const std::vector<int>& seq) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        ~PmergeMe();
        
        PmergeMe& operator=(const PmergeMe& rhs);

        void processInput(int argc, char** argv);
        void sort();
};

#endif
