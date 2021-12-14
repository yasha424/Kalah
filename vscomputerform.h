#ifndef VSCOMPUTERFORM_H
#define VSCOMPUTERFORM_H

#include <QDialog>
#include "game.h"
namespace Ui {
class VSComputerForm;
}

class VSComputerForm: public QDialog {
	Q_OBJECT

public:
	explicit VSComputerForm(QWidget *parent = nullptr);
	~VSComputerForm();

private slots:
	void on_easy_button_clicked();
	void on_medium_button_clicked();
	void on_hard_button_clicked();

private:
	Ui::VSComputerForm *ui;
	Game *game;
};

#endif // VSCOMPUTERFORM_H
