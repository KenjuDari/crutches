#include "priorityqueuel.h"
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
	while ((copyTo != pHead_) && (copyFrom != rhs.pHead_))
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
				//push(copyFrom->pData_);
				pHead_->pNext_ = new Node(nullptr, copyFrom->pData_);
				pHead_ = pHead_->pNext_;
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
		Node* search = pTail_;
		if (pTail_ == pHead_)
		{
			if (pHead_->pData_ > v) {
				pHead_->pNext_ = new Node(nullptr, v);
				pTail_ = pHead_;
				pHead_ = pHead_->pNext_;
			}
			else {
				pTail_ = new Node(pHead_, v);
			}
			return;
		}
		if (pTail_->pData_ < v) {
			pTail_ = new Node(pTail_, v);
			return;
		}
		while (search->pNext_->pData_ > v) 
		{
			search = search->pNext_;
			if (search->pNext_ == nullptr) {
				search->pNext_ = new Node(nullptr, v);
				pHead_ = search->pNext_;
				return;
			}
		}
		search->pNext_ = new Node(search->pNext_, v);
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
	if (!isEmpty())
	{
		Node* writeAll = pTail_;
		while (writeAll != nullptr)
		{
			ostrm << writeAll->pData_ << std::endl;
			writeAll = writeAll->pNext_;
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