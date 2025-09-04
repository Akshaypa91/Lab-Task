int is_non_descending(int *a, int len) {
    
    for(int i=0; i < len-1; i++){
        if(a[i] > a[i+1]){
            return 0;
        }
    }
    return 1;
}
