//#include<stdio.h>
//int countActivites(int N, int starts[], int ends[]) {
//    //your code here
//    int dem = 1,max = 0, i, j, k;
//    int tam[1000], cv[1000];
//    for  (i = 0; i < N; i++)
//    {
//        tam[i] = -1;
//    }
//    for  (i = 0; i < N; i++)
//    {
//        for (j = 0; j < N; j++)
//        {
//            if (starts[j] >= ends[i])
//            {
//                for  (k = 0; k < N; k++)
//                {
//                    if (tam[i] == -1)
//                    {
//                        tam[i] = j;
//                        break;
//                    }
//                    else
//                    {
//                        if ()
//                        {
//
//                        }
//                    }
//                }
//            }
//        }
//    }
//    //end your code
//}
//#include<stdio.h>
//#include<iostream>
//struct Output {
//
//    int row, column;
//
//};
//Output search(int** arr, int N, int M, int K) {
//    //your code here
//    Output temp;
//    temp.column = -1;
//    temp.row = -1;
//    int i, j;
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < N; j++)
//        {
//            if (arr[i][j] == K)
//            {
//                temp.column = j;
//                temp.row = i;
//                break;
//            }
//        }
//        if (temp.column != -1 && temp.row != -1)
//            break;
//    }
//    return temp;
//    //end your code   
//}
//void main()
//{
//    int N, M, K, i, j;
//    M = 3;
//    N = 3;
//    K = 10;
//    int** arr = new int* [M];
//    for (i = 0; i < M; i++)
//    {
//        arr[i] = new int[N];
//    }
//    printf("Input:\n");
//    for (i = 0; i < M; i++)
//    {
//        for (j = 0; j < N; j++)
//        {
//            std::cin >> arr[i][j];
//        }
//        printf("\n");
//    }
//    Output temp = search(arr, N, M, K);
//    printf("Ket qua: arr[%d][%d]", temp.row, temp.column);
//}
//#include<iostream>
//
//using namespace std;
//
//#include<stdio.h>
//int maxSubarraySum(int arr[], int N) {
//    //your code here
//    int best = 0, sum = 0, i;
//
//    for (i = 0; i < N; i++) {
//
//        sum = sum + arr[i];
//
//        if (sum > best)
//
//        {
//
//            best = sum;
//
//        }
//
//        if (sum < 0)
//
//            sum = 0;
//
//    }
//
//    return best;
//
//    //end your code
//}
//int main() {
//    int arr[] = { -1,2,3,4,-2,6, -8,3 };
//    int N = 8;
//    cout << maxSubarraySum(arr, N);
//}
//#include<stdio.h>
//int cntSubarrays(int arr[], int N, int K) {
//    //your code here
//
//    int res = 0;
//
//    for (int i = 0; i < N; i++)
//
//    {
//
//        int sum = 0;
//
//        for (int j = i; j < N; j++)
//
//        {
//
//            sum += arr[j];
//
//            if (sum == K)
//
//                res++;
//
//        }
//
//    }
//
//    return res;
//
//    // end your code
//
//}
//
//void main()
//{
//    int arr[] = { 10, 2, -2, -20, 10 };
//    int k = -10;
//    int N = 5;
//    int a = cntSubarrays(arr, N, k);
//    printf("%d ", a);
//}
//#include <stdio.h>
//
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//struct LinkedList
//{
//	Node* head;
//	Node* tail;
//};
//
//Node* CreateNode(int init_data)
//{
//	Node* node = new Node;
//	node->data = init_data;
//	node->next = NULL;
//	return node;
//}
//
//void CreateList(LinkedList& l)
//{
//	l.head = NULL;
//	l.tail = NULL;
//}
//
//void AddHead(LinkedList& l, Node* node)
//{
//	if (l.head == NULL)
//	{
//		l.head = node;
//		l.tail = node;
//	}
//	else
//	{
//		node->next = l.head;
//		l.head = node;
//	}
//}
//
//void AddTail(LinkedList& l, Node* node)
//{
//	if (l.head == NULL)
//	{
//		l.head = node;
//		l.tail = node;
//	}
//	else
//	{
//		l.tail->next = node;
//		l.tail = node;
//	}
//}
//void PrintList(LinkedList l)
//{
//	if (l.head != NULL)
//	{
//		Node* node = l.head;
//		while (node != NULL)
//		{
//			//cout << node->data << ' ';
//			printf("%d ", node->data);
//			node = node->next;
//		}
//	}
//}
//int searchInList(Node* head, int Key)
//
//{
//
//    //your code here
//	int index = -1, dem = -1;
//	if (head == nullptr)
//	{
//		return index;
//	}
//	Node* temp = head;
//	while (temp != nullptr)
//	{
//		dem++;
//		if (temp->data == Key)
//		{
//			break;
//		}
//		temp = temp->next;
//	}
//	if (temp->data == Key)
//	{
//		index = dem;
//	}
//	return index;
//    //end your code
//
//}
//int main()
//{
//	int A[7] = { 1,7,3,4,5,6,7 };
//	// Create a linked list
//	LinkedList list;
//	CreateList(list);
//
//	// Add sample data to list
//	Node* node;
//	for (auto i = 0; i < 7; i++)
//	{
//		// Create new node with init data is i
//		node = CreateNode(A[i]);
//
//		// Add node to head
//		// List that is added node by AddHead will be reversed
//		//AddHead(list, node);
//
//		// Add node to Tail
//		AddTail(list, node);
//	}
//
//	// Print list
//	//PrintList(list);
//	printf("\n%d", searchInList(list.head, 7));
//}
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//
//Node* mergeList(Node* head1, Node* head2)
//{
//    //your code here
//    Node* result = NULL;
//    if (head1 == NULL)
//        return(head2);
//    else if (head2 == NULL)
//        return(head1);
//    if (head1->data <= head2->data)
//    {
//        result = head1;
//        result->next = mergeList(head1->next, head2);
//    }
//    else
//    {
//        result = head2;
//        result->next = mergeList(head1, head2->next);
//    }
//    return(result);
//    //end your code
//
//}
//void printList(struct Node* Node)
//{
//    while (Node != NULL) {
//        cout << Node->data << " ";
//        Node = Node->next;
//    }
//}
//
///* Utility function to create a new node with
//   given key */
//Node* newNode(int key)
//{
//    Node* temp = new Node;
//    temp->data = key;
//    temp->next = NULL;
//    return temp;
//}
//
///* Driver program to test above functions*/
//int main()
//{
//    /* Start with the empty list */
//    struct Node* res = NULL;
//    Node* a = newNode(-5);
//    a->next = newNode(10);
//    a->next->next = newNode(15);
//    a->next->next->next = newNode(40);
//    Node* b = newNode(2);
//    b->next = newNode(3);
//    b->next->next = newNode(20);
//    cout << "List A before merge: \n";
//    printList(a);
//
//    cout << "\nList B before merge: \n";
//    printList(b);
//
//    /* merge 2 sorted Linked Lists */
//    res = mergeList(a, b);
//
//    cout << "\nMerged Linked List is: \n";
//    printList(res);
//
//    return 0;
//}
//#include <stdio.h>
//void main()
//{
//	char s[3] = { 'A', 'B', 'C' };
//	char tam;
//	tam = s[0];
//	printf("%c", tam);
//}
//#include <stdio.h>
//struct Node {
//
//	int data;
//
//	Node* next;
//
//};
//void ConvertArr2List(int A[], int N, Node*& head)
//{
//	// Kiểm tra head có null hay không
//	int Startindex = 0;
//	int i = 0, count = 0;
//	//Node* X[100];
//
//	Node* last;
//	if (head == nullptr)
//	{
//		head = new Node;
//		head->data = A[0];
//		head->next = nullptr;
//		//head->prev = nullptr;
//		Startindex = 1;
//	}
//	//int i;
//	Node* temp = head;//gán head cho temp
//	//X[count]->next = temp;
//	count++;
//	while (temp->next != nullptr)//di chuyển temp tới vị trí cuối
//	{
//		temp = temp->next;
//		//X[count]->next = temp;
//		count++;
//	}
//	last = temp;
//	for (i = Startindex; i < N; i++) //lần lượt tạo node và lưu data, tạo liên kết trước sau
//	{
//		temp = new Node;
//
//		temp->data = A[i];
//		if (i == N - 1)
//		{
//			temp->next = head->next->next;
//			break;
//		}
//		temp->next = nullptr;
//		//temp->prev = last;
//
//		last->next = temp;
//		last = temp;
//	}
//}
//int checkCycle(Node* head)
//
//{
//
//	//your code here
//	Node* temp = head;
//	int i = 0, count = 0;
//	Node* A[8];
//	while (temp != nullptr)
//	{
//		A[count]->next = temp;
//		//count++;
//		temp = temp->next;
//		for (i = 0; i <= count; i++)
//		{
//			if (A[i]->next == temp)
//			{
//				return A[i]->data;
//				break;
//			}
//		}
//		if (temp = nullptr)
//			return -1;
//		count++;
//	}
//
//	//end your code
//
//}
//void main()
//{
//	Node* head = nullptr;
//	int Arr[] = { 1,2,3,4,5,6,7,8 };
//	ConvertArr2List(Arr, 8, head);
//
//	printf("Ket qua: %d", checkCycle(head));
//
//}
//#include <stdio.h>
//
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//
//int checkCycle(Node* head) {
//
//    //your code here
//    if (head == NULL || head->next == NULL)
//
//        return -1;
//
//
//
//    Node* slow = head, * fast = head;
//
//    slow = slow->next;
//
//    fast = fast->next->next;
//
//    while (fast && fast->next) {
//
//
//
//        if (slow == fast)
//
//            break;
//
//        slow = slow->next;
//
//        fast = fast->next->next;
//
//    }
//
//
//
//    if (slow != fast)
//
//        return -1;
//
//
//
//    slow = head;
//
//    while (slow != fast) {
//
//        slow = slow->next;
//
//        fast = fast->next;
//
//    }
//
//    return slow->data;
//    //end your code
//
//}
//void push(Node** head_ref, int new_data)
//{
//    Node* new_node = new Node();
//    new_node->data = new_data;
//    new_node->next = (*head_ref);
//    (*head_ref) = new_node;
//}
//void printList(Node* node)
//{
//    while (node != NULL)
//    {
//        int ans = node->data;
//        printf("%d ", ans);
//        node = node->next;
//    }
//}
//int main() {
//    struct Node* head = NULL;
//    push(&head, 9);
//    push(&head, 8);
//    push(&head, 7);
//    push(&head, 6);
//    push(&head, 5);
//    push(&head, 4);
//    push(&head, 3);
//    push(&head, 2);
//    push(&head, 1);
//    // Making linked list circular
//    printList(head);
//
//   head->next = head;
//
//    printf("\n%d", checkCycle(head));
//
//}
//#include<iostream>
//#include <stdio.h>
//
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//
//struct Queue {
//
//    // your code here
//
//    Node* top = nullptr;
//
//
//
//    Node* bottom = nullptr;
//
//
//
//    void insert(int value) {
//
//
//
//        if (top == nullptr) {
//
//
//
//            top = new Node;
//
//
//
//            top->data = value;
//
//
//
//            top->next = nullptr;
//
//
//
//            bottom = top;
//
//
//
//            return;
//
//
//
//        }
//
//
//
//        Node* temp;
//
//
//
//        temp = new Node;
//
//
//
//        temp->data = value;
//
//
//
//        temp->next = top;
//
//
//
//        top = temp;
//
//
//
//    }
//
//
//
//    int pop() {
//
//
//
//        if (bottom == nullptr) {
//
//
//
//            return -1;
//
//
//
//        }
//
//
//
//        int value = bottom->data;
//
//
//
//        Node* temp = bottom;
//
//
//
//        Node* last = top;
//
//
//
//        if (top == bottom) {
//
//
//
//            Node* temp = top;
//
//
//
//            top = bottom = nullptr;
//
//
//
//            delete temp;
//
//
//
//            return value;
//
//
//
//        }
//
//
//
//
//
//
//
//        while (last->next != nullptr && last->next != bottom) {
//
//
//
//            last = last->next;
//
//
//
//        }
//
//
//
//        bottom = last;
//
//
//
//        bottom->next = nullptr;
//
//
//
//        delete temp;
//
//
//
//        return value;
//
//
//
//    }
//
//
//
//    bool empty() {
//
//
//
//        return (bottom == nullptr);
//
//
//
//    }
//
//    //end your code
//
//};
//
//int* chisoSpan(int arr[], int N) {
//
//    //your code here
//
//    int* res = new int[N];
//
//
//
//    int i, j;
//
//
//
//    Queue q;
//
//
//
//    for (i = 0; i < N; i++)
//
//
//
//    {
//
//
//
//        int count = 0;
//
//
//
//        for (j = 0; j < i; j++)
//
//
//
//            if (arr[j] < arr[i])
//
//
//
//                count++;
//
//
//
//        q.insert(count + 1);
//
//
//
//    }
//
//
//
//    for (i = 0; i < N; i++)
//
//
//
//        res[i] = q.pop();
//
//
//
//    return res;
//
//    //end your code
//
//}
//void main()
//{
//    int N = 7;
//    int arr[] = { 100, 80, 60, 70, 60, 75, 85 };
//    int* res = chisoSpan(arr, N);
//    for (int i = 0; i < N; i++)
//        std:: cout << res[i] << " ";
//}
// C++ program for a Queue based approach
// to find first non-repeating character

