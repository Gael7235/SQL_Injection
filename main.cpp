#include <iostream>
#include "Database.h"
using namespace std;

int main()
{
    Database my_db;
    int input;

    cout << ((my_db.access()) ? "Signed in" : "Not Signed in") << endl;
    cout << endl;

    my_db.signIn();

    cout << ((my_db.access()) ? "Signed in" : "Not Signed in") << endl;

    return 0;
}
