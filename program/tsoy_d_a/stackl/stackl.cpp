#include "stackl.h"
#include <stdexcept>
#include <iostream>


using namespace std;

StackL::Node::Node(Node* pNext, const int& value) : pNext_(pNext), pData_(value)
{
}

bool StackL::isEmpty() const
{
	return (pHead_ == nullptr);
}

StackL::~StackL()
{
	while (!isEmpty()) {
		pop();
	}
}

StackL::StackL(const StackL& rhs)
{
	if (!rhs.isEmpty()) {
		Node* pCopyFrom(rhs.pHead_->pNext_);
		Node* pCopyTo = new Node(nullptr, rhs.pHead_->pData_);
		pHead_ = pCopyTo;
		while (pCopyFrom != nullptr)
		{
			pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pData_);
			pCopyTo = pCopyTo->pNext_;
			pCopyFrom = pCopyFrom->pNext_;
		}
	}
}

StackL& StackL::operator=(const StackL& rhs)
{
	Node* pCopyTo = pHead_;
	Node* pCopyFrom = rhs.pHead_;
	while ((pCopyTo->pNext_ != nullptr) && (pCopyFrom->pNext_ != nullptr))
	{
		pCopyTo->pData_ = pCopyFrom->pData_;
		pCopyTo = pCopyTo->pNext_;
		pCopyFrom = pCopyFrom->pNext_;
	}
	if ( (pCopyTo->pNext_ == nullptr) && (pCopyFrom->pNext_ != nullptr))
	{
		pCopyTo->pData_ = pCopyFrom->pData_;
		pCopyFrom = pCopyFrom->pNext_;
		while (pCopyFrom != nullptr)
		{
			pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pData_);
			pCopyTo = pCopyTo->pNext_;
			pCopyFrom = pCopyFrom->pNext_;
		}
	}
	else
	{
		if ((pCopyFrom->pNext_ == nullptr) && (pCopyTo->pNext_ != nullptr))
		{
			pCopyTo->pData_ = pCopyFrom->pData_;
			Node* pContinue(pCopyTo->pNext_);
			pCopyTo->pNext_ = nullptr;
			Node* pDelete;
			while (pContinue != nullptr)
			{
				pDelete = pContinue;
				pContinue = pDelete->pNext_;
				delete pDelete;
			}
		}
	}
	return *this;
}

void StackL::push(const int& value)
{
	pHead_ = new Node(pHead_, value);
}

void StackL::pop()
{
	if (!isEmpty()) {
		Node* pDelete(pHead_);
		pHead_ = pDelete->pNext_;
		delete pDelete;
	}
}

int& StackL::top()
{
	if (isEmpty()) {
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

const int& StackL::top() const
{
	if (isEmpty()) {
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

ostream& operator<<(std::ostream& ostrm, const StackL& rhs)
{
	return rhs.writeAll(ostrm);
}

ostream& StackL::writeAll(std::ostream& ostrm) const
{
	if (!isEmpty()) {
		StackL copyStack(*this);
		while (!copyStack.isEmpty())
		{
			ostrm << copyStack.top() << endl;
			copyStack.pop();
		}
	}
	else {
		ostrm << "Stack is Empty";
	}
	return ostrm;
}