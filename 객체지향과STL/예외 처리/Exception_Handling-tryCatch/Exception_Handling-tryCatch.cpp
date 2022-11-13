#include <iostream>
#include <string>

using std::cout;
using std::endl;

// divide함수, v가 0일 때 에러처리를 해주고 싶음
// double divide(double d, double v) {
//     if (v == 0) {
//         // throw라는 키워드 사용
//         throw "Divided by zero"; // return 없이 여기서 함수가 끝남
//     }
//     return d / v;
// }

// // set_terminate에 들어갈 함수
// // terminate가 활성화 되면 아래 함수가 실행된다.
// void terminateFunc() {
//     cout << "Terminated" << endl;
//     exit(123); // abort를 실행하지 않고 함수만 실행 후 끝낼 수 있음
// }

// int main() {
//     // throw가 호출되면, 자동으로 std::terminate()를 호출한다.
//     // terminate를 호출하면 abort가 발생하는데, std::abort와 std::terminate의 차이는
//     // terminate는 설정해 줄 수 있다는 것이다.
//     std::set_terminate(terminateFunc);
//     // std::terminate();
//     cout << divide(10, 2) << endl; // 5
//     cout << divide(10, 0) << endl;
// }


// try & catch문을 통한 예외처리
// double divide(double d, double v) {
//     if (v == 0) {
//         // 여기서 던진 throw가 catch로 간다.
//         throw "Divided by zero"; 
//         throw 123; // anything else
//     }
//     return d / v;
// }

// int main() {
//     try {
//         cout << divide(10, 0) << endl;
//     // throw된 데이터(e)의 타입을 적어줘야 한다.
//     // 파라미터 타입이 throw된 데이터의 타입과 다르면 abort가 실행된다.
//     } catch(const char* e) {
//         cout << e << endl; // Divided by zero
//     // 만약 위 타입으로 잡히지 않는 모든 타입의 에러를 한번에 핸들링 해주고 싶다면 ...을 이용한다.
//     } catch(...) {
//         cout << "anything else" << endl;
//     }
// }

// class Parent {
// public:
//     virtual ~Parent(){}
// };

// class Child : public Parent {

// };

// double divide(double d, double v) {
//     if (v == 0) {
//         // 에러 발생시 자식 객체를 만들어 보냄
//         throw Child();
//     }
//     return d / v;
// }

// int main() {
//     try {
//         cout << divide(10, 0) << endl;
//     // 그럼 Child가 아래에 있으면 아래로 갈까?
//     // 그렇지 않다. try catch에서 체크를 할 때는 위에서부터 순서대로 보기 때문에 아래까지 안 온다.
//     // 따라서 좀 더 구체적인 녀석을 위에 명시해놓아야 한다.
//     } catch (Child&) {
//         cout << "child" << endl;
//     }
//     // throw를 받을 때, 부모로 받을 수 있다.
//      catch (Parent&) {
//         cout << "parent" << endl;
//     }
// }

// Stack UnWinding시 파괴되는 과정을 확인하기 위한 class
// class Test {
// private:
//     std::string _msg;
// public:
//     Test(std::string msg)
//         : _msg(msg) {}
//     // 파괴시 객체의 _msg 출력
//     ~Test() {
//         cout << _msg << endl;
//     }
// };

// double divide(double d, double v) {
//     Test t("divide test");
//     if (v == 0) {
//         throw "Divided by 0";
//     }
//     return d / v;
// }

// void func1() {
//     Test t("func1 test");
//     divide(10, 0);
//     cout << "func1" << endl;
// }

// void func0() {
//     Test t("func0 test");
//     func1();
//     cout << "func0" << endl;
// }

// int main() {
//     try {
//         func0();
//         cout << "main" << endl;
//     /*  divide test
//         func1 test
//         func0 test
//         Divided by 0 */
//         // 각 함수별 출력이 진행되지 않은 상태에서 객체가 모두 파괴된 것을 알 수 있다.
//     } catch (const char* e) {
//         cout << e << endl;
//     }
    
