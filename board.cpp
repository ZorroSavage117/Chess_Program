/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "position.h"
#include "piece.h"
#include <cassert>
using namespace std;


// we really REALLY need to delete this.
Space space;

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
//const Piece& Board::operator [] (const Position& pos) const
//{
//   return space;
//}
//Piece& Board::operator [] (const Position& pos)
//{
//   return space;
//}
Piece& Board::operator[](const Position& pos) {
	assert(pos.isValid());  // Ensure the position is valid
	return *board[pos.getCol()][pos.getRow()];  // Return reference to the Piece at the specified position
}
const Piece& Board::operator[](const Position& pos) const {
	assert(pos.isValid());  // Ensure the position is valid
	return *board[pos.getCol()][pos.getRow()];  // Return const reference to the Piece at the specified position
}


/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr)
{
   pSpace = new Space;
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}