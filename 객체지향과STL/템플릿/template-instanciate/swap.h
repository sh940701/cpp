// swap 함수 header 파일

// 아래는 템플릿 함수의 원형이다.(proto type)
// 템플릿 함수의 원형은 일반 함수와 같되 template 키워드로부터
// 함수의 선언부 전체를 밝히고 본체는 생략하며 끝에 세미콜론을 붙인다.
template<typename T>
void swap(T& x, T& y);

// template 함수는 header 파일에 선언과 구체화를 모두 넣어준다.
// source 파일에 있는 녀석은 애초에 템플릿 구현만 있으면, 컴파일 자체가 안되는 것이다.
// 그러므롤 아예 이 녀석을 헤더에 넣고 실행 파일에서 include하여
// 사용할 때 바로 암시적 구체화를 해주는 것이 효율적이다.
template<typename T>
void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}