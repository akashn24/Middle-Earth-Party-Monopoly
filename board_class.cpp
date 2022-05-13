//
//  board_class.cpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 22/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This source file is where all the board class functions are defined and all the board spaces constructors and charatcer constructor are called. It also has the overloading output of the board class to print a monopoly board.

#include "board_class.h"

// This function initializes the board spaces by calling its constructor and adds it to the vector on the board
void board::fill_board()
{
    board_space_list.push_back(std::make_shared<go_space>(0, "Home"));
    board_space_list.push_back(std::make_shared<properties_space>(1, "The Shire", 60, 15));
    board_space_list.push_back(std::make_shared<plus_100_stars_space>(2, "Plus 100"));
    board_space_list.push_back(std::make_shared<properties_space>(3, "Bree-Land", 60, 15));
    board_space_list.push_back(std::make_shared<minus_200_stars_space>(4, "Minus 200"));
    board_space_list.push_back(std::make_shared<eagle_perch_space>(5, "Eagles Eyrie"));
    board_space_list.push_back(std::make_shared<properties_space>(6, "Annuminas", 100, 25));
    board_space_list.push_back(std::make_shared<plus_100_stars_space>(7, "Plus 100"));
    board_space_list.push_back(std::make_shared<properties_space>(8, "Rivendell", 100, 25));
    board_space_list.push_back(std::make_shared<properties_space>(9, "Angmar", 120, 30));
    board_space_list.push_back(std::make_shared<just_visiting_space>(10, "Just Visiting"));
    board_space_list.push_back(std::make_shared<in_dungeon_space>(11, "In Dungeon"));
    board_space_list.push_back(std::make_shared<properties_space>(12, "Esgaroth", 140, 35));
    board_space_list.push_back(std::make_shared<re_roll_dice_space>(13, "Re-Roll Dice"));
    board_space_list.push_back(std::make_shared<properties_space>(14, "Dale", 140, 35));
    board_space_list.push_back(std::make_shared<properties_space>(15, "Erebor", 160, 40));
    board_space_list.push_back(std::make_shared<eagle_perch_space>(16, "Eagles Eyrie"));
    board_space_list.push_back(std::make_shared<properties_space>(17, "Mirkwood", 180, 45));
    board_space_list.push_back(std::make_shared<plus_100_stars_space>(18, "Plus 100"));
    board_space_list.push_back(std::make_shared<properties_space>(19, "Dol Guldur", 180, 45));
    board_space_list.push_back(std::make_shared<properties_space>(20, "Khazad-Dum", 200, 50));
    board_space_list.push_back(std::make_shared<free_stars_from_pile>(21, "Lucky Day"));
    board_space_list.push_back(std::make_shared<properties_space>(22, "Lorien", 220, 55));
    board_space_list.push_back(std::make_shared<plus_100_stars_space>(23, "Plus 100"));
    board_space_list.push_back(std::make_shared<properties_space>(24, "Fangorn", 220, 55));
    board_space_list.push_back(std::make_shared<properties_space>(25, "Isengard", 240, 60));
    board_space_list.push_back(std::make_shared<eagle_perch_space>(26, "Eagles Eyrie"));
    board_space_list.push_back(std::make_shared<properties_space>(27, "Helm's Deep", 260, 65));
    board_space_list.push_back(std::make_shared<properties_space>(28, "Edoras", 260, 65));
    board_space_list.push_back(std::make_shared<re_roll_dice_space>(29, "Re-Roll Dice"));
    board_space_list.push_back(std::make_shared<properties_space>(30, "Minas Tirith", 280, 70));
    board_space_list.push_back(std::make_shared<go_to_the_dungeon_space>(31, "Go To The Dungeon"));
    board_space_list.push_back(std::make_shared<properties_space>(32, "Osgiliath", 300, 75));
    board_space_list.push_back(std::make_shared<properties_space>(33, "Minas Morgul", 300, 75));
    board_space_list.push_back(std::make_shared<plus_100_stars_space>(34, "Plus 100"));
    board_space_list.push_back(std::make_shared<properties_space>(35, "Gorgoroth", 320, 80));
    board_space_list.push_back(std::make_shared<eagle_perch_space>(36, "Eagles Eyrie"));
    board_space_list.push_back(std::make_shared<plus_100_stars_space>(37, "Plus 100"));
    board_space_list.push_back(std::make_shared<properties_space>(38, "Barad-Dur", 340, 85));
    board_space_list.push_back(std::make_shared<minus_200_stars_space>(39, "Minus 200"));
    board_space_list.push_back(std::make_shared<properties_space>(40, "Mount Doom", 400, 100));
}

