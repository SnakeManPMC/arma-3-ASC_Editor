#ifndef CREATENEWDIALOG_H
#define CREATENEWDIALOG_H

#include <QDialog>

namespace Ui {
class createNewDialog;
}

class createNewDialog : public QDialog
{
	Q_OBJECT

public:
	explicit createNewDialog(QWidget *parent = nullptr);
	~createNewDialog();
	int GridSize();
	int CellSize();
	int BaseElevation();

private slots:
	void on_buttonBox_accepted();

	void on_buttonBox_rejected();

private:
	Ui::createNewDialog *ui;
};

#endif // CREATENEWDIALOG_H
