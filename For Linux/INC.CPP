#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
int err=0,i,h_f=0, j, intid=0, floatid=0, charid=0, rt=0, lineno,cnt;
char stre[20], nm[20], ch[20], A[20], che[20], store_h_f[10][10];
char inti[10][10], floati[10][10], chari[10][10];
char all_h_f[][12]={"pre.h","conio.h","stdio.h","ctype.h","string.h",
	"fstream.h","math.h","iomanip.h","stdlib.h","graphics.h"};
char all_dat_typ[][8]={"int","char","float","double"};

int check_h_f(char stre[])
{for(i=0;i<10;i++)
  {
   if(strcmp(all_h_f[i],stre)==0)
   return 1;
  }
 return -1;
}


void special_char(char che)
{ofstream fout;
 fout.open("error.dat",ios::app);
 if(!fout)
  cout<<"Error.";
 else
  {switch(che)
   {case '@':fout<<"*Error "<<nm<<" "<<lineno<<":Illegal character '@' (0x40)\n";
	     break;
    case '$':fout<<"*Error "<<nm<<" "<<lineno<<":Illegal character '$' (0x24)\n";
	     break;
    case '`':fout<<"*Error "<<nm<<" "<<lineno<<":Illegal character '`' (0x60)\n";
	     break;
    case '&':fout<<"*Error "<<nm<<" "<<lineno<<":Reference variable must be initialised ' 'Illegal character '&' (0x24)\n";
	     break;
    case '#':fout<<"*Error "<<nm<<" "<<lineno<<":Illegal character '#' (0x23)\n";
	     break;
    case '\\':fout<<"*Error "<<	nm<<" "<<lineno<<":Illegal character '\' (0x5c)\n";
	      break;
    default :fout<<"*Error "<<nm<<" "<<lineno<<":Declaration terminated incorrectly\n";
   }
   fout.close();
  }
}

void check_apostreophe(char stre[])
{ofstream fout;
 fout.open("error.dat",ios::app);
 if(!fout)
  cout<<"Error.";
 else
  {int i=1;
   while(stre[i]!='\0')
    {if(stre[i]=='\'')
      break;
    }
   if(stre[i]!='\0')
    {int j=0;
     while((stre[i]!='\0') && (stre[i]=='\''))
      che[j++]=stre[i++];
     che[j]='\0';
     if(stre[i]=='\0')
      fout<<"*Error "<<nm<<" "<<lineno<<": Unterminated streing or character constant\n";
     if(strlen(che)>2||strlen(che)==0)
      fout<<"*Error "<<nm<<" "<<lineno<<": Character constant must be one or two characters long\n";
    }
   fout.close();
  }
}


void store_headerfile(char stre[])
{
 strcpy(store_h_f[h_f++],stre);
}


void check_headerfile(char stre[])
{ofstream fout;
 fout.open("error.dat",ios::app);
 if(!fout)
  cout<<"Error. The  file is not opening.";
 else
  {rt=0;
   if(stre[0]!='#')
    {if(isalpha(stre[0]))
      {check_apostreophe(stre);
       fout<<"*Error "<<nm<<" "<<lineno<<": Declaration syntax error\n";
      }
     else
      {if(isdigit(stre[0]))
	fout<<"*Error "<<nm<<" "<<lineno<<": Declaration terminated incorrectly\n";
       else
	{special_char(stre[0]);
	 fout<<"*Error "<<nm<<" "<<lineno<<": Declaration terminated incorrectly\n";

	}
      }
     rt=i=1;
     while(stre[i]!='\0')
      if(!isalpha(stre[i]) && !isdigit(stre[i]))
       special_char(stre[i++]);
     goto l1;
    }
   else
    {i=1;
     if(!isalpha(stre[i]))
      {fout<<"*Error "<<nm<<" "<<lineno<<": Unknown preprocessor directive: '' \n";
       rt=3;
       goto l1;
      }
     else
      {j=0;
       while(stre[i]!='\0'&& isalpha(stre[i]))
	{if(stre[i]=='<')
	   break;
	 ch[j++]=stre[i++];
	 }ch[j]='\0';
       if(strcmp(ch,"include")!=0)
	{fout<<"*Error "<<nm<<" "<<lineno<<": Unknown preprocessor directive: '"<<ch<<"' \n";
	 rt=4;
	 goto l1;
	}
       else
	{if(stre[i]!='<'&& stre[i]!='\0')
	  {fout<<"*Error "<<nm<<" "<<lineno<<": Bad file name format in include directive  \n";
	   rt=5;
	   goto l1;
	  }
	 else
	  {j=0;int g=0;
	   while(stre[i]!='\0' && stre[i]!='>')
	    ch[j++]=stre[i++];
	    ch[j]='>';ch[j+1]='\0';
	   if(stre[strlen(stre)-1]=='>')
	    {char ch2[14];
	     for(int h=0;ch[h]!='\0';h++)
	      {
	       if(ch[h]!='>'&&ch[h]!='<')
		 {ch2[g++]=ch[h];}
	      }
	     ch2[g]='\0';
	     strcpy(ch,ch2);
	     if(check_h_f(ch)!=1)
	      {fout<<"*Error "<<nm<<" "<<lineno<<": Unable to open include file '"<<ch<<"' \n";
	       rt=6;
	      }
	    }
	   else
	    {if(stre[i]!='\0')
	      fout<<"*Error "<<nm<<" "<<lineno<<": Unable to open include file '"<<ch<<"' \n";
	     else
	      fout<<"*Error "<<nm<<" "<<lineno<<": No file name ending \n";
	    }
	  }
	}
      }
    }
   l1:
   fout.close();
  }
 if(rt==0)
  store_headerfile(ch);
}

void include_checker(char stre[],int k)
{cnt=0;
 lineno=k;
   if(stre[0]=='#')
    cnt+=12;
   for(i=0;stre[i]!='\0';++i)
    {if(stre[i]=='<'||stre[i]=='>'||stre[i]=='.'||stre[i]=='h')
      cnt+=1;
     else
      {if(stre[i]=='i')
	{while(stre[i]!=0&&isalpha(stre[i]))
	  ch[k++]=stre[i++];
	 ch[k]='\0';
	 if((strcmp(ch,"inc")==0)||(strcmp(ch,"incl")==0))
	  cnt+=3;
	 else
	  {if((strcmp(ch,"inclu")==0)||(strcmp(ch,"inclu")==0))
	    cnt+=4;
	   else
	    {if((strcmp(ch,"includ")==0)||(strcmp(ch,"include")==0))
	      cnt+=6;
	    }
	  }
	}
      }
    }
   if(cnt>=12)
    check_headerfile(stre);
}
void functionmain1()
{ifstream fin;
 fin.open("error.dat");
 if(!fin)
  cout<<"Error.";
 else
  {fin.seekg(0);
    fin.getline(stre,80,'\n');
     if(stre[i]>='A' && stre[i]<='Z')
      err=1;
   fin.close();
  }
}

void con(char strr[],int lin0)
{
 include_checker(strr,lin0);
 functionmain1();
}