#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <iosfwd>

using namespace std;

class Array
{
public:
	Array();
	Array(const int n);
	Array(const Array& rhs);
	~Array();
	Array& operator=(const Array& rhs);
	int& operator[](const ptrdiff_t i);
	const int& operator[](const ptrdiff_t i) const;
	Array& resize(const int n);
	int lenth() const; // ���������� ������
	int physicalLenth() const; // ���������� ������
	ostream& writeTo(std::ostream& ostrm) const;
	void insert(const int n, const int i); // ������� � ������� array[i], � �� i-�� �������
	void remove(const int i);
	//istream& readFrom(const std::istream& istrm);
private:
	static const int defaultSize = 5;
	static const int max{ 32 }; // ���������� ������, �� �������� ���������� ������ ������������� �����
	                            // ����� ������������� �� 5
	int physicalSize(const int n); // ����� ������������ ���������� ������, �� �������� ����� ��������� ������
	                               // � ������ ������������ ���� max
	                               // ������������ ���������� ���������� �������� � ���� physSize
	Array& changePhysycSize(const int n); // ��������� ����������� ������� �� ������� n, ������������ � resize
	ptrdiff_t physSize{ defaultSize * 2 }; // ����, �������� ������ ����������� �������
	ptrdiff_t size{ defaultSize }; // ���������� ������
	int* pData_{ nullptr };
	static const char scob1{ '{' };
	static const char scob2{ '}' };
	static const char separator{ ',' };
};

ostream& operator<<(std::ostream& ostrm, const Array& rhs);
//istream& operator>>(std::istream& istrm, const Array& rhs);
#endif 
