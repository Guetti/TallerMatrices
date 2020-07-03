#pragma once
#include "PuzzleNode.h"
class LinkedListPuzzle
{
private:
	PuzzleNode* head;
	int size;
public:
	LinkedListPuzzle();
	LinkedListPuzzle(PuzzleNode* puzzleNode);
	PuzzleNode* getHead();
	void setHead(PuzzleNode* puzzleNode);
	int getSize();
	void setSize(int size);
	bool insert(PuzzleNode* puzzleNode);
};

