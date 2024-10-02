/***********************************************************************
 * Header File:
 *    MOVE 
 * Author:
 *    Arlo Jolley
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;
enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   /*enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };*/

   friend TestMove;
   friend TestBoard;

   // constructors
   Move();
   Move(string smith, bool white);
   Move(Position s, Position d, MoveType m, PieceType cap, PieceType pro, bool white);

   // methods
   Position getSource();
   void setSource(Position s);
   Position getDest();
   void setDest(Position d);
   PieceType getPromote();
   void setPromote(PieceType pro);
   PieceType getCapture();
   void setCapture(PieceType cap);
   MoveType getMoveType();
   void setMoveType(MoveType m);
   bool getIsWhite();
   void setIsWhite(bool w);
   string getText();
   void setText(string smith);


private:
	char letterFromPieceType(PieceType pt)     const;
	PieceType pieceTypeFromLetter(char letter) const;



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


