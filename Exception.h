//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_EXCEPTION_H
#define MTMCHKIN_EXCEPTION_H

#include "utilities.h"

class InvalidName : public std::logic_error{
public:
   explicit InvalidName(): std::logic_error("Invalid Name")    {}
};

class InvalidClass : public std::logic_error{
public:
   explicit InvalidClass(): std::logic_error("Invalid Class") {}
};

class DeckFileNotFound: public std::runtime_error{
public:
    explicit DeckFileNotFound(): std::runtime_error("Deck File Error: File not found"){}
};

class DeckFileFormatError: public std::runtime_error{
public:
    explicit DeckFileFormatError(int lineNumber):
    std::runtime_error("Deck File Error: File format error in line " + std::to_string(lineNumber)){}
};
class DeckFileInvalidSize: public std::runtime_error{
public:
    explicit DeckFileInvalidSize(): std::runtime_error("Deck File Error: Deck size is invalid"){}

};
#endif //MTMCHKIN_EXCEPTION_H
