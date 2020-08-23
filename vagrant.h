#include "include.h"
#include "uphold.h"
#include <time.h>
using namespace std ;

void Start() ;
void Run() ;
void Login() ;
void CreateUser() ;
void print() ;
bool oper(string, string) ;
void GameShow() ;
void Set() ;
void End() ;
int Finish() ;
bool quit() ;
void Help() ;
void UpGame() ;

bool Has ;

//in fact, we only need 6x6

bool won ;

string Str ;

long long Uscore ;


int N ;

struct GF
{
    string name ;
    long long score ;
} UC[1005] ;

bool cmp(GF a, GF b)
{
	return a.score > b.score ;
}

void UpGame()
{
    freopen("game.txt", "r", stdin) ;
    int n ;
    cin >> n ;
    for (int i = 1 ;i <= n ;i ++)
    {
        int ak ;
        cin >> ak ;
        cin >> UC[i].name >> UC[i].score ;
        if (UC[i].name == UserN)
        {
            UC[i].score = Uscore ;
        }
    }
    fclose(stdin) ;
    sort(UC + 1, UC + n + 1, cmp) ;
    freopen("game.txt", "w", stdout) ;
    cout << n << endl ;
    for (int i = 1 ;i <= n ;i ++)
    {
        cout << i << " " << UC[i].name << " " << UC[i].score << endl ;
    } 
    fclose(stdout) ;
}

void Set(int x)
{
    time_t now1 = time(0) ;
    tm *now = localtime(&now1) ;
    if (now -> tm_sec - x >= 0.5)
    {
        for (int i = 1 ;i <= MAPSIZE ;i ++)
        {
            for (int j = 1 ;j <= MAPSIZE ;j ++)
            {
                if (Map[i][j])
                {
                    Map[i][j] ++ ;
                }
            }
        }
    }
}

void Start()
{
    system("07") ;
    system("cls") ;
    system("title Vagrant") ;
    for (int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            ADD[i][j] = 0 ;
        }
    }
    char per ;
    while(1)
    {
        cout << "Already have an account?\n" ;
        cout << "(Press 1:Log in ;Press 0:Register)\n" ;
        per = getch() ;
        if (per == '1' )
        {
            Login() ;
            break ;
        }
        if (per == '0')
        {
            CreateUser() ;
            break ;
        }
        else
        {
            cout << "Error!Again!\nPerss any key to again." ;
            getch() ;
            system("cls") ;
        }
    }
    return ;
}

void CreateUser()
{
    system("cls") ;
    cout << "Input name:>" ;
    string name ;
    cin >> name ;
    string U[1000] ;
    freopen("data/users.txt", "r", stdin) ;
    int n ;
    cin >> n ;
    for (int i = 1 ;i <= n ;i ++)
    {
        cin >> U[i] ;
        if (oper(name, U[i]))
        {
            cout << "Error!It isn't lagal.\n" ;
            getch() ;
            exit(0) ;
        }
    }
    U[n + 1] = name ;
    fclose(stdin) ;
    freopen("data/users.txt", "w", stdout) ;
    n ++ ;
    cout << n  << endl;
    for (int i = 1 ;i <= n + 1 ;i ++)
    {
        cout << U[i] << endl ;
    }
    N = n ;
    fclose(stdout) ;
    freopen("game.txt", "r", stdin) ;
    for (int i = 1 ;i < n ;i ++)
    {
        int ak ;
        cin >> ak ;
        cin >> UC[i].name >> UC[i].score ;
    }
    UC[N].name = name ;
    UC[N].score = 0 ;
    fclose(stdin) ;
    freopen("game.txt", "r", stdout) ;
    cout << n << endl ;
    for (int i = 1 ;i <= n ;i ++)
    {
        cout << i << " " << UC[i].name << " " << UC[i].score ;
    }
    fclose(stdout) ;
    cout << "Please restart.\n" ;
    getch() ;
    exit(0) ;
}

string Un, Uk ;

