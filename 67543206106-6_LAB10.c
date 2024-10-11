#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char word[100] ;

    printf ("Enter word: ") ;
    fgets (word, sizeof(word), stdin) ;
    word[strcspn(word, "\n")] = 0 ;

    if (isPalindrome(word)) {
        printf("Pass.\n") ;
    }//end if

    else {
        printf("Not Pass.\n") ;
    }//end else

    return 0;
}//end function

int isPalindrome (char str[]) {
    int left = 0 ;
    int right = strlen(str) - 1 ;

    while (left < right) {
        char leftChar = tolower(str[left]) ;
        char rightChar = tolower(str[right]) ;

        if (!isalpha(leftChar)) {
            left ++ ;
        }//end if

        else if (!isalpha(rightChar)) {
            right -- ;
        }//end  else if

        else {
            if (leftChar != rightChar) {
                return 0 ;
            }//end if

            left ++ ;
            right -- ;
        }//end else

    }//end while

    return 1 ;
}//end function
