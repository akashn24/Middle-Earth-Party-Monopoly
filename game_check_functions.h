//
//  game_check_functions.h
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 28/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This header file contains prototypes of a few functions, which are used for input validation as well as prototypes for calling all the functions of the board spaces and playing the game.

#ifndef game_check_functions_h
#define game_check_functions_h

#include "board_class.h"

#include <stdio.h>

// Functions in this namepace are used for specific validation checks
namespace game_utility_functions {

    std::string ask_player_to_continue_with_game(std::string player_number);

    std::string check_player_inputed_correct_option();

    bool validate(std::string value, double x);

    double input_card_number(std::string input, double y);
}
// Call all the functions relevant to each board space
void board_space_functions(int character_number, board temp_board);

// Play a turn for each character once and this set can be adjusted to any number of sets
void play_game(board temp_board, int number_of_sets_of_turns);

#endif /* game_check_functions_h */
