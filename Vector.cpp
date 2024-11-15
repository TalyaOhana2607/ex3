#include "Vector.h"

Vector::Vector(int n)
{
	if (n < 2)
		n == 2;
	
	_size = 0;
	_capacity = n;
	_resizeFactor = n;

	this->_elements = new int[this->_resizeFactor];
}
 
Vector::~Vector()
{
	if (this->_elements)
		delete[] this->_elements;

	this->_elements = NULL;
	this->_capacity = 0;
	this->_size = 0;

}

int Vector::size() const
{
	return this->_size;
}

