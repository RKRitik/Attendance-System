#include <iostream>
#include "block.h"
#include "blockchain.h"
#include "sha/sha256.h"
using namespace std;

int main()
{
    cout << "Welcome to Student attendance system";
    Blockchain b1;
    b1.printChain();
    b1.addBlock(Block(999999999));
    b1.printChain();
}