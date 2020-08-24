#include "block.h"

using namespace std;
Block::Block(long theTimestamp, string thePreviousHash) //Attendance theAttendance,
{                                                       //attendance = theAttendance;
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
    return sha256(to_string(timestamp) + previousHash + to_string(timestamp) + to_string(nonce)); // + theAttendance.stringify()
}

void Block::setPreviousHash(string hash)
{
    previousHash = hash;
}

void Block::updateHash(string nHash)
{
    hash = nHash;
}

// string stringify(Transactions transactions[])
// {
//     string res;
//     for (Transaction t in transactions)
//     {
//         res = res + t.stringify();
//     }

//     return res;
// }

// void mineBlock(int difficulty)
// {
//     while (hash.substring(0, difficulty) != = Array(difficulty + 1).join('0'))
//     {
//         nonce++;
//         hash = calculateHash();
//     }

//     cout << " Block mined : " << hash << endl;
// }

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
