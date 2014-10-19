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

Content:
What is Branch and bound?
Valid State Representation
Valid State Branching
Valid State Bounding
- Tight Bound
- Not Tight Bound
Maximum sub-interval sum
- Invalid / Valid State
- Tight/Not Tight Bounding
- Code
Maximum sub-matrix sum

Problems: UVA(108, 10074)
*/











/*
 * Decrease and conquer algorithm
 * 		In this algorithm, we divide current state (e.g. array) to some parts, and pick ONLY one to conquer
 *
 * 		E.g. Binary search algorithm divides the interval equally, determine which part is the promising and conquer it
 *
 *
 * Divide and conquer algorithm
 * 		In this algorithm, we divide current state (e.g. array) to some parts, and conquer each one of them separately, then join answer
 *
 * 		E.g. Merge sort algorithm divides the array equally, sort each part separately, and then get full sorted array from sorted parts
 *
 *
 * 	What about Branch and bound algorithm?
 * 		Branch is same as Divide, we divide current state (e.g. array) to some parts
 *
 * 		bound, is a step we do before conquer. We simply give each state a number expressing how it is beneficial, and we conquer in order the best one
 *
 * 		notice that, the conquer deals with all states since we started the algorithm, not just the ones resulted from branching the state
 *
 * 		If problem is maximization, then we do upper bound estimate, and if it is minimization we do lower bound estimate
 */






























/*
 * 1) A valid State representation is IFF, its definition includes all possible sub-states that could be answers.
 *
 * 		Say answer is a tuple of binary n numbers.
 * 			One valid state could be array initialized to unknown.
 * 			Then any binary sub-state is included in this state
 */














/*
 * 2) A valid state branching IFF, the overall solutions of sub-states = the solutions included in the main state
 *
 * E.g. A dummy branching for the binary state may try to divide the tuple for 2 binary tuples (n-x) and x
 *
 * Or may pick one of unknowns and set it once for 0 and once for 1. Then the 2 sub-states are equal to main one
 */
















/*
 * 	3) A valid upper bound function is one gives correct indicator. E.g. Say, problem is maximization and we have a state (sub-array)
 * 		Say the correct max answer for this is 100
 * 			Then any valid upper function should estimate the state with value >= 100
 *
 * 		Same meaning for lower upper function.
 *
 * 	Theoretically, +OO is a valid upper bound function and -OO is a valid lower bound function
 *
 * 	Bound Design [FIX to video]
 * 		The degree of tightness is indicator for convergence speed.
 * 			Imagine spectrum of functions e.g. for upper bound:
 * 		1) On extreme left, function that return OO
 * 		2) mid functions, not very tight, when reaching a leaf node, its bound != actual value.
 * 			*) According to implementation, you may or may not complete search till the queue be empty
 * 		3) Very Tight functions
 * 			In this one, once state can't be branched any more, its actual value = bound
 * 				--> This has very speed convergence, as bounds are more close to actual values
 * 				--> Very efficient, as once you reached, you terminate the search. You know it was max bound, and no others will be better states
 *
 *
 * 	If you know how a state could be branched, and how to do VALID bound function, you are READY to write Branch and bound algorithm
 *
 * 	Branch and bound algorithm depends on best first search
 * 		1- Same algorithm as breadth first search, with one difference: we sort the data always based on state bound, to pick the best one
 * 		2- Based on Bound Design, we decide when algorithm stops
 *
 *
 * 	Little programming competitions problem are solved by BB
 *
 * 	When finish this session, make sure to revise above notes again and again
 */






























// pseudocode

struct myState {
	int bound;		// best valid possible answer from this state
	// My Data

	int calcBound()	{
		// calc valid bound
		return bound;
	}

	bool canBebranched() {	// is this base case state, or more divisions possible
		return true;
	}

	int realAnswer() {		// Do exact answer for a base case state
		return 0;
	}

