//
//  minigames.cpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 30/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This source file is where all the minigames functions for both minigames are defined as well as overloading the output operator for both minigames.

#include "minigames.h"


lucky_or_not::minigame::minigame()
{
    lucky_cards_bools.push_back(false); // Initialises for 4 cards 1 of which is unlucky
    lucky_cards_bools.push_back(true);
    lucky_cards_bools.push_back(true);
    lucky_cards_bools.push_back(true);
}
// Moves the elements in lucky_cards_bools around randomly so choosing the unlucky card is random
void lucky_or_not::minigame::shuffle_cards()
{
    auto random_number_generator_seed = std::default_random_engine {(unsigned int) time(NULL)};
    std::shuffle(lucky_cards_bools.begin(), lucky_cards_bools.end(), random_number_generator_seed);
}
// Function that prompts character to pick card and receive the boolean associated with it
void lucky_or_not::minigame::pick_card(minigame& temp_minigame, board& temp_board, std::string player_number, double upper_limit_of_cards)
{
    std::string prefix_of_card_number;
    game_utility_functions::ask_player_to_continue_with_game(player_number);
    std::cout << temp_minigame << "\n" << "\n";
    // Card number chosen by character is validated
    int card_number = game_utility_functions::input_card_number(player_number, upper_limit_of_cards);
    // Swith statement to decide prefix of card number
    switch (card_number) {
        case 1:
            prefix_of_card_number = "st";
            break;
            
        case 2:
            prefix_of_card_number = "nd";
            break;
            
        case 3:
            prefix_of_card_number = "rd";
            break;
            
        case 4:
            prefix_of_card_number = "th";
            break;
            
        default:
            break;
    }
    // Assigns boolean chosen to the character
    temp_board.get_character_list(std::stoi(player_number) - 1)->change_lucky_or_not_value(lucky_cards_bools[card_number - 1]);
    // Removes the element that the character has already chosen
    (temp_minigame.lucky_cards_bools).erase((temp_minigame.lucky_cards_bools).begin() + (card_number - 1));

    std::cout << temp_board.get_character_list(std::stoi(player_number) - 1)->get_name() << " has chosen the " << card_number << prefix_of_card_number << " card" << "\n" << "\n";
    std::cout << "There are " << (temp_minigame.lucky_cards_bools).size() << " cards left" << "\n" << "\n";
}
// Function eliminates the character with the false boolean and prints out winner at the end
void lucky_or_not::minigame::check_winner_of_round(board& temp_board)
{
    double counter{};
    for (int i{}; i < 4; i++) {
        // Checks all characters and eliminates the one with the false boolean
        if (temp_board.get_character_list(i)->get_lucky_or_not_value() == false) {
            std::cout << temp_board.get_character_list(i)->get_name() << " has chosen the bad luck card and is the unlucky one to get eliminated." << "\n" << "\n";
            counter++;
        }
    }
    if (counter == 3) {
        for (int i{}; i < 4; i++) {
            // Gives the 250 stars as a reward to the character that does not have a false bool
            if (temp_board.get_character_list(i)->get_lucky_or_not_value() != false) {
                temp_board.get_character_list(i)->change_stars(250);
                std::cout << temp_board.get_character_list(i)->get_name() << " has won the minigame and thus has received 250 stars." << "\n" << "\n";
            }
        }
    }
}
// Plays 1 round of the game and will be repeated 3 times in later function for the whole game
void lucky_or_not::minigame::play_game_round(minigame& temp_minigame, board& temp_board, int number_of_characters_still_playing)
{
    // When there is less than 4 players the vector needs to be modified accordingly
    if (number_of_characters_still_playing == 3) {
        (temp_minigame.lucky_cards_bools).clear();
        (temp_minigame.lucky_cards_bools).push_back(false);
        (temp_minigame.lucky_cards_bools).push_back(true);
        (temp_minigame.lucky_cards_bools).push_back(true);
    }
    else if (number_of_characters_still_playing == 2) {
        (temp_minigame.lucky_cards_bools).clear();
        (temp_minigame.lucky_cards_bools).push_back(false);
        (temp_minigame.lucky_cards_bools).push_back(true);
    }
    temp_minigame.shuffle_cards(); // Reorders the lucky_cards_bools vector randomly
        
        // Does checks to identify the upper limit for each characters turns
        if (temp_board.get_character_list(0)->get_lucky_or_not_value() != false) {
            if (number_of_characters_still_playing == 3) {
                // Last parameter in the function is the upper limit to choose the card number, similar for all
                temp_minigame.pick_card(temp_minigame, temp_board, "1", 4);
            }
            else if (number_of_characters_still_playing == 2) {
                temp_minigame.pick_card(temp_minigame, temp_board, "1", 3);
            }
            else {
                temp_minigame.pick_card(temp_minigame, temp_board, "1", 5);
            }
        }
        if (temp_board.get_character_list(1)->get_lucky_or_not_value() != false) {
            if (((number_of_characters_still_playing == 3) && (temp_board.get_character_list(0)->get_lucky_or_not_value() != false)) || ((number_of_characters_still_playing == 2) && (temp_board.get_character_list(0)->get_lucky_or_not_value() == false))) {
                temp_minigame.pick_card(temp_minigame, temp_board, "2", 3);
            }
            else if ((number_of_characters_still_playing == 2) && (temp_board.get_character_list(3)->get_lucky_or_not_value() == false)) {
                temp_minigame.pick_card(temp_minigame, temp_board, "2", 2);
            }
            else {
                temp_minigame.pick_card(temp_minigame, temp_board, "2", 4);
            }
        }
        if (temp_board.get_character_list(2)->get_lucky_or_not_value() != false) {
            if (temp_board.get_character_list(3)->get_lucky_or_not_value() == false) {
                temp_minigame.pick_card(temp_minigame, temp_board, "3", 2);
            }
            else {
                temp_minigame.pick_card(temp_minigame, temp_board, "3", 3);
            }
        }
        if (temp_board.get_character_list(3)->get_lucky_or_not_value() != false) {
            temp_minigame.pick_card(temp_minigame, temp_board, "4", 2);
        }
        // Eliminates player with false bool each round and at end of 3 rounds, announces minigame winner
        temp_minigame.check_winner_of_round(temp_board);
}
// Function that explain the rules of the game and procedes to ouput the game and ask for inputs
void lucky_or_not::minigame::play_game(minigame& temp_minigame, board& temp_board)
{
    std::cout << "Now it is time for a little side quest." << "\n";
    std::cout << "Players will take turns picking a card from the ones displayed." << "\n";
    std::cout << "Initially there will be 1 bad luck card and the rest will be good luck ones." << "\n";
    std::cout << "The person that chooses the bad luck card, will be eliminated." << "\n";
    std::cout << "Remaining players pick from 3 cards and so on until there is one player left standing." << "\n";
    std::cout << "This player will receive 250 stars as a prize." << "\n" << "\n";
    
    std::cout << "Round 1 Commence" << "\n" << "\n";
    temp_minigame.play_game_round(temp_minigame, temp_board, 4);
    std::cout << "Round 2 Commence" << "\n" << "\n";
    temp_minigame.play_game_round(temp_minigame, temp_board, 3);
    std::cout << "Round 3 Commence" << "\n" << "\n";
    temp_minigame.play_game_round(temp_minigame, temp_board, 2);
}
// Output operator overloaded to print the lucky cards
std::ostream& lucky_or_not::operator<<(std::ostream& minigame_output, const lucky_or_not::minigame& temporary_minigame)
{
    size_t size = (temporary_minigame.lucky_cards_bools).size();
    
    switch (size) {
        case 4:
            minigame_output << "_____________   " << "_____________   " << "______________   " << "______________" << "\n";
            minigame_output << "|    ___    |   " << "|  ______   |   " << "|  ______    |   " << "|  _   _     |" << "\n";
            minigame_output << "|   /_ |    |   " << "|  |__   \\  |   "<< "|  |___  \\   |   "<< "| | | | |    |" << "\n";
            minigame_output << "|    | |    |   " << "|     )  /  |   " << "|    __)  |  |   " << "| | |_| |__  |" << "\n";
            minigame_output << "|    | |    |   " << "|    /  /   |   " << "|   |__  <   |   " << "| |___   __| |" << "\n";
            minigame_output << "|    | |    |   " << "|   /  /___ |   " << "|   ___)  |  |   " << "|     | |    |" << "\n";
            minigame_output << "|    |_|    |   " << "|  /______| |   " << "|  |_____/   |   " << "|     |_|    |" << "\n";
            minigame_output << "|___________|   " << "|___________|   " << "|____________|   " << "|____________|" << "\n";
            break;
            
        case 3:
            minigame_output << "_____________   " << "_____________   " << "______________   " << "\n";
            minigame_output << "|    ___    |   " << "|  ______   |   " << "|  ______    |   " << "\n";
            minigame_output << "|   /_ |    |   " << "|  |__   \\  |   "<< "|  |___  \\   |   "<< "\n";
            minigame_output << "|    | |    |   " << "|     )  /  |   " << "|    __)  |  |   " << "\n";
            minigame_output << "|    | |    |   " << "|    /  /   |   " << "|   |__  <   |   " << "\n";
            minigame_output << "|    | |    |   " << "|   /  /___ |   " << "|   ___)  |  |   " << "\n";
            minigame_output << "|    |_|    |   " << "|  /______| |   " << "|  |_____/   |   " << "\n";
            minigame_output << "|___________|   " << "|___________|   " << "|____________|   " << "\n";
            break;
            
        case 2:
            minigame_output << "_____________   " << "_____________   " << "\n";
            minigame_output << "|    ___    |   " << "|  ______   |   " << "\n";
            minigame_output << "|   /_ |    |   " << "|  |__   \\  |   "<< "\n";
            minigame_output << "|    | |    |   " << "|     )  /  |   " << "\n";
            minigame_output << "|    | |    |   " << "|    /  /   |   " << "\n";
            minigame_output << "|    | |    |   " << "|   /  /___ |   " << "\n";
            minigame_output << "|    |_|    |   " << "|  /______| |   " << "\n";
            minigame_output << "|___________|   " << "|___________|   " << "\n";
            break;
            
        default:
            minigame_output << "_____________   " << "\n";
            minigame_output << "|    ___    |   " << "\n";
            minigame_output << "|   /_ |    |   " << "\n";
            minigame_output << "|    | |    |   " << "\n";
            minigame_output << "|    | |    |   " << "\n";
            minigame_output << "|    | |    |   " << "\n";
            minigame_output << "|    |_|    |   " << "\n";
            minigame_output << "|___________|   " << "\n";
            break;
            
            
    }
    
    return minigame_output;
}

