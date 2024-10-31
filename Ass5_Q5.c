unsigned long factorial(unsigned int n) {
    if(n == 0) {
        return 1;
    }
    unsigned long result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}