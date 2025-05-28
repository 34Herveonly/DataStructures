// a dynamic programming exercise which was about Climbing Stairs and counting how many possible ways this process can be done if we are allowed to either take take 1 step at a time or 2 steps at a time
#include <stdio.h>

int main() {
    int steps[20],pos;
    
    printf("enter the stair nbr you want to get the possible ways for: \n");
    scanf("%d",&pos);
    if(pos>20){
        printf("The position can't be greater than 20");
    }
    else{
        steps[0]=1;
        steps[1]=1;
    
    for(int i=2;i<=20;i++){
        steps[i]=steps[i-1]+steps[i-2];
        }
        printf("the possible ways to reach to stair number %d are : %d ways",pos,steps[pos]);
    }
    return 0;
}