#include <iostream>

using namespace std;

// void count(int n) {
//     if (n < 0) return;
//     cout << n << endl;
//     count(n - 1);
// }

// int fac(int n) {
//     if (n == 1){
//         return 1;
//     }
//     int n0 = fac(n - 1);
//     return n * n0;
// }

// int fib(int n) {
//     if (n <= 1) return 1;
//     return (fib(n - 1) + fib(n - 2));
// }

// Node의 정의 안에 Node 타입의 변수를 선언할 수는 없기 때문에 포인터로 선언해준다.
struct Node {
    int value;
    Node* left;
    Node* right;
};

// Binary tree를 순회하는 재귀함수
// Node type의 pointer를 인자값으로 받는다.
void visit(Node* root) {
    // 존재하지 않는 값에 대한 포인터 리턴값은 0x0, 즉 nullptr이다.
    if (root == nullptr){
        return;
    }
    cout << root->value << endl;
    visit(root->left);
    visit(root->right);
}

int main() {
    Node node0 {0};
    Node node1 {1};
    Node node2 {2};
    Node node3 {3};
    Node node4 {4};
    Node node5 {5};
    Node node6 {6};
    Node node7 {7};
    Node node8 {8};
    Node node9 {9};

    // 위에서 Node.left, right를 포인터로 선언해줘야했기 때문에 주소값으로 넣어준다.
    node0.left = &node1;
    node1.left = &node2;
    node1.right = &node3;
    node3.right = &node4;
    node0.right = &node5;
    node5.left = &node6;
    node6.right = &node7;
    node5.right = &node8;
    node8.left = &node9;
    
    visit(&node0); // 0 1 2 3 4 5 6 7 8 9 -> 아래 트리에서
    // 0에서부터 좌측 출력 후 좌측이 없으면 우측으로 주욱 출력하며 내려간다.
}

// 아래와 같이 생긴 트리를 순회하는 함수

//                n0
//        n1                 n5
//     n2    n3         n6        n8
//             n4         n7    n9