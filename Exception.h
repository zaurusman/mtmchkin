//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_EXCEPTION_H
#define MTMCHKIN_EXCEPTION_H

class InvalidName : public std::logic_error{
public:
    InvalidName(): std::logic_error("Invalid Name.")    {}
};

class InvalidClass :public std::logic_error{
public:
    InvalidClass(): std::logic_error("Invalid Class") {}
};
#endif //MTMCHKIN_EXCEPTION_H
