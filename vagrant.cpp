#include "include.h"
#include "vagrant.h"
using namespace std ;

int main()
{
	system("color 0f") ;
    Start() ;
    char UserChoose ;
    while(1)
    {
    	system("cls") ;
    	cout << "Input the mode you want to play.\n" ;
    	cout << "Press 1:The empty Map\n" ;
    	cout << "Press 2:The Map with cities\n" ;
    	cout << "Press e:Qiut\n" ;
    	UserChoose = getch() ;
    	system("cls") ;
    	switch(UserChoose)
    	{
    		case '1':
    			{
    				memset(Map, 0, sizeof(Map)) ;
    				memset(City, 0, sizeof(City)) ;
    				cout << "Empty Map!\n" ;
    				GetSize() ;
    				Run1() ;
    				End() ;
    				getch() ;
    				break ;
				}
			case '2':
				{
					memset(Map, 0, sizeof(Map)) ;
    				memset(City, 0, sizeof(City)) ;
					cout << "City War!\n" ;
					GetSize() ;
					Run2() ;
    				End() ;
    				getch() ;
    				break ;
				}
			case 'e':
				{
					exit(0) ;
				}
		}
	}
    return 0 ;
}
