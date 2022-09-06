#include<stdlib.h>
#include<stdio.h>
#define NOT_VISITED 0
#define VISITED 1

void fun(int maze[5][5],int work_row,int work_col,int tot_rows,int tot_cols,int visited[5][5])
{
  if(maze[work_row][work_col]==9)//food check
  {
      printf("Food Found\n");
      return;
  }
  //right -> col+1
  if(work_col+1 <tot_cols&&maze[work_row][work_col+1]!=1&&visited[work_row][work_col+1]==NOT_VISITED)
  {
      visited[work_row][work_col]=VISITED;
      fun(maze,work_row,work_col+1,tot_rows,tot_cols,visited);
      visited[work_row][work_col]=NOT_VISITED;
  }
  //down -> row+1
  if(work_row+1 <tot_rows&&maze[work_row+1][work_col]!=1&&visited[work_row+1][work_col]==NOT_VISITED)
  {
      visited[work_row][work_col]=VISITED;
      fun(maze,work_row+1,work_col,tot_rows,tot_cols,visited);
      visited[work_row][work_col]=NOT_VISITED;
  }
  //left -> col-1
  if(work_col-1>=0&&maze[work_row][work_col-1]!=1&&visited[work_row][work_col-1]==NOT_VISITED)
  {
      visited[work_row][work_col]=VISITED;
      fun(maze,work_row,work_col-1,tot_rows,tot_cols,visited);
      visited[work_row][work_col]=NOT_VISITED;
  }
  //top -> row-1
  if(work_row-1>=0&&maze[work_row-1][work_col]!=1&&visited[work_row-1][work_col]==NOT_VISITED)
  {
      visited[work_row][work_col]=VISITED;
      fun(maze,work_row-1,work_col,tot_rows,tot_cols,visited);
      visited[work_row][work_col]=NOT_VISITED;
  }

}
int main()
{
   /* int maze[8][7]={
{0,	0,	0,	0,	1,	1,	1},
{0,	1,	1,	0,	1,	1,	1},
{0,	1,	1,	0,	1,	0,	1},
{0,	0,	0,	0,	1,	1,	1},
{0,	1,	1,	0,	1,	1,	0},
{0,	1,	1,	0,	1,	1,	1},
{0,	9,	0,	0,	0,	0,	0},
{1,	0,	1,	1,	1,	0,	1}
};*/
    int tot_rows;
    int tot_cols;
    scanf("%d %d",&tot_rows,&tot_cols);
    int maze[tot_rows][tot_cols];

    for(int i=0;i<tot_rows;i++)
    {
        for(int j=0;j<tot_cols;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }

    int visited[tot_rows][tot_cols];
    int work_row=0;
    int work_col=0;
    fun(maze,work_row,work_col,tot_rows,tot_cols,visited);

    return EXIT_SUCCESS;
}

