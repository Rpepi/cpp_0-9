#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T *array;
		unsigned int _size;

	public:
		Array() : array(NULL), _size(0) {}
		
		Array(unsigned int n) : _size(n) {
			array = new T[n]();
		}
		
		// Constructeur par copie
		Array(Array const &src) : _size(src._size) {
			array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				array[i] = src.array[i];
		}
		
		// Opérateur d'assignation
		Array &operator=(Array const &src) {
			if (this != &src) {
				delete[] array;
				_size = src._size;
				array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					array[i] = src.array[i];
			}
			return *this;
		}
		
		// Destructeur
		~Array() {
			delete[] array;
		}
		
		// Opérateur []
		T &operator[](unsigned int i) {
			if (i >= _size)
				throw std::out_of_range("Index out of bounds");
			return array[i];
		}
		
		// Getter pour la taille
		unsigned int size() const {
			return _size;
		}
};

#endif