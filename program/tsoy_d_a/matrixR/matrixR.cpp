#include "matrixR.h"
#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;

MatrixR::MatrixR(): nRow(defaultRow), nCol(defaultCol)
{
	pRows_ = new int*[nRow] {nullptr};

	for (int i(0); i < nRow; i++)
	{
		pRows_[0] = new int[nCol*nRow]{ int(0) };
		for (int i(0); i < nRow - 1; i++)
		{
			pRows_[i + 1] = pRows_[i] + nCol;
		}
	}
}

MatrixR::MatrixR(const int row, const int col) : nRow(row), nCol(col)
{
	if ((row <= 0) || (col <= 0)) { throw invalid_argument("Error: Size can't be less or equals 0"); }
	pRows_ = new int*[nRow] {nullptr};;

	for (int i(0); i < nRow; i++)
	{
		pRows_[0] = new int[nCol*nRow]{ int(0) };
		for (int i(0); i < nRow - 1; i++)
		{
			pRows_[i + 1] = pRows_[i] + nCol;
		}
	}
}

MatrixR::MatrixR(const MatrixR& rhs) : nRow(rhs.nRow), nCol(rhs.nCol)
{
	if (this != &rhs)
	{
		pRows_ = new int*[nRow] {nullptr};
		pRows_[0] = new int[nRow * nCol]{ int(0) };
		for (int i(0); i < nRow - 1; i++)
		{
			pRows_[i + 1] = pRows_[i] + nCol;
		}

		for (int j(0); j < nRow; j++)
		{
			for (int i(0); i < nCol; i++)
			{
				pRows_[j][i] = rhs.pRows_[j][i];
			}
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

void MatrixR::swap(MatrixR& lhs, MatrixR& rhs)
{
	int** t = lhs.pRows_;
	lhs.pRows_ = rhs.pRows_;
	rhs.pRows_ = t;
}

MatrixR& MatrixR::operator=(const MatrixR& rhs)
{
	if (this != &rhs)
	{
		MatrixR::swap(*this, MatrixR(rhs));
		nRow = rhs.nRow;
		nCol = rhs.nCol;
	}
	return *this;
}

bool MatrixR::operator==(const MatrixR& rhs) const
{
	bool result = true;
		for (int j(0); j < nRow; j++)
		{
			for (int i(0); i < nCol; i++)
			{
				if (pRows_[j][i] != rhs.pRows_[j][i])
				{
					result = false;
				}
			}
		}
		return result;
}


bool MatrixR::operator!=(const MatrixR& rhs) const
{
	return !(operator==(rhs));
}


int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	//if ((iRow < 0) || (iCol < 0) || (iRow >= nRow) || (nRow >= iCol))  { throw invalid_argument("Error2: Size can't be less or equals 0"); }
	return pRows_[iRow][iCol];
}

const int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	//if ((iRow < 0) || (iCol < 0) || (iRow >= nRow) || (nRow >= iCol)) { throw invalid_argument("Error3: Size can't be less or equals 0"); }
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

//MatrixR& MatrixR::resize(const ptrdiff_t r, const ptrdiff_t c)
//{
//	if ((r <= 0) || (c <= 0)) {
//		throw length_error("Error: Length eror - Size can't be less or equals 0");
//	}
//	if ((nRow != r) && (nCol != c))
//	{
//		int elementsRow = nRow;
//		if (nRow > r)
//		{
//			elementsRow = r;
//		}
//		int elementsCol = nCol;
//		if (nCol > c)
//		{
//			elementsCol = c;
//		}
//
//		int** pRows_new = new int*[ r ] { nullptr };
//		for (int i(0); i < nRow; i++)
//		{
//			pRows_new[0] = new int[r * c]{ int(0) };
//			for (int i(0); i < r - 1; i++)
//			{
//				pRows_new[i + 1] = pRows_[i] + c;
//			}
//		}
//
//		for (int j(0); j < elementsRow; j++)
//		{
//			for (int i{ 0 }; i < elementsCol; i++)
//			{
//				pRows_new[j][i] = pRows_[j][i];
//			}
//		}
//		delete[]  pRows_[0];
//		delete[]  pRows_;
//		pRows_ = pRows_new;
//		nRow = r;
//		nCol = c;
//	}
//	return *this;
//}