#include"c.cpp"
#include"inc.cpp"
#include"type.cpp"
#include"graph.cpp"

char text[80];
int liner=0;
int line_teller=0;
int exist=0;
char cha[20];

void assign(int &a,char f)//ASSIGNS A CHARACTRISED NUMBER TO AN INTEGER VARIABLE
{switch(f)
 {case '1':a=1;break;
  case '2':a=2;break;
  case '3':a=3;break;
  case '4':a=4;break;
  case '5':a=5;break;
  case '6':a=6;break;
  case '7':a=7;break;
  case '8':a=8;break;
  case '9':a=9;break;
  case '0':a=0;break;
 }
}

void head_check()
{char c[80], dir[10], file[20];
 int r=0, ret=0, plot=0, put_check, val=0 ,k=0;
 for(int dr=0;cha[dr]!='\0';dr++)
   if(cha[dr]==')' && cha[dr+1]!=';')
    {errorbit=2;
     break;
    }
 if(errorbit!=2)
 {ifstream read;
 for(int d=0;d<h_f;d++)
  {strcpy(file,store_h_f[d]);
   read.open(file);
   if(!read)
    errorbit=10;
   else
    {read.seekg(0);
     while(!read.eof())
     {read.getline(c,80,'\n');
      do
       {if(isalpha(c[r])||c[r]=='('||c[r]==')'||c[r]==';')
	 dir[ret++]=c[r];
	if(isdigit(c[r]))
	 assign(val,c[r]); r++;
       }while(c[r]!='\0');
      dir[ret]='\0';
      for(ret=0;dir[ret]!='(';ret++);
       ret++;
      if(dir[ret]!=')')
       put_check=1;
      else
       put_check=0;
      for(ret=0;dir[ret]!='\0';ret++)
       if(dir[ret]==cha[k++])
	plot++;
      if(put_check==0)
       {if(plot==val)
	 {errorbit=0;goto close;}}
       else
	{if(plot>=val)
	  {errorbit=0;goto close;}}
	   plot=val=ret=r=k=0;
	  }
	 read.close();
	}
     }close:
  }
}

void ticker()
{char bin[20];
 int len;
 if(errorbit==1)
  {int h=0;
   for(h=0;cha[h]!='\0';h++)
    if(cha[h]=='(')
      goto f;
   for(int i=0;i<vadd;i++)
     {strcpy(bin,mem[i].name);
      len=strlen(bin);
      bin[len]=';';bin[len+1]='\0';
       if(strcmp(cha,bin)==0)
	 {errorbit=0;goto k;}
      }i=0;
      while(cha[i++]!='\0')
       if(cha[i]!=' ')
	errorbit=7;
       else
	break;
 }
 if(errorbit==3)
  {f:
   for(int i=0;i<vadd;i++)
     {strcpy(bin,fmem[i].name);
      len=strlen(bin);
      bin[len]=';';bin[len+1]='\0';
       if(strcmp(cha,bin)==0)
	 {errorbit=0;goto k;}
      }i=0;
      while(cha[i++]!='\0')
       if(cha[i]!=' ')
	errorbit=8;
       else
	break;
  }
 k:
}

void passer()
{cout<<"ENTER THE FILE NAME TO COMPILE:- ";
 gets(text);
 //////////////////////////////DECORATIVE CODE///////////////////////////////
 cout<<"\n";
 for(int k=0;k<39-(strlen(text)/2);k++)
    cout<<"-";
 cout<<text;
  for(int l=0;l<=k;l++)
    cout<<"-";
///////////////////////------------------------------/////////////////////////
 cout<<"\n";
 ifstream fin;
 fin.open(text);
 ofstream fout;
 fout.open("passer.txt");
 if(!fin)
  {cout<<":::FILE DOES'NT EXIST:::";
   getch();
   exist=1;
  }
 else
 {graphics();
  clrscr();
  //////////////////////////////DECORATIVE CODE///////////////////////////////
  cout<<"\n";
  for(int k=0;k<39-(strlen(text)/2);k++)
   cout<<"-";
  cout<<text;
  for(int l=0;l<=k;l++)
   cout<<"-";
  ///////////////////////------------------------------/////////////////////////
  if(!fout)
   cout<<"OUT OF MEMORY\n";
  else
   {fin.seekg(0);
    while(!fin.eof())
    {fin.getline(text,80,'\n');
     for(int g=0;text[g]!='\0';g++)
      {if(text[g]=='{')
       {if(text[g+1]=='{')
	 {fout<<"\n";
	  fout<<text[g];
	  line_teller++;
	 }
	else
	 {fout<<"\n";
	  fout<<text[g];
	  fout<<"\n";
	  line_teller++;
	 }
       }
       else
	if(text[g]=='}')
	 {fout<<text[g];
	  fout<<"\n";
	  line_teller++;
	 }
	else
	 if(text[g]==';')
	  {fout<<text[g];
	   fout<<"\n";
	   line_teller++;
	  }
	 else
	  if(strcmp(text," ")==0)
	   continue;
	  else
	   if(text[g]=='r'&&text[g+1]=='e'&&text[g+2]=='t'&&text[g+3]=='u'&&text[g+4]=='r'&&text[g+5]=='n')
	    {--returner;
	     fout<<text[g];
	    }
	   else
	    if(text[g]=='>'&&text[g+1]!='>')
	     {fout<<text[g]<<"\n";
	      line_teller++;
	     }
	    else
	     fout<<text[g];
       }
     }
    }
 }
}

