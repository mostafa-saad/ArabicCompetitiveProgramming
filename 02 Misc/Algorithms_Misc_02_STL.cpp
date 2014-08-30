/*
 *
 *
 ******************************************** Licence *******************************************
 * 																								*
 * This File is part of Algorithms Arabic Video Series											*
 *	Made By Eng Mostafa Saad, Teaching Assistant in FCI - Cairo University						*
 * 																								*
 *	Available at My YouTube Channel: http://www.youtube.com/user/nobody123497?feature=mhee		*
 * 																								*
 * Feel free to make use of it at anytime, for any reason, in anyway, without any obligations.	*
 * 																								*
 * 																								*
 * In case of finding a mistake, kindly notify me at: mostafa.saad.fci@gmail.com				*
 * 																								*
 * Mostafa Saad Ibrahim © 2013																	*
 * 																								*
 ************************************************************************************************
 *
 *
 */
 
/*
Session 10: STL

Content
Vector Basic Operations
Algorithms on Vector
Queue \ Deque \ Priority Queue \ Stack
Pair \ Set \ Map
String
StringStream
valarray

//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=standardTemplateLibrary
//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=standardTemplateLibrary2
//www.cplusplus.com/reference

*/

#include <functional>
#include <utility>
#include <numeric>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<valarray>
using namespace std;











const int MAX = 100;
int in[MAX];
void printLine(string sub = ""){
	for (int i = 0; i < 50; ++i) {
		cout<<"*";
	}
	cout<<sub;
	for (int i = 0; i < 50; ++i) {
		cout<<"*";
	}
	cout<<"\n";
}

void printVec(vector<int> v2, string s = "")
{
	cout<<s;
	for (int i = 0; i < (int)v2.size(); ++i)
			cout<<v2[i]<<" ";
		cout<<"\n";
}

template<class T>
void printValArray(valarray<T> v2, string s = "")
{
	cout<<s;
	for (int i = 0; i < (int)v2.size(); ++i)
			cout<<v2[i]<<" ";
		cout<<"\n";
}




















#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))

typedef vector<int> vi;

// See different top coders header section

















// if your function is not a CORRECT less than operator <  , RTE probably will happen on a big test case.
// if a < b, then b < a = false
// a and b are considered equivalent if (!(a<b) && !(b<a))

bool sortPairsCmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first * b.second < a.second * b.second;
}




bool isOdd(int n)	{	return n%2 != 0;	}





void vectorBasicTest()
{
	vi v(10);	 							// Initialize 10 elements with zero
	vi v1(10, 7);							// Initialize 10 elements with 7

	// What about vector from array
	const int lenght = 6;
	int array[lenght] = {5, 2, 7, 2, 0, 2};
	vi v2(array, array+lenght);

	printVec(v2, "v2: ");

	cout<<"Front: "<<v2.front()<<" last element: "<<v2.back()<<"\n";

	swap(v2.front(), v2.back());	// back is by reference
	printVec(v2, "swap: ");

	// Vector from Vector
	vi v3(v1.begin(), v1.end());

	v.resize(15);	// resize array from 10 to 15 - if you know size, better use it
	// what happens if we used push back? a 16 element is added

	// What about iterating on vector, Either as in array or using iterators
	for (int i = 0; i < (int)v2.size(); ++i)	// watch out: v.size() return unsigned. Return v.size()-1 may cause problems. Cast to int
		cout<<v2[i]<<" ";
	cout<<"\n";

	// Another way:
	vi::iterator it = v2.begin();
	while(it != v2.end())
	{
		cout<<(*it)<<" ";		// * works so similar to pointers.
		++it;					// Move to next time
	}
	cout<<"\n";


	// Sorting the vector
	sort(v2.begin(), v2.end());		// what if sorting all elements, except 1st 2: 	sort(v2.begin()+2, v2.end());

	printVec(v2, "sorted: ");

	// Sorting decreasing
	sort(v2.begin(), v2.end(), greater<int>());	// let greater first
	sort(v2.rbegin(), v2.rend());

	printVec(v2, "sorted reversed: ");

	// Creating 2D vector of boolean
	vector< vector<bool> > vbs(10, vector<bool>(20, true));	// create array 10 * 20 filled with trues

	// Comparing 2 vectors
	if(v1 < v2)	// same <=, ==, >
		cout<<"v1 Smaller than v2\n";
	else
		cout<<"v2 Smaller than v1\n";

	// Removing 2rd element
	v2.erase(v2.begin()+1);				// O(n)
	printVec(v2, "erase 2th: ");

	v2.insert(v2.begin()+3, 14);		// O(n)
	printVec(v2, "insert 14 in 4th location: ");

	v2.push_back(20);
	printVec(v2, "add 20 in back: ");	// O(1)


	// Check if element in array

	if (find(all(v2), 7) != v2.end())	// find is O(n)
		cout<<"7 in v2\n";

	if (find(all(v2), 9) == v2.end())
		cout<<"9 is not in v2\n";

	// Removing value 7. If element not found, you can't call. Please check first
	v2.erase( find(all(v2), 7) );
	printVec(v2, "after erasing 7 using find: ");

	reverse( all(v2) );
	printVec(v2, "Reversed vector: ");

	random_shuffle(all(v2));		// shuffle randomly array numbers
	printVec(v2, "Shuffled vector: ");

	v2.pop_back();	// remove last in O(1)
	printVec(v2, "Last removed: ");

	v2.clear();
	printVec(v2, "Cleared vector: ");
}






