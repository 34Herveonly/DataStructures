/*Problem: Letter Combinations of a Phone Number
Given a string containing digits from 2 to 9, return all possible letter combinations that the number could represent. Return the answer in any order.*/

#include <stdio.h>
#include <string.h>

// Recursive function to generate combinations
    void printCombinations(char *input, int index, char *map[], char combination[], int inputLength) {
    // Base case: full combination formed
    if (index == inputLength) {
        combination[index] = '\0'; // Null-terminate the string
        printf("%s\n", combination);
        return;
    }

    // Get digit at current index and map to letters
    int digit = input[index] - '0';       // Convert char '2' to int 2
    char *letters = map[digit];           // Get letters for that digit

    // Loop through each letter and recurse
    for (int i = 0; letters[i] != '\0'; i++) {
        combination[index] = letters[i];  // Choose the current letter
        printCombinations(input, index + 1, map, combination, inputLength); // Recurse for next digit
        // Backtracking happens automatically as we overwrite combination[index] in next iteration
    }
}

int main() {
    // Digit to letter mapping
    char *map[] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    char input[20];
    printf("Enter digits (2-9): ");
    scanf("%s", input);

    int inputLength = strlen(input);

    // Edge case: no input
    if (inputLength == 0) {
        printf("No combinations (empty input)\n");
        return 0;
    }

    char combination[20];  // Buffer to build each combination
    printCombinations(input, 0, map, combination, inputLength);

    return 0;
}

/*
// Given a string of digits (from 2 to 9), we want to print all the possible letter combinations that the number could represent — just like the letters on an old phone keypad.


#include <stdio.h>
#include<string.h>

void printCombinations(char *input,int index,char *map[],int length,char combinations[]){
    if(index==length){
        combinations[index]='\0';
        printf("%s\n",combinations);
        return;
    }
    int digit=input[index]-'0';
    char *letters=map[digit];
    
    for(int i=0;letters[i] !='\0';i++){
        combinations[index]=letters[i];
        printCombinations(input,index+1,map,length,combinations);
    }
}

int main() {
char *map[] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    
    char input[20];
    printf("Enter the input between(2-9): ");
    scanf("%s",input);
    int length=strlen(input);
    int index;
    char combinations[20];
    
    printCombinations(input,0,map,length,combinations);
    return 0;
}
*/ 