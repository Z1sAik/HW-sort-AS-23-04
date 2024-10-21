#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <set>
#define SIZE 5000

using namespace std;
//��������� - ���� ������
struct TNode {
    int field;
    TNode* left;
    TNode* right;

    TNode(int x) : field(x), left(nullptr), right(nullptr) {}
};

//����� ����� ������ (����� � ��������� �����)
void treePrint(TNode* tree) {
    if (tree != nullptr) {
        treePrint(tree->left);
        cout << tree->field << " ";
        treePrint(tree->right);
    }
}

//���������� ����� � ������
TNode* addNode(int x, TNode* tree) {
    if (tree == nullptr) {
        return new TNode(x);
    }
    if (x < tree->field) {
        tree->left = addNode(x, tree->left);
    }
    else {
        tree->right = addNode(x, tree->right);
    }
    return tree;
}

//������������ ������ ������
void freeMem(TNode* tree) {
    if (tree != nullptr) {
        freeMem(tree->left);
        freeMem(tree->right);
        delete tree;
    }
}
//������������� ���������� ����� �����
void generateUniqueNumbers(int* arr, int size, int min, int max) {
    set<int> uniqueNumbers;
    while (uniqueNumbers.size() < size) {
        uniqueNumbers.insert(rand() % (max - min + 1) + min);
    }
    copy(uniqueNumbers.begin(), uniqueNumbers.end(), arr);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int arr[SIZE];

    //��������� 20 ���������� ��������� �����
    generateUniqueNumbers(arr, SIZE, 1, 50000);

    TNode* root = nullptr;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        root = addNode(arr[i], root);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> dur = end - start;
    cout << "��������������� �����: ";
    treePrint(root);
    cout << endl;
    cout << "����� ���������� ����������: " << dur.count() << " �����������" << endl;
    freeMem(root);
    return 0;
}