//
// Created by Piotrek on 04.05.2021.
//

#ifndef SPOJ_BOX_H
#define SPOJ_BOX_H
#include <string>


#include <stdlib.h>
#include <string>
#include <iostream>


class Who{

public:
void addWho(std::string tat, int &rat){
    this->rating = rat;
    this->title = tat;
}
    std::string title;
    int rating;
};

#endif //SPOJ_BOX_H
