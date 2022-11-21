#pragma once

class Range {
public:
    class Iterator {
    private:
        // 내부적으로 _num이라는 멤버변수를 갖고 있다.
        // 이 _num은 1씩 증가하며 *iter의 반환값이 된다.
        unsigned _num;
    public:
        Iterator(unsigned begin);
        // ++ 연산을 구현해줌
        Iterator& operator++();
        // ==, != 비교연산을 구현해줌
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        // *iter 할 때 역참조에 대한 연산도 구현해줌
        unsigned operator*() const;
    };
private:
    unsigned _begin;
    unsigned _end;
public:
    // Range 생성자
    Range(unsigned begin, unsigned end);
    // begin이 없을 때의 Range 생성자
    Range(unsigned end);
    // Range.begin() 함수 
    Iterator begin() const;
    // Range.end() 함수 
    Iterator end() const;
};