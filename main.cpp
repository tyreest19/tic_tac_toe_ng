//
//  main.cpp
//  tic_tac_toe_ng
//
//  Created by Tyree Stevenson on 1/21/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Board.hpp"

using namespace std;

struct Player {
    string firstname;
    string lastname;
    int wins;
    int loses;
    int draws;
    char piece;
    bool turn;
};

void clear_cin_buffer();

void get_names(string array_of_names[4]);

void play_game(Player &player1, Player &player2);

bool continue_game(Player player1, Player player2);

char get_player_move(string firstname);

int main(int argc, const char * argv[]) {
    
    string firstname;
    
    string lastname;
    
    Player player1;
    
    Player player2;
    
    cout << "Player one enter full name: ";
    cin >> player1.firstname >> player1.lastname;
    
    
    cout << "Player two enter full name: ";
    cin >> player2.firstname >> player2.lastname;
    cin.clear();
    
    player1.piece = 'x';
    player2.piece = 'o';
    player1.turn = true;
    bool continue_the_game;
    
    do {
        
        if (player1.turn) {
            
            play_game(player1, player2);
            
        }
        
        else {
            play_game(player2, player1);
        }
        
        continue_the_game = continue_game(player1, player2);
        
    } while(continue_the_game);
    
    return 0;
}

void play_game(Player &player1, Player &player2) {
    // This function is the actually tic-tac-toe game and it increments the stats of the player objects
    
    Board board;
    
    while (true) {
        board.display_board();
        board.edit_board(get_player_move(player1.firstname), player1.piece);
        
        if (board.search_for_win(player1.piece)) {
            
            board.display_board();
            
            cout << "Congrats you won your a genius " << player1.firstname << endl;
            
            player1.wins += 1;
            player2.loses += 1;
            player1.turn = false;
            player2.turn = true;
            break;
            
        }
        
        if (board.search_for_tie_game()) {
            
            board.display_board();
            
            cout << "The game ended in a draw" << endl;
            
            player1.draws += 1;
            player2.draws += 1;
            player1.turn = false;
            player2.turn = true;
            break;
            
        }
        
        board.display_board();
        board.edit_board(get_player_move(player2.firstname), player2.piece);
        
        if (board.search_for_win(player2.piece)) {
            
            board.display_board();
            
            cout << "Congrats you won your a genius " << player2.firstname << endl;
            
            player2.wins += 1;
            player1.loses += 1;
            player1.turn = true;
            player2.turn = false;
            break;
            
        }
        
        if (board.search_for_tie_game()) {
            
            board.display_board();
            
            cout << "The game ended in a draw" << endl;
            
            player1.draws += 1;
            player2.draws += 1;
            player1.turn = false;
            player2.turn = true;
            break;
            
        }
    }
}

bool continue_game(Player player1, Player player2) {
    
    char continue_game;
    
    cout << player1.firstname << " " << player1.lastname << " stats are below" << endl;
    cout << "Wins: " << player1.wins << endl;
    cout << "Loses: " << player1.loses << endl;
    cout << "Draws: " << player1.draws << endl;
    cout << endl;
    cout << player2.firstname << " " << player2.lastname << " stats are below" << endl;
    cout << "Wins: " << player2.wins << endl;
    cout << "Loses: " << player2.loses << endl;
    cout << "Draws: " << player2.draws << endl;
    cout << endl;
    cout << player1.firstname<< " and " << player2.firstname << " Enter y to play again and n to quit: ";
    cin >> continue_game;
    
    return continue_game == 'y';
    
}

char get_player_move(string firstname) {
    char move;
    
    cout << firstname <<" enter the number on the board where you want to move: ";
    cin >> move;
    
    return move;
    
}
