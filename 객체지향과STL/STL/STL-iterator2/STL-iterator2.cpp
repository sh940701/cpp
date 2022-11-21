#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <iterator>
#include <fstream>
#include <set>

using std::cout;
using std::endl;

// int main() {
//     std::deque<int> v{2, 3};
//     v.push_front(1); // 1, 2, 3

//     auto iter = v.begin();
//     cout << *(iter + 2) << endl;
//     cout << *(std::addressof(*iter) + 2) << endl; // vector, array는 가능, deque는 불가능
// }

// iterator의 종류
// 위에서 아래로 내려갈수록 포함관계임


// forward iterator
// - forward_list, unordered xxx
// - ++

// bidirectional iterator
// - list, set, map, multiset, multimap
// - ++, --

// random access iterator - 상수 시간에 접근이 가능
// - array, vector, deque
// - ++, --, +, -

// contiguous access iterator(C++20)
// - array, vector
// - ++, --, +, -, physical memory dontiguous


// void ostreamIter(std::ostream& os) {
//     // os를 받아서, 1, 2, 3 을 한 번씩 넣어주는 것
//     // cout에 1, 2, 3 을 넣어주는 것이라고 생각하면 된다.
//     std::ostream_iterator<int> iter(os, " ");
//     *iter = 1;
//     *iter = 2;
//     *iter = 3;
// }

// int main() {
//     ostreamIter(std::cout); // 1, 2, 3
// }

// output iterator
// *iter = value -> 이렇게 값을 넣는 iterator
// *iter = value
// *iter = value // 덮어쓰는 것이 아니라 덧붙여 쓰는 것
// cout을 생각하면 됨

// fstream

// void ostreamIter(std::ostream& os) {
//     // os를 받아서, 1, 2, 3 을 한 번씩 넣어주는 것
//     std::ostream_iterator<int> iter(os, " ");
//     *iter = 1;
//     *iter = 2;
//     *iter = 3;
// }

// int main() {
//     std::ofstream ofs("output.txt");
//     ostreamIter(ofs); // output.txt 파일 생성, 안에서 write해준 1 2 3 이 들어가있음
// }


// void setInsert() {
//     std::set<int> s;

//     // inserter라는 output iterator를 이용하여 set에 데이터를 write하는 과정
//     // 이렇게 특별한 일을 하는 iterator들을 adaptor iterator라고 한다.
//     // std::insert_iterator iter(s, s.begin()); -> 아래와 같은 의미이다.
//     auto iter = std::inserter(s, s.begin());
//     *iter = 10;
//     *iter = 20;
//     *iter = 30;
//     *iter = 40;

//     for (auto num : s) {
//         cout << num << endl;
//     }
// }

// int main() {
//     setInsert();
// }


// input iterator
void istreamIter(std::istream& is) {
    // is 로부터 데이터를 읽어오겠다는 의미이다.
    std::istream_iterator<int> iter(is);
    // 읽은 데이터를 출력해보자
    
    // istream은 하나씩 읽기 때문에, 읽은 후 iter값을 증가시켜줘야 한다.
    auto value = *iter;
    cout << value << endl;
    ++iter;

    value = *iter;
    cout << value << endl;
    ++iter;

    value = *iter;
    cout << value << endl;
}

int main() {
    std::ifstream ifs("output.txt");
    istreamIter(ifs); // 1 2 3
}