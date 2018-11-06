//
// Created by Szymon Gruszczyński on 04/11/2018.
//

#include <fstream>
#include <iostream>
#include "box.h"

box::box() {
    cout << "Utworzono duzego boxa" << endl;
}
void box::addCard() {
    tabOfSmallBox[0].listOfCards.push_back(new card());
}
void box::printBox() {
    for(int smallBoxNumber = 0 ; smallBoxNumber<=4; smallBoxNumber++)
    {
        cout << "SMALLBOX NUMBER " << smallBoxNumber << endl;
        if(tabOfSmallBox[smallBoxNumber].listOfCards.size() == 0)
            cout << "empty" << endl;
        tabOfSmallBox[smallBoxNumber].printCards();
    }
}
void box::test() {
    cout << "testing from smallBox" << endl;
    for(int smallBoxNumber = 0; smallBoxNumber<=4; smallBoxNumber++)
    {
        cout << "BOX NUMBER " << smallBoxNumber << endl;
        string answer;
        int size = tabOfSmallBox[smallBoxNumber].listOfCards.size();
        int loopStoper = 0;
        list<card *>::iterator iter;

        for( iter=tabOfSmallBox[smallBoxNumber].listOfCards.begin(); iter != tabOfSmallBox[smallBoxNumber].listOfCards.end(); ++iter )
        {
            if(size == 0 || loopStoper == size)
                break;
            card *currentCard = *iter;
            cout << "FS: " << currentCard->frontSide<< "    now you have to write the back side...: " << endl << "BS: ";
            cin >> answer;
            if(!currentCard->backSide.compare(answer)) //'compare' function returns '0' if strings are the same, so '!' at first
            {
                if(smallBoxNumber==4)
                {
                    cout << "Good answer!" << endl;
                    cout << "CONGRATULATION! YOU'VE LEARNT A NEW WORD!" << endl;
                    tabOfSmallBox[smallBoxNumber].listOfCards.pop_front();

                }else{
                    cout << "Good answer!" << endl;
                    tabOfSmallBox[smallBoxNumber+1].listOfCards.push_back(currentCard);
                    tabOfSmallBox[smallBoxNumber].listOfCards.pop_front();
                }

            }
            else
            {
                cout << "Wrong answer!" << endl;
                tabOfSmallBox[smallBoxNumber].listOfCards.push_back(currentCard);
                tabOfSmallBox[smallBoxNumber].listOfCards.pop_front();
            }
            loopStoper++;
        }
    }
}
void box::loadCards() {
    fstream dataFile;
    string fileNames[] = {"sB1.txt", "sB2.txt", "sB3.txt", "sB4.txt", "sB5.txt"};
    string bufferFS, bufferBS;
    for(int i = 0; i<=4; i++)
    {
        dataFile.open(fileNames[i], ios::in);
        if(dataFile.good() == true){
            //while(!dataFile.eof()) {
            while(getline(dataFile, bufferFS)) {//dlaczego EOF nie działa???
                cout << bufferFS << endl;
                getline(dataFile, bufferBS);
                cout << bufferBS << endl;
                card *temp = new card(bufferFS, bufferBS);
                tabOfSmallBox[i].listOfCards.push_back(temp);
                cout << "card has been added to list" << endl;
            }
            dataFile.close();
        } else{
            cout << "blad" << endl;
        }
    }
}
void  box::saveCards() {
    fstream dataFile;
    string fileNames[] = {"sB1.txt", "sB2.txt", "sB3.txt", "sB4.txt", "sB5.txt"};
    string bufferFS, bufferBS;
    for(int i = 0; i<=4; i++)
    {
        dataFile.open(fileNames[i], ios::out | ios::trunc);
        list<card *>::iterator iter;
        if(dataFile.good() == true){
            for( iter=tabOfSmallBox[i].listOfCards.begin(); iter != tabOfSmallBox[i].listOfCards.end(); ++iter ){
                card *currentCard = *iter;
                dataFile << currentCard->frontSide << endl;
                dataFile << currentCard->backSide << endl;
                cout << "card has been saved to filr" << endl;
            }
            dataFile.close();
        } else{
            cout << "blad" << endl;
        }
    }
}
