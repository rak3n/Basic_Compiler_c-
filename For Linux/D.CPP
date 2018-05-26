#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

struct memory
{char name[20];
}mem[20], fmem[20];

void init()
{for(int i=0;i<20;i++)
  {strcpy(mem[i].name,NULL);
   strcpy(fmem[i].name,NULL);
  }
}

int vadd=0, fadd=0;
int errorbit=0, deci=7;//decide whether th func. is global or local
char test[20];
int brace=0;
void braceg(char *str)
{
 if(*str=='}')
   brace--;
 if(*str=='{')
   brace++;
}
void brace_c()
{
 if(brace!=0)
  {if(brace<0)
    errorbit=5;
   else
    if(brace>0)
     errorbit=6;
  }
}

void name_giver(char *);
void create_mem(char []);
void videntifier(char *);
int error(int,char *);

void videntifier(char *str)
{int count=0;
 int check=0;
 char ch;
 strcpy(test,NULL);
 ifstream fin("file.osx");
 if(!fin)
  cout<<"Error. The file is not opening.\n";
 else
  {fin.seekg(0);
   while(fin)
   {fin.get(ch);
    while(*str!='\0')
     {if(*str==ch)
       {check++;
	fin.get(ch);
	str++;
       }
      else
       str++;
      count++;
     }
    str-=count;
    if(error(check,str)==0)
     break;
    else
     check=count=0;
   }
  }
 if(!fin)
  errorbit=1;
 if(str=="void main()")
  errorbit=0;
}

int error(int g,char *str)
{if(g==3 || g==4 || g==5 || g==6 || g==10)
  {name_giver(str);
   return 0;
  }
 else
  return 1;
}

void name_giver(char *str)
{int add=0, chance=0, count=0;
 strcpy(test,str);
 for(int i=0;test[i]!='\0';i++)
  if(test[i]=='(')
    for(int j=i+1;test[j]!='\0';j++)
     if(test[j]==')')
       chance=1;

 if(chance!=1)
  {while(*str!=' ')
    {str++;count++;}
     str++;count++;
    while(*str!=';')
    {if(*str!=' ')
     test[add++]=*str;
    else
    chance=1;
    if(chance==1)
	   if(*str!=';')
	     {errorbit=2;break;}
	 str++;count++;
    }
    str-=count;
    test[add]='\0';
    chance=0;
 for(i=0;test[i]!='\0';i++)
  if(test[i]=='(')
    for(int j=i+1;test[j]!='\0';j++)
     if(test[j]==')')
       chance=1;
   if(chance==0)
     {if(errorbit!=2)
       create_mem(test);}
    else
     {errorbit=3;deci=1;
      for(;*str!='\0';str++,count++)
       if(*str==';')
	 {deci=0;break;}
      str-=count;
      }
 }
 else
 {
   errorbit=3;deci=1;
      for(;*str!='\0';str++,count++)
       if(*str==';')
	 {deci=0;break;}
    str-=count;
 }
}

void create_mem(char str[])
{
 strcpy(mem[vadd++].name,str);
}