#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "heightmap.h"
#include "createnewdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_actionOpen_CTRL_O_triggered();

	void on_actionSave_CTRL_S_triggered();

	void on_actionAbout_triggered();

	void on_actionNew_CTRL_N_triggered();

	void on_actionElevations_triggered();

	void on_actionExit_CTRL_Q_triggered();

private:
	Ui::MainWindow *ui;
	heightMap *myMap = new heightMap;
	QString pmcVersion = "v0.0.1";
};

#endif // MAINWINDOW_H
