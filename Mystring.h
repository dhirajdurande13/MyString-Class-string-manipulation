#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

// declarations
class MyString{
private:
    char *data;//pointer to char data
    int length;//size of mystring
public:
    MyString();//default ctor
    MyString(const char *str);//paramiterized ctor
    MyString(const MyString &other);//copy ctor
    ~MyString();//dtor

    // functions declarations
    int size() const;//here const means in function body anyone cannot change size
    bool empty() const;
    const char *c_str() const;
    // overload insertion operator << for easy output
    //find subscript str[0]
    char &operator[](size_t index);

    //find substring
    int find(const MyString& substr) const;

    // concatination of += operator
    MyString &operator+=(const MyString &others);
    // append
    void append(const MyString &others);
    // erase

    void erase(int pos,int length);
    friend std::ostream&operator<<(std::ostream &os,const MyString &str);
    
};
#endif //end MYSTRING_H