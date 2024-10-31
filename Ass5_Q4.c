int max3(int a, int b, int c){
    // int max = a;

    if (b > a)
    {
        a = b;
    }
    if (c > a)
    {
        a = c;
    }

    return a;
}