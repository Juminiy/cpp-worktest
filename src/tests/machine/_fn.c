#include <unistd.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <stdio.h>

int fn0(int a, int b)
{
    return a + b;
}

int fn1(int arr[5])
{
    return arr[1];
}

#define __float2_bits(f_lval) *(int*)(&f_lval)
#define __double2_bits(d_lval) *(long long*)(&d_lval)

// int bitsConv(float f_val)
// {
//     return *(int*)(&f_val);
// }

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // int arrL[100000];
    fn0(1, 2);
    fn1(arr);
    // write()
    float f1 = 1.25;
    double d1 = 1231.375;
    printf("%X\n", __float2_bits(f1));
    printf("%X\n", __double2_bits(d1));
    return 0;
}