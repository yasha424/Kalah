#include "vscomputerform.h"
#include "ui_vscomputerform.h"

VSComputerForm::VSComputerForm(QWidget *parent): QDialog(parent), ui(new Ui::VSComputerForm) {
	ui->setupUi(this);
	ui->label_2->setPixmap(QPixmap("../Resources/irobot.jpg"));
}

VSComputerForm::~VSComputerForm() {
	delete ui;
}

void VSComputerForm::on_easy_button_clicked() {
	game = new Game(1, ui->checkBox->isChecked(), ui->spinBox->value(), this);
	game->setModal(true);
	game->show();
}

void VSComputerForm::on_medium_button_clicked() {
	game = new Game(6, ui->checkBox->isChecked(), ui->spinBox->value(), this);
	game->setModal(true);
	game->show();
}

void VSComputerForm::on_hard_button_clicked() {
    game = new Game(10, ui->checkBox->isChecked(), ui->spinBox->value(), this);
    game->setModal(true);
    game->show();
}
