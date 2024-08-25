#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string title;
    string isbn;
    string category;
    int id;
    double avergeRating;
    User author;
    int numRates;
    double sumRates;

public:
    static int count;
    Book();
    Book(string, string, string);
    Book(const Book &book);

    void setTitle(string);
    string getTitle() const;
    void setIsbn(string);
    string getIsbn() const;
    void setCategory(string);
    string getCategory() const;
    void setId(int);
    int getId() const;
    void setAuthor(const User &user);
    User getAuthor() const;

    double getAverageRating() const;
    void ratebook(double);

    bool operator==(const Book &book) const;
    friend istream &operator>>(istream &input, Book &book);
    friend ostream &operator<<(ostream &output, const Book &book);
};
