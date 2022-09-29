Full name: Yuan Sui (Jenny)
SFU student #: 301415307


Compilation Instructions
------------------------

Please type the following in the command code:
make test
./test

Running Instructions
--------------------

*test.txt file contain a couple book that you can load to your database.
You can use these books to explore the search book submenu.

MAIN MENU:
    After running the program, you will come to the main menu.
    From here, you can select different submenus or choose to
    exit the program by enter integers from -1 t0 6.

ADD BOOK SUBMENU:
    Once you entered 1, you will come to the add book submenu.
    From here, you can select to choose to go back to main
    menu by enter 0 or exit the program by enter -1. If you want
    to add book enter 1. After you entered 1, you will be asked to
    enter the information of the book that you want to add. Here is
    what is considered valid for each field:

    title: must be an non-empty string
    author: must be an non-empty string
    year of publication: must be a valid year after 1970 and before
                         or equal to current year (book published
                         before 1970 don't have isbn number)
    book type: must be "hardcover", "softcover" or "digital"
    isbn number: must be valid 10 or 13 digit isbn number that follow
                 check digit rule (check digit rules followed from
                 https://en.wikipedia.org/wiki/Check_digit)
    number of pages: must be a non-empty positive integer

    - if book added successfully, program will print "Book added successfully!"
    - if book already exist in database, program will print
    "Book record already exist in the database"

    At this point, you can choose to continue adding books by enter 1.
    Or you can choose to exit the program or go back to main page.

DELETE BOOK SUBMENU:
    Once you entered 2, you will come to the delete book submenu.
    From here, you can select to choose to go back to main
    menu by enter 0 or exit the program by enter -1. If you want
    to delete book enter 2. After you entered 2, you will be asked to
    enter the information of the book that you want to delete. See
    above for what value is considered valid.

    - if book deleted successfully, program will print "Book deleted successfully!"
    - if book does not exist in database, book won't be deleted, program will print
    "Book record does not exist in the database"

    At this point, you can choose to continue deleting books by enter 2.
    Or you can choose to exit the program or go back to main page.

UPDATE BOOK SUBMENU:
    Once you entered 3, you will come to the update book submenu.
    From here, you can select to choose to go back to main
    menu by enter 0 or exit the program by enter -1. If you want
    to update book enter 3. After you entered 3, you will be asked to
    enter the field that you want to update. You may only choose from
    the list provided. After wards, you will be asked to enter the
    original information of the book that you want to update. See
    above for what value is considered valid.

    - If the book doesn't exist in database. You will not be allowed to
    enter the updated information.
    - If the book exist in database. You will be asked to enter the updated
    information in the field you indicated earlier.
    - If the book exist in database but your field choice is invalid. You
    will not be allowed to enter the updated information.

    At this point, you can choose to continue updating books by enter 3.
    Or you can choose to exit the program or go back to main page.

SEARCH BOOK SUBMENU:
    Once you entered 4, you will come to the search book submenu.
    From here, you can select to choose to go back to main
    menu by enter 0 or exit the program by enter -1. If you want
    to search book enter 4. After you entered 4, you will be asked to
    enter your search criteria in each field.

    Enter (0) if you don't have any criteria for this field
              of if you finished entering criteria for this field
    Enter (=)hello if you want book with field to equal to "hello"
    Enter (-)hello if you want book with field not equal to "hello"
    Enter (<)2000 if you want book with field smaller than 2000
    Enter (>)2000 if you want book with field bigger than 2000

    for example, if I want "all books from the 1990s with at
    least 200 pages not written by JK Rowling"

    In title criteria I would enter:  (0)
    In author criteria I would enter: (-)JK Rowling
                                      (0)
    In date criteria I would enter:   (>)1989
                                      (<)2000
                                      (0)
    In type criteria I would enter:   (0)
    In ISBN criteria I would enter:   (0)
    In pages criteria I would enter:  (>)199
                                      (0)

    Search criteria considered valid if:
    User search criteria in non-integer field must start with (-), (=)
    User search criteria in integer field must start with (-), (=), (<), or (>)
    User search criteria in integer field must enter integer
    User search criteria for the same field can't be repeated

    - if all search criteria entered correctly, program will proceed to search
    - program will display all book that satisfy the user search criteria
    - program will print "no result" if it find no matching book result

    At this point, you can choose to continue searching books by enter 6.
    Or you can choose to exit the program or go back to main page.

SAVE BOOK SUBMENU:
    Once you entered 5, you will come to the save book submenu.
    From here, you can select to choose to go back to main
    menu by enter 0 or exit the program by enter -1. If you want
    to save book enter 5. After you entered 5, you will be asked to
    enter the name of the file that you want to save the book to.

    - if file opened successfully, book will be saved, program will
    print "Book successfully saved to [your file name]"
    - if file didn't open correctly, book won't be saved, program will
    print "Unable to open file [your file name]"

    At this point, you can choose to continue saving books by enter 5.
    Or you can choose to exit the program or go back to main page.

LOAD BOOK SUBMENU:
    Once you entered 6, you will come to the load book submenu.
    From here, you can select to choose to go back to main
    menu by enter 0 or exit the program by enter -1. If you want
    to load book enter 6. After you entered 6, you will be asked to
    enter the name of the file that you want to load the book from.

    - if file opened successfully, valid book will be loaded, program will
    print "Book successfully saved to [your file name]"
    - if file opened successfully, but there are invalid book, program will
    display all book that can't be loaded
    - Book is considered invalid if they don't have valid values or because
    they already exist in database.
    - if file didn't open correctly, book won't be loaded, program will
    print "Unable to open file [your file name]"

    At this point, you can choose to continue saving books by enter 6.
    Or you can choose to exit the program or go back to main page.

Key Features
------------

1. Every new book is constructed after checking that all values are valid. Methods used
to check valid data are also tested extensively in main().

2. Every new book is added or loaded to the database after checking it doesn't already
exist in database. There won't be repeated books or invalid book in the database.

3. Every user input is checked for its validity. Methods used to check valid user input
are also tested extensively in main().

4. Use error handling technique to ensure that user input and thrown error won't crash
the program. Will ask user to re-enter bad input.

5. Every loaded book will be checked for its validity. Incorrect book from file will not
be loaded and program will display these incorrect book to user.

6. Search book submenu allow for complex searches. For example, user can select multiple
field searches: book not written by J.K Rowlin, but has at least 200 pages, and are in
softcover. Also, user can select multiple searches in a single field or more fields:
book writen by J.K Rowlin and written by Jenny sui, but has more than 200 pages and less
than 300 pages, and are published between year 1980 and 2002.

Bugs and Limitations
--------------------

Search limitation: Beside title, search can't find multiple books in the same field.
For example, search can find books name "hello" or "hi". However, search can't find
books with type "hardcover" or "softcover". If user want to find book with type
"hardcover" or "softcover", they need to search for books that are not "digital".
This is because, the first criteria will select fitted book from the database, but
the second criteria will select fitted book from the previous criteria's list instead
of from the database.

All People, Websites, and Sources of Help
-----------------------------------------

used the following website to learn how to get current year:
https://stackoverflow.com/questions/8343676/how-to-get-current-Date-and-time

used previous instructor file to change color of console,
approved by Mr. Donaldson:
see "ansi_codes.h"