#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &coppied): _array(new T[coppied._size]), _size(coppied._size)
{
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = coppied._array[i];
}

template <typename T>
Array<T>::~Array() { delete[] _array; }

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return (*this);
	delete[] this->_array;
	this->_array = new T[other._size];
	this->_size = other._size;
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = other._array[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size || index < 0)
		throw IndexOutOfRangeException();
	return _array[index];
}

template <typename T>
unsigned int	Array<T>::size() const { return _size; }

template <typename T>
const char*	Array<T>::IndexOutOfRangeException::what() const throw() { return ("Index out of range"); }
