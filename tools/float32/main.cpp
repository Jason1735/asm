#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    float num1;
    unsigned int inum1 = 0;
    unsigned int work = 0xFF000000;
    cin >> num1;
    inum1 = *(int*)&num1;

    cout << "0x";
    for(int i = 0; i < 4; ++i)
    {
        printf("%02x", ((inum1 & work) >> (8 * (3 - i))));
        work >>= 8;
    }
    cout << endl;
    return 0;
}