// }
// try에서 func0을 실행 -> func0에서 func1을 실행 -> func1에서 divide를 실행
// 정상대로라면, divide에서 throw를 하고 divide의 종료 이후 func1, func0 출력이 진행되어야 한다.
// 그런데 throw의 경우에는 divide뿐 아니라 try까지 연관되어있는 모든 함수의 stack을 파괴함으로써
// throw가 수행되는 순간, try에서 선언된 func0()자체가 종료되어 버려서 이후 진행이 되지 않는다.
// 심지어 try의 func0을 실행한 후에 바로 catch로 들어가버려, "main"도 출력이 되지 않는다.
// 이를 Stack Unwinding -> 스택 되감기 라고 한다.
// 또한 이 과정중에는, 되감기 과정에 있는 스택들에 선언이 되어있던 자동 지역 변수들이 전부 파괴된다.



// double divide(double d, double v) {
//     if (v == 0) {
//         throw "Divided by 0";
//     }
//     return d / v;
// }

// void func1() {
//     // func1에서 핸들링을 해주면, 이전처럼 상위 프레임까지 모두 파괴되지 않는다.
//     // throw는 catch를 만나서 handling될 때 까지 프레임을 파괴하며 올라간다.
//     // 그런데 여기서는 divide만 파괴했을 때 catch로 handling이 되었기때문에 여기서 끝난 것이다.
//     try {
//         divide(10, 0);
//     } catch(const char* e) {
//         cout << "func1 handled exception" << endl;
//         // 한 단계 상위 함수로 에러메시지를 또 전달하고 싶을 때는
//         // catch문 내부에서 다시 throw를 선언해주면 된다.
//         // 하위 throw도 catch를 만날때까지 스택 프레임을 파괴하기 때문에
//         // 이 경우에는 "func1 handled exception", "Divided by 0" 이 출력되고 "main"은 출력되지 않는다.
//         throw;
//     }
// }

// void func0() {
//     func1();
// }

// int main() try
// {
//     func0();
//     cout << "main" << endl;
// } catch (const char* e) {
//     cout << e << endl;
// }



// std::exception을 상속받아, 커스텀 예외처리 클래스를 만들어준다.
// 그리고 이를 이용해 좀 더 쉽고 일관적인 방식으로 에러를 표기할 수 있다.

// 아래는 내가 생각한 std::exception 사용 에러 해결방안이다.

// 1. 에러 발생시 CustomException 객체를 만드는데, 그 때 에러 발생장소를 명시한다.
// 2. 생성될 때 받아진 문자열을 객체에 저장해준다.
// 3. throw를 통해 객체 생성과 문자열이 저장되고, 이 객체를 catch에서 받는다.
// 4. 객체의 what 함수를 호출하면, 어디에서 생긴 에러인지 출력된다.

// 뭐 이렇게 사용하는게 아닐수도 있지만 그래도 뿌듯하다 생각해냈다는게

class CustomException : public std::exception {
private:
    const char* _s;
public:
    CustomException(const char* s)
        : _s(s) {}
    // 아래와 같이 exception의 what()함수를 오버라이딩 하여 원하는 text를 리턴하도록 설정해준다.
    virtual const char* what() const _NOEXCEPT override {
        return _s;
    }
};

double devide(int d, int v) {
    if (v == 0) {
        // 이런 느낌으로 상황별 에러발생 장소를 넣어 객체를 만들고 throw하면
        // catch에서 받아서 내부적으로 what을 호출한다.
        throw CustomException("divide func");
    }
    return d / v;
}

int main() {
    try
    {
        devide(10, 0);
    }
    catch(const std::exception& e)
    {
        // what이라는 녀석은 기선언된 에러 텍스트이다.
        // 예외처리 객체를 만들 때 넣어준 텍스트(에러장소)를 what()으로 출력한다.
        std::cerr << e.what() << " error" << '\n';
    }
}