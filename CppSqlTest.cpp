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

int main(int argc, char const *argv[])
 {
	sql::Driver *driver;
	sql::Connection *con;
	//sql::Statement *test;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;

	driver = sql::mysql::get_driver_instance();
	con = driver->connect("localhost", "root", "toor");
	con->setSchema("prasanna");

	pstmt = con->prepareStatement("SELECT gender FROM player_info WHERE gender = 'M'");
	res = pstmt->executeQuery();
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
