#include "User.cpp"
#include "Book.cpp"
#include "UserList.cpp"
#include "BookList.cpp"


UserList *U;
BookList *B;

void main_menu();
void book_menu();
void diplay_search_book_menu();
void displayUpdate();
void user_menu();
void display_search_user_menu();
void displayUpdateUser();

int intgerNumber(string);
int douleNumber(string);


void bookMenuActions();
void createBookAndAddToList();
void assignAuthorToBook(Book &, bool &);
void continueWithoutAssigningAuthor(Book &, bool &);
void SearchForBook();
void searchByName(BookList *, bool &);
void searchById(BookList *, bool &);
void handleBookActions(Book *, bool &);
void updateAuthor(Book *);
void updateTitle(Book *);
void UpdateCategory(Book *);
void deleteBook(Book *, bool &);
void rateBook(Book *);
void displayAllBooks();
void userMenuActions();
void addUser();
void searchForaUser();
void searchUserByName(UserList *, bool &);
void searchUserById(UserList *, bool &);
void handleUserActions(User *, bool &);
void updateName(User *);
void UpdateAge(User *);
void deleteUser(User *, bool &);
void updateEmail(User *);
void displayAllUsers();

void main_menu()
{
    cout << "Select one of the following choices : " << endl;
    cout << "1- Books Menu" << endl;
    cout << "2- Users Menu" << endl;
    cout << "3- Exit " << endl;
}
void book_menu()
{
    cout << "BOOKS MENU" << endl;
    cout << "1- Create a book and add it to the list " << endl;
    cout << "2- Search for a book" << endl;
    cout << "3- Display all books (with book rating)" << endl;
    cout << "4- Back to the main menu" << endl;
}
void diplay_search_book_menu()
{
    cout << "SEARCH FOR A BOOK" << endl;
    cout << "1- Search by name" << endl;
    cout << "2- Search by id" << endl;
    cout << "3- Return to Books Menu" << endl;
}
void displayUpdate()
{
    cout << "1- Update author" << endl;
    cout << "2- Update title" << endl;
    cout << "3- Update Category" << endl;
    cout << "4- Delete Book" << endl;
    cout << "5- rate book" << endl;
    cout << "6- Get back to books menu" << endl;
}
void user_menu()
{
    cout << " USERS MENU" << endl;
    cout << "1- Create a USER and add it to the list " << endl;
    cout << "2- Search for a user " << endl;
    cout << "3- Display all users " << endl;
    cout << "4- Back to the main " << endl;
}
void display_search_user_menu()
{
    cout << "SEARCH FOR A USER" << endl;
    cout << "1- Search by name" << endl;
    cout << "2- Search by id" << endl;
    cout << "3- Return to users Menu" << endl;
}
void displayUpdateUser()
{
    cout << "1- Update name" << endl;
    cout << "2- Update age" << endl;
    cout << "3- Update eamil" << endl;
    cout << "4- Delete user" << endl;
    cout << "5- Get back to users menu" << endl;
}

int intgerNumber(string value)
{
    int choice;
    while (!(cin >> choice))
    {
        cout << "Please enter a " << value << ": ";
        cin.clear();
        cin.ignore();
    }
    return choice;
}
int douleNumber(string value)
{
    double choice;
    while (!(cin >> choice))
    {
        cout << "Please enter a " << value << ": ";
        cin.clear();
        cin.ignore();
    }
    return choice;
}

