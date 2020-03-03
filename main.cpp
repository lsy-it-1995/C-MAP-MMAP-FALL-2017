#include <iostream>
#include "mmap.h"
#include "map.h"
using namespace std;

int main()
{
    MMap<string, int>alex;

    //    cout<<"||||||||||"<<endl;
    //    cout<<alex<<endl;
    //    cout<<"||||||||||"<<endl;

    alex["gary"] += 2;
    alex["aff"] += 3;
    alex["212fsad"] += 4;
    alex["fker"] += 5;
    cout<<alex<<endl;
    cout<<"123"<<endl;
    MMap<string,int>::Iterator it(alex.begin());
    cout<<"23"<<endl;
    for(; it!=alex.end();++it)
    {
        cout<<"hi"<<endl;
        cout<<(*it)<<" ";
    }
    //    cout<<(*it++).value_list<<endl;
    //    cout<<alex<<endl;
    //    cout<<"\\\\\\\\\\\\\\\aaa\\"<<endl;
    //    alex.erase("Kevin");
    // cout<<alex<<endl;
    //    alex.insert("GARY",1);
    //    alex.insert("GGG",2);
    //    cout<<"|||||||||||||||||||||||||"<<endl;
    //    alex["BBB"]=123;
    //    long v = 123;
    //    alex["DDD"] += v;
    //    cout<<"||||||||||"<<endl;
    //    cout<<alex<<endl;
    //    cout<<"||||||||||"<<endl;
    //    alex["SSS"] = 30;
    //    cout<<"||||||||||"<<endl;
    //    cout<<alex<<endl;
    //    cout<<"||||||||||"<<endl;
    //    alex["AAA"] = 32;
    //    cout<<"||||||||||"<<endl;
    //    cout<<alex<<endl;
    //    cout<<"||||||||||"<<endl;
    //    alex["TTT"] = 33;
    //    cout<<"||||||||||"<<endl;
    //    cout<<alex<<endl;
    //    cout<<"||||||||||"<<endl;
    //    alex["WWW"] = 3231;
    //    alex.insert("KKK",3);
    //    alex.insert("KKK",4);
    //    alex.erase("KKK");
    cout << "Hello World!" << endl;
    return 0;
}
