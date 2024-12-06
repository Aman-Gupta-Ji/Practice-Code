/*
Consider the following maze, for example:
                            UP
                 +----------------------+
                 |   1   |   0   |   1  |
                 +----------------------+
       LEFT      |   1   |   1   |   1  |    RIGHT
                 +----------------------+
                 |   0   |   0   |   9  |
                 +----------------------+
                           DOWN
The maze is of dimension 3x3 and there exists a path from the top leftmost corner to the cheese which is in the bottom rightmost corner (down -> right -> right -> down). 
Implement the following function to confirm and return if there exists a path from the top left most corner of the maze to the cheese.*/


// U D R L
// "DRRD"
// 3 x 3
// "NOT FOUND"


// 0 - i, 1 - j
int dir [4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j) {
    return i >= 0 && i < 3 && j >= 0 && j < 3;
}

string backtrack(vector<vector<int>>& grid, int i, int j) {
    if(!isValid(i, j) && grid[i][j] == 0)
        return "N";
    if(grid[i][j] == 9)
        return "";
    stirn up = backtrack(grid, i - 1, j);
    if(up[0] != "N")
        return "D" + up;
    stirn down = backtrack(grid, i + 1, j);
    if(up[0] != "N")
        return "D" + down;
    stirn left = backtrack(grid, i, j - 1);
    if(up[0] != "N")
        return "D" + left;
    stirn right = backtrack(grid, i, j + 1);
    if(up[0] != "N")
        return "D" + riht;
    
    return "N";
}

string findPath(vector<vector<int>>& grid, int i, int j) {
    if(grid[i][j] == 9)
        return "";
    string res = backtrack(grid, i, j);
    if(res == "N")
        return "NOT FOUND";
    else
        return res;
}