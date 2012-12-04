/**
 * @file Qui viene dichiarato il tipo vettore. Ha una struttura molto 
 * 		simile a quella descritta in 
 * 		<http://www.cplusplus.com/reference/vector/vector/>.
 * 		I vettori sono in pratica array dinamici, tramite i quali si può
 * 		evitare di gestire la memoria autonomamente.
 * @remarks Se si memorizzano dei puntatori all'interno dei vettori, 
 * 		eliminarli dalla lista *NON* libererà la memoria occupata.
 * @author marco6
 * 
 */

#ifndef CEXVECTOR
#define CEXVECTOR

///Struttura base dei vettori(array dinamiche)
typedef struct _vector {
	unsigned long capacity, ///<La capacità reale del vettore, verrà duplicata ogni volta
		itemSize,///<La dimensione di un singolo elemento
		size;///<Numero di elementi che contiene il vettore
	void*mem;///Puntatore alla memoria
} *vector;

///Definisce la struttura che gestisce il tipo specificato
#define vector(type) struct { 			\
						unsigned long capacity,	\
							itemSize,		\
							size;			\
						type *mem; 			\
					} *

/** Inizializza una nuova struttura vettore base
 * @param n La capacità iniziale della struttura
 * @param ts Dimensione effettiva del tipo
 */
vector VECTOR_NEW(unsigned long n, unsigned long ts);

/**
 * Inizializza un nuovo vettore di tipo t e capacità n
 * @param n La capacità iniziale del vettore
 * @param t Il tipo di dato
 */
#define vector_new(n, t) (void*)VECTOR_NEW((n), sizeof(t))

/**
 * Libera la memoria del vettore puntato. Tutti i dati da lui contenuti andranno persi.
 * @param v Il vettore da distruggere
 */
#define vector_free(v) VECTOR_FREE((vector)(v))

void VECTOR_FREE(vector v);

/**
 * Elimina tutti gli elementi nella lista. NON libera nessuna zona di memoria.
 *
 * @param Il vettore da pulire
 */
#define vector_clear(v) VECTOR_CLEAR((vector)(v))
void VECTOR_CLEAR(vector v);

/**
 * Assegna un nuovo contenuto al vettore, eliminando il vecchio contenuto e rimpiazzandolo con quello nuovo
 * @param v Il vettore da riempire
 * @param f Puntatore al primo elemento della lista copiare
 * @param l Puntatore all'ultimo elemento della lista copiare 
 */
#define vector_assign(v, f, l) VECTOR_ASSIGN((vector)(v), f, l)
void VECTOR_ASSIGN(vector, void*, void*);

/**
 * Restituisce un puntatore all'n-esimo elemento nel vettore
 * @param v il vettore da cui estrarre il valore
 * @param n la posizione dell'elemento nel vettore
 */
#define vector_at(v, n) ((v)->mem[n])

/**
 * Restituisce la capacità del vettore
 * @param v il vettore
 */
#define vector_capacity(v) ((v)->capacity)

/**
 * Restituisce 1 (true) se il vettore è vuoto
 * @param v il vettore
 */
#define vector_empty(v) (((v)->size) == 0)

/**
 * Restituisce la dimensione attuale del vettore
 * @param v il vettore
 */
#define vector_size(v) ((v)->size)

/**
 * Richiede che la capacità del vettore sia *almeno* s.
 * @param v Il vettore
 * @param s La capacità richiesta
 */
#define vector_reserve(v, s) VECTOR_RESERVE((vector)(v), s)
void VECTOR_RESERVE(vector, unsigned long);

/**
 * Aggiunge alla fine del vettore un nuovo elemento.
 * @param v Il vettore a cui aggiungere l'elemento
 * @param val il valore da aggiungere. NB: questo valore *deve* essere
 * 	passato tramite una variabile locale. Ad esempio NON si può fare 
 * 			vector_push_back(v, 2);
 */
#define vector_push_back(v, val) VECTOR_PUSH_BACK((vector)(v), &val)
void VECTOR_PUSH_BACK(vector, void*);

/**
 * Elimina l'ultimo elemento del vettore.
 * @param v Il vettore
 */
#define vector_pop_back(v) (--((v)->size))

/**
 * Elimina un elemento dal vettore alla posizione i.
 * @param v Il vettore
 * @param i L'indice dell'elemento da eliminare
 */
#define vector_erase_one(v, i) VECTOR_ERASE((vector)(v), i, i+1)

/**
 * Elimina gli elementi nell'intervallo [s, e) dal vettore
 * @param v Il vettore
 * @param s L'indice del primo elemento da eliminare
 * @param e L'indice dell'elemento dopo l'ultimo elemento da eliminare
 */
#define vector_erase(v, s, e) VECTOR_ERASE((vector)(v), s, e)
void VECTOR_ERASE(vector, unsigned long, unsigned long);

/**
 * Inserisce un elemento nel vettore alla posizione p.
 * @param v Il vettore
 * @param p la posizione in cui inserire l'elemento
 * @param i l'elemento da inserire. NB: *deve* essere passata una 
 * 			variabile, non un valore costante
 */
#define vector_insert_one(v, p, i) VECTOR_INSERT((vector)(v), p, &(i), &(i)+1)

/**
 * Inserisce un insieme ( [s, e) )  di valori alla posizione p.
 * @param v Il vettore
 * @param p la posizione in cui inserire gli elementi.
 * @param s Il puntatore al primo elemento da copiare
 * @param e puntatore alla fine dell'array. 
 * 		L'elemento puntato non verrà copiato
 */
#define vector_insert(v, p, s, e) VECTOR_INSERT((vector)(v), p, s, e)
void VECTOR_INSERT(vector, unsigned long, void*, void*);  

/*
vector_resize
//*/
#endif
