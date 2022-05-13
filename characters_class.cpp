//
//  characters_class.cpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 12/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This source files is where all the functions from the character classes are defined, as well as overriding the functions in the derived classes. Also the movement dice of all the characters are initialized here.

#include "characters_class.h"


character::character(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input) : name(character_name), stars(stars_initial_value), move(6), location(location_input), number_of_turns_missed(0), minigame_points(initial_minigame_points), lucky_or_not_value(lucky_or_not_value_input) {}


frodo_baggins::frodo_baggins(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input) : character(character_name, stars_initial_value, location_input, initial_minigame_points, lucky_or_not_value_input)
{
    move[0] = 1; // Adds the dice values for each character into their respective move vectors
    move[1] = 3;
    move[2] = 3;
    move[3] = 3;
    move[4] = 5;
    move[5] = 6;
}

std::string frodo_baggins::symbol_of_character() const
{
    return "F";
}

void frodo_baggins::dice(std::vector<int> temp_move_vector)
{
    // Generates a random number using the computer clock as the seed
    srand((unsigned int) time(NULL));
    // Returns a random number from 0 to the size of the moving vector
    int random_index = rand() % temp_move_vector.size();
    // For the case of the eagle eyries spaces
    if ((location == 5) || (location == 16) || (location == 26) || (location == 36)) {
        location = 0;
        location += temp_move_vector[random_index];
    }
    // For the case of the go to dungeon space to move character to in dungeon space
    else if (location == 31){
        location = 0;
        location += temp_move_vector[random_index];
    }
    // For the case of the in dungeon space to go to just visiting
    else if (location == 11){
        location = 0;
        location += temp_move_vector[random_index];
    }
    // For a general dice roll for any of the 4 characters using their specific die
    else{
        location += temp_move_vector[random_index];
        if (location > 40) {
            location = location - 41;
            std::cout << get_name() << " has passed home and has collected 200 stars" << "\n";
            change_stars(200);
        }
        // On a normal dice roll, players cannot land on the dungeon space so it skips it
        else if (location == 11){
            location = location + 1;
        }
    }
}

double frodo_baggins::change_stars(double value_of_change_in_stars)
{
    return (stars += value_of_change_in_stars);
}

int frodo_baggins::get_location() const
{
    return location;
}

std::string frodo_baggins::get_name() const
{
    return name;
}

double frodo_baggins::get_stars() const
{
    return stars;
}

std::vector<int> frodo_baggins::get_moves() const
{
    return move;
}

int frodo_baggins::get_number_of_turns_missed() const
{
    return number_of_turns_missed;
}

int frodo_baggins::get_points() const
{
    return minigame_points;
}

bool frodo_baggins::get_lucky_or_not_value() const
{
    return lucky_or_not_value;
}

int frodo_baggins::change_number_of_turns_missed(int value_of_change_in_number_of_turns)
{
    return(number_of_turns_missed += value_of_change_in_number_of_turns);
}

int frodo_baggins::change_points(int value_of_change_in_points)
{
    return (minigame_points += value_of_change_in_points);
}

bool frodo_baggins::change_lucky_or_not_value(bool value)
{
    return (lucky_or_not_value = value);
}

samwise_gamgee::samwise_gamgee(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input) : character(character_name, stars_initial_value, location_input, initial_minigame_points, lucky_or_not_value_input)
{
    move[0] = 1; // Adds the dice values for each character into their respective move vectors
    move[1] = 1;
    move[2] = 1;
    move[3] = 5;
    move[4] = 6;
    move[5] = 7;
}

std::string samwise_gamgee::symbol_of_character() const
{
    return "S";
}

void samwise_gamgee::dice(std::vector<int> temp_move_vector)
{
    srand((unsigned int) time(NULL));
    int random_index = rand() % temp_move_vector.size();
    if ((location == 5) || (location == 16) || (location == 26) || (location == 36)) {
        location = 0;
        location += temp_move_vector[random_index];
    }
    else if (location == 31){
        location = 0;
        location += temp_move_vector[random_index];
    }
    else if (location == 11){
        location = 0;
        location += temp_move_vector[random_index];
    }
    else{
        location += temp_move_vector[random_index];
        if (location > 40) {
            location = location - 41;
            std::cout << get_name() << " has passed home and has collected 200 stars" << "\n";
            change_stars(200);
        }
        else if (location == 11){
            location = location + 1;
        }
    }
}

double samwise_gamgee::change_stars(double value_of_change_in_stars)
{
    return (stars += value_of_change_in_stars);
}

int samwise_gamgee::get_location() const
{
    return location;
}

std::string samwise_gamgee::get_name() const
{
    return name;
}

double samwise_gamgee::get_stars() const
{
    return stars;
}

std::vector<int> samwise_gamgee::get_moves() const
{
    return move;
}

int samwise_gamgee::get_number_of_turns_missed() const
{
    return number_of_turns_missed;
}

int samwise_gamgee::get_points() const
{
    return minigame_points;
}

bool samwise_gamgee::get_lucky_or_not_value() const
{
    return lucky_or_not_value;
}

int samwise_gamgee::change_number_of_turns_missed(int value_of_change_in_number_of_turns)
{
    return(number_of_turns_missed += value_of_change_in_number_of_turns);
}

