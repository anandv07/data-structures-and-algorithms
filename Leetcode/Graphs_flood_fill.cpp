// Flood fill, also called seed fill, is a flooding algorithm that determines and alters the area connected to a given node 
// in a multi-dimensional array with some matching attribute. It is used in the "bucket" fill tool of paint programs to fill 
// connected, similarly-colored areas with a different color, and in games such as Go and Minesweeper for determining 
// which pieces are cleared. Source(https://en.wikipedia.org/wiki/Flood_fill)
#include<bits/stdc++.h>
using namespace std;
int R, C;
void print_matrix(char input[][50]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << input[i][j];
        }
        cout << "\n";
    }
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void flood_fill(char input[][50], int i, int j, char ch, char color){
    // base case :  make sure we do not cross boundries of input matrix
    if(i < 0 || j < 0 || i >= R || j >= C)
        return;
    // if we are coming to a cell that is not equal to ch then we dont do anything
    if(input[i][j] != ch)
        return;
    // fill the color     
    input[i][j] = color;
    
    // dfs flood_fill on all directions
    for(int k = 0; k < 4; k++){
        flood_fill(input, i + dx[k], j + dy[k], ch, color);
    }        
}
int main(){
    cin >> R >> C;
    char input[15][50];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> input[i][j];
        }
    }
    print_matrix(input);
    flood_fill(input, 8, 13, '.', 'r');
    print_matrix(input);
    flood_fill(input, 2, 15, '.', 'b');
    print_matrix(input);
return 0;
}

/*
Input
15 30
..............................
.............#####............
.............#...#............
.....#########...#######......
....###.....######.....###....
...##....................##...
..##......................#...
..##.....................##...
..###...................##....
....###................###....
......###............###......
........###........###........
..........##########..........
..............................
...........A.P.P.L.E..........
Output : 
..............................
.............#####............
.............#...#............
.....#########...#######......
....###.....######.....###....
...##....................##...
..##......................#...
..##.....................##...
..###...................##....
....###................###....
......###............###......
........###........###........
..........##########..........
..............................
...........A.P.P.L.E..........
..............................
.............#####............
.............#...#............
.....#########...#######......
....###rrrrr######rrrrr###....
...##rrrrrrrrrrrrrrrrrrrr##...
..##rrrrrrrrrrrrrrrrrrrrrr#...
..##rrrrrrrrrrrrrrrrrrrrr##...
..###rrrrrrrrrrrrrrrrrrr##....
....###rrrrrrrrrrrrrrrr###....
......###rrrrrrrrrrrr###......
........###rrrrrrrr###........
..........##########..........
..............................
...........A.P.P.L.E..........
..............................
.............#####............
.............#bbb#............
.....#########bbb#######......
....###rrrrr######rrrrr###....
...##rrrrrrrrrrrrrrrrrrrr##...
..##rrrrrrrrrrrrrrrrrrrrrr#...
..##rrrrrrrrrrrrrrrrrrrrr##...
..###rrrrrrrrrrrrrrrrrrr##....
....###rrrrrrrrrrrrrrrr###....
......###rrrrrrrrrrrr###......
........###rrrrrrrr###........
..........##########..........
..............................
...........A.P.P.L.E..........
*/