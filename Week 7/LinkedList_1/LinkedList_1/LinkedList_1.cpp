#include <iostream>
struct Node
{
	int data;
	Node* next; // Danh sách liên kết đơn
	Node* prev; // Danh sách liên kết đôi
};

void ConvertArr2List(int A[], int N, Node* &head, Node* &tail)
{
	// Kiểm tra head có null hay không
	int Startindex = 0;
	Node* last;
	if (head == nullptr)
	{
		head = new Node;
		head->data = A[0];
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
		Startindex = 1;
	}
	int i;
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	last = temp;
	for ( i = Startindex; i < N; i++)
	{
		temp = new Node;

		temp->data = A[i];
		temp->next = nullptr;
		temp->prev = last;
		
		last->next = temp;
		last = temp;
	}
	tail = last;
}
// Xóa theo index
void deleteIndex(Node*& head, int index)
{
	int i = 0;
	Node* temp = head;
	while ((&temp) != nullptr)
	{
		if (index == 0)
		{
			head = head->next;
			head->prev = nullptr;
			temp = head;
			break;
		}
		if (i == index)
		{

			if (temp->next->next == nullptr)
			{
				temp->next = nullptr;
			}
			else
			{
				Node* remove = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete remove;
				break;
			}

		}
		else
		{
			temp = temp->next;
			i++;
		}

		if (temp->next == nullptr)
		{
			break;
		}
	}
	/*int i = 0;
	Node* temp = head;
	while (i < (index - 1))
	{
		temp = temp->next;
		i++;
	}
	
	Node* remove1 = temp->next;
	if (index == 0)
	{
		head->data = head->next->data;
	}
	if (temp->next->next != nullptr)
	{
		temp->next = temp->next->next;
		temp->next->prev = temp;
	}
	else
	{
		temp->next = nullptr;
	}

	delete remove1;*/
}
// Xóa theo value
void deleteValue(Node*& head, Node*& tail, int value)
{
	Node* temp = head;
	while ((&temp) != nullptr)
	{
		if (value == head->data)
		{
			head = head->next;
			head->prev = nullptr;
			temp = head;
			break;
		}
		if (temp->next->data == value)
		{

			if (temp->next->next == nullptr)
			{
				temp->next = nullptr;
				tail = temp;
			}
			else
			{
				Node* remove = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete remove;
				break;
			}

		}
		else
		{
			temp = temp->next;
		}

		if (temp->next == nullptr)
		{
			break;
		}
	}
}
//Xoa nhieu phan tu
void deleteValueSame(Node*& head, Node*& tail, int value)
{

	Node* temp = head;
	while ((&temp) != nullptr)
	{
		if (value == head->data)
		{
			head = head->next;
			head->prev = nullptr;
			temp = head;
		}
		if (temp->next->data == value)
		{
			
			if (temp->next->next == nullptr)
			{
				temp->next = nullptr;
				tail = temp;
			}
			else
			{
				Node* remove = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete remove;
			}
			
		}
		else
		{
			temp = temp->next;
		}

		if (temp->next == nullptr)
		{
			break;
		}
	}
}
//Sap xep danh sach
void SapXep(Node*& head)
{
	int i = 0, N = 0, j, swap;
	Node* temp1 = head;
	Node* temp2;
	while ((&temp1) != nullptr)
	{
		N++;
		if (temp1->next == nullptr)
		{
			break;
		}
		temp1 = temp1->next;
	}
	temp1 = head;
	while (i < N)
	{
		temp2 = temp1->next;
		j = i + 1;
		while (j < N)
		{
			if (temp1->data > temp2->data)
			{
				swap = temp1->data;
				temp1->data = temp2->data;
				temp2->data = swap;
			}

			temp2 = temp2->next;
			j++;
		}
		temp1 = temp1->next;
		i++;
	}

}
void SearchMin(Node*& head)
{
	Node* temp = head;
	Node* min = head;
	while ((&temp) != nullptr)
	{
		if (temp->data < min->data)
		{
			min = temp;
		}
		if (temp->next == nullptr)
		{
			break;
		}
		temp = temp->next;
	}
	printf("Min = %d", min->data);
}

void SearchMax(Node*& head)
{
	Node* temp = head;
	Node* max = head;
	while ((&temp) != nullptr)
	{
		if (temp->data > max->data)
		{
			max = temp;
		}
		if (temp->next == nullptr)
		{
			break;
		}
		temp = temp->next;
	}
	printf("Max = %d", max->data);
}

void Insert(Node*& head, int insert, int index)
{
	int i = 0;
	Node* temp = head;
	Node* node = new Node();
	node->data = insert;
	node->next = nullptr;
	node->prev = nullptr;
	if (index == 0)
	{
		node->next = temp;
		temp->prev = node;
		head = node;
	}
	else while ((&temp) != nullptr)
	{
		if (i == index )
		{
			node->next = temp;
			node->prev = temp->prev;
			temp->prev->next = node;
			temp->prev = node;
			break;
		}
		else
		{
			if (temp->next == nullptr)
			{
				temp->next = node;
				node->prev = temp;
				break;
			}
			temp = temp->next;
			i++;
		}
	}
}
void display(const Node &head,int revert)
{
	Node p = head;
	while ((&p) != nullptr)
	{
		printf("%d, ", p.data);
		if (p.next == nullptr and revert == 0)
		{
			break;
		}
		if (p.prev == nullptr and revert == 1)
		{
			break;
		}
		if (revert)
		{
			p = *(p.prev);
		}
		else
		{
			p = *(p.next);
		}
	}
	printf("\n");
}

int main()
{
	int Arr[] = { 6,5,6,12,6};
	Node* head = nullptr;
	Node* tail = nullptr;
	ConvertArr2List(Arr, 5, head, tail);
	//deleteIndex(head, 5);
	//deleteValue(head, tail, 6);
	//Insert(head, 1, 0);
	//SapXep(head);
	deleteValueSame(head, tail, 6);
	display(*tail, 1);
	//SearchMin(head);
	//SearchMax(head);
}