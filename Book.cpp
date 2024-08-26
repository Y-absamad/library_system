#include "Book.h"
#include"User.h"
#include <limits>

int Book::count = 0;

Book::Book()
{
    title = "";
    isbn = "";
    category = "";
    count++;
    id = count;
    avergeRating = 0.0;
    numRates = 0;
    sumRates = 0.0;
}
Book::Book(string title, string isbn, string category)
{
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    count++;
    id = count;
    avergeRating = 0.0;
}

Book::Book(const Book &book)
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    id = book.id;
    avergeRating = book.avergeRating;
    author = book.author;
    avergeRating = book.avergeRating;
    numRates = book.numRates;
    sumRates = book.sumRates;
}

void Book::setTitle(string title)
{
    this->title = title;
}

string Book::getTitle() const
{
    return title;
}

void Book::setIsbn(string isbn)
{
    this->isbn = isbn;
}

string Book::getIsbn() const
{
    return isbn;
}
void Book::setCategory(string category)
{
    this->category = category;
}

string Book::getCategory() const
{
    return category;
}

void Book::setId(int id)
{
    this->id = id;
}

int Book::getId() const
{
    return id;
}

void Book::setAuthor(const User &user)
{
    author = user;
}

User Book::getAuthor() const
{
    return author;
}

double Book::getAverageRating() const
{
    return avergeRating;
}

void Book::ratebook(double rating)
{
    if (rating >= 0.0 && rating <= 5.0)
    {
        numRates++;
        sumRates += rating;
        avergeRating = sumRates / numRates;
        cout << "-----Rating added-----\n";

    }
    else{
        cout<<"Invalid rating. Rating must be between 0 and 5.\n\n";
    }
}

bool Book::operator==(const Book &book) const
{
    return title == book.title && isbn == book.isbn && category == book.category && id == book.id && author == book.author && avergeRating == book.avergeRating;
}
istream &operator>>(istream &input, Book &book)
{
    cout << "********** enter the book info **********\n";
    string title, isbn, category;
    
    cout << "Enter Title    : ";
    input.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(input, title);
    book.setTitle(title);
    
    cout << "Enter isbn     : ";
    input >> isbn;
    input.ignore(numeric_limits<streamsize>::max(), '\n');
    book.setIsbn(isbn);


    cout << "Enter category : ";
    getline(input, category);
    book.setCategory(category);

    return input;
}

ostream &operator<<(ostream &output, const Book &book)
{
    output << "****************************\n"
           << "title        : " << book.getTitle() << "\n"
           << "isbn         : " << book.getIsbn() << "\n"
           << "id           : " << book.getId() << "\n"
           << "category     : " << book.getCategory() << "\n"
           << "avergeRating : " << book.getAverageRating() << "\n";
    if (!book.getAuthor().getName().empty())
        output << "author       : " << book.getAuthor().getName() << "\n";
    output << "****************************\n";

    return output;
}
