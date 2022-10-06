#include <iostream>

using namespace std;

int main(){
    
    // idType이 0일 때는 idInteger, 이외에는 idChars를 반환하는 프로그램 예시
    // 두 가지 경우의 수를 갖기 위해서는 아래와 같이 struct에 미리 선언을 해놔야한다.
    // 그러나 두 개 중 하나만 받을 것인데 두 개를 모두 미리 선언해놓는건 메모리 손해이다.
    struct Product0{
        int idType;
        int idInteger;
        char idChars[10];
    };

    // 이러한 경우에 union을 사용하여 경우의 수를 나눠주면, 두 경우의 수를 struct에
    // 모두 저장하지 않고도 handling을 할 수 있으며, 메모리또한 절약할 수 있다.
    union ID {
        int integer;
        char chars[10];
    };

    struct Product1 {
        int idType;
        ID id;
    };

    Product0 product = {0, 12};
    if (product.idType == 0) {
        cout << product.idInteger << endl;
    } else {
        cout << product.idChars << endl;
    }

    Product1 product1 = {1, {.chars = "abc"}};

    if (product1.idType == 0) {
        cout << product1.id.integer << endl;
    } else {
        cout << product1.id.chars << endl;
    }

    cout << sizeof(Product0) << endl; // 20
    cout << sizeof(Product1) << endl; // 16
}