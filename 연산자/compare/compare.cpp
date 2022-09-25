#include <iostream>

using namespace std;

int main() {
    int num0 = 10, num1(10);
    if (num0 <=> num1)
        cout << "num0 == num1" << endl;
}