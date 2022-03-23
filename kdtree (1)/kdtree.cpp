#include<iostream>
#include<string.h>
using namespace std;
#include<vector>
#include<fstream>
#include<string>
#include <algorithm> 
#include <list>
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
    return n;
}

/* global variable, so sue me */
int visited;
void nearest(struct kd_node_t* root, struct kd_node_t* nd, int i, int dim,
    struct kd_node_t** best, double* best_dist)
{
    double d, dx, dx2;

    if (!root) return;
    d = dist(root, nd, dim);
    dx = root->x[i] - nd->x[i];
    dx2 = dx * dx;

    visited++;

    if (!*best || d < *best_dist) {
        *best_dist = d;
        *best = root;
    }

    /* if chance of exact match is high */
    if (!*best_dist) return;

    if (++i >= dim) i = 0;

    nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);
    if (dx2 >= *best_dist) return;
    nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
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
//#define N 424
Colour_code_name make_tree_file(string infile , Colour_code_name result_code)
 {   
    ifstream fileInput;
    int count, dem = 0, i = 0, N;
    list<int>myFile;
    fileInput.open(infile, fstream::in);
    while (fileInput.fail())
    {
        cout << "File's not found.";
    }
    struct kd_node_t* n;
    while (fileInput)
    {
        fileInput >> i;
        myFile.push_back(i);
    }
    i = 0;
    N = (myFile.size() - 1) / 3;
    n = (struct kd_node_t*)calloc(N, sizeof(struct kd_node_t));
    //cout << "Mang: " << count << endl;
    for (list<int>::iterator it = myFile.begin(); it != myFile.end(); ++it)
    {

        if (dem < 3)
        {
            n->x[i] = *it;
            dem++;
            //cout << n->x[i] << " " << i << endl;
        }
        else
        {
            dem = 0;
            it--;
        }
        i++;
    }
    struct kd_node_t* root, * found;
    root = make_tree(n,N, 0, 3);
    struct kd_node_t testNode = { {0, 0, 0} };
    double best_dist;
    visited = 0;
    found = 0;
    nearest(root, &testNode, 0, 3, &found, &best_dist);
    result_code.r = found->x[0];
    result_code.g = found->x[1];
    result_code.b = found->x[2];
    printf(">>\nsearching for (%g, %g, %g)\n"
        "found (%g, %g, %g) dist %g\nseen %d nodes\n",
        testNode.x[0], testNode.x[1], testNode.x[2],
        found->x[0], found->x[1], found->x[2],
        sqrt(best_dist), visited);
    print3(root);
    return result_code;

}

void input_colour_code(Colour_code_name input[], int n, string infile)
{
    ifstream fileInput;
    int count, dem = 0, i = 0;
    fileInput.open(infile, fstream::in);
    while (fileInput.fail())
    {
        cout << "File's not found.";
    }
    while (fileInput)
    {

        if (dem < 3)
        {
            if (dem == 0)
            {
                fileInput >> input[i].r;
            }
            if (dem == 1)
            {
                fileInput >> input[i].g;
            }
            if(dem==2)
            {
                fileInput >> input[i].b;
            }
            dem++;
        }
        else
        {
            //cout << input[i].r << " " << input[i].g << " " << input[i].b << "\n";
            i++;
            dem = 0;

            //cout << i << " " << n->x[i] << "\n";
        }
    }


}

