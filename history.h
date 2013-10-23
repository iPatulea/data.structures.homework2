/*Patulea Ionut
313CA*/
#include <stdio.h>
#include <string.h>
class history{
private:
	LinkedList<URL> *Q;
	int Day,mdays,size;
public:
	history(int nr){
		Q=new LinkedList<URL>(nr);
		Day=0;
		mdays=30;
		size=0;
	}
	void DAY_PASSES(){
		Day++;
		if (size==0)
			return;
		while( ( Day - Q->back().day ) >= mdays )
		{
			size--;
			Q->pop_back();
		}
	}
	void ACCESS_PAGE(char* ADD){
		URL foo;
		foo.day=Day;
		//aloc memorie separat sa nu intervina modificarea valorii.
		char* ADDU=strdup(ADD);
		foo.url=ADDU;
		Q->push_front(foo);
		size++;
	}
	void CLEAR_RECENT_HISTORY(int NO_DAYS){
		URL foo;
		int i;
		if (size==0)
			return;
		foo=Q->front();
		i=Day-foo.day+1;
		while(i<=NO_DAYS && size>0)
		{
			Q->pop_front();
			size--;
			if (size==0)
				break;
			foo=Q->front();
			i=Day-foo.day+1;
		}
	}
	void SET_MAX_DAYS(int NO_DAYS){
		if (size==0)
			return;
		while( ( Day - Q->back().day ) >= NO_DAYS )
		{
			size--;
			Q->pop_back();
		}
		mdays=NO_DAYS;
	}
	void SHOW_ENTRY(int INDEX){
		URL foo;
		fprintf(stdout,"ENTRY %d:\n",INDEX);
		foo=Q->get(INDEX);
		fprintf(stdout,"%d %s\n",foo.day,foo.url);
	}
	void DELETE_ENTRY(int INDEX){
		Q->erase(INDEX);
		size--;
	}
	void SHOW_HISTORY(){
		fprintf(stdout,"HISTORY:\nCurrent day: %d\n",Day);
		URL foo;
		for (int i=0;i<size;i++)
		{
			foo=Q->get(i);
			fprintf(stdout,"%d %s\n",foo.day,foo.url);
		}
	}
	void RECOVER_HISTORY(char* FILE_NAME){
		FILE *g=fopen(FILE_NAME,"r");
		URL foo;
		int i,nrintr,d;
		char* u;
		fscanf(g,"%d",&nrintr);
		for(i=0;i<nrintr;i++)
		{
			u=new char[100];
			fscanf(g,"%d %s",&d,u);
			if ((Day-d)==mdays)
				break;
			char* up=strdup(u);
			foo.day=d;
			foo.url=up;
			Q->push_back(foo);
			size++;
		}
	}
};
