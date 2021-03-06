/*To compile and run this code on the EC2 machine, use these commands:
cd /var/www/html/Savage
g++ -o test -I/usr/include -I/usr/include/cppconn -Wl,-Bdynamic main.cpp -lmysqlcppconn
./test
*/

/*NOTES TO KEVIN:
	LONG STRINGS CAN GO ON MULTIPLE LINES USING A BACKSLASH (SEE START() FOR EXAMPLE)
	NO NEED FOR BOTH <<ENDL AND \N, THEY BOTH CREATE A NEW LINE
	I REMOVED STRINGUPDATE(), JUST PRINT STRAIGHT TO COUT
		SEE START() FOR EXAMPLE 
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <sstream>
#include <cstdio>
#include <limits>
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
void checkProgress();
void start();
void Tatooine();
void Lukeshome();
void obiwan();
void randomcave();
string update;
string update2;
string userstr;
char instr;
stringstream inss;
int input;
int userid;
sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res;
sql::PreparedStatement *pstmt;

int main(void){
	driver = sql::mysql::get_driver_instance();
	con=driver->connect("localhost", "root", "toor");//Will not work on EC2 unless password = toor
	con->setSchema("techtest");
        while (true){
            system("read -p 'Press Enter to begin...' var");
            userid = login();
            stringstream ss;
            ss<<userid;
            userstr=ss.str();
            checkProgress();
        }
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
			pstmt=con->prepareStatement("INSERT INTO player_info (username, password) VALUES ('"+username+"', '"+password+"')");
			pstmt->executeUpdate();
			delete pstmt;
            pstmt=con->prepareStatement("INSERT INTO inventory (blaster, lightsaber, grenade) VALUES ('0', '0', '0')");
            pstmt->executeUpdate();
            delete pstmt;
			pstmt=con->prepareStatement("SELECT player_ID FROM player_info WHERE username='"+username+"'");
			res=pstmt->executeQuery();
			res->first();
			cout<<"Welcome "<<username<<". You are logged in"<<endl;
            test = res->getInt("player_ID");
			return test;
		}
		delete pstmt;
		delete res;
	}
	return -1;
}

void checkProgress(){
    cout<<"Checking for previous save..."<<endl;
    pstmt=con->prepareStatement("SELECT progress FROM player_info WHERE player_ID = "+userstr);
    res=pstmt->executeQuery();
    int x;
    res->first();
    x = res->getInt("progress");
    delete pstmt;
    delete res;
    if (x!=0){
        here:;
        cout<<"Previous save file found.\n1. Resume from save\n2. Create new game"<<endl;
        cin.get(instr);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (instr!='2' && instr!='1'){
            cout<<"INVALID OPTION"<<endl;
            goto here;
        }
        if (instr=='2'){
            pstmt=con->prepareStatement("UPDATE inventory SET blaster = 0, lightsaber = 0, grenade = 0 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
            pstmt=con->prepareStatement("UPDATE player_info SET luke = 0, obiwan = 0, progress = 0 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
            cout<<"Previous save wiped successfully\n"<<endl;
        }
    }
    switch(x){
        case 0:
            start();
            break;
        case 1:
            Tatooine();
            break;
        case 2:
            obiwan();
            break;
        case 3:
            randomcave();
            break;
    }
}

void start(){
    here:;
    cout <<"Welcome to Albuquerque" << endl;
    cout << "1. Play" <<endl;
    cout << "2. Exit" <<endl;
    cin.get(instr);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (instr!='1' && instr!='2'){
        cout<<"INVALID OPTION"<<endl;
        goto here;
    }
    input = instr - '0';
    switch (input){
        case 1:
    	    cout<<string(100,'\n');
    	    cout<<"Let the game begin"<<endl<<endl;
        	usleep(500000);
    	    cout<<"A long time ago, before Tupac but not really before Tupac"<<endl;
        	usleep(1250000);
    	    cout<<"Luke Skywalker has returned to his home planet of Tatooine in order to. . ."<<endl;
        	usleep(1250000);
    	    cout<<"You know what I don't remember, it's been too long since i've seen the Star Wars movies"<<endl;
        	usleep(1250000);
    	    cout<<"I think he needs to find a way to defeat the Empire. . .which brings up a funny question"<<endl;
        	usleep(1250000);
    	    cout<<"Isn't the Empire the good guys?  I mean they want law and order in the universe"<<endl;
        	usleep(1250000);
    	    cout<<"While Luke and his band of smugglers are trying to overthrow it"<<endl;
        	usleep(1250000);
    	    cout<<"Anyway maybe we got a little to over our heads on this one. . ."<<endl;
        	usleep(1250000);
    	    cout<<"Just please do me a favor and lower your expectations"<<endl;
        	usleep(1250000);
    	    cout<<"We promise we'll make it up to you as the game goes on"<<endl;
        	usleep(1250000);
    	    cout<<"We are all pressed for time in our other classes anyway, we had to dig hard for jokes"<<endl;
        	usleep(1250000);
    	    cout<<"Even the dude I saw bathing in the Boulder Creek River got to put a joke in here"<<endl;
        	usleep(1250000);
    	    cout<<"Anyway, not to keep you waiting anymore, here is 'The Empire Strikes Back' starring Sam Berger as Han Solo"<<endl;
        	usleep(1250000);
    	    cout<<"Kevin Kirk as Darth Vader, Hunter Haller as Chewbacca, Max Hayne as Luke Skywalker"<<endl;
        	usleep(1250000);
    	    cout<<"And Krishna Adettiwar as The Emperor"<<endl<<endl;
    	    for (int i=0;i<60;i++){
    	    	usleep(600000);
    	    	cout<<endl;
    	    }
        	usleep(1);
            cout<<"You are now playing as a Rebel Soldier on Tatooine, your current mission is to meet up with Luke Skywalker"<<endl;
        	usleep(500000);
            cout<<"You currently have no weapons\n"<<endl;
            Tatooine();
            break;
        case 2:
            cout<<"Goodbye"<<endl;
            break;
    }
}

void Tatooine(){
    system("read -p 'Press Enter to continue...' var");
    bool grenade;
    bool luke;
    pstmt = con->prepareStatement("SELECT luke FROM player_info WHERE player_ID = "+userstr);
    res=pstmt->executeQuery();
    res->first();
    luke = res->getInt("luke");
    delete res;
    delete pstmt;
    pstmt = con->prepareStatement("SELECT grenade FROM inventory WHERE player_ID = "+userstr);
    res=pstmt->executeQuery();
    res->first();
    grenade = res->getInt("grenade");
    delete res;
    delete pstmt;
    here:
	usleep(750000);
    cout<<"To the west, you see a dome-like building"<<endl;
	usleep(750000);
    cout<<"To the east, you see a mountain region with a small cave entrance built in"<<endl;
	usleep(750000);
    cout<<"To the north, you see a worn-down home structure\n"<<endl;
	usleep(750000);
    if (luke==0)cout<<"1. Go to the dome-like building"<<endl;
    cout<<"2. Go to the cave"<<endl;
    if (grenade==0)cout<<"3. Go to the worn-down home"<<endl;
    cout<<"4. Save and quit"<<endl;
    cin.get(instr);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (isblank(instr)){
        cout<<"INVALID OPTION"<<endl;
        goto here;
    }
    input = instr - '0';
    switch (input) {
        case 1:
            if (luke==1){
                cout<<"INVALID OPTION"<<endl;
                goto here;
            }
            Lukeshome();
            break;
        case 2:
            randomcave();
            break;
        case 3:
            if (grenade==1){
                cout<<"INVALID OPTION"<<endl;
                goto here;
            }
            obiwan();
            break;
        case 4:
            pstmt=con->prepareStatement("UPDATE player_info SET progress = 1 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            cout<<"Your progress has been saved, thanks for playing!"<<endl;
            return;
        default:
            cout<<"INVALID OPTION"<<endl;
            goto here;
    }
}

void Lukeshome(){
	usleep(750000);
    cout<<"As you enter the building, you see a man you immediately recognize as Luke Skywalker meditating on the floor"<<endl;
	usleep(750000);
    cout<<"He looks up at you as you enter"<<endl;
	usleep(750000);
    cout<<"Luke - Ah, you're the one they've sent to help me, glad to have you!"<<endl;
	usleep(750000);
    cout<<"I have lost my lightsaber and I need you to recover it for me" << endl;
	usleep(750000);
    cout<<"I was jumped by some smugglers while bulls-eyeing womp-rats in my T-16. I think they are set up in that cave by the mountain"<<endl;
	usleep(750000);
    cout<<"Here, take my spare blaster, you might need it!"<<endl;
	usleep(750000);
    pstmt=con->prepareStatement("UPDATE inventory SET blaster = 1 WHERE player_ID = "+userstr);
    pstmt->executeUpdate();
    delete pstmt;
    cout<<"BLASTER ACQUIRED\n"<<endl;
    system("read -p 'Press Enter to continue...' var");
	usleep(250000);
    cout<<"If you haven't already, you may want to visit Obi-Wan at his home, he might be able to supply you with other gear as well"<<endl;
	usleep(750000);
    cout<<"Either way, may the Force be with you"<<endl;
	usleep(750000);
    cout<<"You leave the dwelling\n"<<endl;
    pstmt=con->prepareStatement("UPDATE player_info SET luke = 1 WHERE player_ID = "+userstr);
    pstmt->executeUpdate();
    delete pstmt;
    Tatooine();
}

void obiwan(){
    pstmt=con->prepareStatement("SELECT blaster FROM inventory WHERE player_ID = "+userstr);
    res=pstmt->executeQuery();
    res->first();
    int x;
    x = res->getInt("blaster");
    delete res;
    delete pstmt;
    pstmt=con->prepareStatement("SELECT obiwan FROM player_info WHERE player_ID = "+userstr);
    res=pstmt->executeQuery();
    res->first();
    bool obi;
    string guess;
    obi = res->getInt("obiwan");
    delete res;
    delete pstmt;
	usleep(750000);
    cout<<"You arrive at the small hut. Pushing the ragged flap covering the entrance aside, you enter..."<<endl;
	usleep(750000);
    cout<<"An old man sits at a table in the center of the dwelling"<<endl;
	usleep(750000);
    cout<<"He looks up at you as you enter"<<endl;
	usleep(750000);
    if (obi==0){
        cout<<"Obi-Wan - Ah, a visitor! How can I help you?\n";
    	usleep(750000);
        cout<<"You - I've come to help Luke Skywalker, can you assist?\n";
    	usleep(750000);
        if (x==0){
        	cout<<"Obi-Wan - He lives in the dome-shaped building nearby"<<endl;
        	usleep(750000);
        	cout<<"Obi-Wan - If you prove yourself worthy, I can also give you a handy piece of gear\n"<<endl;
        } 
        else cout<<"Obi-Wan - If you prove yourself worthy, I can give you a handy piece of gear\n\n";
    }
    else cout<<"Obi-Wan - You're back, change your mind on that challenge?"<<endl;
    here:
    cout<<"1. I'll try your challenge\n";
    cout<<"2. This isn't worth my time, thanks anyway old man\n";
    if (x==1) cout<<"3. *Reach for blaster* I think I'll just take it from you, thanks very much\n";
    else cout<<"3. *LOCKED*\n";
    cout<<"4. Save and quit\n";
    cin.get(instr);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (isblank(instr)){
        cout<<"INVALID OPTION"<<endl;
        goto here;
    }
    input = instr - '0';
    switch (input){
        case 1:
        	usleep(750000);
            cout<<"Obi-Wan - If you can answer this question correct, I'll give you what you need"<<endl;
        	usleep(750000);
            cout<<"Obi-Wan - This should be simple for a rebel soldier like you"<<endl;
        	usleep(750000);
            cout<<"Obi-Wan - What was the name of the Star Destroyer that Darth Vader commanded?"<<endl<<"You - ";
            getline(cin, guess);
            if (guess=="Executor"||guess=="executor"||guess=="EXECUTOR"){
        		usleep(250000);
                cout<<"Obi-Wan - Indeed. It was the most fearsome Star Destroyer I've ever come across"<<endl;
	        	usleep(750000);
                cout<<"Obi-Wan - Well, I suppose I owe you this"<<endl;
    	    	usleep(750000);
                cout<<"He hands you a small sphere"<<endl;
        		usleep(750000);
                cout<<"GRENADE ACQUIRED"<<endl;
                pstmt=con->prepareStatement("UPDATE inventory SET grenade = 1 WHERE player_ID = "+userstr);
                pstmt->executeUpdate();
                delete pstmt;
            }
            else{
        		usleep(750000);
                cout<<"Obi-Wan - Incorrect, I'm afraid"<<endl;
        		usleep(750000);
                cout<<"I'm afraid I must ask you to leave now"<<endl;
            }
            pstmt=con->prepareStatement("UPDATE player_info SET obiwan = 1 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
        	usleep(750000);
            cout<<"You leave the old man's dwelling\n"<<endl;
            Tatooine();
            break;
        case 2:
            pstmt=con->prepareStatement("UPDATE player_info SET obiwan = 1 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
        	usleep(250000);
            cout<<"Obi-Wan - May the Force be with you, return if you wish"<<endl;
        	usleep(750000);
            cout<<"You exit the dwelling\n"<<endl;
            Tatooine();
            break;
        case 3:
            if (x==0){
        		usleep(200000);
                cout<<"INVALID OPTION"<<endl;
        		usleep(200000);
                goto here;
            }
        	usleep(750000);
            cout<<"Obi-Wan - Very well"<<endl;
        	usleep(750000);
            cout<<"He hands over a small sphere"<<endl;
        	usleep(200000);
            cout<<"GRENADE ACQUIRED"<<endl;
        	usleep(750000);
            cout<<"Obi-Wan - Now leave my home, and don't come back"<<endl;
        	usleep(750000);
            pstmt=con->prepareStatement("UPDATE inventory SET grenade = 1 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
            pstmt=con->prepareStatement("UPDATE player_info SET luke = 1 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
            cout<<"You leave the old man's dwelling\n"<<endl;
            Tatooine();
        case 4:
            pstmt=con->prepareStatement("UPDATE player_info SET progress = 2 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
        	usleep(200000);
            cout<<"Your progress has been saved, thanks for playing!"<<endl;
            break;
        default:
        	usleep(200000);
            cout<<"INVALID OPTION"<<endl;
        	usleep(200000);
            goto here;
            break;
    }
}

void randomcave(){
    srand(time(NULL));
    int chance;
	usleep(750000);
    cout<<"\nYou enter the cave, and spot 5 smugglers gathered around a campfire"<<endl;
	usleep(750000);
    cout<<"Unfortunately, they seem to have spotted you too!"<<endl;
	usleep(750000);
    cout<<"Smuggler - You've messed up, boy! *draws blaster*"<<endl;
	usleep(750000);
    pstmt=con->prepareStatement("SELECT * FROM inventory WHERE player_ID = "+userstr);
    res=pstmt->executeQuery();
    res->first();
    int blaster;
    int grenade;
    blaster = res->getInt("blaster");
    grenade = res->getInt("grenade");
    delete res;
    delete pstmt;
    chance = rand() % 100 + 1;
    here:
    cout<<"1. Charge with your fists (25% chance to succeed)"<<endl;
    if (blaster==1) cout<<"2. Pull your blaster (50% chance to succeed)"<<endl;
    else cout<<"2. *LOCKED*"<<endl;
    if (grenade==1) cout<<"3. Throw the grenade (75% chance to succeed)"<<endl;
    else cout<<"3. *LOCKED*"<<endl;
    if (grenade==1 && blaster==1) cout<<"4. Throw the grenade and pull your blaster (100% chance to succeed)"<<endl;
    else cout<<"4. *LOCKED*"<<endl;
    cout<<"5. Save and quit\n"<<endl;
    cin.get(instr);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (isblank(instr)){
        cout<<"INVALID OPTION"<<endl;
        goto here;
    }
    input = instr - '0';
    switch (input){
        case 1:
            cout<<"You rolled a "<<chance<<" out of 100"<<endl;
            system("read -p 'Press Enter to continue...' var");
            if (chance>74){
                cout<<"You charge the smugglers, yelling wildly with your fists raised"<<endl;
	        	usleep(750000);
	            cout<<"You charge catches them off guard, you smash the first smugglers nose with a nice right hook"<<endl;
    	    	usleep(750000);
                cout<<"He goes down and you grab his blaster"<<endl;
        		usleep(750000);
                cout<<"Using his body as a shield, you snap off two shots, taking down the closest smugglers"<<endl;
        		usleep(750000);
                cout<<"The survivors flee"<<endl;
            }
            else{
                cout<<"You charge the smugglers, yelling wildly with your fists raised"<<endl;
	        	usleep(750000);
                cout<<"The one who spoke shoots you down, laughing with his friends as your vision goes dark"<<endl;
    	    	usleep(750000);
                cout<<"YOU HAVE DIED"<<endl;
        		usleep(250000);
                cout<<"GAME OVER"<<endl;
                pstmt=con->prepareStatement("UPDATE inventory SET blaster = 0, lightsaber = 0, grenade = 0 WHERE player_ID = "+userstr);
                pstmt->executeUpdate();
                delete pstmt;
                pstmt=con->prepareStatement("UPDATE player_info SET luke = 0, obiwan = 0, progress = 0 WHERE player_ID = "+userstr);
                pstmt->executeUpdate();
                delete pstmt;
                return;
            }
        case 2:
            if (blaster==1){
                cout<<"You rolled a "<<chance<<" out of 100"<<endl;
                system("read -p 'Press Enter to continue...' var");
                if (chance>49){
                    cout<<"You pull your blaster and take cover behind a nearby boulder"<<endl;
		        	usleep(750000);
                    cout<<"A blaster shot hits your shoulder, wounding your arm"<<endl;
        			usleep(750000);
                    cout<<"You fire off a few shots, taking down three of the smugglers"<<endl;
		        	usleep(750000);
                    cout<<"The remaining 2 smugglers flee"<<endl;
                }
                else{
                    cout<<"You dive behind the nearest boulder"<<endl;
        			usleep(750000);
                    cout<<"You pull your blaster, only managing to take down one smuggler before the others shoot you down"<<endl;
		        	usleep(750000);
                    cout<<"YOU HAVE DIED"<<endl;
        			usleep(750000);
                    cout<<"GAME OVER"<<endl;
                    pstmt=con->prepareStatement("UPDATE inventory SET blaster = 0, lightsaber = 0, grenade = 0 WHERE player_ID = "+userstr);
                    pstmt->executeUpdate();
                    delete pstmt;
                    pstmt=con->prepareStatement("UPDATE player_info SET luke = 0, obiwan = 0, progress = 0 WHERE player_ID = "+userstr);
                    pstmt->executeUpdate();
                    delete pstmt;
                    return;
                }
            }
            else{
    			usleep(200000);
                cout<<"INVALID OPTION"<<endl;
        		usleep(200000);
                goto here;
            }
            break;
        case 3:
            if (grenade==1){
                cout<<"You rolled a "<<chance<<" out of 100"<<endl;
                system("read -p 'Press Enter to continue...' var");
            	if (chance>74){
            		cout<<"Reacting fast, you press the detonation button on the grenade"<<endl;
		        	usleep(750000);
            		cout<<"You underhand toss it right into the center of the large group"<<endl;
        			usleep(750000);
            		cout<<"Diving behind the closest boulder, you dodge a few panicked laser shots"<<endl;
		        	usleep(750000);
            		cout<<"With a deafening bang, the grenade explodes"<<endl;
        			usleep(750000);
            		cout<<"Peeking out from behind the boulder, you see four smugglers dead, the other has fled"<<endl;
            	}
            	else{
            		cout<<"You fumble for the grenade in your pack"<<endl;
		        	usleep(750000);
            		cout<<"Pulling it out, you just manage to arc your arm back before the smugglers fire"<<endl;
        			usleep(750000);
            		cout<<"As you hit the ground, the light starts to fade"<<endl;
		        	usleep(750000);
                    cout<<"YOU HAVE DIED"<<endl;
        			usleep(750000);
                    cout<<"GAME OVER"<<endl;
                    pstmt=con->prepareStatement("UPDATE inventory SET blaster = 0, lightsaber = 0, grenade = 0 WHERE player_ID = "+userstr);
                    pstmt->executeUpdate();
                    delete pstmt;
                    pstmt=con->prepareStatement("UPDATE player_info SET luke = 0, obiwan = 0, progress = 0 WHERE player_ID = "+userstr);
                    pstmt->executeUpdate();
                    delete pstmt;
                    return;
            	}
            }
            else{
        		usleep(200000);
                cout<<"INVALID OPTION"<<endl;
        		usleep(200000);
                goto here;
            }
            break;
        case 4:
        	if (grenade==1 && blaster==1){
        		cout<<"With lightning speed, you arm the grenade and toss it into the group of smugglers"<<endl;
	        	usleep(750000);
        		cout<<"Before they even have a chance to react, you take cover behind the nearest boulder"<<endl;
    	    	usleep(750000);
        		cout<<"You gun down those smugglers who were quick enough to even try to run"<<endl;
        	}
        	else{
        		usleep(200000);
                cout<<"INVALID OPTION"<<endl;
        		usleep(200000);
                goto here;
        	}
            break;
        case 5:
            pstmt=con->prepareStatement("UPDATE player_info SET progress = 3 WHERE player_ID = "+userstr);
            pstmt->executeUpdate();
            delete pstmt;
        	usleep(200000);
            cout<<"Your progress has been saved, thanks for playing!"<<endl;
            break;
        default:
        	usleep(200000);
            cout<<"INVALID OPTION"<<endl;
        	usleep(200000);
            goto here;
        	break;
    }
    system("read -p 'Press Enter to continue...' var");
    cout<<"You search the bodies, finding Luke's lightsaber on the first smuggler's corpse"<<endl;
	usleep(500000);
    cout<<"LIGHTSABER ACQUIRED"<<endl;
    pstmt=con->prepareStatement("UPDATE inventory SET lightsaber = 1 WHERE player_ID = "+userstr);
    pstmt->executeUpdate();
    delete pstmt;
    system("read -p 'Press Enter to continue...' var");
    cout<<"YOU WIN"<<endl;
	usleep(250000);
    cout<<"CONGRATULATIONS"<<endl;
	usleep(750000);
    cout<<"GAME OVER"<<endl;
    pstmt=con->prepareStatement("UPDATE inventory SET blaster = 0, lightsaber = 0, grenade = 0 WHERE player_ID = "+userstr);
    pstmt->executeUpdate();
    delete pstmt;
    pstmt=con->prepareStatement("UPDATE player_info SET luke = 0, obiwan = 0, progress = 0 WHERE player_ID = "+userstr);
    pstmt->executeUpdate();
    delete pstmt;
    return;
}