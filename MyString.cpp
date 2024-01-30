#include "MyString.h"
#include<cstring>
#include<utility>
// implementation of .h file fxns
MyString::MyString()
{
    data=new char[1];//if empty we give 1 char
     length=0;
    data[0]='\0';

}
MyString::MyString(const char *str)
{
   data=new char[strlen(str)+1];
    length=strlen(str);
    strcpy(data,str);

}
MyString::MyString(const MyString &other)
{
   data=new char[other.length+1];
    length=other.length;
    strcpy(data,other.data);

}
MyString::~MyString(){
    delete[] data;
}
int MyString::size() const
{
    return length;
}
bool MyString::empty() const
{
    return length==0;
}

const char *MyString::c_str() const{
    return data;
}
std::ostream&operator<<(std::ostream &os,const MyString &str){
    os<<str.c_str();
    return os;
}
// accessing the specific chars
char &MyString::operator[](size_t index)
{
    if(index>=length)
    {
        throw std::out_of_range("\0");
    }
    return data[index];
 }

// find
int MyString::find(const MyString& substr) const{
    if(substr.length>length)
    {
        return -1;
    }
    for(int i=0;i<=length-substr.length;i++)
    {
        int j;
        for(j=0;j<substr.length;j++)
        {
            if(data[i+j]!=substr.data[j])
            {
                break;
            }
        }
        if(j==substr.length)
        {
            return i;
        }
    }
    return -1;
}

// concatination += operator

MyString &MyString::operator+=(const MyString &others)
{
    char *newdata=new char(length+others.length);
    strcpy(newdata,data);
    strcat(newdata,others.data);
    // free previous data and add new
    delete[] data;
    data=newdata;
    length+=others.length;
    return *this;

}

// append
void MyString::append(const MyString &others)
{
    *this+=others;
}
// erase
void MyString::erase(int pos,int len){
    if(pos>length)
    {
        throw std::out_of_range("out of bounds");//Erase till the end if len exceeds the string length from pos

    }
    if(len==0) return;
    int newlen=length - len;//create new length
    char *newdata=new char[newlen+1];//allocate new array
    // Copy characters before 'pos'
    strncpy(newdata, data, pos);
    // copy chars after pos+len
    strcpy(newdata+pos,data+pos+len);
    // null terminate the newstring
     newdata[newlen] = '\0';

// Delete old data and replace with new data
    delete[] data;
    data = newdata;
    
    // Update length
    length = newlen;



}