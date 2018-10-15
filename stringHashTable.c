#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void init_zero() {
	int i;
	for(i=0;i<HASH_TABLE_SIZE;i++) {
		hash_table[i].count=0;
	}
}
void add(char * tag, int num)
{
	int s=0;
	int i,k;
	for(i=0;i<num;i++) {
		s+=tag[i];
	}
	
	k=s%HASH_TABLE_SIZE;
	
	if(hash_table[k].string!=NULL) {
		if(strcmp(tag,hash_table[k].string)==0) {
			hash_table[k].count++;
		}
		else {
			while(hash_table[k].string!=NULL) {
				k++;
				if(hash_table[k].string!=NULL) {
					if(strcmp(tag,hash_table[k].string)==0) {
						hash_table[k].count++;
						break;
					}
				}
			}
		}
	}
	
	
	
	if(hash_table[k].string==NULL) {
		hash_table[k].count++;
		hash_table[k].string=tag;
	}
	
}

void print() {
	int i;
	for(i=0;i<HASH_TABLE_SIZE;i++) {
		if(hash_table[i].count!=0) {
			printf("%s %d\n",hash_table[i].string, hash_table[i].count);
		}
	}
}

