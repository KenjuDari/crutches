#ifndef MATRIXU_H
#define MATRIXU_H

#include <stddef.h>
#include <iosfwd>

using namespace std;

class MatrixU
{
public:
	MatrixU();
	MatrixU(const int row, const int col);
	MatrixU(const MatrixU& rhs);
	~MatrixU();
	MatrixU& operator=(const MatrixU& rhs);
	bool operator==(const MatrixU& rhs) const;
	bool operator!=(const MatrixU& rhs) const;
	int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
	const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
	ostream& writeTo(std::ostream& ostrm) const;
	int Row() const;
	int Col() const;
	MatrixU& resize(const ptrdiff_t r, const ptrdiff_t c);
private:
	const ptrdiff_t defaultRow{ 2 };
	const ptrdiff_t defaultCol{ 2 };
	ptrdiff_t nRow{ 0 };
	ptrdiff_t nCol{ 0 };
	int* pData_{ nullptr };
	void swap(MatrixU& lhs, MatrixU& rhs);
};

ostream& operator<<(std::ostream& ostrm, const MatrixU& rhs);

#endif 