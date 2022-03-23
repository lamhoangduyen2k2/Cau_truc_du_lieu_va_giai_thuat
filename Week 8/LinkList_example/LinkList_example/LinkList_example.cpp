#include <iostream>

struct Node {
    int data;
    Node* next; // danh sách liên kết đơn
    Node* prev;
};

//Xây dựng danh sách liên kết đơn từ mảng 1 chiều
/*void convertArr2List(const int A[], const int N, Node*& head)
{
    // mảng A phải có ít nhất 1 phần tử
    //int N = sizeof(A) / sizeof(A[0]);
    // kiểm tra head có null hay không
    int startindex = 0;
    Node* last;
    if (head == nullptr) {
        head = new Node;
        head->data = A[0];
        head->next = nullptr;
        startindex = 1;
    }

    int i;
    Node* temp;
    temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    last = temp;

    for (i = startindex; i < N; i++) {
        temp = new Node;

        temp->data = A[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;
    }
}*/

struct Stack {
    Node* top = nullptr;
    void insert(int value) {
        if (top == nullptr) {
            top = new Node;
            top->data = value;
            top->next = nullptr;
            return;
        }
        //int i;
        Node* temp;
        temp = new Node;
        temp->data = value;
        temp->next = top;
        top = temp;
    }
    int pop() {
        if (top == nullptr) {
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    bool empty() {
        return (top == nullptr);
    }
    int Size()
    {
        if (top == nullptr)
        {
            return 0;
        }
        int size = 1;
        Node* temp = top;
        while (temp->next != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

// Queue
struct Queue {
    Node* top = nullptr;
    Node* bottom = nullptr;
    void insert(int value) {
        if (top == nullptr) {
            top = new Node;
            top->data = value;
            top->next = nullptr;
            bottom = top;
            return;
        }
        //int i;
        Node* temp;
        temp = new Node;
        temp->data = value;
        temp->next = top;
        top = temp;
    }
    int pop() {
        if (bottom == nullptr) {
            return -1;
        }
        int value = bottom->data;
        Node* temp = bottom;
        Node* last = top;
        if (top == bottom) {
            Node* temp = top;
            top = bottom = nullptr;
            delete temp;
            return value;
        }

        while (last->next != nullptr && last->next != bottom) {
            last = last->next;
        }
        bottom = last;
        bottom->next = nullptr;
        delete temp;
        return value;
    }
    bool empty() {
        return (bottom == nullptr);
    }
    int Size()
    {
        if (top == nullptr)
        {
            return 0;
        }
        int size = 1;
        Node* temp = top;
        while (temp->next != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};
// Deque
struct Deque
{
    Node* top = nullptr;
    Node* bottom = nullptr;
    void insert(int value, bool end)
    {
        if (end == false)
        {
            if (top == nullptr)
            {
                top = new Node;
                top->data = value;
                top->next = nullptr;
                top->prev = nullptr;
                bottom = top;
                return;
            }
            Node* temp = new Node;
            temp->data = value;
            top->prev = temp;
            temp->next = top;
            temp->prev = nullptr;
            top = temp; 
        }
        else
        {
            if (bottom == nullptr)
            {
                bottom = new Node;
                bottom->data = value;
                bottom->next = nullptr;
                bottom->prev = nullptr;
                top = bottom;
                return;
            }
            Node* temp = new Node;
            temp->data = value;
            bottom->next = temp;
            temp->prev = bottom;
            temp->next = nullptr;
            bottom = temp;
        }
    }
    int pop(bool end)
    {
        if (end == false)
        {
            if (top == nullptr) {
                return -1;
            }
            int value = top->data;
            if (top == bottom) {
                Node* temp = top;
                top = bottom = nullptr;
                delete temp;
                return value;
            }
            Node* temp = top;
            top = top->next;
            top->prev = nullptr;
            delete temp;
            return value;
        }
        else
        {
            if (bottom == nullptr) {
                return -1;
            }
            int value = bottom->data;
            if (top == bottom) {
                Node* temp = top;
                top = bottom = nullptr;
                delete temp;
                return value;
            }
            Node* temp = bottom;
            bottom = bottom->prev;
            bottom->next = nullptr;
            delete temp;
            return value;
        }
    }
    int Size()
    {
        if (top == nullptr)
        {
            return 0;
        }
        int size = 1;
        Node* temp = top;
        while (temp->next != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

/*void convertArr2ListDouble(const int A[], const int N, Node*& head, Node*& tail)
{

    int startindex = 0;
    Node* last;
    if (head == nullptr) {
        head = new Node;

        head->data = A[0];
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        startindex = 1;
    }

    int i;
    Node* temp;
    temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    last = temp;

    for (i = startindex; i < N; i++) {
        temp = new Node;

        temp->data = A[i];
        temp->next = nullptr;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    tail = last;
    return;
}



//xóa theo index
void deleteIndex(Node*& head, int index)
{
    int i = 0;
    if (index == -1) {
        return;
    }
    Node* temp;
    temp = head;
    while (i < (index - 1)) {
        i++;
        temp = temp->next;
    }
    //xóa head
    if (index == 0) {
        Node* remove = head;
        head = head->next;
        delete remove;
        return;
    }
    //xóa temp
    Node* remove = temp->next;
    temp->next = temp->next->next;
    delete remove;
}

int findFirstIndex(Node* head, int value)
{
    int i = 0;
    Node* temp;
    temp = head;
    while (temp != nullptr) {
        if (temp->data == value)
            return i;
        i++;
        temp = temp->next;
    }
    return -1;
}
void deleteAllValue(Node*& head, int value)
{
    int index = 0;
    do {
        index = findFirstIndex(head, value);
        deleteIndex(head, index);
    } while (index != -1);
}*/

/*void display(const Node& head, int revert) {
    Node p = head;
    while ((&p) != nullptr) {
        printf("%d, ", p.data);
        if (p.next == nullptr and revert == 0)
            break;
        if (p.prev == nullptr and revert == 1)
            break;
        if (revert)
            p = *(p.prev);
        else
            p = *(p.next);
    }
    printf("\n");
}*/
struct Merge
{
    Node* top = nullptr;
    Node* bottom = nullptr;
    int size;
    void Insert_List(Node *temp, int size)
    {
         for (int i = 0; i < size; i++)
         {
                if (bottom == nullptr)
                {
                    bottom = new Node;
                    bottom->data = temp->data;
                    bottom->next = nullptr;
                    top = bottom;
                    temp = temp->next;
                }
                else
                {
                    Node* swap = new Node;
                    swap->data = temp->data;
                    bottom->next = swap;
                    swap->next = nullptr;
                    bottom = swap;
                    temp = temp->next;
                }
         }
    }
    void Merge_List(Stack stack, Queue queue, bool increase)
    {
        Node* temp = new Node;
        int i;
        size = stack.Size() + queue.Size();
        if (increase == true)
        {
            temp = stack.top;
            Insert_List(temp, stack.Size());
            temp = queue.top;
            Insert_List(temp, queue.Size());
        }
        else
        {
            temp = queue.top;
            Insert_List(temp, stack.Size());
            temp = stack.top;
            Insert_List(temp, queue.Size());
        }
    }
    void Merge_Value(Stack stack, Queue queue, bool increase)
    {
        int i;
        Node* temp;
        Node* swap;
        int value;
        Merge_List(stack, queue, increase);
        temp = top;
        if (increase == true)
        {
            while ((&temp) != nullptr)
            {
                swap = temp->next;
                while (temp->next != nullptr)
                {
                    if (swap->data < temp->data)
                    {
                        value = temp->data;
                        temp->data = swap->data;
                        swap->data = value;
                    }
                    if (swap->next == nullptr)
                    {
                        break;
                    }
                    swap = swap->next;
                }
                if (temp->next == nullptr)
                {
                    break;
                }

                temp = temp->next;
            }
        }
        else
        {
            while ((&temp) != nullptr)
            {
                swap = temp->next;
                while (temp->next != nullptr)
                {
                    if (swap->data > temp->data)
                    {
                        value = temp->data;
                        temp->data = swap->data;
                        swap->data = value;
                    }
                    if (swap->next == nullptr)
                    {
                        break;
                    }
                    swap = swap->next;
                }
                if (temp->next == nullptr)
                {
                    break;
                }

                temp = temp->next;
            }
        }
    }
};
int main()
{
    int Arr[] = { 1,5,2,4,3 };
    Stack stack;
    int i;
    for (i = 0; i < 5; i++)
        stack.insert(Arr[i]);
    printf("Size of Stack: %d\n", stack.Size());
    /*for (i = 0; i < 5; i++)
        printf("%d ", stack.pop());

    printf("\nStack empty?: %d\n", stack.empty());*/
    int Arr2[] = { 6,10,0,4,7 };
    Queue queue;
    for (i = 0; i < 5; i++)
        queue.insert(Arr2[i]);
    printf("Size of Queue: %d\n", queue.Size());
    /*for (i = 0; i < 5; i++)
        printf("%d ", queue.pop());

    printf("\nqueue empty?: %d\n", queue.empty());*/

    Deque deque;
    bool end = false;
    for (i = 0; i < 5; i++)
        deque.insert(Arr[i],false);
    
    end = true;
    printf("Size of Deque: %d\n", deque.Size());
    for (i = 0; i < 5; i++)
        printf("%d ", deque.pop(end));
    printf("\nSau khi sap xep:");
    Merge merge;
    bool increase = true;
    merge.Merge_Value(stack, queue, increase);
    Node* temp = merge.top;
    for  (i = 0; i < merge.size; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    /*for (i = 0; i < 5; i++)
        stack.insert(Arr[i]);
    for (i = 0; i < 5; i++)
        printf("%d ", stack.pop());
    printf("\n");
    for (i = 0; i < 5; i++)
        queue.insert(Arr[i]);
    for (i = 0; i < 5; i++)
        printf("%d ", queue.pop());*/
    
    /*
    Node* head = nullptr;
    Node* tail = nullptr;
    convertArr2ListDouble(Arr,5, head, tail);
    display(*tail,1);
    //deleteAllValue(head, 4);
    //display(*head);
    */
    /*
    deleteIndex(head, 2);
    display(*head);
    convertArr2List(Arr, 5, head);
    display(*head);
    */
}