/***********************************************************
CSCI 340 - Assignment 2 - Spring 2019

Progammer: Kenneth Harris
Z-ID: z1733721
Section: 1
Date Due: February 6, 2019
Purpose: The purpose of the application is to show the difference
between the linear search and binary sort when searching throught
unsorted and sorted data.
************************************************************/ 

#include <algorithm>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;
const int LOW = 1;
const int HIGH = 100;
const int NO_ITEMS = 10;
const int ITEM_W = 6;

/***************************************************************
void genRndNums
Use: Generates random numbers for the linear and binary searches.
Parameters: 1.vector<int>& v
            2. int seed

Returns: Nothing
***************************************************************/
void genRndNums( vector<int>& v, int seed ) {

    srand(seed);
    vector<int>::iterator i;

    for(i = v.begin(); i != v.end(); i++){
	*i = rand() % HIGH - LOW + LOW;
    }

}

/***************************************************************
linear_search
Use: performs a linear search through the vector
Parameters: 1.const vector<int>& inputVec
            2. const int x
            3. int& comparisons
Returns: True if the iterator matches the number that is searched for,
otherwise it returns false.
***************************************************************/
bool linearSearch( const vector<int>& inputVec, int x) {

	vector<int>::const_iterator it;

	it = find(inputVec.begin(), inputVec.end(), x);

	if(it == inputVec.end()){
		return false;
	}

		return true;
}

/***************************************************************
binary_search
Use: Performs a binary search throught the vector
Parameters: 1.const vector<int>& inputVec
            2.const int x
            3. int& comparisons
Returns:  Returns true if the desired value is equal to the middle number,
        otherwise false is returned.
***************************************************************/
bool binarySearch( const vector<int>& inputVec, int x) {

	if(binary_search(inputVec.begin(), inputVec.end(), x)){

		return true;
	}


	else

		return false;
}


/***************************************************************
int search
Use:Generic search algorithm that computes the total number of 
successful searches.
Parameters: 1.const vector<int>& inputVec
            2. const vector<int>& searchVec
	    3. bool*p
	    4. const vector<int>&,
	    5. int

Returns: Total number of successful searches.
***************************************************************/
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){

	vector<int>::const_iterator i;
	int successCount = 0;

	for(i = searchVec.begin(); i != searchVec.end(); i++){

		if(p(inputVec, *i))

			successCount++;

	}

	return successCount;
}

/*************************************************************
sortVector
Use: Sorts the elements inside of the vector.
Parameters: vector<int>& inputVec

Returns: nothing
*************************************************************/
void sortVector (vector<int>& inputVec) {

	sort(inputVec.begin(), inputVec.end());

}

/**************************************************************
pritnStat
Use: Prints out the number of successful searches.
Parameters: 1. int totalSucCnt
	    2. int vec_size

Returns: Nothing
**************************************************************/
void printStat (int totalSucCnt, int vec_size) {

	float percent = ((float)totalSucCnt/ (float)vec_size) * 100;

		cout << fixed << setprecision(2);
		cout << endl;
		cout << "Successful searches: " << percent << "%";
		cout << endl;

}

/***************************************************************
print_vec
Use: Prints out all of the numbers in the vector.
Parameters: 1. const vector<int>& vec

Returns: nothing
***************************************************************/
void print_vec( const vector<int>& vec ){

vector<int>::const_iterator i;
int number = 0;

        for(i = vec.begin(); i != vec.end(); i++){
            if(number != 0 && number % NO_ITEMS == 0)
            cout << endl;
            cout << setw(ITEM_W) << right << *i;

        number++;
        }

}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << endl << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}


