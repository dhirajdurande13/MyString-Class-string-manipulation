#include<iostream>
#include "Mystring.h"
#include<cstring>
using namespace std;

int main() {
    //  string str="rishi";
    // MyString str1("rishi");
    MyString str1="rishi";
    // string s="rishi";
    // string n="ghj";
    MyString str2=":Future Director";
    // MyString s="";
    //  cout<<str1<<endl;
    //  cout<<s<<endl;
    //  cout<<s.empty()<<endl;;
    //  cout<<str1.size()<<endl;
    //  cout<<str1[0]<<endl;
    // cout<<"MyString fxn: "<<str1.find("hia")<<endl;
    // cout<<"string fxn: "<<s.find("hia")<<endl;
    // cout<<s.append("m");
    // str1.append("M");
    // cout<<str1;
        // cout<<s.erase(2,1);
    // str1.erase(2,1);
    // cout<<str1;
    // cout<<s + n;
    str1+=str2;
    cout<<str1;
     return 0;
}