#include "blockchain.h"
#include "block.h"
#include "sha/sha256.h"
#include <iostream>
#include <string>

using namespace std;

Blockchain::Blockchain()
{
    chain[0] = createGenesisBlock();
}

Block Blockchain::createGenesisBlock()
{
    // Block b1(12344444,"25/Aug/2020");
}

//string printChain();

Block Blockchain::getLatestBlock()
{

    return chain[chain.size() - 1];
}

void Blockchain::addBlock(Block b)

{
    b.setPreviousHash(getLatestBlock().getHash());
    b.updateHash(b.getHash());
    chain.push_back(b);
}

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
