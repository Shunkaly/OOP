// Tree.cpp 

#include <iostream>
#include "BinTree.h"

int main()
{
    //int* arr = new int[5] {1, 4, 3,5,8};
    //BinTree<int> lol(arr, 5);
    //lol.print(lol.getRoot());
    int* arr = new int[4] {1, 2, 4 ,6};
    BinTree<int> tree(arr, 4);
    tree.print(tree.getRoot());
    cout << "jfgdhsj" << endl;
}
