#ifndef CMPT135FINALPROJECT_DATABASE_H
#define CMPT135FINALPROJECT_DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.h"
#include "ansi_codes.h"

using namespace std;

class Database{
private:
    vector<Book> allBookRecords;

public:
    Database();

    ~Database();

    //Return -1 if book b is not in the allBookRecords vector
    //Return the index of book b if it is in allBookRecords vector
    int find_book(const Book& b);

    //Add book b to database if book b does not exist in database
    //Throw an error other wise
    void add_book(const Book& b);

    //Delete book b from database if book b exist in database
    //Throw an error other wise
    void delete_book(const Book& b);

    //Update book b from database if book b exist in database
    //Update book b from database if field exist for book b
    //Throw an error other wise
    void update_book(const Book& b, const string& f);

    //Return a vector containing book that satisfy user search criteria
    vector<Book> search_book(const vector<string>& userSearchCriteria);

    //Add book or delete book from searchResult according to user search criteria for title
    void search_title(const string& userChoice, vector<Book>& searchResult);

    //Add book or delete book from searchResult according to user search criteria for author
    void search_author(const string& userChoice, vector<Book>& searchResult);

    //Add book or delete book from searchResult according to user search criteria for date
    void search_date(const string& userChoice, vector<Book>& searchResult);

    //Add book or delete book from searchResult according to user search criteria for book type
    void search_type(const string& userChoice, vector<Book>& searchResult);

    //Add book or delete book from searchResult according to user search criteria for isbn
    void search_isbn(const string& userChoice, vector<Book>& searchResult);

    //Add book or delete book from searchResult according to user search criteria for pages
    void search_pages(const string& userChoice, vector<Book>& searchResult);

    //Save book to from database to file if file can be opened correctly
    //Throw an error otherwise
    void database_to_file(const string& fileName);

    //Load file to database if file can be opened
    //Load file to database if book has right format and valid value
    //Throw an error if file can't be opened
    //Return a vector of string that has wrong format and invalid value
    vector<string> file_to_database(const string& fileName);

    //Convert type string to type book
    //Return type book
    //Throws an error other wise
    Book string_to_book(const string& str);

    //Return a string of all books in the database
    string database_to_string();
};

#endif //CMPT135FINALPROJECT_DATABASE_H