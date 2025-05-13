#include <stdio.h>

int main() {
    int n, num;
    
    printf("Enter how many numbers you want to check: ");
    scanf("%d", &n);
    
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
    	printf("Enter The Element %d:",i+1);
        scanf("%d", &num);
        
        if(num % 2 == 0) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }
    }
    
    return 0;
}