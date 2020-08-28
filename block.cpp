#include "block.h"

using namespace std;
Block::Block(long theTimestamp, vector<string> attendance, string thePreviousHash) //Attendance theAttendance,
{
    Attendance = attendance;
    previousHash = thePreviousHash;
    timestamp = theTimestamp;
    nonce = 0;
    hash = calculateHash();
}

string Block::getHash()
{

    return hash;
}

string Block::calculateHash()
{
    return sha256(to_string(timestamp) + previousHash + to_string(nonce) + stringifyAttendance());
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

void Block::mineBlock(int difficulty)
{
    int temp = difficulty;
    string comp = "";
    while (temp)
    {
        comp += "0";
        temp--;
    }
    /* code which needs to be parallized */
    while (hash.substr(0, difficulty) != comp)
    {
        nonce++;
        hash = calculateHash();
    }

    cout << " Block mined : " << hash << endl;
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