void Login()
{
    system("cls") ;
    cout << "Input your username:>" ;
    cin >> Un ;
    freopen("data/users.txt", "r", stdin) ;
    cin >> num ;
    bool fu = 0 ;
    string user ;
    for (int i = 1 ;i <= num ;i ++)
    {
        cin >> user ;
        if (oper(Un, user))
        {
            fu = 1 ;
            break ;
        }
    }
    if (fu == 1)
    {
        UserN = user ;
        return ;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout << "Error!Username can't find.\n";
        getch() ;
        exit(0) ;
    }
    Str = "User/" ;
    Str += UserN ;
    Str += ".txt" ;
    fclose(stdin) ;
    Sleep(100) ;
    cout << "Do you want to continue the old game?\n" ;
    cout << "Press 1 : continue ; Press otherkey : create a new game.\n" ;
    char cinGet ;
    cinGet = getch() ;
    if (freopen(&Str[0], "r", stdin) != NULL && cinGet == '1')
    {
        Has = 1 ;
        int number ;
        cin >> Ux >> Uy ;
        cin >> number ;
        UserSize = number ;
        for (int i = 1 ;i <= number ;i ++)
        {
            cin >> UserP[i].x >> UserP[i].y ;
        }
        for (int i = 1 ;i <= MAPSIZE ;i ++)
        {
            for (int j = 1 ;j <= MAPSIZE ;j ++)
            {
                cin >> Map[i][j] ;
            }
        }
        for (int i = 1 ;i <= MAPSIZE ;i ++)
        {
            for (int j = 1 ;j <= MAPSIZE ;j ++)
            {
                cin >> ADD[i][j] ;
            }
        }
    }
    else if(cinGet == '1')
    {
        cout << "Sorry!Your old game is lose!You have to start a new one\n" ;
    }
    fclose(stdin) ;
    return ;
}

bool oper(string a, string b)
{
    int len = max(a.size(), b.size()) - 1;
    while(len --)
    {
        if (a[len] != b[len])
        {
            return 0 ;
        }
    }
    return 1 ;
}

void Run()
{
    Ux = 1 ;
    Uy = 1 ;
    Push(Ux, Uy) ;
    Map[Uy][Ux] = 10 ;
    ADD[Uy][Ux] = 1 ;
    NowTime = time(0) ;
    ltm = localtime(&NowTime);
    char UserGet ;
    int Temp ;
    while(1)
    {
        Sleep(200) ;
        FunRand() ;
        print() ;
        UserGet = getch() ;
        if(UserGet == 'w')
        {
            if(Uy > 1 && Map[Uy][Ux] > 1)
            {
                Temp = Map[Uy][Ux] - 1;
                Map[Uy][Ux] = 1 ;
                Uy -- ;
                if (ADD[Uy][Ux] == -1)//if it is red
                {
                    if(Temp > Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 1 ;
                        Temp -= Map[Uy][Ux] ;
                        Temp ++ ;
                        Map[Uy][Ux] = Temp ;
                    }
                    else if(Temp == Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 0 ;
                        Map[Uy][Ux] = 0 ;
                        Change() ;
                    }
                    else
                    {
                        ADD[Uy][Ux] = -1 ;
                        Map[Uy][Ux] = Map[Uy][Ux] - Temp;
                        Change() ;
                    }
                }
                else
                {
                    Map[Uy][Ux] = Temp + Map[Uy][Ux] ;
                    ADD[Uy][Ux] = 1 ;
                }
                if(OfUser(Ux, Uy) == 0)
                {
                    Push(Ux, Uy) ;
                }
            }
        }
        if(UserGet == 's')
        {
            if(Uy < MAPSIZE && Map[Uy][Ux] > 1)
            {
                Temp = Map[Uy][Ux] - 1;
                Map[Uy][Ux] = 1 ;
                Uy ++ ;
                if (ADD[Uy][Ux] == -1)//if it is red
                {
                    if(Temp > Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 1 ;
                        Temp -= Map[Uy][Ux] ;
                        Temp ++ ;
                        Map[Uy][Ux] = Temp ;
                    }
                    else if(Temp == Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 0 ;
                        Map[Uy][Ux] = 0 ;
                        Change() ;
                    }
                    else
                    {
                        ADD[Uy][Ux] = -1 ;
                        Map[Uy][Ux] = Map[Uy][Ux] - Temp;
                        Change() ;
                    }
                }
                else
                {
                    Map[Uy][Ux] = Temp + Map[Uy][Ux] ;
                    ADD[Uy][Ux] = 1 ;
                }
                if(OfUser(Ux, Uy) == 0)
                {
                    Push(Ux, Uy) ;
                }
            }
        }
        if(UserGet == 'a')
        {
            if(Ux > 1 && Map[Uy][Ux] > 1)
            {
                Temp = Map[Uy][Ux] - 1;
                Map[Uy][Ux] = 1 ;
                Ux -- ;
                if (ADD[Uy][Ux] == -1)//if it is red
                {
                    if(Temp > Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 1 ;
                        Temp -= Map[Uy][Ux] ;
                        Temp ++ ;
                        Map[Uy][Ux] = Temp ;
                    }
                    else if(Temp == Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 0 ;
                        Map[Uy][Ux] = 0 ;
                        Change() ;
                    }
                    else
                    {
                        ADD[Uy][Ux] = -1 ;
                        Map[Uy][Ux] = Map[Uy][Ux] - Temp;
                        Change() ;
                    }
                }
                else
                {
                    Map[Uy][Ux] = Temp + Map[Uy][Ux] ;
                    ADD[Uy][Ux] = 1 ;
                }
                if(OfUser(Ux, Uy) == 0)
                {
                    Push(Ux, Uy) ;
                }
            }
        }
        if(UserGet == 'd')
        {
            if(Ux < MAPSIZE && Map[Uy][Ux] > 1)
            {
                Temp = Map[Uy][Ux] - 1;
                Map[Uy][Ux] = 1 ;
                Ux ++ ;
                if (ADD[Uy][Ux] == -1)//if it is red
                {
                    if(Temp > Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 1 ;
                        Temp -= Map[Uy][Ux] ;
                        Temp ++ ;
                        Map[Uy][Ux] = Temp ;
                    }
                    else if(Temp == Map[Uy][Ux])
                    {
                        ADD[Uy][Ux] = 0 ;
                        Map[Uy][Ux] = 0 ;
                        Change() ;
                    }
                    else
                    {
                        ADD[Uy][Ux] = -1 ;
                        Map[Uy][Ux] = Map[Uy][Ux] - Temp;
                        Change() ;
                    }
                }
                else
                {
                    Map[Uy][Ux] = Temp + Map[Uy][Ux] ;
                    ADD[Uy][Ux] = 1 ;
                }
                if(OfUser(Ux, Uy) == 0)
                {
                    Push(Ux, Uy) ;
                }
            }
        } 
        if (UserGet == 'e')
        {
            exit(0) ;
        }
        if (UserGet == 'p')
        {
            getch() ;
        }
        if (UserGet == 'h')
        {
            Help() ;
        }
        //UpGame() ;
        /*if (UserGet == 'g')
        {
            GameShow() ;
        }*/
        Set(ltm -> tm_sec) ;
        print() ;
        UpHold() ;
        if (CheckWinIs())
        {
            won = 1 ;
            return ;
        }
        if (CheckLoseIs())
        {
            won = 0 ;
            return ;
        }
    }
}

