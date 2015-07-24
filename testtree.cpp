// File:        stocksystem.cpp

#include <iostream>
#include <cstdlib>
#include <string>

#include "redblacktree.h"

using namespace std;

int main()
{
    RedBlackTree<int>* tree = new RedBlackTree<int>();
    tree->Insert(41);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(32);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(71);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(65);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(51);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(87);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(82);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Insert(93);
    cout << "root " << tree->GetRoot()->data << endl;

    /*
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Remove(51);
    cout << "root " << tree->GetRoot()->data << endl;
    tree->Remove(32);
    cout << "root " << tree->GetRoot()->data << endl;
*/
    RedBlackTree<int>* copytree = new RedBlackTree<int>(*tree);
}
