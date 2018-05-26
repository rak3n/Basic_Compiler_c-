#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

void graphics()
{int gdriver = DETECT, gmode, errorcode;
 int midx, midy;
 initgraph(&gdriver, &gmode,"../bgi");
 errorcode = graphresult();
 if (errorcode != grOk)
 {cout<<"Graphics error:\n"<< grapherrormsg(errorcode);
  cout<<"Press any key to halt:";
  getch();
  exit(0);
 }
 midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 for(int i=1,j=40;i<=26;++i,j+=10)
 {cleardevice();
  setcolor(i);
  if(j<=160)
  {setfillstyle(j/20,i);
   circle(midx, midy,j);
   fillellipse(midx, midy, j, j);
   circle(midx, midy,j+10);
  }
  else
   {j=40;
    cleardevice();
   }
  //setfillstyle(1,0);
  //pieslice(midx, midy, 0, i, 50);
  //setfillstyle(EMPTY_FILL,0);
  //pieslice(midx, midy, 0, i, 40);
  gotoxy(36,16);
  cout<<" COMPILING";
  delay(100);
 }
 closegraph();
}