void Help()
{
    system("cls") ;
    system("type help.txt") ;
    getch() ;
}

void print()
{
    system("cls") ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "Your score:" <<setw(5)<< Uscore << "   Location:(" << Ux << "," << Uy <<")\n" ;
    cout << "-------------Game-------------\n" ;
    Uscore = 0 ;
    for (int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            if(OfUser(j, i)&&ADD[i][j] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                cout << setw(5) << Map[i][j] ;
                Uscore += Map[i][j] ;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
                FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
            }
            else if (ADD[i][j] == -1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
                cout << setw(5) << Map[i][j] ;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
                FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
                cout << setw(5) << Map[i][j] ;
        }
        cout << "\n\n" ;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "------------------------------\n" ;
    cout <<"Press h for help.\n" ;
}

void End()
{
    cout << "Stop!Press any key to stop!\n" ;
    getch() ;
    system("cls") ;
    if (won == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
        FOREGROUND_RED) ;
        cout << "You win!\n" ;
        cout << "Your score is " << Finish() ;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7) ;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
        FOREGROUND_GREEN) ;
        cout << "Sorry!\nYou're lose." ;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7) ;
    }
}

int Finish()
{
    int ans = 0;
    for (int i = 1 ;i <= MAPSIZE ;i ++)
    {
        for (int j = 1 ;j <= MAPSIZE ;j ++)
        {
            ans += Map[i][j] ;
        }
    }
    return ans ;
}

bool quit()
{
    char Get ;
    system("cls") ;
    cout << "Yes?You'll quit?\n" ;
    cout << "Perss 1 to quit and save.\n" ;
    cout << "Press 2 to quit, but don't save.\n" ;
    cout << "Press other key to continue(don't quit).\n" ;
    Get = getch() ;
    if (Get == '1')
    {
        freopen(&Str[0], "w", stdout) ;
        cout << Ux << ' '<< Uy <<'\n' ; 
        cout << num << '\n' ;
        for (int i = 1 ;i <= UserSize ;i ++)
        {
            cout << UserP[i].x << ' ' << UserP[i].y ;
        }
        for (int i = 1 ;i <= MAPSIZE ;i ++)
        {
            for (int j = 1 ;j <= MAPSIZE ;j ++)
            {
                cout << Map[i][j] << ' ' ;
            }
            cout << endl ;
        }
        for (int i = 1 ;i <= MAPSIZE ;i ++)
        {
            for (int j = 1 ;j <= MAPSIZE ;j ++)
            {
                cout << ADD[i][j] << ' ' ;
            }
            cout << endl ;
        }
        fclose(stdout) ;
        return 1 ;
    }
    else
    {
        return 0 ;
    }
}

void GameShow()
{
    system("cls") ;
    system("type game.txt") ;
    getch() ;
}
