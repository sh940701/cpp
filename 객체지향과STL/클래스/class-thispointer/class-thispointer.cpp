#include <iostream>
#include <string>

using namespace std;

// class Person{
// private:
//     float _weight;
//     float _height;

// public:
//     Person(float weight, float height) 
//     : _weight(weight), _height(height){

//     }
    
//     // this를 한번 사용해보자
//     void loseWeight(float weight){
//         // this 는 이 객체를 가리키는 포인터, 포인터는 주소값
//         // 주소값을 값으로 바꿔서 접근하기 위해 역참조 연산이 가능하다.
//         // this->_weight == _weight
//         this->_weight -= weight;
//         if (this->_weight < 0) {
//             this->_weight = 0;
//         }
//     }

//     void skipMeals(int times) {
//         this->loseWeight(times * 0.5);
//     }
// };

// class Person{
// private:
//     float weight;
//     float height;
//     const string name;

// public:
//     // string을 받을 때 const와 레퍼런스 기호를 사용해주는 이유는 문자열을 그대로 받기 때문이다.
//     // 복사된 값이 아니라 원본 값을 가져올 것이기 때문에 레퍼런스 기호를 표시해주며
//     // 만약 받아온 레퍼런스값에 대해 변경을 하면 "abc" = "def"와 같이 리터럴 데이터에 대한 변경
//     // 을 의미하기 때문에 불가하다. 그래서 앞에 const를 붙여주는 것이다.
//     Person(float weight, float height, const string& name) 
//     : weight(weight), height(height), name(name){

//     }
//     // 두 개의 person 객체가 각각의 bmi지수를 비교한다고 하자.
//     float getBMI(){
//         return weight / (height * 100 * height * 100);
//     }
//     // BMI 지수가 낮은 객체가 winner이다.
//     Person& complete(Person& person) {
//         // this와 person이 BMI수치를 두고 경쟁하는 것이다.
//         if (this->getBMI() < person.getBMI()) {
//             // 밖에 나가서 조작하기 쉽게 역참조(레퍼런스)값으로 return 해준다.
//             return *this;
//         } else {
//             // person은 레퍼런스 값으로 받았기 때문에 그대로 return 해준다.
//             return person;
//         }
//     }

//     // 이기면 세레머니 하는 함수
//     void doCeremony() {
//         cout << name << " win!!" << endl;
//     }
    
// };

// int main() {
//     Person person(67.3, 172.3, "david");
//     Person person1(58.2, 167.8, "daniel");

//     // 아래와 같이 한 객체에 대하여 complete함수를 실행하면 객체를 반환하고
//     // 이에 대해 doCeremony 함수를 실행한다. this를 사용하여 본인인 객체도 리턴할 수 있다.
//     person.complete(person1).doCeremony();
// }

// 블록체인 예시
// 트랜잭션을 만든다.
struct Transaction {
    const int txId;
    const int fromId;
    const int toId;
    const int value;
    
    class Builder {
    private:
        int _fromId;
        int _toId;
        int _value;

    public:
        Transaction build() {
            int txId = _fromId ^ _toId ^ _value;
            return Transaction{txId, _fromId, _toId, _value};
        }
        
        Builder& setFromId(int fromId){
            _fromId = fromId;
            return *this;
        }

        Builder& setToId(int toId){
            _toId = toId;
            return *this;
        }

        Builder& setValue(int value){
            _value = value;
            return *this;
        }
    };
};

int main() {
    Transaction tx = Transaction::Builder()
    .setFromId(1234)
    .setToId(4321)
    .setValue(5678)
    .build();
}