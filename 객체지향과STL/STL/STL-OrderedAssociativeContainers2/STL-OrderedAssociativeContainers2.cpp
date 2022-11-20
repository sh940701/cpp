#include <iostream>
#include <map>
#include <set>
#include <functional>

using std::cout;
using std::endl;

// int main() {
//     cout << std::boolalpha;
//     std::map<int, std::string> m {
//         {1, "1"},
//         {2, "2"},
//         {3, "3"}
//     };

//     // insert가 실행된 후 리턴되는 값을 출력해보자
//     // map type이 first, boolean type이 second로 들어가는 pair가 리턴된다.
//     // boolean은 insert가 성공했는지 실패했는지를 반환한다.
//     // map은, 성공하면 삽입된 녀석, 실패하면 원래 있던 녀석을 반환한다.
//     // std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({3, "10"});
//     // 위 녀석도 auto로 추론이 가능하다.
//     auto result = m.insert({3, "10"});
//     // pair의 경우에 C++ 이후 구조적 바인딩을 이용해 아래와 같이도 담아줄 수 있다.
//     // 아래에서 iter에는 결과값의 first, success에는 결과값의 second가 들어간다.
//     auto [iter, success] = m.insert({3, "10"});
    
//     // 성공 여부를 출력해보자
//     cout << result.second << endl; // key = 3 이 있으면 false, 없으면 true
//     // result.first는 pair type이고, 이 pair의 key, value를 출력해보자
//     cout << result.first->first << endl; // key = 3이 있어도 3, 없어도 3
//     cout << result.first->second << endl; // key = 3이 있으면 원래 value, 없으면 새로 들어간 value
// }


// 구조적 바인딩

// int main() {
//     std::map<int, std::string> m {
//         {1, "1"},
//         {2, "2"},
//         {3, "3"}
//     };

//     for (auto& [key, value] : m) {
//         value = "abc";
//     }

//     for (const auto [key, value] : m) {
//         cout << key << " : " << value << endl;
//     }
// }

// int main() {
//     cout << std::boolalpha;
//     std::map<int, std::string> m {
//         {1, "1"},
//         {2, "2"},
//         // {3, "3"}
//     };

//     if (auto [iter, success] = m.insert({3, "10"}); success) {
//         cout << success << endl;
//         cout << iter->first << endl;
//         cout << iter->second << endl;
//     }
// }

// int main() {
//     cout << std::boolalpha;
//     std::map<int, std::string> m {
//         {1, "1"},
//         {2, "2"},
//         {3, "3"}
//     };
    
//     // m.count(n) -> m에 n이라는 key의 value가 있는지 확인
//     cout << m.count(1) << endl; // 1
//     cout << m.count(10) << endl; // 0

//     // 있는지 없는지 + 있다면 해당 iterator를 가져와보자 -> m.find(n)
//     std::map<int, std::string>::iterator iter = m.find(10);
//     auto iter = m.find(3); // 위 녀석도 auto로 변경 가능
    
//     // 있다면 iterator를 반환, 없다면 m.end()를 반환한다.
//     // C++17 이후 전역 말고 if문 한정으로 아래와 같이 사용 가능
//     if (auto iter = m.find(3); iter != m.end()) {
//         cout << iter->second << endl; // m.find(3) -> 3
//     }
// }

// int main() {
//     cout << std::boolalpha;
//     std::map<int, std::string> m {
//         {1, "1"},
//         {2, "2"},
//         {3, "3"}
//     };

//     // 있었는데요.
//     cout << m.count(3) << endl; // 1
    
//     if (auto iter = m.find(3); iter != m.end()) {
//         cout << iter->second << endl; // 3
//         // erase 함수를 사용해서 해당 요소를 지울 수 있다.
//         m.erase(iter);
//     }

//     // 없어요.
//     cout << m.count(3) << endl; // 0

//     // erase 함수는 iterator 혹은 key만 넘겨줘서 지울 수도 있다.
//     m.erase(2);
//     cout << m.count(2) << endl; // 0

// }



// multi map

// int main() {
//     std::multimap<int, std::string> mm {
//         {2, "10"},
//         {1, "20"},
//         {1, "30"},
//         {1, "40"},
//     };

//     // multimap과 일반 map이 다른점 - 첨자 연산
//     // 하나의 key에 여러 value를 가질 수 있기 때문에 첨자연산이 안된다.
//     // mm[1] = "bc"; // error

//     // multimap과 일반 map이 다른점 - insert
//     // multimap은 insert가 무조건 성공한다.
//     // 따라서 multi에서 insert연산 리턴값은 {iterator, bool}이었다면, multimap에서는 iterator를 리턴한다.

//     std::multimap<int, std::string>::iterator iter = mm.insert({1, "100"});
//     cout << iter->first << " : " << iter->second << endl;

//     for (auto& [key, value] : mm) {
//         cout << key << " : " << value << endl;
//     }
// }

// int main() {
//     std::multimap<int, std::string> mm {
//         {2, "10"},
//         {1, "20"},
//         {1, "30"},
//         {1, "40"},
//     };

