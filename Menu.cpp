#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

//Print main menu page
//Prompt user to enter their choice for submenu or exit the program
void Menu::Main_menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*WELCOME TO YOUR PERSONAL DATABASE*" << endl
         << "***********************************" << endl;
    for (int i = 0; i < menuChoices.size(); i++) {
        cout << "Enter " << i + 1 << " to " << menuChoices.at(i) << endl;
    }
    cout << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
    //user input range from -1 to 6 to select submenu or to exit the program
    read_user_choice();
    try {
        Open_menu();
    } catch(...){
        cout << ANSI_RED << "An unknown error has occured" << ANSI_NORMAL << endl;
    }
}

//Call menu method according to user menu choice
//Call no method if user choose to exit the program
void Menu::Open_menu() {
    if (userMenuChoice == -1) {
    } else if (userMenuChoice == 1) {
        Add_Book_Menu();
    } else if (userMenuChoice == 2) {
        Delete_Book_Menu();
    } else if (userMenuChoice == 3) {
        Update_Book_Menu();
    } else if (userMenuChoice == 4) {
        Search_Book_Menu();
    } else if (userMenuChoice == 5) {
        Save_Book_Tofile_Menu();
    } else if (userMenuChoice == 6) {
        Read_Book_Fromfile_Menu();
    } else if (userMenuChoice == 0) {
        Main_menu();
    }
}

//Prompt user to enter menu choice
//Check if user input is an int between -1 and 6
void Menu::read_user_choice() {
    while (true) {
        string userChoice = "";
        getline(cin,userChoice);
        if (is_allInt(userChoice)) {
            int choice = stoi(userChoice);
            //check if user value is valid
            if (choice >= -1 && choice <= 6) {
                userMenuChoice = choice;
                break;
            }
        }
        cout << ANSI_RED << "Your input is invalid, please re-enter" << ANSI_NORMAL << endl;
    }
}

//Return true of user input is a negative or positive integer
//Return false other wise
bool Menu::is_allInt(const string &s) {
    if (s.size() == 0) return false;
    int pos = 0;
    if (s[0] == '-') pos = 1;

    for (int i = pos; i < s.size(); i++) {
        if (s[i] < 48 || s[i] > 57) {
            return false;
        }
    }
    return true;
}

//Print add book submenu
//Allow user to add a book to the database
//Does not allow user to add a book if the book already exist in database
void Menu::Add_Book_Menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*        ADD BOOK SUBMENU         *" << endl
         << "***********************************" << endl;

    while (true) {
        cout << ANSI_GREEN << "Enter 0 to go back to main menu" << endl
             << "Enter 1 to add book" << endl
             << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
        read_user_choice();
        if (userMenuChoice != 1) {
            Open_menu();
            break;
        }
        cout << ANSI_MAGENTA << "Please enter the information of the book that you want to add:" << ANSI_NORMAL << endl;
        Book userBook;
        try {
            userDatabase.add_book(userBook);
            cout << ANSI_YELLOW << "Book added successfully!" << ANSI_NORMAL << endl;
        } catch (const runtime_error& e) {
            cout << ANSI_RED << e.what() << ANSI_NORMAL << endl;
        }
    }
}

//Print delete book submenu
//Allow user to delete a book to the database
//Does not allow user to delete a book if the book doesn't exist in database
void Menu::Delete_Book_Menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*       DELETE BOOK SUBMENU       *" << endl
         << "***********************************" << endl;

    while (true) {
        cout << ANSI_GREEN << "Enter 0 to go back to main menu" << endl
             << "Enter 2 to delete book" << endl
             << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
        read_user_choice();
        if (userMenuChoice != 2) {
            Open_menu();
            break;
        }
        cout << ANSI_MAGENTA << "Please enter the information of the book that you want to delete:" << ANSI_NORMAL << endl;
        Book userBook;
        try {
            userDatabase.delete_book(userBook);
            cout << ANSI_YELLOW << "Book deleted successfully!" << ANSI_NORMAL << endl;
        } catch (const runtime_error& e) {
            cout << ANSI_RED << e.what() << ANSI_NORMAL << endl;
        }
    }
}

