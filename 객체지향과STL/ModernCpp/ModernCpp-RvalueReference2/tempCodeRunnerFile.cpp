void foo(int&) {
    std::cout << "int&" << std::endl;
}

void foo(int&&) {
    std::cout << "int&&" << std::endl;
}

int main() {
    foo(1); // int&&

    int num = 10;
    foo(num + 10); // int&&

    foo(num); // int&
    // std::move는 LValue를 강제로 move가 가능하도록 만들어주는 녀석
    foo(std::move(num)); // int&&
    // static_cast로 RValue타입으로 변경해서 넘겨주면, RValue로 속는다.
    foo(static_cast<int&&>(num)); // int&&

    // 어라 근데 이녀석은 안 속는다. 왜그럴까?
    // 아아 int&& num0은 RValue를 묶은 결과로, LValue다. 그래서 int&가 출력된것이다.
    // 사실상, 이름을 가지게 되는 순간! LValue인 것이다.
    int&& num0 = static_cast<int&&>(num); // xvalue
    foo(num0); // int&

    // std::move()는 내부적으로 static_cast를 사용하여 RValue Ref 타입으로 묶어서 리턴하는 녀석이다.
    // move는 이동시킨다기보다. 이동할 수 있도록 casting을 해주는 녀석
}