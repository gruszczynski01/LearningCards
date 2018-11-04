//
// Created by Szymon Gruszczyński on 04/11/2018.
//

#include "smallBox.h"
#include "card.h"
#include <string>

//using namespace std;


smallBox::smallBox() {
 cout << "utworzono pudelko " << endl;
}
void smallBox::printCards() {
    list<card *>::iterator iter;
    for( iter=listOfCards.begin(); iter != listOfCards.end(); ++iter )
    {
        card *temp = *iter;
        temp->printCard();
    }
}
