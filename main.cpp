//
//  main.cpp
//  EightQueens
//
//  Created by Luis Eduardo Brime Gomez on 8/19/19.
//  Copyright © 2019 Luis Eduardo Brime Gomez. All rights reserved.
//

#include <iostream>
#include "Queen2.hpp"

void printBoard(int* board, int size) {
    int actualRow = 0;
    for (int i = 0; i < size*size; i++) {
        if ((int)i/size != actualRow) {
            printf("\n");
            actualRow = (int) i / size;
        }
        printf("%d\t", board[i]);
    }
}

int main(int argc, const char * argv[]) {
    int size = 8;
    Queen2 *queens = new Queen2[size];
    int *board = new int[size*size];
    
    for (int i = 0; i < size*size; i++) {
        board[i] = 0;
    }
    
    if (queens[0].place(board, size, queens, 0))
        printBoard(board, size);
    else {
        printf("Oh shit\n");
        printBoard(board, size);
    }
    
    return 0;
}
