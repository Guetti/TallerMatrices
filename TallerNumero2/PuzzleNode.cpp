#include "PuzzleNode.h"

PuzzleNode::PuzzleNode()
{
    this->puzzle = nullptr;
    this->next = nullptr;
}

PuzzleNode::PuzzleNode(Puzzle* puzzle)
{
    this->puzzle = puzzle;
    this->next = nullptr;
}

Puzzle* PuzzleNode::getPuzzle()
{
    return this->puzzle;
}

void PuzzleNode::setPuzzle(Puzzle* puzzle)
{
    this->puzzle = puzzle;
}

PuzzleNode* PuzzleNode::getNext()
{
    return this->next;
}

void PuzzleNode::setNext(PuzzleNode* puzzleNode)
{
    this->next = puzzleNode;
}
