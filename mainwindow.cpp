#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	ui->label_2->setPixmap(QPixmap("../Resources/background.jpeg"));
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_vs_computer_button_clicked() {
	form = new VSComputerForm(this);
	form->setModal(true);
	form->show();
}

void MainWindow::on_toolButton_clicked() {
    QDesktopServices::openUrl(QUrl("https://mancala.fandom.com/wiki/Kalah"));
}