// This function initializes the characters by calling its constructor and adds it to the vector on the board
void board::initialize_character_list()
{
    character_list.push_back(std::make_shared<frodo_baggins>("Frodo", 1500, 0, 0, true));
    character_list.push_back(std::make_shared<samwise_gamgee>("Sam", 1500, 0, 0, true));
    character_list.push_back(std::make_shared<peregrin_took>("Pippin", 1500, 0, 0, true));
    character_list.push_back(std::make_shared<meriadoc_brandybuck>("Merry", 1500, 0, 0, true));
}

void board::update_character_location(int character_number)
{
    // Checks if character is currently located in the dungeon and the number of turns he has missed
    if ((character_list[character_number]->get_location() == 11) &&  (character_list[character_number]->get_number_of_turns_missed() == 0)) {
        // If still in dungeon and hasn't missed any turns then it will leave the character there
        character_list[character_number]->change_number_of_turns_missed(2);
        std::cout << character_list[character_number]->get_name() << " has missed this turn as he is in the dungeon" << "\n" << "\n";
    }
    else if ((character_list[character_number]->get_location() == 11) && (character_list[character_number]->get_number_of_turns_missed() == 1)){
         // If still in dungeon and has missed both turns then character will be moved to just visiting space
        std::vector<int> just_visiting_space;
        just_visiting_space.push_back(10);
        character_list[character_number]->change_number_of_turns_missed(-1);
        std::cout << character_list[character_number]->get_name() << " has now been released from the dungeon" << "\n" << "\n";
        character_list[character_number]->dice(just_visiting_space); // Calls character dice function but uses the just visiting space, space number
        // Immediately plays the characters turn as in the else case
        character_list[character_number]->dice(character_list[character_number]->get_moves());
        std::cout << character_list[character_number]->get_name() << " has thrown a " << ((character_list[character_number]->get_location()) - 10) << " and has moved to space number " << character_list[character_number]->get_location() << "\n" << "\n";
    }
    else if ((character_list[character_number]->get_location() == 11) && (character_list[character_number]->get_number_of_turns_missed() == 2)){
        // If character has only missed 1 turn, character stays in dungeon
        character_list[character_number]->change_number_of_turns_missed(-1);
        std::cout << character_list[character_number]->get_name() << " has missed another turn as he is still in the dungeon" << "\n" << "\n";
    }
    else{
        // If character is on any other space except the dungeone space it will the character as usual based on the characters die
        int previous_location = character_list[character_number]->get_location();
        character_list[character_number]->dice(character_list[character_number]->get_moves());
        int dice_value = ((character_list[character_number]->get_location()) - previous_location);
        if (dice_value < 0) {
            dice_value = 41 + dice_value; // Checks if the character has reached the last space on the board and loops back to the initial home space
        }
        std::cout << character_list[character_number]->get_name() << " has thrown a ";
        std::cout << dice_value;
        std::cout << " and has moved to space number " << character_list[character_number]->get_location() << "\n" << "\n";
    }
}

std::vector<std::shared_ptr<character>> board::get_full_character_list() const
{
    return character_list;
}

std::shared_ptr<board_space> board::get_specific_board_space(int space_number_wanted) const
{
    return board_space_list[space_number_wanted];
}

std::shared_ptr<character> board::get_character_list(int character_number_wanted) const
{
    return character_list[character_number_wanted];
}

