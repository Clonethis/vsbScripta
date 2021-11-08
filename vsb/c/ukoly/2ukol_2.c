#include <stdio.h>
int compute_grade( int points ) {
    int grade = 4;
    if (points>100){
        grade=5;
    }
    else if ( points > 85) {
        grade = 1;
    } else if ( points > 65 ) {
        grade = 2;
    } else if ( points > 50 ) {
        grade = 3;
    } else if (points <=50 && points >= 0){
        grade = 4;
    }else{
        return 0;  
    }
    return grade;
}

int main(){
    int x,output;
do{
        scanf("%d",&x);
        output = compute_grade(x);
        if ( output < 5 && output >0){
            printf("%d\n",output);
        }else if (output==5){
            printf("NA\n");
        }else{
            break;
        }
    }while(x>=0);
    return 0;
}