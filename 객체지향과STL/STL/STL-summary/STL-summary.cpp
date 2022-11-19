#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <set>
#include <unordered_set>
#include <functional>

using std::cout;
using std::endl;

// vector

// int main() {
//     std::v<int> v;
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);

//     for (int num : v) {
//         cout << num << endl; // 10, 20, 30 순서대로 나옴
//     }
// }

// deque

// int main() {
//     std::deque<int> d;
//     d.push_back(10);
//     d.push_back(20);
//     d.push_back(30);
//     d.push_front(3);

//     for (int num : d) {
//         cout << num << endl; // 3, 10, 20, 30 -> 넣는 순서대로 나옴
//     }
// }

// set

// int main() {
//     std::set<int> s;
//     s.insert(10);
//     s.insert(100);
//     s.insert(20);
//     s.insert(30);

//     for (int num : s) {
//         cout << num << endl; // 10, 20, 30, 100 -> 정렬되어서 나옴
//     }
// }

// unordered_set

// int main() {
//     std::unordered_set<int> us;
//     us.reserve(10);

//     us.insert(-1);
//     us.insert(100);
//     us.insert(20);
//     us.insert(10);


//     for (int num : us) {
//         cout << num << endl;
//     }
// }

// iterator

// int main() {
//     std::vector<int> v{1, 2, 3, 4};

//     // 일반적인 for문으로 순회
//     for (int i = 0; i < v.size(); ++i) { // [0, v.size())
//         cout << v[i] << endl; // 1, 2, 3, 4
//     }
//     cout << endl;

//     // range_based_for문으로 순회
//     for (int num : v) {
//         cout << num << endl; // 1, 2, 3, 4
//     }
//     cout << endl;

//     // interator를 사용하여 순회
//     // 여기서 iter는 <int>타입 iterator이기 때문에 ++iter를 하면 int type size만큼 커진다.
//     // v.begin()은 v의 첫번째를 가리키는 iterator를 반환해줌
//     // v.end()는 v의 마지막 + 1번째 녀석을 가리키는 iterator를 반환해줌
//     for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) { // [begin, end)
//         // 포인터같은 역할을 하기 때문에, 역참조를 사용하여 핸들링 가능
//         cout << *iter << endl; // 1, 2, 3, 4
//     }
// }


// algorithm

// int main() {
//     std::vector<int> nums{10, 20, -1, -3};
//     // nums.begin(), nums.end() 등 iterator 객체를 넘겨주었다.
//     // iterator를 통해서 algorithm을 적용할 범위를 정해줄 수도 있다.
//     std::sort(nums.begin(), nums.end() -1);
//     for (int num : nums) {
//         cout << num << endl;
//     }
// }

int main() {
    std::vector<int> nums{10, 20, -1, -3};
    // 아래와 같이 함수 객체를 넘겨주어 설정값을 정해줄 수도 있다.
    std::sort(nums.begin(), nums.end(), std::greater());
    for (int num : nums) {
        cout << num << endl; // 20, 10, -1, -3
    }
}