#include<iostream.h>
#include<conio.h>
#include<dos.h>

void loadmain()
{
 clrscr();
 gotoxy(28,6);
 cout<<"Digvijay and Rishabh present - ";
 gotoxy(28,8);
 cout<<"\t   COMPILER";
 delay(2000);
 int j;
 for(int i=1;i<65;++i)
 {clrscr();
  highvideo();
  textattr(i);
  textbackground(0);
  gotoxy(28,11);
  cout<<"\t    Loading...";
  for(j=1;j<=i;++j)
   {gotoxy(10+j,12);
    cout<<(char)219;
   }
  delay(30);
 }
 clrscr();
 textbackground(0);
 textattr(1+(1<<1));
}
