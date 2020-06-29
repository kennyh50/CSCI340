/***********************************************************
CSCI 340 - Assignment 6 - Spring 2019

Progammer: Kenneth Harris

Purpose: Implement functions of a binary search tree.
************************************************************/

////////////////////////////////////////////
// Assignment 6 driver program -- build BST with random numbers
//              and test search operations
////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

static const int MAX_COUNT = 20;
static int mcount = 0;

void display2(int d) {
    if ( mcount < MAX_COUNT ) {
        cout <<  setw(4) << d;
        mcount++;
    }
}

// produce a random number within range [1 1000]
int rand_1000() {
    return rand() % 1000 + 1;
}

void show_tree_information( BST& bst ) {
    cout << "Size of the tree: " << bst.size() << endl;
    cout << "Height of the tree: " << bst.height() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = 0;
    bst.inorder( display2 );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = 0;
    bst.preorder( display2 );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = 0;
    bst.postorder( display2 );
}

// For each value in searchVec, search it in the binary search tree
// and report the number of successful searches
void run_search( BST& bst, vector<int>& searchVec ) {
    int success = 0;
    vector<int>::iterator it;
    for ( it = searchVec.begin(); it != searchVec.end(); it++ )
        if ( bst.search( *it ) )
            success++;
    cout << endl << endl << "Out of " << searchVec.size() << " searches, " << success << " are successful." << endl << endl;
}

int main() {
    //-------------- Create a B.S.T. using unique random numbers -----------
    vector<int> inputVec(1000);
    srand(7);
    generate(inputVec.begin(), inputVec.end(), rand_1000);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    BST bst;
    for (it=inputVec.begin(); it!=inputVec.end(); it++)
        bst.insert( *it );
    cout << "A binary search tree is generated with random numbers: " << endl;
    show_tree_information( bst );

    //-------------- Create a vector of random integers to be searched ------
    vector<int> searchVec(500);
    srand(11);
    generate( searchVec.begin(), searchVec.end(), rand_1000 );

    cout << endl << endl << "Sum of leaves: " << bst.sumLeaves() << endl;

    //------------ test search operations ----------------
    run_search( bst, searchVec );

    //------------ remove half of nodes from the tree ---------
    int counter = 0;
    random_shuffle( inputVec.begin(), inputVec.end() );
    for ( it = inputVec.begin(); it < inputVec.end(); it += 2 ) {
        if ( bst.remove( *it ) )
            counter++;
    }
    cout << endl << counter << " nodes are removed." << endl << endl;
    show_tree_information( bst );

    cout << endl << endl << "Sum of leaves: " << bst.sumLeaves() << endl;

    //-------------- test search operations again ---------------
    run_search( bst, searchVec );

    return 0;
}

/**************************************************************
insert
Use: insert the integer into the empty node.
Parameters: 1. Node*& r
            2. int x

Returns: nothing
**************************************************************/
void BST::insert( Node*& n, int x){

    if(n == NULL)
        n = new Node(x);

    else{

        if(n -> value > x){
            insert(n -> left, x);
        }

        else{
            insert(n -> right, x);
        }
    }

}

/**************************************************************
bool
Use:
Parameters: 1. Node*& n
            2. int x

Returns: boolean value
**************************************************************/
bool BST::search( Node*& n, int x){

    if(n != NULL){

        if(n -> value == x){
            return true;
        }

        if(n -> value > x){
           return search(n -> left, x);
        }

        else{
            return search(n -> right, x);
        }

    }

    else
        return false;
}

/**************************************************************
remove
Use: removes node.
Parameters: 1. Node*& n
            2. int x

Returns: boolean value
**************************************************************/
bool BST::remove( Node*& n, int x){

    if(n == NULL){

        return false;
    }

    if(n -> value > x){

        return remove(n -> left, x);
    }

    else if(n -> value < x){

        return remove(n -> right, x);

    }

    else if(n -> left != NULL && n -> right != NULL){

        Node* pred = predecessor(n);

        n -> value = pred -> value;
        return remove(n -> left, pred -> value);
    }

    else if(n -> left == NULL && n -> right == NULL){

        delete n;
        n = NULL;
        return true;
    }

    else if(n -> left == NULL){

        Node* temp = n;
        n = n -> right;
        delete temp;
        return true;
    }

    else {

        Node* temp = n;
        n = n -> left;
        delete temp;
        return true;
    }
}

/**************************************************************
sumLeaves
Use: Finds the sum of all the leaves.
Parameters: 1. Node*& n

Returns: integer
**************************************************************/
int BST::sumLeaves( Node*& n){

    if(n == NULL){

        return 0;
    }

    else if(n -> left != NULL || n -> right){

        return( sumLeaves(n -> left) + sumLeaves(n -> right));
    }
    else {

        return n -> value;
    }
}

void BST::insert(int x){

    insert(root, x);
}

bool BST::search(int x){

    return search(root, x);
}

bool BST::remove(int x){

    return remove(root, x);
}

int BST::sumLeaves(){

    return sumLeaves(root);
}

Node* BST::predecessor( Node*& n){

    Node* pred;

    if( n -> left){

        pred = n -> left;

        while(pred -> right){

            pred = n -> right;
        }
    }

    return pred;
}

