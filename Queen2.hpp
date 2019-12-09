//
//  Queen2.hpp
//  EightQueens
//
//  Created by Luis Eduardo Brime Gomez on 8/20/19.
//  Copyright © 2019 Luis Eduardo Brime Gomez. All rights reserved.
//
#include <stdio.h>
#include <cmath>

class Queen2 {
public:
    Queen2();
    ~Queen2();
    bool place(int* board, int size, Queen2* queens, int id);
};
