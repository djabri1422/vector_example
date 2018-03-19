#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() : elements_(nullptr), size_(0), capacity_(0)
{
}

vector_t::vector_t(vector_t const & other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;
	
	elements_ = new int [capacity_];
	for (size_t i = 0; i < capacity_; i++)
	{
		elements_[i] = other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this != &other)
	{
		if(elements_ != nullptr)
			delete[]elements_;
		elements_ = new int [other.capacity_];

		for (size_t i = 0; i < other.capacity_; i++)
		{
			elements_[i] = other.elements_[i];
		}
		capacity_ = other.capacity_;
		size_ = other.size_;
	}
		return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	for (size_t i = 0; i < other.capacity_; i++)
	{
		if (elements_[i] == other.elements_[i])
		{
			return false;
		}
	}
	
	return true;
}

vector_t::~vector_t()
{
	if(elements_ != nullptr)
	{
		delete[]elements_;
	}
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if (capacity_ == 0)
	{
		capacity_ = 1;
		elements_ = new int [1];
		size_ = 1;
	}
	if ( size_ == capacity_)
	{
		capacity_ *= 2;
		int *temp_elements = new int [capacity_];
		for (size_t i = 0; i < capacity_; i++)
		{
			temp_elements[i] = elements_[i];
		}
		
		delete[]elements;
		
		for (size_t i = 0; i < size_; i++)
		{
			elements_[i] = temp_elements[i];	
		}
	}
	
	elements_[size_++] = value;
}

void vector_t::pop_back()
{
	if (size_ == 0)
	{
		
	}
	
	if (size_ <= ( capacity_ / 4 ))
	{
		capacity_ = capacity_ / 2;
		size--;
		int * temp_elements = new int [capacity_];
		for (int i = 0; i < size_; i++)
			temp_elements[i] = elements_[i];
		
		delete[]elements_;
		
		elements_ = temp_elements;
	}
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[0];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return !(lhs == rhs);
}
