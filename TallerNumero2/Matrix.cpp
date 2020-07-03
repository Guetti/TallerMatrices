#include "Matrix.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

Matrix::Matrix()
{
}

Matrix::Matrix(int rows, int columns)
{
	this->maxHeaders = 100;
	this->rows = rows;
	this->columns = columns;
	this->size = 0;
	this->rowsHeader = new MatrixNode* [maxHeaders + 1];
	this->columnsHeader = new MatrixNode* [maxHeaders + 1];
	for (int i = 1; i <= maxHeaders; i++) {
		this->columnsHeader[i] = new MatrixNode();
		this->columnsHeader[i]->setRow(0);
		this->columnsHeader[i]->setColumn(i);
		this->columnsHeader[i]->setUp(this->columnsHeader[i]);
	}
	for (int i = 1; i <= maxHeaders; i++) {
		this->rowsHeader[i] = new MatrixNode();
		this->rowsHeader[i]->setRow(i);
		this->rowsHeader[i]->setColumn(0);
		this->rowsHeader[i]->setLeft(this->rowsHeader[i]);
	}
}

MatrixNode** Matrix::getColumnsHeader()
{
	return this->columnsHeader;
}

MatrixNode** Matrix::getRowsHeader()
{
	return this->columnsHeader;
}

void Matrix::setColumnsHeader(MatrixNode** matrixNode)
{
	this->columnsHeader = matrixNode;
}

void Matrix::setRowsHeader(MatrixNode** matrixNode)
{
	this->rowsHeader = matrixNode;
}

void Matrix::print()
{
	cout << "      ";
	for (int i = 0; i < this->columns; i++) {
		if (i + 1 >= 10) {
			std::cout << "" << i + 1;
		}
		else {
			std::cout << "" << i + 1 << " ";
		}
	}
	std::cout << std::endl;
	for (int i = 1; i <= this->rows; i++) {
		string row;
		MatrixNode* aux;
		aux = this->rowsHeader[i];
		aux = aux->getLeft();
		int emptySpaces = this->columns - aux->getColumn();
		if (i >= 10) {
			cout << "  " << i << " ";
		}
		else {
			cout << "  " << i << "  ";
		}
		while (true) {
			for (int j = 0; j < emptySpaces; j++) {
				row = "  " + row;
			}
			if (aux->getColumn() == 0) break;
			std::stringstream s;
			s << " " << char(254) << "";
			row = s.str() + row;
			emptySpaces = aux->getColumn() - aux->getLeft()->getColumn() - 1;
			aux = aux->getLeft();
		}
		cout << row << endl;
	}
}

int Matrix::getRows()
{
	return this->rows;
}

int Matrix::getColumns()
{
	return this->columns;
}

void Matrix::setRows(int rows)
{
	this->rows = rows;
}

void Matrix::setColumns(int columns)
{
	this->columns = columns;
}

bool Matrix::addNode(int value, int row, int column)
{
	if (row > this->rows || column > this->columns) {
		return false;
	}
	MatrixNode* newNode = new MatrixNode();
	newNode->setColumn(column);
	newNode->setRow(row);
	newNode->setValue(value);
	MatrixNode* auxRow = this->rowsHeader[row];
	while (auxRow->getLeft()->getColumn() > newNode->getColumn()) {
		auxRow = auxRow->getLeft();
	}
	newNode->setLeft(auxRow->getLeft());
	auxRow->setLeft(newNode);
	MatrixNode* auxColumn = this->columnsHeader[column];
	while (auxColumn->getUp()->getRow() > newNode->getRow()) {
		auxColumn = auxColumn->getUp();
	}
	newNode->setUp(auxColumn->getUp());
	auxColumn->setUp(newNode);
	return true;
}

bool Matrix::removeNode(int row, int column)
{
	MatrixNode* aux = rowsHeader[row]->getLeft();
	while (aux->getColumn() != column && aux->getColumn() != 0) {
		aux = aux->getLeft();
	}
	if (aux->getColumn() == 0) {
		return false;
	}

	MatrixNode* auxRow = rowsHeader[row];
	while (auxRow->getLeft() != aux) {
		auxRow = auxRow->getLeft();
	}
	auxRow->setLeft(aux->getLeft());

	MatrixNode* auxColumn = columnsHeader[column];
	while (auxColumn->getUp() != aux) {
		auxColumn = auxColumn->getUp();
	}
	auxColumn->setUp(aux->getUp());
	delete aux;
	return true;
}

bool Matrix::expand(int rows, int columns)
{
	if (this->rows + rows > maxHeaders || this->columns + columns > maxHeaders) {
		cout << "\tExcede limite de filas o columnas" << endl;
		return false;
	}
	if (this->rows + rows <= 0 || this->columns + columns <= 0) {
		cout << "\tNo es posible dejar una matriz con valores menores o iguales a cero" << endl;
		return false;
	}
	int oldRows = this->rows;
	this->rows = this->rows + rows;

	if (rows < 0) {
		for (int i = 1; i <= this->columns; i++) {
			for (int j = this->rows; j <= oldRows; j++) {
				removeNode(j, i);
			}
		}
	}

	int oldColumns = this->columns;
	this->columns = this->columns + columns;

	if (columns < 0) {
		for (int i = 1; i <= this->rows; i++) {
			for (int j = this->columns; j <= oldColumns; j++) {
				removeNode(i, j);
			}
		}
	}

	return true;
}

MatrixNode* Matrix::searchNode(int row, int column)
{
	MatrixNode* aux;
	aux = this->rowsHeader[row];
	aux = aux->getLeft();
	while (aux->getColumn() != 0 && aux->getColumn() != column) {
		aux = aux->getLeft();
	}
	return aux;
}

Matrix::~Matrix()
{
}
