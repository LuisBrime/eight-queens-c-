//
//  Queen2.cpp
//  EightQueens
//
//  Created by Luis Eduardo Brime Gomez on 8/20/19.
//  Copyright © 2019 Luis Eduardo Brime Gomez. All rights reserved.
//

#include "Queen2.hpp"


Queen2::Queen2() {
    
}

Queen2::~Queen2() {
}

void printBoardQ(int* board, int size) {
    int actualRow = 0;
    for (int i = 0; i < size*size; i++) {
        if ((int)i/size != actualRow) {
            printf("\n");
            actualRow = (int) i / size;
        }
        printf("%d\t", board[i]);
    }
    printf("\n\n");
}

bool isSafe(int* board, int pos, int size) {
    printf("Trying pos %d\n", pos);
    int i, j;
    
    // Check upper column
    for (i = pos; i >= pos % size; i -= size) {
        printf("Pos %d Col %d\t", pos, i);
        if (board[i])
            return false;
    }
    printf("\n");
    
    // Check upper-left diagonal
    for (i = pos    , j = pos % size;
         i >= 0    && j <= pos % size;
         i -= size+1) {
        printf("Pos %d ULDiag %d\t", pos, i);
        if (board[i])
            return false;
        j = i % size;
    }
    printf("\n");
    
    // Check upper-right diagonal
    for (i = pos    ,   j = pos % size;
         i >= 0     &&  j >= pos % size;
         i -= size-1) {
        printf("Pos %d URDiag %d\t", pos, i);
        if (board[i])
            return false;
        j = i % size;
    }
    printf("\n");
    printf("\n");
    
    return true;
}

bool Queen2::place(int *board, int size, Queen2* queens, int id) {
    if (id >= size) {
        return true;
    }
    
    // ID is the row where the queen is trying to place itself.
    // It has to run through the columns to see where it can be placed.
    // ID * size gives the first element of the row.
    // (ID * size) + size - 1 gives the last element of the row.
    for ( int i = id * size; i <= ((id*size)+size-1); i++ ) {
        printf("Row: %d Pos: %d\n", id, i);
        
        // Checks if the spot does not interfere with another queen's path.
        if (isSafe(board, i, size)) {
            printf("Place myself, %d, at %d\n", id, i);
            board[i] = 1;
            printBoardQ(board, size);
            
            if (queens[id+1].place(board, size, queens, id+1)) {
                printf("I could place myself %d\n", id);
                return true;
            }
            
            printf("%d could not place, I am %d\n", id+1, id);
            board[i] = 0;
        }
    }
    
    printf("I cant do this %d\n", id);
    return false;
}
