#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    int K[t];
    int lengths[t];

    // READ INPUT
    for (int i = 0; i < t; i++) {
        scanf("%d", &K[i]);

        int n = K[i];
        lengths[i] = 0;
        do {
            ++lengths[i];
            n/=10;
        } while (n>0);
    }

    // ITERATE OVER INPUT
    for (int i = 0; i < t; i++) {
        int del = lengths[i]/2;                         // delimiter
        int idel = lengths[i]-del;                      // length-delimiter
        int up = K[i] / (int) pow(10, del);             // upper value
        int n = 0;                                      // result

        // MIRROR - ROUND 1
        int u = up;
        n = up * pow(10, del);
        for (int j = 0; j < del; j++) {
            int temp = u / (int) pow(10, idel-j-1);
            n += temp * (int) pow(10, j);
            u -= temp * (int) pow(10, idel-j-1);
        }

        // <= ORIGINAL ? => MIRROR - ROUND 2
        if (n <= K[i]) {
            up++;
            if (up / (int) pow(10, idel) > 0) {
                idel++;
                if (del == 0) {                         // FOR SPECIAL CASE: 9
                    idel--;
                    del++;
                    up /= 10;
                }
            }
            n = up * pow(10, del);

            for (int j = 0; j < del; j++) {
                int temp = up / (int) pow(10, idel-j-1);
                n += temp * (int) pow(10, j);
                up -= temp * (int) pow(10, idel-j-1);
            }
        }

        // PRINT RESULT
        printf("%d\n", n);
    }

    return 0;
}
