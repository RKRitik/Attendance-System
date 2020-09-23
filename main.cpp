#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <string.h>
#include <vector>
#include "block.h"
#include "blockchain.h"
#include "sha/sha256.h"
using namespace std;
int select_ = 0;
Blockchain b1;
#define KEY_UP 72
#define KEY_DOWN 80

vector<string> options;

void printStars()
{
    cout << "\n *********************************************\n";
}
void printOptions()
{
    for (int i = 0; i < options.size(); i++)
    {
        cout << "\t " << i + 1 << "." << options[i] << "\n";
    }
}
void addAttendance()
{
    system("CLS");
    printStars();
    printStars();
    cout << "\tEnter the registration numbers (Enter 0 to end)\n";
    string regnum = "";
    vector<string> list;
    while (regnum != "0")
    {
        cin >> regnum;
        list.push_back(regnum);
    }
    b1.addBlock(Block(time(NULL), list));
}

int main()
{

    boolean mainMenu = true;

    options.push_back("Print Blockchain");
    options.push_back("Take Attendance");
    options.push_back("Check Attendance");
    options.push_back("Save Attendance");
    options.push_back("Load Attendance");
    options.push_back("Delete Blockchain");
    options.push_back("Exit");
    int c = 0;
    system("Color 10");
    while (mainMenu)
    {
        system("CLS");
        printStars();
        printStars();
        cout << "\tWelcome to Student attendance system\n\n";

        printStars();
        printStars();
        printOptions();

        c = 0;
        cin >> c;
        switch (c)
        {
        case 1:
            b1.printChain();
            break;
        case 2:
            addAttendance();
            break;
        case 3:
            b1.printAttendance();
            break;
        case 4:
            //  b1.printChain();
            break;
        case 5:
            // b1.printChain();
            break;
        case 7:
            mainMenu = false;
            break;
        }
    }

    // cout << "mining block 1 \n";
    //  b1.addBlock(Block(999999999, {"18BCE0813", "18BCB1105"}));

    // cout << "mining block 2 \n";
    //b1.addBlock(Block(9999999, {"18BCE0813", "18BCB1105"}));
    system("CLS");
    //b1.printChain();
    //Block bl1 = b1.chain.at(0);
    //Block bl2 = b1.chain.at(1);

    // cout << "chain valid? " << b1.isChainValid();
}