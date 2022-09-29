#include "Database.h"

Database::Database(){}

Database::~Database(){}

//Return -1 if book b is not in the allBookRecords vector
//Return the index of book b if it is in allBookRecords vector
int Database::find_book(const Book& b){
    for(int i = 0; i < allBookRecords.size(); i++){
        if(allBookRecords.at(i).equals(b)){
            return i;
        }
    }
    return -1;
}

//Add book b to database if book b does not exist in database
//Throw an error other wise
void Database::add_book(const Book& b){
    if(find_book(b)==-1){
        allBookRecords.push_back(b);
    } else{
        throw runtime_error("Book record already exist in the database");
    }
}

//Delete book b from database if book b exist in database
//Throw an error other wise
void Database::delete_book(const Book& b){
    int index = find_book(b);
    if( index != -1) {
        allBookRecords.erase(allBookRecords.begin() + index);
    } else{
        throw runtime_error ("Book record does not exist in the database");
    }
}

//Update book b from database if book b exist in database
//Update book b from database if field exist for book b
//Throw an error other wise
void Database::update_book(const Book& b, const string& f){
    int index = find_book(b);
    if(index == -1) throw runtime_error("Book not found in database");
    if(f=="title"){
        allBookRecords.at(index).ask_userEnter_title();
    } else if(f=="author"){
        allBookRecords.at(index).ask_userEnter_author();
    } else if(f=="date of publication"){
        allBookRecords.at(index).ask_userEnter_dateOfPublication();
    } else if(f=="book type"){
        allBookRecords.at(index).ask_userEnter_bookType();
    } else if(f=="ISBN"){
        allBookRecords.at(index).ask_userEnter_ISBN();
    } else if(f=="number of pages"){
        allBookRecords.at(index).ask_userEnter_numOfPages();
    } else{
        throw runtime_error(f + " is not a valid option for book update");
    }
}

//Return a vector containing book that satisfy user search criteria
vector<Book> Database::search_book(const vector<string>& userSearchCriteria){

    vector<Book> searchResult;

    //Iterate through each search criteria
    for(int i = 0; i < userSearchCriteria.size(); i++){
        string currentCriteria = userSearchCriteria.at(i);

        if(currentCriteria.find("title:") == 0){
            search_title(currentCriteria.substr(6), searchResult);
        } else if(userSearchCriteria.at(i).find("author:") == 0){
            search_author(currentCriteria.substr(7), searchResult);
        } else if(userSearchCriteria.at(i).find("date of publication:") == 0){
            search_date(currentCriteria.substr(20), searchResult);
        } else if(userSearchCriteria.at(i).find("book type:") == 0){
            search_type(currentCriteria.substr(10), searchResult);
        } else if(userSearchCriteria.at(i).find("ISBN:") == 0){
            search_isbn(currentCriteria.substr(5), searchResult);
        } else if(userSearchCriteria.at(i).find("number of pages:") == 0){
            search_pages(currentCriteria.substr(16), searchResult);
        }
    }
    return searchResult;
}

//Add book or delete book from searchResult according to user search criteria for title
void Database::search_title(const string& userChoice, vector<Book>& searchResult) {
    //if the search result is empty
    if (searchResult.empty()) {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_title() == userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_title() != userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        }
    } else {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_title() == userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_title() == userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        }
    }
}

//Add book or delete book from searchResult according to user search criteria for author
void Database::search_author(const string& userChoice, vector<Book>& searchResult){
    //if search result is empty
    if (searchResult.empty()) {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_author() == userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            for (Book b: allBookRecords) {
                //iterate through database
                if (b.get_author() != userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        }
    } else {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through existing search result
            //can't iterate through database because there are previous criteria that has to be met
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_author() != userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_author() == userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        }
    }
}

//Add book or delete book from searchResult according to user search criteria for date
void Database::search_date(const string& userChoice, vector<Book>& searchResult){
    if (searchResult.empty()) {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_dateOfPublication() == stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_dateOfPublication() != stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(>)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_dateOfPublication() > stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(<)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_dateOfPublication() < stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        }
    } else {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_dateOfPublication() != stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_dateOfPublication() == stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(>)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_dateOfPublication() <= stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(<)") {
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_dateOfPublication() >= stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        }
    }
}

