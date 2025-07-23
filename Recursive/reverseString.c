
#include <stdio.h>      // Standard Input/Output library
#include <string.h>     // Includes string handling functions like strlen()

// Recursive function to reverse a string in place
int reverse(int i, int j, char sentence[]) {

    // Base case: when the two pointers meet or cross, stop recursion
    if (i >= j) return 0;

    else {
        // Swap the characters at index i and j
        int temp = sentence[i];
        sentence[i] = sentence[j];
        sentence[j] = temp;
    }

    // Recursive call: move the pointers inward
    reverse(i + 1, j - 1, sentence);
}

// Main function
int main() {
    // Declare and initialize the string to be reversed
    char sentence[] = "MOTHER FUCKER";

    // Call the reverse function with:
    // i = starting index (0)
    // j = last index (length - 1)
    // sentence = the string to reverse
    reverse(0, strlen(sentence) - 1, sentence);

    // Print the reversed string
    printf("%s", sentence);

    return 0;
}

/*
// Today im going to be revising about this string reverse using the recursion approach

#include <stdio.h>
#include <string.h>

void reverse(char word[],int start,int end){

    if(start>=end)return;
    
    char temp=word[start];
    word[start]=word[end];
    word[end]=temp;
 
    reverse(word,start+1,end-1);
}

int main(){
    char word[]="MONEY ON MY MIND";
    printf("The given sentence is: %s",word);
    int size=strlen(word);
    int start;
    int end;

    reverse(word,0,size-1);
    printf("The reversed sentence is: %s",word);

    
}


*/ 