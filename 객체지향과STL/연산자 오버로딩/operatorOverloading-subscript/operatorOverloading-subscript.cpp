#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// class Vector {
// private:
//     float x, y, z;

// public:
//     Vector(int x, int y, int z) 
//         : x(x), y(y), z(z){
//         }

//     float& operator[](int index) {
//         if (index < 1) {
//             return x;
//         } else if (index == 1) {
//             return y;
//         } else {
//             return z;
//         }
//     }
// };

// int main() {
//     // 하고싶은 것 -> v[0], [1], [2] 를 출력해보자
//     Vector v(1, 2, 3);
//     cout << v[-1] << endl; // 1
//     cout << v[0] << endl; // 1
//     cout << v[1] << endl; // 2
//     cout << v[2] << endl; // 3
//     cout << v[3] << endl; // 3

//     // 역으로 Vector 내에 data를 넣어보자 -> 위에서 float이 아니라 float& 을 리턴해주면 된다.
//     v[1] = 1000;
//     cout << v[1] << endl; // 1000
// }

// class Vector {
// private:
//     float x, y, z;

// public:
//     Vector(int x, int y, int z) 
//         : x(x), y(y), z(z){
//         }

//     // 변경 가능 함수
//     float& operator[](int index) {
//         if (index < 1) {
//             return x;
//         } else if (index == 1) {
//             return y;
//         } else {
//             return z;
//         }
//     }

//     // 변경 불가 함수
//     // 만약 변경 불가일 때 큰 자료형을 반환하게 되면 const float& 으로 리턴해주자
//     // 변경이 불가한 reference값을 반환하여 변경불가, 메모리 절약 의 두가지가 이루어진다.
//     float operator[](int index) const {
//         cout << &x << endl;
//         cout << &y << endl;
//         cout << &z << endl;
//         cout << this << endl;
//         if (index < 1) {
//             return x;
//         } else if (index == 1) {
//             return y;
//         } else {
//             return z;
//         }
//     }
// };

// int main() {
//     // 만약 Vector가 const로 선언되어 있다면, 위 함수에서 const this로 받아줘야 하며 또한
//     // float&을 리턴이 불가능하다. 그 이유는 const 로 선언되어 들어간 값인데 float&을 이후 외부에서
//     // 바꿀 수도 있기 때문이다.

//     // 따라서 const로 Vector가 선언될 수도 있기 때문에, 첨자연산자를 오버로딩 할 때에는
//     // 변경 가능 함수와 변경 불가능 함수 두 개를 만들어줘야 한다.
//     const Vector v(1, 2, 3);
//     Vector v1(1, 2, 3);
//     v[0];
//     // v[1] = 1000; // error
//     v1[1] = 1000; // 정상
// }


// class String {
// private:
//     char* _chars;
// public:
//     // 문자 배열을 함수로 가져올 때 const를 선언해줘야 warning을 방지할 수 있다.
//     String(const char* chars) 
//         // 컴파일타임에 길이를 알 수 없고, 실행중에 할당되는 녀석이기 때문에 동적할당 배열로 만들어준다.
//         : _chars(new char[strlen(chars) + 1]){
//             strcpy(_chars, chars);
//         }
//     // 진짜 이상한 것을 발견했다. 이전 Vector예시에서는 함수 뒤에 const를 선언해주면 const *this로 받아서
//     // 아예 레퍼런스를 반환하지도 못하게 했었는데 여기서는 const를 선언해줬는데도 안에서 변경이 가능하고
//     // 레퍼런스도 반환할 수가 있다.
//     // 그래서 나름의 차이점을 생각해봤는데, 이전 Vector에서는 요소들이 모두 주소값을 가지고 있는 변수였다.
//     // 그런데 이번 String은 받을 때 애초에 하나의 배열 안에 들어있는 literal 문자열들을 받아서
//     // 만들어주는 것이기 때문에 큰 주소값(String 객체의)만 바뀌지 않으면 내부적으로 값이 바뀌어도
//     // 상관이 없는 것이 아닐까? 라고 생각해본다.
//     // 아무래도 내 생각이 맞는 것 같다.

//     // 위 Vector에서 x, y, z, this 의 주소값을 찍어보면 this와 x의 주소값은 같고, 나머지 y z의 값은 다르다.
//     // 그런데 아래에서 _chars[1], [2], [3]의 주소값을 찍어보면 문자열만 출력된다. _chars 전체에 대한 주소값만 있다.
//     // 그리고 이는 *this의 주소값과 같은 값을 나타낸다.
//     // 내 생각에는 const로 객체를 선언하고, const *this로 받고 할 때, 내부 요소들이 각각의 주소값을 갖고있는
//     // 변수이면 이를 바꿀 수 없는 것 같고 그게 아니라면 큰 그림에서의 주소값만 const되는게 아닐까 싶다...
//     // 그 예로 밑에서 _chars = "qdj"; 를 직접 넣어줬더니 const 어쩌구 하면서 실행이 안된다... 너무어렵네염
//     // 배열을 동적으로 할당해준것과도 연관이 있는지 궁금하다...

//     // 만약 위에서 나열한 이유가 아니라면 동적으로 heap 영역에 자리한 데이터와 그렇지 않은 차이인걸까?

