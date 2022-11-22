#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using std::cout;
using std::endl;

// 대부분 알고리즘 안의 함수들의 형태
// void func(iter begin, iter end);
// void func(iter begin, iter end, Functor func);


// 함수객체 -> 호출할 수 있는 객체
// struct Func {
//     int operator()(int value) const {
//         return value;
//     }
// };

// int main() {
//     // 만든 함수 객체 사용
//     Func func;
//     func(10); // 10
// }


// int main() {
//     // Lamda -> 일종의 callable한 익명 함수
//     // 대괄호, 소괄호, 중괄호의 형태로 생겼다.
//     // 대괄호에는, 함수 밖에 있는 녀석을 캡쳐할 때 쓸 수 있다. -> 대괄호 안에 없으면 접근 불가
//     // 소괄호에는 함수 인자값이 들어간다.

//     // Lamda에서는 return type을 정해주지 않아도, auto를 사용해 추론이 가능하다.
//     int num = 77;
//     auto func0 = [num](int value) {
//         return num + value;
//     };

//     cout << func0(23) << endl; // 100;
// }



// int main() {
//     std::vector<int> v{1, 2, 3};
//     // 시작부터 끝까지 탐색하여 2가 있는지 찾는다.
//     // 있다면 해당 iterator, 없다면 v.end 위치의 iterator가 반환된다.
//     auto iter0 = std::find(v.begin(), v.end(), 2);
//     if (iter0 != v.end()) {
//         cout << *iter0 << endl;
//     }

//     std::set<int> s{1, 2, 3};
//     // set에서도 std::find를 사용이 가능하다.
//     // auto iter1 = std::find(s.begin(), s.end(), 2);

//     // 그런데 set에는 find라는 내장함수가 왜 따로 있을까? -> 효율성 때문에
//     // 내장함수로 find 등이 따로 있는 녀석은 무조건 그걸 쓰는게 성능면에서 이득이다.

//     auto iter1 = s.find(2);
//     if (iter1 != s.end()) {
//         cout << *iter1 << endl; // 2
//     }

//     // set, map은 unordered, ordered, multi 안 가리고 find를 가지고 있다. 무조건 이걸 써야 한다.
// }


// int main() {
//     std::set<int> s{1, 2, 3};
//     s.find(2); // O(log (n))

//     std::unordered_set<int> us{1, 2, 3};
//     us.find(2); // O(1)

//     auto iter = std::find(s.begin(), s.end(), 2); // O(n)
// }


int main() {
    // std::에는 find_if라는 함수가 있는데, 이는 set 등의 내부함수로 들어있지 않다.
    // 실제로 tree, hash table container에서는 key에 따른 조건으로 정렬을 해놓기 때문에
    // 이를 사용해서 좀 더 효율적으로 find를 실행할 수 있는 것이다.
    // 그런데 find_if는 key, value 혹은 다른 어떤 것을 기준으로 탐색할지 모르기 때문에
    // 내부함수로 따로 지원하지 않는 것이다. 어차피 iterator로 순회를 해야 하기 때문에

    std::set<int> s{1, 2, 3};
    // s.find_if(); // error

    std::unordered_set<int> us{1, 2, 3};
    // us.find_if() // error
    
    std::vector<int> v{1, 2, 3};
    // 세번째 인자로 함수 객체 대신 Lamda 식 사용 -> value에는 1, 2, 3이 들어간다.
    // 아래와 같이 key가 아니라, 조건을 만족하는 값을 찾기 위해서 사용도 가능하기 때문에
    // find_if는 순회를 해야만 한다.
    auto iter = std::find_if(v.begin(), v.end(), [](const int& value) {
        if (value % 2 == 0) {
            return true;
        }
    }); // O(n)
    cout << *iter << endl;
}