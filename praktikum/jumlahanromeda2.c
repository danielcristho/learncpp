#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ROW 5
#define COL 5


// fungsi utk memasukan CELL kedalam DFS(recursive)
int isLand(int M[] [COL], int row, int col, bool visited[][COL]) {
  // RANGE ROW & COL
  return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

// buat fungsi untuk matriks
void DFS(int M[][COL], int row, int col, bool visited[][COL]) {

    //membuat array dgn matriks 2D utk mendapatkan baris dan Kolom
    //pada sel
    static int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // mark this cell
    visited[row][col] = true;

    //membuat rekursive
    for (int k = 0; k < 8; ++k)
        if (isLand(M, row + rowNum[k], col + colNum[k], visited))
            DFS(M, row + rowNum[k], col + colNum[k], visited);
}

// funsi untuk menghitung jumlah pulau dari matriks
int jumPulau(int M[][COL]) {
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    //intial
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) {
                DFS(M, i, j, visited);
                ++count;
            }
    return count;          
}
 int main() {
    /*int M[][COL] = { { 0, 0, 0, 1, 1},
                     { 1, 0, 0, 0, 1},
                     { 1, 0, 0, 1, 0},
                     { 0, 0, 0, 0, 0},
                     { 1, 0, 0, 1, 1} };*/
    int M[COL][ROW];              
    int i, j;


    for (i = 0; i<5;i++) {
        for (j = 0; j<5;j++) {
            scanf("%d",  &M[i][j]);
        }   

        


    }                 
 
    printf("Jumlah pulau Andromeda: %d\n", jumPulau(M));

    return 0;
}
