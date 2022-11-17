보나치 함수
int fib(int value) {
    if (value <= 1) {
        return value;
    }
    return fib(value - 1) + fib(value - 2);
}

int main() {
    cout << fib(7) << endl;
}