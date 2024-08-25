#include "User.h"
#include <limits>
int User::count = 0;
User::User()
{
   name = "";
   age = 0;
   password = "";
   email = "";
   count++;
   id = count;
   
}
User::User(string name, int age, string password, string email)
{
   this->name = name;
   this->age = age;
   this->password = password;
   this->email = email;
   count++;
   id = count;
}
User::User(const User &user)
{
   name = user.name;
   age = user.age;
   password = user.password;
   email = user.email;
   id = user.id;
}
void User::setName(string name)
{
   this->name = name;
}
string User::getName() const
{
   return name;
}
void User::setId(int id )
{
   this->id = id;
}
int User::getId() const
{
   return id;
}
void User::setAge(int age)
{
   this->age = age;
}

int User::getAge() const
{
   return age;
}
void User::setPassword(string password)
{
   this->password = password;
}

string User::getPassword() const
{
   return password;
}
void User::setEmail(string email)
{
   this->email = email;
}

string User::getEmail() const
{
   return email;
}

void User::display_info()
{
   cout << "****************************" << endl;
   cout << "Name  : " << name << endl;
   cout << "Age   : " << age << endl;
   cout << "Id    : " << id << endl;
   cout << "Email : " << email << endl;
   cout << "****************************" << endl;
}

bool User::operator==(const User &user) const
{
   if (name != user.name || age != user.age || password != user.password || email != user.email || id != user.id)
   {
      return false;
   }
   return true;
}

ostream &operator<<(ostream &output, const User &user)
{
   output << "****************************" << endl;
   output << "Name  : " << user.getName() << endl;
   output << "Age   : " << user.getAge() << endl;
   output << "Id    : " << user.getId() << endl;
   output << "Email : " << user.getEmail() << endl;
   output << "****************************" << endl;
   return output;
}

istream &operator>>(istream &input, User &user)
{
   cout << "********** Enter the user info ********** \n";
   string name, email, password;
   int age;
   cout << "Name : ";
   input.ignore(numeric_limits<streamsize>::max(), '\n');
   getline(input , name);
   user.setName(name);

   cout << "Age : ";
   while (!(input >> age))
   {
      cout << "Please enter a number for age.\nAge : ";
      input.clear(); 
      input.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   user.setAge(age);
  
   cout << "Email : ";
   input >> email;
   user.setEmail(email);
   cout << "password : ";
   input >> password;
   user.setPassword(password);
   return input;
}
