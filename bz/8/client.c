/*
 * Se mai voleste compilare usate il comando
 *	make
 */
#include <stdio.h>
#include "client.h"
#include "job.h"
#include "plist.h"

static unsigned int ServerCount = 3;
static Plist list;

int main() {
	char in[256];
	unsigned int p;
	Job j;
	list = plist_new();
	printf("Comandi: \n a = aggiungi job \n e = avvisa che un job e' terminato \n c = chiudi\n\nInserisci comando>");  
	while(gets(in) && in[0] != 'c'){
		switch(in[0]){
			case 'a':
				printf("Inserisci priorita'>");
				gets(in);
				sscanf(in, "%u", &p);
				printf("Inserisci nome>");
				gets(in);
				j = job_new(p, in);
				newJob(j);
			break;
			case 'e':
				jobEnd();
			break;
			default:
				printf("Selezione non valida");
			break;
		}
		printf("\nInserisci comando>");
	}
	plist_free(list);
	return 0;
}

void newJob(Job j) {
	if(ServerCount > 0){
		ServerCount--;
		printf("Job %s acquisito (p=%u). Job lanciato su un pc.", job_name(j), job_priority(j));
		job_esegui(j);
	}
	else {
		plist_add(list, j);
		printf("Job %s acquisito (p=%u). Job messo in attesa.", job_name(j), job_priority(j));
	}
}

void jobEnd() {
	Job j;
	printf("Un job ha finito l'esecuzione.");
	ServerCount++;
	if(!plist_empty(list)){
		j = plist_pop(list);
		printf("Job %s (p=%d) lanciato e tolto dall'attesa.", job_name(j), job_priority(j));
	}
}
