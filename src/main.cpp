// Copyright 2024 Kasimov Tofiq

#include "..\include\myString.h"
#include <string>
#include <iostream>

int main() {
    myString exampleForConstructor1;
    myString exampleForConstructor2("exampleForConstructor2");
    std::string temp = "exampleForConstructor3";
    myString exampleForConstructor3(temp);

    myString exampleForConstructor4(exampleForConstructor2);

    myString exampleForConstructor5(exampleForConstructor3
                                    + exampleForConstructor2);

    std::cout << "example1: " << exampleForConstructor1 <<
    std::endl << "example2: " << exampleForConstructor2 <<
    std::endl << "example3: " << exampleForConstructor3 <<
    std::endl << "example4: " << exampleForConstructor4 <<
    std::endl << "example5: " << exampleForConstructor5 <<
    std::endl;


    size_t exampleSize = exampleForConstructor2.length();
    auto exampleStr    = exampleForConstructor2.get();

    std::cout << "Size: " << exampleSize << std::endl
                << " Str: " << exampleStr << std::endl;

    myString exampleOperator;

    size_t koef = 5;
    exampleOperator = exampleForConstructor3 * koef;

    std::cout << "Operator *: " << exampleOperator << std::endl;

    exampleOperator = exampleForConstructor3 + exampleForConstructor5;

    std::cout << "Operator +: " << exampleOperator << std::endl;

    exampleOperator = exampleOperator - exampleForConstructor2;

    std::cout << "Operator -: " << exampleOperator << std::endl;

    if (exampleForConstructor2 == exampleForConstructor3) {
        std::cout << "exampleForConstructor2 == exampleForConstructor3"
                    << std::endl;
    }
    if (exampleForConstructor1 != exampleForConstructor2) {
        std::cout << "exampleForConstructor1 != exampleForConstructor2"
                    << std::endl;
    }
    if (exampleForConstructor2 > exampleForConstructor3) {
        std::cout << "exampleForConstructor2 > exampleForConstructor3"
                    << std::endl;
    }
    if (exampleForConstructor2 < exampleForConstructor3) {
        std::cout << "exampleForConstructor2 < exampleForConstructor3"
                    << std::endl;
    }

    std::cout << "exampleForConstructor2[7]: "
                << exampleForConstructor2[7] << std::endl;
    std::cout << "exampleForConstructor5 and exampleForConstructor2: "
                << exampleForConstructor5 <<  ' ' << exampleForConstructor2
                    << std::endl;

    std::cout << "exampleForConstructor5(exampleForConstructor2): "
                << exampleForConstructor5(exampleForConstructor2) << std::endl;
    std::cout << "Enter, please, something: ";
    std::cin >> exampleForConstructor1;
    std::cout << "Input: " << exampleForConstructor1 << std::endl;

    return 0;
}
