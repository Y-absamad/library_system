#include "BookList.h"
//#include"Book.h"

BookList::BookList()
{
    capacity = 0;
    booksCount = 0;
}

BookList::BookList(int capacity)
{
    this->capacity = capacity;
    books = new Book[capacity];
    booksCount = 0;
}

void BookList::addBook(Book &book)
{
    if (booksCount < capacity)
    {
        book.setId(booksCount + 1);
        books[booksCount++] = book;
    }
    else
        cout << "Book list is full\n";
}

Book *BookList::searchBook(string name)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getTitle() == name)
            return &books[i];
    }
    return nullptr;
}
Book *BookList::searchBook(int id)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getId() == id)
            return &books[i];
    }
    return nullptr;
}

void BookList::deleteBook(int id)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getId() == id)
        {
            while (i < booksCount - 1)
            {
                books[i] = books[i + 1];
                books[i].setId(i + 1);
                i++;
            }
            booksCount--;
            capacity--;
            break;
        }
    }
}

Book &BookList::operator[](int position)
{
    if (position < 0 || position >= booksCount)
    {
        cout << "Position Error\n";
    }
    else
    {
        return books[position];
    }
}


BookList::~BookList()
{
    delete[] books;
}

ostream &operator<<(ostream &output, const BookList &booklist)
{
    if (booklist.booksCount == 0)
    {
        output << "------The Booklist is Empty------\n";
    }
    else
    {
        for (int i = 0; i < booklist.booksCount; i++)
        {
            output << booklist.books[i];
        }
    }
    return output;
}
