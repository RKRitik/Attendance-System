#include <iostream>
#include "block.h"
#include "sha/sha256.h"
using namespace std;

int main()
{
    cout << "Welcome to Student attendance system";
    cout << "\n sha256 of ritik is " << sha256("ritik");
    Block b1(12344444);
    cout << b1.printHash();
}