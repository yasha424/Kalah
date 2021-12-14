#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include "vscomputerform.h"

QT_BEGIN_NAMESPACE namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE class MainWindow: public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_vs_computer_button_clicked();

    void on_toolButton_clicked();

private:
	Ui::MainWindow *ui;
	VSComputerForm *form;
};
#endif // MAINWINDOW_H
