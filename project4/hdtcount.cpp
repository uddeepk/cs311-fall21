// hdtcount.cpp
// Uddeep Karki
// Created: 2021-09-24
// Updated: 2021-09-27
// 
// For CS 311 Fall 2021
// Project 4: counting "holey domino tilings"
// Source file for hdtCount

// I want to give credit to my friend, and class mate Nathan Damon
// for helping me refactor my code. He told me not to use any 
// loops. Also, talking to him helped me come up with this solution.
// Without our conversation this wouldn't be possible.

#include "hdtcount.h" // header for counting "holey domino tilings"
#include <cassert> // For assert
#include <vector> // For vector
using std::vector;
#include <cstddef> // For size_t
using std::size_t;


using MyBoardType = vector<vector<int>>;

// hdtCount_recurse
// Given a partial solution to the "holey domino tilings returns the
// number of full solutions.
// Recursive workhorse function
// Pre:
//     board is type vector<vector<int>>
//     squaresLeft >= 0
//     curr_x, curr_y, total are ints
// Exception free

void hdtCount_recurse(MyBoardType &board,
                     int curr_x, int curr_y,
                     int squaresLeft,
                     int &total)
{
    // BASE CASE
    if (squaresLeft == 0) {
        ++total;
        return;
    }
    
    // Check if valid x index or move down another y
    if(static_cast<size_t>(curr_x) >= board.size()) {
        curr_x = 0;
        ++curr_y;
    }
    if ( static_cast<size_t>(curr_y) >= board[0].size()) { 
        // Invalid index
        return ;
    }
    
    // Recursive Case
    if(board[curr_x][curr_y] == 0) {
        ++board[curr_x][curr_y];
        --squaresLeft;
        if(static_cast<size_t>(curr_x + 1) < board.size() && board[curr_x+1][curr_y]==0) {
            ++board[curr_x+1][curr_y];
            --squaresLeft; 
            hdtCount_recurse(board, curr_x+2,curr_y,squaresLeft, total);
            --board[curr_x+1][curr_y];
            ++squaresLeft;
        }
        
        if(static_cast<size_t>(curr_y+1) < board[0].size() && board[curr_x][curr_y+1]==0) {
            ++board[curr_x][curr_y+1];
            --squaresLeft;
            hdtCount_recurse(board, curr_x+1,curr_y,squaresLeft, total);
            --board[curr_x][curr_y+1];
            ++squaresLeft;
        }
        --board[curr_x][curr_y];
        ++squaresLeft;
    } else // recurse from next square
        hdtCount_recurse(board,curr_x+1,curr_y,squaresLeft,total);
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
// Exception:
//     Can throw std::bad_alloc
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
    ++board[forbid1_x][ forbid1_y];
    ++board[forbid2_x][ forbid2_y];
    squaresLeft-=2;
    int total = 0;
    
    if (!(squaresLeft % 2)) // if squaresLeft are even
	 hdtCount_recurse(board, 0, 0, squaresLeft, total);
    return total;
}
