#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "block.h"
#include "sha/sha256.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Blockchain
{
public:
    vector<Block> chain;
    int difficulty = 5;
    // public:
    /**
   * default constructor
   *
   *
   */

    Blockchain();

    /**
   * return the first block 
   *
   * @returns {Block}
   */

    Block createGenesisBlock();

    void printChain();

    /**
   * return the block at the  end of chain
   *
   * @returns {Block}
   */
    Block getLatestBlock();

    /**
   * adds a block to the end of chain
   *
   * @returns {void}
   */
    void addBlock(Block b);

    /**
   * Returns the SHA256 of this block (by processing all the data stored
   * inside this block)
   *
   * @returns {string}
   */
    string calculateHash();

    /**
   * Loops over all the blocks in the chain and verify if they are properly
   * linked together and nobody has tampered with the hashes. By checking
   * the blocks it also verifies the (signed) transactions inside of them.
   *
   * @returns {boolean}
   */
    bool isChainValid();

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