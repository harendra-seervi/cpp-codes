#include <bits/stdc++.h>
using namespace std;

// void display(vector<vector<bool>> &visited, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << visited[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

bool issafe(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int n)
{
    if (row < 0 || col < 0 || row >= n || col >= n)  return false;
    if (visited[row][col] == true)  return false;
    if (grid[row][col] == 1)  return false;
    else{
        return true;
    }
}

int total = 0;

void rat_in_maze(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int n)
{
    if (row == n - 1 && col == n - 1)
    {
        // display(visited,n);
        total++;
        visited[n - 1][n - 1] = true;
        // cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    if (issafe(grid, visited, row, col, n))
    {
        visited[row][col] = true;
        rat_in_maze(grid, visited, row + 1, col, n); //DOWNWARD
        rat_in_maze(grid, visited, row, col + 1, n); //RIGHT
        rat_in_maze(grid, visited, row - 1, col, n); //UPWARD
        rat_in_maze(grid, visited, row, col - 1, n); //DOWNWARD
        visited[row][col] = false;
    }
}

int main()
{
    int n;
    cin >> n; //input size of grid
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j]; //input gird
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false)); //initializing visited
    rat_in_maze(grid, visited, 0, 0, n);    
    // cout << endl;
    cout << total << endl;
    // cout << endl;
    return 0;
}

// 0 1 0 1 0
// 0 0 0 0 0
// 1 0 1 0 1
// 0 1 1 0 0
// 0 0 0 1 0

// 7
// 0 0 1 0 0 1 0
// 1 0 1 1 0 0 0
// 0 0 0 0 1 0 1
// 1 0 1 0 0 0 0
// 1 0 1 1 0 1 0
// 1 0 0 0 0 1 0
// 1 1 1 1 0 0 0
