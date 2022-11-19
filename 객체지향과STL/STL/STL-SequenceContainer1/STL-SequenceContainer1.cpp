#include <iostream>
#include <array>
#include <vector>
#include <deque>

using std::cout;
using std::endl;

// int main() {
//     std::array<int, 5> arr;
// }

// int main() {
//     std::vector<int> vec {1, 2, 3};
//     // iter는 vec의 첫번째 원소의 iterator 이다.
//     std::vector<int>::iterator iter = vec.begin();
//     // num은 vec[0]의 참조값이다.
//     int& num = vec[0];

//     int* pNum0 = &vec[0];

//     // vec[0]의 값을 10으로 할당해보자
//     vec[0] = 10;
//     cout << *iter << endl; // 10
//     cout << num << endl; // 10

//     // reserve는 최소한 인자값으로 들어온 녀석만큼은 capacity를 잡아주는 녀석이다.
//     // 재할당으로 인한 오버헤드를 줄이기 위해선, 배열의 길이를 알고 있을 경우 reserve를 미리 정해주는것이 좋다.
//     // 아래에서는 원래 capacity + 1 만큼 할당하였으므로, 무조건 재할당이 일어난다.
//     vec.reserve(vec.capacity() + 1);
//     vec[0] = 100;

//     int* pNum1 = &vec[0];

//     // vec[0]을 100으로 바꿔줬는데 왜 아래에서는 10이 나올까?
//     // 아래 예시에서 알 수 있다시피, capacity가 변하면 원래 값들이 새로운 배열에 할당된다.
//     // 따라서 *iter, num은 기존 주소를 가리키고 있기 때문에 그대로 10이 나온 것이다.
//     cout << *iter << endl; // 10
//     cout << num << endl; // 10

//     // 같은 vec[0]이지만 재할당이 일어나 주소값이 다르다.
//     cout << pNum0 << endl; // 0x141e069e0
//     cout << pNum1 << endl; // 0x141e069f0
// }
    // vector는 내부적으로 size와 capacity로 이루어져 있다.
    // vector size, capacity

    // [1, 2, 3, ?] -> 위 vec의 원래 생긴 모습
    // vector size = 3
    // capacity = 4 -> vector의 사이즈는 3, capacity = 4이다.

    // push_back(4) -> 4를 더해준다고 생각해보자.
    // [1, 2, 3 , 4] -> 변경된 모습
    // vec size = 4
    // capacity = 4

    // push_back(5) -> 5를 또 더해줘보자
    // [1, 2, 3, 4, 5, ?, ?, ?] -> capacity가 늘어나는데, 보통 두 배로 늘어난다.
    // 이 때 배열이 바뀐다. 그러니까 완전히 새로운 배열에 원래 배열 요소들이 복사되는 것이다.
    // 따라서 주소가 바뀐다.
    // vector size = 5
    // capacity = 8


// int main() {
//     std::vector<int> vec {1, 2, 3};
//     // vector의 push_back의 시간복잡도는 대체로 1이다.
//     vec.push_back(4);
//     // 왜 대체로냐하면, capacity가 충분할 때 push_back은 1이지만
//     // capacity를 초과할 경우 새로운 배열을 만들고 복사 재할당을 해야하기 때문이다.

//     // vector의 pop_back의 시간복잡도는 항상 1이다.
//     vec.pop_back();

//     // iterator를 이용하여 맨 뒤가 아닌 곳에 넣어주는 경우, 시간복잡도는 n이다.
//     vec.insert(vec.begin(), 10);
//     // 이러한 비효율성 때문에 vector는 push_front를 지원하지 않는다.
// }


// deque

int main() {
    std::vector<int> v;
    // 재할당이 일어나지 않도록 capacity 확보
    v.reserve(100);
    // v에서 1이 있는 곳의 주소값을 출력해보자
    v.push_back(1);
    cout << &v[0] << endl; // 0x139e069e4
    // [1, ...]

    // v의 앞에 10을 넣어주었다.
    v.insert(v.begin(), 10);
    // 다시 v에서 1이 있는 곳의 주소를 출력해보자
    // 정확히 4바이트만큼 뒤로 밀려난 것을 볼 수 있다.
    cout << &v[1] << endl; // 0x139e069e4
    // [10, 1, ...]


    // 위 vector에서의 과정을 deque에서도 똑같이 진행해보자
    std::deque<int> nums;
    nums.push_back(1);
    cout << &nums[0] << endl; // 0x13a009800
    
    // deque는 push_front를 지원하기 때문에 intert를 사용할 필요가 없다.
    nums.push_front(10);
    cout << &nums[1] << endl; // 0x13a009800
    // deque는 push_front로 앞에 넣었는데도 1이 있는 곳의 주소값이 같다. 왜그럴까?
    // deque의 구성은, 내부적으로 배열을 여러개 가지고 있기 때문이다.

    // deque
    // [0, 1, 2, 3, 4, 5, 6, ?] -> 처음 deque의 상태라고 가정하자.
    // 위 상태에서 앞에 넣으려면 원래는 싹 다 뒤로 밀어줘야한다. 이는 오버헤드가 크다.

    // [?, ?, ?, 10] [0, 1, 2, 3, 4, 5, 6, ?] -> 그래서 deque는 push_front를 이런 식으로 구현한다.
    // 앞에 아예 또 다른 배열을 넣어주는 것이다.

    // deque는 대략 이런 느낌으로 구현되어있기 때문에 앞, 뒤로 push를 하는 것의 시간복잡도가 1이다.
    // 다만 deque도 아예 중간에 삽입을 하게 되는 경우에는 시간복잡도가 높아지기 때문에 deque가 안좋은 선택일 수도 있다.
}