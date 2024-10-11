#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game() {
    int score = 100, target, guess, min = 1, max = 100 ; //score : คะแนน target : เลขที่สุ่มมา guess : คำตอบที่ผุ้ใช้พิมพ์ Min,Max : เลข 1-100
    target = rand() % 100 + 1 ; //สุ่มตัวเลขระหว่าง1-100 เก็บค่าไว้ที่ Target
    printf("(score=%d)\n", score) ;

    //คำสั่งวนลูปเกมส์
    while (1) {
        printf("Guess the winning number (%d-%d) :\n", min, max) ;
        scanf("%d", &guess) ;

        //ตรวจสอบเลขที่ทายว่าถูกหรือไม่
        if (guess == target) { 
            printf("That is correct! The winning number is %d\n", target) ;
            printf("Score this game : %d\n", score) ;
            break ; 
        }//end if

        else {
            score -= 10 ;

            if (score <= 0) {
                printf("You lose\n") ;
                return ;
            }//end if

            if (guess < target) {
                printf("Sorry, the winning number is HIGHER than %d (score = %d)\n", guess, score) ;
                min = guess + 1 ; //ปรับช่วงตัวเลขที่สามารถทายใหม่ให้สูงขึ้นกว่าเลขที่ทาย
            }//end if

            else {
                printf("Sorry, the winning number is LOWER than %d (score = %d)\n", guess, score) ;
                max = guess - 1 ; //ปรับช่วงตัวเลขที่สามารถทายใหม่ให้ต่ำกว่าเลขที่ทาย
            }//end else

        }//end else

    }//end while

}//end function

int main() {
    int run ;
    srand(time(NULL)) ; //ตั้งค่าสำหรับสุ่มตัวเลขให้แตกต่างจากเลขเดิม

    while (1) {
        printf("Do you want to play the game (1 = play, -1 = exit) :\n") ;
        scanf("%d", &run) ;

        if (run == 1) {
            game() ;
        }//end if

        else if (run == -1) {
            break ;
        }//end else if

    }//end while

    return 0 ;
}//end function