void error_check()
{ofstream f_r;
 f_r.open("error.dat",ios::app);
 if(f_r)
 {ticker();
  if(errorbit==8) //THIS IS TO CHECK MAIN FUNCTION...
   {main_checker(cha);
    if(errorbit!=0)
     errorbit=8;
   }
  if(errorbit==8) //THIS IS TO CHECK INCLUDED HEADER FILES PRE DEFINED FUNCTIONS
   head_check();
  switch(errorbit)
   {case 1:f_r<<"*Error "<<text<<" "<<liner<<": Declaration syntax error in line:\n";  break;
    case 3:f_r<<"*Error "<<text<<" "<<liner<<": Declaration syntax error in line:\n";  break;
    case 2:f_r<<"*Error "<<text<<" "<<liner<<": Declaration missing ; in line:\n";     break;
    case 4:f_r<<"*Error "<<text<<" "<<liner<<": Main function missing IN THE MODULE\n";     break;
    case 5:f_r<<"*Error "<<text<<" "<<liner<<": Expected {\n";           break;
    case 6:f_r<<"*Error "<<text<<" "<<liner<<": Expected }\n";           break;
    case 7:f_r<<"*Error "<<text<<" "<<liner<<": Variable Declaration missing\n";break;
    case 8:f_r<<"*Error "<<text<<" "<<liner<<": Function prototype missing \n";break;
    case 10:f_r<<"*Error "<<text<<" "<<liner<<": Included file does not exist\n";break;
    default:break;
   }
 }f_r.close();
}

void read_error()
{
 ifstream fin;
 fin.open("error.dat");
 if(fin)
 {char stru[80];
  fin.seekg(0);
  while(!fin.eof())
  {
  fin.getline(stru,80,'\n');
  cout<<stru<<"\n";
  }
 }
 else
  cout<<"SUCCESS";
 fin.close();

}

void make()   //CONVERT MAKE TO MAIN TO USE THIS FILE.....
{clrscr();
 brace=0;
 returner=0;
 liner=0;
 line_teller=0;
 char *str;
 passer();
 if(exist==1)
   goto l;
 if(line_teller!=0)
 {ifstream fin;
 fin.open("passer.txt");
 if(!fin)
  cout<<"error";
 else
  {fin.seekg(0);
   while(line_teller!=0)
    {m:
     fin.getline(cha,20,'\n');
     liner++;
     str=cha;
     cout<<str<<"\n";
     for(int h=0;cha[h]!='\0';h++)
     {if(cha[h]=='#'||(cha[h]=='<'&&cha[h+1]!='<')||(cha[h]=='>'&&cha[h+1]!='>'))
      {con(cha,liner);
	  if(rt==1)
	     { getch();goto l;}
       goto b;
      }
     }
    if(*str=='}'||*str=='{')
      braceg(str);
    else
     {
     c(str);
     error_check();
     }
     if(deci==1)
	{fin.getline(cha,20,'\n');
	 cout<<str<<"\n";liner++;
	 if(*str!='{')
	  {errorbit=3;error_check();}
	 else
	  braceg(str);
	 }
     if(errorbit!=0)
       break;
     b:
     line_teller--;
    }
   if(errorbit==0)
   {brace_c();error_check();
       if(errorbit==0)
	{main_checker();
	    error_check();}}
  }
 if(returner!=0)
 {cout<<"\n        ----------------------------WARNING-----------------------------\n";
 if(returner>0)
  cout<<"RETURN STATEMENT MISSING IN "<<returner<<" RETURNING FUNCTIONS\n";
 else
  cout<<"RETURN STATEMENT USED IN AN NON-RETURNING FUNCTION\n";
 }
 if(line_teller!=0)
  {
  errorbit=0;
  line_teller--;
  goto m;}
 /*if(errorbit==0)
  {int point=0;
   fin.seekg(0);
   while(fin)
   {
    fin.getline(cha,20,'\n')
     for(i=0;cha[i]!='\0';i++)
      if(cha[i]==')'||cha[i]=='(')
       point++;
     if(point==2)
       variable_exist_checker(cha);
    }
  }*///WORK IN PROGRESS :)
 if(errorbit==0)
   {cout<<"\n\nSUCCESS...........................................";
   remove("error.dat");
   }
 else
   {
   cout<<"\n        ----------------------------ERRORS-----------------------------\n";
   read_error();
   }
 fin.close();
 }
 getch();
 l:
 remove("error.dat");
}