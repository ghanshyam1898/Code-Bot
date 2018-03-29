/* THIS PROGRAM IS SPEIAL BECAUSE IT CAN RUN FILES DIRECTLY FROM THEIR SOURCE
   CODE. NO NEED TO CREATE AN EXECUTABLE FILE. THIS IS VERY BENIFITIAL
   TO RUN LARGE APPLICATIONS IN WEAK(SMALL) PROCESSORS.*/






#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>



int code_found(char []);
int length=0,true_var=0,var_add;
char var_list[100];
int var_value[100];
char code_info[30],var_name[30];








void main()
{


clrscr();
cout<<"\t\t\t";

//VARIABLE DECLARATION


char a,start[19]="Welome to CODE BOT",log_read[30],ch[2], name[30],code[100],student_name[30];
int cp1=0,cp2=0;
textcolor(6);

//DISPLAYS WELCOME NOTE GRAPHICALLY

for(int i=0;i<19;i++)
	{
		cout<<start[i];
		delay(100);
	}

clrscr();


//SHOWS LOADING GRAPHICALLY

fstream file("code.txt",ios::in|ios::out|ios::nocreate|ios::noreplace);
fstream log("log.txt",ios::in|ios::out|ios::nocreate|ios::noreplace);


for(i=0;i<15;i++)
	{
		cout<<"\t\t\tWelome to CODE BOT\n\nPlease wait till the program loads |";
		delay(100);
		clrscr();
		cout<<"\t\t\tWelome to CODE BOT\n\nPlease wait till the program loads /";
		delay(100);
		clrscr();
		cout<<"\t\t\tWelome to CODE BOT\n\nPlease wait till the program loads \\";
		delay(100);
		clrscr();
	}

//INSERTS NULL IN ARRAYS. IT IS REQUIRED DUE TO PROGRAM LOGIC.



for(int p=0;p<30;p++)
	{
		code_info[p]=NULL;
	}
for(p=0;p<100;p++)
	{
		var_list[p]=NULL;
		var_value[p]=NULL;
	}

cout<<"\t\t\t\tCODE BOT\n\n";


if(log.bad())
	{
	cout<<"\n\nSome important program files missing. Please reinstall the application.";
	getch();
	exit(1);
	}


if(file.bad())
	{
		cout<<"\n\nFile not found.\nPlease enter a valid file name.";
		getch();
		exit(1);
	}



//THIS CODE BLOCK FINDS LINES OF CODE ONE-BY-ONE IN THE SOURCE CODE FILE
//AND PASSES IT FOR FURTHER PROCESSING.

//(IT IS ONE OF THE MOST IMPORTANT PART OF MY PROGRAM.)


//THIS IS THE {{{  HEART  }}} OF MY PROGRAM. IT MEANS THAT IT CONTROLS THE FLOW
//OF LINES OF CODE.



for(long int j=0;!file.eof();j++)
	{
		file.seekg(j,ios::beg);
		file.getline(ch,2);
		if(strcmp(ch,"<")==0)
			cp1=j;
		else if(strcmp(ch,">")==0)
			cp2=j;
		if(cp2>cp1)
			{
				length=cp2-cp1;
				file.seekg((cp1+1),ios::beg);
				file.getline(code,length);
				code_found(code);
			}
	}

cout<<"\n\n\n\n\n***Program exeution complete***";
log.close();
file.close();

getch();
}

//THIS IS THE {{{  BRAIN  }}} OF MY PROGRAM. IT PROCESSES THE CODE AND TRIGGERS OUTPUT.



int code_found(char code[])
{

for(int p=0;p<4;p++)
	{
		code_info[p]=code[p];
	}

if(strcmp(code_info,"look")==0)
	{
		for(int k=4;k<strlen(code);k++)
			{
				if(code[k]=='#')
				{
				cout<<endl;
				k++;
				}
				cout<<code[k];
			}
	}
else if(strcmp(code_info,"wait")==0)
	{
		getch();
	}
else if(strcmp(code_info,"data")==0)
	{
	 var_list[true_var]=code[5];
	 cin>>var_value[true_var];
	 true_var++;
	}
else if(strcmp(code_info,"plus")==0)
	{
	int sum=0;

		for(int k=0;var_list[k]!=NULL;k++)
			{
			if(var_list[k]==code[5])
			break;
			}
	sum=sum+var_value[k];

		for(k=0;var_list[k]!=NULL;k++)
			{
			if(var_list[k]==code[7]);
			break;
			}
	sum=sum+var_value[k+1];
	cout<<"\nRequired sum is : "<<sum;
	}
else if(strcmp(code_info,"into")==0)
	{
	int into=1;

		for(int k=0;var_list[k]!=NULL;k++)
			{
			if(var_list[k]==code[5])
			break;
			}
	into=into*var_value[k];

		for(k=0;var_list[k]!=NULL;k++)
			{
			if(var_list[k]==code[7]);
			break;
			}
	into=into*var_value[k+1];
	cout<<"\nRequired multiplication is : "<<into;
	}

return 0;

}