void board::pay_rent_to_property_owner(int space_number_of_property, int character_number)
{
    // Checks if character is on a property which is already owned
    if ((character_list[character_number]->get_location() == board_space_list[space_number_of_property]->get_space_number()) && (board_space_list[space_number_of_property]->get_ownership_boolean() == true)){
        std::cout << character_list[character_number]->get_name() << " is on a property owned by " << board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() << "\n";
        // Depending on which character owns the property, the current character on the space will pay the appropriate rent amount to them
        if ((board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() == "Frodo") && (character_list[character_number]->get_name() != "Frodo" )) {
            // Takes stars away from character on property
            character_list[character_number]->change_stars(-(board_space_list[space_number_of_property]->get_rent_on_property()));
            // Gives owner the amount of stars as rent
            character_list[0]->change_stars(board_space_list[space_number_of_property]->get_rent_on_property());
            
            std::cout << character_list[character_number]->get_name() << " paid " << board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() << " " << board_space_list[space_number_of_property]->get_rent_on_property() << " stars as rent" << "\n";
            
            std::cout << character_list[0]->get_name() << " now has " << character_list[0]->get_stars() << "\n";
        }
        else if ((board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() == "Sam") && (character_list[character_number]->get_name() != "Sam" )) {
            
            character_list[character_number]->change_stars(-(board_space_list[space_number_of_property]->get_rent_on_property()));
            
            character_list[1]->change_stars(board_space_list[space_number_of_property]->get_rent_on_property());
            
            std::cout << character_list[character_number]->get_name() << " paid " << board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() << " " << board_space_list[space_number_of_property]->get_rent_on_property() << " stars as rent" << "\n";
            
            std::cout << character_list[1]->get_name() << " now has " << character_list[1]->get_stars() << "\n";
        }
        else if ((board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() == "Pippin") && (character_list[character_number]->get_name() != "Pippin" )) {
            
            character_list[character_number]->change_stars(-(board_space_list[space_number_of_property]->get_rent_on_property()));
            
            character_list[2]->change_stars(board_space_list[space_number_of_property]->get_rent_on_property());
            std::cout << character_list[character_number]->get_name() << " paid " << board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() << " " << board_space_list[space_number_of_property]->get_rent_on_property() << " stars as rent" << "\n";
            std::cout << character_list[2]->get_name() << " now has " << character_list[2]->get_stars() << "\n";
        }
        else if ((board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() == "Merry") && (character_list[character_number]->get_name() != "Merry" )) {
            
            character_list[character_number]->change_stars(-(board_space_list[space_number_of_property]->get_rent_on_property()));
            
            character_list[3]->change_stars(board_space_list[space_number_of_property]->get_rent_on_property());
            std::cout << character_list[character_number]->get_name() << " paid " << board_space_list[space_number_of_property]->get_name_of_character_who_owns_property() << " " << board_space_list[space_number_of_property]->get_rent_on_property() << " stars as rent" << "\n";
            
            std::cout << character_list[3]->get_name() << " now has " << character_list[3]->get_stars() << "\n";
        }
        else {
            std::cerr << "Error" << "\n" << "\n";
        }
        std::cout << character_list[character_number]->get_name() << " now has " << character_list[character_number]->get_stars() << "\n" << "\n";
    }
}
// Checks and see if the character is on the minus 200 pile and if he is then the 200 stars lost are put into the pile
void board::add_stars_into_the_pile_if_character_minus_200(int space_number_of_minus_200_space, int character_number)
{
    if (get_character_list(character_number)->get_location() == get_specific_board_space(space_number_of_minus_200_space)->get_space_number()){
        get_specific_board_space(space_number_of_minus_200_space)->change_stars_of_character_on_space(get_character_list(character_number));
        get_specific_board_space(11)->change_number_of_stars_in_pile(200);
    }
}

