nt main() {
    std::map<int, std::string> m {
        {2, "1"},
        {1, "2"},
        {3, "3"}
    };

    // 이 안에서 한번 원소를 바꿔보자
    for (const std::pair<int, std::string>& pair : m) {
        cout << pair.first << " : " << pair.second << endl;
    }
}