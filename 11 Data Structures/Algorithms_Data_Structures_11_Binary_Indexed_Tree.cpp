const int MAX_VAL = 30000+9;
int BITTree[MAX_VAL] = {0};		// We have an array of MAX_VAL all with 0

void add(int idx ,int val){	// WATCHOUT: if idx=0, SHIFT VALUES
	while (idx < MAX_VAL) BITTree[idx] += val, idx += (idx & -idx);
}

int getAccum(int idx){
	int sum = 0; 	while (idx > 0)	sum += BITTree[idx], idx -= (idx & -idx); 		return sum;
}

// Prerequisite : current array is positive, so that accum is increasing and BS is applicable
int getIdx1(int accum) { // If updates [1, -1], then  accumIdx(k) is same as kth -> 1+1+1..ktime = k
	int s = 1, e = MAX_VAL;

	while(s < e) {
		int midIdx = s + (e-s)/2, val = getAccum(midIdx);
		if(val >= accum)	e = midIdx;		else s = midIdx+1;
	}
	return s;		// s is the least x for which p(x) is true
}

// Prerequisite : current array is positive, so that accum is increasing and BS is applicable
int getIdx(int accum) {
	accum--;	// Function modified to return first occurrence of accum instead of last occurrence
	int base = 0, limit = 1<<(int)(log(MAX_VAL)/log(2));

	while(limit) {
		if( (base+limit) < MAX_VAL && accum >= BITTree[base+limit])
			base += limit, accum -= BITTree[base];
		limit >>= 1;
	}
	return base+1;	// to get last occurrence, remove this +1 and line accum--;
}

int getValue(int idx) {
	return getAccum(idx) - getAccum(idx-1);
}

// Given N from 1, 2, 3...N
// Remove 1st, 3rd, 5...
// Then remove 1st, 4th, ..
// so N=9: (1) remove 1, 3, 5, 7, 9. (2) Remove 4, 8,...last removed is 6
int lastRemoved(int N) {
	clr(BITTree, 0);

	lp(i, N)
		add(i + 1, 1);

	int TN = N, shift = 2, last = -100;
	while (TN) {
		int cur = 1;
		while (TN) {
			int idx = getIdx(cur);
			if (idx == MAX_VAL)
				break;
			last = idx;
			add(idx, -1);
			TN--;
			cur += shift - 1;
		}
		shift++;
	}

	return last;
}