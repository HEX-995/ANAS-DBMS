#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

int main()
{
    try
    {
        // Connect to MySQL server (X Protocol uses port 33060)
        Session session("localhost", 33060, "root", "19517305");

        // Select database
        Schema db = session.getSchema("cpp_test");

        // Select table
        Table students = db.getTable("students");

        // Execute query
        RowResult res = students.select("*").execute();

        // Print results
        for (Row row : res)
        {
            cout << "ID: " << row[0] << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Age: " << row[2] << endl;
            cout << "----------------------" << endl;
        }
        
    }
    catch (const mysqlx::Error &err)
    {
        cout << "Error: " << err.what() << endl;
    }

    return 0;
}