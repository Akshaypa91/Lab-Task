#define M1(a,b) ((a) + (b))
#define M2(a,b,c) (M1(a,b) / M1(b,c))
#define M3(a,b,c) (M2(a,b,c) / M1(a,c))
#define M4(a,b,c) (M3(a,b,c))

int main() {
    int i = M4(1,2,3);   // (3 / 5) / 4 = 3 / (5 * 4) = 3 / 20 --> 0
    printf("%d\n", i);
}
