#include <bits/stdc++.h>
using namespace std;

enum Player {
	O=0, X, TOTAL
};

enum class Result {
	None, O, X
};

Result playerToResult(Player p)
{
	switch(p) {
	case O:
		return Result::O;
	case X:
		return Result::X;
	default:
		assert(0);
	}
}


template <size_t N>
class Board
{
public:
	Board()
		: mRows{0}
		, mCols{0}
		, mDiags{0}
		, mPlayer{X} // X is the first player
	{}
	Result move(int row, int col)
	{
		assert(row <= N && col <= N);
		mRows[row-1][mPlayer]++;
		mCols[col-1][mPlayer]++;
		//diagonal
		if(row == col)
			mDiags[0][mPlayer]++;
		if(row+col == N+1)
			mDiags[1][mPlayer]++;

		//check victory
		for(size_t i=0; i<N; i++) {
			if(mRows[i][mPlayer] == N || mCols[i][mPlayer] == N)
				return playerToResult(mPlayer);
		}
		if (mDiags[0][mPlayer] == N || mDiags[1][mPlayer] == N)
			return playerToResult(mPlayer);

		//change player
		mPlayer = mPlayer == O ? X : O;

		return Result::None;
	}
	
private:
	int mRows[N][TOTAL], mCols[N][TOTAL], mDiags[2][TOTAL];
	Player mPlayer; // current player
};

int main()
{
	
}
