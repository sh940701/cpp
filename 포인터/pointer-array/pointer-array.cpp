#include <iostream>

using namespace std;

int main() {
    // 포인터와 배열
    // int nums[] = {1, 2, 3};

    // cout << nums << endl;
    // int* pNums = nums;
    // cout << pNums << endl;

    // 포인터로 변하면서 생기는 특성들
    // cout << sizeof(nums) << endl; // 4byte * 3 = 12
    // cout << sizeof(pNums) << endl; // nums의 크기가 아니라 pNums라는 변수의 크기 -> 8

    // cout << nums << endl; // 0x16f616f48
    // cout << &nums << endl; // 0x16f616f48
    // cout << &nums[0] << endl; // 0x16f616f48

    // int* pNums = nums; // 정상
    // int* pNums = &nums; // error
    // int* pNums = &nums[0]; // 정상

    // typeid를 출력해보자.
    // cout << typeid(nums).name() << endl; // A3_i -> Array(길이 3)_int type
    // cout << typeid(&nums).name() << endl; // PA3_i -> Array(길이 3)_int type의 Pointer
    // cout << typeid(&nums[0]).name() << endl; // Pi -> int type의 Pointer

    // cout << nums << endl;
    // cout << &nums[0] << endl;

    // int nums0[] = {1, 2, 3};
    // nums = nums0

    int nums[] = {1, 2, 3};
    int* pNums = nums;

    // cout << pNums[0] << endl;
    // cout << pNums[1] << endl;
    // cout << pNums[2] << endl;

    // cout << pNums << endl; // 0x16fc26f48
    // cout << pNums + 1 << endl; // 0x16fc26f4c
    // cout << pNums + 2 << endl; // 0x16fc26f50

    // cout << *pNums << endl;
    // cout << *(pNums + 1) << endl;
    // cout << *(pNums + 2) << endl;

    // cout << nums << endl; // 0x16d9fef48
    // cout << nums + 1 << endl; // 0x16d9fef4c
    // cout << nums + 2 << endl; // 0x16d9fef50

    // cout << *nums << endl; // 1
    // cout << *(nums + 1) << endl; // 2
    // cout << *(nums + 2) << endl; // 3

    // cout << *&nums[0] << endl; // 1
    // cout << *(&nums[0] + 1) << endl; // 2
    // cout << *(&nums[0] + 2) << endl; // 3

    cout << *pNums << endl; // nums의 첫번째 원소의 메모리 주소에 대한 역참조 -> 1
    pNums++; // 메모리 주소에 대해서 +1 연산 수행
    cout << *pNums << endl; // 포인터의 type이 integer이기 때문에 4byte만큼 증가됨 -> 2

    // nums++; // 배열은 해당 연산이 불가능
}