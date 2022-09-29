#include "Book.h"
#include "Database.h"
#include "Menu.h"
#include <cassert>

using namespace std;

//test all methods in Book class except methods that prompts user to enter in the console
void test_BookClass(){
    Book test1 {"test1Title","test1Author","2020","hardcover","1234567891231","123" };

    //test getters
    assert(test1.get_title()=="test1Title");
    assert(test1.get_author()=="test1Author");
    assert(test1.get_dateOfPublication()==2020);
    assert(test1.get_bookType()=="hardcover");
    assert(test1.get_ISBN()=="1234567891231");
    assert(test1.get_numOfPages()==123);

    //test setters
    test1.set_title("t");
    test1.set_author("a");
    test1.set_dateOfPublication("2019");
    test1.set_bookType("digital");
    test1.set_ISBN("1357924682");
    test1.set_numOfPages("12");

    assert(test1.get_title()=="t");
    assert(test1.get_author()=="a");
    assert(test1.get_dateOfPublication()==2019);
    assert(test1.get_bookType()=="digital");
    assert(test1.get_ISBN()=="1357924682");
    assert(test1.get_numOfPages()==12);

    //test equals()
    Book test2 {"t","a","2019","digital","1357924682","12" };
    Book test3 {"different","test1Author","2020","hardcover","1234567891231","123" };

    assert(test1.equals(test2));
    assert(!test1.equals(test3));

    //test is_dateOfPublication()
    assert(!test1.is_dateOfPublication(""));
    assert(!test1.is_dateOfPublication("alkje8"));
    assert(!test1.is_dateOfPublication("2021"));
    assert(!test1.is_dateOfPublication("0"));
    assert(test1.is_dateOfPublication("2002"));
    assert(test1.is_dateOfPublication("2020"));
    assert(test1.is_dateOfPublication("1970"));
    assert(test1.is_dateOfPublication("2013"));

    //test is_bookType()
    assert(!test1.is_bookType(""));
    assert(!test1.is_bookType("alkje8"));
    assert(!test1.is_bookType("2021"));
    assert(!test1.is_bookType("hardCover"));
    assert(test1.is_bookType("hardcover"));
    assert(test1.is_bookType("softcover"));
    assert(test1.is_bookType("digital"));

    //test is_ISBN()
    assert(!test1.is_ISBN(""));
    assert(!test1.is_ISBN("alkje8"));
    assert(!test1.is_ISBN("123"));
    assert(!test1.is_ISBN("1234567890"));
    assert(test1.is_ISBN("061826941x"));
    assert(test1.is_ISBN("3452679861"));
    assert(test1.is_ISBN("1234567891231"));
    assert(test1.is_ISBN("3454678787652"));

    //test is_allInt()
    assert(!test1.is_allInt(""));
    assert(!test1.is_allInt("alkje8"));
    assert(!test1.is_allInt("  "));
    assert(!test1.is_allInt("-98 0"));
    assert(test1.is_allInt("061826941"));
    assert(test1.is_allInt("3452679861"));
    assert(test1.is_allInt("1234567891231"));
    assert(test1.is_allInt("3454678787652"));

    //test book_to_string()
    assert(test1.book_to_string()=="Title: t     Author: a     Date of publication: 2019     Book type: digital     ISBN: 1357924682     Number of pages: 12\n"
                                   "---------------------\n");
    assert(test2.book_to_string()=="Title: t     Author: a     Date of publication: 2019     Book type: digital     ISBN: 1357924682     Number of pages: 12\n"
                                   "---------------------\n");
}

//test all methods in Menu class except the methods that prompts user to enter in console
void test_MenuClass(){
    Menu test;

    //test is_AllInt()
    assert(!test.is_allInt(""));
    assert(!test.is_allInt("asff"));
    assert(!test.is_allInt("098- 98"));
    assert(test.is_allInt("123"));
    assert(test.is_allInt("-89"));

    //test isSearchCriteriaValid()
    assert(!test.isSearchCriteriaValid("","title"));
    assert(!test.isSearchCriteriaValid("sldkj","title"));
    assert(!test.isSearchCriteriaValid("  (=)","author"));
    assert(!test.isSearchCriteriaValid("(<)123","title"));
    assert(!test.isSearchCriteriaValid("(-)","book type"));
    assert(!test.isSearchCriteriaValid("(0) ","title"));
    assert(!test.isSearchCriteriaValid("asdf(=)","ISBN"));
    assert(!test.isSearchCriteriaValid("(<)dflk","number of pages"));
    assert(!test.isSearchCriteriaValid("(=)   387","date of publication"));

    assert(test.isSearchCriteriaValid("(=)hello","title"));
    assert(test.isSearchCriteriaValid("(=)my name","author"));
    assert(test.isSearchCriteriaValid("(>)1234","date of publication"));
    assert(test.isSearchCriteriaValid("(-)minus","ISBN"));
    assert(test.isSearchCriteriaValid("(-)-123","number of pages"));

    //test findSearchCriteria()
    vector<string> criteriaTest = {"author:(=)hello", "title:(-)jenny"};
    assert(test.findSearchCriteria("author:(=)hello",criteriaTest));
    assert(test.findSearchCriteria("title:(-)jenny",criteriaTest));
    assert(!test.findSearchCriteria("author:(=)jenny",criteriaTest));
    assert(!test.findSearchCriteria("author:(-)hello",criteriaTest));
}

int main() {

    //test class methods except for methods that require user to enter in console
    test_BookClass();
    test_MenuClass();
    //print "success" if all test passed
    cout << "success" << endl;

    Menu test;
    //runs the menu starting from the main menu
    test.Main_menu();
}