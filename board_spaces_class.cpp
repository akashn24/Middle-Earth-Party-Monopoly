//
//  board_spaces_class.cpp
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 12/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This source file is where all the functions are intialized and overridden for all the different types of board spaces. The specific functions that each board space carries out if there is a character on it is also defined here.

#include "board_spaces_class.h"

board_space::board_space(int space_number_input, std::string space_name_input) : space_number(space_number_input), space_name(space_name_input) {}


go_space::go_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input) {}

std::string go_space::get_space_name()
{
    return space_name;
}

int go_space::get_space_number()
{
    return space_number;
}
// Depending on if a character is on the space it will print the character symbol or a blank space
std::string go_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

plus_100_stars_space::plus_100_stars_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input) {}

// If character is on the plus 100 spacee it will add 100 stars to the character
void plus_100_stars_space::change_stars_of_character_on_space(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        temporary_character->change_stars(100);
        std::cout << "100 stars were given to " << temporary_character->get_name() << "\n";
        std::cout << temporary_character->get_name() << " now has " << temporary_character->get_stars() << " stars" << "\n" << "\n";
    }
}

std::string plus_100_stars_space::get_space_name()
{
    return space_name;
}

int plus_100_stars_space::get_space_number()
{
    return space_number;
}

std::string plus_100_stars_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

minus_200_stars_space::minus_200_stars_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input) {}

// If character is on the minus spacee it will add minus 200 stars from the character
void minus_200_stars_space::change_stars_of_character_on_space(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        temporary_character->change_stars(-200);
        std::cout << "200 stars were taken from " << temporary_character->get_name() << " and added into the pile" << "\n";
        std::cout << temporary_character->get_name() << " now has " << temporary_character->get_stars() << " stars" << "\n" << "\n";
    }
}

std::string minus_200_stars_space::get_space_name()
{
    return space_name;
}

int minus_200_stars_space::get_space_number()
{
    return space_number;
}

std::string minus_200_stars_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

go_to_the_dungeon_space::go_to_the_dungeon_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input)
{
    dungeon_location.resize(0);
    dungeon_location.push_back(11); // Location of the dungeon space
}
// If character is on this space then it will send the character to the dungeon
void go_to_the_dungeon_space::send_character_to_dungeon(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        std::cout << temporary_character->get_name() << " has been sent to the dungeon" << "\n" << "\n";
        temporary_character->dice(dungeon_location);
    }
}

std::string go_to_the_dungeon_space::get_space_name()
{
    return space_name;
}

int go_to_the_dungeon_space::get_space_number()
{
    return space_number;
}

std::string go_to_the_dungeon_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

in_dungeon_space::in_dungeon_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input)
{
    just_visiting_space_location.resize(0);
    just_visiting_space_location.push_back(10); // Location of just visiting space
}

// Checks if character wants to get out of jail by paying 150 stars
void in_dungeon_space::get_character_out_of_dungeon(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        std::string response_to_question;
        std::cout << temporary_character->get_name() << " is now in jail and will miss 2 turns before being allowed to keep playing" << "\n";
        std::cout << "Would " << temporary_character->get_name() << " like to get out of jail now for 50 stars? (yes or no): " << "\n" << "\n";
        std::cin >> response_to_question;
        std::cout << "\n";
        while ((response_to_question != "yes") && (response_to_question != "no")) {
             std::cin.clear();
                   std::cin.ignore();
                   std::cout << "Please input a valid answer: ";
                   std::cin >> response_to_question;
                   std::cout << "\n";
        }
        // If character wants to get out he pays 150 stars if not stays in jail and misses 2 turns
        if (response_to_question == "yes") {
            temporary_character->change_stars(-150);
            std::cout << "150 stars were taken from " << temporary_character->get_name() << "\n";
            std::cout << temporary_character->get_name() << " now has " << temporary_character->get_stars() << " stars" << "\n" << "\n";
            temporary_character->dice(just_visiting_space_location);
            std::cout << temporary_character->get_name() << " is now just visiting the dungeon" << "\n" << "\n";
        }
    }
}

std::string in_dungeon_space::get_space_name()
{
    return space_name;
}

int in_dungeon_space::get_space_number()
{
    return space_number;
}

std::string in_dungeon_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

just_visiting_space::just_visiting_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input) {}

std::string just_visiting_space::get_space_name()
{
    return space_name;
}

int just_visiting_space::get_space_number()
{
    return space_number;
}

std::string just_visiting_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

free_stars_from_pile::free_stars_from_pile(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input)
{
    stars_in_pile = 0; // Initially there are no stars in the lucky stars pile
}

double free_stars_from_pile::get_number_of_stars_in_pile()
{
    return stars_in_pile;
}

double free_stars_from_pile::change_number_of_stars_in_pile(double number_to_change_stars)
{
    return (stars_in_pile += number_to_change_stars);
}

// If character is on lucky space the give the stars from the pile to him
void free_stars_from_pile::give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        temporary_character->change_stars(get_number_of_stars_in_pile());
        std::cout << "It's " << temporary_character->get_name() << "'s lucky day";
        std::cout << get_number_of_stars_in_pile() << " stars were given to " << temporary_character->get_name() << "\n";
        std::cout << temporary_character->get_name() << " now has " << temporary_character->get_stars() << " stars" << "\n" << "\n";
    }
}

