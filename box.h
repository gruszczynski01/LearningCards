//
// Created by Szymon Gruszczyński on 04/11/2018.
//

#ifndef CARD_CONTAINERSSTL_BOX_H
#define CARD_CONTAINERSSTL_BOX_H

#include <list>
#include <iostream>
#include "smallBox.h"

using namespace std;

class box {
public:

    smallBox tabOfSmallBox[5];
    box();
    ~box() = default;
    void addCard();
    void printBox();
    void test();



};


#endif //CARD_CONTAINERSSTL_BOX_H
