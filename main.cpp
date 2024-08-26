#include"main.h"

int main()
{
    B = new BookList(100);
    U = new UserList(100);
    bool b1 = true;

    while (b1)
    {
        main_menu();
        int choice1 = intgerNumber("chooes the available options");
        switch (choice1)
        {
        case 1: // book_menu
            bookMenuActions();
            break;
        case 2: // Users Menu
            userMenuActions();
            break;
        case 3: // Exit
            b1 = false;
            break;
        default:
            cout << "---Please chooes the available options---\n\n";
        }
    }
    delete B;
    delete U;
    return 0;
}
