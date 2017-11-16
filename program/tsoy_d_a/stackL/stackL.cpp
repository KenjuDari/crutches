#include "stackL.h"
#include <stdexcept>
#include <iostream>


using namespace std;

StackL::Node::Node(Node* pNext, const int& value) : pNext_(pNext), data_(value)
{
}

bool StackL::isEmpty() const
{
	return (pHead_ == nullptr);
}

StackL::~StackL()
{
	while (!isEmpty())
	{
		pop();
	}
}

StackL::StackL(const StackL& rhs)
{
	StackL turned;
	Node* pForget(rhs.pHead_);
	while (nullptr != (pForget))
	{
		turned.push(pForget -> data_);
		pForget = pForget -> pNext_;
	}
	while (!turned.isEmpty())
	{
		push(turned.top());
		turned.pop();
	}
}

StackL& StackL::operator=(const StackL& rhs)
{
	StackL turned;
	Node* pForget(rhs.pHead_);
	while (nullptr != (pForget))
	{
		turned.push(pForget->data_);
		pForget = pForget->pNext_;
	}
	while (!turned.isEmpty())
	{
		push(turned.top());
		turned.pop();
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
	return pHead_->data_;
}

const int& StackL::top() const
{
	if (isEmpty()) {
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->data_;
}

ostream& operator<<(std::ostream& ostrm, const StackL& rhs)
{
	return rhs.writeAll(ostrm);
}

ostream& StackL::writeAll(std::ostream& ostrm) const
{
	StackL copyStack(*this);
	while (!copyStack.isEmpty())
	{
		ostrm << copyStack.top() << endl;
		copyStack.pop();
	}
	return ostrm;
}