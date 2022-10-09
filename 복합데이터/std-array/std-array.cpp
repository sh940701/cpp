#include <iostream>
#include <array>

using namespace std;

int main() {
    // 선언하는 방법 : array<자료형, 길이> 변수명;
    // array<int, 5> arr{1, 2, 3, 4, 5};

    // cout << arr[-2] << endl;
    // cout << arr[10] << endl;

    // cout << arr.at(-2) << endl; // error
    // cout << arr.at(10) << endl; // error

    // int arr0[] = {1, 2, 3};
    // cout << sizeof(arr0) / sizeof(int) << endl;

    // cout << arr.size() << endl;

    // cout << arr.front() << endl;
    // cout << arr[0] << endl;

    // cout << arr.back() << endl;
    // cout << arr[arr.size() - 1] << endl;

    // 배열간 스왑
    // array<int, 5> arr0{1, 2, 3, 4, 5};
    // array<int, 5> arr1{5, 4, 3, 2, 1};

    // arr0.swap(arr1);

    // for (int i = 0; i < arr0.size(); ++i){
    //     cout << arr0[i];
    // } 
    // cout << endl;
    // for (int i = 0; i < arr1.size(); ++i){
    //     cout << arr1[i];
    // } 
    // cout << endl;

    // if (arr0 == arr1) {
    //     cout << "==" << endl;
    // }
    // if (arr0 > arr1)  {
    //     cout << ">" << endl;
    // }
    // if (arr0 < arr1)  {
    //     cout << "<" << endl;
    // }

    // 내부 배열 data에 접근
    // cout << arr0 << endl; // error
    // cout << arr0.data() << endl;
    // cout << arr0[0] << endl;
    // cout << arr0.data()[0] << endl;

    array<int, 5> arr0{1, 2, 3, 4, 5};
    array<int, 5> arr1{5, 4, 3, 2, 1};

    arr0 = arr1;

    cout << (arr0 == arr1) << endl;
    cout << arr0.data() << endl;
    cout << arr1.data() << endl;
    cout << (arr0.data() == arr1.data()) << endl;
}