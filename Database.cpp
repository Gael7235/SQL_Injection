#include <iostream>
#include "Database.h"
#include <string>
#include <iomanip>

using namespace std;

Database::Database()
{
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

void Database::outputEmailChoices()
{
    sql::Statement* command = myConnection->createStatement();
    sql::ResultSet* row = command->executeQuery("SELECT email_address "
                                                "FROM users");

    while (row->next()) {
        cout << row->getString("email_address") << endl;
    }
}

void Database::signIn()
{
 try
    {
        cout << "Enter Email: ";
        cin >> email_address_input;
        cout << endl;
        
        cout << "Enter Password: ";
        cin >> password_input;
        cout << endl;
        
        sql::PreparedStatement* prepCommand = myConnection->prepareStatement("SELECT * "
                                                                             "FROM Users "
                                                                             "WHERE email_address = ? "
                                                                             "AND user_password = ?);
        prepCommand->setString(1, email_address_input);
        prepCommand->setString(2, password_input);
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
        std::cerr << "Error Code: " << e.getErrorCode() << endl;
        std::cerr << "SQL State: " << e.getSQLState() << endl;
    }
{