bool isEqual(int a, int b) { return abs(a-b) < 2;	}	// consider

// In fact lots of here, applicable to any thing has iterators (e.g. strings)
void vectorManipulation()
{
	const int lenght = 10;
	int array[lenght] = {4, 2, 3, 2, 9, 2, 17, 17, 17, 20};
	vi v2(array, array+lenght);
	vi v1(v2.begin()+2, v2.begin()+5);

	printVec(v2, "V2: ");

	// Distance between 2 iterators = Equal to subtracting their iterators: E.g. it2 - it1	(where it2 is bigger)
	cout<<"distance: "<<distance(v2.begin(), v2.begin()+3)<<"\n";
	cout<<"distance: "<<distance(v2.begin()+4, v2.begin())<<"\n";

	vector<int>::iterator it;

	vector<int> v3 = v2;	// copy
	replace(all(v3), 2, 7);
	printVec(v3, "V3: ");

	replace_if(all(v3), isOdd, 15);
	printVec(v3, "V3: ");

	//search for 3 consecutive elements with value 20
	it = search_n(all(v2), 3, 17);

	if(it != v2.end())
		cout<<"3 Consecutive 17s from index: "<<it-v2.begin()<<"\n";

	it = search(all(v2), all(v1));			// search for vec
	if(it != v2.end())
		cout<<"sub-vector from index: "<<it-v2.begin()<<"\n";

	// unique/binary_search/lower_bound/upper_bound must applied on 	SORTED 		array.
	sort( all(v2) );
	printVec(v2, "Sorted ");

	bool ans = binary_search(all(v2), 17);	//v2 must be sorted first - O(logn)
	cout<<"Searching for 17: "<<ans<<"\n";

	//Finds the first element greater than or equal to a given value
	it = lower_bound(all(v2), 17);

	if(it != v2.end())
		cout<<"First element >= 17 "<<*it<<"\n";

	//Finds the first element greater than a given value
	it = upper_bound(all(v2), 17);
	if(it != v2.end())
		cout<<"First element > 17 "<<*it<<"\n";

	// return iterator to last element of unique sorted array.
	v2.resize(unique( all(v2) ) - v2.begin());
	printVec(v2, "Removing duplicates: ");

	// set_intersection/set_difference/set_union/set_symmetric_difference  must applied on 	SORTED 		array.
	v1 = v2;
	v1.push_back(v1.back());
	v1.push_back(v1.back()+20);
	v1.push_back(v1.back()+7);
	printVec(v1, "V1: ");
	vector<int> v;

	set_intersection(all(v1), all(v2), back_inserter(v));
	printVec(v, "set_intersection: ");

	v.clear();
	set_difference(all(v1), all(v2), back_inserter(v));
	printVec(v, "set_difference: ");	// what happens if v1 is proper subset of v2? v is empty

	v.clear();
	set_union(all(v1), all(v2), back_inserter(v));
	printVec(v, "set_union: ");

	/////////////////////////////////////////////////////////////////////////////////

	int mx = *max_element(v2.begin(), v2.end());
	int mn = *min_element(v2.begin(), v2.end());

	cout<<"Maximum: "<<mx<<" minimum "<<mn<<"\n";
	printVec(v1, "v1: ");
	printVec(v2, "v2: ");

	swap_ranges(v2.end()-2, v2.end(), v1.begin() );	// you could swap from different vectors

	printVec(v2, "Range swaps ");


	v2.clear();
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(4);
	printVec(v2, "New v2: ");

	int vecSum = accumulate(all(v2), 0); 						// return array SUM
	int vecMul = accumulate(all(v2), 1, multiplies<int>()); 	// return array product

	int sumOfProducts1 = inner_product(all(v2), v2.begin(), 0);			 						// inner product: V1[0] * V1[0] + V2[0]*v2[0]...
	int sumOfProducts2 = inner_product(all(v2), v2.begin(), 0, plus<int>(), multiplies<int>()); // same as above
	int productsOfSum = inner_product(all(v2), v2.begin(), 1, multiplies<int>(), plus<int>()); // 1 * (V1[0] + V1[0]) * (V2[0] + v2[0])
	// 0, 1, 0 are the initial value for accumulation

	cout<<"vecSum: "<<vecSum<<" vecMul: "<<vecMul<<" sumOfProducts: "<<sumOfProducts1<<" productsOfSum:"<<productsOfSum<<"\n";

	v1.clear();
	partial_sum(all(v2), back_inserter(v1));
	printVec(v1, "Accumulative array: ");

	v1.clear();
	partial_sum(all(v2), back_inserter(v1), minus<int>());
	printVec(v1, "Subtracting array: ");

	// writing to a stream
	ostringstream oss1;
	partial_sum ( all(v2), ostream_iterator<int>(oss1," "));
	cout<<"Accumulative array in string: "<<oss1.str()<<"\n";			// 27 68 149 the partial accumulatation

	adjacent_difference(all(v2), v1.begin());
	printVec(v1, "adjacent_difference ");

	adjacent_difference (all(v2), v1.begin() , plus <int>());
	printVec(v1, "adjacent_sum ");

	it = adjacent_find(all(v2), isEqual);	//find first 2 adjacent elements who are EQUAL based on equal function
	if(it != v2.end())
		cout<<"The 2 adjacent values are: "<<*it<<" "<<*(it+1)<<"\n";

	v2.insert(v2.begin(), 6);
	v2.insert(v2.begin()+3, 6);
	v2.push_back(6);

	printVec(v2, "V2: ");

	cout<<"Count of 6: "<<count(all(v2), 6)<<"\n";
	count_if (all(v2), isOdd);	// isOdd is a function called for each element in v2

	v2.erase(	remove(all(v2), 6)	, v2.end());	// remove all 6, and preserve order
	printVec(v2, "Remove 6s: ");

	rotate(v2.begin(), v2.begin()+1, v2.end()); 	//rotate Direction <--
	printVec(v2);

	//In case listing all next_permutation, you must SORT input first
	sort( all(v2) );
	do {
		printVec(v2, "Perm: ");
	} while(next_permutation(all(v2)));	// permutate on any given iterator with compare function
}




