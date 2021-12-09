#include "game.h"
#include "ui_game.h"

Game::Game(int depth, bool first_move, QWidget *parent): QDialog(parent), ui(new Ui::Game) {
	ui->setupUi(this);
	this->depth = depth;
	this->first_move = first_move;
	kalah = new Kalah();
	kalah->setwhoseTurn(!first_move);
	makeBoard();
	while (kalah->getWhoseTurn()) {
		// sleep(1);

		int best_move = kalah->bestMove(depth);

		kalah->makeMove(best_move);
		makeBoard();
	}
}

Game::~Game() {
	delete ui;
}

void Game::makeBoard() {
	ui->hole_1->setText(QString::number(kalah->getBoard()[0][0]));
	ui->hole_2->setText(QString::number(kalah->getBoard()[0][1]));
	ui->hole_3->setText(QString::number(kalah->getBoard()[0][2]));
	ui->hole_4->setText(QString::number(kalah->getBoard()[0][3]));
	ui->hole_5->setText(QString::number(kalah->getBoard()[0][4]));
	ui->hole_6->setText(QString::number(kalah->getBoard()[0][5]));
	ui->kalah_1->setText(QString::number(kalah->getBoard()[0][6]));
	ui->hole_7->setText(QString::number(kalah->getBoard()[1][0]));
	ui->hole_8->setText(QString::number(kalah->getBoard()[1][1]));
	ui->hole_9->setText(QString::number(kalah->getBoard()[1][2]));
	ui->hole_10->setText(QString::number(kalah->getBoard()[1][3]));
	ui->hole_11->setText(QString::number(kalah->getBoard()[1][4]));
	ui->hole_12->setText(QString::number(kalah->getBoard()[1][5]));
	ui->kalah_2->setText(QString::number(kalah->getBoard()[1][6]));
	if (!kalah->getWhoseTurn()) {
		ui->whose_turn_label->setText("Your turn");
	} else {
		ui->whose_turn_label->setText("AI's turn");
	}
}

void Game::AIMove() {
	if (kalah->getWhoseTurn()) {
		int best_move = kalah->bestMove(depth);

		kalah->makeMove(best_move);
		makeBoard();
		if (kalah->gameOver()) {
			if (kalah->getPoints(true) > kalah->getPoints(false)) {
				ui->whose_turn_label->setText("AI Won!");
			} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
				ui->whose_turn_label->setText("You Won!");
			} else {
				ui->whose_turn_label->setText("It's a draw");
			}
		}
	}
}

void Game::on_hole_1_clicked() {
	if (!kalah->getWhoseTurn()) {
		kalah->makeMove(0);
		makeBoard();
	}
// if (kalah->getWhoseTurn()){
// sleep(1);
// AIMove();
// }
	if (kalah->gameOver()) {
		if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("AI Won!");
		} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("You Won!");
		} else {
			ui->whose_turn_label->setText("It's a draw");
		}
	}
}

void Game::on_hole_2_clicked() {
	if (!kalah->getWhoseTurn()) {
		kalah->makeMove(1);
		makeBoard();
	}
// if (kalah->getWhoseTurn()){
//// sleep(1);
// AIMove();
// }
	if (kalah->gameOver()) {
		if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("AI Won!");
		} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("You Won!");
		} else {
			ui->whose_turn_label->setText("It's a draw");
		}
	}
}

void Game::on_hole_3_clicked() {
	if (!kalah->getWhoseTurn()) {
		kalah->makeMove(2);
		makeBoard();
	}
// if (kalah->getWhoseTurn()){
//// sleep(1);
// AIMove();
// }
	if (kalah->gameOver()) {
		if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("AI Won!");
		} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("You Won!");
		} else {
			ui->whose_turn_label->setText("It's a draw");
		}
	}
}

void Game::on_hole_4_clicked() {
	if (!kalah->getWhoseTurn()) {
		kalah->makeMove(3);
		makeBoard();
	}
// if (kalah->getWhoseTurn()){
//// sleep(1);
// AIMove();
// }
	if (kalah->gameOver()) {
		if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("AI Won!");
		} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("You Won!");
		} else {
			ui->whose_turn_label->setText("It's a draw");
		}
	}
}

void Game::on_hole_5_clicked() {
	if (!kalah->getWhoseTurn()) {
		kalah->makeMove(4);
		makeBoard();
	}
// if (kalah->getWhoseTurn()){
//// sleep(1);
// AIMove();
// }
	if (kalah->gameOver()) {
		if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("AI Won!");
		} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("You Won!");
		} else {
			ui->whose_turn_label->setText("It's a draw");
		}
	}
}

void Game::on_hole_6_clicked() {
	if (!kalah->getWhoseTurn()) {
		kalah->makeMove(5);
		makeBoard();
	}
// if (kalah->getWhoseTurn()){
//// sleep(1);
// AIMove();
// }
	if (kalah->gameOver()) {
		if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("AI Won!");
		} else if (kalah->getPoints(true) > kalah->getPoints(false)) {
			ui->whose_turn_label->setText("You Won!");
		} else {
			ui->whose_turn_label->setText("It's a draw");
		}
	}
}

void Game::on_pushButton_clicked() {
	if (kalah->getWhoseTurn() && !kalah->gameOver()) {
		AIMove();
	}
}
