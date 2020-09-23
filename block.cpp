#include "block.h"
#include <iostream>
#include <float.h>
#include <limits.h>
#include <omp.h>
#include <conio.h>
using namespace std;
Block::Block(long theTimestamp, vector<string> attendance, string thePreviousHash) //Attendance theAttendance,
{
    Attendance = attendance;
    previousHash = thePreviousHash;
    timestamp = theTimestamp;
    nonce = 0;
    attendanceString = stringifyAttendance();
    hash = calculateHash();
}

string Block::getHash()
{

    return hash;
}

string Block::calculateHash()
{
    return sha256(to_string(timestamp) + previousHash + to_string(nonce) + attendanceString);
}

string Block::calculateHash(int nonce)
{
    return sha256(to_string(timestamp) + previousHash + to_string(nonce) + attendanceString);
}
string Block::stringifyAttendance()
{
    string res = "";
    vector<string> temp = Attendance;
    vector<string>::iterator it = temp.begin();
    while (it != temp.end())
    {
        res += *it;
        it++;
    }
    return res;
}

void Block::setPreviousHash(string hash)
{
    previousHash = hash;
}

string Block::getPreviousHash()
{
    return previousHash;
}

void Block::updateHash(string nHash)
{
    hash = nHash;
}

vector<string> Block::getAttendance()
{
    return Attendance;
}

void Block::mineBlock(int difficulty)
{

    int temp = difficulty;
    int tempNonce = 0;
    string comp = "";
    while (temp)
    {
        comp += "0";
        temp--;
    }
    /* code which can be parallized */
    nonce = 0;
    while (hash.substr(0, difficulty) != comp)
    {
        cout << "Mining block ....\n";
        cout << "Current hash : ";
        nonce++;
        hash = calculateHash(tempNonce++);
        cout << hash;
    }
    nonce = tempNonce;
    cout << " Block mined : " << hash << endl;
    getchar();
}

void Block::mineBlockParallel(int difficulty)
{
    int tempNonce;
    int mined = 0;
    string tempHash;
    int temp = difficulty;
    string comp = "";
    while (temp)
    {
        comp += "0";
        temp--;
    }
/* code which needs to be parallized */
#pragma omp parallel private(tempHash, tempNonce) shared(mined)
    {

#pragma omp for

        for (tempNonce = 0; tempNonce < INT_MAX; tempNonce++)
        {
            if (mined == 0)
            {

                cout << "mining .... \n";
                tempHash = calculateHash(tempNonce);
                cout << tempHash;
                if (tempHash.substr(0, difficulty) == comp)
                {
                    cout << tempHash;
                    mined = 1;
                    hash = tempHash;
                    nonce = tempNonce;
                    getch();
                }
                //system("CLS");
            }
        }
    }

    cout << " Block mined : " << hash << endl;
    getch();
}

// bool hasValidTransactions()
// {
//     for (const tx of this.transactions)
//     {
//         if (!tx.isValid())
//         {
//             return false;
//         }
//     }

//     return true;
// }
