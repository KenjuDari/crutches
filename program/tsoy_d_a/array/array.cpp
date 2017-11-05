#include "array.h"
#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;

Array::Array() :pData_(new int[physSize] { int() })
{
}

Array::Array(const int n): size(n)
{
	if (n <= 0) throw invalid_argument("Error: Size can't be less or equals 0");
	pData_= new int[physicalSize(n)]{ int() };
}


Array::Array(const Array& rhs): size(rhs.size), pData_(new int[physicalSize(rhs.size)]{ int() })
{
	if (this != &rhs)
	{
		for (int i(0); i < rhs.size; i++)
			pData_[i] = rhs.pData_[i];
	}
}

Array::~Array()
{
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}		
}

int Array::physicalSize(const int n)
{
	if (n < max) {
		physSize = n * 2;
	}
	else {
		physSize = n + 8;
	}
	return physSize;
}


void Array::swap(Array& lhs, Array& rhs)
{
	int* t_ = lhs.pData_;
	lhs.pData_ = rhs.pData_;
	rhs.pData_ = t_;
}

Array& Array::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
	swap(*this, Array(rhs));  
	size = rhs.size;
	}
	return *this;
}

int& Array::operator[](const ptrdiff_t i)
{
	//if ((i <= 0) || (i >= size)) { throw invalid_argument("Error2: Out of range in insert"); }  //вызывает искдючение
	return pData_[i];
}

const int& Array::operator[](const ptrdiff_t i) const
{
	//if ((i <= 0) || (i >= size)) {
	//	throw invalid_argument("Error3: Out of range in insert"); }
	return pData_[i];
}

bool Array::operator==(const Array& rhs) const
{
	bool result = true;
	for (int i(0); i < size; i++)
	{
		if (pData_[i] != rhs.pData_[i])
		{
			result = false;
		}
	}
	return result;
}


bool Array::operator!=(const Array& rhs) const
{
	return !(operator==(rhs));
}



Array& Array::resize(const int n)
{
	if (n <= 0) {
		throw length_error("Error: Length eror - Size can't be less or equals 0"); }
		
	if (n <= physSize) {
		size = n;
	}		          // если новый размер влезает в физический размер
	              // просто меняем значение лог. размера
	else
	{
		int logichSize(0);
		if (size < n) {
			logichSize = size; //если новое значение меньше логического размер
		}                     	// обрезаем массив				  
		else {
			logichSize = n;
		}

		int* pData_new = new int[physicalSize(n)] {int()};
		for (int i(0); i < logichSize; i++)
		{
			pData_new[i] = pData_[i]; // записываем старые значения
		}
		delete[] pData_;
		pData_ = pData_new; 
		size = n; //устанавливаем логически размер
	}
	return *this;
}

int Array::lenth() const
{
	return size;
}

int Array::physicalLenth() const
{
	return physSize;
}

ostream& Array::writeTo(std::ostream& ostrm) const
{
	if (!(pData_ == nullptr))
	{
		ostrm << scob1 << ' ';
		for (int i(0); i < size - 1; i++)
			ostrm << pData_[i] << ", ";
		ostrm << pData_[size - 1] << ' ' << scob2;
	}
	else {
		ostrm << "Array was deleting";
	}
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
	return rhs.writeTo(ostrm);
}

void Array::insert(const int n, const int i)
{
	if ((i < 0) || (i >= size)) {
		throw out_of_range("Error: Out of range in insert");
	}
		
	if (size == physSize) // если физического размера не хватает на новое значение
	{
		resize(size + 1);
		size--;
	}

	for (int j(size); j > i; j--)
	{
		pData_[j] = pData_[j - 1];
	}
	pData_[i] = n;
	size++;
}

void Array::remove (const int i)
{
	if ((i < 0) || (i >= size)) {
		throw out_of_range("Error: Out of range in remove");
	}
	for (int j(i); j < size - 1; j++)
	{
		pData_[j] = pData_[j + 1];
	}
	size--;
}