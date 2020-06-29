/***********************************************************
CSCI 340 - Assignment 5 - Spring 2019

Progammer: Kenneth Harris
Z-ID: z1733721
Section: 1
Date Due: March 8, 2019
Purpose: Header file.
************************************************************/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node{

    public:

	Node(int v, Node* l = nullptr, Node* r = nullptr){
		left = l;
		right = r;
		value = v;
	}

    private:

	int value;
	Node* left;
	Node* right;
	friend class binTree;
	friend class BST;
};

class binTree{

    public:

	binTree ( ); // default constructor
	int height ( ) const; // returns height of tree
	unsigned size () const; // return size of tree
	virtual void insert ( int ); // inserts a node in tree
	void inorder( void(*)(int) ); // inorder traversal of tree
	void preorder( void(*)(int) ); // preorder traversal
	void postorder( void(*)(int) ); // postorder traversal


    protected:

	Node* root; // root of tree

    private:

	int height(Node*) const; // private version of height()
	unsigned size(Node*) const; // private version of size()
	void insert (Node*&, int); // private version of insert()
	void inorder( Node*, void(*)(int) ); // private version of inorder()
	void preorder( Node*, void(*)(int) ); // private version of preorder()
	void postorder( Node*, void(*)(int));// private version of postorder()

};

#endif