	// Let priority sort based on larger first (default. switch < to > for smaller first
	bool operator < (const myState & s) const{
		return bound < s.bound;
	}
};



int solveMax(myState intial)
{
	priority_queue<myState> queue;	// sort based on larger

	intial.calcBound();
	queue.push( intial );

	int iters = 0;
	int best = (int)-1e8;

	while ( ++iters ) {	// Best first search
		myState st1 = queue.top();
		queue.pop();

		if(st1.bound <= best)	// without this line, you are just doing exhaustive search
			continue;			// we already achieve much better than your best possible value

		if(!st1.canBebranched())	// base case
		{
			best = max(best, st1.realAnswer());
			continue;	// break if tight bound
		}

		myState st2, st3;
		// branch st1 to st2 and st2

		st2.calcBound(), st3.calcBound();
		queue.push(st1), queue.push(st2);
	}

	return best;
}













/*
 * Books describe classical examples such as TSP problem. Please read.
 *
 * We will give a recent algorithm for Christoph H. Lampert, published in 2008.
 * 		Beyond SlidingWindows: Object Localization by Efficient Subwindow Search, in CVPR 2008
 *
 * 	The team gave a good algorithm for popular problem: Maximum sub-rectangle sum
 * 		The algorithm is data dependent. The larger sub-matrix answer, the faster algorithm termination. Its order ranges from O(n^2) to O(n^4)
 * 		Later, extremely faster algorithm in 2009, improved order to range from O(n^2) to O(n^3)
 *
 * 	We already described an O(n^3) to this problem using DP.
 *
 * 	Today, we will describe a simpler problem, the maximum sub-interval sum, and your homework is to extend to Maximum sub-rectangle sum
 *
 * 	It may be a bit hard example to explain, but is very interesting and has many thoughts.
 *
 * 	As we mentioned before: Branch and Bound = Valid Branching + Valid Bounding
 */




























/*
 * Maximum sub-interval sum = Given a list of N numbers, find sub-interval with maximum sum.
 *
 * 1) What is your state?
 *
 * 		let's think in State. We need interval, so let state be (start, end) of a window.
 *
 * 		Define state: Our state represent all sub-windows between (start and end)
 * 				E.g. if state is (2, 4), then we have following windows: (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (4, 4)
 *
 *		Initially state (1, n) contains all possible widows
 *
 * 2) Branching
 *
 * 		Greedily, divide it to 2 halves
 *
 * 		Imagine we have 10 numbers. So initial interval is (1, 10)
 *
 * 		Now, let's divide it, then we have 2 states
 * 			(1, 5)
 * 			(5, 6)
 *
 * 	WRONG
 *
 * 		According to your definition, could the answer be window (4, 7)? NO!
 *
 * 		So even state representation is challenging!
 */

















/*
 * What is the problem? Although state representation definition contained all possible answers,
 * 		the branching when applied dropped some space parts. Hence wrong.
 *
 * 	Then, either we need to think in different branching, which is not clear! or think in new state.
 */


















/*
 * What about 2 intervals in a state. First interval represents an index for main interval start and, 2nd interval for main interval end.
 *
 * E.g. If state is (2, 3) and (6, 8)
 * 		Then possible windows are: (2, 6), (2, 7), (2, 8), (3, 6), (3, 7), (3, 8)
 *
 * 		If we generated a window and its start after its end, we simply drop it
 * 		state is (2, 4) and (2, 4), possible windows: (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (4, 4)
 * 			E.g. we dropped (3, 2)
 *
 * So what about initial state? will be (1, n) and (1, n) -> which contains the initial N^2 windows
 *
 * What about branching?
 * 		We have 2 intervals per state. Get largest, and cut it to 2 halves
 *
 * 		E.g. if state is (2, 6) and (7, 9)	which contains: 5 * 3 windows
 * 			we branch to
 * 				(2, 4) and (7, 9) = which contains: 3 * 3 windows
 * 				(5, 6) and (7, 9) = which contains: 2 * 3 windows
 *
 * 		Great! We have correct branching!
 * 			When to stop branching? when ever the intervals have one item inside. E.g. state (3, 3) and (5, 5) which represents interval [3, 5]
 *
 * 		Time for valid bound! Or we back from start!
 */




























