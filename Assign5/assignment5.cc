/***********************************************************
CSCI 340 - Assignment 5 - Spring 2019

Progammer: Kenneth Harris

Purpose: Implement functions of a binary tree.
************************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;


void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

/*#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
**/

/**************************************************************
insert
Use: insert the integer into the empty node.
Parameters: 1. Node*& r
	    2. int x

Returns: nothing
**************************************************************/
void binTree::insert( Node*& r, int x){

    if(r == NULL){

	r = new Node(x);

    }


       else{

	     if(height(r -> left) > height(r -> right)){

                insert(r -> right,x);
            }

	    else{
	    	insert(r -> left, x);
	    }
	}

}

/**************************************************************
height
Use: Returns the height of the tree.
Parameters: Node* r

Returns: maximum height
**************************************************************/
int binTree::height( Node* r) const{

    if(r == NULL){
	return -1;
    }

    else{
	return max(height(r -> left), height(r -> left)) + 1;
    }
}

/**************************************************************
size
Use: Returns the size of the tree.
Parameters: Node* r

Returns: Returns -1 if root is empty otherwise returns the size
of the tree.
**************************************************************/
unsigned binTree::size( Node* r) const{

    if(r == NULL){
	return -1;
    }

    else{
	return size(r -> left) + size(r -> right) + 1;
    }
}

/**************************************************************
inorder
Use: Goes through the tree using the inorder process
Parameters: Node* r, void(* p)(int)

Returns: Nothing
**************************************************************/
void binTree::inorder( Node* r, void(* p)(int) ){

    if(r != NULL){
	inorder(r -> left, p);
	p(r -> value);

	inorder(r -> right, p);

    }

}

/**************************************************************
preorder
Use: Goes through the tree using the preorder process
Parameters: Node* r, void(* p)(int)

Returns: Nothing
**************************************************************/
void binTree::preorder( Node* r, void(* p)(int) ){

    if(r != NULL){

	p(r -> value);

	preorder(r -> left, p);
	preorder(r -> right, p);
    }
}

/**************************************************************
postorder
Use: Goes through the tree using the postorder process
Parameters: Node* r, void(* p)(int)

Returns: Nothing
**************************************************************/
void binTree::postorder( Node* r, void(* p)(int) ){

    if(r != NULL){

	postorder(r -> left, p);
	postorder(r -> right, p);

	p(r -> value);

    }

}

binTree::binTree(){

root = NULL;

}

void binTree::insert(int x){

	insert(root, x);
}

int binTree::height() const{

	return height(root);
}

unsigned binTree::size() const{

	return size(root);
}

void binTree::inorder(void(* p)(int)){

	inorder(root, p);
}

void binTree::preorder(void(* p)(int)){

	preorder(root, p);
}

void binTree::postorder(void(* p)(int)){

	postorder(root, p);
}
