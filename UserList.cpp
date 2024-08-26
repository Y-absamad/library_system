#include "UserList.h"

UserList::UserList()
{
    capacity = 0;
    usersCount = 0;
}

UserList::UserList(int capacity)
{
    this->capacity = capacity;
    users = new User[capacity];
    usersCount = 0;
}

UserList::~UserList()
{
    delete[] users;
}

void UserList::addUser(User &user)
{
    if (usersCount < capacity)
    {
        user.setId(usersCount + 1);
        users[usersCount++] = user;
    }
    else
    {
        std::cout << "User list is full\n";
    }
}

void UserList::deleteUser(int id)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id)
        {
            while (i < usersCount - 1)
            {
                users[i] = users[i + 1];
                users[i].setId(i + 1);
                i++;
            }
            usersCount--;
            capacity--;
            break;
        }
    }
}

User *UserList::searchUser(string name)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getName() == name)
            return &users[i];
    }
    return nullptr;
}

User *UserList::searchUser(int id)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id)
            return &users[i];
    }
    return nullptr;
}

ostream &operator<<(ostream &output, const UserList &userList)
{
    if (userList.usersCount == 0)
    {
        cout << "------ The user list is empty ------\n";
    }
    else
    {
        for (int i = 0; i < userList.usersCount; i++)
        {
            output << userList.users[i];
        }
    }
    return output;
}
