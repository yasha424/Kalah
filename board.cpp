#include "board.h"

Kalah::Kalah(int count_of_stones) {
	stones_num = count_of_stones;
	player = new int *[2];
	for (size_t i = 0; i < 2; i++) {
		player[i] = new int[7];
		for (size_t j = 0; j < 6; j++) {
			player[i][j] = stones_num;
		}
		player[i][6] = 0;
	}
	whoose_turn = false;
}

Kalah::Kalah(const Kalah &kalah) {
	player = new int *[2];
	for (size_t i = 0; i < 2; i++) {
		player[i] = new int[7];
		for (size_t j = 0; j < 6; j++) {
			player[i][j] = kalah.player[i][j];
		}
		player[i][6] = kalah.player[i][6];
	}
	whoose_turn = kalah.whoose_turn;
}

Kalah::~Kalah() {
	for (size_t i = 0; i < 2; i++) {
		delete[] player[i];
	}
	delete[] player;
}

void Kalah::print() {
	cout << player[1][6] << "  ";
	for (int i = 5; i >= 0; i--) {
		cout << player[1][i] << " ";
	}
	cout << endl << "   ";
	for (size_t i = 0; i < 6; i++) {
		cout << player[0][i] << " ";
	}
	cout << " " << player[0][6] << endl;
}

int **Kalah::getBoard() {
	return player;
}

bool Kalah::getWhoseTurn() {
	return whoose_turn;
}

void Kalah::setwhoseTurn(bool is_comp) {
	whoose_turn = is_comp;
}

bool Kalah::makeMove(int hole_index) {
	int count_of_stones = player[whoose_turn][hole_index];
	int player_number = whoose_turn;

	if (count_of_stones != 0) {
		player[player_number][hole_index] = 0;
		for (size_t i = 0; i < count_of_stones; i++) {
			hole_index++;
			if (hole_index == 6 && player_number == whoose_turn) {
				player[player_number][hole_index]++;
				player_number = !player_number;
				hole_index = -1;
			} else if (hole_index == 6) {
				player_number = !player_number;
				hole_index = 0;
				player[player_number][hole_index]++;
			} else {
				player[player_number][hole_index]++;
			}
		}
		if (hole_index == -1 && whoose_turn != player_number) {
			whoose_turn = !whoose_turn;
		} else if (player[player_number][hole_index] == 1 && player_number == whoose_turn &&
			player[!player_number][5 - hole_index] != 0) {
			player[player_number][6] += player[!player_number][5 - hole_index] + 1;
			player[!player_number][5 - hole_index] = 0;
			player[player_number][hole_index] = 0;
		}
		whoose_turn = !whoose_turn;
		return true;
	}
	return false;
}

bool Kalah::gameOver() {
	for (size_t i = 0; i < 6; i++) {
		if (player[whoose_turn][i] != 0) {
			return false;
		}
	}
	for (size_t i = 0; i < 6; i++) {
		player[!whoose_turn][6] += player[!whoose_turn][i];
		player[!whoose_turn][i] = 0;
	}
	return true;
}

int Kalah::bestMove(int depth) {
	int best_score = -INT_MAX, best_move = -1;

	for (size_t i = 0; i < 6; i++) {
		Kalah *current = new Kalah(*this);
		int score = -INT_MAX;

		if (current->makeMove(i)) {
			score = current->minimax(depth - 1, -INT_MAX, INT_MAX);
			if (best_score <= score) {
				best_score = score;
				best_move = i;
			}
		}
		delete current;
	}
	return best_move;
}

int Kalah::minimax(int depth, int alpha, int beta) {
	int best_score = 0;

	if (gameOver()) {
        return heuristic();
	} else if (depth > 0) {
		if (whoose_turn) {
			best_score = -INT_MAX;
			for (size_t i = 0; i < 6; i++) {
				Kalah *current = new Kalah(*this);

				if (current->makeMove(i)) {
					int score = current->minimax(depth - 1, alpha, beta);

					if (alpha < score) {
						alpha = score;
					}
					if (best_score < score) {
						best_score = score;
					}
					if (score >= beta) {
						delete current;
						break;
					}
				}
				delete current;
			}
			return best_score;
		} else if (!whoose_turn) {
			best_score = INT_MAX;
			for (size_t i = 0; i < 6; i++) {
				Kalah *current = new Kalah(*this);

				if (current->makeMove(i)) {
					int score = current->minimax(depth - 1, alpha, beta);

					if (beta > score) {
						beta = score;
					}
					if (best_score > score) {
						best_score = score;
					}
					if (score <= alpha) {
						delete current;
						break;
					}
				}
				delete current;
			}
			return best_score;
		}
	}
	return heuristic();
}

int Kalah::heuristic() {
	return player[1][6] - player[0][6];
}

int Kalah::getPoints(bool whose) {
	return player[whose][6];
}

void Kalah::changeSides() {
	for (size_t i = 0; i < 7; i++) {
		int tmp = player[0][i];

		player[0][i] = player[1][i];
		player[1][i] = tmp;
	}
}
