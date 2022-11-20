#include <iostream>
#include <map>

using std::cout;
using std::endl;

// int main() {
//     // map은 class template 타입으로, template인자 두 개를 받는다.
//     // 왼쪽 녀석은 key, 오른쪽 녀석은 value에 해당한다. -> key가 value에 맵핑(대응)된다.
//     const std::map<int, std::string> m;

//     // 대응
//     m[1] = "a";

//     // 조회
//     cout << m[1] << endl; // a
//     cout << m.size() << endl; // 1

//     // 없는 녀석을 조회하면 공백이 나오고, size가 2로 늘어나게 된다.
//     cout << m[2] << endl; // " "
//     cout << m.size() << endl; // 2

//     // 첨자연산자[]로 조회를 할 때 key가 없다면 value의 default생성자를 호출해 값을 넣어준다.
//     // 이와 같은 맥락에서 map을 만들 때 const로 선언을 하면 첨자연산호출이 불가능하다.
//     // 첨자연산으로 실행했다가 value의 default값이 들어가게 되면 map이 바뀌는 것이기 때문이다.
// }


// 첨자연산이 아닌 다른 방법으로 map을 다뤄보자

// int main() {
//     std::map<int, std::string> m {
//         // map은 key가 중복되면 안됨.
//         {2, "1"}, // {key, value} -> initializer list
//         std::pair(1, "2"), // pair 사용 -> pair 템플릿에 타입이 추론된것임
//         std::make_pair(3, "3") // make_pair 사용
//     };

//     // range_based_for문으로 원소들을 출력해보자.
//     // 원소들은 모두 pair의 형식으로 저장되어 있기 때문에 pair의 타입을 명시해준다.
//     // key값은 어떤 순서로 넣어도 1, 2, 3으로 정렬되어 나오는 것을 확인할 수 있다.
//     for (const std::pair<int, std::string>& pair : m) {
//         cout << pair.first << " : " << pair.second << endl;
//     }
// }

// int main() {
//     std::map<int, std::string> m {
//         {2, "1"},
//         {1, "2"},
//         {3, "3"}
//     };

//     // 이 안에서 한번 원소를 바꿔보자
//     // pair앞의 const를 빼고 각 key의 value를 바꾸려고 하는데 안된다. 왜일까?
//     // pair의 key인 int는 사실 그냥 int가 아니라 const int이기 때문이다.
//     // 임의로 이미 저장되어있는 key의 값을 바꾸려고 하면, 해당 자리에 다른 숫자가 들어가게 되고
//     // 이미 정렬되어있는 key를 바꿈으로써 map tree의 정합성이 파괴되기 때문에 막아놓은 것이다.
    
//     // 근데 나는 key가 아니라 value를 바꾸려고 하는데?
//     // 그럴땐 key의 타입 앞에 const를 붙여주면 된다. 어차피 들어가면 const type이 되는것이긴 하지만
//     // 만약 해당 타입이 int가 아니라 큰 사이즈의 복잡한 데이터라면, 복사하고 const type으로 바꾸는 과정에
//     // 성능을 저하시킬 수도 있고 여러 에러가 발생할 수도 있다. 이런 상황을 방지하기 위해 지원을 안해주는 것이다.

//     // 그럼 std::pair앞의 const는 무슨 의미이지? -> pair에 대한 const는 second를 바꿀 수 있는 여부이다.
//     for (std::pair<const int, std::string>& pair : m) {
//         pair.second = "abc";
//         cout << pair.first << " : " << pair.second << endl;
//     }
// }

// int main() {
//     std::map<int, std::string> m {
//         {2, "1"},
//         {1, "2"},
//         {3, "3"}
//     };

//     // auto를 사용하면 컴파일러가 알아서 추론을 해주기 때문에 value 변경에 대한 문제가 없다.
//     for (auto& pair : m) {
//         pair.second = "abc";
//         cout << pair.first << " : " << pair.second << endl;
//     }

//     // const를 붙이면 그대로 value 값이 변환되지 않는다.
//     for (const auto& pair : m) {
//         pair.second = "abc";
//         cout << pair.first << " : " << pair.second << endl;
//     }
// }


// iterator

// int main() {
//     std::map<int, std::string> m {
//         {2, "1"},
//         {1, "2"},
//         {3, "3"}
//     };

//     for(std::map<int, std::string>::iterator iter = m.begin(); iter != m.end(); ++iter) {
//         // iter가 가리키는 녀석이 하나의 pair이다.
//         iter->second = "cba";
//     }

//     // 그런데 아래 녀석에서는 출력만 해줄 것인데 내부적으로 value 변경이 가능하다.
//     // 이를 막기위해선 const_iterator, cbegin(), cend() 를 사용해주면 된다.
//     for(std::map<int, std::string>::const_iterator iter = m.cbegin(); iter != m.cend(); ++iter) {
//         cout << iter->first << " : " << iter->second << endl;
//     }

//     // 위와같이 iterator를 사용하는 녀석도 auto로 만들어줄 수 있다.

//     for(auto iter = m.begin(); iter != m.end(); ++iter) {
//         // iter가 가리키는 녀석이 하나의 pair이다.
//         iter->second = "999";
//     }

//     // 그런데 아래 녀석에서는 출력만 해줄 것인데 내부적으로 value 변경이 가능하다.
//     // 이를 막기위해선 const_iterator, cbegin(), cend() 를 사용해주면 된다.
//     for(auto iter = m.cbegin(); iter != m.cend(); ++iter) {
//         cout << iter->first << " : " << iter->second << endl;
//     }
// }


// insert

int main() {
    std::map<int, std::string> m {
        {1, "1"},
        {2, "2"},
        {3, "3"}
    };

    // 첨자연산 삽입
    m[1] = "a";
    m[1] = "b";
    // 첨자연산으로 삽입 시 위와같이 이미 있는 녀석에 대해서는 덮어 씌워지게 된다.
    // 덮어씌우지 않고, 없는 원소에 대해서만 삽입을 원하면 insert를 사용하자.
    // 삽입은 initilizer list, pair, make_pair 모두 사용 가능하다.
    m.insert({3, "10"});
    cout << m[3] << endl; // 3 -> 이미 있기 때문에 삽입이 안됐다.

    auto iter = m.begin()++;

    cout << iter->second << endl;
}