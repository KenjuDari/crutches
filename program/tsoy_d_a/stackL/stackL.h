#ifndef STACKL_H
#define STACKL_H

#include <iosfwd>

class StackL
{
public:
	StackL() = default;
	~StackL();
	StackL(const StackL& rhs);
	StackL& operator=(const StackL& rhs);
	void push(const int& value);
	void pop();
	int& top();
	const int& top() const;
	bool isEmpty() const;
	std::ostream& writeAll(std::ostream& ostrm) const;
private:
	struct Node
	{
		Node(Node* pNext, const int& value);
		~Node() = default;
		Node* pNext_{ nullptr };
		int data_{ int(0) };
	};
	Node* pHead_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, const StackL& rhs);

#endif 