//     // const *this 인데 char&반환은 왜 될까
//     char& operator[](int index) const {
//         _chars[1] = 'q'; // 왜 될까
//         cout << "this: " << &(*this) << endl;
//         _chars = "qdj"; // error
//         // cout << &this << endl;
//         cout << &_chars << endl;
//         cout << _chars[1] << endl;
//         cout << _chars[2] << endl;
//         return _chars[index];
//     }

//     // 출력 연산자 << 오버로딩
//     friend ostream& operator<<(ostream& os, const String& s) {
//         return os << s._chars;
//     }
// };

// int main() {
//     // 하고싶은것 : String 클래스의 요소를 s[1], [2] 와 같이 출력하는 것
//     // 심지어 const String으로 선언해주었는데 왜 변경이 가능할까????
//     const String s("abc");
//     cout << s[1] << endl; // b
//     s[1] = 'j'; // 왜 되는거얌
//     cout << s[1] << endl; // j
//     cout << s << endl;
// }

// 첨자 연산을 사용하여 hashTable 만들어보기

using Key = string;
using Value = string;
using KeyValue = pair<Key, Value>;

class Bucket {
private:
    vector<KeyValue> _items;
    // 하나의 버킷에 아이템을 넣는 과정
    // make_pair함수는 두 개의 인자를 받아 앞의 것을 key, 뒤의 것을 value로 저장해준다.

public:
    // 값을 가지고 나오는 get이라는 함수를 만들자
    Value& get(const Key& key) {
        // bucket 안에서 key가 입력받은 "key"와 같은 녀석을 찾아 value를 return해주자.
        // 충돌이 일어날 것 까지 감안해서, 버킷 내부 여러개의 KeyValue중 알맞은 것을 찾아주는 것이다.
        for (KeyValue& keyValue : _items) {
            // pair는 first와 second를 주어, key와 value를 구분하게 한다.
            if (keyValue.first == key) { // keyValue의 first(key)가 입력받은 key와 같으면
                return keyValue.second; // value를 반환하라. -> 값이 있다는 의미
            }
        }
        // 없으면 make_pair 함수를 이용해 key : value pair를 만들어 줄 것이다.
        _items.push_back(make_pair(key, Value()));
        // 없어서 만들어주었으니 vector의 마지막에 들어가있겠지? 그 마지막의 second(value)를 return해준다.
        // Value()는 빈 값이다. 그러므로 해당 bucket의 마지막 pair는 지금 {key : ""}로 되어있을 것이다.
        // return을 레퍼런스로 해 주면서 결과적으로 레퍼런스값이 return되고, 아래에서
        // HashTable["abc"] = "def"; 의 선언은 HashTable["abc"]의 주소값에 "def"라는 데이터를 넣는게 되는것이다.!!!
        return _items.back().second;
    }
};

class HashTable {
private:
    vector <Bucket> _buckets;
    // 입력값을 받아 hash화해주는 hash함수를 만들자.
    int hash(const Key& key) {
        int h = 0;
        // 각각의 아스키코드를 다 더해주는 방식으로 결과값을 만든다.
        for (char ch : key) {
            h += ch;
        }
        return h;
    }

// 해시테이블을 만들자
public:
    HashTable(int size = 100)
        : _buckets(size) // _buckets(vector <Bucket>(size)) -> 내부적으로 이렇게 만들어진다.
        {}
    
    Value& operator[](Key key) {
        // 나머지 연산을 사용해 key보다 작은 index의 버킷을 사용한다.
        int bucketIndex = hash(key) % _buckets.size();
        // bucketIndex를 사용하여 어떤 버킷으로 들어갈지 정한다.
        Bucket& bucket = this->_buckets[bucketIndex];
        // 들어간 버킷에서 value를 가지고 나오자
        return bucket.get(key);
    }
};

int main() {
    HashTable hashTable;

    hashTable["abc"] = "def";
    cout << hashTable["abc"] << endl; // def

    // get함수에서 찾았을 때도 pair second의 주소값을 리턴해준다.
    // 따라서 아래 함수에서 나온 주소값에 "123"을 다시 넣어주면
    // 내부적으로 "abc"라는 key값의 value는 "123"으로 변경된다.
    hashTable["abc"] = "123";
    cout << hashTable["abc"] << endl; // 123

    // 아래와같이 "cba"라는 key값에 "456"이라는 value를 넣는 가정을 해보자.
    // 사실 위에서 h값을 아스키코드로 정해줬기 때문에 "abc"와 "cba"의 h값은 같다.
    // 따라서 "abc"와 "cba"는 같은 버킷 안에 저장된다.
    // 그런데 내부적으로 get함수에서 for문을 돌 때 "cba"라는 key값에 대한 value는 없기 때문에
    // get 함수는 {abc : 123} 다음 페어를 만들어 그 second의 주소값을 리턴한다.
    // 그리고 그 주소값에 "456"이라는 data가 들어가게 되는 것이다.
    hashTable["cba"] = "456";

    // 따라서 "abc"와 "cba"는 해시충돌로 같은 버킷에 들어가게 되지만, key값이 다르기 때문에
    // 서로 다른 pair로 저장되어, 아래 출력값으로는 456이 나오게 된다.
    cout << hashTable["cba"] << endl; // 456
}
