int maxabsdiff(int arr[], int len){
    int sum = 0, max = 0;
    sum = arr[0] - arr[1];
    max = sum;
    for(int i = 1; i < len-1; i++){
        sum = arr[i] - arr[i+1];
        if(sum < 0){
            sum = -1 * sum;
        }
        max = max<sum ? sum : max;
    }
    return max;
}