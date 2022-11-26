= 1) {
        return num;
    }
    long long prev = 0;
    long long curr = 1;

    for (int i = 2; i <= num; ++i) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return cu