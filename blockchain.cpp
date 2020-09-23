#include "blockchain.h"
#include "block.h"
#include <conio.h>
#include "sha/sha256.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Blockchain::Blockchain()
{
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock()
{
    return Block(12344444); //, " ", "25/Aug/2020"
}

Block Blockchain::getLatestBlock()
{

    return chain[chain.size() - 1];
}

void Blockchain::printChain()
{
    system("CLS");
    int f;
    cout << "Printing chain...";
    for (int i = 0; i < chain.size(); i++)
    {
        cout << chain[i].getHash() << "\n";
        cout << chain[i].getPreviousHash() << "\n ***************\n";
    }

    getch();
}

void Blockchain::printAttendance()
{
    string regNum;
    cout << "\nEnter the registration number of student : ";
    cin >> regNum;
    int attendanceCount = 0;
    int len = chain.size();
    for (int i = 1; i < len; i++)
    {
        Block b = chain.at(i);
        vector<string> attendance = b.getAttendance();
        vector<string>::iterator it = find(attendance.begin(), attendance.end(), regNum);
        if (it != attendance.end())
        {
            attendanceCount++;
        }
    }
    cout << "The attendance is " << attendanceCount << " /" << len - 1;
    getch();
}

void Blockchain::addBlock(Block b)

{
    b.setPreviousHash(getLatestBlock().getHash());
    //b.mineBlockParallel(difficulty);
    b.mineBlock(difficulty);
    chain.push_back(b);
}

string calculateHash();

/**
   * Starts the mining process on the block. It changes the 'nonce' until the hash
   * of the block starts with enough zeros (= difficulty)
   *    needs to be parallized
   * @param {number} difficulty
   */
// string stringify(Attendance attendance);

// void mineBlock(int difficulty);

/**
   * Validates all the transactions inside this block (signature + hash) and
   * returns true if everything checks out. False if the block is invalid.
   *
   * @returns {boolean}
   */
// bool hasValidTransactions();

bool Blockchain::isChainValid()
{
    // Check if the Genesis block hasn't been tampered with by comparing
    // the output of createGenesisBlock with the first block on our chain
    Block realGenesis = createGenesisBlock();
    Block thisChainGenesis = chain.at(0);
    if (realGenesis.getHash() != thisChainGenesis.getHash())
    {
        return false;
    }

    // Check the remaining blocks on the chain to see if there hashes and
    // signatures are correct
    for (int i = 1; i < chain.size(); i++)
    {
        Block currentBlock = chain.at(i);
        Block previousBlock = chain.at(i - 1);
        if (currentBlock.getPreviousHash() != previousBlock.getHash())
        {
            cout << "\ncurrentBlock.getPreviousHash() = " << currentBlock.getPreviousHash();
            cout << " \npreviousBlock.getHash() = " << previousBlock.getHash() << endl;

            return false;
        }

        if (currentBlock.getHash() != currentBlock.calculateHash())
        {
            cout << "\ncurrentBlock.getHash() = " << currentBlock.getHash();
            cout << "\ncurrentBlock.calculateHash() = " << currentBlock.calculateHash() << endl;
            return false;
        }
    }

    return true;
}
