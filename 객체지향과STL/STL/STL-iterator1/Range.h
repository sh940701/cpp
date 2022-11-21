#pragma once

class Range {
public:
    class Iterator {
    private:
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
    Range(unsigned begin, unsigned end);
    Range(unsigned end);
    Iterator begin() const;
    Iterator end() const;
};