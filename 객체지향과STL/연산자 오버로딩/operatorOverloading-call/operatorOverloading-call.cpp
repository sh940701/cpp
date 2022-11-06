#include <iostream>
#include <algorithm>
#include <numeric>


using namespace std;

// class Max {
// private:
//     // numeric_limits class에서 지원하는 최대한 작은 숫자를 가져온다.
//     int _max = numeric_limits<int>::min();
// public:
//     int operator()(int x) {
//         // 파라미터를 입력받아 두 개 중 더 큰  녀석을 _max에 넣고, 그 _max값을 리턴해준다.
//         return _max = max(x, _max);
//     }
// };

// int main() {
//     Max mx;

//     // 이전에 입력받은 값과 비교하여 더 큰 값을 출력한다.
//     cout << mx(1) << endl;
//     cout << mx(2) << endl;
//     cout << mx(42) << endl;
//     cout << mx(1) << endl;
//     cout << mx(32) << endl;
// }

// 평균을 구하는 call 연산자 오버로딩 -> struct도 가능하다.
// struct Average {
// private:
//     double _total = 0;
//     int _times = 0;

// public:
//     double operator()(double value) {
//         _times += 1;
//         _total += value;
//         return _total / _times;
//     }

// };

// int main() {
//     // 이렇게 상태값을 저장하는 함수의 객체를 "함수 객체"라고 한다. Functer(?)
//     Average avg;

//     // 지금까지 입력되었던 모든 값에 대한 평균을 내서 출력해준다.
//     cout << avg(100) << endl;
//     cout << avg(200) << endl;
//     cout << avg(300) << endl;
// }

// 함수 객체 예시

// #include <functional>

// struct Print {
// public:
//     // 숫자를 입력받아 프린트해주는 함수
//     void operator()(int v) const {
//         cout << v << endl;
//     }
// };

// int main() {
//     // p 객체를 선언하고, 멤버함수를 사용하여 각 숫자를 넣어 함수를 실행해준다.
//     Print p;
//     int nums[] = {1, 2, 3, 4, 5};
//     for (int num : nums) {
//         p(num); // 1, 2, 3, 4, 5
//     }

//     // 위 실행문을 for_each를 사용하여 아래와 같이 함수객체 자체로 사용해줄 수 있다.
//     // for_each(첫 주소값, 마지막 주소값, 실행할 함수 객체)
//     for_each(nums, nums + size(nums), Print()); // 1, 2, 3, 4, 5

//     // 함수 객체는 <functional>과도 호환하여 사용할 수 있다.
//     Print p2;
//     function<void(int)> f = p2;
//     f(10); // 10
// }

// functional 모듈 안에는 pre-defined 된 함수 객체들이 있다.

#include <functional>

int main() {
    plus<int> p;
    cout << p(1, 2) << endl; // 3 -> 더하기 함수객체

    negate<int> n;
    cout << n(1) << endl; // -1 -> 마이너스 함수객체

    equal_to<int> et;
    cout << et(1, 1) << endl; // 1 -> 같은지 함수객체
}