//     // 만약 1이라는 key에 담긴 모든 value를 알고싶으면 어떻게 해야할까?
//     // mm.find(1)을 하면 하나만 나온다. -> 이 때 사용하는게 bound이다.
//     std::multimap<int, std::string>::iterator lower = mm.lower_bound(1);
//     std::multimap<int, std::string>::iterator upper = mm.upper_bound(1);
    
//     // lower는 key 1의 value중 첫번째, upper는 key 1의 value중 마지막 요소의 다음 위치이다.
//     for (auto& iter = lower; iter != upper; ++iter) {
//         cout << iter->first << " : " << iter->second << endl; // 1 : 20, 1 : 30, 1 : 40
//     }

//     // 위와같은 lower와 upper를 한 번에 구할 수 있는 equal_range라는 녀석도 있다.
//     // equal_range의 리턴값은 lower와 upper의 iterator pair이다.
//     std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> lowerUpper = mm.equal_range(1);
//     auto lower1 = lowerUpper.first;
//     auto upper1 = lowerUpper.second;

//     for (std::multimap<int, std::string>::iterator iter = lower1; iter != upper1; ++iter) {
//         cout << iter->first << " : " << iter->second << endl;
//     }

//     // 위 코드를 auto와 구조적 바인딩을 사용해서 아래와 같이 단순화할 수 있다.
//     auto [lower2, upper2] = mm.equal_range(1);
//     for (auto iter = lower2; iter != upper2; ++iter) {
//         cout << iter->first << " : " << iter->second << endl;
//     }
// }


// set
// int main() {
//     cout << std::boolalpha;
//     // key와 value가 동일하기 때문에 template parameter를 하나만 받는다.
//     std::set<int> s{
//         1, 2, 3, 4
//     };
//     // 첨자연산은 지원하지 않는다. insert를 사용해야 함
//     // insert연산 리턴값은 map과 동일하다.
//     // 구조적 바인딩을 하려면 타입을 auto로 해줘야 하는 것 같다!!
//     // std::pair<std::set<int>::iterator, bool> [iter, success] = s.insert(10);

//     if (const auto& [iter, success] = s.insert(10); success) {
//         cout << success << endl;
//         // set의 iter는 pair가 아니라 들어간 값 그 자체이다. -> const integer type
//         cout << *iter << endl;
//     }
// }


// multiset
// int main() {
//     std::multiset<int> ms {
//         1, 1, 3, 10, 10, 3
//     };

//     // 이녀석도 값을 넣으면 항상 성공이기 때문에, return 값이 bool이 없고 iterator만 있다.
//     auto iter = ms.insert(1);
//     cout << *iter << endl; // 1
    
//     cout << ms.count(1) << endl; // 3

//     for (int num : ms) {
//         cout << num << endl;
//     }

//     // multiset 또한 내부적으로 lower_bound, upper_bound, equal_range를 가지고 있다.
// }


// set 템플릿 파라미터에 두 번째 인자 넣기

// int main() {
//     // std::less<type>는 left < right를 리턴해주는 함수 객체이다.
//     // 인자값으로 각 key가 들어가서, key의 value끼리 비교연산을 진행한다.
//     // 이러한 함수객체의 실행결과값을 기준으로 정렬이 되고, less는 set, map의 default값이다.
//     std::set<int, std::less<int>> s;
//     std::map<int, std::string, std::less<int>> m;
// }


template<typename T>
struct Greater {
    // 실행을 하는데, 함수 뒤에 const를 붙여주지 않으면 자꾸 warning이 뜨는 것이다. -> 근데 또 실행은 된다..
    // 근데 const는 객체가 있을 때 this의 값을 변경하지 않겠다는 의미로 붙여주는 것인데
    // 너무 이상해서 계속 찾아보다가 결국에는 경고메시지에서 찾았다.
    // set::set 클래스의 618번줄에 근거한 에러였다.
    // warning: the specified comparator type does not provide a viable const call operator
    // 경고: 지정한 비교기 유형이 실행 가능한 상수 호출 연산자를 제공하지 않습니다.
    // set에서 받은 함수 객체를 어떻게 사용하는지는 잘 모르겠지만, 결과적으로 이 함수 객체는
    // 두 값을 비교하는 함수여야 하고 꼭 상수여야 한다는 것이다.
    // 뿌듯... 하기도 하고 좀 더 자세히 알고싶은 마음도 간절하다 알면 알수록....
    bool operator()(const T& left, const T& right) const {
        return left > right;
    }
};

int main() {
    std::set<int, std::less<int>> s0 {
        3, 10, -1
    };
    for (const auto& num : s0) {
        cout << num << endl; // -1, 3, 10
    }

    std::set<int, std::greater<int>> s1 {
        3, 10, -1
    };
    for (const auto& num : s1) {
        cout << num << endl; // 10, 3, -1
    }

    // 함수 객체를 만들어서 실행하기
    std::set<int, Greater<int>> s2 {
        3, 10, -1
    };
    for (const auto& num : s2) {
        cout << num << endl; // 10, 3, -1
    }
    
}