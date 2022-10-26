#include <iostream>

using namespace std;

int main() {
    // 다차원 배열
    // int matrix[3][4] = {
    //     {1, 2, 3, 4},
    //     {4, 5, 6, 5},
    //     {7, 8, 9, 12}
    // };

    // cout << matrix[0][0] << endl;

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 4; ++j) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << sizeof(matrix) << endl;

    // 행렬의 곱셈
    // int matrix0[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // int matrix1[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // int matrix2[3][3] = {}; // 정답을 넣을 배열 내 원소들을 모두 0으로 초기화

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j){
    //         for (int k = 0; k < 3; ++k){
    //             matrix2[i][j] += matrix0[i][k] * matrix1[k][j];
    //         }
    //     }
    // }

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         cout << matrix2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << sizeof(matrix2) << endl;

    // 다차원 배열 복사하기
    // int matrix0[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // int matrix1[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // int matrix2[3][3] = {};

    // memcpy(matrix2, matrix0, sizeof(matrix0));

    // std::copy로 복사하기
    // copy(&matrix0[0][0], &matrix0[0][0] + 3 * 3, &matrix2[0][0]);

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         cout << matrix2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << matrix0[1][1] << endl;

    // 캐시와 다차원배열의 관계
    int matrix[20240][20240] = {};
    
    int sum = 0;
    for (int i = 0; i < 20240; ++i) {
        for (int j = 0; j < 20240; ++j) {
            sum += matrix[i][j];
        }
    }
    cout << sizeof(matrix) << endl;
    cout << sum << endl;

    // 위와같이 큰 배열을 선언하고, 연산을 할 때, sum += matrix[i][j]로 선언하면 금방 답이 나온다.
    // 그러나 sum += matrix[j][i]로 선언하면 훨씬 더 오랜 시간이 걸리게 된다.
    // 이는 캐시의 지역성과 관련이 있는데, 다차원 배열을 선언하면 내부 값들이 메모리에 [0][0]부터 sequensial하게 나열이 된다.
    // 캐시는 한 번 결과값을 가져올 때, 그 주변의 값을 함께 가져오고, 이후 연산에 최대한 그 값을 활용하게 된다.
    // matrix[i][j]에 대한 연산을 실행하면, matrix[i]행의 값들을 가져오고, 그에따라 j를 증가시키면
    // 캐시에 있는 값을 활용해 [i][0]부터 sequensial하게 있는 값들에 대한 연산을 수행해주면 되기 때문에
    // 캐시히트가 가능하고, 빠른 연산이 가능하다. 그런데 matrix[j][i]에 대한 연산을 실행하게 되면
    // matrix[j]와 sequensial한 값들을 가져오는데, i가 증가하면 행 자체가 바뀌기 때문에
    // 캐시미스가 생기고 계속해서 메모리에서 캐시로 값을 가져오는 overhead가 발생하게 되어 연산이 느리게 된다.
    // 위 연산에서 [i][j] -> [i][j+1]은 4byte거리에 있지만, [j][i] -> [j][i+1]은 4 * 20240 byte 거리에 있는 것이다.
}