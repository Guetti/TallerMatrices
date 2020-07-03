#pragma once
#include "MatrixNode.h"
class Matrix
{
private:
	MatrixNode** columnsHeader;
	MatrixNode** rowsHeader;
	int size;
	int rows;
	int columns;
	int maxHeaders;
public:
	Matrix();
	Matrix(int rows, int columns);
	MatrixNode** getColumnsHeader();
	MatrixNode** getRowsHeader();
	void setColumnsHeader(MatrixNode** matrixNode);
	void setRowsHeader(MatrixNode** matrixNode);
	void print();
	int getRows();
	int getColumns();
	void setRows(int rows);
	void setColumns(int columns);
	bool addNode(int value, int row, int column);
	bool removeNode(int row, int column);
	bool expand(int rows, int columns);
	MatrixNode* searchNode(int row, int column);
	~Matrix();
};

