/*BFS (Breadth-First Search)
Surrounded Regions (Medium)

The Surrounded Regions problem (Leetcode 130) asks you to flip all 'O's on a 2D board that are completely surrounded by 'X' into 'X', while keeping border-connected 'O's unchanged. To solve it using BFS, you scan the board’s borders and perform a BFS from each 'O' found there, marking all connected 'O's as safe (e.g., using '#'). After this, you loop through the entire board: flip all unmarked 'O's to 'X' (since they're trapped), and restore the marked '#'s back to 'O'. This way, only the 'O's truly surrounded on all sides get flipped, while those connected to the edge stay intact.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int x, y;
} Point;

// Directions: Down, Up, Right, Left
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

// Simple BFS function
void bfs(char** board, int rows, int cols, int i, int j) {
    Point queue[MAX];
    int front = 0, rear = 0;

    board[i][j] = '#'; // mark as safe
    queue[rear++] = (Point){i, j};

    while (front < rear) {
        Point p = queue[front++];

        for (int d = 0; d < 4; d++) {
            int ni = p.x + dir[d][0];
            int nj = p.y + dir[d][1];

            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && board[ni][nj] == 'O') {
                board[ni][nj] = '#';
                queue[rear++] = (Point){ni, nj};
            }
        }
    }
}

// Solves the surrounded regions problem
void solve(char** board, int rows, int* colSizes) {
    if (rows == 0 || colSizes[0] == 0) return;
    int cols = colSizes[0];

    // Step 1: Mark border-connected 'O's
    for (int i = 0; i < rows; i++) {
        if (board[i][0] == 'O') bfs(board, rows, cols, i, 0);
        if (board[i][cols - 1] == 'O') bfs(board, rows, cols, i, cols - 1);
    }

    for (int j = 0; j < cols; j++) {
        if (board[0][j] == 'O') bfs(board, rows, cols, 0, j);
        if (board[rows - 1][j] == 'O') bfs(board, rows, cols, rows - 1, j);
    }

    // Step 2: Flip and restore
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';      // Surrounded → X
            else if (board[i][j] == '#')
                board[i][j] = 'O';      // Safe → Restore
        }
    }
}

// Helper function to print the board
void printBoard(char** board, int rows, int cols) {
    printf("Board:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Main function to test
int main() {
    int rows = 4;
    int cols = 4;
    int colSizes[4] = {4, 4, 4, 4};

    // Allocate memory for board
    char** board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        board[i] = (char*)malloc(cols * sizeof(char));
    }

    // Initialize the board
    char input[4][4] = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    // Copy input to board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = input[i][j];
        }
    }

    printf("Before:\n");
    printBoard(board, rows, cols);

    solve(board, rows, colSizes);

    printf("After:\n");
    printBoard(board, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

