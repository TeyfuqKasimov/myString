// Copyright 2024 Kasimov Tofiq

#include <string>
#include <iostream>
#ifndef C__USERS_TOFIK_DESKTOP_P_MYSTRING_H_
#define C__USERS_TOFIK_DESKTOP_P_MYSTRING_H_
#endif  // C__USERS_TOFIK_DESKTOP_P_MYSTRING_H_

class myString {
 public:

  explicit myString(const char* = nullptr);

  explicit myString(const std::string);

  explicit myString(const myString&);

  myString(myString&&);

  size_t length() const;

  char* get();

  // overload operator<< std::cout
  friend std::ostream& operator<<(std::ostream& os, const myString&);

  friend std::istream& operator>>(std::istream& is, myString&);

  myString& operator=(const myString&);

  myString& operator=(myString&&);

  // myString& myString::operator=(const myString&&);

  myString operator+(const myString&) const;

  myString operator-(const myString&) const; // Don't work 

  myString operator*(const size_t&) const;

  bool operator==(const myString&);

  bool operator!=(const myString&);

  bool operator>(const myString&);

  bool operator<(const myString&);

  bool operator>=(const myString&);

  bool operator<=(const myString&);

  myString operator!();

  char operator[] (const size_t& index);

  size_t operator() (const myString&);

  ~myString();
  char* str;
  size_t size = 0;

  void recalloc(const size_t&);
 private:

};
