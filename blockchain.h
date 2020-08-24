#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "block.h"
#include "sha/sha256.h"
#include <iostream>
#include <string>

using namespace std;
class Blockchain
{
    /**
   * @param {blocks[]} chain
   *
   */

    Block chain[];

public:
    Blockchain(long timestamp, string previousHash = " "); //Attendance attendance,

    Block createGenesisBlock();
    string printChain();

    /**
   * Returns the SHA256 of this block (by processing all the data stored
   * inside this block)
   *
   * @returns {string}
   */
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
};
#endif