void QueueStackBasicTest()
{
	queue<int> q;
	q.push(20);
	q.push(10);
	q.push(30);

	cout<<"Last element in Queue: "<<q.back()<<"\n";
	cout<<"Queue elements: ";
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";

	deque<int> dq;		// double-ended queue
	dq.push_back(20);
	dq.push_front(10);

	// Order elements, larger first
	priority_queue<int> pq;
	// priority_queue<int, cmp> pq;	// pass cmp to sort them
	pq.push(20);
	pq.push(10);
	pq.push(30);

	cout<<"Priority Queue elements: ";
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<"\n";


	stack<int> s;
	s.push(20);
	s.push(10);
	s.push(30);

	cout<<"Stack elements: ";
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";

}




void SetAndPairAndMapBasicTest()
{
	// Pair
	pair<int, char> p1 = make_pair(10, 'z');
	pair<string, pair<int, char> > p2 = make_pair("mostafa", p1);

	cout<<p2.first<<"\n";
	cout<<p2.second.first<<"\n";
	cout<<p2.second.second<<"\n";


	// Rule: any algorithm / data structure that need to compare data, e.g. sort
	// will use basic data types to compare (e.g. 3 < 5), or you provide a comparator / compare function

	vector< pair<int, int> > vp;
	vp.push_back( make_pair(1, 2) );
	vp.push_back( make_pair(4, 4) );
	sort( all(vp), sortPairsCmp);

	////////////////////////////////////////////

	set<string> strSet;
	strSet.insert("mostafa");
	strSet.insert("ali");

	if(strSet.count("mostafa"))
		cout<<"Mostafa is in Set\n";

	set<string>::iterator strIt = strSet.lower_bound("mostafa");
	strIt = strSet.find("mostafa");

	//replace(all(strSet), "mostafa", "hani");	// In maps and sets, don't try intermediate playing. They are based on keys.

	map<string, int> mp;
	mp["Mostafa"] = 10;
	mp["Saad"] = 20;

	// You could iterate on map and set normally like vector. Never to change keys while iterating

	// Another way, convert map to vector of pair: key, value
	vector< pair<string, int> > mptov( all(mp) );

	for (int i = 0; i < (int)mptov.size(); ++i)
		cout<<mptov[i].first<<" "<<mptov[i].second<<"\n";

	// Map and set are logn
	// multiset & multimap same but allows keys repetition
}

