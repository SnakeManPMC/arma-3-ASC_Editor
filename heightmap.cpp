#include "heightmap.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

heightMap::heightMap(QWidget *parent) : QMainWindow(parent)
{
	setXllcorner(200000);
	setYllcorner(0);
	setNoDataValue(-300);
	setGridSize(8);
	setUserElevation(-50);
}

void heightMap::setNcols(int mySize)
{
	ncols = mySize;
}

void heightMap::setNrows(int mySize)
{
	nrows = mySize;
}

void heightMap::setGridSize(int mySize)
{
	gridSize = mySize;
	setNcols(mySize);
	setNrows(mySize);
}

void heightMap::setCellSize(int mySize)
{
	cellSize = mySize;
}

void heightMap::setYllcorner(float mySize)
{
	yllcorner = mySize;
}

void heightMap::setXllcorner(float mySize)
{
	xllcorner = mySize;
}

void heightMap::setNoDataValue(int mySize)
{
	noDataValue = mySize;
}

void heightMap::setUserElevation(int mySize)
{
	userElevation = mySize;
}

void heightMap::setHeader()
{
	hmHeader = "ncols ";
	hmHeader.append(QString::number(ncols));
	hmHeader.append("\nnrows ");
	hmHeader.append(QString::number(nrows));
	hmHeader.append("\nxllcorner " + QString::number(xllcorner) + "\nyllcorner " + QString::number(yllcorner) + "\n");
	hmHeader.append("cellsize " + QString::number(cellSize) + "\nnodata_value " + QString::number(noDataValue) + "\n");
}

void heightMap::loadAsc()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("ASC"), "", tr("ASC files (*.asc)"));
	if (fileName.isEmpty())
	{
		createMsgBox("Opening file for loading failed, sorry!");
	}
	else
	{
		QStringList list;
		QString line;

		QFile ascLoadFile (fileName);
		ascLoadFile.open(QIODevice::ReadOnly);
		QTextStream out(&ascLoadFile);

		// header ncols
		line = out.readLine();
		list = line.split(" ", QString::SkipEmptyParts);
		line = list[1];
		setNcols(line.toInt());

		// nrows
		line = out.readLine();
		list = line.split(" ", QString::SkipEmptyParts);
		line = list[1];
		setNrows(line.toInt());

		// xllcorner
		line = out.readLine();
		list = line.split(" ", QString::SkipEmptyParts);
		line = list[1];
		setXllcorner(line.toInt());

		// yllcorner
		line = out.readLine();
		list = line.split(" ", QString::SkipEmptyParts);
		line = list[1];
		setYllcorner(line.toInt());

		// cell size
		line = out.readLine();
		list = line.split(" ", QString::SkipEmptyParts);
		line = list[1];
		setCellSize(line.toInt());

		// nodata_value
		line = out.readLine();
		list = line.split(" ", QString::SkipEmptyParts);
		line = list[1];
		setNoDataValue(line.toInt());

		setHeader();

		// elevation meters
		for (int i=0; i<ncols; i++)
		{
			line = out.readLine();
			list = line.split(" ", QString::SkipEmptyParts);

			for (int ix=0; ix<nrows; ix++)
			{
				line = list[ix];
				int myNum = line.toInt();
				Elevations.append(myNum);
			}
		}

		ascLoadFile.close();
	}

	createMsgBox("Load ASC Complete!");
}

void heightMap::saveAsc()
{
	setHeader();

	QString fileName = QFileDialog::getSaveFileName(this, tr("ASC"), "", tr("ASC files (*.asc)"));
	if (fileName.isEmpty())
	{
		createMsgBox("Opening file for saving failed, sorry!");
	}
	else
	{
		QFile ascSaveFile (fileName);
		ascSaveFile.open(QIODevice::WriteOnly);
		QTextStream out(&ascSaveFile);

		out << hmHeader;

		int cx = 0;
		for (int i=0; i<ncols; i++)
		{
			for (int ix=0; ix<nrows; ix++)
			{
				out << Elevations.at(cx) << " ";
				cx++;
			}
			out << endl;
		}

		ascSaveFile.close();
	}

	createMsgBox("Save ASC Complete!");
}


void heightMap::doElevations()
{
	int cx = 0;
	for (int i=0; i<ncols; i++)
	{
		for (int ix=0; ix<nrows; ix++)
		{
			Elevations.append(userElevation);
			cx++;
		}
	}
}


void heightMap::createMsgBox(QString msg)
{
	QMessageBox *myBox = new QMessageBox();
	myBox->resize(400,100);
	myBox->setWindowTitle("ASC Editor");
	myBox->setText(msg);
	myBox->exec();
}
