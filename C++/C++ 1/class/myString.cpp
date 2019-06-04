//
//  myString.cpp
//  class
//
//  Created by glx on 2019/6/1.
//  Copyright © 2019 glx. All rights reserved.
//

#include "myString.hpp"
#include <string.h>


myString::myString(const char * str) {
    if (str == nullptr){
        this->str_ = new char[1];
        this->str_[0] = 0;
    }else{
        size_t len = strlen(str);
        this->str_ = new char[len + 1];
        memset(this->str_, 0, len + 1);
    }
}

myString::~myString() {
    if (this->str_ != nullptr)
    {
        delete [] this->str_;
        this->str_ = nullptr;
    }
}

myString::myString(const myString &another) {
    delete [] this->str_;
    size_t len = sizeof(another.str_);
    this->str_ = new char[len + 1];
    strcpy(this->str_, another.str_);
}

myString & myString::operator=(const myString &another) {
    if (this == &another) return *this;
    
    delete [] this->str_;
    size_t len = strlen(this->str_);
    this->str_ = new char[len + 1];
    strcpy(this->str_, another.str_);
    return *this;
}

myString &myString::operator+=(const myString &another) {
    size_t old_len = sizeof(this->str_);
    size_t ano_len = sizeof(another.str_);
    
    this->str_ = static_cast<char *>(new char[old_len + ano_len + 1]);
    memset(this->str_+old_len, 0, ano_len);
    strcat(this->str_, another.str_);
    
    return *this;
}

//bool myString::operator==(const myString &another) {
//    <#code#>;
//}
//
//bool myString::operator>(const myString &another) { 
//    <#code#>;
//}
//
//bool myString::operator<(const myString &another) { 
//    <#code#>;
//}
//
//bool myString::operator>=(const myString &another) { 
//    <#code#>;
//}
//
//bool myString::operator<=(const myString &another) {
//    <#code#>;
//}
//
//char myString::operator[](const int n) { 
//    <#code#>;
//}