int samwise_gamgee::change_points(int value_of_change_in_points)
{
    return (minigame_points += value_of_change_in_points);
}

bool samwise_gamgee::change_lucky_or_not_value(bool value)
{
    return (lucky_or_not_value = value);
}

peregrin_took::peregrin_took(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input) : character(character_name, stars_initial_value, location_input, initial_minigame_points, lucky_or_not_value_input)
{
    move[0] = 0; // Adds the dice values for each character into their respective move vectors
    move[1] = 2;
    move[2] = 4;
    move[3] = 4;
    move[4] = 4;
    move[5] = 6;

}

std::string peregrin_took::symbol_of_character() const
{
    return "P";
}

void peregrin_took::dice(std::vector<int> temp_move_vector)
{
    srand((unsigned int) time(NULL));
    int random_index = rand() % temp_move_vector.size();
    if ((location == 5) || (location == 16) || (location == 26) || (location == 36)) {
        location = 0;
        location += temp_move_vector[random_index];
    }
    else if (location == 31){
        location = 0;
        location += temp_move_vector[random_index];
    }
    else if (location == 11){
        location = 0;
        location += temp_move_vector[random_index];
    }
    else{
        location += temp_move_vector[random_index];
        if (location > 40) {
            location = location - 41;
            std::cout << get_name() << " has passed home and has collected 200 stars" << "\n";
            change_stars(200);
        }
        else if (location == 11){
            location = location + 1;
        }
    }
}

double peregrin_took::change_stars(double value_of_change_in_stars)
{
    return (stars += value_of_change_in_stars);
}

int peregrin_took::get_location() const
{
    return location;
}

std::string peregrin_took::get_name() const
{
    return name;
}

double peregrin_took::get_stars() const
{
    return stars;
}

std::vector<int> peregrin_took::get_moves() const
{
    return move;
}

int peregrin_took::get_number_of_turns_missed() const
{
    return number_of_turns_missed;
}

int peregrin_took::get_points() const
{
    return minigame_points;
}

bool peregrin_took::get_lucky_or_not_value() const
{
    return lucky_or_not_value;
}

int peregrin_took::change_number_of_turns_missed(int value_of_change_in_number_of_turns)
{
    return(number_of_turns_missed += value_of_change_in_number_of_turns);
}

int peregrin_took::change_points(int value_of_change_in_points)
{
    return (minigame_points += value_of_change_in_points);
}

bool peregrin_took::change_lucky_or_not_value(bool value)
{
    return (lucky_or_not_value = value);
}

meriadoc_brandybuck::meriadoc_brandybuck(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input) : character(character_name, stars_initial_value, location_input, initial_minigame_points, lucky_or_not_value_input)
{
    move[0] = 0; // Adds the dice values for each character into their respective move vectors
    move[1] = 4;
    move[2] = 6;
    move[3] = 6;
    move[4] = 6;
    move[5] = 6;
}

std::string meriadoc_brandybuck::symbol_of_character() const
{
    return "M";
}

void meriadoc_brandybuck::dice(std::vector<int> temp_move_vector)
{
    srand((unsigned int) time(NULL));
    int random_index = rand() % temp_move_vector.size();
    if ((location == 5) || (location == 16) || (location == 26) || (location == 36)) {
        location = 0;
        location += temp_move_vector[random_index];
    }
    else if (location == 31){
        location = 0;
        location += temp_move_vector[random_index];
    }
    else if (location == 11){
        location = 0;
        location += temp_move_vector[random_index];
    }
    else{
        location += temp_move_vector[random_index];
        if (location > 40) {
            location = location - 41;
            std::cout << get_name() << " has passed home and has collected 200 stars" << "\n";
            change_stars(200);
        }
        else if (location == 11){
            location = location + 1;
        }
    }
}

double meriadoc_brandybuck::change_stars(double value_of_change_in_stars)
{
    return (stars += value_of_change_in_stars);
}

int meriadoc_brandybuck::get_location() const
{
    return location;
}

std::string meriadoc_brandybuck::get_name() const
{
    return name;
}

double meriadoc_brandybuck::get_stars() const
{
    return stars;
}

std::vector<int> meriadoc_brandybuck::get_moves() const
{
    return move;
}

int meriadoc_brandybuck::get_number_of_turns_missed() const
{
    return number_of_turns_missed;
}

int meriadoc_brandybuck::get_points() const
{
    return minigame_points;
}

bool meriadoc_brandybuck::get_lucky_or_not_value() const
{
    return lucky_or_not_value;
}

int meriadoc_brandybuck::change_number_of_turns_missed(int value_of_change_in_number_of_turns)
{
    return(number_of_turns_missed += value_of_change_in_number_of_turns);
}

int meriadoc_brandybuck::change_points(int value_of_change_in_points)
{
    return (minigame_points += value_of_change_in_points);
}

bool meriadoc_brandybuck::change_lucky_or_not_value(bool value)
{
    return (lucky_or_not_value = value);
}

fake_character_for_lambda_function::fake_character_for_lambda_function(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input) : character(character_name, stars_initial_value, location_input, initial_minigame_points, lucky_or_not_value_input)
{
    move[0] = 0; // Adds the dice values for each character into their respective move vectors
    move[1] = 0;
    move[2] = 0;
    move[3] = 0;
    move[4] = 0;
    move[5] = 0;
}
