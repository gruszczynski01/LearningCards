//
// Created by Szymon Gruszczyński on 04/11/2018.
//

#include "card.h"
card::card() {
    cout << "tworze nowa karte" << endl;

    cout << "Podaj pierwsza strone fiszki: " << endl;
    cin >> this->frontSide;
    cout << "Podaj druga strone fiszki: " << endl;
    cin >> this->backSide;
}
void card::printCard() {
    cout << "========CARD=======" << endl;
    cout << "Front side: " << this->frontSide <<  endl;
    cout << "Back side: " << this->backSide <<  endl;
}
string card::getFrontSide() {
    return this->frontSide;
}
string card::getBackSide() {
    return this->backSide;
}