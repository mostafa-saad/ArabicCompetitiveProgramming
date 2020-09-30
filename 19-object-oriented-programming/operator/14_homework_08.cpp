#include <bits/stdc++.h>
using namespace std;

class ChessBoard {
private:
	int rows;
	int colums;

public:
	ChessBoard(int rows, int colums) :
			rows(rows), colums(colums) {
	}
};

int main() {
	ChessBoard board(2, 3);	// 2x3 grid

	board(0, 0) = 10;
	board[0][1] = 20;

	cout << board[0][0] << " " << board(0, 1);

	return 0;
}
