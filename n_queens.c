#include <stdio.h>
 int N;
 int board[20][20];
 int found = 0;   
 int isSafe(int row, int col) {
 int i, j;
 
for (i = 0; i < col; i++)
 if (board[row][i])
 return 0;
for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
 if (board[i][j])
 return 0;
for (i = row, j = col; i < N && j >= 0; i++, j--)
 if (board[i][j])
 return 0;
 return 1;
}
 void solve(int col) {
if (col == N) {
 found = 1;  
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < N; j++)
 printf("%d ", board[i][j]);
 printf("\n");}
 printf("\n");
 return;
}
 for (int i = 0; i < N; i++) {
  if (isSafe(i, col)) {
 board[i][col] = 1;
 solve(col + 1);
 board[i][col] = 0;
} }
}
int main() {
    printf("Enter N: ");
    scanf("%d", &N);
    solve(0);
    if (!found)   
      printf("No solution exists\n");
return 0;
}
