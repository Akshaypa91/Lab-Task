
void reverse(int a[] , int len){
    int i=0 , k = len - 1;
    while(i<k){
        int tempt = a[i];
        a[i] = a[k];
        a[k] = tempt;
        
        i++;
        k--;
    }
}

