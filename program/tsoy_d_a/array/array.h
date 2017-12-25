#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <iosfwd>


class Array
{
public:
	Array();
	Array(const int n);
	Array(const Array& rhs);
	~Array();
	Array& operator=(const Array& rhs);
	int& operator[](const ptrdiff_t i);
	bool operator==(const Array& rhs) const;
	bool operator!=( const Array& rhs) const;
	const int& operator[](const ptrdiff_t i) const;
	Array& resize(const int n);
	int lenth() const; // логический размер
	int physicalLenth() const; // физический размер
	std::ostream& writeTo(std::ostream& ostrm) const;
	void insert(const int n, const int i); // вставка в позицию array[i], а не i-ый элемент
	void remove(const int i);
	//istream& readFrom(const std::istream& istrm);
private:
	static const int defaultSize = 8;
	static const int max{ 32 }; // физический размер, до которого физический массив увеличивается вдвое
	                            // далее увеличивается на 8
	int physicalSize(const int n); // метод возвращающий физический размер, до которого нужно увеличить массив
	                               // с учетом статического поля max
	                               // одновременно записывает полученное значение в поле physSize
	ptrdiff_t physSize{ defaultSize * 2 }; // поле, хранящее размер физического массива
	ptrdiff_t size{ defaultSize }; // логический размер
	int* pData_{ nullptr };
	void swap(Array& lhs, Array& rhs);
	static const char scob1{ '{' };
	static const char scob2{ '}' };
	static const char separator{ ',' };
};

std::ostream& operator<<(std::ostream& ostrm, const Array& rhs);
//istream& operator>>(std::istream& istrm, const Array& rhs);
#endif 
