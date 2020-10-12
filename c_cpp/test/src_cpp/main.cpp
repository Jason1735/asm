#include <iostream>

using namespace std;
extern "C" int add(int, int);
extern "C" int sub(int, int);
int main(int argc, char *argv[])
{
	cout << "Result = " << add(10, 7) << "." << endl; 
	cout << "Result = " << sub(10, 7) << "." << endl; 
	return 0;
}

