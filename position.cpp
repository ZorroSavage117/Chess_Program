/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

 /******************************************
  * POSITION INSERTION OPERATOR
  ******************************************/
ostream& operator << (ostream& out, const Position& rhs)
{
   out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream& operator >> (istream& in, Position& rhs)
{
   return in;
}

/*************************************
 * POSITION CONSTRUCTOR GIVEN CHAR
 **************************************/
Position::Position(const char* s) : colRow(0x99) {
   if (s != nullptr && strlen(s) >= 2) {
      char colChar = s[0];
      char rowChar = s[1];

      // Handle column character
      int col;
      if (colChar >= 'a' && colChar <= 'h') {
         col = colChar - 'a';
      }
      else if (colChar >= 'A' && colChar <= 'H') {
         col = colChar - 'A';
      }
      else {
         colRow = 0x99; // Invalid
         return;
      }

      // Handle row character
      int row;
      if (rowChar >= '1' && rowChar <= '8') {
         row = rowChar - '1';
      }
      else {
         colRow = 0x99; // Invalid
         return;
      }

      // Set colRow
      colRow = (col << 4) | row;
   }
   else {
      colRow = 0x99; // Invalid
   }
}