//Print update book submenu
//Allow user to update the field of a book to the database
//Does not allow user to update a book if the book doesn't exist in database
//Does not allow user to update a book if the field doesn't exist in the book
void Menu::Update_Book_Menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*       UPDATE BOOK SUBMENU       *" << endl
         << "***********************************" << endl;

    while (true) {
        cout << ANSI_GREEN << "Enter 0 to go back to main menu" << endl
             << "Enter 3 to update book" << endl
             << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
        read_user_choice();
        if (userMenuChoice != 3) {
            Open_menu();
            break;
        }
        cout << ANSI_MAGENTA << "Please enter the field you want to update:" << endl
             << "(choose from \"title\" , \"author\" , \"date of publication\" , \"book type\" , \"ISBN\" and \"number of pages\")" << ANSI_NORMAL << endl;
        string userField;
        getline(cin, userField);
        cout << ANSI_MAGENTA << "Please enter the information of the book that you want to update:" << ANSI_NORMAL << endl;
        Book userBook;
        cout << ANSI_MAGENTA << "Please enter the updated information in the following" << ANSI_NORMAL << endl;
        try {
            userDatabase.update_book(userBook, userField);
            cout << ANSI_YELLOW << "Book updated successfully!" << ANSI_NORMAL << endl;
        } catch (const runtime_error& e) {
            cout << ANSI_RED << e.what() << ANSI_NORMAL << endl;
        }
    }
}

//Print search book submenu
//Allow user search for books in the database according to some criteria
//Does not allow user to search book if user criteria is invalid
//Print out book that satisfy user criteria
void Menu::Search_Book_Menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*       SEARCH BOOK SUBMENU       *" << endl
         << "***********************************" << endl;

    while (true) {
        cout << ANSI_GREEN << "Enter 0 to go back to main menu" << endl
             << "Enter 4 to search book" << endl
             << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
        read_user_choice();
        if (userMenuChoice != 4) {
            Open_menu();
            break;
        }
        cout << ANSI_MAGENTA
             << "You will be asked to enter your search criteria in each field " << endl
             << "Enter (0) to skip each field " << endl
             << "Enter (-) to indicate negation" << endl
             << "Enter (=) to indicate equality" << endl
             << "Enter (<) to indicate smaller numerical value" << endl
             << "Enter (>) to indicate bigger numerical value" << ANSI_NORMAL << endl;
        vector<string> userSearchCriteria;
        vector<string> bookField = {"title", "author", "date of publication", "book type", "ISBN",
                                    "number of pages"};
        for (int i = 0; i < bookField.size(); i++) {
            ask_user_searchOption(bookField.at(i), userSearchCriteria);
        }
        try {
            vector<Book> searchResult = userDatabase.search_book(userSearchCriteria);
            if (!searchResult.empty()) {
                cout << ANSI_YELLOW;
                for (Book s: searchResult) {
                    cout << s.book_to_string();
                }
                cout << ANSI_NORMAL;
            } else {
                cout << ANSI_YELLOW << "No Result" << ANSI_NORMAL << endl;
            }
        } catch (const runtime_error& e) {
            cout << ANSI_RED << e.what() << ANSI_NORMAL << endl;
        }
    }
}

//Prompt user to enter search criteria
//Check if user criteria is valid
void Menu::ask_user_searchOption(const string &field, vector<string>& userSearchCriteria) {
    cout << ANSI_BLUE << "Please enter the information of the book for " << field << ANSI_NORMAL << endl;

    string userCriteria;
    while (getline(cin, userCriteria)) {
        if (userCriteria == "(0)") {
            break;
        }
        if (isSearchCriteriaValid(userCriteria, field)) {
            if(!findSearchCriteria(field + ":" + userCriteria, userSearchCriteria)) {
                //special notation used for searches in database
                userSearchCriteria.push_back(field + ":" + userCriteria);
            } else{
                cout << ANSI_RED << "your search criteria already exist, please re-enter" << ANSI_NORMAL << endl;
            }
        } else{
            cout << ANSI_RED << "your search criteria is invalid, please re-enter" << ANSI_NORMAL << endl;
        }
    }
}

