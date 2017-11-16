/*To compile and run this code on the EC2 machine, use these commands:
g++ -o test -I/usr/include -I/usr/include/cppconn -Wl,-Bdynamic CppSqlTest.cpp -lmysqlcppconn
./test
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

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
using namespace sql::mysql;

sql::Driver *driver;
sql::Connection *con;
sql::Statement *test;
sql::ResultSet *res;
sql::PreparedStatement *pstmt;

int main(int argc, char const *argv[])
 {
	driver = sql::mysql::get_driver_instance();
	con = driver->connect("localhost", "root", "toor");
	con->setSchema("prasanna");

	string test = "C";
	pstmt = con->prepareStatement("SELECT gender FROM player_info WHERE gender = '"+test+"'");
	res = pstmt->executeQuery();
	if (!res->first()){
		cout<<"Nope"<<endl;
		exit(0);
	}
	while (res->next()){
		cout<<res->getString("gender")<<endl;
	}
	cout<<"1"<<endl;
	//delete test;
	cout<<"1"<<endl;
	delete con;
	cout<<"1"<<endl;
	delete res;
	cout<<"1"<<endl;
 	return EXIT_SUCCESS;
 }
