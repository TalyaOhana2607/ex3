#include "Vector.h"

Vector::Vector(int n)
{
	//checl if illegal value
	if (n < 2)
	{
		n = 2;
	}
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
	//check if size equal to capacital (if it's true -> We will allocate a larger array
	if (this->_size == this->_capacity)
		this->reserve(this->_capacity + this->_resizeFactor);
	// add the value at the end of free space
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
	// if not enough capacity in the vector
	if (n > this->_capacity)
	{
		int* temp = this->_elements;
		//calculatation of next allocation
		int cp = this->_capacity + this->_resizeFactor;
		while (n > cp)
		{
			cp += this->_resizeFactor;
		}
		//create new array
		this->_elements = new int[cp];
		this->_capacity = cp;
		//copy the old values
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

void Vector::resize(const int n, const int& val)
{
	int i = 0;
	int startPoint = this->_size;

	this->resize(n);
	for (i = startPoint; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}

Vector::Vector(const Vector& other)
{
	this->_size = other.size();
	this->_capacity = other.capacity();
	this->_resizeFactor = other.resizeFactor();
	this->_elements = new int[other.capacity()];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	// copy fields
	this->_size = other.size();
	this->_capacity = other.capacity();
	this->_resizeFactor = other.resizeFactor();
	// allocating memory 
	this->_elements = new int[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
	return *this;
}

int& Vector::operator[](int n) const
{
	if (n >= this->_size || n < 0)
	{
		std::cerr << "error: illegal index" << std::endl;
		n = 0;
	}
	return this->_elements[n];
}

Vector& Vector::operator+=(const Vector& other)
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] += other._elements[i];

	}
	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] -= other._elements[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& other) const
{
	Vector v3 = *this;  // Copy vector using copy constructor
	v3 += other; // use substruction assignment operator to substruct other from result
	return v3; 
}

Vector Vector::operator-(const Vector& other) const
{
	Vector v3 = *this; // Copy vector using copy constructor
	v3 -= other; // use substruction assignment operator to substruct other from result
	return v3;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "Vector info:\nCapacity is " << v.capacity() << "\nSize is " << v.size() << "\n{";
	for (int i = 0; i < v.size(); i++)
	{
		os << v[i]; // uses element access operator
		if (i < v.size() - 1) // not last element
		{
			os << ",";
		}
	}
	os << "}\n";
	return os;
}