void input_colour_name(Colour_code_name input[], int n, string infile)
{
    ifstream fileInput;
    int count, dem = 0, i = 0;
    fileInput.open(infile, fstream::in);
    while (fileInput.fail())
    {
        cout << "File's not found.";
    }
    for (i = 0; i < n; i++)
    {
        fileInput >> input[i].colour;
    }

}
 void compare_color_code(Colour_code_name input[],Colour_code_name result_code,int n)
 {
     for (int i = 0; i < n; i++)
     {
         if (result_code.r == input[i].r && result_code.g == input[i].g && result_code.b == input[i].b)
         {
             printf("\nThe equivalent colour to colour code of (%d, %d, %d) is: ", result_code.g, result_code.g, result_code.b);
             cout << input[i].colour;
         }
     }
 }
 void pressAnyKey() {
     cout << "\n\nBam phim bat ky de tiep tuc...";
     system("pause");
     system("cls");
 }
 int main(void)
 {
     struct kd_node_t* root, * found;
     double best_dist;
     struct kd_node_t testNode = { {9, 2} };
     struct kd_node_t wp[] = {
         {{5, 4}},{{7, 2}}, {{2, 3}}, {{9, 6}}, {{8, 1}}, {{4, 2}}
     };
     root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);
     struct kd_node_t* root2;
     struct kd_node_t mang3[] = {
         {{2,3,7}}, {{4,3,4}}, {{3, 1, 4}}, {{2,1,3}}, {{2,4,5}}, {{6,1,4}}, {{1,4,4}},{{0,5,7}},{{5,2,5}},{{4,0,6}},{{7,1,6}}
     };
     struct kd_node_t testNode2 = { {9, 2,4} };
     root2 = make_tree(mang3, sizeof(mang3) / sizeof(mang3[1]), 0, 3);
     int key;
     while (true)
     {
         cout << "***************************************************\n";
         cout << "**    CHUONG TRINH HIEN THI K-D TREE             **\n";
         cout << "**      1. In k-d tree 2 chieu                   **\n";
         cout << "**      2. Tim diem gan {9,2} trong cay 2 chieu  **\n";
         cout << "**      3. In k-d tree 3 chieu                   **\n";
         cout << "**      4. Tim diem gan {9,2,4} trong cay 3 chieu**\n";
         cout << "**      5. In k-d tree 3 chieu cho file mau. Tim diem mau gan diem {248, 248,254}.Vi tri tim thay la mau**\n";
         //cout << "**      6. Tim diem mau gan diem {248, 248,254}  **\n";
         //cout << "**      7. Vi tri tim thay la mau                **\n";
         cout << "**      0. Thoat                                 **\n";
         cout << "***************************************************\n";
         cout << "**       Nhap lua chon cua ban                   **\n";
         cin >> key;
         switch (key)
         {
         case 1:
         {
             print(root);
             pressAnyKey();
             break;
         }
         case 2:
         {
             visited = 0;
             found = 0;
             nearest(root, &testNode, 0, 2, &found, &best_dist);
             printf(">>cay 2 chieu \ndiem dang tim (%g, %g)\n"
                 "diem gan nhat tim thay (%g, %g) khoang cach %g\nseen %d nodes\n\n",
                 testNode.x[0], testNode.x[1],
                 found->x[0], found->x[1], sqrt(best_dist), visited);
             pressAnyKey();
             break;
         }

         case 3:
         {
             print3(root2);
             pressAnyKey();
             break;
         }
         case 4:
         {
             found = 0;
             nearest(root, &testNode2, 0, 3, &found, &best_dist);

             printf(">> cay 3 chieu\ndiem dang tim (%g, %g, %g)\n"
                 "diem gan nhat tim thay (%g, %g, %g) khoang cach %g\nseen %d nodes\n",
                 testNode2.x[0], testNode2.x[1], testNode2.x[2],
                 found->x[0], found->x[1], found->x[2],
                 sqrt(best_dist), visited);
             pressAnyKey();
             break;
         }
         case 5:
         {
             int n = 424;
             Colour_code_name input[1000];
             Colour_code_name result_code;
             input_colour_code(input, n, "./color_code.txt");
             input_colour_name(input, n, "./color_name.txt");
             result_code = make_tree_file("./color_code.txt", result_code);
             compare_color_code(input, result_code, n);
             pressAnyKey();
             break;
         }
         case 0:
         {
             printf("\nBan da chon thoat chuong trinh!");

             return 0;
         }
         default:
         {
             printf("\nKhong co chuc nang nay!");
             printf("\nBam phim bat ky de tiep tuc!");
             pressAnyKey();
             break;
         }
         }

     }

 }