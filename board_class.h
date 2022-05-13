//
//  board_class.hpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 22/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This header file contains the board class that holds all the board spaces as well as all the charatcers. The functions for the class are also prototyped here.

#ifndef board_class_h
#define board_class_h

#include "board_spaces_class.h"

#include <stdio.h>

class board
{
    // Overloading the output operator so that it will print out the board in an elegant format.
    friend std::ostream& operator<<(std::ostream& game_board_output, const board& temporary_board);
protected:
    // Vector of shared pointers point calls the constructor of each board space and then points to them.
    std::vector<std::shared_ptr<board_space>> board_space_list{};
    // Vector of shared pointers point calls the constructor of each character and then points to them
    std::vector<std::shared_ptr<character>> character_list{};
public:
    board() = default;
    ~board() {}
    // Accessor functions
    std::vector<std::shared_ptr<character>> get_full_character_list() const;
    std::shared_ptr<board_space> get_specific_board_space(int space_number_wanted) const;
    std::shared_ptr<character> get_character_list(int character_number_wanted) const;
    void fill_board(); // Initializes the board space list by calling the constructor of each derived space class
    void initialize_character_list(); //Initializes the character list by calling the constructor of each derived character class
    void update_character_location(int character_number); // Calls the characters dice function and moves the character across the board
    void pay_rent_to_property_owner(int space_number_of_property, int character_number); // If character is on property that is owned, rent will be payed to the character that owns it
    void add_stars_into_the_pile_if_character_minus_200(int space_number_of_minus_200_space, int character_number); // When characters lose stars it is added into the lucky space pile
    void check_winner_of_boss_battle_minigame(); // Identifies the winner of the minigames by finding the character with the highest points
    void check_winner_of_whole_game(); // Identifies the winner of the whole game by finding the character with the highest number of stars.
    void introductory_message_and_ruleset(); // Prints out the initial story and the rules.
};

#endif /* board_class_hpp */
