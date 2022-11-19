#include <iostream>
#include <list>
#include <algorithm>
#include <forward_list>

using std::cout;
using std::endl;

// int main() {
//     std::list<int> list0{1, 2, 3};
//     // std::list에서 원하는 위치의 원소에 접근하고 싶으면 std::advance를 사용한다.
//     std::list<int>::iterator iter = list0.begin();
//     // 리스트 첫번째 원소의 iterator값을 준 후 2번 이동하게 한다.
//     // 실제로 아래에선 두 번의 연산을 거쳐 값을 iter에 담아준 것이다.
//     std::advance(iter, 2);

//     cout << *iter << endl; // 3
// }

// int main() {
//     std::list<int> list0{4, 1, 2, 3};
//     // list도 정렬함수를 지원해준다. -> 기존 algorithm의 sort는 느려서 지원을 안해주는것
//     // 그래서 list만의 방식으로 최적화된 sort 함수가 내장되어 있는 것이다.
//     list0.sort();

//     // list도 range_based_for 문을 지원해준다.
//     for (int num : list0) {
//         cout << num << endl;
//     }

//     // 어 그런데 algorithm에도 sort가 있었는데 list에도 있다. 왜일까?
//     std::sort(list0.begin(), list0.end()); // error
//     // std::sort는 random access iterator에만 사용할 수 있다.
//     // vec[0], vec[1]처럼 접근이 가능해야만 std::sort를 사용할 수 있다는 것이다.
//     // list의 iterator는 iterator + 1 와 같은 연산이 안된다. iterator++만 가능하다.
//     // std::sort는 위와같이 iterator + n 의 연산이 가능한 타입에만 사용할 수 있는 것이다.
// }


// bool condition(const int& value) {
//     cout << value << endl; // 4, 1, 3
//     return value % 2 == 0;
// }

// int main() {
//     std::list<int> list0{4, 1, 2, 3};
//     // 원소를 지우는 remove 함수
//     list0.remove(2);
//     for (int num : list0) {
//         cout << num << endl; // 4, 1, 3
//     }

//     cout << "=========" << endl;

//     // 함수를 인자로 받아 조건에 맞는 녀석을 지워주는 함수
//     // 모든 원소중 짝수인 녀석을 지워보자
//     list0.remove_if(condition);
//     for (int num : list0) {
//         cout << num << endl; // 1, 3
//     }

//     // list는 indexing을 못하는 대신, 전 영역 삽입/삭제 작업 수행속도가 빠르다.
//     // 전체 요소를 옮기고 복사하고 하는게 아니라, 그냥 next와 prev의 포인터를 연결해주기만 하면 되기 때문
//     // vector의 경우에는, 중간 하나를 지운다고 하면 이후 모든 원소들을 옮겨줘야 한다.
// }

// int main() {
//     std::list<int> list0{1, 1, 2, 3};
//     std::list<int> list1{1, 2, 3, 4};

//     // merge할 때의 주의점은, 두 list의 녀석들이 각각 정렬이 되어있어야 한다는 것이다.
//     list0.merge(list1);

//     for (int num : list0) {
//         cout << num << endl; // 1, 1, 1, 2, 2, 3, 3, 4 -> 정렬된 상태로 merge가 된다.
//     }

//     // 중복된 녀석들을 삭제해주는 unique
//     list0.unique();

//     for (int num : list0) {
//         cout << num << endl; // 1, 2, 3, 4
//     }
// }


// forward_list
// 메모리에 대한 제약사항이 큰 경우는 사용할 수 있지만, 보통은 사용하지 않는다.

int main() {
    std::forward_list<int> list0{1, 1, 2, 3};
}
// 이렇게 생겼다.
// Head -> Node0 -> Node1 -> Node2 -> Tail
// list에서 Node0 자리에 Node10이라는 요소를 추가하고 싶으면, insert를 통해
// Node10의 prev로 Head를 연결하고, Node10의 next로 Node0을 추가 이후
// Head의 next로 Node10을 넣고, Node0의 prev로 Node10을 넣으면 된다.

// 그런데 forward_list에서는 위와 같은 과정이 일어날 수 없다. 단방향 연결이기 때문이다.
// Node0자리에 Node10을 넣으려고 해도, Node0은 Head의 주소를 모른다. 그렇기 때문에 Head는
// 계속해서 Node0을 next로 가리키게 된다. 이 때문에 forward_list는 insert_after함수밖에 지원하지 않는다.
// 그래서 특정 자리에 요소를 추가하는 것이 아니라, 특정 자리 다음에 요소를 추가하는 작업만 가능한 것이다.
