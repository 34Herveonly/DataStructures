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
/*

// This was a revision of how we did this question as well as strenghtening the core understanding of how it works 

// The newly learnt thing is if we had 5 as input and we're getting the stairs[4]+stairs[3] we dont add the 4 and 3 as the results of our computation we just add the previously obtained ways to reach them. for our case we would add the number of ways to reach the staie 4 and the stair 3 and we would be set.

#include <stdio.h>

int main() {
    int stairs[20],pos;
    
    int size=sizeof(stairs)/sizeof(stairs[0]);
    
    printf("Enter the number of stairs to climb: ");
    scanf("%d",&pos);
    
    if(pos>20){
        printf("The staircase cant exceed 20 for it cant be computed");
    }
    else{
        stairs[0]=1;
        stairs[1]=1;
    }
    for(int i=2;i<=size;i++){
        stairs[i]=stairs[i-1]+stairs[i-2];
    }
    printf("You can reach the stair %d in: %d ways",pos,stairs[pos]);
    return 0;
}

*/ 