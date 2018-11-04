//
// Created by Szymon Gruszczyński on 04/11/2018.
//

#ifndef CARD_CONTAINERSSTL_CARD_H
#define CARD_CONTAINERSSTL_CARD_H

#include <string>
#include <iostream>
using namespace std;


class card {
public:
    string frontSide;
    string backSide;
    card();
    ~card() = default;
    void printCard();
    string getFrontSide();
    string getBackSide();
};


#endif //CARD_CONTAINERSSTL_CARD_H
