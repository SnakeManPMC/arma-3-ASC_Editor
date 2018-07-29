#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "heightmap.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("ASC Editor " + pmcVersion + " (c) PMC");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionOpen_CTRL_O_triggered()
{
	myMap->loadAsc();
}

void MainWindow::on_actionSave_CTRL_S_triggered()
{
	myMap->saveAsc();
}

void MainWindow::on_actionAbout_triggered()
{
	QMessageBox *msgBox = new QMessageBox;
	msgBox->setText("ASC Editor " + pmcVersion + " (c) PMC");
	msgBox->exec();
}

void MainWindow::on_actionNew_CTRL_N_triggered()
{
	createNewDialog *myNewHm = new createNewDialog;
	myNewHm->exec();
	myMap->setGridSize(myNewHm->GridSize());
	myMap->setCellSize(myNewHm->CellSize());
	myMap->setUserElevation(myNewHm->BaseElevation());
	myMap->doElevations();
}

void MainWindow::on_actionElevations_triggered()
{

}

void MainWindow::on_actionExit_CTRL_Q_triggered()
{
	QApplication::quit();
}
