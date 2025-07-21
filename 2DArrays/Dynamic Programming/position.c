// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
int n,fib[50];
printf("Enter the maximum value of sequence : ");
    scanf("%d",&n);
if(n>50){
    printf("Error, The length cant exceed 50. ");
    }
else {

fib[0]=0;
fib[1]=1;
// printf("Enter the values of our sequence");
for(int i=2;i<=n;i++){
    // scanf("%d",&fib[i]);
    fib[i]=fib[i-1]+fib[i-2];
}
printf("The value at position %d is: %d\n", n, fib[n]);
    return 0;
}
}

/*

// This was me doing revision fo how this question can be approached using dynamic programming  and making sure that i understand whats going on instead of just memorising

// Online C compiler to run C program online
#include <stdio.h>

int main() {

int fib[50],pos;
int size=sizeof(fib)/sizeof(fib[0]);
printf("Enter the position from which you would like to know it value in our fibonacci sequence: ");
scanf("%d",&pos);

if(pos>50){
    printf("\nThe position cant exceed 50 coz it would print nothing.");
}else{
    fib[0]=0;
    fib[1]=1;
    
    for(int i=2;i<=size;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    printf("\n The value at positon %d is : %d",pos,fib[pos]);
}
    return 0;
}

*/