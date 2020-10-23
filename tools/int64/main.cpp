#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    int64_t num1;
    uint64_t work = 0xFF00000000000000;
    cin >> num1;

    cout << "0x";
    for(int i = 0; i < 8; ++i)
    {
        printf("%02lx", ((num1 & work) >> (8 * (7 - i))));
        work >>= 8;
    }
    cout << endl;
    return 0;
}
