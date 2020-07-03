#pragma once
#include "Puzzle.h"
class PuzzleNode
{
private:
	Puzzle* puzzle;
	PuzzleNode* next;

public:
	PuzzleNode();
	PuzzleNode(Puzzle* puzzle);
	Puzzle* getPuzzle();
	void setPuzzle(Puzzle* puzzle);
	PuzzleNode* getNext();
	void setNext(PuzzleNode* puzzle);

};