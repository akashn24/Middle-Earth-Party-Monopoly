//
//  game_check_functions.cpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 28/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This source file is where all the input validation check functions are defined and also the functions to play the monopoly game.

#include "game_check_functions.h"

// This function prompts the player when its their turn
std::string game_utility_functions::ask_player_to_continue_with_game(std::string player_number)
{
    std::string response_to_question;
    std::cout << "Player " << player_number << ", please input your player number to play your turn: ";
    std::cin >> response_to_question;
    std::cout << "\n";
    // Loop repeats to check for invalid input entries untill a valid entry is inputed
    while (response_to_question != player_number) {
       std::cin.clear();
       std::cin.ignore();
       std::cout << "Please input a valid answer: ";
       std::cin >> response_to_question;
       std::cout << "\n";
    }
    return response_to_question;
}
// This function checks to see if the player has chosen a weapon among the 3 that is available
std::string game_utility_functions::check_player_inputed_correct_option()
{
    std::string response_to_question;
    std::cout << "Please input which weapon you would like to use (scissors, paper or stone): ";
    std::cin >> response_to_question;
    std::cout << "\n";
    // Loop repeats to check for invalid input entries untill a valid entry is inputed
    while ((response_to_question != "scissors") && (response_to_question != "paper") && (response_to_question != "stone")) {
       std::cin.clear();
       std::cin.ignore();
       std::cout << "Please input a valid answer: ";
       std::cin >> response_to_question;
       std::cout << "\n";
    }
    return response_to_question;
}

// Function that checks to see that all conditions of the input are met
bool game_utility_functions::validate(std::string value, double upper_limit){
    for (int i{}; i < value.size(); i++) {
        //isdigit is a function that looks at each value of a string and checks if there is an integer.
        if((isdigit(value[i]) == false)){
           return false;
            // Checks integer is not less than or equal to zero and not more than or equal to the set upper limit
        }else if ((std::stoi(value) <= 0) || (std::stoi(value) >= upper_limit)){
            return false;
        }
    }return true;
}
// This function uses the validation function as a condition to ask player to input a valid answer
double game_utility_functions::input_card_number(std::string input_player_number, double upper_limit){
    std::string arbitrary_string_value;
    double arbitrary_value;
    std::cout << "Player " << input_player_number << ", please pick a card number out of the ones displayed:  ";
    std::cin >> arbitrary_string_value;
    std::cout << "\n";
    // While loop, loops if any of the validation conditions are not met.
    while (game_utility_functions::validate(arbitrary_string_value, upper_limit) == false) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Please input a valid answer: ";
        std::cin >> arbitrary_string_value;
        std::cout << "\n";
        game_utility_functions::validate(arbitrary_string_value, upper_limit);
    }
    arbitrary_value = std::stoi(arbitrary_string_value);
    return arbitrary_value;
}

// This function uses the board space list in the board class and calls all the functions for each space right after a character has moved, and if character is on a space the specific functionality will be implemented
void board_space_functions(int character_number, board temp_board)
{
    temp_board.pay_rent_to_property_owner(1, character_number);
    (temp_board.get_specific_board_space(1))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(2))->change_stars_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(3, character_number);
    (temp_board.get_specific_board_space(3))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.add_stars_into_the_pile_if_character_minus_200(4, character_number);
    (temp_board.get_specific_board_space(5))->fly_by_eagles(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(6, character_number);
    (temp_board.get_specific_board_space(6))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(7))->change_stars_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(8, character_number);
    (temp_board.get_specific_board_space(8))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(9, character_number);
    (temp_board.get_specific_board_space(9))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(12, character_number);
    (temp_board.get_specific_board_space(12))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(13))->re_roll_dice_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(14, character_number);
    (temp_board.get_specific_board_space(14))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(15, character_number);
    (temp_board.get_specific_board_space(15))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(16))->fly_by_eagles(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(17, character_number);
    (temp_board.get_specific_board_space(17))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(18))->change_stars_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(19, character_number);
    (temp_board.get_specific_board_space(19))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(20, character_number);
    (temp_board.get_specific_board_space(20))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(21))->give_stars_from_pile_to_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(22, character_number);
    (temp_board.get_specific_board_space(22))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(23))->change_stars_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(24, character_number);
    (temp_board.get_specific_board_space(24))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(25, character_number);
    (temp_board.get_specific_board_space(25))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(26))->fly_by_eagles(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(27, character_number);
    (temp_board.get_specific_board_space(27))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(28, character_number);
    (temp_board.get_specific_board_space(28))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(29))->re_roll_dice_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(30, character_number);
    (temp_board.get_specific_board_space(30))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(31))->send_character_to_dungeon(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(11))->get_character_out_of_dungeon(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(32, character_number);
    (temp_board.get_specific_board_space(32))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(33, character_number);
    (temp_board.get_specific_board_space(33))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(34))->change_stars_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(35, character_number);
    (temp_board.get_specific_board_space(35))->buy_the_property(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(36))->fly_by_eagles(temp_board.get_character_list(character_number));
    (temp_board.get_specific_board_space(37))->change_stars_of_character_on_space(temp_board.get_character_list(character_number));
    temp_board.pay_rent_to_property_owner(38, character_number);
    (temp_board.get_specific_board_space(38))->buy_the_property(temp_board.get_character_list(character_number));
    temp_board.add_stars_into_the_pile_if_character_minus_200(39, character_number);
    temp_board.pay_rent_to_property_owner(40, character_number);
    (temp_board.get_specific_board_space(40))->buy_the_property(temp_board.get_character_list(character_number));
}

// Calls the function to move the character and then checks which space its on and implements that spaces functionality
// This is done for each character once and can be set to how many times the set is called in the main source file
void play_game(board temp_board, int number_of_sets_of_turns)
{
    for (int i{}; i < number_of_sets_of_turns; i++) {
        game_utility_functions::ask_player_to_continue_with_game("1"); // Prompts player 1 to play, similarly for the rest
        temp_board.update_character_location(0); // Moves the character
        std::cout << temp_board << "\n" << "\n";
        board_space_functions(0, temp_board);   // Checks which space character is on and calls the functions accordingly
        std:: cout << temp_board.get_character_list(0)->get_name() << ": "<<temp_board.get_character_list(0)->get_stars() << " stars" << "\n" << "\n";
        std::cout << temp_board << "\n" << "\n";
        
        game_utility_functions::ask_player_to_continue_with_game("2");
        temp_board.update_character_location(1);
        std::cout << temp_board << "\n" << "\n";
        board_space_functions(1, temp_board);
        std:: cout << temp_board.get_character_list(1)->get_name() << ": "<<temp_board.get_character_list(1)->get_stars() << " stars" << "\n" << "\n";
        std::cout << temp_board << "\n" << "\n";
        
        game_utility_functions::ask_player_to_continue_with_game("3");
        temp_board.update_character_location(2);
        std::cout << temp_board << "\n" << "\n";
        board_space_functions(2, temp_board);
        std:: cout << temp_board.get_character_list(2)->get_name() << ": "<<temp_board.get_character_list(2)->get_stars() << " stars" << "\n" << "\n";
        std::cout << temp_board << "\n" << "\n";
        
        game_utility_functions::ask_player_to_continue_with_game("4");
        temp_board.update_character_location(3);
        std::cout << temp_board << "\n" << "\n";
        board_space_functions(3, temp_board);
        std:: cout << temp_board.get_character_list(3)->get_name() << ": "<<temp_board.get_character_list(3)->get_stars() << " stars" << "\n" << "\n";
        std::cout << temp_board << "\n" << "\n";
    }
}
