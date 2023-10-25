#include "Header.h"

int main() {
	Stack<int> stack;
	stack.Push(1);
	stack.Push(2);
	cout << stack << endl;
	int a = stack.top();
	cout << a << endl;
	stack.Pop();
	cout << stack << endl;
	return 0;
}

