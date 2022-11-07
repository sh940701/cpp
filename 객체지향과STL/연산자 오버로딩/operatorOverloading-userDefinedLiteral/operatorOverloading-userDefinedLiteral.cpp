#include <iostream>
#include <chrono> // 시간과 관련된 표준 라이브러리

using namespace std;

// int main() {
//     // 아래와 같이 접미사를 붙여 형을 정해주는것
//     123.0f;
//     123u;

//     // 시간 리터럴 표준 라이브러리 chrono
//     // 표준 라이브러리에서도 operator overloading을 통해 사용자 정의 리터럴화 하여 사용함
//     chrono::minutes m = 24h + 5min;

//     cout << m.count() << endl; // 1445
// }

// 길이를 나타내는 사용자 리터럴을 만들어보자

class Length {
private:
    // 멤버변수를 const로 선언하여 변하지 않게 만들어준다.
    const long double _value;
    Length(long double value) : _value(value) {
    }

    // 사용자 정의 리터럴 friend로 선언

    // 사용자 정의 리터럴에 넘어갈 수 있는 type이 정해져있다. -> int는 안됨
    // 리터럴에는 마이너스가 없다 -1은 1에 -연산자가 붙은것
    friend Length operator"" _m(unsigned long long value);    
    friend Length operator"" _m(long double value);

    friend Length operator"" _km(unsigned long long value);    
    friend Length operator"" _km(long double value);

    friend Length operator"" _cm(unsigned long long value);    
    friend Length operator"" _cm(long double value);

    friend Length operator"" _mm(unsigned long long value);    
    friend Length operator"" _mm(long double value);

// ======================================================

public:

    // 결과값 리턴 함수
    // 미터 단위로 리턴 함수
    long double m() { return _value; }

    // 킬로미터 단위로 리턴 함수
    long double km() { return _value * 0.001; }

    // 센티미터 단위로 리턴 함수
    long double cm() { return _value * 100; }

    // 밀리미터 단위로 리턴 함수
    long double mm() { return _value * 1000; }

// ======================================================

    // 연산자 오버로딩

    // - 연산자 오버로딩
    Length operator -() const {
        return Length(-_value);
    }

    // + 연산자 오버로딩
    Length operator +() const {
        return Length(_value);
    }

    // 우항을 받아서 파라미터에 넣어준다.
    // Length끼리 + 연산자 오버로딩
    Length operator + (const Length& length) const {
        return Length(_value + length._value);
    }

    // Length끼리 - 연산자 오버로딩
    Length operator - (const Length& length) const {
        return Length(_value - length._value);
    }

};

// ======================================================

// 사용자 정의 리터럴 생성

// -> _m를 입력할 때 정수를 반환하므로, m가 현재 기본값이라고 할 수 있다.
// 정수형 사용자 정의 리터럴
Length operator"" _m(unsigned long long value) {
    return Length(value);
    }

// 실수형 사용자 정의 리터럴
Length operator"" _m(long double value) {
    return Length(value);
}

// 정수형 _km 사용자 정의 리터럴
Length operator"" _km(unsigned long long value) {
    return Length(1000 * value);
    }

// 실수형 _km 사용자 정의 리터럴
Length operator"" _km(long double value) {
    return Length(1000 * value);
}

// 정수형 _cm 사용자 정의 리터럴
Length operator"" _cm(unsigned long long value) {
    return Length(0.01 * value);
    }

// 실수형 _cm 사용자 정의 리터럴
Length operator"" _cm(long double value) {
    return Length(0.01 * value);
}

// 정수형 _mm 사용자 정의 리터럴
Length operator"" _mm(unsigned long long value) {
    return Length(0.001 * value);
    }

// 실수형 _mm 사용자 정의 리터럴
Length operator"" _mm(long double value) {
    return Length(0.001 * value);
}

// ======================================================

int main() {
    1_m; // 정수형 리터럴
    1.0_m; // 실수형 리터럴
    -1.0_m; // overloading 된 - 연산자 + 실수형 리터럴
    +1.0_m; // overloading 된 + 연산자 + 실수형 리터럴
    -1.0_km; // overloading 된 - 연산자 + 실수형 리터럴
    +1.0_km; // overloading 된 - 연산자 + 실수형 리터럴
    1.0_km + 30_m; // Length + Length overloading
    1.0_km - 30_m; // Length - Length overloading

    Length len = 1_m + 1_km;
    cout << len.m() << endl; // 1001 -> m단위
    cout << len.km() << endl; // 1.001 -> km단위
    
    // 변수에 담지 않고, 아래와 같이 호출할 수도 있다.
    cout << (1_m + 1_km).m() << endl; // 1001
    cout << (1_m + 1_km).km() << endl; // 1.001

    // 여러 단위를 더해보자
    Length len2 = 1_m + 1_km + 1_cm + 1_mm;
    // 정밀도를 높여서 출력
    cout.precision(16);
    cout << len2.m() << endl;
    cout << len2.km() << endl;
    cout << len2.cm() << endl;
    cout << len2.mm() << endl;
    // cout << (1_m + 1_km + 1_cm + 1_mm).cm() << endl;
    // cout << (1_m + 1_km + 1_cm + 1_mm).mm() << endl;

}