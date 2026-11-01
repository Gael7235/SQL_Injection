#include <iostream>
#include "Database.h"
#include <string>
#include <iomanip>

using namespace std;

Database::Database()
{
    hasAccess = false;
    try
    {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();

        myConnection = driver->connect("tcp://localhost:3306", "guest_user_sfpl", "mypassword123");

        myConnection->setSchema("User_Info");
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
        std::cerr << "Error Code: " << e.getErrorCode() << endl;
        std::cerr << "SQL State: " << e.getSQLState() << endl;
    }
}

void Database::signIn()
{

    string email_address_input, password_input;

    cout << "Enter Email: ";
    getline(cin, email_address_input);

    cout << "Enter Password: ";
    getline(cin, password_input);
    cout << endl;

    string query = "SELECT * FROM Users WHERE email_address = '" + email_address_input + "' AND user_password = '" + password_input + "'";

    try
    {
        sql::Statement* Command = myConnection->createStatement();
        sql::ResultSet* row = Command->executeQuery(query);

        if (row->next()) {
            hasAccess = true;
            cout << "Login Successful" << endl;
        }
        else {
            cout << "Login failed" << endl;
        }
    }
    catch (const sql::SQLException& e)
    {
        hasAccess = false;
        cerr << "Login failed: " << e.what() << endl;
    }
}

bool Database::access()
{
    return hasAccess;
}