//Add book or delete book from searchResult according to user search criteria for book type
void Database::search_type(const string& userChoice, vector<Book>& searchResult){
    if (searchResult.empty()) {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_bookType() == userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_bookType() != userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        }
    } else {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_bookType() != userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_bookType() == userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        }
    }
}

//Add book or delete book from searchResult according to user search criteria for isbn
void Database::search_isbn(const string& userChoice, vector<Book>& searchResult){
    if (searchResult.empty()) {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_ISBN() == userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_ISBN() != userChoice.substr(3)) {
                    searchResult.push_back(b);
                }
            }
        }
    } else {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_ISBN() != userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_ISBN() == userChoice.substr(3)) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        }
    }
}

//Add book or delete book from searchResult according to user search criteria for pages
void Database::search_pages(const string& userChoice, vector<Book>& searchResult){
    if (searchResult.empty()) {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_numOfPages() == stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_numOfPages() != stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(>)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_numOfPages() > stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        } else if (userChoice.substr(0, 3) == "(<)") {
            //iterate through database
            for (Book b: allBookRecords) {
                if (b.get_numOfPages() < stoi(userChoice.substr(3))) {
                    searchResult.push_back(b);
                }
            }
        }
    } else {
        if (userChoice.substr(0, 3) == "(=)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_numOfPages() != stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(-)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_numOfPages() == stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(>)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_numOfPages() <= stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        } else if (userChoice.substr(0, 3) == "(<)") {
            //iterate through existing search result
            for (int i = 0; i < searchResult.size(); i++){
                if (searchResult.at(i).get_numOfPages() >= stoi(userChoice.substr(3))) {
                    searchResult.erase(searchResult.begin()+i);
                    i--;
                }
            }
        }
    }
}

//Save book from database to file if file can be opened correctly
//Save book from database to file if database is not empty
//Throw an error otherwise
void Database::database_to_file(const string& fileName){
    if(allBookRecords.size()==0){
        throw runtime_error("Book records can't be saved as there is no book records in the database");
    }

    ofstream fileOut(fileName);

    if(fileOut.fail()) {
        throw runtime_error("Unable to open file " + fileName);
    }

    string bookRecords = database_to_string();

    fileOut << bookRecords;

    fileOut.close();
}

//Load file to database if file can be opened
//Load file to database if book has right format, valid value and doesn't previously exist in database
//Throw an error if file can't be opened
//Return a vector of string that has wrong format and invalid value
vector<string> Database::file_to_database(const string& fileName){
    ifstream fileIn(fileName);

    if(fileIn.fail()) {
        throw runtime_error("Unable to open file " + fileName);
    }

    vector<string> wrongBookRecords;

    string b = "";
    while(getline(fileIn, b)){
        if(b!="---------------------"){
            try{
                Book currentBook = string_to_book(b);
                add_book(currentBook);
            } catch(const runtime_error &){
                wrongBookRecords.push_back(b + "\n---------------------\n");
            }
        }
    }

    fileIn.close();

    return wrongBookRecords;
}

//Convert type string to type book
//Return type book if book has right format and data
//Throws an error other wise
Book Database::string_to_book(const string& str){
    int titleIndex = str.find("Title: ") + 7;
    int authorIndex = str.find("Author: ") + 8;
    int dateIndex = str.find("Date of publication: ") + 21;
    int bookTypeIndex = str.find("Book type: ") + 11;
    int ISBNIndex = str.find("ISBN: ") + 6;
    int pagesIndex = str.find("Number of pages: ") + 17;

    string inputTitle = str.substr(titleIndex,authorIndex - 8 - 5 - titleIndex);
    string inputAuthor = str.substr(authorIndex,dateIndex - 21 - 5 - authorIndex);
    string inputDate = str.substr(dateIndex,bookTypeIndex - 11 - 5 - dateIndex);
    string inputBookType = str.substr(bookTypeIndex,ISBNIndex - 6 - 5 - bookTypeIndex);
    string inputISBN = str.substr(ISBNIndex,pagesIndex - 17 - 5 - ISBNIndex);
    string inputPages = str.substr(pagesIndex,str.size() - pagesIndex);

    Book b{inputTitle, inputAuthor, inputDate, inputBookType, inputISBN, inputPages};
    return b;
}

//Return a string of all books in the database
string Database::database_to_string(){
    string str = "";
    for(int i = 0; i < allBookRecords.size(); i++){
        str += allBookRecords.at(i).book_to_string();
    }
    return str;
}
