#include "matrixU.h"
#include<iostream>
#include<sstream>
#include <stdexcept>

using namespace std;

MatrixU::MatrixU() :nRow(defaultRow), nCol(defaultCol), pData_(new int[defaultRow * defaultCol] { int() })
{
}

MatrixU::MatrixU(const int row, const int col) : nRow(row), nCol(col)
{
	if ((row <= 0) || (col <= 0)) throw invalid_argument("Error: Size can't be less or equals 0");
	pData_ = new int[nCol*nRow]{ int() };
}

MatrixU::MatrixU(const MatrixU& rhs) :nRow(rhs.nRow), nCol(rhs.nCol), pData_(new int[rhs.nRow * rhs.nCol]{ int() })
{
	for (int j(0); j < nRow; j++)
	{
		for (int i{ 0 }; i < nCol; i++)
		{
			pData_[nCol * j + i] = rhs.pData_[nCol * j + i];
		}
	}
}

MatrixU::~MatrixU()
{
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
}

void MatrixU::swap(MatrixU& lhs, MatrixU& rhs)
{
	int* t = lhs.pData_;
	lhs.pData_ = rhs.pData_;
	rhs.pData_ = t;
}

MatrixU& MatrixU::operator=(const MatrixU& rhs)
{
	MatrixU::swap(*this, MatrixU(rhs));
	nRow = rhs.nRow;
	nCol = rhs.nCol;
	return *this;
}


bool MatrixU::operator==(const MatrixU& rhs) const
{
	bool b = true;
	for (int j(0); j < nRow; j++)
	{
		for (int i{ 0 }; i < nCol; i++)
		{
			if (pData_[nCol * j + i] != rhs.pData_[nCol * j + i])
			{
				b = false;
			}
		}
	}
	return b;
}

bool MatrixU::operator!=(const MatrixU& rhs) const
{
	return !(operator==(rhs));
}

int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow) || (iCol >= nCol)) { throw invalid_argument("Error2: Out of range"); }
	return pData_[nCol * iRow + iCol];
}

const int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow) || (iCol >= nCol)) { throw invalid_argument("Error3: Out of range"); }
	return pData_[nCol * iRow + iCol];
}


ostream& MatrixU::writeTo(std::ostream& ostrm) const
{
	if (pData_ != nullptr)
	{
		for (int j(0); j < nRow; j++)
		{
			for (int i{ 0 }; i < nCol; i++)
			{
				ostrm << pData_[nCol * j + i] << ' ';
			}
			ostrm << endl;
		}
	}
	else {
		ostrm << "Array was deleting";
	}
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const MatrixU& rhs)
{
	return rhs.writeTo(ostrm);
}


int MatrixU::Row() const
{
	return nRow;
}

int MatrixU::Col() const
{
	return nCol;
}

MatrixU& MatrixU::resize(const ptrdiff_t r, const ptrdiff_t c)
{
	if ((r <= 0) || (c <= 0)) {
		throw length_error("Error: Length eror - Size can't be less or equals 0");
	}	
	if ((nRow != r) && (nCol != c))
	{
		int elementsRow = nRow;
		if (nRow > r)
		{
			elementsRow = r;
		}
		int elementsCol = nCol;
		if (nCol > c)
		{
			elementsCol = c;
		}

		int* pData_new = new int[r * c]{ int() };

		for (int j(0); j < elementsRow; j++)
		{
			for (int i{ 0 }; i < elementsCol; i++)
			{
				pData_new[c * j + i] = pData_[nCol * j + i];
			}
		}
		delete[] pData_;
		pData_ = pData_new;
		nRow = r;
		nCol = c;
	}
	return *this;
}