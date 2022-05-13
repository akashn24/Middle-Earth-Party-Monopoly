//
//  characters_class.h
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 12/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This header file contains the abstract base class for characters as well as the derived character class. These characters are the ones that will be used to play the game. The classes also contain the prototyped functions for each of the characters.

#ifndef characters_class_h
#define characters_class_h

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>

// Abstract Base class with pure virtual functions for the characters
class character
{
protected:
    std::string name{};
    double stars{}; // Stars is the currency used in the game
    std::vector<int> move{}; // Vector stores all moves character can make
    int location{};
    int number_of_turns_missed{}; // This variable is used if the character is in the dungeon space
    int minigame_points{};
    bool lucky_or_not_value{};
public:
    character(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input);
    virtual ~character() {}
    // Accessor functions
    virtual std::string symbol_of_character() const = 0; // Returns the symbol of the characters
    virtual int get_location() const = 0;
    virtual std::string get_name() const = 0;
    virtual double get_stars() const = 0;
    virtual std::vector<int> get_moves() const = 0;
    virtual int get_number_of_turns_missed() const = 0;
    virtual int get_points() const = 0;
    virtual bool get_lucky_or_not_value() const = 0;
    virtual void dice(std::vector<int> temp_move_vector) = 0; // Randomly chooses a value from the move vector
    // Functions that change member variables
    virtual double change_stars(double value_of_change_in_stars) = 0; // Updates the value of the stars of the characters
    virtual int change_number_of_turns_missed(int value_of_change_in_number_of_turns) = 0; // Updates the number of turns the character has missed
    virtual int change_points(int value_of_change_in_points) = 0; // Updats the points the character receives from the minigame
    virtual bool change_lucky_or_not_value(bool value) = 0; // Updates whether the character has been eliminated from the minigame or not
};

// 4 derived classes for each character with their overriden functions
class frodo_baggins : public character
{
public:
    frodo_baggins(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input);
    ~frodo_baggins() {}
    std::string symbol_of_character() const;
    void dice(std::vector<int> temp_move_vector);
    double change_stars(double value_of_change_in_stars);
    int get_location() const;
    std::string get_name() const;
    double get_stars() const;
    std::vector<int> get_moves() const;
    int get_number_of_turns_missed() const;
    int get_points() const;
    bool get_lucky_or_not_value() const;
    int change_number_of_turns_missed(int value_of_change_in_number_of_turns);
    int change_points(int value_of_change_in_points);
    bool change_lucky_or_not_value(bool value);
};

class samwise_gamgee : public character
{
public:
    samwise_gamgee(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input);
    ~samwise_gamgee() {}
    std::string symbol_of_character() const;
    void dice(std::vector<int> temp_move_vector);
    double change_stars(double value_of_change_in_stars);
    int get_location() const;
    std::string get_name() const;
    double get_stars() const;
    std::vector<int> get_moves() const;
    int get_number_of_turns_missed() const;
    int get_points() const;
    bool get_lucky_or_not_value() const;
    int change_number_of_turns_missed(int value_of_change_in_number_of_turns);
    int change_points(int value_of_change_in_points);
    bool change_lucky_or_not_value(bool value);
};

class peregrin_took : public character
{
public:
    peregrin_took(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input);
    ~peregrin_took() {}
    std::string symbol_of_character() const;
    void dice(std::vector<int> temp_move_vector);
    double change_stars(double value_of_change_in_stars);
    int get_location() const;
    std::string get_name() const;
    double get_stars() const;
    std::vector<int> get_moves() const;
    int get_number_of_turns_missed() const;
    int get_points() const;
    bool get_lucky_or_not_value() const;
    int change_number_of_turns_missed(int value_of_change_in_number_of_turns);
    int change_points(int value_of_change_in_points);
    bool change_lucky_or_not_value(bool value);
};

class meriadoc_brandybuck : public character
{
public:
    meriadoc_brandybuck(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input);
    ~meriadoc_brandybuck() {}
    std::string symbol_of_character() const;
    void dice(std::vector<int> temp_move_vector);
    double change_stars(double value_of_change_in_stars);
    int get_location() const;
    std::string get_name() const;
    double get_stars() const;
    std::vector<int> get_moves() const;
    int get_number_of_turns_missed() const;
    int get_points() const;
    bool get_lucky_or_not_value() const;
    int change_number_of_turns_missed(int value_of_change_in_number_of_turns);
    int change_points(int value_of_change_in_points);
    bool change_lucky_or_not_value(bool value);
};

class fake_character_for_lambda_function : public character
{
public:
    fake_character_for_lambda_function(std::string character_name, const double stars_initial_value, const int location_input, const int initial_minigame_points, bool lucky_or_not_value_input);
    ~fake_character_for_lambda_function() {}
    std::string symbol_of_character() const {return "";}
    void dice(std::vector<int> temp_move_vector) {}
    double change_stars(double value_of_change_in_stars) {return 0;}
    int get_location() const {return 0;}
    std::string get_name() const {return "";}
    double get_stars() const {return 0;}
    std::vector<int> get_moves() const {std::vector<int> blank; return blank;}
    int get_number_of_turns_missed() const {return 0;}
    int get_points() const {return 0;}
    bool get_lucky_or_not_value() const {return true;}
    int change_number_of_turns_missed(int value_of_change_in_number_of_turns) {return 0;}
    int change_points(int value_of_change_in_points) {return 0;}
    bool change_lucky_or_not_value(bool value) {return true;}
};

#endif /* characters_class_h */
