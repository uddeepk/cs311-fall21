// hdtcount.cpp
// Uddeep Karki
// Created: 2021-09-24
// Updated: 2021-09-25
// 
// For CS 311 Fall 2021
// Project 4: counting "holey domino tilings"
// Source file for hdtCount

#include "hdtcount.h" // header for counting "holey domino tilings"
#include <cassert> // For assert
#include <vector> // For vector
using std::vector;
#include <cstddef> // For size_t
using std::size_t;


using MyBoardType = vector<vector<int>>;

// checkBoard
// given partial solution to "holey domino tilings" problem,
// dimensions of the board, and co-ordinates of the current tile
// it returns true if full solution possible
// Pre:
//     board is of type vector<vector<int>>
//     dim_x == board.size() && dim_y == board[0].size()
//     0 <= curr_x < dim_x && 0 <= curr_y < dim_y
// Exception free
bool checkBoard (const MyBoardType &board,
		 int dim_x, int dim_y,
		 int curr_x, int curr_y)
{
    assert(static_cast<size_t>(dim_x) == board.size() &&
	   static_cast<size_t>(dim_y) == board[0].size());
    assert(0 <= curr_x && curr_x < dim_x);
    assert(0 <= curr_y && curr_y < dim_y);
    for (int i = 0 ; i < dim_x ; ++i ) {
	for (int j = 0 ; j < dim_y ; ++j) {
	    if ((i * dim_y + j) >= (curr_x * dim_y + curr_y))
		return true;
	    else {
		if (board[i][j]==0)
		    return false;
	    }
	}
    }
    return true;
}


// popDomino
// given partial solution to "holey domino tilings" problem,
// dimensions of the board, and co-ordinates for the domino piece,
// it removes the positions as used and reduces squares left by 2
// Pre:
//     board is of type vector<vector<int>>
//     board.size() == dim_x && board[0].size() == dim_y
//     0 <= x1,x2 < dim_x
//     0 <= y1,y2 < dim_y
//     squaresLeft >= 0
// Exception free
void popDomino (MyBoardType &board,
		int dim_x, int dim_y,
		int x1, int y1,
		int x2, int y2,
		int &squaresLeft)
{
    assert(board.size() == static_cast<size_t> (dim_x) &&
	   board[0].size() == static_cast<size_t>(dim_y));
    assert(0 <= x1 && x1 < dim_x && 0 <= y1 && y1 < dim_y);
    assert(0 <= x2 && x2 < dim_x && 0 <= y2 && y2 < dim_y);
    assert(squaresLeft >= 0 && squaresLeft <= dim_x * dim_y - 2 );
    --board[x1][y1];
    --board[x2][y2];
    squaresLeft += 2;
}


// placeDomino
// Given partial solution to "holey domino tilings" problem,
// dimensions of the board, and co-ordinates for the domino piece,
// marks those positions on the board and reduces squares left by 2
// Pre:
//     board is of type vector<vector<int>>
//     board.size() == dim_x && board[0].size() == dim_y
//     0 <= x1,x2 < dim_x
//     0 <= y1,y2 < dim_y
//     squaresLeft > 1
// Exception free
void placeDomino (MyBoardType &board,
                  int dim_x, int dim_y,
                  int x1, int y1,
                  int x2, int y2,
                  int &squaresLeft)
{
    assert(board.size() == static_cast<size_t>(dim_x) &&
	   board[0].size() == static_cast<size_t>(dim_y));
    assert(0 <= x1 && x1 < dim_x && 0 <= y1 && y1 < dim_y);
    assert(0 <= x2 && x2 < dim_x && 0 <= y2 && y2 < dim_y);
    assert(squaresLeft > 1);
    ++board[x1][y1];
    ++board[x2][y2];
    squaresLeft -= 2;                
}



// checkDomino
// Given partial solution to the "holey domino tilings" problem,
// dimensions of the board, and proposed new tile placement is
// acceptable, i.e. it doesn't fall in any of the used positions
// Pre:
//     board is of type vector<vector<int>>
//     board.size() == dim_x && board[0].size() == dim_y
//     board represents a placement of dominos and forbidden squares
//     size_x, size_y > 0
//     0 <= x1 , y1, x2, y2
// Exception free
bool checkDomino ( const MyBoardType &board,
	           int dim_x, int dim_y,
	           int x1, int y1,
	           int x2, int y2)
{
    assert(board.size() == static_cast<size_t>(dim_x) &&
	   board[0].size() == static_cast<size_t>(dim_y));
    assert(0 <= x1 && 0 <= y1);
    assert(0 <= x2 && 0 <= y2);
    
    if(x1 < dim_x && y1 < dim_y && x2 < dim_x && y2 < dim_y) {
	return !(board[x1][y1] || board[x2][y2]);
    } else
	return false;
}




