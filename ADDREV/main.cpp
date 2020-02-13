#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nums[i][0], &nums[i][1]);
    }
    for (int i = 0; i < n; i++) {
        int lens[4]; // 0 - actual length 1; 1 - length 1; 2 - actual length 2; 3 - length 2

        // get lengths ...
        for (int j = 0; j < 2; j++) {
            int temp = nums[i][j];
            lens[j*2] = 0;
            // compute amount of trailing zeros
            while (temp%10==0) {
                lens[j*2]++;
                temp /= 10;
            }
            // compute length
            lens[j*2+1] = lens[j*2];
            while (temp>0) {
                lens[j*2+1]++;
                temp /= 10;
            }
            lens[j*2] = lens[j*2+1] - lens[j*2];              // compute actual length (= length without trailing zeros)
        }

        int shorter = lens[0] < lens[2] ? 0 : 1;
        int longer = 1-shorter;
        int carry = 0;
        int res = 0;

        // add overlapping sections
        for (; lens[shorter*2] > 0; --lens[0], --lens[1], --lens[2], --lens[3]) {
            int sdiv = (int)pow(10.0, lens[shorter*2+1]-1);
            int ldiv = (int)pow(10.0, lens[longer*2+1]-1);
            int temp = (nums[i][shorter]/sdiv + nums[i][longer]/ldiv) + carry;

            carry = temp/10;
            temp %= 10;
            res += temp * (int) pow(10.0, lens[longer*2]-1);

            nums[i][shorter] %= sdiv;
            nums[i][longer] %= ldiv;
        }

        // append longer section
        for (; lens[longer*2] > 0; --lens[longer*2], --lens[longer*2+1]) {
            int ldiv = (int)pow(10.0, lens[longer*2+1]-1);
            int temp = (nums[i][longer]/ldiv)+carry;

            carry = temp/10;
            temp %= 10;
            res += temp * (int) pow(10.0, lens[longer*2]-1);

            nums[i][longer] %= ldiv;
        }

        printf("%d\n", res);
    }
    return 0;
}
