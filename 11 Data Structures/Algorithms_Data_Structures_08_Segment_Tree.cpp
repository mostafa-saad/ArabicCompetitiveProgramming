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
 
Content:
- What is segment tree?
- segment tree vs interval tree
- contests version of segment tree
- When to apply it
- Practical Example

UVA(10909), SPOJ(BRCKTS, BYTESE2, GSS1, GSS3, GSS5, HELPR2D2, KGSS, POSTERS, RACETIME), TC(SRM310-1-2, SRM315-2-3, SRM404-1-2, SRM339-1-3)



/*
 * Segment tree data structure solves:
 * 		Given set of intervals (a-b). Then given set of queries, each query is a number, HOW many intervals contain the number?
 *
 * Segment tree ~= Interval Tree
 *
 * Interval tree data structure solves:
 * 		Given set of intervals (a-b). Then given set of queries, each query is an interval, HOW many intervals intersect the given interval?
 * 			If given interval has start = end, then it could solve what Segment tree
 *
 * Interval tree is extremely efficient in time/memory when moving to higher dimension
 *
 * Other related structures: range tree & fenwick(BIT) tree
 */























/* In fact, in programming competitions we typically work over a specific case of segment tree: The given intervals have start=end
 *
 * 		1) We assume we have a coordinate space on x-axis from [0 - N]
 * 		2) we are given set of numbers (order is not issue)	e.g.: 20 7 4 9 12		(actually, they are set of intervals [1-1], [7-7], ...)
 * 		3) Queries are as following
 * 			a) HOW many numbers are in given interval?
 * 				E.g In interval [1-3]  = 0	-> Notice, our first element is 4
 * 				E.g In interval [0-8]  = 2	-> 4, 7
 * 				E.g In interval [6-15] = 3	-> 7, 9, 12
 *
 *			b) Get Kth item in sorted list
 *				E.g. get(2) = 7		-> in sorted list 4 7 9 12 20
 *
 *			c) Remove kth item in sorted list
 *				E.g. remove(5) 		-> 4 7 9 12
 *
 *			b) Insert new element: so we update our list:
 *				E.g. insert(16)		-> 4 7 9 12 16 20
 */




























/*
 * The main point in these data structures is idea of PRE-PROCESSING before answering Queries.
 *
 * So how is segment tree constructed? Done as a BINARY tree, each item holds an interval, represents HOW many numbers are in this interval. Leaf nodes represents the main number.
 *
 * So to have N numbers as leaf, and want to go up layer by later till reach root as a binary tree, we need to go up logN level
 *
 * Assume we have N = 8, so above is 4, then 2, then 1. So a total number of nodes: 15 = 2^4 -1
 *
 * How to index them, given initial N values?
 * How to do the pre-processing?
 */









































const int MAX = 2000000;
int interval[4194304];	// 2^(Ceil(log2(MAX))+1

int S = 0, E = MAX;
// call build(0, MAX) to initialzie all cells to val = 1
int build(int s = S, int e = E, int p = 1) {	// O(nlogn)
	if(s == e)	return  interval[p] = 1;
	return interval[p] = build(s, (s+e)/2, 2*p) + build((s+e)/2+1, e, 2*p+1);
}


// insert num and return its order (kth in order)
int insert(int num, int s = S, int e = E, int p = 1) {	//O(logn)
	interval[p]++;
	if(s == e)	return interval[p];	// control here for repeated nums
	if(num <= (s+e)/2)
		return insert(num, s, (s+e)/2, 2*p);
	return interval[2*p] + insert(num, (s+e)/2+1, e, 2*p+1);
}


// delete kth element, and return its value
int delkTh(int kTh, int s = S, int e = E, int p = 1) {
	interval[p]--;
	if(s == e)	return s;
	if(interval[2*p] >= kTh)	return delkTh(kTh, s, (s+e)/2, 2*p);
	return delkTh(kTh-interval[2*p], (s+e)/2+1, e, 2*p+1);
}


// get value of kth element
int getkTh(int kTh, int s = S, int e = E, int p = 1) {
	if(s == e)	return s;
	if(interval[2*p] >= kTh)	return getkTh(kTh, s, (s+e)/2, 2*p);
	return getkTh(kTh-interval[2*p], (s+e)/2+1, e, 2*p+1);
}

int remove(int num, int s=S, int e=E, int p=1)
{	// return position of deleted val in O(logn)
	interval[p]--;
	if(s == e)	return interval[p]+1;

	if((s+e)/2 >= num)
		return remove(num, s, (s+e)/2, 2*p);
	return interval[2*p] + remove(num, (s+e)/2+1, e, 2*p+1);
}

void displayElements(int s=S, int e=E, int p=1)
{
	if(s < e) {
		displayElements(s, (s+e)/2, 2*p);
		displayElements((s+e)/2+1, e, 2*p+1);
	}
	if(s == e) {
		int cnt = interval[p];
		while(cnt--)	cout<<s<<" ";
	}
}














/*
 * The tree could be used in many cases..don't limit ur mind for number of elements
 * 		Think for a while: could it represent accumulation of numbers in a given range?
 *
 *
 * Remember, this data structure allows following:
 * 		Allows for updating list of numbers with insert / delete NUMBER
 * 		Allows to get the position of a value
 * 		Allows to get the value of the kth position
 *
 * 		So it is Dynamic array vs the basic static array
 *
 *
 * 	Whenever problem needs subset of these features, consider segment tree
 *
 * 	Let's see an example
 */
















