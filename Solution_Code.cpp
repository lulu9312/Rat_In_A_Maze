#include <iostream>
using namespace std;
#define SIZE 5


int maze[SIZE][SIZE] = {    //Input Matrix
    {0,1,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
    {0,0,1,1,0},
    {1,0,0,0,0}
};          


int solution[SIZE][SIZE];   //Matrix to store solution

void printsolution()       //Function to print the solution
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            cout<<"\t"<<solution[i][j];
        }
        cout<<endl<<endl;
    }
}

int solvemaze(int r, int c)  //Function to solve maze  using backtracking
{
    if((r==SIZE-1) && (c==SIZE-1)) //If the destination is reached,the maze is solved,destination is the last cell i.e (maze[SIZE-1][SIZE-1])
    {
        solution[r][c] = 1;
        return 1;
    }
    //The indices of the cell must be in(0,SIZE-1)
	// solution[r][c] == 0 is making sure that the cell is not already visited 
	//maze[r][c] == 0 is making sure that the cell is not blocked
    if(r>=0 && c>=0 && r<SIZE && c<SIZE && solution[r][c] == 0 && maze[r][c] == 0)
    
 {
        solution[r][c] = 1;  //if safe to visit then visit the cell
        
        if(solvemaze(r+1, c)) //going down
            return 1;
        if(solvemaze(r, c+1)) //going right
            return 1;
        if(solvemaze(r-1, c)) //going up
            return 1;
        if(solvemaze(r, c-1)) //going left
            return 1;
        solution[r][c] = 0; //backtracking
        return 0;
    }
    return 0;

}

int main()
{
    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            solution[i][j] = 0;
        }
    }
    if (solvemaze(0,0))
        printsolution();
    else
        cout<<"No Solution"<<endl;
    return 0;
}
