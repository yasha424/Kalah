#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QMessageBox>
#include <unistd.h>
#include "board.h"

namespace Ui {
class Game;
}

class Game: public QDialog {
	Q_OBJECT

public:
	explicit Game(int depth, bool first_move, int count_of_stones, QWidget *parent = nullptr);
	~Game();
	void makeBoard();
	void endGame();
    void playMusic();

private slots:
	void on_hole_1_clicked();
	void AIMove();
	void on_hole_2_clicked();
	void on_hole_3_clicked();
	void on_hole_4_clicked();
	void on_hole_5_clicked();
	void on_hole_6_clicked();
	void on_pushButton_clicked();

private:
	Ui::Game *ui;
	int depth;
	Kalah *kalah;
	bool first_move;
};

#endif // GAME_H
