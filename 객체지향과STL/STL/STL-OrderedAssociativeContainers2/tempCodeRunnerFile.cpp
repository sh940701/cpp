td::set<int, Greater<int>> s2 {
        3, 10, -1
    };

    for (const auto& num : s2) {
        cout << num << endl; // 10, 3, -1
    }