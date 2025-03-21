#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : _vec(src._vec), _deq(src._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _vec = rhs._vec;
        _deq = rhs._deq;
    }
    return *this;
}

void PmergeMe::_displaySequence(const std::vector<int>& seq) const {
    for (size_t i = 0; i < seq.size() && i < 5; ++i)
        std::cout << seq[i] << " ";
    if (seq.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::processInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int num;
        
        if (!(ss >> num) || num < 0 || !ss.eof()) {
            throw std::runtime_error("Error");
        }
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

void PmergeMe::_mergeVector(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

void PmergeMe::_insertionSortVector(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::_mergeInsertSortVector(std::vector<int>& arr) {
    const int THRESHOLD = 10;
    int n = arr.size();
    
    for (int size = 1; size < n; size = 2 * size) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            
            if (right - left + 1 <= THRESHOLD)
                _insertionSortVector(arr, left, right);
            else
                _mergeVector(arr, left, mid, right);
        }
    }
}

void PmergeMe::_mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

void PmergeMe::_insertionSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::_mergeInsertSortDeque(std::deque<int>& arr) {
    const int THRESHOLD = 10;
    int n = arr.size();
    
    for (int size = 1; size < n; size = 2 * size) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            
            if (right - left + 1 <= THRESHOLD)
                _insertionSortDeque(arr, left, right);
            else
                _mergeDeque(arr, left, mid, right);
        }
    }
}

void PmergeMe::sort() {
    std::cout << "Before: ";
    _displaySequence(_vec);

    clock_t start = clock();
    _mergeInsertSortVector(_vec);
    clock_t end = clock();
    double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    _mergeInsertSortDeque(_deq);
    end = clock();
    double time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    _displaySequence(_vec);

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " << std::fixed 
              << std::setprecision(5) << time_deq << " us" << std::endl;
}
