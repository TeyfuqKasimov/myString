// Copyright 2024 Kasimov Tofiq

#include "..\include\myString.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

myString::myString(const char* temp) {
    if (temp == nullptr) {
        str = nullptr;
        size = 0;
        return;
    }
    while (temp[size] != '\0') {
        size++;
    }
    str = new char[size + 1];
    for (size_t i = 0; i < size; ++i) {
        this->str[i] = temp[i];
    }
    this->str[size] = '\0';
}

myString::myString(const std::string temp) {
    while (temp[size] != '\0') {
        size++;
    }
    str = new char[size + 1];

    for (size_t i = 0; i < size; ++i) {
        this->str[i] = temp[i];
    }
}

myString::myString(const myString& temp) {
    if (temp.str == nullptr) {
        this->str = nullptr;
        this->size = 0;
        return;
    }

    this->size = temp.size;
    this->str = new char[this->size + 1];
    for (size_t i = 0; i < this->size + 1; ++i) {
        this->str[i] = temp.str[i];
    }
}

myString::myString(myString&& temp) {
    if (&temp != this) {
        this->str = std::move(temp.str);
        this->size = temp.size;
        temp.str = nullptr;
        temp.size = 0;
    }
}

size_t myString::length() const { return size; }

char* myString::get() { return str; }

myString& myString::operator=(const myString& temp) {
    if (this != &temp) {
        delete[] this->str;

        this->size = temp.size;
        this->str = new char[size];

        for (size_t i = 0; i < size; ++i) {
            this->str[i] = temp.str[i];
        }
    }

    return *this;
}

myString& myString::operator=(myString&& temp) {
    if (&temp != this) {
        delete[] this->str;
        this->str = std::move(temp.str);
        this->size = temp.size;
        temp.str = nullptr;
        temp.size = 0;
    }

    return *this;
}

myString myString::operator+(const myString& temp) const {
    myString ans;
    ans.size = this->size + temp.size;
    ans.str = new char[ans.size + 1];
    for (size_t i = 0; i < this->size; ++i) {
        ans.str[i] = this->str[i];
    }
    for (size_t i = 0; i < temp.size; ++i) {
        ans.str[i + this->size] = temp.str[i];
    }
    ans.str[ans.size] = '\0';

    return ans;
}

myString myString::operator*(const size_t& temp) const {
    myString ans;
    if (temp > 0) {
        ans.size = this->size * temp;
        ans.str = new char[ans.size];
        for (size_t i = 0; i < ans.size; ++i) {
            ans.str[i] = this->str[i % this->size];
        }
        ans.str[ans.size] = '\0';
    }
    return ans;
}

myString myString::operator-(const myString& temp) const {
    myString ans;
    ans.size = this->size;
    ans.str = new char[ans.size];
    size_t current = 0;
    bool flag;
    for (size_t i = 0; i < this->size; ++i) {
        flag = true;
        for (size_t j = 0; j < temp.size; ++j) {
            if (this->str[i] == temp.str[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.str[current] = this->str[i];
            ++current;
        }
    }

    if (current > 0) {
        ans.str[current] = '\0';
        if (current < ans.size) { ans.recalloc(current); }
    } else {
        delete[] ans.str;
        ans.str = nullptr;
        ans.size = 0;
    }

    return ans;
}

std::ostream& operator<<(std::ostream& os, const myString& temp) {
    for (size_t i = 0; i < temp.size; ++i) {
        os << temp.str[i];
    }

    return os;
}

void myString::recalloc(const size_t& pr) {
    myString temp;
    temp.str = new char[pr + 1];
    temp.size = pr;
    for (size_t i = 0; i < (std::min(temp.size, this->size) + 1); ++i) {
        temp.str[i] = this->str[i];
    }
    *this = temp;
}

std::istream& operator>>(std::istream& is, myString& temp) {
    delete[] temp.str;

    temp.size = 16;
    temp.str = new char[temp.size];
    size_t current = 0;
    char _temp;

    _temp = is.get();

    while (_temp != '\n' && _temp != '\0'&& _temp != ' ') {
        temp.str[current] = _temp;

        if (current > (temp.size * 0.75)) {
            temp.recalloc(temp.size*2);
        }
        ++current;
        _temp = is.get();
    }
    temp.recalloc(current);

    return is;
}

bool myString::operator==(const myString& temp) {
    if (this == &temp) { return true; }

    if (this->size != temp.size) { return false; }

    for (size_t i = 0; i < temp.size; ++i) {
        if (this->str[i] != temp.str[i]) {
            return false;
        }
    }

    return true;
}

bool myString::operator!=(const myString& temp) { return !(*this == temp); }

bool myString::operator>(const myString& temp) {
    if (this == &temp) { return false; }

    for (size_t i = 0; i < std::min(temp.size, this->size); ++i) {
        if (this->str[i] > temp.str[i]) { return true; }
        if (this->str[i] < temp.str[i]) { return false; }
    }
    if (this->size > temp.size) { return true; }

    return false;
}

bool myString::operator<(const myString& temp) {
    if (this == &temp) { return false; }

    for (size_t i = 0; i < std::min(temp.size, this->size); ++i) {
        if (this->str[i] < temp.str[i]) { return true; }
        if (this->str[i] > temp.str[i]) { return false; }
    }
    if (this->size < temp.size) { return true; }

    return false;
}

bool myString::operator>=(const myString& temp) {
    if (*this == temp) { return true; }
    if (*this > temp)  { return true; }

    return false;
}

bool myString::operator<=(const myString& temp) {
    if (*this == temp) { return true; }
    if (*this > temp)  { return true; }

    return false;
}

myString myString::operator!() {
    myString ans;
    ans = *this;
    size_t k;
    for (size_t i = 0; i < size; ++i) {
        k = str[i];
        if (k >= 65 && k <= 90)  { ans.str[i] += 32; }
        if (k >= 97 && k <= 122) { ans.str[i] -= 32; }
    }

    return ans;
}

char myString::operator[](const size_t& index) { return str[index]; }

size_t myString::operator()(const myString& temp) {
bool flag;
    for (size_t i = 0; i < this->size - temp.size + 1; ++i) {
        if (this->str[i] == temp.str[0]) {
            flag = true;
            for (size_t j = 1; j < temp.size; ++j) {
                if (this->str[i + j] != temp.str[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) { return i; }
        }
    }

    return -1;
}


myString::~myString() { delete[] str; }