/////////////////////////////////
int toInt(string str) {
	int num;
	istringstream iss(str);
	iss>>num; return num;
}

template <class T> string toStr(T par) {
	ostringstream oss;
	oss<<par;
	return oss.str();
}

bool startsWith(string str, string pat) {
	return (int)str.find(pat) == 0;
}

bool endsWith(string str, string pat) {
	int pos = str.rfind(pat);
	return pos != -1 && pos+sz(pat) == sz(str);
}


void stringBasicTest() {

	string str2("initial2");
	string test  = "hi abc abc abc abc";

	cout<<test.substr(3)			<<"\n";		// abc abc abc abc
	cout<<test.substr(3, 5)		<<"\n";			// abc

	cout<<"Mostafa at: "<<test.find("Mostafa")<<"\n";
	cout<<"Mostafa at: "<<(int)test.find("Mostafa")<<"\n";

	cout<<test.find("abc", 5)		<<"\n";	// starting the search at 6th character

	//Functions that searches for a CHARACTER from a given string
	cout<<test.find_last_of("cab")  <<"\n";
	cout<<test.find_first_of("aic") <<"\n";
	cout<<test.find_first_of("aic", 4) <<"\n";
	cout<<test.find_first_of("aic", 4, 6) <<"\n";
	cout<<test.find_first_not_of("aic") <<"\n";

	test.replace(4, 3, "x");		// replace from 4, 3 chars with x

	char array[4] = {'a', 'b', 'c', 'd'};
	string t = array;		//Converts character array into string.
	const char* s = t.c_str();		//Converts character array into string.

	test.erase(4);					//Remove from position 4 to END of string.
	cout<<"String "<<test<<"\n";
	test.erase(4, 6);				//Removes 6 chars starting in position 4

	/////////////////////////////////////////////////
	cout<<toStr(32)<<"\n";

	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(7);

	ostringstream oss;
	copy (all(v), ostream_iterator<int>(oss, ","));	// convert vector to string
	cout<<oss.str()<<"\n";

	istringstream iss("10 20 30");	// helps much in reparsing input blocks
	int x;
	while(iss>>x)	// same if cin stream
		cout<<"Readed X "<<x<<"\n";
}

void valarrayTest()	// If you want to manipulate lots of basic operations, but on group of numbers
{
	int val[] = {1, -2, 3, -4, -5};

	valarray<int> v1 (val, 5);	// NOT (val, val+5)

	valarray<int> v2 = abs (v1);

	cout<<v2.sum()<<"\n";

	valarray<int> v3 = 2 * (v1 + v2);
	printValArray(v3, "v3: ");


	valarray<bool> v4 = (v1 == v2);
	cout<<v4.min()<<" "<<v4.max()<<"\n";

	double arr[] = {0, 1, 2, 3};
	valarray<double> v5(arr, 4);

	valarray<double> v6 = 2.0 * (v5 + 3.0 * v5);	// 2.0 NOT 2 - same types used, not MIXED

	cout<<pow(2.0, v5).sum()<<"\n";	// 2^4 -1
	cout<<pow(v5, 2.0).sum()<<"\n";
	cout<<pow(2.5 * v5, v6).sum()<<"\n";
	//cout<<pow(v5, 2.5 * v6).sum()<<"\n";	// compile error

	// other interesting operations: slice_array,
}
