/*BFS (Breadth-First Search)
Surrounded Regions (Medium)

The Surrounded Regions problem (Leetcode 130) asks you to flip all 'O's on a 2D board that are completely surrounded by 'X' into 'X', while keeping border-connected 'O's unchanged. To solve it using BFS, you scan the board’s borders and perform a BFS from each 'O' found there, marking all connected 'O's as safe (e.g., using '#'). After this, you loop through the entire board: flip all unmarked 'O's to 'X' (since they're trapped), and restore the marked '#'s back to 'O'. This way, only the 'O's truly surrounded on all sides get flipped, while those connected to the edge stay intact.
*/
