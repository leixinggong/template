//
//  myString.hpp
//  class
//
//  Created by glx on 2019/6/1.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef myString_hpp
#define myString_hpp

#include <iostream>


class myString
{
public:
    myString(const char * str = nullptr);
    ~myString();
    myString(const myString & another);
    myString & operator=(const myString & another);
    myString & operator+=(const myString & another);
    bool operator==(const myString & another);
    bool operator>(const myString & another);
    bool operator<(const myString & another);
    bool operator>=(const myString & another);
    bool operator<=(const myString & another);
    char operator[](const int n);
    
private:
    
    char * str_;
    
};

#endif /* myString_hpp */
