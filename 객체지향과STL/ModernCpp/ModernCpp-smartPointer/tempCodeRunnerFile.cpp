struct Test {
    int num;
    Test(int num) : num(num) {
        std::cout << "Construct: " << num << std::endl;
    }

    ~Test() {
        std::cout << "Destruct: " << num << std::endl;
    }
};
