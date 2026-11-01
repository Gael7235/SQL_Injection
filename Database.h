#pragma once

#include <stdexcept>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

class Database
{
private:
	sql::Connection* myConnection;
public:
	Database();
	void outputEmailChoices();
  void signIn();
};
