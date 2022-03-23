#include <iostream>
#include <queue>

struct BNode {
	int data;
	BNode* left, * right;
	void init() {
		left = right = nullptr;
	}
};

struct Tree {
	BNode* root = nullptr;
	void init(BNode*& node) {
		node = new BNode;
		node->init();
	}
	BNode* merge(BNode* root1, BNode* root2) {
		// assume: root1 < root2
		BNode* result = root1;
		BNode* root1right = root1->right;
		root1->right = root2;
		//tim vi tri merge root1right
		BNode* temp = root2;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		temp->left = root1right;
		return result;
	}
	int deleteNode(int value, BNode*& parent) {
		//tim node
		BNode* temp = parent;
		BNode* current_root = parent;
		while (temp != nullptr && temp->data != value)
		{
			current_root = temp;
			if (temp->data < value)  temp = temp->right;
			else   temp = temp->left;
		}
		if (temp == nullptr) {
			return -1;
		}
		//xoa node
		if (temp->left == nullptr && temp->right == nullptr) {
			delete temp;
			if (current_root->data > value)   current_root->left = nullptr;
			else  current_root->right = nullptr;
		}
		else {
			if (temp->left != nullptr && temp->right == nullptr) {
				current_root->left = temp->left;
				temp->left->right = temp->right;
			}
			else if (temp->right != nullptr && temp->left == nullptr) {
				current_root->right = temp->right;
				temp->right->left = temp->left;
			}
			else {
				BNode* treemerge;
				treemerge = merge(temp->left, temp->right);
				if (current_root->data > value) {
					current_root->left = treemerge;
				}
				else if (current_root->data < value) {
					current_root->right = treemerge;
				}
				else {
					parent = treemerge;
				}

			}
			delete temp;
		}
		return 1;
	}
	int N = 0;
	void size_tree(BNode* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		if (temp != NULL)
		{
			size_tree(temp->right);
			N++;
			size_tree(temp->left);
		}
	}
	void make_array(int tree[], BNode* temp, int& i)
	{
		//int i = 0;
		if (temp == nullptr)
		{
			return;
		}
		if (temp != NULL)
		{
			make_array(tree, temp->right, i);
			tree[i] = temp->data;
			//tree->data = temp->data;
			//printf("\n%d %d", temp->data, i);
			i++;
			make_array(tree,temp->left, i);
		}
	}
	void sort(int tree[], int N) {
		int swap;
		for  (int i = 0; i < N-1; i++)
		{
			for  (int j = i + 1; j < N; j++)
			{
				if (tree[j] < tree[i])
				{
					swap = tree[i];
					tree[i] = tree[j];
					tree[j] = swap;
				}
			}
		}
	}


	/* see quickselect method */
	int
		find_median(int tree[], int start, int end, struct BNode*& temp)
	{
		if (end <= start) return NULL;
		/*if (end == start + 1)
			return start;*/

		int md = start + (end - start) / 2;
		insert(tree[md], temp);
		return md;
	}

	void make_tree(struct BNode*& t,int tree[],int front, int len)
	{
		int n;

		if (len == 0) return;

		if ((n = find_median(tree,front, front + len, t))) {
			//i = (i + 1) % dim;
			make_tree(t,tree,front, n - front);
			make_tree(t,tree,n + 1, front + len - (n + 1));
		}
		return;
	}
	void balance(BNode*& parent) {
		//insert 1 node
		//delete 1 node
		// call balance
		//int N = size_tree(parent), dem = 0;
		size_tree(parent);
		BNode* root = nullptr;
		int tree[1000], i = 0;
		make_array(tree, parent, i);
		sort(tree, N);
		make_tree(root, tree, 0, N);
		parent = root;
	}
	void insert(int value, BNode*& parent) {
		if (parent == nullptr) {
			init(parent);
			parent->data = value;
			return;
		}
		//tim vi tri de insert
		if (value < parent->data) {
			insert(value, parent->left);

		}
		else {
			insert(value, parent->right);

		}
		return;
	}
	void print(BNode* parent) {
		//in theo de quy
		/*
		if (parent != nullptr) {
			printf("%d ", parent->data);
			if (parent->left != nullptr) {
				print(parent->left);
			}
			if (parent->right != nullptr) {
				print(parent->right);
			}
		}
		else
			return;
		*/
		//in bằng cách sử dụng stack
		std::queue<BNode*> results;
		BNode* node = parent;
		BNode* current_node;
		results.push(node);
		while (results.empty() == false) {
			current_node = results.front();
			results.pop();
			printf("%d ", current_node->data);
			if (current_node->left != nullptr)   results.push(current_node->left);
			if (current_node->right != nullptr)   results.push(current_node->right);
		}

	}
};


int main()
{
	Tree binaryTree;
	binaryTree.insert(10, binaryTree.root);
	binaryTree.insert(5, binaryTree.root);
	binaryTree.insert(6, binaryTree.root);
	binaryTree.insert(15, binaryTree.root);
	binaryTree.insert(12, binaryTree.root);
	binaryTree.insert(7, binaryTree.root);
	binaryTree.insert(30, binaryTree.root);
	binaryTree.insert(35, binaryTree.root);
	binaryTree.insert(45, binaryTree.root);


	binaryTree.print(binaryTree.root);

	printf("%d\n", binaryTree.deleteNode(15, binaryTree.root));
	binaryTree.balance(binaryTree.root);
	binaryTree.print(binaryTree.root);
}
