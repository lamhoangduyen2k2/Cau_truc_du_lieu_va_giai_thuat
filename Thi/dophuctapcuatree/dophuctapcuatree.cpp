#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm> 
#include <list>
#include <chrono>
#include <thread>
using namespace std;
#define MAX_DIM 3
struct kd_node_t {
    double x[MAX_DIM];
    struct kd_node_t* left, * right;
};
struct Colour_code_name
{
    int r;
    int g;
    int b;
    string colour;
};
//typedef Colour_code_name Code_name;
inline double
dist(struct kd_node_t* a, struct kd_node_t* b, int dim)
{
    double t, d = 0;
    while (dim--) {
        t = a->x[dim] - b->x[dim];
        d += t * t;
    }
    return d;
}
inline void swap(struct kd_node_t* x, struct kd_node_t* y) {
    double tmp[MAX_DIM];
    memcpy(tmp, x->x, sizeof(tmp));
    memcpy(x->x, y->x, sizeof(tmp));
    memcpy(y->x, tmp, sizeof(tmp));
}


/* see quickselect method */
struct kd_node_t*
    find_median(struct kd_node_t* start, struct kd_node_t* end, int idx)
{
    if (end <= start) return NULL;
    if (end == start + 1)
        return start;

    struct kd_node_t* p, * store, * md = start + (end - start) / 2;
    double pivot;
    while (1) {
        pivot = md->x[idx];

        swap(md, end - 1);
        for (store = p = start; p < end; p++) {
            if (p->x[idx] < pivot) {
                if (p != store)
                    swap(p, store);
                store++;
            }
        }
        swap(store, end - 1);

        /* median has duplicate values */
        if (store->x[idx] == md->x[idx])
            return md;

        if (store > md) end = store;
        else        start = store;
    }
}

struct kd_node_t*
    make_tree(struct kd_node_t* t, int len, int i, int dim)
{
    struct kd_node_t* n;

    if (!len) return 0;

    if ((n = find_median(t, t + len, i))) {
        i = (i + 1) % dim;
        n->left = make_tree(t, n - t, i, dim);
        n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
    }
    //this_thread::sleep_for(std::chrono::seconds(1));
    return n;

}
#define COUNT 10
void printRec(kd_node_t* temp, int space)
{
    if (temp == NULL)
    {
        return;
    }
    if (temp != NULL)
    {
        space += COUNT;
        printRec(temp->right, space);
        cout << "\n";
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << "{" << temp->x[0] << "," << temp->x[1] << "} ";
        printRec(temp->left, space);
    }
}

void print(kd_node_t* root)
{
    cout << "Root: " << "{" << root->x[0] << "," << root->x[1] << "}" << "\n";
    printRec(root, 0);
}
void printRec3(kd_node_t* temp, int space)
{
    if (temp == NULL)
    {
        return;
    }
    if (temp != NULL)
    {
        space += COUNT;
        printRec3(temp->right, space);
        cout << "\n";
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << "{" << temp->x[0] << "," << temp->x[1] << "," << temp->x[2] << "} ";
        printRec3(temp->left, space);
    }
}

void print3(kd_node_t* root)
{
    cout << "Root: " << "{" << root->x[0] << "," << root->x[1] << "," << root->x[2] << "}" << "\n";
    printRec3(root, 0);
}
const int k = 3;
kd_node_t* minNode(kd_node_t* x, kd_node_t* y, kd_node_t* z, int d)
{
    kd_node_t* res = x;
    if (y != NULL && y->x[d] < res->x[d])
        res = y;
    if (z != NULL && z->x[d] < res->x[d])
        res = z;
    return res;
}
//
kd_node_t* findMinRec(kd_node_t* root, int d, unsigned depth)
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
kd_node_t* findMin(kd_node_t* root, int d)
{
    // Pass current level or depth as 0
    return findMinRec(root, d, 0);
}
bool arePointsSame(kd_node_t* point1, kd_node_t* point2)
{
    // Compare individual pointinate values
    for (int i = 0; i < k; ++i)
        if (point1->x[i] != point2->x[i])
            return false;

    return true;
}
//
void copyPoint(kd_node_t* p1, kd_node_t* p2)
{
    for (int i = 0; i < k; i++)
        p1->x[i] = p2->x[i];
}
//
kd_node_t* deleteNodeRec(kd_node_t* root, kd_node_t* point, int depth)
{
    // Given point is not present
    if (root == NULL)
        return NULL;
    kd_node_t* temp = NULL;
    // Find dimension of current node
    int cd = depth % k;
    // If the point to be deleted is present at root
    if (arePointsSame(root, point))
    {
        // 2.b) If right child is not NULL
        if (root->right != NULL)
        {
            // Find minimum of root's dimension in right subtree
            kd_node_t* min = findMin(root->right, cd);

            // Copy the minimum to root
            copyPoint(root, min);
            // Recursively delete the minimum
            root->right = deleteNodeRec(root->right, min, depth + 1);
        }
        else if (root->left != NULL) // same as above
        {
            kd_node_t* min = findMin(root->left, cd);
            copyPoint(root, min);
            root->left = deleteNodeRec(root->left, min, depth + 1);
        }
        else // If node to be deleted is leaf node
        {
            return NULL;
        }
        return root;
    }
    if (point->x[cd] < root->x[cd])
        root->left = deleteNodeRec(root->left, point, depth + 1);
    else
        root->right = deleteNodeRec(root->right, point, depth + 1);
    return root;
}
//
kd_node_t* deleteNode(kd_node_t* root, kd_node_t* point)
{
    // Pass depth as 0
    return deleteNodeRec(root, point, 0);
}
#define N 10000
#define rand1() (rand() / (double)RAND_MAX)
#define rand_pt(v) { v.x[0] = rand(); v.x[1] = rand(); v.x[2]=rand(); }
int main(void)
{

    struct kd_node_t* root, * found, * million;
    million = (struct kd_node_t*)calloc(N, sizeof(struct kd_node_t));
    int ar[1000];
    int min = NULL, max = NULL;
    double mean, sum = 0;
    //
    int res;
    //
    for (int j = 0; j < 1000; j++)
    {
        for (int i = 0; i < N; i++)
        {
            rand_pt(million[i]);
        }
        srand(time(NULL));
        for (int i = 0; i < 1000; i++)
        {
            res = rand() % (9999 - 0 + 1) + 0;
            ar[i] = res;
            //cout << ar[i] << "\n";
        }
        root = make_tree(million, N, 0, 3);
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = deleteNodeRec(root, (&million[ar[i]]), 0);
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1);
        // Min time
        if (min == NULL)
        {
            min = duration.count();
        }
        else if (min > duration.count())
        {
            min = duration.count();
        }
        // Max time
        if (max == NULL)
        {
            max = duration.count();
        }
        else if (max < duration.count())
        {
            max = duration.count();
        }
        //
        sum += duration.count();
        //cout << j << ": " << duration.count() << endl;
    }
    mean = sum / 1000;
    cout << "Sum: " << sum << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Mean: " << mean << endl;
    return 0;
}