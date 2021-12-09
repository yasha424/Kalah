#include <iostream>
#include <vector>
using namespace std;

class Kalah {
	int **player;
	// vector<Kalah *> childs;
	bool whoose_turn;                   // true for computer
	const int stones_num = 4;

public:
	Kalah();
	Kalah(const Kalah &kalah);

	~Kalah();
	void print();

	int **getBoard();

	void setwhoseTurn(bool is_comp);
	bool getWhoseTurn();
	bool makeMove(int hole_index);
	bool gameOver();
	int bestMove(int depth);
	int minimax(int depth, int alpha, int beta);
	int heuristic();
	int getPoints(bool whose);
	void changeSides();
};
