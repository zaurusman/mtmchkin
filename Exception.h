//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_EXCEPTION_H
#define MTMCHKIN_EXCEPTION_H

#include "utilities.h"
/*
 * inherits from invalid_argument
 * This Exception is been thrown when the user input
 * for player name is invalid
 *
 */
class InvalidName : public std::invalid_argument{
public:
   InvalidName(): std::invalid_argument("Player Creation Error: Invalid Name")    {
   }
};

/*
 * inherits from invalid_argument
 * This Exception is been thrown when the user input
 * for player class is invalid
 *
 */
class InvalidClass : public std::invalid_argument{
public:
   InvalidClass(): std::invalid_argument("Player Creation Error: Invalid Class") {
   }
};

/*
 * inherits from runtime_error
 * This Exception is been thrown when the Deck.txt file
 * is not found.
 */
class DeckFileNotFound: public std::runtime_error{
public:
    DeckFileNotFound(): std::runtime_error("Deck File Error: File not found"){}
};

/*
 * inherits from runtime_error
 * This Exception is been thrown when the Deck.txt file
 * is not in the expected format.
 */
class DeckFileFormatError: public std::runtime_error{
public:
    explicit DeckFileFormatError(int lineNumber):
    std::runtime_error("Deck File Error: File format error in line " + std::to_string(lineNumber)){}
};

/*
 * inherits from runtime_error
 * This Exception is been thrown when the Deck size
 * is not in the right size.
 */
class DeckFileInvalidSize: public std::runtime_error{
public:
    DeckFileInvalidSize(): std::runtime_error("Deck File Error: Deck size is invalid"){}
};

/*
 * inherits from invalid_argument
 * This Exception is been thrown when the input for
 * merchant is invalid.
 */
class InvalidMerchantInput: public std::invalid_argument{
public:
    InvalidMerchantInput(): std::invalid_argument("Merchant Input Error: Input is invalid"){}
};

/*
 * inherits from runtime_error
 * This Exception is been thrown when the gang
 * is not in the correct format.
 */
class BadGangFormat: public std::runtime_error{
public:
    explicit BadGangFormat(int lineNumber):
            std::runtime_error("Gang Format Error: format error in line " + std::to_string(lineNumber)){}
};


#endif //MTMCHKIN_EXCEPTION_H
