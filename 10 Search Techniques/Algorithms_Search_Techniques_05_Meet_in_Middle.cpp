/*
 *
 *
 ******************************************** License *******************************************
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
- What is meet in middle?
- Bidirectional search Problem
- Breaking Double Encryption
- Equal KnapSacks problem
- Sum 4 numbers = 0 Problem

Problems: SPOJ(SUMFOUR, SUBSUMS, SOLIT, PARITY, ABCDEF), TC(KnapsackProblem TCHS07-D1-3, SRM(388-D1-3 TelephoneNumbers), SRM(307-D1-3 SplitAndMergeGame)), UVA(704)
 */
















/**
 * Meet in the middle technique:
 * 		The technique assumes we could formulate the problem as a start state and end state, and our current algorithm just go from start to end in O(B^N)
 *
 * 		However, O(B^N) is too much. If applicable, we could ask the start and end states to meet in the middle way.
 * 		If this is applicable, such that start takes O(B^(N/2)) and end takes O(B^(N/2)) 	THEN	we got and 2 x O(O(B^(N/2))) algorithm
 *
 * 		Typically, but not necessarily, algorithm flow
 * 			From Start State, generate half solutions in O(B^(N/2)), and save them in memory in O(B^(N/2))
 * 			From End State, walk backward, and generate half solutions in O(B^(N/2)). Then start to match with the saved memory.
 *
 *
 * 	The art is to define what is start & end. Sometimes they are explicit and many times they are implicit.
 *
 * 	Meet in the middle has some well known applications (E.g. Bidirectional search, Breaking 2DES encryption algorithm), and adhock ones.
 */

















/**
 * Given unweighted graph of M Nodes (very large number), where each node has 4 children only. Find the shortest path between initial vertex and goal vertex, given that
 * the maximum possible answer is N?
 *  	Basically, we could run BFS, will will have order O(4^N), assuming 4^N <= M
 *
 * How Meet in the middle think? Let start and end meet in the middle!
 *  	What about running two simultaneous BFS searches: one forward from the initial state, and one backward from the goal
 * 			where stopping condition is when the two meet in the middle. If we simulate one step from start, then from end, they must meet after N/2 steps maximum
 * 				That is start takes O(4^(N/2)), and same for end node. So total order is 2 * O(4^(N/2)) which is an extreme improvement!
 *				Generally O(b^(N/2)) where b is the branching factor
 *
 * Another easy implementation way, is to simulate N/2 steps from start and save SP's in vector
 * 		Then simulate the second node for N/2 steps, and whenever hitting a node, do minimization.
 *
 * Note, we were lucky as problem already have start state and end state! Explicit start and end nodes
 *
 * What kind of real life applications that may need so? Extremely large graph + small shortest paths?
 * 		Imagine Facebook friendship graph. They have 1.11 billion people using the site each month!
 * 			But do we need to consider a path of millions of edges? No, possibly 2 persons may have a relation with connections (path) up to ~40 link
 *
 * This algorithm is known as Bidirectional search.
 *
 *
 * Such algorithm could be applied in many cases, where graph is implicit:
 * 	E.g. 8 puzzle. Given initial configuration and the purpose is to get to the final sorted configuration in the fewest number of moves.
 *
 * See the image.
 */










