#include <iostream>

using namespace std;

int main() {
    // cout << 40 - 32 / 2 << "==" << 24 << endl;

    // cout << 4 - 6 + 2 + 8 / 2 / 2 * 2 << endl;

    int num(10);

    cout << ++num + num++ << endl;
    cout << num << endl;

    printf("%d %d\n", ++num, ++num);
    printf("%d\n", num);
}