//Return true if criteria exist in the criteria list
//Return false other wise
bool Menu::findSearchCriteria(const string& criteria, const vector<string>& allCriterias){
    for(int i = 0; i < allCriterias.size(); i++){
        if(allCriterias.at(i)==criteria) return true;
    }
    return false;
}

//Return true if user search criteria is valid
//Return false other wise
//User search criteria in non-integer field must start with (-), (=)
//User search criteria in integer field must start with (-), (=), (<), or (>)
//User search criteria in integer field must enter integer
bool Menu::isSearchCriteriaValid(const string &str, const string &field) {
    if (str.size() < 4) return false;
    if (str.find("(-)") != 0 && str.find("(<)") != 0 && str.find("(>)") != 0 && str.find("(=)") != 0) {
        return false;
    }
    if (field == "date of publication" || field == "number of pages") {
        if (!is_allInt(str.substr(3, str.size() - 3))) {
            return false;
        }
    } else {
        if (str.find("(<)") == 0 || str.find("(>)") == 0) return false;
    }
    return true;
}

//Print save book submenu
//Allow user to save book from the database to a file
//Does not allow user to save book to file if there is no book in the database
//Does not allow user to save book to file if file can't be opened correctly
void Menu::Save_Book_Tofile_Menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*        SAVE BOOK SUBMENU        *" << endl
         << "***********************************" << endl;

    while (true) {
        cout << ANSI_GREEN << "Enter 0 to go back to main menu" << endl
             << "Enter 5 to save book to file" << endl
             << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
        read_user_choice();
        if (userMenuChoice != 5) {
            Open_menu();
            break;
        }
        cout << ANSI_MAGENTA << "Please enter the name of your file" << ANSI_NORMAL << endl;
        string userFile;
        getline(cin, userFile);
        try {
            userDatabase.database_to_file(userFile);
            cout << ANSI_YELLOW << "Book successfully saved to " << userFile << ANSI_NORMAL << endl;
        } catch (const runtime_error& e) {
            cout << ANSI_RED << e.what() << ANSI_NORMAL << endl;
        }
    }
}

//Print load book submenu
//Allow user to load book from the from file to database
//Does not allow user to load book to database if book contain invalid data
//Does not allow user to load book to database if book already exist in the database
//Does not allow user to save book to database if file can't be opened correctly
//Print out book that contain invalid data
void Menu::Read_Book_Fromfile_Menu() {
    cout << ANSI_GREEN
         << "***********************************" << endl
         << "*        LOAD BOOK SUBMENU        *" << endl
         << "***********************************" << endl;

    while (true) {
        cout << ANSI_GREEN << "Enter 0 to go back to main menu" << endl
             << "Enter 6 to load book from file" << endl
             << "Enter -1 to exit the database" << ANSI_NORMAL << endl;
        read_user_choice();
        if (userMenuChoice != 6) {
            Open_menu();
            break;
        }
        cout << ANSI_MAGENTA << "Please enter the name of your file" << ANSI_NORMAL << endl;
        string userFile;
        getline(cin, userFile);
        try {
            vector<string> wrongData = userDatabase.file_to_database(userFile);
            if (wrongData.empty()) {
                cout << ANSI_YELLOW << "Book successfully loaded from " << userFile << ANSI_NORMAL << endl;
            } else {
                cout << ANSI_YELLOW << "Following books can't be loaded because they " << endl
                     << "have incorrect data or already exist in database" << endl;
                for (string str: wrongData) {
                    cout << str;
                }
                cout << ANSI_NORMAL;
            }
        } catch (const runtime_error& e) {
            cout << ANSI_RED << e.what() << ANSI_NORMAL << endl;
        }
    }
}