// hdtCount_recurse
// Given a partial solution to the "holey domino tilings returns the
// number of full solutions.
// Recursive workhorse function
// Pre:
//     board is type vector<vector<int>>
//     board.size() == dim_y && board[0].size() == dim_x
//     0 <= squaresLeft <= dim_x * dim_y - 2
//     0 <= curr_x < dim_x && 0 <= curr_y < dim_y
// Exception free
int hdtCount_recurse(MyBoardType &board,
		     int dim_x, int dim_y,
		     int curr_x, int curr_y,
		     int squaresLeft)
{
    assert(board.size() == static_cast<size_t>(dim_x) &&
	   board[0].size() == static_cast<size_t>(dim_y));
    assert(0 <= curr_x && curr_x < dim_x);
    assert(0 <= curr_y && curr_y < dim_y);
    assert(0 <= squaresLeft && squaresLeft <= dim_x * dim_y - 2);

    // BASE CASES
    if (squaresLeft == 0)
	return 1; // We have a full solution

    if (!checkBoard(board,
		    dim_x,  dim_y,
		    curr_x,  curr_y))
	return 0; // We would have no solution
    
    int total = 0;
    // Recursive Case
    
    // FInd first not-yet covered square
    for (int x = 0 ; x < dim_x ; ++x)
    {
	for (int y = 0 ; y < dim_y ; ++y) {
	    
	    // Try horizontal domino
	    //     Mark two squares covered
	    //     Reduce squares-left count by 2
	    //     Recurse; add return value to total
	    //     Restore all changes, except total
	    if (checkDomino( board,
			     dim_x, dim_y,
			     x, y,
			     x+1, y)) {
		// mark squares
		placeDomino(board, dim_x, dim_y,  
			    x, y,
			    x+1, y,
			    squaresLeft);
		// recurse
		total += hdtCount_recurse(board,
					  dim_x, dim_y,
					  x, y,
					  squaresLeft);
		// restore changes
		popDomino(board, dim_x, dim_y,
			  x, y,
			  x+1, y,
			  squaresLeft);
	    }
	    // Try vertical domino
	    //     Same as vertical except squares passed
	    if(checkDomino( board,
			    dim_x, dim_y,
			    x, y,
			    x, y+1)) {
		
		// mark squares
		placeDomino(board, dim_x, dim_y,  
			    x, y,
			    x, y+1,
			    squaresLeft);
		// recurse
		total += hdtCount_recurse(board,
					  dim_x, dim_y,
					  x, y,
					  squaresLeft);
		// restore changes
		popDomino(board, dim_x, dim_y,
			  x, y,
			  x, y+1,
			  squaresLeft);
	    }
	}
    }
    return total;
}


// hdtCount
// wrapper function
// returns the number of solutions to the "holey domino tilings"
// for board of given dimensions with co-ordinates for two forbidden
// squares.
// Pre:
//     dim_x,dim_y>0 &&
//     0 <= forbid1_x,forbid2_x < dim_x &&
//     0 <= forbid1_y,forbid2_y < dim_y
// Exception free
int hdtCount(int dim_x, int dim_y,
	     int forbid1_x, int forbid1_y,
	     int forbid2_x, int forbid2_y)
{
    assert(dim_x > 0 && dim_y > 0 );
    assert(0 <= forbid1_x && forbid1_x < dim_x);
    assert(0 <= forbid1_y && forbid1_y < dim_y);
    assert(0 <= forbid2_x && forbid2_x < dim_x);
    assert(0 <= forbid2_y && forbid2_y < dim_y);
    // Initialize board
    // MyBoardType board(dim_x, (dim_y, 0));
    MyBoardType board (dim_x, vector<int>(dim_y, 0));
    int squaresLeft = dim_x * dim_y;
    
    // Setting the forbidden squares
    placeDomino(board, dim_x, dim_y,  
                forbid1_x, forbid1_y,
	        forbid2_x, forbid2_y,
	        squaresLeft);
     if (squaresLeft % 2)
	 return 0;
     else
	 return hdtCount_recurse(board, dim_x, dim_y, 0,0,squaresLeft);
}
