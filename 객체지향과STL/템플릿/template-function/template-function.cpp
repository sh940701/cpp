#include <iostream>

using std::cout;
using std::endl;

// <>에 들어가는 녀석은 "template parameter"라고 한다.
// 아래에서 typename T라는것은, 함수 템플릿 내에서 T를 type으로 사용하겠다는 것이다.
// template<typename T> // class T 로 써도 된다.
// void swap(T& x, T& y){
//     T temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int x = 10, y = 20;
//     // <int>는, 템플릿 파라미터로, 템플릿에서 사용할 파라미터이다.
//     swap<int>(x, y);
//     // <int>를 입력해주지 않으면, 컴파일을 할 때 swap 함수가 있는지 먼저 찾는다.
//     // 만약 없으면 template함수를 검색하게 된다. 암시적으로 인자값의 타입을 추론해주기도 하지만
//     // 특별한 이유가 없으면 <type>을 명시해주는 것이 좋다.
//     cout << x << endl; // 20
//     cout << y << endl; // 10
// }


// template<int N>
// int num() {
//     return N;
// }

// int main() {
//     cout << num<5>() << endl;
// }




// template 함수를 이용하여, 배열의 길이를 리턴해보자.
// 이 때 배열을 pointer로 받으면 길이를 잃게 되는 Decay현상이 발생하게 된다.
// 이를 방지하기 위해 레퍼런스 형으로 받아준다.
// void func(int (&nums)[3]) {}

// int main() {
//     int nums[] = {1, 2, 3};
//     func(nums);
// }

// 템플릿 추가
// template<int N>
// // 함수 인자값으로 "int 요소를 갖는 길이 3의 배열"이 넘어왔다.
// // 그런데 여기서 int, 배열(&nums)은 명시되어있기 때문에 N == 3 이라는 것을 컴파일 타임에
// // 추론할 수 있다. 그리고 이는 바로 위에 있는 template parameter <int N>에 들어가게 된다.
// int func(int (&nums)[N]) {
//     return N;
// }

// int main() {
//     int nums[] = {1, 2, 3};
//     // nums의 타입은 "int 요소를 갖는 길이 3의 배열" 이다.
//     cout << func(nums) << endl; // 3 -> 함수 실행의 결과값으로 길이가 반환되었다.
// }


// 함수 파라미터가 "'어떤' 요소를 갖는 '길이 몇'의 '배열'"임을 이미 컴파일타임에 알고 있기 때문에
// 어떤 요소를 갖는지에 대한 타입 또한 template화 해줄 수 있다.
template<typename T, int N>
T func(T (&nums)[N]) {
    return N;
}

int main() {
    double nums[100] = {1, 2, 3}; // 100 -> int 가 아닌 다른 타입의 배열을 넣어도 잘 실행이 된다.
    cout << func(nums) << endl;
}