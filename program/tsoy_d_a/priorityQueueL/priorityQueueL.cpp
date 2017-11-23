#include "priorityQueueL.h"
#include <iostream>
#include <stdexcept>


PriorityQueueL::Node::Node(Node* pNext, const int& v): pNext_(pNext), pData_(v)
{
}

bool PriorityQueueL::isEmpty() const
{
	return (pTail_ == nullptr);
}

PriorityQueueL::PriorityQueueL(const PriorityQueueL& rhs)
{
	Node* copyFrom(rhs.pTail_);
	while (copyFrom != nullptr)
	{
		push(copyFrom->pData_);
		copyFrom = copyFrom->pNext_;
	}
}
PriorityQueueL& PriorityQueueL::operator=(const PriorityQueueL& rhs)
{
	Node* copyFrom(rhs.pTail_);
	Node* copyTo(pTail_);
	while ( (copyTo != pHead_) && (copyFrom != rhs.pHead_) )
	{
		copyTo->pData_ = copyFrom->pData_;
		copyTo = copyTo->pNext_;
		copyFrom = copyFrom->pNext_;
	}
	if ((copyTo != pHead_) && (copyFrom != rhs.pHead_))
	{
		copyTo->pData_ = copyFrom->pData_;
	}
	else
	{
		if ((copyTo == pHead_) && (copyFrom != rhs.pHead_))
		{
			copyTo->pData_ = copyFrom->pData_;
			while (copyFrom != nullptr)
			{
				push(copyFrom->pData_);
				copyFrom = copyFrom->pNext_;
			}
		}
		else
		{
			copyTo->pData_ = copyFrom->pData_;
			pHead_ = copyTo;
			pHead_->pNext_ = nullptr;
			copyTo = copyTo->pNext_;
			Node* pDelete(copyTo);
			while (copyTo != nullptr)
			{
				copyTo = copyTo->pNext_;
				delete pDelete;
				pDelete = copyTo;
			}
		}
	}
	return *this;
}

PriorityQueueL::~PriorityQueueL()
{
	while (!isEmpty())
	{
		pop();
	}
}

void PriorityQueueL::push(const int& v)
{
	if (isEmpty())
	{
		pHead_ = new Node(nullptr, v);
	    pTail_ = pHead_;
	}
	else
	{
		pHead_->pNext_ = new Node(nullptr, v);
		pHead_ = pHead_->pNext_;
	}
}

void PriorityQueueL::pop()
{
	if (!isEmpty())
	{
		Node* pDelete(pTail_);
		pTail_ = pTail_->pNext_;
		delete pDelete;
	}
}

int& PriorityQueueL::bot()
{
	if (isEmpty()) {
		throw std::invalid_argument("Error: Stack is Empty");
	}
	return pTail_->pData_;
}

const int& PriorityQueueL::bot() const
{
	if (isEmpty()) {
		throw std::invalid_argument("Error: Stack is Empty");
	}
	return pTail_->pData_;
}

std::ostream& PriorityQueueL::writeAll(std::ostream& ostrm) const
{
	//if (!isEmpty())
	//{
	//	Node* copy(pTail_);
	//	while (copy != nullptr)
	//	{
	//		ostrm << copy->pData_ << std::endl;
	//		copy = copy->pNext_;
	//	}
	//}
	if (!isEmpty())
	{
		PriorityQueueL copy(*this);
		while (!copy.isEmpty())
		{
			ostrm << copy.bot() << std::endl;
			copy.pop();
		}
	}
	else
	{
		ostrm << "Queue is Empty";
	}
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs)
{
	return rhs.writeAll(ostrm);
}