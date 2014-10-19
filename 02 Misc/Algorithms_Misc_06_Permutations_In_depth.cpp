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
Given Index i, find ith Permutations
Given Permutations, find its index
Permutation multiplication
Apply Permutation 10^9 time using power function
Permutation Cycle Notation
Effect of permutation applying over cycle length
Permutation Order
Stirling numbers of the first kind
Problems
- Sorting Numbers by swap operations of cost 1
- Sorting Numbers by swap operations of cost sum of swapped
- Number of possible orders for a permutation

Problems:
UVA: 306, 10570
Live Archive: 2481
TC: SRM572-1-1, SRM280-2-3, SRM379-2-3, SRM220-1-3, SRM391-1-2, SRM160-1-3, TCCC06-QR2-1-3, TCO06-R2-1-3, TCO03-R3-1-3

NOTE: SRM379-2-3 Means SRM 379 Division 2, Level 3

 */
/*











For vector {0, 1, 2} -> we have 3! = 6

Idx: 0		0 1 2		-> Sorted		{			Block of length 2! = 2
Idx: 1		0 2 1						}

Idx: 2		1 0 2
Idx: 3		1 2 0

Idx: 4		2 0 1
Idx: 5		2 1 0		-> Reversed


For vector {0, 1, 2, 3} -> we have 4! = 24

Idx: 0		0 1 2 3 					{
Idx: 1		0 1 3 2 					.
Idx: 2		0 2 1 3 					.			Block Start with Zeros. Its Length 3! = 6
Idx: 3		0 2 3 1 					.
Idx: 4		0 3 1 2 					.
Idx: 5		0 3 2 1 					}

Idx: 6		1 0 2 3
Idx: 7		1 0 3 2
Idx: 8		1 2 0 3
Idx: 9		1 2 3 0
Idx: 10		1 3 0 2
Idx: 11		1 3 2 0

Idx: 12		2 0 1 3
Idx: 13		2 0 3 1
Idx: 14		2 1 0 3
Idx: 15		2 1 3 0
Idx: 16		2 3 0 1
Idx: 17		2 3 1 0

Idx: 18		3 0 1 2
Idx: 19		3 0 2 1
Idx: 20		3 1 0 2
Idx: 21		3 1 2 0
Idx: 22		3 2 0 1
Idx: 23		3 2 1 0










// How to iteratively generate them?
// Given Input Vector: inp -> If inp is sorted, then n! will be found.

do {
	//Print
} while(next_permutation(all(inp)));	// get next lexicographically permutation after given one

























// Given a permutation length, what is the ith permutation?

vector<ll> nthPerm(ll len, ll nth) {
	vector<ll> identity(len), perm(len);
	lp(i, len) identity[i] = i;

	for (int i = len - 1; i >= 0; --i) {
		ll p = nth / Fact[i];
		perm[len - 1 - i] = identity[p];
		identity.erase(identity.begin() + p);
		nth %= Fact[i];
	}
	return perm;
}

























// Given a permutation, what is its index?
ll PermToIndex(vector<int> perm) {

	ll idx = 0;
	int n = sz(perm);
	for (int i = 0; i < n; ++i) {
		// Remove first, and Renumber the remaining elements to remove gaps
		idx += Fact[n-i-1] * perm[i];
		for(int j = i+1; j < n; j++)
			perm[j] -= perm[j] > perm[i];
	}
	return idx;
}

































Permutations Application:
	Say we have a permutation: 	2 0 1 3
		Applying a permutation on other, aka multiplication, means to map its values according to the permutation.

		So 2 0 1 3 MEANS: 0 -map-> 2	1 -map-> 0		2 -map-> 1		3 -map-> 3

	Then
		(0 1 2 3) * (2 0 1 3) = 2 0 1 3
		(2 3 1 0) * (2 0 1 3) = 1 3 0 2
		(3 2 0 1) * (2 0 1 3) = 3 1 2 0
		(3 2 0 1) * (2 0 1 3) * (2 0 1 3) = (3 1 2 0) * (2 0 1 3) = 3 0 1 2


	Permutation Multiplication is associative, like numbers Multiplication, e.g. doesn't matter what to apply first
		For Numbers: 3 * 5 * 7 = (3 * 5) * 7 = 3 * (5 * 7)

		Then for Some Permutations: P1 * p2 * p3 * p4 = P1 * (p2 * p3 * p4) = (P1 * p2) * (p3 * p4) and so on.

	Permutation Multiplication is NOT Commutative, like numbers subtraction, e.g. order matter
		For numbers: 3-5 ~= 5-3

		Then for Permutations = (0 1 2 3) * (2 0 1 3) ~= (2 0 1 3) * (0 1 2 3)


	P^k means apply Permutation k times, e.g. (3 2 0 1) * (2 0 1 3) * (2 0 1 3) is written as: p1 * p2^2

	Say we are given P1 and P2, and we would like to evaluate p1 * p2^k, where k = 10^9?!!

		Check above, Permutation is similar in that for Numbers.
		E.g. how do you calculate a^16? we use divide and conquer: a^16 = a^8 * a^8. Calculate a^8 and square it! SAME for Permutation

		typedef vector<int> perm;

		perm pow(perm inp, perm apply, int k)
		{
			if(k == 0) // won't apply permutation, so same as input
				return inp;

			if(k == 1)
				return applyPerm(inp, apply);	// implement: (0 1 2 3) * (2 0 1 3) = 2 0 1 3

			perm = pow(inp, apply, k/2);
			cur = applyPerm(cur, cur);

			if(k%2 == 1)	// we have odd power
				cur = applyPerm(cur, perm);

			return cur;
		}

		Order? N for applyPerm * logk for depth -> O(nlogk)

		Could we do better? YES, a bit more code, but we can do it! Using Permutation Cycle Notation




































Permutation Cycle Notation
	From Abstract Algebra, we know that Permutation is set of dis-joint cycles. How
		In other words, if you followed which value replace other, you create a cycle.

	Let Say we have permutation p: 1 2 3 0

		0 -> 1
		1 -> 2
		2 -> 3
		3 -> 0	// End of Cycle

	What about 3 2 1 0 4
		0 -> 3
		3 -> 0	// End of Even Cycle

		1 -> 2
		2 -> 1	// End of Even Cycle

		4 -> 4 // End of ODD Cycle, with one element

	What about 2 0 1 4 3
		0 -> 2
		2 -> 1
		1 -> 0	// End of ODD Cycle

		3 -> 4
		4 -> 3	// End of Even Cycle



	Then, any permutation is set of cycles -> this is CLUE for many permutation problems

	Let's pick a one cycle permutation, and see its application: 3 0 1 2
		0 -> 3		3 -> 2		2 -> 1		1 -> 0

	let's apply it many times over a perm p: 0 1 2 3

	(0 1 2 3) * (3 0 1 2)^1 = 3 0 1 2
	(0 1 2 3) * (3 0 1 2)^2 = 2 3 0 1	Notice, the rotation of the cycle
	(0 1 2 3) * (3 0 1 2)^3 = 1 2 3 0
	(0 1 2 3) * (3 0 1 2)^3 = 0 1 2 3	We backed again!

	Think in that, a cycle of length N, if applied N times, it backs to is origin!
		And applying a cycle N+1 	= 1 	time
							 N+2 	= 2 	times
							 2N+1	= 1 	time
							 M		= M%N 	time

	Let's think again in our problem: how to solve p1 * p2^k	and k = 10^9?
		Simply, 1) Generate Permutation Cycles (aka disjoint cycle decomposition) -> O(n)
				2) For each cycle length M, apply cycle M%N times, which is just a rotation
				3) Cleverly, implement all in O(n)









































Effect of permutation applying over cycle length
	Say we have permutation p = 3 0 1 2 5 6 4
		then we have cycle of length 4 = (3 0 1 2), and cycle of length 3 (5 6 4)

	How is applying it over itself? p*p
							p' = 2 3 0 1 6 4 5
		then we have cycle of length 2 = (2 0), and 2 (3 1) and cycle of length 3 (6 4 5)

	Conclusion: Applying a permutation ONCE on a cycle, divide even to 2 cycles of length, cycleLen/2
				and odd cycle remain same.

				More application is not deterministic for even cycle, but same for odd cycles.

				The elements of the original disjoint cycles will never be mixed.




































Permutation Order
	We said that, if we have a cycle of length N, applying permutation N times, back it to original

	What about whole string, after how many perm it back to its original? This is called Permutation Order

	Let say that we have ONLY one cycle of length 4 -> Then string back to its original after 4 steps

	what about 2 cycles of length 4, and 8
		Then after 8 steps: I am 2*4 and 8, so both of us are backed to same

	what about 2 cycles of length 6, and 9
		Then after 18 step: I am 3*6 and 2*9, so both of us are divisble by number of steps.

	Then we need LCM between cycles length, to know when we all back to original in same time.































Stirling numbers of the first kind
	Number of permutations of n elements with k permutation cycles.

	Has a nice recurrence to implement. See wikipedia






























Problems:
	When ever you have relations between permutations, think in Permutation Cycles.
		Typically relation won't be clear, it is your turn to find it!























Problem 1: NewArenaPassword		SRM 572-1-1
	Given String, and K, find minimum changes to make first K characters same like last K characters.
	E.g. 	topcoderopen	K = 5
			topcndetopcn

	We have 2 cases, either the 2 blocks of K chars don't intersect, then we simply change every different characters.

	Or some characters interfere with each other. Try to change a letter of them, it is changed in both, actually more.

		amavckdnz					K = 7
		avckdnz

		Notice the pairs: (m, v), (v, k), (k, n)
			When you change one, you will change it in remain.

		Notice, we have permutation cycles.

		Simply, extract the cycles in length K, for each cycle, color it with highest frequency one.



























Problem 2: Meeting with Aliens: UVA 10570
	We have group of numbers in circular format. We want them be in order 1 2 3 .. n OR n n-1 ... 3 2 1
	Operation allowed is swapping 2 elements, it cost 1. Do that in minimum cost.

	Say N = 3: So order them to any of: 1 2 3, 2 3 1, 3 1 2, 3 2 1, 2 1 3, 1 3 2	[Sorted/reversed * rotated]

	Let say we want to arrange them to 1 2 3 4 ... n
	From permutation cycles we know that, they are disjoint groups.

	Say input is 4 3 2 1: They are cycles (4 1) and (3 2)
		Then swaps of 4 1 is unrelated to 3 2
		So overall cost is 1 + 1 = 2.

		Generally a cycle of length M, needs M-1 swaps






























Problem 3: Silly Sort: Live Archive 2481
	Given array unsorted, sort it, by swap operation. Cost of swap is sum of swapped elements.

	Same idea as above, but more tricker.
	Say we divided the sequence to cycles. To sort it, greedily use the minimum element in cycle to sort it.
	Say we have cycle 5 3 1 7
		Then Swap (1, 3), (1 5), (1 7) = 3 * min + sum - min

	One final trick! Imagine another cycle in same above sequence (10, 20, 30, 40)
		According to above we do 3 * 10 + 20+30+40

		In this case, better to swap 1 with 10, so sequence is 1, 20, 30, 40.
			Then do the 3*1 + 20+30+40

			Then swap (1, 10) again


































Problem 4: NumPermutationOrders:    TCO 06-R1-3
	Considering all permutations on S, return how many possible orders there are.

	A permutation order is LCM of their numbers.

	Say we have cycles of permutations of length: 4, 3, 1, 1: N = 9, LCM = LCM(4, 3)

	Then we need all numbers such that SUM <= N (for cycles of length 1).

	Wait, this way, many values will lead to SAME LCM, should be count once.

	FACT LCM(p1, p2, p3) = p1*p2*p3 IFF they are coprimes.

	Use only prime numbers in your generation and you will have no duplicated









































*/
