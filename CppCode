#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void stringupdate();
void Tatoonine();
void Lukeshome();
void randomcave();
void talktoluke();
int input;
void youdie();
string update;
string update2;

int main()
{
     cout << "\n Welcome to Albuquerque" << endl;
     cout << "\n 1. Play" <<endl;
     cout << "\n 2. Exit" <<endl;
     cout << "\n" << endl;
     cin >> input;

     switch (input){

 case 1:
    update = "Let the game begin";
    update2 = "A long time ago, before Tupac but not really before Tupac.  Luke Skywalker has returned to his home planet of Tatooine in order to. . .you know what I don't remember, it's been to long since I've seen the Star Wars movies.  I think he needs to find a way to defeat the Empire. . .which brings up a funny question.  Isn't the Empire the good guys?  I mean they want law and order in the universe, while Luke and his band of smugglers are trying to overthrow it.  Anyway maybe we got a little to over our heads on this one. . .just please do me a favor and lower your expectations, we promise we'll make it up to you as the game goes on.  We are all pressed for time in our other classes anyway, we had to dig hard for jokes.  Even the dude I saw bathing in the Boulder Creek River got to put a joke in here.  Anyway, not to keep you waiting anymore, here is 'The Empire Strikes Back' starring Same Berger as Han Solo, Kevin Kirk as Darth Vader, Hunter Haller as Chewbacca, Max Hayne as Luke Skywalker and Krishna Adettiwar as The Emperor.";
    cout << "\n"  << endl;
    stringupdate();
    system("read -p 'Press Enter to continue...' var");
    Tatoonine();
     }



}

void Tatoonine(){

cout << "You are now playing as a Rebel Soldier on Tatooine, your current mission is to meet up with Luke Skywalker." << endl;
cout << "\n" << endl;
cout << "1. Go to Luke's destroyed home" << endl;
cout << "2. Go explore that cave" << endl;
cout << "\n" << endl;
cin >> input;
switch (input) {

    case 1:
    Lukeshome();

    case 2:
    randomcave();

}

}

void Lukeshome(){

system("clear");
cout << "I need your help to load this stuff onto The Millennium Falcon, so we can go and blow up The Death Star" << endl;
cout << "However, I lost my light saber and I need help finding it, can you get it for me?" << endl;
cout << "1. Yes" << endl;
cout << "2. No" << endl;
cin >> input;

system("read -p 'Press Enter to continue...' var");

switch (input)
{

case 1:
    talktoluke();
case 2:
    youdie();

}


}

void talktoluke(){

cout << "Sweet, I was jumped by some smugglers while bull's-eyeing womp rats in my t-16, they took my light saber. . .can you retrieve it for me? " << endl;
cout << "\n"  << endl;
system("read -p 'Press Enter to continue...' var");
system("clear");
cout << "1. Sure (Isn't this a sign that Luke is a serial killer?)" << endl;
cout << "2. No (I am not helping out this psychopath)"  << endl;
cin >> input;
cout << "\n" <<endl;
system("read -p 'Press Enter to continue...' var");

switch (input)
{

case 1:
    randomcave();
case 2:
    youdie();

}



}

void randomcave(){

system("clear");
cout << " Smuggler - What are you doing here?" << endl;

}

void youdie(){

cout << "Luke - Well then I don't need you any more! *shoots you with a blaster pistol*" << endl;

system("read -p 'Press Enter to continue...' var");

exit(0);
}

void stringupdate() {

    cout << "\n " << update << endl;
    cout << "\n ";

    if (update2 != "") {
        cout << "\n " << update2 << endl;
        cout << "\n ";
    }

    return;

}
