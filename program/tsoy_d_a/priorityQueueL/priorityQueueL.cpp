#include "priorityQueueL.h"
#include <iostream>
#include <stdexcept>


PriorityQueueL::Node::Node(Node* pNext, const int& v): pNext_(pNext), pData_(v)
{
}

bool PriorityQueueL::isEmpty() const
{
	return (pHead_ == nullptr);
}

PriorityQueueL::PriorityQueueL(const PriorityQueueL& rhs)
{
	Node* copyFrom(pHead_);
	while (copyFrom != nullptr)
	{
		push(copyFrom->pData_);
		copyFrom = copyFrom->pNext_;
	}
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
	pTail_->pNext_ = new Node(nullptr, v);
	if (isEmpty())
	{
		pHead_ = pTail_;
	}
}

void PriorityQueueL::pop()
{
	if (!isEmpty())
	{
		Node* pDelete(pHead_);
		pHead_ = pHead_->pNext_;
		delete pDelete;
	}
}

int& PriorityQueueL::bot()
{
	if (isEmpty()) {
		throw std::invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

const int& PriorityQueueL::bot() const
{
	if (isEmpty()) {
		throw std::invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

std::ostream& PriorityQueueL::writeAll(std::ostream& ostrm) const
{
	Node* copy(pHead_);
	while (pHead_ != nullptr)
	{
		ostrm << copy->pData_ << std::endl;
		copy = pHead_->pNext_;
	}
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs)
{
	return rhs.writeAll(ostrm);
}