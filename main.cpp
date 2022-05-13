//
//  main.cpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 01/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
// This program creates a playable monopoly board with minigames in between sets of turns. In this main source file, the board and minigames classes are outputed.

#include "characters_class.h"
#include "board_spaces_class.h"
#include "board_class.h"
#include "game_check_functions.h"
#include "minigames.h"



int main() {
    int number_of_sets {10};       // Each character has a turn per set and 10 sets in total before a minigame
    double sauron_number_of_lives {10};          // Sauron the enemy in the boss battle minigame starts of with 10 lives
    std::string response_to_question;         // Use to determine whether character wants to play again
    do {
        board game_board;
        game_board.fill_board();       // Adds all the different board spaces to the game board
        game_board.initialize_character_list();     // Adds the 4 different characters to the game board
        game_board.introductory_message_and_ruleset();        // Explains the game and its rules to the players
        std::cout << game_board << "\n" << "\n";
        
        play_game(game_board, number_of_sets);   // Each player gets 10 dice throws
        
        lucky_or_not::minigame lucky_or_not{};           // First minigame begins here
        lucky_or_not.play_game(lucky_or_not, game_board);
        std::cout << "Now wasn't that a fun little side quest." << "\n";
        std::cout << "But now young hobbits, we must get back to the quest at hand." << "\n" << "\n";
        
        play_game(game_board, number_of_sets); // Each player gets another 10 dice throws
        
        boss_battle::minigame sauron_fight{sauron_number_of_lives};         // Final minigame begins here
        sauron_fight.play_game(sauron_fight, game_board);
        game_board.check_winner_of_boss_battle_minigame();
        
        game_board.check_winner_of_whole_game();         // Decides the winner of the whole game based on their stars
        
        // Check if players would like to replay the game
        std::cout << "Would you like to play again?: ";
        std::cin >> response_to_question;
        std::cout << "\n";
        while ((response_to_question != "yes") && (response_to_question != "no")) {
          std::cin.clear();
          std::cin.ignore();
          std::cout << "Please input a valid answer: ";
          std::cin >> response_to_question;
          std::cout << "\n";
        };
    } while (response_to_question == "yes");  // If players would like to play again the game restarts
    
    std::cout << "Thank you very much for playing the Middle Earth Party Game." << "\n" << "\n";

    return 0;
}
