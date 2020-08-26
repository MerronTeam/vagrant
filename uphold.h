#include "include.h"
using namespace std ;


bool OfUser(int, int) ;
void Push(int, int) ;
void FunRand() ;
void Change() ;
bool CheckWinIs() ;
bool CheckLoseIs() ;


int num ;
int CityNum = 5 ;
string UserN ;
char *sys_time ;
time_t NowTime ;
tm *ltm ;

int Ux, Uy ;

int Lucky = 30 ;


struct XY
{
    int x ;
    int y ;
} UserP[1000];

int ADD[20][20] ; 

int Map[20][20] ;
bool City[20][20] ;


int UserSize;

int MAPSIZE ;


void Push(int x, int y)
{
    UserSize ++ ;
    UserP[UserSize].x = x ;
    UserP[UserSize].y = y ;
}


bool OfUser(int x, int y)
{
    for(int i = 1 ;i <= UserSize ;i ++)
    {
        if(UserP[i].x == x && UserP[i].y == y)
        {
            return 1 ;
        }
    }
    return 0 ;
}

void FunRand()
{
    srand(time(0)) ;
    int n = 1 ;
    for(int i = 1 ;i <= n ;i ++)
    {
        int X = rand()%MAPSIZE + 1 ;
        int Y = rand()%MAPSIZE + 1 ;
        if (X!= Ux && Y!= Uy && rand() % 2)
        {
            Map[Y][X] = rand() % 30;
            ADD[Y][X] = -1 ;
        }
        if (Y == Uy && X == Ux)
        {
            n ++ ;
        }
    }
}

void UpHold()
{
    for(int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            if(Map[i][j] < 0)
            {
                if(ADD[i][j] == -1)
                {
                    Map[i][j] *= -1 ;
                    ADD[i][j] = 1 ;
                }
                else
                {
                    Map[i][j] *= -1 ;
                    ADD[i][j] = -1 ;
                }
            }
        }
    }
}

void Change()
{
    int ans = 0; 
    for (int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            if (Map[i][j] > ans && ADD[i][j] == 1)
            {
                ans = Map[i][j] ;
                Ux = j ;
                Uy = i ;
            }
        }
    }
}

bool CheckWinIs()
{
    for (int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            if(ADD[i][j] != 1)
            {
                return 0 ;
            }
        }
    }
    return 1 ;
}

bool CheckLoseIs()
{
    for (int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            if(ADD[i][j] != -1 && i != Uy && j != Ux)
            {
                return 0 ;
            }
        }
    }
    return 1 ;
}
