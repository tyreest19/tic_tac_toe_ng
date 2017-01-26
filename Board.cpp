// Tyree Stevenson
// Dr. Chung Ng – Data Structures and Algorithm Analysis
// January 27, 2017
//  Board.cpp
//  tic_tac_toe_ng
//
//  Created by Tyree Stevenson on 1/21/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Board.hpp"
#include <iostream>
#include "Board.hpp"
#include <string>

using namespace std;

string board[3][3];

//============================================================================================
// Creates Board object.
//============================================================================================

Board:: Board(){
    
    generate_board();
    
};

//============================================================================================
// Generates a two dimensional char array with numbers from 1-9.
//============================================================================================

void Board:: generate_board() {
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
};

//============================================================================================
// Allows user to edit the board.
//============================================================================================

void Board:: edit_board(char user_input,char players_piece) {
    
    if(user_input == '1' || user_input == '2' || user_input == '3') {
        
        if (user_input == '1') {
            
            board[0][0] = players_piece;
            
        }
        
        if (user_input == '2') {
            
            board[0][1] = players_piece;
            
        }
        
        if (user_input == '3') {
            
            board[0][2] = players_piece;
            
        }
    }
    
    if(user_input == '4' || user_input == '5' || user_input == '6') {
        
        if (user_input == '4') {
            
            board[1][0] = players_piece;
            
        }
        
        if (user_input == '5') {
            
            board[1][1] = players_piece;
            
        }
        
        if (user_input == '6') {
            
            board[1][2] = players_piece;
            
        }
    }
    
    if(user_input == '7' || user_input == '8' || user_input == '9') {
        
        if (user_input == '7') {
            
            board[2][0] = players_piece;
            
        }
        
        if (user_input == '8') {
            
            board[2][1] = players_piece;
            
        }
        
        if (user_input == '9') {
            
            board[2][2] = players_piece;
            
        }
    }
};

//============================================================================================
// Displays the board.
//============================================================================================

void Board:: display_board() {
    
    for (int i = 0; i < 3; i++) {
        
        cout << " - - -" << endl;
        cout << "|";
        
        for (int j = 0; j < 3; j++) {
            
            cout << board[i][j];
            cout << "|";
            
        }
        
        cout << endl;
        
    }
    
    cout << " _ _ _" << endl;
    
};

//============================================================================================
// Searches for win by checking all of the possible winning methods.
//============================================================================================

bool Board:: search_for_win(char piece) {
    
    bool diagonal_win = Board:: search_for_diagonal_win(piece);
    
    bool horizontal_win = Board:: search_for_horizontal_win(piece);
    
    bool vertical_win = Board:: search_for_vertical_win(piece);
    
    if (diagonal_win == true || horizontal_win == true || vertical_win == true) {
        
        return true;
        
    }
    
    return false;
    
}

//============================================================================================
// Searches the board for a winning diagnol combination and if combination found it is capitalized and returns true.
//============================================================================================

bool Board:: search_for_diagonal_win(char piece) {
    
    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) {
        
        board[0][0] = toupper(piece);
        board[1][1] = toupper(piece);
        board[2][2] = toupper(piece);
        
        return true;
    }
    
    if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece) {
        
        board[0][2] = toupper(piece);
        board[1][1] = toupper(piece);
        board[2][0] = toupper(piece);
        
        return true;
    }
    
    return false;
}

//============================================================================================
// Searches the board for a winning horizontal combination if combination found it is capitalized and returns true.
//============================================================================================

bool Board:: search_for_horizontal_win(char piece) {
    
    int score = 0;
    
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {
            
            if(board[i][j] == piece) {
                
                score += 1;
                
                if (score == 3) {
                    
                    board[i][j - 2] = toupper(piece);
                    board[i][j - 1] = toupper(piece);
                    board[i][j] = toupper(piece);
                    
                    return true;
                }
            }
        }
        
        score = 0;
        
    }
    
    return false;
}

//============================================================================================
// Searches the board for a winning vertical combination if combination found it is capitalized and  returns true.
//============================================================================================

bool Board:: search_for_vertical_win(char piece) {
    
    if (board[0][0] == piece && board[1][0] == piece && board[2][0] == piece) {
        
        board[0][0] = toupper(piece);
        board[1][0] = toupper(piece);
        board[2][0] = toupper(piece);
        
        return true;
    }
    
    if (board[0][1] == piece && board[1][1] == piece && board[2][1] == piece) {
        
        board[0][1] = toupper(piece);
        board[1][1] = toupper(piece);
        board[2][1] = toupper(piece);
        
        return true;
    }
    
    if (board[0][2] == piece && board[1][2] == piece && board[2][2] == piece) {
        
        board[0][2] = toupper(piece);
        board[1][2] = toupper(piece);
        board[2][2] = toupper(piece);
        
        return true;
    }
    
    return false;
}

//============================================================================================
// Searches for tie game.
//============================================================================================

bool Board:: search_for_tie_game() {
    // Searches for tie game.
    int spaces_taken = 0;
    
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {
            
            if (board[i][j] == 'x' || board[i][j] == 'o') {
                
                spaces_taken += 1;
            }
        }
    }
    
    return spaces_taken == 9;
}
