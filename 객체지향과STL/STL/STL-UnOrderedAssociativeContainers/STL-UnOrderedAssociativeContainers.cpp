#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;

// int main() {
//     // unordered 객체는 타입 파라미터로 뒤에 두 개를 더 넣어줄 수 있다.
//     // 세 번째는 해시함수 객체이고, 네 번째는 충돌이 생겼을 때, 같은 버킷에
//     // 키가 중복되는 녀석이 있는지 확인해야하는데, 이를 위해서 사용되는 함수 객체이다.
//     std::unordered_map<int, std::string> um {
//         {1, "10"},
//         {2, "20"},
//         {3, "30"},
//         {4, "40"},
//     };

//     cout << um[3] << endl; // 30 -> 기본적으로 첨자연산을 지원한다.
// }
// unordered에서는 해시충돌로 인해 같은 버킷에 담기게 될 경우
// 첫째 pair와 그 다음 들어온 pair를 리스트로 연결한다.
// b0 -> {123, "abc"} -> {321, "acb"}



// 간단한 해시함수를 만들어보자
struct HashFunc {
    // 해시함수 객체에 파라미터로는 key값이 들어오게 된다.
    size_t operator()(const int& key) const {
        // 만약 모든 해시 결과값을 1로 리턴한다고 해보자. 어떤 문제가 생길까?
        return 1;
    }
};

int main() {
    std::unordered_map<int, int, HashFunc> um;
    for (int i = 0; i < 10000; ++i) {
        um[i] = i;
    }

    cout << um.bucket_count() << endl; // 12853 -> 총 bucket의 개수
    cout << um.bucket_size(0) << endl; // 0 -> 0번 bucket의 size
    cout << um.bucket_size(1) << endl; // 10000 -> 1번 bucket의 size

    // 만약 위와같은 상황이 발생하게 되면, key를 새로 넣을 때마다 bucket1에 들어가게 되고
    // 하나를 넣어줄 때 마다 10000개의 버킷을 다 돌면서 키가 겹치는지 확인 후 들어간다.
    // 그만큼 작업이 느려지고 오버헤드가 커지는 것이다.
    // 만약 HashFunc를 지우고 실행하면, default 해시가 진행되어 요소가 고르게 분포하게 된다.
    // 기본적으로 제공되는 해시 함수는 std::hash<int>이다.
}