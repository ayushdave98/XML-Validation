#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern int pop();
extern int isEmpty();
extern void push(char*);
extern void add(char*,int num);
extern void init_zero();
extern void print();

void zero(char arr[]) {
	int i;
	for(i=0;i<100;i++) {
		arr[i]=NULL;
	}	   
}

int main(int argc, char * argv[])
{
  int ch;
  char temp[100]={0};
  char *temp2;
  char *temp3;
  int t2;
  t2=0;
  int f=0;
  init_zero();

  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;

    if(ch=='<') {
	//printf("<     %d\n",f);
	f++;
	continue;
    }

    if(f==1) {
		if(ch=='/') {
		//printf("/    %d\n",f);
		f++;
		continue;
	    }
	
		else if(isalpha(ch)) {
		//printf("alpha    %d\n",f);
		temp[t2]=(char)ch;
		//printf("Array %c\n",temp[t2]);
		t2++;
		continue;
	    }
		
		else if(f==1 && ch=='>') {
		//printf(">%d\n",f);
		temp2=(char*)malloc(t2*sizeof(char));
		strcpy(temp2,temp);
		//printf("String:       %s\n",temp2);
		push(temp2);
		add(temp2,t2);
		f=0;
		t2=0;
		zero(temp);
		continue;
		}
    }

    if(f==2) {
		if(isalpha(ch)) {
		//printf("alpha   %d\n",f);
		temp[t2]=(char)ch;
		//printf("Array %c\n",temp[t2]);
		t2++;
		continue;
		}
	
		if(ch=='>') {
		//printf(">        %d\n",f);
		f=0;
		temp2=(char*)malloc(t2*sizeof(char));
		strcpy(temp2,temp);
		temp3=(char*)malloc(t2*sizeof(char));
		strcpy(temp3,pop());
		//printf("String:       %s\n",temp3);
			if(strcmp(temp3,temp2)!=0){
			printf("Invalid");
			exit(1);
			}
		t2=0;
		zero(temp);
		continue;
		}
   }	   
  }
  
if(isEmpty()==1) {
	printf("valid\n");
	print();
	exit(0);
}
if(isEmpty()==0) {
	printf("Invalid");
}
  exit(1);
}

