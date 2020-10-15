#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    __int64_t num1;
    double res = 0.0f;
    scanf("%lx", &num1);
    res = *(double*)&num1;
    
    cout << res << endl;
    return 0;
}
