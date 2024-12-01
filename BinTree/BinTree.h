#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct TreeNode {
	T value;
	TreeNode<T>* left;
	TreeNode<T>* right;

	TreeNode(T value, TreeNode<T>* lest, TreeNode<T>* right) : value(value), left(left), right(right) {};
};
template<typename T>
class BinTree
{
	TreeNode<T>* root;
	void clearMemory(TreeNode<T>* root);
public:
	BinTree(T* arr, int size);
	void insert(T val, TreeNode<T>* root);
	void remove(TreeNode<T>**, T);
	TreeNode<T>* find(T value, TreeNode<T>* root);
	void print(TreeNode<T>* root);
	TreeNode<T>* getRoot();
	~BinTree();
};

template<typename T>
inline void BinTree<T>::clearMemory(TreeNode<T>* root)
{
	if (root == nullptr) {
		return;
	}
	clearMemory(root->right);
	clearMemory(root->left);
	delete root;
}

template<typename T>
inline BinTree<T>::BinTree(T* arr, int size)
{
	/*for (int i = 1; i < size;i++) {
		if (arr[1] <= arr[0]) {
			arr[1]



		}

	}*/
	/*TreeNode<T>* newNode = new Node();
	newNode->value = value;
	newNode->left = newNode->right = nullptr;
	return newNode;*/
	this->root = new TreeNode<T>(arr[0], nullptr, nullptr);
	for (int i = 1; i < size; i++) {
		insert(arr[i], this->root);
	}
}

template<typename T>
inline void BinTree<T>::insert(T val, TreeNode<T>* root)
{
	if (val > root->value) {
		if (root->right == nullptr) {
			root->right = new TreeNode<T>(val, nullptr, nullptr);
			return;
		}
		return insert(val, root->right);
	}
	else {
		if (root->left == nullptr) {
			root->left = new TreeNode<T>(val, nullptr, nullptr);
			return;
		}
		return insert(val, root->left);
	}
}

template<typename T>
inline void BinTree<T>::remove(TreeNode<T>** rootPtr, T value)
{
		TreeNode<T>* root = *rootPtr; 
		if (root == nullptr) {
			return;
		}

		if (value < root->value) {
			remove(&root->left, value); 
		}
		else if (value > root->value) {
			remove(&root->right, value);
		}
		else {
				if (root->left == nullptr) {
					TreeNode<T>* node = root->right;
					delete(root); 
					*rootPtr =node; 				}
				else if (root->right == nullptr) {
					TreeNode<T>*node = root->left;
					free(root);
					*rootPtr = node; 
				}
				else {
					TreeNode<T>* node = nullptr;
					while (node->left != nullptr) {
						node = node->left;
					}
					
					root->value = node->value; 
					remove(&root->right, node->value); 
				}
		}	
}



template<typename T>
inline TreeNode<T>* BinTree<T>::find(T value,TreeNode<T>* root)
{
	if (value == root->value) { return root; }
	else if (value > root->value) {
		find(value, root->right);
	}
	else {
		find(value, root->left);
	}
}

template<typename T>
inline void BinTree<T>::print(TreeNode<T>* root)
{
	if (root == nullptr) {
		return;
	}
	cout << root->value << " " << endl;
	print(root->right);
	print(root->left);
}

template<typename T>
inline TreeNode<T>* BinTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
inline BinTree<T>::~BinTree()
{
	clearMemory(this->root);
}

