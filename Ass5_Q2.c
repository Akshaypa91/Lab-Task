int add(int a, int b) {
    return a + b;
}
int mult(int x, int y) {
    int abs_x = (x < 0) ? -x : x;
    int abs_y = (y < 0) ? -y : y;
    int result = 0;
    
    while (abs_y > 0) {
        result = add(result, abs_x);
        abs_y = add(abs_y, -1); 
    }

    if ((x < 0) ^ (y < 0)) {
        result = -result;
    }

    return result;
}