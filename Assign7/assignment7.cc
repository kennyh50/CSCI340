/***********************************************************
CSCI 340 - Assignment 7 - Spring 2019

Progammer: Kenneth Harris
Z-ID: z1733721
Section: 1
Purpose:
************************************************************/
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

const int HEAP_SIZE = 50;

void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) );
bool less_than ( int e1, int e2 );
bool greater_than ( int e1, int e2 );
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) );
void print_vector ( vector < int >& v, int pos, int size );

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}

/**************************************************************
build_heap
Use:
Parameters: 1. vector<int>& v
            2. int heap_size
            3. bool (*compar)(int, int)

Returns: nothing
**************************************************************/
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) ){
    for(int loc = heap_size/2; loc > 0; loc--){

	heapify(v, heap_size, loc, compar);
    }
}


/**************************************************************
heapify
Use:
Parameters: 1. vecotr<int>& v
            2. int heap_size
	    3. int r
	    4. bool (*compar)(int, int)

Returns: nothing
**************************************************************/
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) ){

    int left = (2*r);
    int right = (2*r) + 1;
    int pos;

    if(left <= heap_size && compar(v[left], v[r])){
	pos = left;
    }

    else
	pos  = r;

    if(right <= heap_size && compar(v[right], v[pos])){
	pos = right;
    }

    if(pos != r){
	int temp = v[pos];
	v[pos] = v[r];
	v[r] = temp;
	heapify(v, heap_size, pos, compar);
    }
}


/**************************************************************
less_than
Use: If true is returned then the heap is a min heap.
Parameters: 1. int e1
            2. int e2

Returns: boolean value
**************************************************************/
bool less_than ( int e1, int e2 ){

    if(e1 < e2){
	return true;
    }

    else
	return false;
}


/**************************************************************
greater_than
Use: If true is returned then the heap is a max heap.
Parameters: 1. int e1
            2. int e2

Returns: boolean value
**************************************************************/
bool greater_than ( int e1, int e2 ){

    if(e1 > e2){
        return true;
    }

    else
        return false;

}



/**************************************************************
heap_sort
Use:
Parameters: 1. vector<int>& v
            2. int heap_size
	    3. bool (*compar)(int, int)

Returns: nothing
**************************************************************/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) ){
    while( heap_size > 1){
	extract_heap(v, heap_size, compar);
    }

    reverse(v.begin() + 1, v.end());
}

/**************************************************************
extract_heap
Use:
Parameters: 1. vector<int>* v
            2. int& heap_size
	    3. bool (*compar)(int,int)

Returns: integer
**************************************************************/
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) ){

    int oldRoot = v[1];
    v[1] = v[heap_size];
    heap_size--;
    heapify(v, heap_size, 1, compar);

    return oldRoot;

}

/**************************************************************
pirnt_vector
Use:
Parameters: 1. vector<int>& v
            2. int pos
	    3. int size

Returns: nothing
**************************************************************/
void print_vector ( vector < int >& v, int pos, int size ){

    for( int i = pos; i <= size; i++){
	cout << setw(5) << right << v[i];

	if(i % 8 == 0){
	    cout << endl;
	}
    }

    cout << endl;
}
