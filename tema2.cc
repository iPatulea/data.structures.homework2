/*Patulea Ionut
313CA*/
#include <iostream>
#include "hibrid.h"
#include "history.h"
#include <stdio.h>
#include <string.h>
int main()
{
	
	char *command,*URL,*FILE_NAME;
	int INDEX,NO_DAYS,nr;
	command=new char[100];
	URL=new char[100];
	FILE_NAME=new char[100];
	scanf("%d",&nr);
	history B(nr);
	while(fscanf(stdin,"%s",command)==1)
	{
		if(!strcmp(command,"DAY_PASSES")){
			B.DAY_PASSES();
			continue;
		}
		if(!strcmp(command,"ACCESS_PAGE")){
			scanf("%s",URL);
			B.ACCESS_PAGE(URL);
			continue;
		}
		if(!strcmp(command,"CLEAR_RECENT_HISTORY")){
			scanf("%d",&NO_DAYS);
			B.CLEAR_RECENT_HISTORY(NO_DAYS);
			continue;
		}
		if(!strcmp(command,"SET_MAX_DAYS")){
			scanf("%d",&NO_DAYS);
			B.SET_MAX_DAYS(NO_DAYS);
			continue;
		}
		if(!strcmp(command,"SHOW_ENTRY")){
			scanf("%d",&INDEX);
			B.SHOW_ENTRY(INDEX);
			continue;
		}
		if(!strcmp(command,"DELETE_ENTRY")){
			scanf("%d",&INDEX);
			B.DELETE_ENTRY(INDEX);
			continue;
		}
		if(!strcmp(command,"SHOW_HISTORY")){
			B.SHOW_HISTORY();
			continue;
		}
		if(!strcmp(command,"RECOVER_HISTORY")){
			scanf("%s",FILE_NAME);
			B.RECOVER_HISTORY(FILE_NAME);
			continue;
		}
	}
	delete FILE_NAME;
	delete URL;
	delete command;
	return 0;
}
