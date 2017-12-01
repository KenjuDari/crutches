#include "stackR.h"
#include <iostream>
#include <stdexcept>


void StackR::copy(const StackR& rhs, const ptrdiff_t& lenth)
{
	for (int i(0); i <= lenth; i++)
	{
		pData_[i] = rhs.pData_[i];
	}
	pHead_ = lenth;
}


StackR::StackR(const StackR& rhs) 
{
	if (!rhs.isEmpty()) {
		pData_ = new int[rhs.size]{ int() };
		copy(rhs, rhs.pHead_);
		empty = false;
	}
}


StackR::~StackR() {
	delete[] pData_;
	//empty = true;
	//pHead_ = 0;
}

void StackR::swap(StackR& rhs)
{
	int* t_(pData_);
	pData_ = rhs.pData_;
	rhs.pData_ = t_;
}

StackR& StackR::operator=(const StackR& rhs)
{
	if (!rhs.isEmpty()) {
		if (isEmpty()) {
			pData_ = new int[rhs.size]{ int() };
			copy(rhs, rhs.pHead_);
			empty = false;
		}
		else {
				swap(StackR(rhs));
				pHead_ = rhs.pHead_;
		}
	}
	return *this;
}

bool StackR::isEmpty() const {
	return empty;
}

ptrdiff_t StackR::countSize(const ptrdiff_t& n) const
{
	if (n < max) {
		return n * 2;
	}
	else {
		return n + 8;
	}
}


StackR& StackR::push(const int& v)
{
	if (isEmpty()) {
		pData_ = new int[defaultSize] {int()};
		size = defaultSize;
		empty = false;
	}
	if (pHead_ == (size - 1)) {
		int* pData_new = new int[countSize(pHead_+1)]{ int() };
		for (int i(0); i <= pHead_; i++)
		{
			pData_new[i] = pData_[i];
		}
		delete[] pData_;
		pData_ = pData_new;
	}
	pHead_++;
	pData_[pHead_] = v;

	return *this;
}

StackR& StackR::pop()
{
	if (pHead_ != -1)
	{
		pHead_--;
	}
	if (pHead_ == -1)
	{
		empty = true;
	}
	return *this;
}

int& StackR::top()
{
	if (isEmpty()) {
		throw std::invalid_argument("Error: stack is empty");
	}
	return pData_[pHead_];
}

const int& StackR::top() const
{
	if (isEmpty()) {
		throw std::invalid_argument("Error: stack is empty");
	}
	return pData_[pHead_];
}

std::ostream& StackR::writeTo(std::ostream& ostrm) const
{
	if (pHead_ > -1) {
		for (int i(pHead_); i >= 0; i--)
		{
			ostrm << pData_[i] << std::endl;
		}
	}
	else
	{
		ostrm << "Stack is Empty";
	}
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const StackR& rhs)
{
	return rhs.writeTo(ostrm);
}