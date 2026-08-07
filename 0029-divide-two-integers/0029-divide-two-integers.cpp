class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) != (divisor < 0);

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long count = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            while (a >= temp + temp) {
                temp = temp + temp;
                multiple = multiple + multiple;
            }

            a = a - temp;
            count = count + multiple;
        }

        if (negative)
            count = -count;

        return (int)count;
    }
};