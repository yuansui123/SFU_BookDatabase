#include "Book.h"

//create a new book with all field entered by parameter
Book::Book(const string& t, const string& a, const string& d, const string& b, const string& i, const string& n){
    //check if all data are valid
    if(is_dateOfPublication(d) && is_bookType(b) && is_ISBN(i) && is_allInt(n)){
        set_title(t);
        set_author(a);
        set_dateOfPublication(d);
        set_bookType(b);
        set_ISBN(i);
        set_numOfPages(n);
    } else{
        throw runtime_error("At least one of the value doesn't follow correct format");
    }
}

//create a new book with all field prompting user to enter
Book::Book(){
    new_book();
}

Book::~Book(){}

//prompt user to enter all field of a book
void Book::new_book(){
    ask_userEnter_title();
    ask_userEnter_author();
    ask_userEnter_dateOfPublication();
    ask_userEnter_bookType();
    ask_userEnter_ISBN();
    ask_userEnter_numOfPages();
}

string Book::get_title() const{
    return title;
}

string Book::get_author() const{
    return author;
}

int Book::get_dateOfPublication() const{
    return dateOfPublication;
}

string Book::get_bookType() const{
    return bookType;
}

string Book::get_ISBN() const{
    return ISBN;
}

int Book::get_numOfPages() const{
    return numOfPages;
}

void Book::set_title(const string& t){
    title = t;
}

void Book::set_author(const string& a){
    author = a;
}

void Book::set_dateOfPublication(const string& d){
    dateOfPublication = stoi(d);
}

void Book::set_bookType(const string& b){
    bookType = b;
}

void Book::set_ISBN(const string& i){
    ISBN = i;
}

void Book::set_numOfPages(const string& n){
    numOfPages = stoi(n);
}

//return true if every field of the book equates
//return false if there is at least one field that is different
bool Book::equals(const Book& b){
    return title == b.get_title() &&
           author == b.get_author() &&
           dateOfPublication == b.get_dateOfPublication() &&
           bookType == b.get_bookType() &&
           ISBN == b.get_ISBN() &&
           numOfPages == b.get_numOfPages();
}

//return true if year is later or equal to 1970 and is before or equal to current year
//return false otherwise
//year before 1970 is invalid because only book published after 1970 has isbn number
bool Book::is_dateOfPublication(const string& year){
    if(!is_allInt(year)) return false;

    //get current year
    int s = stoi(year);
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int current_year = aTime->tm_year + 1900;

    if(s < 1970 || s > current_year) return false;
    return true;
}

//return true is user enter "hardcover" or "softcover" or "digital"
//return false other wise
bool Book::is_bookType(const string& s){
    return s=="hardcover" || s=="softcover" || s=="digital";
}

//return true if the user enter a valid 10 digit or 13 digit isbn number
//return false other wise
bool Book::is_ISBN(const string& s){

    if(s.size() == 10 || s.size() == 13) {
        if (s.size() == 10) {
            //check if user enter invalid value
            if (!is_allInt(s.substr(0, 9))) return false;
            if ((s[9] < 48 || s[9] > 57) && s[9] != 'x') return false;

            int digitSum = 0;
            for (int i = 0; i < s.size() - 1; i++) {
                digitSum += stoi(s.substr(i, 1)) * (10 - i);
            }
            //check isbn number's check digit
            if (digitSum % 11 == 0) {
                return s[9] == '0';
            } else if (digitSum % 11 == 1) {
                return s[9] == 'x';
            } else {
                return digitSum % 11 + stoi(s.substr(9, 1)) == 11;
            }
        }

        if (s.size() == 13) {
            //check if user enter invalid value
            if (!is_allInt(s)) return false;

            int digitSum = 0;
            for (int i = 0; i < s.size(); i++) {
                digitSum += stoi(s.substr(i, 1)) * (1 + (i % 2) * 2);
            }
            //check isbn number's check digit
            if (digitSum % 10 == 0) return true;
            return false;
        }
    }
    return false;
}

//return true if user enter all positive digit
//return false other wise
bool Book::is_allInt(const string& s){
    if(s.size()==0) return false;
    for(int i = 0; i < s.size(); i ++){
        if(s[i]<48 || s[i]>57){
            return false;
        }
    }
    return true;
}

//prompt user to enter title until user enter a non-empty string
void Book::ask_userEnter_title(){
    while(true) {
        cout << ANSI_BLUE << "Please enter the title of the book record" << ANSI_NORMAL << endl;
        string t;
        getline(cin,t);
        if (t != "") {
            set_title(t);
            break;
        }
        cout << ANSI_RED << "Title can't be empty" << ANSI_NORMAL << endl;
    }
}

//prompt user to enter author until user enter a non-empty string
void Book::ask_userEnter_author(){
    while(true) {
        cout << ANSI_BLUE << "Please enter the author of the book record" << ANSI_NORMAL << endl;
        string a;
        getline(cin, a);
        if (a != "") {
            set_author(a);
            break;
        }
        cout << ANSI_RED << "Author can't be empty" << ANSI_NORMAL << endl;
    }
}

//prompt user to enter date of publication until user enter a
//valid date of publication
void Book::ask_userEnter_dateOfPublication(){
    while(true) {
        cout << ANSI_BLUE << "Please enter the year of publication of the book record" << ANSI_NORMAL << endl;
        string y;
        getline(cin,y);
        if (is_dateOfPublication(y)) {
            set_dateOfPublication(y);
            break;
        }
        cout << ANSI_RED << "Date of publication must be an valid Date before or equal to the current Date" << ANSI_NORMAL << endl;
    }
}

//prompt user to enter book type until user enter a
//valid book type
void Book::ask_userEnter_bookType(){
    while(true) {
        cout << ANSI_BLUE << "Please enter the type of the book record" << endl
             << R"((choose from "hardcover" , "softcover", "digital"))" << ANSI_NORMAL << endl;
        string b;
        getline(cin,b);
        if (is_bookType(b)) {
            set_bookType(b);
            break;
        }
        cout << ANSI_RED << "Book type is invalid" << ANSI_NORMAL << endl;
    }
}

//prompt user to enter isbn number until user enter a
//valid isbn number
void Book::ask_userEnter_ISBN(){
    while(true) {
        cout << ANSI_BLUE << "Please enter the ISBN number (do not include hyphen)"
             << "of the book record" << ANSI_NORMAL << endl;
        string i;
        getline(cin, i);
        if (is_ISBN(i)) {
            set_ISBN(i);
            break;
        }
        cout << ANSI_RED << "ISBN number is invalid" << ANSI_NORMAL << endl;
    }
}

//prompt user to enter number of pages until user enter a
//valid number of pages
void Book::ask_userEnter_numOfPages(){
    while(true) {
        cout << ANSI_BLUE << "Please enter the number of pages of the book record" << ANSI_NORMAL << endl;
        string n;
        getline(cin, n);
        if (is_allInt(n)) {
            set_numOfPages(n);
            break;
        }
        cout << ANSI_RED << "Number of pages must be a non-empty positive integer" << ANSI_NORMAL << endl;
    }
}

//return string format of the book
string Book::book_to_string(){
    return "Title: " + title + "     " +
           "Author: " + author + "     " +
           "Date of publication: " + to_string(dateOfPublication) + "     " +
           "Book type: " + bookType + "     " +
           "ISBN: " + ISBN + "     " +
           "Number of pages: " + to_string(numOfPages) + "\n" +
           "---------------------" + "\n";
}

