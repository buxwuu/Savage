/*

This file has NOT BEEN TESTED.  
This is a slightly modified version of the original main.cpp with changes that allow for automated testing.
New variables (slightly redundant) have been created for this purpose.

CHANGES:
The old main() function is now gamestart(), a function called by test(), which is itself called in main().
The test() function includes a pre-loading of cin that allows input to be created in the script before the game is run.  The game should be run automatically.
New variables created for cin to load (input1, input2, etc...)
This file is set up to create a user on run.  If run more than once, this process will necessarily fail (assuming it works at all).
    One should change the initial 1 in the pre-loading of cin to a 2 to make it a login process instead of creation.

CONCERNS:
Not sure how the pre-loaded cin will handle the "Press enter to continue..." scenario.  Might freeze until user hits the bar?  Not sure.



*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h).
*/
#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql::mysql;

int login();
int createUser();
void youdie();
void start();
void Lukeshome2();
void Tatooine();
void Lukeshome();
void randomcave();
void talktoluke();
void test();
void gameStart(void);

string update;
string update2;
int input;
int input1;
int input2;
int input3;
int input4;
int userid;
sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res;
sql::PreparedStatement *pstmt;


int main(void){
  test();
  
  return 0;
}

int gameStart(void)
{
	driver = sql::mysql::get_driver_instance();
	con=driver->connect("localhost", "root", "toor");//Will not work on EC2 unless password = toor
	con->setSchema("techtest");
	userid = login();
	start();
}

int login(){
	string username;
	string password;
	string choice;
	cout<<"Would you like to create an account or log in?\n1. Create account\n2. Log in"<<endl;
	getline(cin, choice);
	while (true){
		if(choice=="1"){
			userid=createUser();
			if (userid!=-1){
				return userid;
			}
		}
		cout<<"Please enter your username"<<endl;
		getline(cin, username);
		cout<<"Please enter your password"<<endl;
		getline(cin, password);
		pstmt=con->prepareStatement("SELECT player_ID FROM player_info WHERE username='"+username+"' AND password='"+password+"'");
		res=pstmt->executeQuery();
		if (!res->first()){
			cout<<"User not found. Enter again or create account?\n1. Create account\n2. Enter again"<<endl;
			getline(cin, choice);
			delete pstmt;
			delete res;
			goto fin;
		}
		userid=res->getInt("player_ID");
		cout<<"Welcome "<<username<<". You are logged in"<<endl;
		delete pstmt;
		delete res;
		return userid;
		fin:;
	}
}

int createUser(){
	string username;
	string password;
	int test;
	string choice="0";
	while (choice!="2"){
		cout<<"Enter your desired username: ";
		getline(cin, username);
		cout<<"Enter your desired password: ";
		getline(cin, password);
		pstmt=con->prepareStatement("SELECT player_ID FROM player_info WHERE username='"+username+"'");
		res=pstmt->executeQuery();
		if(res->first()){
			cout<<"ERROR: User already exists. Try again or log in?\n1. Try again\n2. Log in"<<endl;
			getline(cin, choice);
		}
		else{
			delete pstmt;
			pstmt=con->prepareStatement("INSERT INTO player_info (username, password) VALUES ('"+username+"', '"+password+"')");
			pstmt->executeUpdate();
			delete pstmt;
			delete res;
			pstmt=con->prepareStatement("SELECT player_ID FROM player_info WHERE username='"+username+"'");
			res=pstmt->executeQuery();
			res->first();
			cout<<"Welcome "<<username<<". You are logged in"<<endl;
			return res->getInt("player_ID");
		}
		delete pstmt;
		delete res;
	}
	return -1;
}

void start(){
	cout <<"Welcome to Albuquerque" << endl;
    cout << "1. Play" <<endl;
    cout << "2. Exit" <<endl;
    cin >> input;
    switch (input){
		case 1:
		    cout<<"Let the game begin"<<endl<<endl;
		    cout<<"A long time ago, before Tupac but not really before Tupac.  Luke Skywalker has returned to his \
home planet of Tatooine in order to. . .you know what I don't remember, it's been too long since I've \
seen the Star Wars movies.  I think he needs to find a way to defeat the Empire. . .which brings up a \
funny question.  Isn't the Empire the good guys?  I mean they want law and order in the universe, while \
Luke and his band of smugglers are trying to overthrow it.  Anyway maybe we got a little to over our heads \
n this one. . .just please do me a favor and lower your expectations, we promise we'll make it up to you \
as the game goes on.  We are all pressed for time in our other classes anyway, we had to dig hard for \
jokes.  Even the dude I saw bathing in the Boulder Creek River got to put a joke in here.  Anyway, not to \
keep you waiting anymore, here is 'The Empire Strikes Back' starring Sam Berger as Han Solo, Kevin \
Kirk as Darth Vader, Hunter Haller as Chewbacca, Max Hayne as Luke Skywalker and Krishna Adettiwar as \
The Emperor."<<endl<<endl;
		    Tatooine();
    }
}

