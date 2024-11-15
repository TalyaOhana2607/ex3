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

int Vector::capacity() const
{
	return this->_capacity;
}

int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}

bool Vector::empty() const
{
	if (this->_size == 0)
		return true;
	return false;
}

void Vector::push_back(const int& val)
{
	if (this->_size == this->_capacity)
		this->reserve(this->_capacity + this->_resizeFactor);
	this->_elements[this->_size] = val;
	this->_size++;
}


int Vector::pop_back()
{
	if (this->_size > 0)
	{
		this->_size--;
		return this->_elements[this->_size];
	}
	else
	{
		std::cerr << "error: pop from empty vector" << std::endl;
		return -9999;
	}
}

void Vector::reserve(const int n)
{
	if (n > this->_capacity)
	{
		int* temp = this->_elements;
		int cp = this->_capacity + this->_resizeFactor;
		while (n > cp)
		{
			cp += this->_resizeFactor;
		}
		this->_elements = new int[cp];
		this->_capacity = cp;
		for (int i = 0; i < this->_size; i++)
		{
			this->_elements[i] = temp[i];
		}
		delete[] temp;

	}
}

void Vector::resize(const int n)
{
	if (n <= this->_capacity)
		this->_size = n;
	else if (n > this->_capacity)
	{
		this->reserve(n);
		this->_size = n;
	}
}

void Vector::assign(const int val)
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}

