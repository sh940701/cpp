nt prevValue = 0;
        int currValue = 1;
        do
        {
            int nextValue = prevValue + currValue;
            prevValue = currValue;
            currValue = nextValue;
        } while (--num -1);
        c