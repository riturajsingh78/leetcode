class Solution {
public:
   vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n =grid[0].size();

        queue<vector<int>> q;

        int i=0 , j =0;

        q.push({0,0,k}); // starting point

        bool visited[41][41][1601]; //visited chech karne k lie
        memset(visited, false , sizeof(visited));

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                vector<int> temp =q.front();
                q.pop();

                int curr_i =temp[0];
                int curr_j =temp[1];
                int ob  =temp[2];

                if(curr_i == m-1 && curr_j ==n-1)
                return steps;

                for(vector<int> &dir :directions){

                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    int obs   = temp[2];

                    if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)  continue; /// out of bounds

                    if(grid[new_i][new_j] == 0 && !visited[new_i][new_j][obs]){
                        q.push({new_i,new_j,obs});
                        visited[new_i][new_j][obs] = true;
                    }
                    else if(grid[new_i][new_j] == 1 && obs > 0 && !visited[new_i][new_j][obs-1]){
                        q.push({new_i,new_j,obs-1});
                        visited[new_i][new_j][obs-1] = true;//visited
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};