void board::check_winner_of_boss_battle_minigame()
{
    // Lambda function and max element used to compare the current character in the vector with the next vector, and returns iterator holding pointer to character that won
    std::vector<std::shared_ptr<character>>::iterator highest_scoring_character_points = std::max_element(character_list.begin(), character_list.end(), [](const std::shared_ptr<character>& temp_character1, const std::shared_ptr<character>& temp_character2)->bool
    {
        // Compares the number of points of the character and the one next to it in the vector and returns a boolean accordingly
       if(temp_character1->get_points() < temp_character2->get_points()) {
           return true;
       }
       else {
           return false;
       }
    });
    
    // Gives 500 stars to the winner of the boss battle as a reward
    std::cout << "Even though all 4 of you helped defeat Sauron, there is one among you that was the strongest" << "\n";
    std::cout << "The hobbit that dealt the most damage to Sauron was: " << (*highest_scoring_character_points)->get_name() << "\n" << "\n";
    (*highest_scoring_character_points)->change_stars(500);
    std::cout << "Thus " << (*highest_scoring_character_points)->get_name() << " receives 500 stars." << "\n" << "\n";
}

void board::check_winner_of_whole_game()
{
    // Prints out the final number of stars for each character before checking who won 
    for (int i{}; i < character_list.size(); i++) {
        std:: cout << character_list[i]->get_name() << ": " << character_list[i]->get_stars() << " stars" << "\n" << "\n";
    }
    // Lambda function and max element used to compare the current character in the vector with the next vector, and returns iterator holding pointer to character that won
    std::vector<std::shared_ptr<character>>::iterator character_with_most_stars = std::max_element(character_list.begin(), character_list.end(), [](const std::shared_ptr<character>& temp_character1, const std::shared_ptr<character>& temp_character2)->bool
     {
        // Compares the star values of the character and the one next to it in the vector and returns a boolean accordingly
        if(temp_character1->get_stars() < temp_character2->get_stars()) {
            return true;
        }
        else {
            return false;
        }
    });
    std::cout << "The hobbit that has the most stars is " << (*character_with_most_stars)->get_name() << "\n" << "\n";
    std::cout << (*character_with_most_stars)->get_name() << " has won the Middle Earth Party Board Game" << "\n" << "\n";
    std::cout << "Thank you for playing the Middle Earth Board Game" << "\n" << "\n";
}

// Introduction to the game and the rules to play
void board::introductory_message_and_ruleset()
{
    std::cout << "You are now playing MIDDLE EARTH PARTY" << "\n" << "\n";
    std::cout << "This is a four player game and the aim of the game is to end up with the highest number of stars when the game ends." << "\n";
    std::cout << "There is a minigame after every 8 turns, with the last one being a boss battle." << "\n";
    std::cout << "Each character will start with 1500 stars." << "\n";
    std::cout << "Stars can be obtained from mini-games or spaces on the board." << "\n";
    std::cout << "Properties on board can be bought for a certain star value." << "\n";
    std::cout << "Characters that land on an owned property space will have to pay the owner rent of half the value." << "\n";
    std::cout << "Players 1, 2, 3 and 4 will play the characters Frodo, Sam, Pippin and Merry respectively." << "\n" << "\n";
    std::cout << "*Insert Cutscene*" << "\n";
    std::cout << "Sauron the Great has plagued these lands for centuries." << "\n";
    std::cout << "Fateful hobbits, your aim is to defeat Sauron." << "\n";
    std::cout << "Without further ado, may the adventure begin." << "\n" << "\n";
}

