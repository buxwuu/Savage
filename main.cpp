/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include <string>
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main(void)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;
	driver = sql::mysql::get_driver_instance();
	driver=con->connect("localhost", "root", "storylover");//Will not work on EC2 unless password = toor
	int userid;
	userid = login();
}

int login(){
	string username;
	string password;
	bool done = 0;
	while (!done){
		cout<<"Please enter your username"<<endl;
		getline(cin, username);
		cout<<"Please enter your password"<<endl;
		getline(cin, password);

	}
}