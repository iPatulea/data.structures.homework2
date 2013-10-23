/*Patulea Ionut
313CA*/
struct URL{
	int day;
	char* url;
};
template<typename T> struct list_elem{
    int info;
	T* V;
    struct list_elem<T> *next, *prev;
};
template <typename T> class LinkedList{
private:
	struct list_elem<T> *pfirst, *plast;
	int nr;
public:
	void push_front(T x){
		if (pfirst!=NULL){
			if (pfirst->info==nr-1){
				struct list_elem<T> *paux;
				paux = new struct list_elem<T>;
				paux->info=0;
				paux->V=new T[nr];
				paux->V[paux->info]=x;
				paux->next=pfirst;
				pfirst->prev=paux;
				paux->prev=NULL;
				pfirst=paux;
			}
			else{
				for(int i=pfirst->info+1;i>=1;i--)
					pfirst->V[i]=pfirst->V[i-1];
				pfirst->info++;
				pfirst->V[0]=x;
			}
		}
		else{
			struct list_elem<T> *paux;
			paux = new struct list_elem<T>;
			paux->info=0;
			paux->V=new T[nr];
			paux->V[paux->info]=x;
			paux->prev=NULL;
			paux->next=NULL;
			pfirst=paux;
			plast=pfirst;
		}
	}
	void push_back(T x){
		if (plast!=NULL){
			if (plast->info==nr-1){
				struct list_elem<T> *paux;
				paux = new struct list_elem<T>;
				paux->info=0;
				paux->V=new T[nr];
				paux->V[paux->info]=x;
				paux->prev=plast;
				plast->next=paux;
				paux->next=NULL;
				plast=paux;
			}
			else{
				plast->info++;
				plast->V[plast->info]=x;
			}
		}
		else{
			struct list_elem<T> *paux;
			paux = new struct list_elem<T>;
			paux->info=0;
			paux->V=new T[nr];
			paux->V[paux->info]=x;
			paux->next=NULL;
			paux->prev=NULL;
			plast=paux;
			pfirst=plast;
		}
	}
	void pop_front(){
		if (pfirst->info==0){
			struct list_elem<T>* paux;
			paux = new struct list_elem<T>;
			paux = pfirst->next;
			if (pfirst == plast) plast = NULL;
			delete[] pfirst->V;
			delete pfirst;
			pfirst = paux;
			if (pfirst != NULL) pfirst->prev = NULL;
		}
		else{
			for(int i=0;i< pfirst->info ;i++)
				pfirst->V[i]=pfirst->V[i+1];
			pfirst->info--;
		}
	}
	void pop_back() {
		if (plast->info==0){
			struct list_elem<T>* paux;
			paux = new struct list_elem<T>;
			paux = plast->prev;
			if (plast == pfirst) pfirst = NULL;
			delete[] plast->V;
			delete plast;
			plast = paux;
			if (plast != NULL) plast->next = NULL;
		}
		else{
			plast->info--;
		}
	}
	T front(){
		return pfirst->V[0];
	}
	T back(){
		return plast->V[plast->info];
	}
	void erase(int poz){
		int i=pfirst->info;
		struct list_elem<T>* paux;
		paux = new struct list_elem<T>;
		paux=pfirst;
		while(i<poz)
		{
			paux=paux->next;
			i+=(paux->info+1);
		}
		i-=(paux->info);
		for (int j=0;j<=paux->info;j++)
		{
			if (i==poz)
			{
				if (paux->info==0)
				{
					if (paux==pfirst && paux==plast)
					{
						pfirst=NULL;
						plast=NULL;
						delete[] paux->V;
						delete paux;
						break;
					}
					if (paux==pfirst)
					{
						paux->next->prev=NULL;
						pfirst=paux->next;
						delete[] paux->V;
						delete paux;
						break;
					}
					if (paux==plast)
					{
						paux->prev->next=NULL;
						plast=paux->prev;
						delete[] paux->V;
						delete paux;
						break;
					}
					paux->next->prev=paux->prev;
					paux->prev->next=paux->next;
					delete[] paux->V;
					delete paux;
					break;
				}
				else
				{
					for (i=j;i<paux->info;i++)
						paux->V[i]=paux->V[i+1];
					paux->info--;
					break;
				}
			}
			i++;
		}			
	}
	T get(int poz){
		int i=pfirst->info;
		struct list_elem<T>* paux;
		paux = new struct list_elem<T>;
		paux=pfirst;
		while(i<poz)
		{
			paux=paux->next;
			i+=paux->info+1;
		}
		i-=(paux->info);
		int j;
		for (j=0;j<=paux->info;j++)
		{
			if (i==poz)
				break;
			i++;
		}
		return paux->V[j];
	}
	int isEmpty() {
		return (pfirst == NULL);
	}
    LinkedList(int N) {
		nr=N;
        pfirst = plast = NULL;
    }
	~LinkedList(){
		struct list_elem<T>* paux;
		struct list_elem<T>* paux2;
		paux=pfirst;
		while(paux)
		{	
			paux2=paux->next;
			delete[] paux->V;
			delete paux;
			paux=paux2;
		}
	}
	
};
