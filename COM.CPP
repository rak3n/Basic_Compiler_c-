#include"mouse.cpp"
#include"main.cpp"
#include"loading.cpp"
#include<stdlib.h>

char array[]={'>>','<<','%',')','(','^','!','*',',','{','}',';','+','=','||','@','$','#','"',':','-' };
class UI
{int j,i;
 public:
 UI()
 {i=j=0;}

 void animate();
 void about();
 void credits();
 void compile()
  {
   make();
   cout<<" \n\n\n              ................PRESS ANY KEY TO QUIT................";
   getch();
  }
};
void UI::animate()
 {int j;
  for(i=0;i<40-5;i++)
  { j=random(21);cout<<array[j]<<" ";}
 }

void UI::about()
{for(i=0;i<30;i++)
    cout<<" ";
   cout<<":::C++ COMPILER:::";
   cout<<"\n\n\n";
   cout<<"THIS BETA C++ COMPILER IS VERY BASIC VERSION OF ORIGINAL C++ COMPILER. TILL NOW IT ONLY INCLUDES NON_PARAMETRISED FUNCTION CREATION AND VARIABLE INITIALIZATION CHECKING AND OTHER STUFFS ,BUT SOON MORE FEATURES SHALL BE ADDED.\n";
   cout<<"\n\nHOW TO COMPILE A PROGRAMME FILE?\n";
   cout<<"\n1.To compile a programme edit it in a file and save it in ''../Turboc3/tc/bin/'' directory (through notepad or gedit).";
   cout<<"\n\n2.Now click on 'COMPILE A PROGRAMME' dialoge box";
   cout<<"\n\n3.Then enter the name of the file with extension(like .txt)";
   cout<<"\n\n4.Correspoding error shall be raised by the compiler if any..";
   cout<<"\n\n\n         THANK YOU.....";
   cout<<" \n\n\n              ................PRESS ANY KEY TO QUIT................";
   getch();
  }

void UI::credits()
{
 for(i=0;i<30;i++)
   cout<<" ";
 cout<<":::C++ COMPILER:::";
 cout<<"\n\n                      THIS C.S. PROJECT IS CREATED BY:- \n\n";
 cout<<"                              1. RISHABH KUMAR\n";
 cout<<" \n\n\n              ................PRESS ANY KEY TO QUIT................";
 getch();
}

void main()
{highvideo();
 clrscr();
 char ch;
 loadmain();
 int x,y,c;
 UI W;
 call_mouse();
 while(!kbhit())
 {
 clrscr();
 randomize();
 show_mouse();
 for(int i=0;i<30;i++)
   cout<<" ";
 cout<<":::C++ COMPILER:::";
 cout<<"\n";
 for(i=0;i<45;i++)
   cout<<" ";
   cout<<"      ";
 for(i=0;i<8;i++)
   cout<<"\n";
 for(i=0;i<28;i++)
   cout<<" ";
 cout<<"--COMPILE A PROGRAMME--\n";
 for(i=0;i<28;i++)
   cout<<" ";
   cout<<"---ABOUT THE COMPILER---\n";
 for(i=0;i<34;i++)
   cout<<" ";
   cout<<"--CREDITS--";
 cout<<"\n\n\n";
 cout<<"    ";
 W.animate();
 cout<<" \n\n\n                  HOLD CLICK ANY OPTION FOR 2 SECONDS TO CONTINUE \n                            OR PRESS ANY KEY TO QUIT";
  delay(500);
 get_mouse(x,y,c);
 if((x>=231&&x<=415)&&(y>=80&&y<=86))
    if(c==1)
     {clrscr();W.about();}
 if((x>=254&&x<=377)&&(y>=89&&y<=94))
   if(c==1)
      {clrscr();W.credits();}
 if((x>=226&&x<=403)&&(y>=73&&y<=79))
  if(c==1)
   {clrscr();
    W.compile();
   }
 }
 getch();
 normvideo();
}
