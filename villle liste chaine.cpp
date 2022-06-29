#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pays {//description des elemets de la liste
	char nom[20];
	int habitants;
	float mri;
	char capital[10];
	pays *next;
}py,watan;

pays* insertFront(pays *st,pays p){
	pays *newPays=NULL;
	newPays=(pays*)malloc(sizeof(pays));
	strcpy(newPays->capital,p.capital);
	newPays->habitants=p.habitants;
	strcpy(newPays->nom,p.nom);
	newPays->mri=p.mri;
	newPays->next=st;
	return newPays;
}

void print(pays *st){
	while(st!=NULL){
		printf("[%s] [%s] [%d] [%.2f]\n",st->nom,st->capital,st->habitants,st->mri);
		st=st->next;
	}
}

int size(pays *st){
	int s=0;
	while(st!=NULL){
		s++;
		st=st->next;
	}
	return s;
}

pays* deleteFirst(pays *st){
	pays *p=st;
	st=st->next;
	free(p);
	return st;
}

pays* deleteLast(pays *st){
	pays *p=st;
	while(p->next->next!=NULL){
		p=p->next;
	}
	free(p->next);
	p->next=NULL;
	return st;
}

pays* insertBack(pays *st,pays p){
	pays *newPays=NULL;
	newPays=(pays*)malloc(sizeof(pays));
	strcpy(newPays->capital,p.capital);
	newPays->habitants=p.habitants;
	strcpy(newPays->nom,p.nom);
	newPays->mri=p.mri;
	newPays->next=NULL;
	if (st==NULL){
		return newPays;
	}else{
		pays *p=st;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newPays;
		return st;
	}
}








int main(){
	pays *start=NULL;//liste vide
	pays p;
	strcpy(p.nom,"libya");
	p.habitants=4000000;
	p.mri=5000.60;
	strcpy(p.capital,"Tarabloss");
	pays p2;
	strcpy(p2.nom,"Espage");
	p2.habitants=3200000;
	p2.mri=7800.90;
	strcpy(p2.capital,"BARCA");
	pays p3;
	strcpy(p3.nom,"ALgerie");
	p3.habitants=800000;
	p3.mri=900.60;
	strcpy(p3.capital,"ALgerie");
	start=insertFront(start,p);
	start=insertBack(start,p2);
	start=insertFront(start,p3);
	printf("Before deleting:");
	print(start);
	printf("taille:%d",size(start));
	start=deleteLast(start);
	printf("After deleting:");
	print(start);
	printf("taille:%d",size(start));
	
}