void bookMenuActions()
{
    bool b6 = true;
    while (b6)
    {
    //start:
        book_menu();
        int choice = intgerNumber("chooes the available options");
        switch (choice)
        {
        case 1: // Create a book and add it to the list
            createBookAndAddToList();
            break;
        case 2: // Search for a book
            SearchForBook();
            break;
        case 3: // Display all books
            displayAllBooks();
            break;
        case 4:
            b6 = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            //goto start;
        }
    }
}
void createBookAndAddToList()
{
    Book book1;
    cin >> book1;

    bool b8 = true;
    while (b8)
    {
    start:
        cout << "\n1- Assign Author" << endl
             << "2- Continue\n";
        int choice8 = intgerNumber("chooes the available options");
        switch (choice8)
        {
        case 1: // Assign Author
            assignAuthorToBook(book1, b8);
            break;
        case 2: // Continue
            continueWithoutAssigningAuthor(book1, b8);
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            goto start;
        }
    }
}
void assignAuthorToBook(Book &book1, bool &b8)
{
    cout << "Enter author (user ) id : ";
    int id = intgerNumber("id");
    User *userId;
    userId = U->searchUser(id);
    if (userId == nullptr)
    {
        cout << "No Author Found with id = " << id << endl;
        cout << "**********************\n";
    }
    else
    {
        book1.setAuthor(*userId);
        B->addBook(book1);
        cout << "-----Added successfully-----\n";
        b8 = false;
    }
}
void continueWithoutAssigningAuthor(Book &book1, bool &b8)
{
    B->addBook(book1);
    cout << "-----Added successfully-----\n";
    b8 = false;
}
void SearchForBook()
{
    bool b7 = true;
    while (b7)
    {
    start:
        diplay_search_book_menu();
        int choice7 = intgerNumber("chooes the available options");
        switch (choice7)
        {
        case 1: // search by name
            searchByName(B, b7);
            break;
        case 2: // search by id;
            searchById(B, b7);
            break;
        case 3:
            b7 = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            goto start;
        }
    }
}
void searchByName(BookList *B, bool &b7)
{
    string name;
    cout << "Enter name for search : ";
    cin.ignore();
    getline(cin, name);
    Book *BookAfterUpdate;
    BookAfterUpdate = B->searchBook(name);
    if (BookAfterUpdate == nullptr)
    {
        cout << " ---- " << name << " : Not Found  "
             << " ----" << endl;
    }
    else
    {
        cout << *BookAfterUpdate;
        handleBookActions(BookAfterUpdate, b7);
    }
}
void searchById(BookList *B, bool &b7)
{
    cout << "Enter id for search : ";
    int id = intgerNumber("id");
    Book *BookAfterUpdate;
    BookAfterUpdate = B->searchBook(id);
    if (BookAfterUpdate == nullptr)
    {
        cout << " ---- " << id << " : Not Found  "
             << " ----" << endl;
    }
    else
    {
        cout << *BookAfterUpdate;
        handleBookActions(BookAfterUpdate, b7);
    }
}
void handleBookActions(Book *book, bool &b7)
{
    while (b7)
    {
    start:
        displayUpdate();
        int choice9 = intgerNumber("chooes the available options");
        switch (choice9)
        {
        case 1: // update Author
            updateAuthor(book);
            break;
        case 2: // update title
            updateTitle(book);
            break;
        case 3: // Update Category
            UpdateCategory(book);
            break;
        case 4: // Delete Book
            deleteBook(book, b7);
            break;
        case 5: // rate book
            rateBook(book);
            break;
        case 6: // Get back to books menu
            b7 = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            goto start;
        }
    }
}
void updateAuthor(Book *BookAfterUpdate)
{
    cout << "enter new id for user : ";
    int id = intgerNumber("id");
    User *userAfterUpdate;
    userAfterUpdate = U->searchUser(id);
    if (userAfterUpdate == nullptr)
    {
        cout << " ---- " << id << " : Not Found  "
             << " ----" << endl;
    }
    else
    {
        Book *BookAfterUpdateAuthor;
        BookAfterUpdateAuthor = BookAfterUpdate;
        BookAfterUpdateAuthor->setAuthor(*userAfterUpdate);
        cout << "------update successful------\n";
    }
}
void updateTitle(Book *BookAfterUpdate)
{
    string NewTitle;
    cout << "Enter new title : ";
    cin.ignore();
    getline(cin, NewTitle);
    Book *BookAfterUpdateTitle;
    BookAfterUpdateTitle = BookAfterUpdate;
    BookAfterUpdateTitle->setTitle(NewTitle);
    cout << "------update successful------\n";
}
void UpdateCategory(Book *BookAfterUpdate)
{
    string NewCategory;
    cout << "Enter new category : ";
    cin.ignore();
    getline(cin, NewCategory);
    Book *BookAfterUpdateCategory;
    BookAfterUpdateCategory = BookAfterUpdate;
    BookAfterUpdateCategory->setCategory(NewCategory);
    cout << "------update successful------\n";
}
void deleteBook(Book *BookAfterUpdate, bool &b7)
{
    Book *BookAfterDelete;
    BookAfterDelete = BookAfterUpdate;
    B->deleteBook(BookAfterDelete->getId());
    cout << "------deleted successfully------\n";
    b7 = false;
}
void rateBook(Book *BookAfterUpdate)
{
    cout << "Enter the Rate for a Book : ";
    double rate = douleNumber("number 1.0 to 5.0");
    Book *BookAfterRate;
    BookAfterRate = BookAfterUpdate;
    BookAfterRate->ratebook(rate);
    BookAfterUpdate = BookAfterRate;
}
void displayAllBooks()
{
    cout << *B;
}

