/*
 Our goal is to find the largest possible square-shaped patch of connected fertile land — meaning all 1s — without including any infertile (0) cells inside it.
 We do this by checking, for each plot, how big a square of fertile land can end there, using info from the top, left, and top-left neighboring plots.

 #include <stdio.h>

 #define ROW 5
 #define COL 5

 int min(int a ,int b ,int c){
  int m = a < b ? a : b;
  
  return m < c ? m : c;   
  
  } 

 int main(){
 int farm[ROW][COL] = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1}
    };

  int maxSize=0;
  int maxRow=0;
  int maxCol=0;

  int dp[ROW][COL];

    for(int i=0;i<ROW;i++){
      for(int j=0; j<COL;j++){

      if(i==0 || j==0){
          dp[i][j]=farm[i][j];
        } 
          else if(farm[i][j] == 1){
            dp[i][j]= 1 + min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);  
        }
          else {
          dp[i][j]=0;  
        }
          
      if(dp[i][j] > maxSize){
        maxSize=dp[i][j];
         maxRow = i;
         maxCol = j;
        } 
      }
    }
      printf("The Largest square of 1's is: %d",maxSize);
    printf("\nArea: %d\n", maxSize * maxSize);
    printf("Bottom-right corner of the largest square is at: (%d, %d)\n", maxRow, maxCol);
    printf("The square starts at: (%d, %d)\n", maxRow - maxSize + 1, maxCol - maxSize + 1);

    return 0;

}


*/