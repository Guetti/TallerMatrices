#pragma once
#include "LinkedListPuzzle.h"
class PicrossSystem
{
public:
	PicrossSystem();
	int insertOption(int options);
	void readFiles();
	void mainMenu();
	void solutionsMenu();
	void puzzleMenu();
	void modifyPuzzleMenu();
	void save();
private:
	LinkedListPuzzle* puzzles;
};