void userMenuActions()
{
    bool b2 = true;
    while (b2)
    {
    start:
        user_menu();
        int choice = intgerNumber("chooes the available options");
        switch (choice)
        {
        case 1: // Create a USER and add it to the list
            addUser();
            break;
        case 2: // Search for a user
            searchForaUser();
            break;
        case 3: // Display all users
            displayAllUsers();
            break;
        case 4: // Back to the main
            b2 = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            goto start;
        }
    }
}
void addUser()
{
    User user;
    cin >> user;
    U->addUser(user);
    cout << "-----Added successfully-----\n";
}
void searchForaUser()
{
    bool b = true;
    while (b)
    {
    start:
        display_search_user_menu();
        int choices = intgerNumber("chooes the available options");
        switch (choices)
        {
        case 1: // search by name
            searchUserByName(U, b);
            break;
        case 2: // search by id
            searchUserById(U, b);
            break;
        case 3: // Return to users Menu
            b = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            goto start;
        }
    }
}
void searchUserByName(UserList *U, bool &b)
{
    string name;
    cout << "Enter name for search : ";
    cin.ignore();
    getline(cin, name);
    User *userAfterUpdate;
    userAfterUpdate = U->searchUser(name);
    if (userAfterUpdate == nullptr)
    {
        cout << " ---- " << name << " : Not Found  "
             << " ----" << endl;
    }
    else
    {
        cout << *userAfterUpdate;
        handleUserActions(userAfterUpdate, b);
    }
}
void searchUserById(UserList *U, bool &b)
{
    cout << "Enter id : ";
    int id = intgerNumber("id");
    User *userAfterUpdate;
    userAfterUpdate = U->searchUser(id);
    if (userAfterUpdate == nullptr)
    {
        cout << " ---- " << id << " : Not Found  "
             << " ----" << endl;
    }
    else
    {
        cout << *userAfterUpdate;
        handleUserActions(userAfterUpdate, b);
    }
}
void handleUserActions(User *user, bool &b)
{
    while (b)
    {
    start:
        displayUpdateUser();
        int choice = intgerNumber("chooes the available options");
        switch (choice)
        {
        case 1: // Update name
            updateName(user);
            break;
        case 2: // update  age
            UpdateAge(user);
            break;
        case 3: // update email
            updateEmail(user);
            break;
        case 4: // delete user
            deleteUser(user, b);
            break;
        case 5: // Get back to users menu
            b = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
            goto start;
        }
    }
}
void updateName(User *userAfterUpdate)
{
    string NewName;
    cout << "Enter new name : ";
    cin.ignore();
    getline(cin, NewName);
    User *userAfterUpdateName;
    userAfterUpdateName = userAfterUpdate;
    userAfterUpdateName->setName(NewName);
    cout << "------update successful------\n";
}
void UpdateAge(User *userAfterUpdate)
{
    int age;
    cout << "Enter new age : ";
    while (!(cin >> age))
    {
        cout << "Please enter a number for age.\nAge : ";
        cin.clear();
        cin.ignore();
    }
    User *userAfterUpdateAge;
    userAfterUpdateAge = userAfterUpdate;
    userAfterUpdateAge->setAge(age);
    cout << "------update successful------\n";
}
void deleteUser(User *userAfterUpdate, bool &b)
{
    User *userAfterdelete;
    userAfterdelete = userAfterUpdate;
    U->deleteUser(userAfterdelete->getId());
    cout << "------delete successful------\n";
    b = false;
}
void updateEmail(User *userAfterUpdate)
{
    string NewEmail;
    cout << "Enter new eamil : ";
    cin.ignore();
    getline(cin, NewEmail);
    User *userAfterUpdateEmail;
    userAfterUpdateEmail = userAfterUpdate;
    userAfterUpdateEmail->setEmail(NewEmail);
    cout << "------update successful------\n";
}
void displayAllUsers()
{
    cout << *U;
}
