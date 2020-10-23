#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    int num1;
    float res = 0.0f;
    scanf("%x", &num1);
    res = *(float*)&num1;
    printf("%.15f\n", res);
    //cout << res << endl;
    return 0;
}
