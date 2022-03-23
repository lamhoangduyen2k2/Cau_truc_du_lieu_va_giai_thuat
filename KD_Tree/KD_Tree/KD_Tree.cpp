// A C++ program to demonstrate operations of KD tree
#include<iostream>
using namespace std;

const int k = 2;

// 
struct Node
{
    int point[k]; // To store k dimensional point
    Node* left, * right;
    //unsigned depth = 0;
};
//
struct Node* newNode(int arr[])
{
    struct Node* temp = new Node;

    for (int i = 0; i < k; i++)
        temp->point[i] = arr[i];

    temp->left = temp->right = NULL;
    return temp;
}
// 
Node* insertRec(Node* root, int point[], unsigned depth)
{
    // Tree is empty?
    if (root == NULL)
        return newNode(point);

    // Calculate current dimension (cd) of comparison
    unsigned cd = depth % k;

    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (point[cd] < (root->point[cd]))
    {
        root->left = insertRec(root->left, point, depth + 1);
        //root->left->depth = depth + 1;
    }
    else
    {
        root->right = insertRec(root->right, point, depth + 1);
        //root->right->depth = depth + 1;
    }
    return root;
}
// 
Node* insert(Node* root, int point[])
{
    return insertRec(root, point, 0);
}
void printRec(Node* temp)
{
    if (temp != NULL)
    {
        printRec(temp->left);
        cout << "{" << temp->point[0] << "," << temp->point[1] << "} ";
        printRec(temp->right);
    }
}
void print(Node* root)
{
    cout << "Root: " << "{" << root->point[0] << "," << root->point[1] << "}" << "\n";
    printRec(root);
}
// 
Node* minNode(Node* x, Node* y, Node* z, int d)
{
    Node* res = x;
    if (y != NULL && y->point[d] < res->point[d])
        res = y;
    if (z != NULL && z->point[d] < res->point[d])
        res = z;
    return res;
}
//
Node* findMinRec(Node* root, int d, unsigned depth)
{
    // Base cases
    if (root == NULL)
        return NULL;

    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned cd = depth % k;

    // Compare point with root with respect to cd (Current dimension)
    if (cd == d)
    {
        if (root->left == NULL)
            return root;
        return findMinRec(root->left, d, depth + 1);
    }
    // If current dimension is different then minimum can be anywhere
    // in this subtree
    return minNode(root, findMinRec(root->left, d, depth + 1), findMinRec(root->right, d, depth + 1), d);
}
//
Node* findMin(Node* root, int d)
{
    // Pass current level or depth as 0
    return findMinRec(root, d, 0);
}
bool arePointsSame(int point1[], int point2[])
{
    // Compare individual pointinate values
    for (int i = 0; i < k; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}
//
void copyPoint(int p1[], int p2[])
{
    for (int i = 0; i < k; i++)
        p1[i] = p2[i];
}
//
Node* deleteNodeRec(Node* root, int point[], int depth)
{
    // Given point is not present
    if (root == NULL)
        return NULL;

    // Find dimension of current node
    int cd = depth % k;
    // If the point to be deleted is present at root
    if (arePointsSame(root->point, point))
    {
        // 2.b) If right child is not NULL
        if (root->right != NULL)
        {
            // Find minimum of root's dimension in right subtree
            Node* min = findMin(root->right, cd);

            // Copy the minimum to root
            copyPoint(root->point, min->point);

            // Recursively delete the minimum
            root->right = deleteNodeRec(root->right, min->point, depth + 1);
        }
        else if (root->left != NULL) // same as above
        {
            Node* min = findMin(root->left, cd);
            copyPoint(root->point, min->point);
            root->right = deleteNodeRec(root->left, min->point, depth + 1);
        }
        else // If node to be deleted is leaf node
        {
            delete root;
            return NULL;
        }
        return root;
    }
    if (point[cd] < root->point[cd])
        root->left = deleteNodeRec(root->left, point, depth + 1);
    else
        root->right = deleteNodeRec(root->right, point, depth + 1);
    return root;
}
//
Node* deleteNode(Node* root, int point[])
{
    // Pass depth as 0
    return deleteNodeRec(root, point, 0);
}
//
bool searchRec(Node* root, int point[], unsigned depth)
{
    // Base cases
    if (root == NULL)
        return false;
    if (arePointsSame(root->point, point))
        return true;

    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned cd = depth % k;

    // Compare point with root with respect to cd (Current dimension)
    if (point[cd] < root->point[cd])
        return searchRec(root->left, point, depth + 1);
    return searchRec(root->right, point, depth + 1);
}
//
bool search(Node* root, int point[])
{
    // Pass current depth as 0
    return searchRec(root, point, 0);
}
//
int main()
{
    struct Node* root = NULL;
    int points[][k] = { {3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19} };

    int n = sizeof(points) / sizeof(points[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, points[i]);
    print(root);
    /*int point1[] = { 10, 19 };
    (search(root, point1)) ? cout << "Found\n" : cout << "Not Found\n";

    int point2[] = { 12, 19 };
    (search(root, point2)) ? cout << "Found\n" : cout << "Not Found\n";*/
    root = deleteNode(root, points[1]);

    cout << "\nRoot after deletion of \n";
    cout << points[1][0] << ", " << points[1][1] << endl;
    print(root);
    /*cout << "Minimum of 0'th dimension is " << findMin(root, 0)->point[0] << endl;
    cout << "Minimum of 1'th dimension is " << findMin(root, 1)->point[1] << endl;*/
    return 0;
}