// C++ program for a Queue based approach
// to find first non-repeating character

//#include <stdio.h>
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//
//struct Queue {
//
//    // your code here
//
//    Node* top = nullptr;
//
//    Node* bottom = nullptr;
//
//    void insert(int value) {
//
//        if (top == nullptr) {
//
//            top = new Node;
//
//            top->data = value;
//
//            top->next = nullptr;
//
//            bottom = top;
//
//            return;
//
//        }
//
//        Node* temp;
//
//        temp = new Node;
//
//        temp->data = value;
//
//        temp->next = top;
//
//        top = temp;
//
//    }
//
//    int pop() {
//
//        if (bottom == nullptr) {
//
//            return -1;
//
//        }
//
//        int value = bottom->data;
//
//        Node* temp = bottom;
//
//        Node* last = top;
//
//        if (top == bottom) {
//
//            Node* temp = top;
//
//            top = bottom = nullptr;
//
//            delete temp;
//
//            return value;
//
//        }
//
//
//
//        while (last->next != nullptr && last->next != bottom) {
//
//            last = last->next;
//
//        }
//
//        bottom = last;
//
//        bottom->next = nullptr;
//
//        delete temp;
//
//        return value;
//
//    }
//
//    bool empty() {
//
//        return (bottom == nullptr);
//
//    }
//
//    int Size()
//
//    {
//
//        if (top == nullptr)
//
//        {
//
//            return 0;
//
//        }
//
//        int size = 1;
//
//        Node* temp = top;
//
//        while (temp->next != nullptr)
//
//        {
//
//            size++;
//
//            temp = temp->next;
//
//        }
//
//        return size;
//
//    }
//
//    //end your code
//
//};
//
//char* firstCharacter(char s[], int N) {
//
//    //your code here
//
//    Queue q;
//
//    int i, j;
//
//    int charCount[26] = { 0 };
//
//    char* res = new char[N];
//
//    for (i = 0; s[i]; i++) {
//
//
//
//        charCount[s[i] - 'a']++;
//
//        for (j = 0; j < N; j++)
//
//        {
//
//            if (charCount[j] == 1)
//
//            {
//
//                q.insert(j + 'a');
//
//                j = N;
//
//            }
//
//            if (charCount[j] == 0)
//
//            {
//
//                break;
//
//            }
//
//
//
//        }
//
//        if (charCount[j - 1] > 1)
//
//        {
//
//            q.insert('0');
//
//        }
//
//        res[i] = q.pop();
//
//
//
//    }
//
//    return res;
//
//    //end your code
//
//}
//// Driver function
//void main()
//{
//    int N = 8;
//    char arr[] = "ababbcbc";
//    char* res = firstCharacter(arr, N);
//    for (int i = 0; i < N; i++)
//        //cout << res[i] << " ";
//        printf("%c", res[i]);
//}
//#include <iostream>
////#include<stack>
//using namespace std;
//struct Queue {
//
//	// your code here
//	string* arr;
//	int index;
//	void Init(int N) {
//		index = -1;
//		arr = new string[N];
//	}
//	bool empty() {
//		return index == -1;
//	}
//	void pop() {
//		index--;
//	}
//	void push(string value) {
//		arr[++index] = value;
//	}
//	string top() {
//		if (index == -1)
//			return " ";
//		return arr[index];
//	}
//	int size() {
//		return index;
//	}
//	//end your code
//
//};
//string simplify(string A)
//{
//	Queue st;
//	st.Init(A.length());
//	string dir;
//
//	string res;
//
//	res.append("/");
//
//	int len_A = A.length();
//
//	for (int i = 0; i < len_A; i++) {
//
//		dir.clear();
//
//		while (A[i] == '/')
//			i++;
//
//		while (i < len_A && A[i] != '/') {
//			dir.push_back(A[i]);
//			i++;
//		}
//
//		if (dir.compare("..") == 0) {
//			if (!st.empty())
//				st.pop();
//		}
//
//		else if (dir.compare(".") == 0)
//			continue;
//
//		else if (dir.length() != 0)
//			st.push(dir);
//	}
//
//	Queue st1;
//	st1.Init(A.length());
//	while (!st.empty()) {
//		st1.push(st.top());
//		st.pop();
//	}
//
//	while (!st1.empty()) {
//		string temp = st1.top();
//
//		if (st1.size() != 1)
//			res.append(temp + "/");
//		else
//			res.append(temp);
//
//		st1.pop();
//	}
//	return res;
//}
//int main()
//{
//	string str("/aa/./bb/../../cc/");
//	string res = simplify(str);
//	cout << res;
//	return 0;
//}
//#include <stdio.h>
//
//struct HashTable {
//
//    int K;
//
//    int* table;
//
//    void construct(int arr[], int N) {
//
//        // your code here
//
//        int i;
//
//        for (i = 0; i < N; i++)
//
//        {
//
//            int index, j, flag = 0, hkey;
//
//            hkey = arr[i] % K;
//
//            for (j = 0; j < K; j++)
//
//            {
//
//                index = (hkey + j) % K;
//
//                if (table[index] == NULL)
//
//                {
//
//                    table[index] = arr[i];
//
//                    break;
//
//                }
//
//            }
//
//        }
//
//        // end your code
//
//    }
//
//};
//void main()
//{
//    HashTable table;
//    int arr[] = { 38, 19, 8, 109, 10 };
//    int N = 5;
//    table.K = 7;
//    table.construct(arr, N);
//}
//#include <iostream>
//#include <stdio.h>
//
//struct BNode { //BST --> AVL
//
//	int data;
//
//	BNode* left, * right;
//
//	// your code here
//
//	void init() {
//
//
//
//		left = right = nullptr;
//
//
//
//	}
//
//	// end your code
//
//};
//
//struct Tree {
//
//	BNode* root = nullptr;
//
//	// your code here
//
//	void init(BNode*& node) {
//
//
//
//		node = new BNode;
//
//
//
//		node->init();
//
//
//
//	}
//
//	void insert(int value, BNode*& parent) {
//
//		if (parent == nullptr) {
//
//			init(parent);
//
//			parent->data = value;
//
//			return;
//
//		}
//
//		if (value < parent->data) {
//
//			insert(value, parent->left);
//
//
//
//		}
//
//		else {
//
//			insert(value, parent->right);
//
//
//
//		}
//
//		return;
//
//	}
//
//	//end your code
//
//};
//
//int* leftView(Tree* tree, int& N)
//
//{
//
//	// your code here
//
//	N = 0;
//
//
//
//	BNode* temp = tree->root;
//
//	int* res = new int[100];
//
//
//
//	while (temp != nullptr)
//
//
//
//	{
//
//
//
//		res[N] = temp->data;
//
//
//
//		if (temp->left != nullptr)  temp = temp->left;
//
//
//
//		else   temp = temp->right;
//
//
//
//		N++;
//
//
//
//	}
//
//
//
//	return res;
//
//	//end your code
//
//}
//void main()
//{
//	Tree binaryTree;
//	binaryTree.insert(10, binaryTree.root);
//	binaryTree.insert(2, binaryTree.root);
//	binaryTree.insert(3, binaryTree.root);
//	binaryTree.insert(7, binaryTree.root);
//	binaryTree.insert(8, binaryTree.root);
//	binaryTree.insert(15, binaryTree.root);
//	binaryTree.insert(12, binaryTree.root);
//	binaryTree.insert(14, binaryTree.root);
//
//
//	//binaryTree.print(binaryTree.root);
//
//	//printf("%d\n", binaryTree.deleteNode(15, binaryTree.root));
//	int N;
//	//printf("%d", binaryTree.root->data);
//	//printf("%d\n",*getDistance(binaryTree,6,1,N)),"\n";
//	//printf("%d\n", maxDepth(binaryTree.root));
//	int* res = leftView(&binaryTree, N);
//	for (int i = 0; i < N; i++)
//	{
//		std::cout << res[i] << " ";
//	}
//
//	std::cout << "N = " << N;
//}
// ////////////////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//
//struct HashTable {
//
//	int K;
//
//	int* table;
//
//	void construct(int arr[], int N) {
//
//		// your code here
//		int key, key2, i,j;
//		table = new int[K];
//		for (i = 0; i < K; i++)
//			table[i] = NULL;
//		for (i = 0; i < N; i++)
//		{
//			j = 0;
//			key = arr[i] % K;
//			key2 = key;
//			while (table[key] != NULL)
//			{
//				key = (key2 + j * j) % K;
//				j++;
//			}
//			table[key] = arr[i];
//		}
//		// end your code
//
//	}
//
//};
//
//int main()
//{
//	int A[15] = { 89,18,49,58,79 };
//	int N = 5;
//	HashTable hb;
//	hb.K = 10;
//	hb.construct(A, N);
//	for (int i = 0; i < hb.K; i++)
//	{
//		printf("%d \n", hb.table[i]);
//	}
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//
//struct Node {
//
//	int data;
//
//	Node* next;
//
//};
//
//struct HashTable {
//
//	int K;
//
//	Node* table;
//
//	void construct(int arr[], int N) {
//
//		// your code here
//		table = new Node[7];
//		Node* temp = nullptr;
//		table[0].next = temp;
//		// end your code
//
//	}
//
//};
//#include <stdio.h>
//
//struct BNode {
//
//    int data;
//
//    BNode* left, * right;
//
//    int height;
//
//    // your code here
//
//        // end your code
//
//};
//
//struct BSTree {
//
//    BNode* root = nullptr;
//
//    // your code here
//
//    int max(int a, int b)
//
//    {
//
//        return (a > b) ? a : b;
//
//    }
//
//    struct BNode* newNode(int item)
//
//    {
//
//        struct BNode* temp = new BNode();
//
//        temp->data = item;
//
//        temp->left = temp->right = NULL;
//
//        return temp;
//
//    }
//
//    void inorder(struct BNode* root)
//
//    {
//
//        if (root != NULL) {
//
//            inorder(root->left);
//
//            printf("%d \n", root->data);
//
//            inorder(root->right);
//
//        }
//
//    }
//
//    void insert(int key) {
//
//        root = insertNode(root, key);
//
//    }
//
//    BNode* insertNode(BNode* node, int key)
//
//    {
//
//        if (node == NULL)
//
//            return newNode(key);
//
//        if (key < node->data)
//
//            node->left = insertNode(node->left, key);
//
//        else if (key > node->data)
//
//            node->right = insertNode(node->right, key);
//
//        return node;
//
//    }
//
//    int findHeightUtil(BNode* root, int x, int& height)
//
//    {
//
//        if (root == NULL) {
//
//            return -1;
//
//        }
//
//        int leftHeight = findHeightUtil(
//
//            root->left, x, height);
//
//
//
//        int rightHeight
//
//            = findHeightUtil(
//
//                root->right, x, height);
//
//        int ans = max(leftHeight, rightHeight) + 1;
//
//        if (root->data == x)
//
//            height = ans;
//
//
//
//        return ans;
//
//    }
//
//    //end your code
//
//};
//
//int search(BSTree* tree, int K)
//
//{
//
//    // your code here
//
//    int h = -1;
//
//    int maxHeight = tree->findHeightUtil(tree->root, K, h);
//
//    return h;
//
//    //end your code
//
//}
//int main() {
//    struct BSTree BST;
//    BST.insert(50);
//    BST.insert(60);
//    BST.insert(30);
//    BST.insert(40);
//    BST.insert(20);
//    BST.insert(10);
//
//    printf("%d", search(&BST, 30));
//}
////////////////////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <iostream>
//struct BNode { //BST --> AVL
//	int data;
//	BNode* left, * right;
//	// your code here
//	BNode(int data) {
//		this->data = data;
//		left = right = nullptr;
//	}
//	// end your code
//};
//struct Tree {
//	BNode* root = nullptr;
//	// your code here
//	bool isEmpty() { return root == nullptr; }
//	void insert(int data, BNode*& node) {
//		BNode* newNode = new BNode(data);
//		if (node == nullptr) {
//			node = newNode;
//		}
//		else {
//			if (node->data > data)
//				insert(data, node->left);
//			else
//				insert(data, node->right);
//		}
//	}
//
//
//	/*void Add(int data) {
//		insert(data, root);
//	}*/
//
//	//end your code
//};
//int* leftView(Tree* tree, int& N)
//{
//	// your code here
//	BNode* node = tree->root;
//	N = 0;
//	int res[1000];
//	if (node == nullptr)
//		return &res[0];
//
//	res[N++] = node->data;
//	node = node->left;
//
//	while (node != nullptr) {
//		res[N++] = node->data;
//		if (node->left == nullptr)
//			node = node->right;
//		else
//			node = node->left;
//	}
//	return &res[0];
//	//end your code
//}
//void main()
//{
//	Tree binaryTree;
//	binaryTree.insert(10, binaryTree.root);
//	binaryTree.insert(2, binaryTree.root);
//	binaryTree.insert(3, binaryTree.root);
//	binaryTree.insert(7, binaryTree.root);
//	binaryTree.insert(8, binaryTree.root);
//	binaryTree.insert(15, binaryTree.root);
//	binaryTree.insert(12, binaryTree.root);
//	binaryTree.insert(14, binaryTree.root);
//
//
//	//binaryTree.print(binaryTree.root);
//
//	//printf("%d\n", binaryTree.deleteNode(15, binaryTree.root));
//	int N;
//	//printf("%d", binaryTree.root->data);
//	//printf("%d\n",*getDistance(binaryTree,6,1,N)),"\n";
//	//printf("%d\n", maxDepth(binaryTree.root));
//	int* res = leftView(&binaryTree, N);
//	for (int i = 0; i < N; i++)
//	{
//		std::cout << res[i] << " ";
//	}
//
//	std::cout << "N = " << N;
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//
//struct HashTable {
//
//    int K = 10;
//
//    Node* table;
//
//    void construct(int arr[], int N) {
//
//        // your code here
//        table = new Node[K];
//        int i, j, swap;
//        for  (i = 0; i < N - 1; i++)
//        {
//            for  (j = i + 1; j < N; j++)
//            {
//                if (arr[i] > arr[j])
//                {
//                    swap = arr[i];
//                    arr[i] = arr[j];
//                    arr[j] = swap;
//                }
//            }
//        }
//        for (i = 0; i < K; i++)
//        {
//            table[i].data = NULL;
//            table[i].next = nullptr;
//        }
//            
//        int key;
//
//        for (i = 0; i < N; i++)
//        {
//            key = arr[i] % K;
//            if (table[key].next == nullptr)
//            {
//                Node* temp = new Node();
//                temp->data = arr[i];
//                temp->next = nullptr;
//                table[key].next = temp;
//            }
//            else
//            {
//                Node* temp1 = table[key].next;
//                while (temp1->next != nullptr)
//                {
//                    temp1 = temp1->next;
//                }
//                Node* temp2 = new Node();
//                temp2->data = arr[i];
//                temp2->next = nullptr;
//                temp1->next = temp2;
//            }
//        }
//
//        // end your code
//        
//
//    }
//
//};
//int main()
//{
//    int A[] = { 10,22,107,12,42 };
//    int i;
//    int N = sizeof(A) / sizeof(A[0]);
//    HashTable hb;
//    hb.construct(A, N);
//    for (i = 0; i < hb.K; i++)
//    {
//        if (hb.table[i].next == nullptr)
//            printf("%d: ----->\n", i);
//        else
//        {
//            Node* temp = hb.table[i].next;
//            printf("%d: ----->%d", i, temp->data);
//            while (temp->next != nullptr)
//            {
//                temp = temp->next;
//                printf("----->%d", temp->data);
//            }
//            printf("\n");
//        }
//    }
//}
//////////////////////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//
//struct Node {
//
//    int data;
//
//    Node* next;
//
//};
//
//struct HashTable {
//
//    int K;
//
//    Node* table;
//
//    void construct(int arr[], int N) {
//
//        // your code here
//        int key, i, j;
//        table = new Node[K];
//        for (i = 0; i < K; i++) {
//            table[i].next = NULL;
//            table[i].data = NULL;
//        }
//        for (i = 0; i < N; i++) {
//            key = arr[i] % K;
//            Node* temp = &table[key];
//            while (temp->next != NULL)
//            {
//                temp = temp->next;
//            }
//
//            Node* newNode = new Node();
//            newNode->data = arr[i];
//            newNode->next = NULL;
//            if (temp->data == NULL) {
//                temp->data = arr[i];
//                temp->next = NULL;
//            }
//            else
//                temp->next = newNode;
//        }
//        // end your code
//
//    }
//
//};
//int main()
//{
//    int A[8] = { 10,22,107,12,42 };
//    int N = 5;
//    HashTable hb;
//    hb.K = 10;
//    hb.construct(A, N);
//    for (int i = 0; i < hb.K; i++)
//    {
//        Node* temp = &hb.table[i];
//        while (temp != NULL) {
//            printf("%d ", temp->data);
//            temp = temp->next;
//        }
//        printf("\n");
//    }
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//using namespace std;
//#include <stdio.h>
//
//struct BNode { //BST --> AVL
//
//	int data;
//
//	BNode* left, * right;
//
//	// your code here
//
//	BNode(int data) {
//
//		this->data = data;
//
//		left = right = nullptr;
//
//	}
//
//	// end your code
//
//};
//
//struct Tree {
//
//	BNode* root = nullptr;
//
//	// your code here
//
//	int arr[1000] = { 0 };
//
//	int count = 0;
//
//	bool empty() {
//
//		return root == nullptr;
//
//	}
//
//
//
//	void insert(int data, BNode*& node) {
//
//		BNode* newNode = new BNode(data);
//
//		if (node == nullptr) {
//
//			node = newNode;
//
//		}
//
//		else {
//
//			if (node->data > data)
//
//				insert(data, node->left);
//
//			else
//
//				insert(data, node->right);
//
//		}
//
//	}
//
//
//
//	void insert(int val) {
//
//		insert(val, root);
//
//	}
//
//	void searchNodeDown(BNode* root, int k)
//
//	{
//
//		if (root == NULL || k < 0)  return;
//
//		if (k == 0)
//
//		{
//
//			arr[count++] = root->data;
//
//			return;
//
//		}
//
//		searchNodeDown(root->left, k - 1);
//
//		searchNodeDown(root->right, k - 1);
//
//	}
//
//	int searchNode(BNode* root, int target, int k)
//
//	{
//
//		if (root == NULL) return -1;
//
//		if (root->data == target)
//
//		{
//
//			searchNodeDown(root, k);
//
//			return 0;
//
//		}
//
//
//
//		int temp1 = searchNode(root->left, target, k);
//
//		if (temp1 != -1)
//
//		{
//
//			if (temp1 + 1 == k)
//
//				arr[count++] = root->data;
//
//			else
//
//				searchNodeDown(root->right, k - temp1 - 2);
//
//			return 1 + temp1;
//
//		}
//
//		int temp2 = searchNode(root->right, target, k);
//
//		if (temp2 != -1)
//
//		{
//
//			if (temp2 + 1 == k)
//
//				arr[count++] = root->data;
//
//			else
//
//				searchNodeDown(root->left, k - temp2 - 2);
//
//			return 1 + temp2;
//
//		}
//
//		return -1;
//
//	}
//
//	//end your code
//
//};
//
//int* getDistance(Tree* tree, int n, int k, int& N)
//
//{
//
//	// your code here
//
//	tree->searchNode(tree->root, n, k);
//
//	N = tree->count;
//
//	int* result = &(tree->arr[0]);
//
//	return result;
//
//	//end your code
//
//}
//int main()
//{
//	Tree b;
//	int n;
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		b.insert(x);
//	}
//	int dem;
//	int* res = getDistance(&b, 5, 2, dem);
//	for (int i = 0; i < dem; i++)
//		cout << res[i] << " ";
//	cout << endl << dem;
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

struct Node {

	int data;

	Node* next;

};

struct HashTable {

	int K;

	Node* table;

	void construct(int arr[], int N) {

		// your code here

		int key, i, j;

		table = new Node[K];

		for (i = 0; i < K; i++) {

			table[i].next = NULL;

			table[i].data = NULL;

		}

		for (i = 0; i < N; i++) {

			key = arr[i] % K;

			Node* temp = &table[key];

			while (temp->next != NULL)

			{

				temp = temp->next;

			}



			Node* newNode = new Node();

			newNode->data = arr[i];

			newNode->next = NULL;

			if (temp->data == NULL) {

				temp->data = arr[i];

				temp->next = NULL;

			}

			else

				temp->next = newNode;

		}

		// end your code

	}

};
int main()
{
	int A[] = { 10,22,107,12,42 };
	int N = 5;
	HashTable hb;
	hb.K = 10;
	hb.construct(A, N);
	for (int i = 0; i < hb.K; i++)
	{
		Node* temp = &hb.table[i];
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
