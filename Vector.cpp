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
 