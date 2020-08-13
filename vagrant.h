#include "include.h"
using namespace std ;

void Start() ;
void Login() ;
void CreateUser() ;
bool oper(string, string) ;

int num ;
string UserN ;

void Start()
{
    system("cls") ;
    system("title Vagrant") ;
    cout << "Already have an account?\n" ;
    cout << "(Press 1:Log in ;Press 0:Register)\n" ;
    char per ;
    while(1)
    {
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
    cout << n + 1 << endl;
    for (int i = 1 ;i <= n + 1 ;i ++)
    {
        cout << U[i] << endl ;
    }
    fclose(stdout) ;
}

string Un, Uk ;

void Login()
{
    while(1)
    {
        Sleep(100) ;
        system("cls") ;
        cout << "Input your username:>" ;
        getline(cin, Un) ;
        freopen("data/users.txt", "r", stdin) ;
        cin >> num ;
        getline(cin, Uk) ;
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
            cout << "Error!Username can't find.\n";
            cout << "Perss any key to Again\n" ;
            getch() ;
        }
        fclose(stdin) ;
    }

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