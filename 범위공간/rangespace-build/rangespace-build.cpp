#include <iostream>
#include <string>

using namespace std;

void sum(int x, int y) {
    
}

int main(int argc, char* argv[]) {
    int total = 0;
    for (int i = 1; i < argc; ++i) {
        string arg(argv[i]);
        int num = stoi(arg);
        // total = sum(total, num);
    }
    return total;
}