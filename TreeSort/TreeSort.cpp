#include <iostream>
#include <Windows.h>
using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int key) 
{
    if (root == nullptr) 
    {
        return new Node(key);
    }

    if (key <= root->key) 
    {
        root->left = insert(root->left, key);
    }
    else 
    {
        root->right = insert(root->right, key);
    }

    return root;
}
Node* createTree(int* arr, const int size, Node* root)
{
    for (int i = 0; i < size; ++i)
    {
        int key = arr[i];
        root = insert(root, key);
    }
    return root;
}

void printArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void inOrder(Node* root, int* arr, int& index) 
{
    static int counter = 0;
    if (root != nullptr) 
    {
        inOrder(root->left, arr, index);
        arr[index++] = root->key;
        cout << "Крок " << ++counter;
        if (counter < 10) cout << ":  ";
        else cout << ": ";
        printArray(arr, 10);
        inOrder(root->right, arr, index);
    }
}


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 5, 3, 2, 4, 7, 6, 8, 3, 4,9 };
    const int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = nullptr;
    root = createTree(arr, size, root);
    int index = 0;
    cout << "Масив до сортування: ";
    printArray(arr, size);
    cout << endl;
    inOrder(root, arr,index);
    cout << "Масив посортовано";
    return 0;
}