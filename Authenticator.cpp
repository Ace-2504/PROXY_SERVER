#include "Authenticator.h"
#include <fstream>
#include <sstream>
#include <functional>

using namespace std;

string hashPassword(const string& password)
{
    hash<string> hasher;
    size_t hashed = hasher(password);

    stringstream ss;
    ss << hashed;
    return ss.str();
}

void Authenticator::loadUsers(const string& filename)
{
ifstream file(filename);
string user, pass, role;
while (file >> user >> pass >> role)
{
users[user] = {pass, role};
}
file.close();
}

string Authenticator::login(const string& user, const string& pass)
{
string hashedPass = hashPassword(pass);

if (users.find(user) != users.end() &&
users[user].first == hashedPass)
{
return users[user].second;
}
return "";
}

void Authenticator::signup(const string& user,
const string& pass,
const string& role)
{
ofstream file("users.txt", ios::app);

string hashedPass = hashPassword(pass);

file << "\n" << user << " " << hashedPass << " " << role << endl;

file.close();
users[user] = {hashedPass, role};
}