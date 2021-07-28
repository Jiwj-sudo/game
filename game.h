#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            board[i][j] = ' ';
    }
}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        //1.打印一行的数据
//        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//        //2.打印分割行
//        if (i < row - 1)
//            printf("---|---|---\n");
//    }
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        //1.打印一行的数据
       int j = 0;
       for (j = 0; j < col; j++)
       {
            if (j < col - 1)
                printf(" %c |", board[i][j]);
            else
                printf(" %c ", board[i][j]);
       }
       printf("\n");
        //2.打印分割行
        if (i < row - 1)
        {
            for(j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
        }
        printf("\n");
    }
}

/*
    函数名称:Playermove
    功能: 玩家走棋
*/
void Playermove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家走:>\n");
    while (1)
    {
        printf("请输入要走的坐标:>");
        scanf("%d%d", &x, &y);
        //判断坐标的合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else
                printf("该坐标被占用\n");
        }
        else
            printf("坐标非法，请重新输入!\n");
    }
}

/*
    函数名称:Computermove
    功能: 电脑走棋
*/
void Computermove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("电脑走:>\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

/*
    函数名称:IsFull
    功能:判断棋盘是否已满
    如果已满返回1
    否则返回0
*/
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0; // 没满
        }
    }
    return 1; //满了
}
/*
    函数名称:IsWin
    功能:判断谁赢
    四种状态：
    玩家赢 -- '*'
    电脑赢 -- '#'
    平局 -- 'Q'
    继续 -- 'C'
*/
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)  // 判断横三行
    {
        if ( board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }
    for (i = 0; i < col; i++)  // 判断竖三列
    {
        if ( board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    //两个对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
        return board[1][1];
    //判断是否平局
    if (1 == IsFull(board, ROW, COL))
        return 'Q';
    return 'C';
}
#endif // GAME_H
