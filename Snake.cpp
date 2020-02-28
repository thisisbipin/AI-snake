#include<windows.h>
#include<iostream> 
#include<fstream>
#include<conio.h> 
#include<iomanip> 
#include<dos.h> 
#include<math.h> 
#include<ctype.h> 
#include<string.h> 
#include<stdio.h> 
#include<process.h> 
#include<stdlib.h> 
#include<time.h> 
using namespace std;
void board();
void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
int main()
{
    
    int a=2,b=2,t=120,n,x,y;
    char jump,c='o',name[10],ch='*'; //c=4 i.e) 4th ASCII character that is a diamond
    system("cls");  board();
    int score=-1; //-1 so that initial score = 0
    gotoxy(a,b); 
    cout<<ch; 
    jump=getch(); 
    position: 
    x=rand()%77+3;
    y=rand()%22+3; //this determines the position of food to be eaten
    ++score;//for score 
    do { while(!kbhit()) 
            {       system("cls"); 
                //sound(random(500)); 
                board(); 
                gotoxy(20,25); 
                cout<<"SCORE : "<<score<<" If you want to exit press 0.";
                gotoxy(a,b); //to create movement of ch 
                cout<<ch;
                gotoxy(x,y);//for position of food
                cout<<c; 
                if( (a==1&&(b>=1&&b<=25)) || (a==80&&(b>=1&&b<=24)) ||  (b==1&&(a>=1&&a<=80)) || (b==24&&(a>=1&&a<=80)) ) 
                    goto end; //Condition so that user should be out if he hits the wall. /*-------Movement of cursor--------------*/
                if(jump==72 || jump=='w' || jump=='W') --b; //move turtle up
                    else if(jump==80 || jump=='s' || jump=='S') ++b; //move turtle down
                    else if(jump==77 || jump=='d' || jump=='D') ++a; //move turtle right
                    else if(jump==75 || jump=='a' || jump=='A') --a; //move turtle left
                    else if(jump=='0') goto end;
                if(a==x&&b==y) 
                    goto position; //if turtle feeds the food must get on new position
                Sleep(t);
            }
                jump=getch();
        } while(jump!='0');

end: gotoxy(35,12); cout<<"GAME OVER ,SCORE : " <<score;
   
    return 0;
}

void board()
{
   cout<<"+-------------------------------------------------------------------------------+\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"|                                                                               |\n";
   cout<<"+-------------------------------------------------------------------------------+\n";
}
