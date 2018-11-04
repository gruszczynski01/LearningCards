//
// Created by Szymon Gruszczyński on 04/11/2018.
//

#ifndef CARD_CONTAINERSSTL_SMALLBOX_H
#define CARD_CONTAINERSSTL_SMALLBOX_H


#include "card.h"
#include <list>
#include <iostream>

using namespace std;

class smallBox {
public:
    list <card *> listOfCards;
    smallBox();
    ~smallBox() = default;
    void printCards();

};


#endif //CARD_CONTAINERSSTL_SMALLBOX_H
