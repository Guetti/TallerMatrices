#include "Puzzle.h"

Puzzle::Puzzle()
{
	this->name = "UNNAMED";
	this->matrix = nullptr;
}

Puzzle::Puzzle(string name, Matrix* matrix)
{
	this->name = name;
	this->matrix = matrix;
}

string Puzzle::getName()
{
	return this->name;
}

void Puzzle::setName(string name)
{
	this->name = name;
}

Matrix* Puzzle::getMatrix()
{
	return this->matrix;
}

void Puzzle::setMatrix(Matrix* matrix)
{
	this->matrix = matrix;
}