boss_battle::minigame::minigame(double sauron_health_lives_input) : sauron_health_lives(sauron_health_lives_input)
{
    scissors_paper_stone.push_back("scissors");// Adds the 3 weapon choices to the vector, where the enemy can choose from
    scissors_paper_stone.push_back("paper");
    scissors_paper_stone.push_back("stone");

    std::vector<int> temp_vector_1{0, 2, 1};
    std::vector<int> temp_vector_2{1, 0, 2};
    std::vector<int> temp_vector_3{2, 1, 0};
    check_winner.push_back(temp_vector_1); // This array decides who the winner is, with 0 being a draw, 1 being Sauron
    check_winner.push_back(temp_vector_2); // and and 2 being the character
    check_winner.push_back(temp_vector_3);
}

int boss_battle::minigame::get_health_lives() const
{
    return sauron_health_lives;
}

int boss_battle::minigame::change_health_lives(double value_to_change_health_lives)
{
    return (sauron_health_lives += value_to_change_health_lives);
}
// Function randomly chooses a weapon from the vector of 3 weapons
int boss_battle::minigame::saurons_choice()
{
    srand((unsigned int) time(NULL));
    int random_index = rand() % scissors_paper_stone.size();
    std::string sauron_weapon_choice = scissors_paper_stone[random_index];
    
    std::cout << "Sauron has chosen "<< sauron_weapon_choice<< " to be his weapon of choice." << "\n" << "\n";
    
    if (sauron_weapon_choice == "stone") {         // Rock is given the value 0
        return 0;
    }
    else if (sauron_weapon_choice == "paper") {   // Paper is given the value 1
        return 1;
    }
    else {                                        // Scissors is given the value 2
        return 2;
    }
}
// Function prompts player to choose one of the valid 3 weapons
int boss_battle::minigame::player_pick_weapon(board& temp_board, std::string player_number)
{
    game_utility_functions::ask_player_to_continue_with_game(player_number);
    std::string weapon_chosen_by_player = game_utility_functions::check_player_inputed_correct_option();
    
    std::cout << temp_board.get_character_list(std::stoi(player_number) - 1)->get_name() << " has chosen " << weapon_chosen_by_player << " to be his weapon of choice." << "\n" << "\n";
    
    if (weapon_chosen_by_player == "stone") {        // Rock is given the value 0
        return 0;
    }
    else if (weapon_chosen_by_player == "paper") {  // Paper is given the value 1
        return 1;
    }
    else {                                          // Scissors is given the value 2
        return 2;
    }
    
}
// Chooses weapon for enemy and pits it against one character, can be repeated for all characters
void boss_battle::minigame::play_round_for_single_character(boss_battle::minigame& temp_minigame, board& temp_board, std::string player_number_wanted)
{
    if (temp_minigame.get_health_lives() != 0) {
        std::cout << temp_minigame;
        int player_weapon_choice = temp_minigame.player_pick_weapon(temp_board, player_number_wanted); // Player choice
        int saurons_weapon_choice = temp_minigame.saurons_choice();  // Enemy's Choice
        // Used 9x9 vector to get integer that represents outcome of battle
        int check_winner_integer = check_winner[saurons_weapon_choice][player_weapon_choice];
        // Checks what the outcome of the battle is
        switch (check_winner_integer) {
            case 0:
                std::cout << "It's a draw." << "\n" << "\n";
                break;
                
            case 1:
                temp_board.get_character_list(std::stoi(player_number_wanted) - 1)->change_stars(-50);
                std::cout << "Sauron has defeated " << temp_board.get_character_list(std::stoi(player_number_wanted) - 1)->get_name() << " this round, with his superior choice in weapon." << "\n";
                std::cout <<  temp_board.get_character_list(std::stoi(player_number_wanted) - 1)->get_name() << " has thus lost 50 stars in the process." << "\n" << "\n";
                break;
                
            case 2:
                temp_board.get_character_list(std::stoi(player_number_wanted) - 1)->change_points(1);
                temp_minigame.change_health_lives(-1);
                std::cout << temp_board.get_character_list(std::stoi(player_number_wanted) - 1)->get_name() << " was succesful in attacking Sauron this round and has received 1 point" << "\n";
                std::cout << "Sauron now has " << temp_minigame.get_health_lives() << " health lives left." << "\n" << "\n";
                break;
                
            default:
                break;
        }
    }
    
}
// Explains rules of the game and lets each character have a chance of attacking untill the enemy has lost all lifes
void boss_battle::minigame::play_game(boss_battle::minigame& temp_minigame, board& temp_board)
{
    std::cout << "Now young hobbits it is the final leg of your journey." << "\n";
    std::cout << "You will need to muster up all the strength and courage you have to defeat Sauron for good. " << "\n" << "\n";
    std::cout << "Oh no Sauron is upon us, I must leave now but good luck my friends and may the odds be ever in your favour."  << "\n" << "\n";
    std::cout << "*Sauron appears in front of the hobbits* " << "\n";
    std::cout << "It is I, Sauron the Great." << "\n";
    std::cout << "So it is 4 measly hobbits that challenge me." << "\n";
    std::cout << "Well then do your best to entertain me." << "\n" << "\n";
    do{
        temp_minigame.play_round_for_single_character(temp_minigame, temp_board, "1");
        temp_minigame.play_round_for_single_character(temp_minigame, temp_board, "2");
        temp_minigame.play_round_for_single_character(temp_minigame, temp_board, "3");
        temp_minigame.play_round_for_single_character(temp_minigame, temp_board, "4");
    }while (temp_minigame.get_health_lives() != 0); // Only ends when enemy's life is 0
    
    std::cout << "*Sauron dies*" << "\n";
    std::cout << "HUZZAH!!!" << "\n";
    std::cout << "You 4 courageous hobbits have managed to defeat him, now to claim your reward" << "\n" << "\n";
    for (int i{}; i < 4; i++) {
        std::cout << temp_board.get_character_list(i)->get_name() << " has " << temp_board.get_character_list(i)->get_points() << " points" << "\n";
    }
    std::cout << "\n";
}
// Output operator overloaded to print the eye of sauron and his lifes
std::ostream& boss_battle::operator<<(std::ostream& minigame_output, const boss_battle::minigame& temporary_minigame)
{
    
    std::cout << R"(
                                  Three::::rings
                              for:::the::Elven-Kings
                           under:the:sky,:Seven:for:the
                         Dwarf-Lords::in::their::halls:of
                        stone,:Nine             for:Mortal
                       :::Men:::     ________     doomed::to
                      die.:One   _,-'...:... `-.    for:::the
                     ::Dark::  ,- .:::::::::::. `.   Lord::on
                    his:dark ,'  .:::::zzz:::::.  `.  :throne:
                    In:::the/    ::::dMMMMMb::::    \ Land::of
                    :Mordor:\    ::::qMMMMMp::::    / :where::
                    ::the::: '.  ':::::zzz:::::'  ,'  Shadows:
                    lie.::One  `. ``:::::::::'' ,'    Ring::to
                     ::rule::    `-._```:'''_,-'     ::them::
                      all,::One      `-----'        ring::to
                       ::find:::                  them,:One
                        Ring:::::to            bring::them
                          all::and::in:the:darkness:bind
                            them:In:the:Land:of:Mordor
                               where:::the::Shadows
                                    :::lie.:::
    
    )" << "\n";
    
    std::cout << "                               Sauron's Health:" << "\n";
    std::cout << "                               ";
    for (int i{}; i < temporary_minigame.sauron_health_lives ; i++) {
        std::cout << "⬜️ "; // Emoji used can only run on Xcode on macOS
    }
    std::cout << "\n" << "\n" << "\n";
    
    return minigame_output;
}
