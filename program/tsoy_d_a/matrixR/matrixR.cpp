#include "matrixR.h"
#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;

MatrixR::MatrixR(): nRow(defaultRow), nCol(defaultCol)
{
	pRows_ = new int*[nRow];

	for (int i(0); i < nRow; i++)
	{
		pRows_[0] = new int[nCol*nRow];
		for (int i(0); i < nRow - 1; i++)
		{
			pRows_[i + 1] = pRows_[i] + nCol;
		}
	}
}

MatrixR::MatrixR(const int row, const int col) : nRow(row), nCol(col)
{
	if ((row <= 0) || (col <= 0)) { throw invalid_argument("Error: Size can't be less or equals 0"); }
	pRows_ = new int*[nRow];

	for (int i(0); i < nRow; i++)
	{
		pRows_[0] = new int[nCol*nRow];
		for (int i(0); i < nRow - 1; i++)
		{
			pRows_[i + 1] = pRows_[i] + nCol;
		}
	}
}

MatrixR::~MatrixR()
{
	if (!(pRows_ == nullptr))
	{
		delete[]  pRows_[0];
		delete[]  pRows_;
		pRows_ = nullptr;
	}
}

int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	//if ((iRow <= 0) || (iCol <= 0)) { throw invalid_argument("Error2: Size can't be less or equals 0"); }
	return pRows_[iRow][iCol];
}

const int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	//if ((iRow <= 0) || (iCol <= 0)) { throw invalid_argument("Error3: Size can't be less or equals 0"); }
	return pRows_[iRow][iCol];
}

ostream& MatrixR::writeTo(std::ostream& ostrm) const
{
	if (!(pRows_ == nullptr))
	{
		for (int j(0); j < nRow; j++)
		{
			for (int i(0); i < nCol; i++)
			{
				ostrm << pRows_[j][i] << ' ';
			}
			ostrm << endl;
		}
	}
	else
	{
		ostrm << "Array was deleting";
	}
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const MatrixR& rhs)
{
	return rhs.writeTo(ostrm);
}

int MatrixR::lenth() const
{
	return nCol * nRow;
}