/*
 * We said, bound could be tight or not tight. A valid bound should always give higher/lower value than correct one.
 *
 * Ok...we have set of windows inside my state. We need an upper that is larger than any actual window summation.
 *
 * Here is a nice one. Sum the positive integer in the largest window.
 * 		E.g. if state is (2, 6) and (7, 9), sum +ve values in interval [2, 9]
 *
 * 		Is this valid? Sure, we just dropped all -ve values, which could lower a summation.
 * 			Imagine even all interval has +ve numbers, simply our bound same as real value
 *
 * 		is this extremely tight? No. state (3, 3) and (5, 5) which represents interval [3, 5]
 * 			let interval values be [2 -5 4]. Our bound is 6. Actual is 1.
 * 				IFF real = bound in base case, this is not tight
 *
 * 	Let's see some code.
 */









































const int DIM = 2;
enum {Left, Right};

const int MAX = 1000;
int W[MAX], pos[MAX], neg[MAX];





struct state {			// represents set of intervals: where one side is represented with interval
	int upperbound;
	short intervalStart[DIM], intervalEnd[DIM];	// 2 intervals. For code simplicity, we make array for the 2 intervals start and 2 for end
	// E.g. state is (2, 3) and (6, 8), then intervalStart{2, 6} and intervalEnd{3, 8}

	int largestInterval() {
		int bestSide = 0;
		for (int i = 1; i < DIM; ++i) if(intervalEnd[i] - intervalStart[i] > intervalEnd[bestSide] - intervalStart[bestSide])
			bestSide = i;
		return bestSide;
	}

	bool isLeafNode() {
		int bestSide = largestInterval();

		return intervalEnd[bestSide] == intervalStart[bestSide];
	}


	int intervalSum(int arr[MAX], int i, int j) {
		return arr[j] - arr[i-1];
	}

	//determine dimensions of small and large intervals and calculate F+(MAX), F-(SMALL) intervals.
	void calcTightUpperBound() {
		int score_plus =  intervalSum(pos, intervalStart[Left], intervalEnd[Right]);

		int score_mins =  0;
		if(intervalEnd[Left] <= intervalStart[Right])	// check if there is a common interval
			score_mins = intervalSum(neg, intervalEnd[Left], intervalStart[Right]);

		upperbound = score_plus + score_mins;
	}

	//determine dimensions of small and large intervals and calculate F+(MAX), F-(SMALL) intervals.
	void calcNotTightUpperBound() {

		if(isLeafNode())
			return calcTightUpperBound();

		int score_plus =  intervalSum(pos, intervalStart[Left], intervalEnd[Right]);

		upperbound = score_plus;
	}

	// Let priority sort based on larger first
	bool operator < (const state & s) const{
		return upperbound < s.upperbound;
	}
};



















/*
 * W 	= [1 	2 	-5 	3 	2 	1 	-4 	-2	]
 * Pos 	= [1 	3 	3  	6 	8 	9  	9  	9	]	// Accumulate array, and consider any negative as zero
 * Neg 	= [0 	0 	-5 -5 	-5 	-5  -9  -11	]	// Accumulate array, and consider any positive as zero
 */



void calcPosNegAccumulative(int n) {

	for (int i = 1; i <= n; i++)
	{
		neg[i] = neg[i - 1], pos[i] = pos[i - 1];

		if (W[i] > 0)
			pos[i] += W[i];
		else
			neg[i] += W[i];
	}
}

















