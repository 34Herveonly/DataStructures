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