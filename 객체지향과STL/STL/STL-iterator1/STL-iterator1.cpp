#include <iostream>
#include <vector>
#include <list>
#include "Range.h"

using std::cout;
using std::endl;

// int main() {
//     std::vector<int> v {1, 2, 3};

//     // mutable 원소를 가지면, *iter를 사용하여 value 변경도 가능하다.
//     for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
//         *iter *= 2;
//     }

//     // begin(), end() 는 mutable, cbegin(), cend() 는 immutable
//     // end()는 마지막 원소의 다음 iterator
//     // ++iter는 배열의 포인터처럼 iterator의 크기만큼 1씩 추가하여 다음 원소를 가리키게 된다.
//     for (std::vector<int>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter) {
//         cout << *iter << endl;
//     }
// }


// vector 내에 어떤 수가 있는지 알아보는 함수를 만들어보자
// TIterator에는 type별 iterator가 들어간다.
// template<typename TIterator, typename T>
// bool has(const TIterator& begin, const TIterator& end, T value) {
//     for (auto iter = begin; iter != end; ++iter) {
//         if (*iter == value) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     cout << std::boolalpha;
//     std::vector<int> v{1, 2, 3};
//     cout << has(v.begin(), v.end(), 2) << endl; // true
//     cout << has(v.begin(), v.end(), 7) << endl; // false

//     // 그런데 만약 vector가 아닌, 같은 구성의 list라면 우리가 만든 has 함수를 사용할 수 없다.
//     // 이 때는 template과 iterator를 사용하여 모두 사용 가능하게 해줄 수 있다.
    
//     std::list<int> li{1, 2, 3};
//     cout << has(li.begin(), li.end(), 2) << endl; // true
//     cout << has(li.begin(), li.end(), 7) << endl; // false
// }


// iterator를 사용하여 주어진 범위에 대해서만 동작하는 함수를 만들어보자


int main() {
    for (int num : Range(0, 3)) {
        cout << num << endl; // 0, 1, 2
    }

    std::vector<int> v{1, 2, 3};
    for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){

    }
}