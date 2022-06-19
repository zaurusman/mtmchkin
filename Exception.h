//
// Created by Yotam on 07/06/2022.
//
/** Issues:
 * should we put getInfoStream in protected or is public ok?
 * printleaderboard
 *  exception can't use utilities functions
 *  do exceptions need cpy ctors and such
 *  are protected consts ok?
 *  benefits of using a factory over an if function
 *  leaderboards for non winning players - should we print leaderboard even if game isnt over?
 *  how to implement leaderboards as a class
 *  is it ok to use deque instead of queue solely for the iterator?
 */



#ifndef MTMCHKIN_EXCEPTION_H
#define MTMCHKIN_EXCEPTION_H

#include "utilities.h"

class InvalidName : public std::invalid_argument{
public:
   InvalidName(): std::invalid_argument("Player Creation Error: Invalid Name")    {
   }
};

class InvalidClass : public std::logic_error{
public:
   InvalidClass(): std::logic_error("Player Creation Error: Invalid Class") {
   }
};

class DeckFileNotFound: public std::runtime_error{
public:
    DeckFileNotFound(): std::runtime_error("Deck File Error: File not found"){}
};

class DeckFileFormatError: public std::runtime_error{
public:
    explicit DeckFileFormatError(int lineNumber):
    std::runtime_error("Deck File Error: File format error in line " + std::to_string(lineNumber)){}
};

class DeckFileInvalidSize: public std::runtime_error{
public:
    DeckFileInvalidSize(): std::runtime_error("Deck File Error: Deck size is invalid"){}
};

class InvalidMerchantInput: public std::invalid_argument{
public:
    InvalidMerchantInput(): std::invalid_argument("Merchant Input Error: Input is invalid"){}
};

#endif //MTMCHKIN_EXCEPTION_H
