#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;

// int main() {
//     std::vector<int> v{1, 2, 3, 4 , 3, 2, 1};
//     // 시작부터 끝까지 순회하며, 2 라는 값을 지우는 함수 실행
//     auto iter = std::remove(v.begin(), v.end(), 2);

//     for (auto num : v) {
//         cout << num << endl; // 1, 3, 4, 3, 1, 2, 1
//     }

//     cout << endl;

//     // remove만 진행을 하면, 실제로 2가 있던 자리를 한 칸 앞으로 당겨온다.
//     // 위에서는 두 개가 있었기 때문에 두 칸이 당겨지고 뒤에 두개는 2, 1이 원래대로 있는 것이다.
//     // 이를 해결하기 위해 뒤에 있는 두 칸을 지워보자, erase함수를 사용한다.
//     // remove 함수의 반환값은 iterator로, 정상적으로 나온 값(1, 3, 4, 3, 1)바로 뒤를 가리킨다.
//     v.erase(iter, v.end());

//     for (auto num : v) {
//         cout << num << endl; // 1, 3, 4, 3, 1
//     }
// }

// int main() {
//     std::list<int> v{1, 2, 3, 4, 3, 2, 1};
//     // list의 내장함수는 우리가 원하는 것처럼 동작한다.
//     // 내부적으로 연결고리를 끊고 다시 앞뒤를 연결하는 식으로 구현이 가능하기 때문이다.
//     v.remove(2);
    
//     std::remove(v.begin(), v.end(), 2);

//     for (auto num : v) {
//         cout << num << endl; // 1, 3, 4, 3, 1
//     }

//     v.remove_if([](const int& value) {
//         return value % 2 == 0; // 짝수만 다 지움
//     });

//     for (auto num : v) {
//         cout << num << endl; // 1, 3, 3, 1
//     }
// }

// int main() {
//     std::set<int> v{1, 2, 3, 4, 3, 2, 1};
//     auto iter = std::remove(v.begin(), v.end(), 2); // error
// }

// int main() {
//     std::set<int> v{1, 2, 3, 4, 3, 2, 1};

//     // 내부적으로 ++iter를 해주기 때문에 for문에서 넣지 않아도 된다.
//     for (auto iter = v.begin(); iter != v.end();) {
//         // iter가 2를 가리키면, 그 iter를 지운다. 그럼 그 반환값은 다음(3)이 될 것이다.
//         // 다시 for문을 돌면, 해당 iter(3) 에 대한 검사를 시작하게 된다.
//         if (*iter == 2) {
//             iter = v.erase(iter);
//         } else {
//             // 만약 *iter가 2라서 위 iter에 3이 들어갔다고 하면, for문에서 ++iter를 하면 다음에
//             // 3에 대한 검사를 건너 뛰고 4로 넘어가게 된다. 그래서 for문이 아니라 else일때 ++iter를 하는 것이다.
//             ++iter;
//         }
//     }
//     for (auto num : v) {
//         cout << num << endl; // 1, 3, 4
//     }
// }


// int main() {
//     // 배열의 복사
//     int nums0[] = {1, 2, 3, 4};
//     int nums1[std::size(nums0)];
//     std::copy(std::begin(nums0), std::end(nums0), nums1);

//     for (int num : nums1) {
//         cout << num << endl; // 1, 2, 3, 4
//     }

//     // vector의 복사
//     std::vector<int> v0 = {1, 2, 3, 4};
//     std::vector<int> v1(v0.size());
//     std::copy(v0.begin(), v0.end(), v1.begin());

//     for (int num : v1) {
//         cout << num << endl; // 1, 2, 3, 4
//     }
// }


// vector에 사이즈를 넣지 않고도 copy를 해줄 수 있다.
int main() {
    std::vector<int> v0 = {1, 2, 3, 4};
    // 아래와 같이 사이즈를 아예 잡지 않으면 에러가 발생한다.
    // 이는 copy가 내부적으로 v0과 v1이 같이 돌면서 v0의 원소를 v1에 하나씩 넣어주기 때문이다.
    // 그러므로 v1의 사이즈가 v0의 사이즈 이상이 아니라면 예외가 발생하는 것이다.
    std::vector<int> v1;
    // std::copy(v0.begin(), v0.end(), v1.begin());

    // 위와 같은 상황을 타개하기 위해 back_inserter라는 것을 사용할 수 있다.
    // 이 녀석은 내부적으로 back_insert_iterator를 리턴해주고, back_insert_iterator는
    // output으로, 계속 "써지는" 녀석이다. -> push_back을 해줌으로.
    // 그러니까, copy함수에서 v0과 v1이 같이 돌며, v0의 녀석을 v1에 push_back해줌으로써
    // v1도 크기가 자동으로 늘어나 정상적으로 copy가 되는 것이다.
    std::copy(v0.begin(), v0.end(), std::back_inserter(v1));

    for (int num : v1) {
        cout << num << endl; // 1, 2, 3, 4
    }
}