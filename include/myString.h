// Copyright 2024 Kasimov Tofiq

#include <string>
#include <iostream>
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_
#endif  // INCLUDE_MYSTRING_H_

class myString {
 public:
  explicit myString(const char* = nullptr);

  explicit myString(const std::string);

  explicit myString(const myString&);

  myString(myString&&);

  size_t length() const;

  char* get();

  friend std::ostream& operator<<(std::ostream& os, const myString&);

  friend std::istream& operator>>(std::istream& is, myString&);

  myString& operator=(const myString&);

  myString& operator=(myString&&);

  myString operator+(const myString&) const;

  myString operator-(const myString&) const;

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

 private:
  char* str;
  size_t size = 0;

  void recalloc(const size_t&);
};
