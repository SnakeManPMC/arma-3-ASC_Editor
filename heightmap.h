#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <QMainWindow>

class heightMap : public QMainWindow
{
	Q_OBJECT
public:
	explicit heightMap(QWidget *parent = nullptr);
	void setNcols(int mySize);
	void setNrows(int mySize);
	void setGridSize(int mySize);
	void setCellSize(int mySize);
	void setYllcorner(float mySize);
	void setXllcorner(float mySize);
	void setNoDataValue(int mySize);
	void setUserElevation(int mySize);
	void loadAsc();
	void saveAsc();
	void doElevations();

signals:

public slots:

private:
	int ncols, nrows, gridSize, cellSize, noDataValue, userElevation;
	QString hmHeader;
	void setHeader();
	float xllcorner, yllcorner;
	QVector<int> Elevations;
	void createMsgBox(QString msg);
};

#endif // HEIGHTMAP_H
