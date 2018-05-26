#include<iostream.h>
#include<conio.h>
#include<dos.h>

union REGS in,out;

int call_mouse()
{
 in.x.ax=0;
 return 1;
}

void show_mouse()
{
 in.x.ax=1;
 int86(51,&in,&out);
}

void get_mouse(int &xpos,int &ypos,int &click)
{
 in.x.ax=3;
 int86(51,&in,&out);
 click=out.x.bx;
 xpos=out.x.cx;
 ypos=out.x.dx;

}