// Output operator overloaded to print the game board and the characters
std::ostream& operator<<(std::ostream& game_board_output, const board& temporary_board)
{
    // TOP SECTION OF BOARD
    // 1st row of board with names of each tile
    for (int i{}; i < 152; i++) {
        game_board_output << "_";
    }
    game_board_output << "\n";
    game_board_output << "|" << temporary_board.board_space_list[21]->get_space_name() << "       ";
    for (int i{}; i < 4; i++) {
        game_board_output << "|" << temporary_board.board_space_list[22 + i]->get_space_name();
        game_board_output << temporary_board.board_space_list[22 + i]->print_owner_of_property();
               for (int l{}; l < 9 - (temporary_board.board_space_list[22 + i]->get_space_name()).length(); l++) {
                   game_board_output << " ";
               }
    }
    game_board_output << "|" << (temporary_board.board_space_list[26]->get_space_name()).substr(0,6) << temporary_board.board_space_list[26]->print_owner_of_property() << "   ";
    game_board_output << "|" << (temporary_board.board_space_list[27]->get_space_name()).substr(0,6) << temporary_board.board_space_list[27]->print_owner_of_property() << "   ";
    game_board_output << "|" << temporary_board.board_space_list[28]->get_space_name() << temporary_board.board_space_list[28]->print_owner_of_property() << "   ";
    game_board_output << "|" << (temporary_board.board_space_list[29]->get_space_name()).substr(0,7) << temporary_board.board_space_list[29]->print_owner_of_property() << "  ";
    game_board_output << "|" << (temporary_board.board_space_list[30]->get_space_name()).substr(0,5) << temporary_board.board_space_list[30]->print_owner_of_property() << "    ";
    game_board_output << "|" << (temporary_board.board_space_list[31]->get_space_name()).substr(0,9) << temporary_board.board_space_list[31]->print_owner_of_property() << "    |";
    game_board_output << "\n";
    
    //2nd row of board with the continuation of the longer tile names
    game_board_output << "|                ";
    for (int i{}; i < 4; i++) {
        game_board_output << "|            ";
    }
    game_board_output << "|" << (temporary_board.board_space_list[26]->get_space_name()).substr(7,5) << "       ";
    game_board_output << "|" << (temporary_board.board_space_list[27]->get_space_name()).substr(7,4) << "        ";
    game_board_output << "|            ";
    game_board_output << "|" << (temporary_board.board_space_list[29]->get_space_name()).substr(8,4) << "        ";
    game_board_output << "|" << (temporary_board.board_space_list[30]->get_space_name()).substr(6,6) << "      ";
    game_board_output << "|" << (temporary_board.board_space_list[31]->get_space_name()).substr(10,7) << "         |";
    game_board_output << "\n";

    //Remaining rows of top spaces
    for (int j{}; j < 3; j++) {
        game_board_output << "|                ";
        for (int i{}; i < 9; i++) {
            game_board_output << "|            ";
        }
        game_board_output << "|                |";
        game_board_output << "\n";
    }
    
    // Second last row of top spaces, which will show the symbol of the character if there is a character on it
    game_board_output << "|    " << temporary_board.board_space_list[21]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
    game_board_output << temporary_board.board_space_list[21]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
    game_board_output << temporary_board.board_space_list[21]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
    game_board_output << temporary_board.board_space_list[21]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    ";
    
    for (int i{}; i < 9; i++) {
        game_board_output << "|  " << temporary_board.board_space_list[22 + i]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
        game_board_output << temporary_board.board_space_list[22 + i]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
        game_board_output << temporary_board.board_space_list[22 + i]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
        game_board_output << temporary_board.board_space_list[22 + i]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "  ";
    }
    
    game_board_output << "|    " << temporary_board.board_space_list[31]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
    game_board_output << temporary_board.board_space_list[31]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
    game_board_output << temporary_board.board_space_list[31]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
    game_board_output << temporary_board.board_space_list[31]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    |";
    game_board_output << "\n";
    
    // Last row of the top spaces
    game_board_output << "|________________";
    for (int i{}; i < 9; i++) {
       game_board_output << "|____________";
    }
    game_board_output << "|________________|";
    game_board_output << "\n";
    
    //MIDDLE SECTION OF BOARD
    // All rows of spaces in middle section expect the last row of spaces
    for (int k{}; k < 8; k++) {
        game_board_output << "|" << temporary_board.board_space_list[20 - k]->get_space_name();
        game_board_output << temporary_board.board_space_list[20 - k]->print_owner_of_property();
        for (int l{}; l < 13 - (temporary_board.board_space_list[20 - k]->get_space_name()).length(); l++) {
            game_board_output << " ";
        }
        game_board_output << "|";
        for (int i{}; i < 116; i++) {
            game_board_output << " ";
        }
        game_board_output << "|" << temporary_board.board_space_list[32 + k]->get_space_name();
         game_board_output << temporary_board.board_space_list[32 + k]->print_owner_of_property();
        for (int l{}; l < 13 - (temporary_board.board_space_list[32 + k]->get_space_name()).length(); l++) {
            game_board_output << " ";
        }
        game_board_output << "|";
        game_board_output << "\n";
        for (int j{}; j < 2; j++) {
            game_board_output << "|                |";
            for (int i{}; i < 116; i++) {
                game_board_output << " ";
            }
            game_board_output << "|                |";
            game_board_output << "\n";
        }
        //Symbol check for the middle section board spaces
        game_board_output << "|    " << temporary_board.board_space_list[20 - k]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
        game_board_output << temporary_board.board_space_list[20 - k]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
        game_board_output << temporary_board.board_space_list[20 - k]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
        game_board_output << temporary_board.board_space_list[20 - k]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    |";
        for (int i{}; i < 116; i++) {
            game_board_output << " ";
        }
        game_board_output << "|    " << temporary_board.board_space_list[32 + k]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
        game_board_output << temporary_board.board_space_list[32 + k]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
        game_board_output << temporary_board.board_space_list[32 + k]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
        game_board_output << temporary_board.board_space_list[32 + k]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    |";
        game_board_output << "\n";
        //Bottom row of each middle board space
        game_board_output << "|________________|";
        for (int i{}; i < 116; i++) {
           game_board_output << " ";
        }
        game_board_output << "|________________|";
        game_board_output << "\n";
    }
    
    // Last row of board spaces in middle section
    game_board_output << "|" << temporary_board.board_space_list[12]->get_space_name();
    game_board_output << temporary_board.board_space_list[12]->print_owner_of_property();
    for (int l{}; l < 13 - (temporary_board.board_space_list[12]->get_space_name()).length(); l++) {
        game_board_output << " ";
    }
    game_board_output << "|";
    for (int i{}; i < 116; i++) {
        game_board_output << " ";
    }
    game_board_output << "|" << temporary_board.board_space_list[40]->get_space_name();
    game_board_output << temporary_board.board_space_list[40]->print_owner_of_property();
    for (int l{}; l < 13 - (temporary_board.board_space_list[40]->get_space_name()).length(); l++) {
        game_board_output << " ";
    }
    game_board_output << "|";
    game_board_output << "\n";
    for (int j{}; j < 2; j++) {
        game_board_output << "|                |";
        for (int i{}; i < 116; i++) {
            game_board_output << " ";
        }
        game_board_output << "|                |";
        game_board_output << "\n";
    }
    //Symbol check for the last row of the last row of board spaces
    game_board_output << "|    " << temporary_board.board_space_list[12]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
    game_board_output << temporary_board.board_space_list[12]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
    game_board_output << temporary_board.board_space_list[12]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
    game_board_output << temporary_board.board_space_list[12]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    |";
    for (int i{}; i < 116; i++) {
        game_board_output << " ";
    }
    game_board_output << "|    " << temporary_board.board_space_list[40]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
    game_board_output << temporary_board.board_space_list[40]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
    game_board_output << temporary_board.board_space_list[40]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
    game_board_output << temporary_board.board_space_list[40]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    |";
    game_board_output << "\n";
    //Bottom row of last row of board spaces
    game_board_output << "|________________|";
    for (int i{}; i < 116; i++) {
       game_board_output << "_";
    }
    game_board_output << "|________________|";
    game_board_output << "\n";
    
    // BOTTOM SECTION OF BOARD
    // 1st row of bottom section of board with names of each tile
    // Check if any characters are in the dungeone
    game_board_output << "|" << temporary_board.board_space_list[11]->get_space_name() << "(";
    game_board_output << temporary_board.board_space_list[11]->symbol_of_character_on_space(temporary_board.character_list[0]);
    game_board_output << temporary_board.board_space_list[11]->symbol_of_character_on_space(temporary_board.character_list[1]);
    game_board_output << temporary_board.board_space_list[11]->symbol_of_character_on_space(temporary_board.character_list[2]);
    game_board_output << temporary_board.board_space_list[11]->symbol_of_character_on_space(temporary_board.character_list[3]) << ")";
    
    game_board_output << "|" << temporary_board.board_space_list[9]->get_space_name() << temporary_board.board_space_list[9]->print_owner_of_property() << "   ";
    game_board_output << "|" << temporary_board.board_space_list[8]->get_space_name() << temporary_board.board_space_list[8]->print_owner_of_property();
    game_board_output << "|" << temporary_board.board_space_list[7]->get_space_name() << temporary_board.board_space_list[7]->print_owner_of_property() << " ";
    game_board_output << "|" << temporary_board.board_space_list[6]->get_space_name() << temporary_board.board_space_list[6]->print_owner_of_property();
    game_board_output << "|" << (temporary_board.board_space_list[5]->get_space_name()).substr(0,6) << temporary_board.board_space_list[5]->print_owner_of_property() << "   ";
    game_board_output << "|" << temporary_board.board_space_list[4]->get_space_name() << temporary_board.board_space_list[4]->print_owner_of_property();
    game_board_output << "|" << temporary_board.board_space_list[3]->get_space_name() << temporary_board.board_space_list[3]->print_owner_of_property();
    game_board_output << "|" << temporary_board.board_space_list[2]->get_space_name() << temporary_board.board_space_list[2]->print_owner_of_property() << " ";
    game_board_output << "|" << (temporary_board.board_space_list[1]->get_space_name()).substr(0,3) << temporary_board.board_space_list[1]->print_owner_of_property() << "      ";
    game_board_output << "|" << temporary_board.board_space_list[0]->get_space_name() << temporary_board.board_space_list[0]->print_owner_of_property() << "         |";
    game_board_output << "\n";
    
    //2nd row of bottom section of board with the continuation of the longer tile names
    game_board_output << "|" << temporary_board.board_space_list[10]->get_space_name() << "   ";
    for (int i{}; i < 4; i++) {
        game_board_output << "|            ";
    }
    game_board_output << "|" << (temporary_board.board_space_list[5]->get_space_name()).substr(7,5) << "       ";
    for (int i{}; i < 3; i++) {
           game_board_output << "|            ";
       }
    game_board_output << "|" << (temporary_board.board_space_list[1]->get_space_name()).substr(4,5) << "       ";
    game_board_output << "|                |";
    game_board_output << "\n";

    for (int j{}; j < 3; j++) {
        game_board_output << "|                ";
        for (int i{}; i < 9; i++) {
            game_board_output << "|            ";
        }
        game_board_output << "|                |";
        game_board_output << "\n";
    }
    
    // Second last row of bottom spaces, which will show the symbol of the character if there is a character on it
    game_board_output << "|    " << temporary_board.board_space_list[10]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
    game_board_output << temporary_board.board_space_list[10]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
    game_board_output << temporary_board.board_space_list[10]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
    game_board_output << temporary_board.board_space_list[10]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    ";
    
    for (int i{}; i < 9; i++) {
        game_board_output << "|  " << temporary_board.board_space_list[9 - i]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
        game_board_output << temporary_board.board_space_list[9 - i]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
        game_board_output << temporary_board.board_space_list[9 - i]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
        game_board_output << temporary_board.board_space_list[9 - i]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "  ";
    }
    
    game_board_output << "|    " << temporary_board.board_space_list[0]->symbol_of_character_on_space(temporary_board.character_list[0]) << " ";
    game_board_output << temporary_board.board_space_list[0]->symbol_of_character_on_space(temporary_board.character_list[1]) << " ";
    game_board_output << temporary_board.board_space_list[0]->symbol_of_character_on_space(temporary_board.character_list[2]) << " ";
    game_board_output << temporary_board.board_space_list[0]->symbol_of_character_on_space(temporary_board.character_list[3]) << " " << "    |";
    game_board_output << "\n";
    
    // Last row of the bottom spaces
       game_board_output << "|________________";
       for (int i{}; i < 9; i++) {
          game_board_output << "|____________";
       }
       game_board_output << "|________________|";
       game_board_output << "\n";

    return game_board_output;
}