/**
 * Caesar's cipher is an encryption techniques, where each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet.
 * For example, with a left shift of 3, D would be replaced by A, E would become B, and so on.
 *
 * So we could build Encrypt(String, shift) that encrypt a string
 * 		For example:    Encrypt(ABCDHIJKLMNOXYZ, 23) = XYZAEFGHIJKLUVW
 * 		Similarly		Decrypt(XYZAEFGHIJKLUVW, 23) = ABCDHIJKLMNOXYZ
 * 		and				Decrypt( Encrypt(ABCDHIJKLMNOXYZ, 23), 23) = ABCDHIJKLMNOXYZ
 *
 *
 *
 * A string may have double encryption with 2 different codes:
 * 		Encrypt( Encrypt(Mostafa, 20), 19) and to get original string  once with 19, then with 20.
 *
 * 	Generally, assume we have a complicated encryption with similar properties as Caesar's cipher.
 *
 * 	Say we are given original string, and double encrypted string, and we know a key is in range [0-N]
 * 		Could you know what are the 2 used keys for encryption?
 *
 * 			Yes in O(N^2) * O(Enc)
 *
 * 			For each N
 * 				1  = Encrypt(Original)
 * 					For each N
 * 						2  = Encrypt(1)
 *
 * 						Compare 2 to given decrypted string
 *
 *
 * 			Sure we could do reverse: Start from decrypted string, and decode twice in 2 loops
 *
 *
 * Assumes an encryption algorithm which uses 20 bit keys, that is N up to 2^20 and algorithm order is 2^40
 *
 * How Meet in the middle helps?
 * 		Start from Original, try N keys, encrypt them and push in map			-> O(N) time + O(N) memory
 * 		Start from encrypted, try N keys, decrypt and search map for a match	-> O(N) time + O(logN) search Map
 *
 * So we converted an O(N^2) algorithm to 2 x O(N) time and O(N) memory
 *
 * See 2Des Image (Src: http://www.infoarena.ro/blog/meet-in-the-middle)
 *
 * Note, we were lucky as problem already have start state and end state! Explicit start and end strings.
 *
 * Actually, meet in middle was invented by Diffie and Hellman in 1977 to solve this problem.
 * 		They devised a space-time tradeoff that could break the 2DES schema in only double the time to break the single-encryption scheme
 * 		Later people used 3DES, that is encrypt 3 times to avoid such attack
 *
 *
 */

/*
 * Homework:
 * 		Given two equal length strings S and T. Figure out if we can get string T starting from string S by applying 4 substring reversal operations.
 */

/**
 * Remember: Big # of states + Small Length Shortest path + Direction = !Revere -> Check meet in middle
 */



























/**
 * What about an implicit start and end states?
 *
 * Say we are given set of integers, and we want to divide them to 2 equal parts in summation.
 *
 * E.g. 1 2 4 5 3 6 1 0
 * 		1+5+3+2 = 4+6+1+0 = 11
 *
 * This problem is solved efficiently using DP, but let's see how meet in middle approaches it.
 *
 * A direct brute force will try 2^n states, for each state extract sum of 0's and sum of 1's and compare
 *
 * E.g. if mask is 00101100: then we have (1, 2, 5, 1, 0)=9 and (4, 3, 6)=13	-> Not equal set
 *
 * Notice, we need the set sum = (1+2+4+5+3+6+1+0)/2 = 11
 *
 * How could we think in meet in middle? How to find start & end states?
 *
 * Let's divide the numbers to 2 halves: (1, 2, 4, 5) and (3, 6, 1, 0)
 *
 * Let's generate 2^4 states for the first half, and save in map pair of the 0's sum and 1's sum
 *
 * Now, let's do same for the second half. For each set we have a pair of the 0's sum and 1's sum
 *
 * Say that set was 0011, then we have sum (3+6=9, 1+0=1)
 *
 * We know this is valid division IFF, if its complement = (11-9, 11-1)
 * 		So search map for pair (2, 10) -> if exist, we found a solution.
 *
 * What happened
 * 		O(2^n) time -> 2 x O(2^(n/2)) time  + O(2^(n/2)) memory
 *
 *
 * 	Homework: What if we want to divide the numbers to 4 equal parts?
 */






















/**
 * Given array of numbers, could you find 4 numbers their sum = 0? You could use same number more than once.
 *
 * E.g. arr = 1, 5, 6, -2, 3, -9, 10, -10, -1, -15
 *
 * 		sol = 5+6-2-9  or 10-10+1+-1	or 	5+5+5-15
 *
 *
 * 	A direct solution is n^4: 4 loops tries every thing.
 *
 * 	Thinking in meet in middle -> pair + pair = 4 numbers
 *
 * 	First try every pair of numbers, save their sum in map (1+5, 1+6, 1-2, 1+2.......,-1-15).
 * 	Now, try again every pair of numbers, find their complement in map.
 *
 * 	E.g. assume, in 2nd time, we have pair sum 6, then IFF map has -6, we have 4 numbers that have 0 sum
 */



