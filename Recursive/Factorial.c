#include <stdio.h>

// passing n parameter value to our function 
int factorial(int n){
    if(n<=1)return 1; // checks wether n is equal to 1 or less to return 1
    
    
    else return n*factorial(n-1); // if the n value is greater than 1 we will recursively keep changing our n through the line factorial(n-1) and check again wether our 1st condition until it stops and then we will get an answer by multiplying the values we got! 
}

int main() {
    int n=5; // n value initialisation 
    
    printf("%d",factorial(n)); // calling our factorial function and passing in the n argument

    return 0;// terminating our function
}

/*
// Just going to take on this factorial recursive exrecise to make sure i recall everything

#include <stdio.h>

int factorial(int n){

if(n<=1){
    return 1;
    }
    else {
    return n*factorial(n-1);
    }
}

int main(){
int n;

printf("Enter the value to find the factorial for:");
scanf("%d",&n);

printf("%d",factorial(n));
    
}


*/ 