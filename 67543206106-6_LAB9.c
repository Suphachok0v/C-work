#include <stdio.h>
int main() {
    int N ;

    printf("Enter N :\n    ") ;
    scanf("%d", &N) ;

    int values[N] ;
    for (int i = 0 ; i < N ; i++) {
        printf("Enter value[%d] :\n    ", i) ;
        scanf("%d", &values[i]) ;
    }//end for

    printf("\nIndex :  ") ;
    for (int i = 0 ; i < N ; i++) {
        printf("%d  ", i) ;
    }//end for

    printf("\nArray : ") ;
    for (int i = 0 ; i < N ; i++) {
        if (isPrime(values[i])) {
            printf("%d  ", values[i]) ;
        }//end if
        
        else {
            printf("#  ") ;
        }//end else

    }//end for

    printf("\n") ;
    
    return 0 ;
}//end function

int isPrime(int number) {
    if (number <= 1) return 0 ;
    for (int i = 2 ; i * i <= number ; i++) {
        if (number % i == 0) return 0 ; 
    }//end for

    return 1 ;
}//end function
