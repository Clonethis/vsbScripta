#include <stdio.h>
int compute_grade( int points ) {
    int grade = 4;
    printf("iam running");
    if ( points > 85 && points <101 ) {
        grade = 1;
    } else if ( points > 65 ) {
        grade = 2;
    } else if ( points > 50 ) {
        grade = 3;
    } else if (points <=50){
        grade = 4;
    }else{
        printf("NA");   
    }
    return grade;
}

int main(int argc, char *argv[]){
    int x= 100;
    printf("Hello");
    // int output;
    // while(1)
    // scanf("%d",x)==
while(x>0){
        scanf("%d",x);

        printf("While is running");
 compute_grade(x);
        printf("%d",x);
    };
}