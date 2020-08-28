#include <iostream>
#include "block.h"
#include "blockchain.h"
#include "sha/sha256.h"
using namespace std;

int main()
{
    cout << "Welcome to Student attendance system";
    Blockchain b1;
    cout << "\n ***************\n";
    // b1.printChain();
    cout << "mining block 1 \n";
    b1.addBlock(Block(999999999, {"18BCE0813", "18BCB1105"}));

    cout << "mining block 2 \n";
    b1.addBlock(Block(9999999, {"18BCE0813", "18BCB1105"}));
    b1.printChain();
    //Block bl1 = b1.chain.at(0);
    //Block bl2 = b1.chain.at(1);

    // cout << "chain valid? " << b1.isChainValid();
}