#include <stdio.h>
struct  SingleNode
{
	int data;
	SingleNode* next;
};

struct Stack 
{
	SingleNode* top = nullptr;
	void insert(int value)
	{
		if (top == nullptr)
		{
			top = new SingleNode;
			top->data = value;
			top->next = nullptr;
		}
		SingleNode* temp = new SingleNode;
		temp->data = value;
		temp->next = top;
		top = temp;
	}
	int pop()
	{
		if (top == nullptr)
		{
			return -1;
		}
		int value = top->data;
		SingleNode* temp = top;
		top = top->next;
		delete temp;
		return value;
	}
	bool empty()
	{
		return (top == nullptr);
	}
}; 
struct Queue
{
	SingleNode* top = nullptr;
	SingleNode* bottom = nullptr;
	void insert(int value)
	{
		if (top == nullptr)
		{
			top = new SingleNode;
			top->data = value;
			top->next = nullptr;
			bottom = top;
			return;
		}
		SingleNode* temp = new SingleNode;
		temp->data = value;
		temp->next = top;
		top = temp;
	}
	int pop()
	{
		if (bottom == nullptr)
		{
			return -1;
		}
		int value = bottom->data;
		SingleNode* temp = bottom;
		SingleNode* last = top;
		while (last->next != nullptr && last->next != bottom)
		{
			last = last->next;
		}
		bottom = last;
		bottom->next = nullptr;
		delete temp;
		return value;
	}
	bool empty()
	{
		return (top == nullptr);
	}
};
int main()
{
	int Arr[] = { 1, 5, 2, 4, 3 };
	Stack stack;
	int i;
	for  ( i = 0; i < 5; i++)
	{
		stack.insert(Arr[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", stack.pop());
	}
	printf("\nStack size: %d\n", stack.empty());

	Queue queue;
	for (i = 0; i < 5; i++)
	{
		queue.insert(Arr[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", queue.pop());
	}
	printf("\nStack size: %d", queue.empty());
}