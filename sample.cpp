#include "acsdb.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

using namespace std;



int main(){
    MXPSQL::ACSharpDB::ACSharpDB db;

    srand(time(NULL));

    db.load("test.acsdb");

    bool status = db.setCollection("Collection");
    bool status2 = db.setCollection("Collection2");
    MXPSQL::ACSharpDB::ACSharpCollection coll;
    MXPSQL::ACSharpDB::ACSharpCollection coll2;

    coll = db.getCollection("Collection");
    coll2 = db.getCollection("Collection2");

    coll2.set("key2", to_string(rand() % 10 + 1));
    coll.set("key", "notkeypair");
    coll.set("key", "pair");

    vector<string> coll_list = db.listCollections();
    int vectorcount = coll_list.size();

    cout << "Sample ACSharpDB program" << endl;

    // keypair and status
    cout << "db collection 1 status: " << status << endl << "db collection 2 status: " << status2 << endl << endl;
    cout << "db collection 1 key value: " << coll.get("key") << endl << "db collection 2 key2 value: " << coll2.get("key2") << endl << endl;

    // show size of collection and lists them
    cout << endl << endl;

    cout << "count of db collection: " << vectorcount << endl;
    cout << "list of collection keys:" << endl;

    vector<std::string>::iterator it;

    for(it=coll_list.begin();it!=coll_list.end();it++)
    {
        cout << *it << endl;
    }

    cout << endl << endl;

    // get the db string
    cout << "db string: " << endl << db.getString() << endl << endl;

    // get the toml table
    cout << "db table string: " << endl << db.getTomlTable() << endl << "\nAnd the type of the tbl is: " << typeid(db.getTomlTable()).name() << endl << endl;

    cout << "Dumping file" << endl;
    bool dumpstatus = db.Dump();
    cout << "Dump status: " << dumpstatus << endl << endl;
    cout << "End of program" << endl;

    return 0;
}