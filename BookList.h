#include <iostream>
using namespace std;
class BookList
{
private:
    Book *books;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(int);
    void addBook(Book &);
    ~BookList();
    friend ostream &operator<<(ostream &, const BookList &);
    Book *searchBook(string);
    Book *searchBook(int);
    void deleteBook(int);
    Book &operator[](int);
};