void Tatooine(){

	system("read -p 'Press Enter to continue...' var");
	cout << "You are now playing as a Rebel Soldier on Tatooine, your current mission is to meet up with Luke Skywalker." << endl<<endl;
	cout << "1. Go to Luke's destroyed home" << endl;
	cout << "2. Go explore that cave"<<endl;
        cout<<"3. Save and quit\n"<<endl;
	cin >> input1;
	switch (input1) {
	    case 1:
	    	Lukeshome();
	    	break;
	    case 2:
	    cout<<" On your way to the cave you you came across Luke."<<endl;
            Lukeshome();
            system("read -p 'Press Enter to continue...' var");
            break;
	}
}

void Lukeshome(){

	system("read -p 'Press Enter to continue...' var");
	cout << "Luke - I need your help to load this stuff onto The Millennium Falcon, so we can go and blow up The Death Star" << endl;
	cout << "However, I lost my light saber and I need help finding it, can you get it for me?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> input2;
	switch (input2)
	{
		case 1:
		    talktoluke();
		    break;
		case 2:
		    youdie();
		    break;
	}
}

void Lukeshome2(){
    cout << "You - Luke, I got your lightsaber."<<endl;
    cout << " Luke - Good job man!" << endl;
    
    system("read -p 'End of test. Press Enter to close the game...' var");
    
}

void talktoluke(){

	system("read -p 'Press Enter to continue...' var");
	cout << "Sweet, I was jumped by some smugglers while bull's-eyeing womp rats in my t-16, they took my light saber. . .can you retrieve it for me? " << endl<<endl;
	cout << "1. Sure (Isn't this a sign that Luke is a serial killer?)" << endl;
	cout << "2. No (I am not helping out this psychopath)"  << endl<<endl;
	cin >> input3;

	switch (input3){
		case 1:
		    randomcave();
		    break;
		case 2:
		    youdie();
		    break;
	}
}

void randomcave(){

    system("read -p 'Press Enter to continue...' var");
    cout << " Smuggler - What are you doing here?" << endl;
    cout << " You - I am looking around for something that you may have."<<endl;
    cout << " Smuggler - What may that be?"<<endl;
    cout << " You - A lightsaber."<<endl;
    cout << " Smiggler - I have one of those, but it'll cost you."<<endl;
    cout << " 1. Continue talking to him." << endl;
    cout << " 2. Reach for your blaster pistol" <<endl;
    cin >> input4;
    
    system("read -p 'Press Enter to continue...' var");

    switch (input4)
    {
            
        case 1:
            cout << "You - How much?"<<endl;
            cout << "Smuggler - Your life."<<endl;
            cout<<" You reach for your blaster pistol and a firefight ensues. . .you manage to kill 3 of the 5 smugglers, but the other 2 escape.  However, you did manage to find and secure Luke's lightsaber, but on the flipside you were shot in the arm."<<endl;
            break;
        case 2:
            cout<<"You reach for your blaster pistol and a firefight ensues. . .you manage to kill 3 of the 5 smugglers, but the other 2 escape.  However, you did manage to find and secure Luke's lightsaber."<<endl;
            break;
    }
    system("read -p 'Press Enter to continue...' var");

    Lukeshome2();
    
}

void youdie(){

	cout << "Luke - Well then I don't need you any more! *shoots you with a blaster pistol*\nYou have lost" << endl;
	system("read -p 'Press Enter to close the game...' var");
}

void test(){
  
  cout << "This is an automated test running through all the main features of the game!" << endl;
  cout << "This version has veen slightly modified to allow automated testing." << endl;
  cout << "You should see a user get created/logged in, as well as the primary events of a working version of the story.  Enjoy!\n\n\n";
  
  
  istringstream iss("1 sampleUser samplePassword 1 1 1 1 2"); //change the initial 1 to a 2 to login instead of making a new user.  Making a new user will only work once!
  cin.rdbuf(iss.rdbuf());
  while(cin >> choice >> username >> password >> input >> input1 >> input2 >> input3 >> input4|| !cin.eof()) {
      if(cin.fail()) {
          cin.clear();
          string dummy;
          cin >> dummy;
          continue;
      }
      gamestart();
  }
  
}




