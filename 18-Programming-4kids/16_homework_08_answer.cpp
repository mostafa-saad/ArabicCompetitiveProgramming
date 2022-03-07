#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/asteroid-collision.cpp

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;

    for (auto& asteroid : asteroids) {
    	// For every new asteroid, remove all what will explode
    	// Only may happens when asteroid going backword and something coming forward
        bool is_exploded = false;
        while (!result.empty() && asteroid < 0 && 0 < result.back()) {
        	// last will explode.
            if (result.back() < -asteroid) {
                result.pop_back();
                continue;	// See if more explode
            } else if (result.back() == -asteroid)	// both exploded
                result.pop_back();
            is_exploded = true;		// only asteroid explode
            break;
        }
        if (!is_exploded)
            result.push_back(asteroid);
    }
    return result;
}

int main() {

	return 0;
}