int BB_not_Tight(int n) {
	calcPosNegAccumulative(n);
	priority_queue<state> queue;

	state st;
	lp(i, DIM) st.intervalStart[i] = 1;
	st.intervalEnd[Left] = st.intervalEnd[Right] = n;

	st.calcNotTightUpperBound();
	queue.push( st );

	int iters = 0;
	int best = (int)-1e8;

	while ( ++iters ) {	// Best first search
		state st1 = queue.top(), st2 = st1;
		queue.pop();

		if(st1.upperbound <= best)	// without this line, you are just doing exhaustive search
			continue;	// we already achive much better than your best possible value

		int bestSide = st1.largestInterval();

		if(st1.intervalEnd[bestSide] == st1.intervalStart[bestSide])
		{
			//Calc this interval sum
			int posSum = st1.intervalSum(pos, st1.intervalStart[Left], st1.intervalEnd[Right]);
			int negSum = st1.intervalSum(neg, st1.intervalEnd[Left], st1.intervalStart[Right]);

			best = max(best, posSum + negSum);
			continue;
		}

		st1.intervalEnd[bestSide] = (st1.intervalEnd[bestSide] + st1.intervalStart[bestSide])/2;
		st2.intervalStart[bestSide] = st1.intervalEnd[bestSide] + 1;

		st1.calcNotTightUpperBound(), st2.calcNotTightUpperBound();
		queue.push(st1), queue.push(st2);
	}

	return best;
}




// If we want to do a break at the base case, we could do a simple trick
// When we branch, if branched node is base case, set its bound = actual value. This is more efficient





























/*
 * As we said, the more tight, the more efficient, could we make it more tight? Extremely tight?
 *
 * Extremely Tight means bound in base = real.
 *
 * E.g. if state (3, 3) and (5, 5) which represents interval [3, 5]
 * 		let interval values be [2 -5 4]. Our bound must be total sum = 1, not just positive
 *
 *
 * Ok, think in following. if state is (2, 3) and (6, 8).
 * 		What is the common interval inside all windows? Simply first end and 2nd start. E.g. (3, 6).
 * 		For the common interval, we will add both negative and positive values. In other words, all interval be there.
 *
 * 	Could this be valid bound? sure. We have common part + positive values in both sides
 *
 * 	Could this be Extremely tight? if state (3, 3) and (7, 7) which represents interval [3, 7]
 * 		let interval values be [-2 3 -5 4 6].
 * 			As now common interval is same as main interval, bound will have all values.
 */
























int BB_Tight(int n) {
	calcPosNegAccumulative(n);
	priority_queue<state> queue;

	state st;
	lp(i, DIM) st.intervalStart[i] = 1;
	st.intervalEnd[Left] = st.intervalEnd[Right] = n;

	st.calcTightUpperBound();
	queue.push( st );

	int iters = 0;
	while ( ++iters ) {	// Best first search
		state st1 = queue.top(), st2 = st1;

		int bestSide = st1.largestInterval();

		if(st1.intervalEnd[bestSide] == st1.intervalStart[bestSide])
			break;

		st1.intervalEnd[bestSide] = (st1.intervalEnd[bestSide] + st1.intervalStart[bestSide])/2;
		st2.intervalStart[bestSide] = st1.intervalEnd[bestSide] + 1;

		queue.pop();

		st1.calcTightUpperBound(), st2.calcTightUpperBound();
		queue.push(st1), queue.push(st2);
	}

	return queue.top().upperbound;
}




































int MIS(int n)	// popular O(n) algorithm for maximum sub-interval sum
{
	int best, maxi;

	maxi = best = 0;
	for(int i = 0; i< n ;i++)
	{
		if(best < 0)
			best = W[i+1];
		else
			best += W[i+1];

		if(best > maxi)
			maxi = best;
	}
	return maxi;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen("c.txt", "wt", stdout);
#endif

	int n = 200;

	while(true)
	{
		for (int i = 0; i < n; i++)
		{
			W[i + 1] = rand();
			if(rand()%2)
				W[i+1] *= -1;
		}

		assert(MIS(n) == BB_Tight(n));
	}



	return 0;
}
