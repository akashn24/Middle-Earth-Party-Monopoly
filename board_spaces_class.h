//
//  board_spaces_class.h
//  Final Assignment Boardgame
//
//  Created by Akash Nair on 12/04/2020.
//  Copyright © 2020 Akash Nair. All rights reserved.
//
//  Coded in Xcode 11.31 with Clang as front end compiler and LLVM as back end compiler
//
//  This header file contains the abstract base class for boards spaces as well as the derived specifc space classes. These spaces are the spaces on the monopoly board and each derived class reprsents a single type of space on the board for a total of 10 spaces. The functions are also prototyped in the class.

#ifndef board_spaces_class_h
#define board_spaces_class_h

#include "characters_class.h"

#include <stdio.h>
#include <memory>
#include <algorithm>
#include <numeric>

// Abstract Base class with pure virtual functions for the board spaces
class board_space
{
protected:
    int space_number{};      // Monopoly board has 41 spaces
    std::string space_name{};
public:
    board_space(int space_number_input, std::string space_name_input);
    virtual ~board_space() {};
    // Accessor functions
    virtual std::string get_space_name() = 0;
    virtual int get_space_number() = 0;
    virtual double get_value_of_property() = 0;
    virtual double get_rent_on_property() = 0;
    virtual std::string get_name_of_character_who_owns_property() = 0;
    virtual bool get_ownership_boolean() = 0;
    virtual std::string print_owner_of_property() = 0; // If property is owned
    virtual double get_number_of_stars_in_pile() = 0;
    virtual std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const = 0;
    // Changes value of stars for the character or in the pile
    virtual double change_number_of_stars_in_pile(double number_to_change_stars) = 0;
    virtual void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) = 0;
    virtual void fly_by_eagles(std::shared_ptr<character> temporary_character) = 0; // Moves character to random space
    virtual void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) = 0; // Allows character to move again
    virtual void send_character_to_dungeon(std::shared_ptr<character> temporary_character) = 0; // Moves character to dungeon space
    virtual void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) = 0; // Moves character to just visiting space
    virtual void buy_the_property(std::shared_ptr<character> temporary_character) = 0; // Allows character to buy property if the character is on that space
    virtual void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) = 0; // Characters receiver the stars from the pile
    
};

class go_space : public board_space
{
public:
    go_space(int space_number_input, std::string space_name_input);
    ~go_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
    
};

class plus_100_stars_space : public board_space
{
 public:
    plus_100_stars_space(int space_number_input, std::string space_name_input);
    ~plus_100_stars_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character);
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class minus_200_stars_space: public board_space
{
public:
    minus_200_stars_space(int space_number_input, std::string space_name_input);
    ~minus_200_stars_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character);
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class go_to_the_dungeon_space: public board_space
{
protected:
    std::vector<int> dungeon_location{}; // Vector holds the space number of the dungeon so character can be sent there
public:
    go_to_the_dungeon_space(int space_number_input, std::string space_name_input);
    ~go_to_the_dungeon_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character);
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class in_dungeon_space: public board_space
{
protected:
    std::vector<int> just_visiting_space_location{}; // Vector holds the space number of the visiting space so when characters have missed their turns or paid to get out they will be moved there
public:
    in_dungeon_space(int space_number_input, std::string space_name_input);
    ~in_dungeon_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character);
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class just_visiting_space: public board_space
{
public:
    just_visiting_space(int space_number_input, std::string space_name_input);
    ~just_visiting_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class free_stars_from_pile : public board_space
{
protected:
    double stars_in_pile{}; // The money taken from characters by the minus spaces are added into this pile and given to whoever who lands on the free stars space
public:
    free_stars_from_pile(int space_number_input, std::string space_name_input);
    ~free_stars_from_pile() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile();
    double change_number_of_stars_in_pile(double number_to_change_stars);
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character);
    
};

class re_roll_dice_space: public board_space
{
public:
    re_roll_dice_space(int space_number_input, std::string space_name_input);
    ~re_roll_dice_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character);
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class eagle_perch_space: public board_space
{
protected:
    std::vector<int> eagle_eyrie_locations{}; // This vector has the space numbers of all the spaces on the board except the dungeon and the eagle space locations
public:
    eagle_perch_space(int space_number_input, std::string space_name_input);
    ~eagle_perch_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character);
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property() {return 0;}
    double get_rent_on_property() {return 0;}
    std::string get_name_of_character_who_owns_property() {return "";}
    bool get_ownership_boolean() {return false;}
    void buy_the_property(std::shared_ptr<character> temporary_character) {}
    std::string print_owner_of_property() {return "   ";}
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

class properties_space : public board_space
{
protected:
    double value_of_property_in_stars{}; // Players pay this amount to own the property
    double rent_on_property_if_owned{};  // When player lands on owned space they pay this amount to the owner
    bool owned_by_character{};           // Value is true if owned by character otherwise it is false
    std::string owned_by_who{};          // Holds the name of the owner of the property if property is owned
public:
    properties_space(int space_number_input, std::string space_name_input, double value_of_property_input, double rent_of_property_input);
    ~properties_space() {}
    std::string get_space_name();
    int get_space_number();
    std::string symbol_of_character_on_space(std::shared_ptr<character> temporary_character) const;
    void change_stars_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void fly_by_eagles(std::shared_ptr<character> temporary_character) {}
    void re_roll_dice_of_character_on_space(std::shared_ptr<character> temporary_character) {}
    void send_character_to_dungeon(std::shared_ptr<character> temporary_character) {}
    void get_character_out_of_dungeon(std::shared_ptr<character> temporary_character) {}
    double get_value_of_property();
    double get_rent_on_property();
    std::string get_name_of_character_who_owns_property();
    bool get_ownership_boolean();
    void buy_the_property(std::shared_ptr<character> temporary_character);
    std::string print_owner_of_property();
    double get_number_of_stars_in_pile() {return 0;}
    double change_number_of_stars_in_pile(double number_to_change_stars) {return 0;}
    void give_stars_from_pile_to_character_on_space(std::shared_ptr<character> temporary_character) {}
};

#endif /* board_spaces_class_h */
