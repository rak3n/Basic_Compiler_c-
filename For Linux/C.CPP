#include"d.cpp"

int chance=0;
int returner;

void fidentifier(char *);
void name_giver2(char *);
void create_mem2(char []);
int error2(int ,char *);

void evaluate()
{int j;
 for(int i=0;test[i]!=' ';i++);
 test[i++];
 j=0;
 while(test[i]!=';')
  test[j++]=test[i++];
 test[j]='\0';
}

void main_checker(char dub[]="main()")
{errorbit=4;
 for(int i=0;i<fadd;i++)
  {if(strcmp(fmem[i].name,dub)==0)
    {errorbit=0;break;}
  }
}

void c(char *str)
{deci=7;
 videntifier(str);
 if(deci!=7)
  {
    if(deci==1)
       {fidentifier(str);}
     else
       {errorbit=0;evaluate();create_mem2(test);}
  }
}

/*
void main()
{ clrscr();
  char *str;
  gets(str);
  videntifier(str);
  if(deci!=7)
  {
  if(deci==1)
   fidentifier(str);
  else
   {create_mem2(test); errorbit=0; }
  }
  cout<<errorbit;
  cout<<fmem[0].name;
  main_checker();
  cout<<errorbit;
  getch();
}*/

void fidentifier(char *str)
{int count=0;
 int check=0;
 char ch;
 if(errorbit==3)
 {char val[15];int g=0;
 for(;*str!=' ';str++)
  {count++;val[g++]=*str;}
 if((strcmp(val,"int")==0)||(strcmp(val,"float")==0)||(strcmp(val,"char")==0)||(strcmp(val,"double")==0)||(strcmp(val,"long double")==0))
  {returner+=1;}
 str-=count;count=0;
 errorbit=0;
 ifstream fin("file2.osx");
 {fin.seekg(0);
 while(fin)
 {fin.get(ch);
  while(*str!='\0')
   {
    if(*str==ch)
     {check++;fin.get(ch);str++;}
    else
     str++;
     count++;
   }
  str-=count;
  if(error2(check,str)==0)
    {break;}
  else
   {check=count=0;}
 }
 if(!fin)
  {errorbit=1;}
 }
}
}

int error2(int g,char *str)
{
 if(g==6||g==7||g==8||g==11||g==9)
  {name_giver2(str);return 0;}
 else
   {return 1;}
}

void name_giver2(char *str)
{char test2[20];
 int add=0,count2=0;
 while(*str!=' ')
  {str++;count2++;}
 str++;count2++;
 while(*str!='\0')
  {if(*str!=' ')
    {test2[add++]=*str;str++; }
   else
   str++;
   count2++;
   }
 str-=count2;
 test2[add]='\0';
 create_mem2(test2);
 chance=1;
}

void create_mem2(char str[])
{
 strcpy(fmem[fadd++].name,str);
}