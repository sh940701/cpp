#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    // boolean으로 이루어진 원소가 31개인 배열
    // const int arraySize = 31;

    // bool attendanceBook[arraySize];

    // int nums[3];

    // nums[0] = 10;
    // nums[1] = 11;
    // nums[2] = 12;

    // cout << nums[0] << endl;
    // cout << nums[1] << endl;
    // cout << nums[2] << endl;

    // int nums[3] = {1, 2, 3};

    // cout << nums[0] << endl;
    // cout << nums[0] << endl;
    // cout << nums[0] << endl;

    // cout << sizeof(nums) << endl;

    // 반복문을 사용해서 배열 채워보기
    // int nums[2] = {1, };
    // int arrSize = size(nums);
    // // sizeof(nums) / sizeof(int);

    // for (int i = 0; i < arrSize; ++i){
    //     cout << nums[i] << endl;
    // }

    // cout << arrSize << endl;

    // int nums[3];
    // int arrSize = size(nums);
    // cout << arrSize << endl;

    // 배열 복사하기
    // int nums0[3] = {0, 1, 2};
    // int nums1[3];

    // nums1 = nums0;

    // cout << nums0 << endl;
    // cout << nums1 << endl;

    // for (int i = 0; i < 3; ++i) {
    //     nums1[i] = nums0[i];
    //     cout << nums1[i] << endl;
    // }
    // cout << nums1 << endl;
    // cout << nums0 << endl;

    // memcpy사용하기
    // memcpy (void* dest, const void* source, size_t num)
    /*
    인자값
    dest : 데이터가 복사될 곳을 가리키는 포인터
    source : 복사할 데이터가 있는 위치를 가리키는 포인터
    num : 복사할 바이트 수

    리턴값
    dest가 리턴됨
    */

    // memcpy(nums1, nums0, sizeof(nums0));

    // for (int i = 0; i < 3; ++i) {
    //     cout << nums1[i] << endl;
    // }

    // std copy 사용해보기
    // copy(nums0, nums0 + 3, nums1);

    // for (int i = 0; i < 3; ++i) {
    //     cout << nums1[i] << endl;
    // }

    // 배열에서 XOR연산을 이용하여 홀수(1, 3, 5 ...) 번만 등장하는 원소 골라내기
    // int nums[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    // int result = 0;
    // for (int i = 0; i < sizeof(nums) / sizeof(int); ++i){
    //     result ^= nums[i];
    //     cout << result << endl;
    // }
    // cout << result << endl;

    // bubble sort

    int nums[] = {5, 4, 3, 1, 7, 4, 3, 6, 5, 1, 2};

    // for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
    //     for (int j = 0; j < sizeof(nums) / sizeof(int); ++j){
    //         if (nums[j] > nums[j+1]) {
    //             int temp = nums[j + 1];
    //             nums[j + 1] = nums[j];
    //             nums[j] = temp;
    //         }
    //     }
    // }

    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        for (int j = 0; j < sizeof(nums) / sizeof(int) - i -1; ++j){
            if (nums[j] > nums[j+1]) {
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        cout << nums[i] << endl;
    }
    
}

// bool, bool, bool .. bool(31개)