std::string free_stars_from_pile::get_space_name()
{
    return space_name;
}

int free_stars_from_pile::get_space_number()
{
    return space_number;
}

std::string free_stars_from_pile::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

re_roll_dice_space::re_roll_dice_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input) {}

// If character on re-roll dice space then call dice function again to move the character
void re_roll_dice_space::re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        temporary_character->dice(temporary_character->get_moves());
    }
}

std::string re_roll_dice_space::get_space_name()
{
    return space_name;
}

int re_roll_dice_space::get_space_number()
{
    return space_number;
}

std::string re_roll_dice_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

eagle_perch_space::eagle_perch_space(int space_number_input, std::string space_name_input) : board_space(space_number_input, space_name_input)
{
    // Locations charcter can teleport too not including the other eagle spaces and the dungeon space
    eagle_eyrie_locations.resize(41);
    std::iota(eagle_eyrie_locations.begin(), eagle_eyrie_locations.end(), 0);
    eagle_eyrie_locations.erase (eagle_eyrie_locations.begin() + 5);
    eagle_eyrie_locations.erase (eagle_eyrie_locations.begin() + 10);
    eagle_eyrie_locations.erase (eagle_eyrie_locations.begin() + 14);
    eagle_eyrie_locations.erase (eagle_eyrie_locations.begin() + 23);
    eagle_eyrie_locations.erase (eagle_eyrie_locations.begin() + 32);
}

// If character is on an eagle space, he will be automatically sent to another space
void eagle_perch_space::fly_by_eagles(std::shared_ptr<character> temporary_character)
{
    if (temporary_character->get_location() == get_space_number()){
        std::cout << "Fly You Fools" << "\n" << "\n";
        temporary_character->dice(eagle_eyrie_locations);
        std::cout << temporary_character->get_name() << " has been picked up by eagles and sent to space number " << temporary_character->get_location() << "\n" << "\n";
    }
}

std::string eagle_perch_space::get_space_name()
{
    return space_name;
}

int eagle_perch_space::get_space_number()
{
    return space_number;
}

std::string eagle_perch_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}

properties_space::properties_space(int space_number_input, std::string space_name_input, double value_of_property_input, double rent_of_property_input) : board_space(space_number_input, space_name_input), value_of_property_in_stars(value_of_property_input), rent_on_property_if_owned(rent_of_property_input)
{
    // Initially no one owns the property spaces
    owned_by_character = false;
    owned_by_who = "";
}

double properties_space::get_value_of_property()
{
    return value_of_property_in_stars;
}

double properties_space::get_rent_on_property()
{
    return rent_on_property_if_owned;
}

std::string properties_space::get_name_of_character_who_owns_property()
{
    return owned_by_who;
}

bool properties_space::get_ownership_boolean()
{
    return owned_by_character;
}

void properties_space::buy_the_property(std::shared_ptr<character> temporary_character)
{
    // Function only works when character is on that specific property and if the property is not already owned by another character
    if ((temporary_character->get_location() == get_space_number()) && (owned_by_character == false)){
        std::string response_to_question;
        std::cout << temporary_character->get_name() << " is now in " << get_space_name() << "\n";
        std::cout << "Would " << temporary_character->get_name() << " like to buy " << get_space_name() << " for "<< get_value_of_property() <<" stars: ";
        std::cin >> response_to_question;
        std::cout << "\n";
        // Loop repeats to check for invalid input entries untill a valid entry is inputed
        while ((response_to_question != "yes") && (response_to_question != "no")) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please input a valid answer: ";
            std::cin >> response_to_question;
            std::cout << "\n";
        }
        if (response_to_question == "yes") {
            // Character buys property
            owned_by_character = true;
            owned_by_who = temporary_character->get_name(); // Updates the space to let it know the new owner of the property
            temporary_character->change_stars(-(get_value_of_property()));
            std::cout << temporary_character->get_name() << " now owns " << get_space_name() << " and has " <<temporary_character->get_stars() << " stars" << "\n" << "\n";
        }
        else{
            std::cout << temporary_character->get_name() << " has decided not to buy " << get_space_name() << "\n" << "\n";
        }
    }
}

// If character owns that property, that character's symbol is printed next to the name
std::string properties_space::print_owner_of_property()
{
    if (get_name_of_character_who_owns_property() == "Frodo") {
        return "(F)";
    }
    else if (get_name_of_character_who_owns_property() == "Sam") {
        return "(S)";
    }
    else if (get_name_of_character_who_owns_property() == "Pippin") {
        return "(P)";
    }
    else if (get_name_of_character_who_owns_property() == "Merry") {
        return "(M)";
    }
    else{
        return "   ";
    }
}

std::string properties_space::get_space_name()
{
    return space_name;
}

int properties_space::get_space_number()
{
    return space_number;
}

std::string properties_space::symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const
{
    if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Frodo")) {
        return "F";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Sam")) {
        return "S";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Pippin")) {
        return "P";
    }
    else if ((temporary_character->get_location() == space_number) && (temporary_character->get_name() == "Merry")) {
        return "M";
    }
    else {
    return " ";
    }
}
