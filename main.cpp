#include <iostream>
#include "box.h"
#include "smallBox.h"
#include "card.h"

using namespace std;

int main() {
    box mainBox;
    /*mainBox.addCard();
    mainBox.addCard();
    mainBox.addCard();
    mainBox.addCard();*/
    //mainBox.printBox();
    //mainBox.test();
    mainBox.printBox();
    mainBox.loadCards();
    mainBox.printBox();
    mainBox.addCard();
    mainBox.addCard();
    mainBox.addCard();
    mainBox.saveCards();

    return 0;
}