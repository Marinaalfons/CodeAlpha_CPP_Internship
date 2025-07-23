#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <cstdlib> 
using namespace std;

bool userExists(string username) {
    ifstream file("users.txt");
    string u ,p;
    while (file >> u >> p) {
    if (u == username) {
    return true;}
    }
    return false;
}

void Register() {
int tcheck=1; 
    while (true) {
    system("cls");
string username, password;
cout << "\n*********** Register **********\n";
cout << "Enter new username: ";
cin >> username;

if (userExists(username)) {
cout << "Username already exists. Try another.\n";
}
else {
while(tcheck==1){
cout << "Enter new password: ";
cin >> password;
int tcheck_pas=password.length();

if(tcheck_pas>=6)
{ tcheck=0;}
else if(tcheck_pas<=5)
{cout<<"The password must contain at least 6 characters \n";
tcheck=1;} 
}
hash<string> hasher;
size_t hashedPass = hasher(password);
ofstream file("users.txt", ios::app);
file << username << " " << hashedPass << endl;

cout << "Registration successful!\n";}

int back;
cout << "\nDo you want to go back Enter 0 : ";
cin >> back;
if (back == 0) break;  }
}


void Login() {
    while (true) {
system("cls");
string username, password;
cout << "\n*********** Login **********\n";
cout << "Enter username: ";
cin >> username;
cout << "Enter password: ";
cin >> password;

hash<string> hasher;
size_t hashedInput = hasher(password);

ifstream file("users.txt");
string u,p;
bool found = false;

while (file >> u >> p) {
if (u == username && p == to_string(hashedInput)) {
found = true;
break; }  }

if (found) {
   cout << "Login successful! Welcome, " << username << "!\n"; } 
   else {
    cout << "Login failed. Invalid username or password.\n"; }

int back;
cout << "\nDo you want to go back Enter 0 : ";
cin >> back;
if (back == 0) break; 
    }
}

int main() {
int choice;
do {
system("cls");
cout << "****** WELCOME ******\n";
cout << "1. Register\n"<< "2. Login\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1:
  Register();
  break;
case 2:
  Login();
  break;
default:
cout << "Invalid choice. Try again.\n"; }

} while (choice != 0);

    return 0;
}