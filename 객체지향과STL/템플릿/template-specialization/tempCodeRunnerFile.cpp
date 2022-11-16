emplate<>
void swap<Test>(Test& x, Test& y) { // 여기서 <Test>는 빼줘도 컴파일러가 암시적으로 추론한다.
    cout << "swap<Test>" << endl;
}