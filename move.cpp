/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
	source = Position();
	dest = Position();
	promote = SPACE;
	capture = SPACE;
	moveType = MOVE_ERROR;
	isWhite = true;
	text = "";
}

char Move::letterFromPieceType(PieceType pt) const
{
	switch (pt) {
	case PAWN:    return 'p';
	case KNIGHT:  return 'n';
	case BISHOP:  return 'b';
	case ROOK:    return 'r';
	case QUEEN:   return 'q';
	case KING:    return 'k';
	default:      return ' ';
	}
}

PieceType Move::pieceTypeFromLetter(char letter) const
{
	switch (letter) {
	case 'p': return PAWN;
	case 'n': return KNIGHT;
	case 'b': return BISHOP;
	case 'r': return ROOK;
	case 'q': return QUEEN;
	case 'k': return KING;
	default:  return SPACE;
	}
}


