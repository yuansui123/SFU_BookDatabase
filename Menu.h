#ifndef CMPT135FINALPROJECT_MENU_H
#define CMPT135FINALPROJECT_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "Database.h"
#include "ansi_codes.h"

using namespace std;

class Menu {
private:
    int userMenuChoice = 0;
    Database userDatabase;
    vector<string> menuChoices = {"add book", "delete book", "update book", "search book", "save book to file",
                                  "load book from file"};
public:

    Menu();

    ~Menu();

    //Print main menu page
    //Prompt user to enter their choice for submenu or exit the program
    void Main_menu();

    //Call menu method according to user menu choice
    //Call no method if user choose to exit the program
    void Open_menu();

    //Prompt user to enter menu choice
    //Check if user input is an int between -1 and 6
    void read_user_choice();

    //Return true of user input is a negative or positive integer
    //Return false other wise
    bool is_allInt(const string &s);

    //Print add book submenu
    //Allow user to add a book to the database
    //Does not allow user to add a book if the book already exist in database
    void Add_Book_Menu();

    //Print delete book submenu
    //Allow user to delete a book to the database
    //Does not allow user to delete a book if the book doesn't exist in database
    void Delete_Book_Menu();

    //Print update book submenu
    //Allow user to update the field of a book to the database
    //Does not allow user to update a book if the book doesn't exist in database
    //Does not allow user to update a book if the field doesn't exist in the book
    void Update_Book_Menu();

    //Print search book submenu
    //Allow user search for books in the database according to some criteria
    //Does not allow user to search book if user criteria is invalid
    //Print out book that satisfy user criteria
    void Search_Book_Menu();

    //Prompt user to enter search criteria
    //Check if user criteria is valid
    void ask_user_searchOption(const string &field, vector<string> &userSearchCriteria);

    //Return true if criteria exist in the criteria list
    //Return false other wise
    bool findSearchCriteria(const string& criteria, const vector<string>& allCriterias);

    //Return true if user search criteria is valid
    //Return false other wise
    //User search criteria in non-integer field must start with (-), (=)
    //User search criteria in integer field must start with (-), (=), (<), or (>)
    //User search criteria in integer field must enter integer
    bool isSearchCriteriaValid(const string &str, const string &field);

    //Print save book submenu
    //Allow user to save book from the database to a file
    //Does not allow user to save book to file if there is no book in the database
    //Does not allow user to save book to file if file can't be opened correctly
    void Save_Book_Tofile_Menu();

    //Print load book submenu
    //Allow user to load book from the from file to database
    //Does not allow user to load book to database if book contain invalid data
    //Does not allow user to load book to database if book already exist in the database
    //Does not allow user to save book to database if file can't be opened correctly
    //Print out book that contain invalid data
    void Read_Book_Fromfile_Menu();
};

#endif //CMPT135FINALPROJECT_MENU_H