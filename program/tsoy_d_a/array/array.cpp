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
		//swap(*this, Array(rhs));  зацикливается
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
	if (n < max)
		physSize = n * 2;
	else
		physSize = n + 5;

	return physSize;
}


Array& Array::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		pData_ = new int[physicalSize(rhs.size)]{ int() };
		for (int i(0); i < rhs.size; i++)
			pData_[i] = rhs.pData_[i];
	//swap(*this, Array(rhs));  зацикливается
	}
	return *this;
}

int& Array::operator[](const ptrdiff_t i)
{
	return pData_[i];
}

const int& Array::operator[](const ptrdiff_t i) const
{

	return pData_[i];
}

Array& Array::changePhysycSize(const int n)
{
	int logichSize(0);
	if (size < n)
		logichSize = size; //если новое значение меньше логического размер
	                       // обрезаем массив
	else
		logichSize = n;

	int* pData_old = new int[size] {int()};
	swap(pData_old, pData_); // запоминаем старые значения
	delete[] pData_;
	pData_ = new int[n]{ int() }; // создаем новый массив с новым размером
	for (int i(0); i < logichSize; i++)
	{
		pData_[i] = pData_old[i]; // записываем старые значения
	}
	return *this;
}

Array& Array::resize(const int n)
{
	if (n <= 0) throw length_error("Error: Length eror - Size can't be less or equals 0");
	if (n <= physSize)
		size = n; // если новый размер влезает в физический размер
	              // просто меняем значение лог. размера
	else
	{
		changePhysycSize(physicalSize(n)); // меняем физический массив с запасом
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
	else
		ostrm << "Array was deleting";
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
	return rhs.writeTo(ostrm);
}

void Array::insert(const int n, const int i)
{
	if ((i < 0) || (i >= size )) throw out_of_range("Error: Out of range in insert");
		
	if (size == physSize) // если физического размера не хватает на новое значение
	{
		changePhysycSize(physicalSize(size));
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
	if ((i < 0) || (i >= size)) throw out_of_range("Error: Out of range in remove");
	for (int j(i); j < size - 1; j++)
	{
		pData_[j] = pData_[j + 1];
	}
	size--;
}