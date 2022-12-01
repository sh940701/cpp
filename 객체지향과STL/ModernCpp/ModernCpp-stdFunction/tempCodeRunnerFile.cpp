
    static int func(float value) {
        return value;
    }
};

int main() {
    std::function<int (float)> f = Func::func;
    std::cout << f(10) << std::endl;
}