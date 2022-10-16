#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main() {
    // int s;
    // cin >> s;
    // vector<int> vec(s);
    // for(int i = 0; i < vec.size(); ++i) {
    //     cout << vec[i] << endl;
    // }
    // for (int num : vec) {
    //     cout << num << endl;
    // }

    // vector<int> vec(5, 2);
    // for (int num : vec) {
    //     cout << num << endl;
    // }

    // vec.resize(3);
    // for (int num : vec) {
    //     cout << num << endl;
    // }

    // vec.resize(10);
    // for (int num : vec) {
    //     cout << num << endl;
    // }

    // vec.resize(10, 7);
    // for (int num : vec) {
    //     cout << num << endl;
    // }

    // vector를 초기화없이 선언만 해주면 size가 0이 된다.
    // vector<int> vec;
    // cout << vec.size() << endl; // 0

    // vector는 동적이기때문에 뒤에 계속 값을 넣어줄 수 있다. 그리고 값을 넣어줄때마다 size가 증가한다.
    // vector<int> vec;
    // vec.push_back(10); // vector에 10이라는 값을 넣어줌
    // cout << vec[0] << endl; // 10
    // cout << vec.size() << endl; // 1

    // // pop_back 함수를 사용하면, 뒤에 있는 요소를 지울 수 있다.
    // vec.pop_back(); // vector맨 뒤 요소를 하나 지워줌
    // cout << vec.size() << endl; // 0

    // vector<int> vec;
    // vec.reserve(1000);

    // vector는 동적 배열이기 때문에, 내부적으로 사이즈가 변경될 때 계속 할당을 다시 해줘야한다.
    // for(int i = 0; i < 10; ++i) {
    //     vec.push_back(i);
    //     cout << vec.size() << endl;
    //     cout << vec.data() << endl;
    // }

    // std::array에서의 연산 적용해보기
    
    // std::array방식으로 초기화
    // vector<int> vec{1, 2, 3};
    // std::array에서의 front(), back() 함수 적용
    // cout << vec.front() << endl; // 1
    // cout << vec.back() << endl; // 3

    vector<int> vec0{1, 2, 3};
    vector<int> vec1{3, 2, 1};
    
    // std::array의 swap 연산
    // vec0.swap(vec1);
    // for (int num : vec0) {
    //     cout << num << endl;
    // }
    // for (int num : vec1) {
    //     cout << num << endl;
    // }

    // vec0 = vec1;
    // for (int num : vec0) {
    //     cout << num << endl;
    // }

    if (vec0 == vec1) {
        cout << "==" << endl;
    }
    if (vec0 > vec1) {
        cout << ">" << endl;
    }
    if (vec0 < vec1) {
        cout << "<" << endl;
    }
}