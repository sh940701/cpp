#include <iostream>
#include "Range.h"

using Iterator = Range::Iterator;

Range::Range(unsigned begin, unsigned end)
    : _begin(begin), _end(end) {}

Range::Range(unsigned end)
    // : _begin(0), _end(end) {}
    : Range(0, end) {}

Iterator Range::begin() const {
    return Iterator(_begin);
} 

Iterator Range::end() const {
    return Iterator(_end);
} 

Iterator::Iterator(unsigned num) 
    : _num(num) {}

Iterator& Range::Iterator::operator++() {
    ++_num;
    return *this;
}

bool Iterator::operator==(const Iterator& other) const {
    return other._num == _num;
}

bool Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}

unsigned Iterator::operator*() const {
    return _num;
};