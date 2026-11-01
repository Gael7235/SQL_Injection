#include <iostream>
#include "Database.h"
using namespace std;

int main()
{
    Database my_db;
    int input;

    cout << "Email Addresses: " << endl;
    my_db.outputEmailChoices();

    my_db.signIn();

    return 0;
}
