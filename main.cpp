#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;

	w.setStyleSheet("QPushButton:pressed { border-style:solid; border-width:2px; }"
		"QPushButton:hover:!pressed { border: 2px solid green; }");
	w.show();
	return a.exec();
}
