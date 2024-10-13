#include <stdio.h>

int main() {
    int amount;
    scanf("%d", &amount);

    
    int denominations[] = {100, 50, 20, 5, 1};
    int notes[5] = {0}; 
    int totalNotes = 0;

    for (int i = 0; i < 5; i++) {
        notes[i] = amount / denominations[i]; 
        amount %= denominations[i];            
        totalNotes += notes[i];                
    }

    for (int i = 0; i < 5; i++) {
        if (notes[i] > 0) {
            printf("%d %d ", denominations[i], notes[i]); 
        }
    }
    printf("%d\n", totalNotes);
    return 0;
}