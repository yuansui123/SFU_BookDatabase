#ifndef CMPT135FINALPROJECT_BOOK_H
#define CMPT135FINALPROJECT_BOOK_H

#include <iostream>
#include <string>
#include <time.h>
#include "ansi_codes.h"

using namespace std;

class Book{
private:
    string title;
    string author;
    int dateOfPublication;
    string bookType;
    string ISBN;
    int numOfPages;

public:
    //create a new book with all field entered by parameter
    Book(const string& t, const string& a, const string& d, const string& b, const string& i, const string& n);

    //create a new book with all field prompting user to enter
    Book();

    ~Book();

    //prompt user to enter all field of a book
    void new_book();

    //return title in string
    string get_title() const;

    //return author in string
    string get_author() const;

    //return date of publication in int year
    int get_dateOfPublication() const;

    //return book type in string
    string get_bookType() const;

    //return isbn number in string
    string get_ISBN() const;

    //return number of pagest in int
    int get_numOfPages() const;

    void set_title(const string& t);

    void set_author(const string& a);

    void set_dateOfPublication(const string& d);

    void set_bookType(const string& b);

    void set_ISBN(const string& i);

    void set_numOfPages(const string& n);

    //return true if every field of the book equates
    //return false if there is at least one field that is different
    bool equals(const Book& b);

    //return true if year is later or equal to 1970 and is before or equal to current year
    //return false otherwise
    //year before 1970 is invalid because only book published after 1970 has isbn number
    bool is_dateOfPublication(const string& year);

    //return true is user enter "hardcover" or "softcover" or "digital"
    //return false other wise
    bool is_bookType(const string& s);

    //return true if the user enter a valid 10 digit or 13 digit isbn number
    //return false other wise
    bool is_ISBN(const string& s);

    //return true if user enter all positive digit
    //return false other wise
    bool is_allInt(const string& s);

    //prompt user to enter title until user enter a non-empty string
    void ask_userEnter_title();

    //prompt user to enter author until user enter a non-empty string
    void ask_userEnter_author();

    //prompt user to enter date of publication until user enter a
    //valid date of publication
    void ask_userEnter_dateOfPublication();

    //prompt user to enter book type until user enter a
    //valid book type
    void ask_userEnter_bookType();

    //prompt user to enter isbn number until user enter a
    //valid isbn number
    void ask_userEnter_ISBN();

    //prompt user to enter number of pages until user enter a
    //valid number of pages
    void ask_userEnter_numOfPages();

    //return string format of the book
    string book_to_string();
};

#endif //CMPT135FINALPROJECT_BOOK_H