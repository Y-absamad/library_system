#ifndef USERLIST_H
#define USERLIST_H
#include"User.h"

using namespace std;
class UserList
{
private:
    User *users;
    int capacity;
    int usersCount;

public:
    UserList();
    UserList(int);
    ~UserList();
    void addUser(User &);
    void deleteUser(int);
    User *searchUser(string);
    User *searchUser(int);
    friend ostream &operator<<(ostream &, const UserList &);
};
#endif