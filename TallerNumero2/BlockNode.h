#pragma once
class BlockNode
{
private:
	int value;
	BlockNode* left;
	BlockNode* up;
	int row;
	int column;
public:
	BlockNode(int row, int column, BlockNode blockNode, BlockNode up);
	int getValue();
	void setValue(int value);
	BlockNode getLeft();
	void setLeft(BlockNode blockNode);
	BlockNode getUp();
	void setUp(BlockNode blockNode);
	int getRow();
	void setRow(int row);
	int getColumn();
	void setColumn(int column);
};

