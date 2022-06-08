//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_EXCEPTION_H
#define MTMCHKIN_EXCEPTION_H

class InvalidName : public std::length_error{
public:
    InvalidName(): std::length_error("Invalid Name Length.") {}
};
#endif //MTMCHKIN_EXCEPTION_H
