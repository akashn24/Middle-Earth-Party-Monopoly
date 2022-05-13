//
//  minigames.h
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 30/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This header file two classes one for each minigame and are differentiated by their namespaces. It also holds all the prototype functions to play the minigame and to output the game.

#ifndef minigames_h
#define minigames_h

#include "board_class.h"
#include "game_check_functions.h"

#include <stdio.h>
#include <random>
#include <algorithm>

namespace lucky_or_not {

    class minigame 
    {
        // Overloading the output operator so that it will print out the cards in a visually appealing manner
        friend std::ostream& operator<<(std::ostream& minigame_output, const minigame& temporary_minigame);
    protected:
        std::vector<bool> lucky_cards_bools{}; // Holds the lucky cards and the 1 bad luck card
    public:
        minigame();
        ~minigame() {}
        void shuffle_cards(); // Randomly moves around the elements in the lucky_cards_bools vectors
        void pick_card(minigame& temp_minigame, board& temp_board, std::string player_number, double upper_limit_of_cards);
        void check_winner_of_round(board& temp_board); // Eliminates players with bad luck card and announces winner
        void play_game_round(minigame& temp_minigame, board& temp_board, int number_of_characters_still_playing);
        void play_game(minigame& temp_minigame, board& temp_board);
    };
}

namespace boss_battle {

    class minigame
    {
        // Overloading the output operator so that it will print out the enemy and its health lives
        friend std::ostream& operator<<(std::ostream& minigame_output, const minigame& temporary_minigame);
    protected:
        int sauron_health_lives{};
        std::vector<std::string> scissors_paper_stone{}; // Vector holds the three weapon choices of enemy
        std::vector<std::vector<int>> check_winner{};    // Vector of vectors with integers to determine the winner
    public:
        minigame(double sauron_health_lives_input);
        ~minigame() {}
        // Accesor function
        int get_health_lives() const;
        int change_health_lives(double value_to_change_health_lives);
        int saurons_choice(); // Enemy randomly chooses scissors, paper or stone
        int player_pick_weapon(board& temp_board, std::string player_number);
        void play_round_for_single_character(minigame& temp_minigame, board& temp_board, std::string player_number_wanted);
        void play_game(minigame& temp_minigame, board& temp_board);
    };
}


#endif /* minigames_h */
