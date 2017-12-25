#include "stacklis.h"
#include <iostream>
#include <memory>

using namespace std;

StackLis::Node::Node(unique_ptr<Node> pNext, const int& value) : pNext_(std::move(pNext)), pData_(value)
{
}


bool StackLis::isEmpty() const
{
	return (pHead_ == nullptr);
}

StackLis::~StackLis()
{
	while (!isEmpty()) {
		pop();
	}
}

StackLis::StackLis(const StackLis& rhs)
{
	if (!rhs.isEmpty()) 
	{
		if (!rhs.isEmpty()) {
			Node* pCopyFrom(rhs.pHead_->pNext_.get());
			pHead_ = make_unique<Node>(Node(nullptr, rhs.pHead_->pData_));
			Node* pCopyTo = pHead_.get();
			while (pCopyFrom != nullptr)
			{
				pCopyTo->pNext_ = make_unique<Node>(Node(nullptr, pCopyFrom->pData_));
				pCopyTo = pCopyTo->pNext_.get();
				pCopyFrom = pCopyFrom->pNext_.get();
			}
		}
	}
}

StackLis& StackLis::operator=(const StackLis& rhs)
{
	if ((!isEmpty()) && (!rhs.isEmpty()))
	{
		Node* pCopyTo = pHead_.get();
		Node* pCopyFrom = rhs.pHead_.get();
		while ((pCopyTo->pNext_ != nullptr) && (pCopyFrom->pNext_ != nullptr))
		{
			pCopyTo->pData_ = pCopyFrom->pData_;
			pCopyTo = pCopyTo->pNext_.get();
			pCopyFrom = pCopyFrom->pNext_.get();
		}
		if ((pCopyTo->pNext_ == nullptr) && (pCopyFrom->pNext_ != nullptr))
		{
			pCopyTo->pData_ = pCopyFrom->pData_;
			pCopyFrom = pCopyFrom->pNext_.get();
			while (pCopyFrom != nullptr)
			{
				pCopyTo->pNext_ = make_unique<Node>(Node(nullptr, pCopyFrom->pData_));
				pCopyTo = pCopyTo->pNext_.get();
				pCopyFrom = pCopyFrom->pNext_.get();
			}
		}
		else {
			if ((pCopyFrom->pNext_ == nullptr) && (pCopyTo->pNext_ != nullptr))
			{
				pCopyTo->pData_ = pCopyFrom->pData_;
				pCopyTo->pNext_ = nullptr;
			}
		}
	}
	else {
		if ((rhs.isEmpty()) && (!isEmpty())) {
			pHead_ = nullptr;
		}
		if ((!rhs.isEmpty()) && (isEmpty()))  {
			Node* pCopyFrom(rhs.pHead_->pNext_.get());
			pHead_ = make_unique<Node>(Node(nullptr, rhs.pHead_->pData_));
			Node* pCopyTo = pHead_.get();
			while (pCopyFrom != nullptr)
			{
				pCopyTo->pNext_ = make_unique<Node>(Node(nullptr, pCopyFrom->pData_));
				pCopyTo = pCopyTo->pNext_.get();
				pCopyFrom = pCopyFrom->pNext_.get();
			}
		}
	}

	return *this;
}

void StackLis::push(const int& value)
{
	unique_ptr<Node> pRemeber = move(pHead_);
	pHead_ = make_unique<Node>(Node(move(pRemeber), value));
	
}

void StackLis::pop()
{
	if (!isEmpty()) {
		unique_ptr<Node> pRemeber = move(pHead_);
		pHead_ = move(pRemeber->pNext_);
	}
}


int& StackLis::top()
{
	if (isEmpty()) {
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

const int& StackLis::top() const
{
	if (isEmpty()) {
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

ostream& operator<<(std::ostream& ostrm,  StackLis& rhs)
{
	return rhs.writePop(ostrm);
}

ostream& StackLis::writePop(std::ostream& ostrm)
{
	if (!isEmpty()) {
			ostrm << top();
			pop();
	}
	else {
		ostrm << "Stack is Empty";
	}
	return ostrm;
}