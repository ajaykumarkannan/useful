#include <iostream>
#include "../include/printFormat.h"

using namespace std;

void printBin(unsigned char input){
    int i = 0;
    int temp;
    cout << "1b";
    for(i = 128; i > 0; i >>=1){
        temp = (input & i) != 0 ? 1:0;
        cout << temp;
    }
}

void printVal(unsigned char input){
    if(input > 15) return;

    switch(input){
        case 10:
            cout << "A";
            break;
        case 11:
            cout << "B";
            break;
        case 12:
            cout << "C";
            break;
        case 13:
            cout << "D";
            break;
        case 14:
            cout << "E";
            break;
        case 15:
            cout << "F";
            break;
        default:
            cout << (int) input;
            break;
    }
}

void printHex(unsigned char input){
    unsigned char temp = (input & 0xF0) >> 4;
    cout << "0x";
    printVal(temp);
    temp = input & 0xF;
    printVal(temp);
}