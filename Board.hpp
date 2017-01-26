//
//  make_board.hpp
//  tic_tac_toe
//
//  Created by Tyree Stevenson on 1/21/17.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp
#include <stdio.h>
#include <string>

using namespace std;

class Board {

public:
    
    Board();
    void generate_board();
    void edit_board(char user_input,char player_piece);
    void display_board();
    char board[3][3];
    bool search_for_win(char piece);
    bool search_for_tie_game();
    
private:
    
    bool search_for_diagonal_win(char piece);
    bool search_for_horizontal_win(char piece);
    bool search_for_vertical_win(char piece);
    
};

#endif /* Board_hpp */
