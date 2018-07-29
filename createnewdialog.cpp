#include "createnewdialog.h"
#include "ui_createnewdialog.h"

createNewDialog::createNewDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::createNewDialog)
{
	ui->setupUi(this);
}

createNewDialog::~createNewDialog()
{
	delete ui;
}

void createNewDialog::on_buttonBox_accepted()
{
}

void createNewDialog::on_buttonBox_rejected()
{
}

int createNewDialog::GridSize()
{
	return ui->lineEditGridSize->text().toInt();
}

int createNewDialog::CellSize()
{
	return ui->lineEditCellSize->text().toInt();
}

int createNewDialog::BaseElevation()
{
	return ui->lineEditBaseElevation->text().toInt();
}
