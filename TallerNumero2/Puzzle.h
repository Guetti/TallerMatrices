#pragma once

#include <string>
#include "Matrix.h"
using namespace std;
class Puzzle
{
private:
	string name;
	Matrix* matrix;
public:
	Puzzle();
	Puzzle(string name, Matrix* matrix);
	string getName();
	void setName(string name);
	Matrix* getMatrix();
	void setMatrix(Matrix* matrix);

};


