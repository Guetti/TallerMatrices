#pragma once
class MatrixNode
{
private:
	MatrixNode* left;
	MatrixNode* up;
	int value;
	int row;
	int column;
public:
	MatrixNode();
	MatrixNode(int value, int row, int column);
	MatrixNode* getLeft();
	MatrixNode* getUp();
	int getValue();
	int getRow();
	int getColumn();
	void setLeft(MatrixNode* matrixNode);
	void setUp(MatrixNode* matrixNode);
	void setValue(int value);
	void setRow(int row);
	void setColumn(int column);
	~MatrixNode();
};

