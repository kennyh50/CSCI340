/***********************************************************
CSCI 340 - Assignment 1 - Spring 2019

Progammer: Kenneth Harris


Purpose: This program generates random unique numbers.  Afterwards
it selects 100 random numbers to be searched.  A linear search 
and binary search are performed.  The vector is sorted and the 
linear and binary search are performed again.  After each sort
the average number of comparisons are displayed.
************************************************************/ 

#include <algorithm>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;
const int NO_ITEMS = 8;
const int ITEM_W = 4;

/***************************************************************
linear_search
Use: performs a linear search through the vector
Parameters: 1.const vector<int>& inputVec
            2. const int x
	    3. int& comparisons
Returns: True if the iterator matches the number that is searched for,
otherwise it returns false.
***************************************************************/
int linear_search(const vector<int>& inputVec, const int x, int& comparisons) {

vector<int>::const_iterator i;
comparisons = 0;

    for(i = inputVec.begin(); i != inputVec.end(); i++)
    {
	    comparisons++;
	    if(*i == x)
	    {
		return true;
	    }

	}
	    return false;
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
int binary_search(const vector<int>& inputVec, const int x, int& comparisons) {

comparisons = 0;
int left = 0, right = inputVec.size() - 1, mid = ((left + right) /2);

    while(left <= right)
    {

	if(x == inputVec[mid])
	{
		return true;
	}

	if(x < inputVec[mid])
	{
		right = mid - 1;
	}

	else{
		left = mid + 1;

	}
		mid = ((right + left)/2);
		comparisons++;

    }

	return false;
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

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

    int random_number() {

   return rand()%DATA_RANGE + 1;
}


int main () {

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl;
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}
