#ifndef MATRIXR_H
#define MATRIXR_H

#include <stddef.h>
#include <iosfwd>

using namespace std;

class MatrixR
{
public:
	MatrixR();
	MatrixR(const int row, const int col);
	MatrixR(const MatrixR& rhs);
	~MatrixR();
	MatrixR& operator=(const MatrixR& rhs);
	int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
	const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
	ostream& writeTo(std::ostream& ostrm) const;
	int lenth() const;
private:
	const ptrdiff_t defaultRow{ 2 };
	const ptrdiff_t defaultCol{ 2 };
	ptrdiff_t nRow{ 0 };
	ptrdiff_t nCol{ 0 };
	int** pRows_{ nullptr };
};

ostream& operator<<(std::ostream& ostrm, const MatrixR& rhs);

#endif 