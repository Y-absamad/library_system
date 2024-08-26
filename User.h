#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;
class User{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;
    User();
    User(string , int , string , string );  
    User(const User &user);  
    void setName(string);
    string getName()const; 
    void setId(int);
    int getId()const;
    void setAge(int);
    int getAge()const;
    void setPassword(string);
    string getPassword()const;
    void setEmail(string);
    string getEmail()const;
    void display_info();
    bool operator==(const User &user) const;
    friend ostream&operator<<(ostream & output, const User &user);
    friend istream&operator>>(istream &input ,User &user);
};

#endif