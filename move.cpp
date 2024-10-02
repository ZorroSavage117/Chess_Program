/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    Arlo Jolley
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
	source = INVALID;
	dest = INVALID;
	promote = SPACE;
	capture = SPACE;
	moveType = MOVE_ERROR;
	isWhite = true;
	text = "";
}

Move::Move(string smith, bool white = true)
{
	source = smith.substr(0,2);
	dest = smith.substr(2,2);
	if (smith.length() > 4)
	{
		if (smith.length() == 5) // promote or capture
		{
			char action = smith[4];
			switch (action)
			{
				case 'p' :
					promote = SPACE;
					capture = PAWN;
					moveType = MOVE;
					break;
				case 'n':
					promote = SPACE;
					capture = KNIGHT;
					moveType = MOVE;
					break;
				case 'b':
					promote = SPACE;
					capture = BISHOP;
					moveType = MOVE;
					break;
				case 'r':
					promote = SPACE;
					capture = ROOK;
					moveType = MOVE;
					break;
				case 'q':
					promote = SPACE;
					capture = QUEEN;
					moveType = MOVE;
					break;
				case 'k':  // place holder and end game condition
					promote = SPACE;
					capture = KING;
					moveType = MOVE;
					break;
				case 'c':
					promote = SPACE;
					capture = SPACE;
					moveType = CASTLE_KING;
					break;
				case 'C':
					promote = SPACE;
					capture = SPACE;
					moveType = CASTLE_QUEEN;
					break;
				case 'E':
					promote = SPACE;
					capture = PAWN;
					moveType = ENPASSANT;
					break;
				case 'N':
					promote = KNIGHT;
					capture = SPACE;
					moveType = MOVE;
					break;
				case 'B':
					promote = BISHOP;
					capture = SPACE;
					moveType = MOVE;
					break;
				case 'R':
					promote = ROOK;
					capture = SPACE;
					moveType = MOVE;
					break;
				case 'Q':
					promote = QUEEN;
					capture = SPACE;
					moveType = MOVE;
					break;
				default:
					promote = SPACE;
					capture = SPACE;
					moveType = MOVE_ERROR;
			}
		}
		else // capture and promote
		{
			string action = smith.substr(4, 2);
			if (action == "pQ" || action == "Qp")
			{
				promote = QUEEN;
				capture = PAWN;
				moveType = MOVE;
			}
			else if (action == "nQ" || action == "Qn")
			{
				promote = QUEEN;
				capture = KNIGHT;
				moveType = MOVE;
			}
			else if (action == "bQ" || action == "Qb")
			{
				promote = QUEEN;
				capture = BISHOP;
				moveType = MOVE;
			}
			else if (action == "rQ" || action == "Qr")
			{
				promote = QUEEN;
				capture = ROOK;
				moveType = MOVE;
			}
			else if (action == "qQ" || action == "Qq")
			{
				promote = QUEEN;
				capture = QUEEN;
				moveType = MOVE;
			}
		}
	}
	else // no promote or capture
	{
		promote = SPACE;
		capture = SPACE;
		moveType = MOVE;
	}
	isWhite = white;
	text = smith;
}

Position Move::getSource()
{
	return source;
}

void Move::setSource(Position s)
{
	source = s;
}

Position Move::getDest()
{
	return dest;
}

void Move::setDest(Position d)
{
	dest = d;
}

PieceType Move::getPromote()
{
	return promote;
}

void Move::setPromote(PieceType pro)
{
	promote = pro;
}

PieceType Move::getCapture()
{
	return capture;
}

void Move::setCapture(PieceType cap)
{
	capture = cap;
}

//MoveType Move::getMoveType()
//{
//	return moveType;
//}

void Move::setMoveType(MoveType m)
{
	moveType = m;
}

bool Move::getIsWhite()
{
	return isWhite;
}

void Move::setIsWhite(bool w)
{
	isWhite = w;
}

string Move::getText()
{
	return text;
}

void Move::setText(string t)
{
	text = t;
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




