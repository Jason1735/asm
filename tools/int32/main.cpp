#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    int num1;
    unsigned int work = 0xFF000000;
    cin >> num1;

    cout << "0x";
    for(int i = 0; i < 4; ++i)
    {
        printf("%02x", ((num1 & work) >> (8 * (3 - i))));
        work >>= 8;
    }
    cout << endl;
    return 0;
}
