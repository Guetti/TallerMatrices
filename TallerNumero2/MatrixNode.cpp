#include "MatrixNode.h"

MatrixNode::MatrixNode()
{
    this->value = 0;
    this->row = 0;
    this->column = 0;
    this->left = nullptr;
    this->up = nullptr;
}

MatrixNode::MatrixNode(int value, int row, int column)
{
    this->value = value;
    this->row = row;
    this->column = column;
    this->left = nullptr;
    this->up = nullptr;
}

MatrixNode* MatrixNode::getLeft()
{
    return this->left;
}

MatrixNode* MatrixNode::getUp()
{
    return this->up;
}

int MatrixNode::getValue()
{
    return this->value;
}

int MatrixNode::getRow()
{
    return this->row;
}

int MatrixNode::getColumn()
{
    return this->column;
}

void MatrixNode::setLeft(MatrixNode* matrixNode)
{
    this->left = matrixNode;
}

void MatrixNode::setUp(MatrixNode* matrixNode)
{
    this->up = matrixNode;
}

void MatrixNode::setValue(int value)
{
    this->value = value;
}

void MatrixNode::setRow(int row)
{
    this->row = row;
}

void MatrixNode::setColumn(int column)
{
    this->column = column;
}

MatrixNode::~MatrixNode()
{

}
