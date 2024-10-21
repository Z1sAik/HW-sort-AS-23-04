#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithms.h"

//��������� - ���� ������
template <typename T>
struct TNode {
    T field;
    TNode* left;
    TNode* right;

    TNode(T x) : field(x), left(nullptr), right(nullptr) {}
};

//���������� ����� � ������
template <typename T>
TNode<T>* addNode(TNode<T>* tree, T x) {
    if (tree == nullptr) {
        return new TNode<T>(x);
    }
    if (x < tree->field) {
        tree->left = addNode(tree->left, x);
    }
    else {
        tree->right = addNode(tree->right, x);
    }
    return tree;
}

//��������� ����� ��� ���������� ��������������� ������
template <typename T>
void inorder(TNode<T>* tree, std::vector<T>& sorted) {
    if (tree != nullptr) {
        inorder(tree->left, sorted);
        sorted.push_back(tree->field);
        inorder(tree->right, sorted);
    }
}

//������������ ������ ������
template <typename T>
void freeMem(TNode<T>* tree) {
    if (tree != nullptr) {
        freeMem(tree->left);
        freeMem(tree->right);
        delete tree;
    }
}

//�������� ������� ����������
template <typename T>
std::vector<T> Kochetov_TreeSort(std::vector<T> data) {
    TNode<T>* root = nullptr;
    for (const T& item : data) {
        root = addNode(root, item);
    }

    std::vector<T> sorted;
    inorder(root, sorted);

    freeMem(root);

    return sorted; 
}

// ����� ������������� ��� int 
template std::vector<int> Kochetov_TreeSort(std::vector<int> data);
template std::vector<double> Kochetov_TreeSort(std::vector<double> data);