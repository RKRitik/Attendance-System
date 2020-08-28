#ifndef BLOCK_H
#define BLOCK_H
//#include "attendance.h"
#include "sha/sha256.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Block
{
    /**
   * @param {number} timestamp
   * @param {Transaction[]} transactions
   * @param {string} previousHash
   */

    long timestamp;
    vector<string> Attendance;
    string previousHash;
    int nonce;
    string hash;

public:
    Block(long timestamp, vector<string> attendance = {" "}, string previousHash = " "); //Attendance attendance,

    string getHash();

    void setPreviousHash(string hash);

    string getPreviousHash();

    void updateHash(string nHash);

    /**
   * Returns the SHA256 of this block (by processing all the data stored
   * inside this block)
   *
   * @returns {string}
   */
    string calculateHash();

    string stringifyAttendance();

    /**
   * Starts the mining process on the block. It changes the 'nonce' until the hash
   * of the block starts with enough zeros (= difficulty)
   *    needs to be parallized
   * @param {number} difficulty
   */

    void mineBlock(int difficulty);

    /**
   * Validates all the transactions inside this block (signature + hash) and
   * returns true if everything checks out. False if the block is invalid.
   *
   * @returns {boolean}
   */
    // bool hasValidTransactions();
};
#endif