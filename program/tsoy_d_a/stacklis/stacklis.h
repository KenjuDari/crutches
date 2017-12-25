#ifndef STACKLIS_H
#define STACKLIS_H

#include <iosfwd>
#include <stddef.h>
#include <memory>


class StackLis
{
public:
	StackLis() = default;
	~StackLis();
	StackLis(const StackLis& rhs);
	StackLis& operator=(const StackLis& rhs);
	void push(const int& value);
	void pop();
	int& top();
	const int& top() const;
	bool isEmpty() const;
	std::ostream& writePop(std::ostream& ostrm);
private:
	struct Node
	{
		Node(std::unique_ptr<Node> pNext, const int& value);
		std::unique_ptr<Node> pNext_{ nullptr };
		int pData_{ int(0) };
	};
	std::unique_ptr<Node> pHead_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, StackLis& rhs);

#endif // !STACKLIS_H
