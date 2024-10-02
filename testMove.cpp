/***********************************************************************
 * Header File:
 *    TEST MOVE 
 * Author:
 *    Arlo Jolley
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input: 
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default() 
{
	Move move;
	assertUnit(move.getSource() == INVALID);
	assertUnit(move.getDest() == INVALID);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
	Move move('e5e6');
	assertUnit(move.getSource() == '4,4');
	assertUnit(move.getDest() == '4,5');
	//assertUnit(move.getMoveType() == Move::MOVE);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ simple move 
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
	Move move;
	string input = "e5e6";
	move.source = Position(4, 4);  // e5 -> (4,4)
	move.dest = Position(4, 5);    // e6 -> (4,5)
	move.moveType = Move::MOVE;
	assertUnit(move.source == Position(4, 4));
	assertUnit(move.dest == Position(4, 5));
	assertUnit(move.moveType == Move::MOVE);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ capture move 
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::read_capture()
{
	Move move;
	string input = "e5d6r";
	move.source = Position(4, 4);  // e5 -> (4,4)
	move.dest = Position(3, 5);    // d6 -> (3,5)
	move.capture = ROOK;           // captured a rook
	move.moveType = Move::MOVE;
	assertUnit(move.source == Position(4, 4));
	assertUnit(move.dest == Position(3, 5));
	assertUnit(move.capture == ROOK);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ enpassant move 
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::read_enpassant()
{
	Move move;
	string input = "e5f6E";
	move.source = Position(4, 4);  // e5 -> (4,4)
	move.dest = Position(5, 5);    // f6 -> (5,5)
	move.moveType = Move::ENPASSANT;
	assertUnit(move.source == Position(4, 4));
	assertUnit(move.dest == Position(5, 5));
	assertUnit(move.moveType == Move::ENPASSANT);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::read_castleKing()
{
	Move move;
	string input = "e1g1c";
	move.source = Position(4, 0);  // e1 -> (4,0)
	move.dest = Position(6, 0);    // g1 -> (6,0)
	move.moveType = Move::CASTLE_KING;
	assertUnit(move.source == Position(4, 0));
	assertUnit(move.dest == Position(6, 0));
	assertUnit(move.moveType == Move::CASTLE_KING);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::read_castleQueen()
{
	Move move;
	string input = "e1c1C";
	move.source = Position(4, 0);  // e1 -> (4,0)
	move.dest = Position(2, 0);    // c1 -> (2,0)
	move.moveType = Move::CASTLE_QUEEN;
	assertUnit(move.source == Position(4, 0));
	assertUnit(move.dest == Position(2, 0));
	assertUnit(move.moveType == Move::CASTLE_QUEEN);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
	Move move;
	move.source = Position(4, 4);  // e5
	move.dest = Position(4, 5);    // e6
	move.moveType = Move::MOVE;
	assertUnit(move.source == Position(4, 4));
	assertUnit(move.dest == Position(4, 5));
	assertUnit(move.moveType == Move::MOVE);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
	Move move;
	move.source = Position(4, 4);   // e5
	move.dest = Position(3, 5);     // d6
	move.capture = ROOK;            // captured a rook
	move.moveType = Move::MOVE;
	assertUnit(move.source == Position(4, 4));
	assertUnit(move.dest == Position(3, 5));
	assertUnit(move.capture == ROOK);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
	Move move;
	move.source = Position(4, 0);  // e1
	move.dest = Position(6, 0);    // g1
	move.moveType = Move::ENPASSANT;
	assertUnit(move.source == Position(4, 0));
	assertUnit(move.dest == Position(6, 0));
	assertUnit(move.moveType == Move::ENPASSANT);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::assign_castleKing()
{
	Move move;
	move.source = Position(4, 0);  // e1
	move.dest = Position(6, 0);    // g1
	move.moveType = Move::CASTLE_KING;
	assertUnit(move.source == Position(4, 0));
	assertUnit(move.dest == Position(6, 0));
	assertUnit(move.moveType == Move::CASTLE_KING);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
	Move move;
	move.source = Position(4, 0);  // e1
	move.dest = Position(6, 0);    // g1
	move.moveType = Move::CASTLE_QUEEN;
	assertUnit(move.source == Position(4, 0));
	assertUnit(move.dest == Position(6, 0));
	assertUnit(move.moveType == Move::CASTLE_QUEEN);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Output:  e5e6
  **************************************/
void TestMove::getText_simple()
{
	Move move;
	move.source = Position(4, 4); // e5
	move.dest = Position(4, 5);   // e6
	move.moveType = Move::MOVE;
	move.text = "e5e6";
	assertUnit(move.text == "e5e6");
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Output:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
    assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Output:  e5f6E
  **************************************/
void TestMove::getText_enpassant()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT king side castle
  * Input : source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  * Output:  e1g1c
  **************************************/
void TestMove::getText_castleKing()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT queen side castle
  * Input : source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN  
  * Output:  e1c1C
  **************************************/
void TestMove::getText_castleQueen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
	Move move;
	assertUnit(move.letterFromPieceType(SPACE) == ' ');
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
	Move move;
	assertUnit(move.letterFromPieceType(PAWN) == 'p');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
	Move move;
	assertUnit(move.letterFromPieceType(BISHOP) == 'b');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
	Move move;
	assertUnit(move.letterFromPieceType(KNIGHT) == 'n');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
	Move move;
	assertUnit(move.letterFromPieceType(ROOK) == 'r');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
	Move move;
	assertUnit(move.letterFromPieceType(QUEEN) == 'q');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
	Move move;
	assertUnit(move.letterFromPieceType(KING) == 'k');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('p') == PAWN);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('b') == BISHOP);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Output:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('n') == KNIGHT);
    //assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Output:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('r') == ROOK);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Output:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('q') == QUEEN);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Output:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king() 
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('k') == KING);
	//assertUnit(NOT_YET_IMPLEMENTED);
}


 /*************************************
  * EQUAL - NOT
  * Input : b2b4 == b2b5
  * Output: false
  **************************************/
void TestMove::equal_not()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * EQUAL - EQUALS
  * Input : b2b4 == b2b4
  * Output: false
  **************************************/
void TestMove::equal_equals()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LESS THAN - LESS THAN
  * Input : b2b2 < b2b4
  * Output: false
  **************************************/
void TestMove::lessthan_lessthan()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LESS THAN - EQUALS
  * Input : b2b4 < b2b4
  * Output: false
  **************************************/
void TestMove::lessthan_equals()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LESS THAN - GREATAER THAN
  * Input : b2b4 < b2b2
  * Output: false
  **************************************/
void TestMove::lessthan_greaterthan()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}
