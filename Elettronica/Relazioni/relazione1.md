### RELAZIONE DI LABORATORIO – MISURE ELETTRONICHE
### ESERCITAZIONE 1 – USO DELL’OSCILLOSCOPIO DIGITALE
**(Giovedì 10 Ottobre 2013)**

SQUADRA A06  – LED 9

Nome:		 BONATO Alessio		____________________________

Matricola:		180472

Nome:		 DI BIASE Armonia	____________________________

Matricola:		181325

Nome: 		 MANINO Marco		____________________________

Matricola:		180678

Nome:	  	 MANTOVANI Alessia	____________________________

Matricola:		180812

(figura 1)    (figura 2)   (figura 3)
  
•	**Elenco dei dispositivi:**
	
o	Oscilloscopio Digitale Agilent DSO3102A  (Figura 1)
o	Multimetro digitale da banco Agilent 34401A (Figura 2)
o	Cavi coassiali (BNC-BNC)
o	Cavi coassiali (BNC-banana)
o	Cavi banana-banana
o	Sonde compensate Agilent N2862A
o	Resistenze
o	Scheda
o	Piastra per montaggi sperimentale 
o	Generatore di funzioni Agilent 33220A (Figura 3)

•	**Scopo dell’esercitazione**

Utilizzo dello strumento per:

o	Misurazione di valore efficace 
o	Misurazione della frequenza
o	Misurazione del tempo di salita
o	Verifica dell’aliasing
o	Rilevazione sincrona dei segnali

•	**Cenni di teoria**

L’oscilloscopio numerico, che è chiamato comunemente oscilloscopio digitale, è uno strumento che sta gradualmente sostituendo l’oscilloscopio analogico, sia per l’evoluzione verso la strumentazione numerica, sia per il fatto che è in grado di rappresentare segnali non ripetitivi, quali transistori, impulsi casuali e forme d’onda. 
L’oscilloscopio digitale, pur mantenendo le principali funzionalità di un oscilloscopio analogico, opera in modo sostanzialmente diverso da questo, in quanto: campiona il segnale e lo quantizza tramite un convertitore A\D, quindi memorizza i campioni numerici in una memoria RAM, li elabora e rappresenta infine il segnale su uno schermo di un tubo a raggi catodici. Ne consegue quindi che i circuiti che precedono il convertitore devono avere banda passante adeguata a quella del segnale. Inoltre la memorizzazione dei campioni numerici deve avvenire alla stessa velocità con cui si esegue la scansione. Dopodichè il vincolo della velocità viene meno, in quanto la porzione temporale viene memorizzata in una RAM che può essere letta ciclicamente. La gestione delle varie operazioni  è affidata ad uno o più microprocessori, che controllano le diverse funzioni, quali il campionamento, il trigger, l’elaborazione dei dati memorizzati e la presentazione sullo schermo. 
Una particolarità degli oscilloscopi digitali è la possibilità di operare il campionamento in tempo equivalente. Infatti se si studia un segnale periodico, è possibile campionare ripetutamente il segnale per più periodi, raggiungendo una banda passante di oltre 50 GHz campionando a soli 20 GHz.
Tra le principali differenze da segnalare rispetto all’oscilloscopio analogico c’è, oltre la possibilità di catturare transitori, anche la notevole flessibilità dell’impostazione del trigger (permette infatti di determinare l’inizio e\o la fine della fase di acquisizione). 
Negli ultimi anni ci si sta dirigendo verso convertitori A\D e memorie sempre più veloci, per cui si sta assistendo ad un’evoluzione deli oscilloscopi digitali verso le alte frequenze, mentre lo sviluppo di hardware e software sempre più sofisticati permette di ottenere migliori prestazioni. 

•	**DIARIO DELL’ESPERIENZA**

Come prima cosa abbiamo generato un segnale sinusoidale (di frequenza 1 kHz e ampiezza 1 V senza offset) attraverso il generatore di funzioni e, tramite un cavo coassiale, lo abbiamo poi collegato all’oscilloscopio digitale all’ingresso CH1 (500 μs/div), per visualizzarne l’andamento.
Ci siamo quindi apprestati ad effettuare le misurazioni richieste.

o	*VALORE EFFICACE*

Inizialmente abbiamo visualizzato un segnale “sospetto” di ampiezza picco-picco 1V , quando invece ci aspettavamo esattamente il doppio; dopo varie verifiche, utilizzando l’oscilloscopio e constatando che veniva visualizato un risultato corretto da quest’ultimo, abbiamo capito che questo problema era dovuto al fatto che il generatore di funzioni era impostato per funzionare con un oscilloscopio ad alta impedenza (da 1 MΩ) quando noi ci aspettavamo che fosse impostato per 50Ω. Così, dopo qualche perplessità, siamo riusciti a risolvere il problema modificando le caratteristiche di uscita del generatore nel modo corretto. 
Abbiamo quindi letto la misura dell’ampiezza picco-picco, utilizzando i cursori che ci hanno direttamente dato il valore  di 2,021V.
Leggendo dal manuale abbiamo constatato che l’incertezza dell’oscilloscopio è il 3% di fondo scala,  quindi nel nostro caso è pari a ± 0.090 V
Il valore efficace ci risulta quindi: 0.714 ± 0.031

o	*FREQUENZA*

Abbiamo agito in modo analogo alla precedente richiesta, ottenendo i seguenti valori: 
Periodo: 1 ms ± 0.0001 ms,  utilizzando la formula per l’errore: ± 100 ppm.
Frequenza: 1000 ± 0.1 Hz.
Dopo aver ottenuto i precedenti valori, abbiamo proseguito con la verifica dei suddetti cambiando strumento, ovvero utilizzando un multimetro e verificandone la compatibilità.
La formula per l’errore del multimetro letta dal manuale è: ± (0.06% (of reading) + 0.04% (of frange))
Valore efficace: 0.70592 ± 0.00046 V
Frequenza: 999.96 ± 0.09 Hz  (errore = 0.01 %(of reading))   

o	*TEMPO DI SALITA*

Dalla teoria è noto che viene definito “tempo di salita”, il tempo che il segnale impiega per passare dal livello 10% al livello 90%.
Per ricavare il suddetto tempo nella nostra esperienza abbiamo generato un segnale ad onda quadra (di frequenza 1 kHz e ampiezza 1 V senza offset) attraverso il generatore di funzioni e, tramite un cavo coassiale, lo abbiamo poi collegato all’oscilloscopio digitale per visualizzarne il fronte di salita (10 ns/div).

Le richieste erano quelle di compiere due misurazioni differenti inserendo e rimuovendo un terminatore di valore 50Ω; noi, però, non abbiamo riscontrato significativi cambiamenti nei due casi:
Misurazione senza resistenza: ts1 = 10,90 ns
Misurazione con resistenza: ts2 = 10,80 ns.
Poichè la banda passante è di 100 MHz (da datasheet), il tempo di salita dell’oscilloscopio è risultato essere 3,5 ns. Secondo la formula  

(formula 1)

, invece, il tempo di salita senza l’effetto dell’oscilloscopio: 10,32 ns.
In seguito abbiamo calcolato la frequenza del polo e ne abbiamo valutato l’effetto sulla misura del tempo di salita, prendendo una coppia di cavi coassiali intestati da una parte con un connettore BNC e dall’altro con delle pinzette, e collegati entrambi alle estremità di una resistenza da 1kΩ (i due cavi sono risultati essere lunghi circa 3 m).

(circuito 1)

Capacità totale (oscilloscopio+cavi): 313 pF
Resistenza del generatore “modificato”: 1050 Ω
Frequenza polo: 484.51 kHz
Tempo di salita dovuto al polo: 72.20 ns
Verifica sperimentale del tempo di salita: 316 ns

(figura 4)

(circuito 2)

Dopo aver sostituito i cavi con una sonda compensata abbiamo rilevato i seguenti valori (con capacità della sonda 30 pF):
Nuova frequenza del polo: 5537.39 kHz
Nuovo tempo di salita atteso: 63.20 ns
Infine, abbiamo verificato sperimentalmente l’effetto della sonda   dopo averla compensata: 28.55 ns.

(figura 4)

Infine, abbiamo verificato sperimentalmente l’effetto della sonda dopo averla compensata: 28.55 ns.
Benché anche dopo l’immissione della sonda il ts atteso dista da quello trovato sperimentalmente di 34.65ns, l’esperienza si può considerare riuscita in quanto la differenza tra i due tempi nel secondo caso (con sonda) è molto diminuita rispetto al primo (senza sonda).
 
o	*ALIASING*

Abbiamo generato un segnale sinusoidale (di frequenza 100 kHz e ampiezza 1 V senza offset) attraverso il generatore di funzioni e tramite un cavo coassiale, lo abbiamo poi collegato all’oscilloscopio digitale per visualizzarne l’andamento (2 μs/div).
Secondo il teorema di campionamento, la minima frequenza risulta essere: 200 kHz,
mentre la frequenza di campionamento dell’oscilloscopio è di 50000 kHz.
Dopodichè abbiamo ridotto la velocità di scansione in modo da arrivare ad avere una frequenza di campionamento di 1 MHz; abbiamo quindi impostato lo strumento come indicato ed abbiamo infatti verificato che l’immagine rappresentata era diversa dalle nostre aspettative, non era una sinusoide, a causa di un errore di interpolazione.
Modificando, invece, la frequenza del generatore, è stato visualizzato un segnale che assomigliava a tante sinusoidi sovrapposte, ma in realtà era una sola.

In conclusione, abbiamo verificato i casi visti a lezione: in un primo caso, quando il rapporto di frequenza del segnale e frequanza equivalente è irrazionale, abbiamo visualizzato dei punti casuali; successivamente, in un secondo caso, quando il suddetto rapporto è razionale, abbiamo visualizzato una forma d’onda ed un’ampiezza coerenti con le aspettative, ma di frequenza diversa; in un terzo caso , detto di “aliasing percettivo”, dovuto ad un errore dell’occhio umano, abbiamo visualizzato un segnale apparentemente non sincronizzato, poichè i nostri occhi associavano i punti spazialmente più vicini, mentre si sarebbero dovuti considerare quelli temporalmente più prossimi.

Successivamente per verificare l’aliasing nel dominio del tempo, abbiamo lasciato l’oscilloscopio impostato come nel punto precedente, fissato la frequenza del generatore a Fs = 100.1 kHz e ridotto la velocità di scansione fino ad avere una frequenza di campionamento di 100 kHz. In queste condizioni la frequenza del segnale osservato è risultata essere 98.14 Hz. Comportamento che è giustificabile dal fatto che non si è rispettato il teorema di Shannon, ovvero la relazione Fev > 2Fs (Fev=Nd/Tx) non è stata soddisfatta ed inoltre il rapporto Fs/Fev risulta non razionale.
Andando a modificare la frequenza del generatore a 100kHz, il teorema di Shannon continua a non essere verificato, ma il rapporto risulta invece essere razionale: ciò giustifica il fatto che, vedendo il segnale, non si ha alcuna sensazione dell’errore: si ottengono infatti sia la forma d’onda che l’ampiezza prevista, ma si rileva una frequenza notevolemente differente dalle aspettative.

o	*RILEVAZIONE SINCRONA DEI SEGNALI*


Seguendo lo schema in figura 4, abbiamo realizzato il circuito con la piastra per montaggi sperimentali, collegando due resistenze da 680Ω (già presenti in laboratorio) e utilizzando per la resistenza da 47Ω, 2 resistenze da 100Ω e una da 800Ω (100Ω//100Ω//800Ω = ~47Ω).
Dopo aver collegato all'oscilloscopio il sistema con delle sonde sono apparsi due segnali diversi sui canali dell'oscilloscopio. Sul canale 2, si vedeva una sinusoide. Il segnale del canale 1 invece risultava disturbato (figura 5).
Dopo aver impostato la frequenza del disturbo a 4.8 kHz abbiamo analizzato il segnale nel canale 1 più da vicino. Quello che è comparso sullo schermo è stato un segnale molto disturbato (figura 6).

(figura 5)  (foto 1)  (foto 2)

Utilizzando però la funzione “media” dell’oscilloscopio digitale e aumentandone progressivamente i campionamenti, abbiamo potuto constatare un significativo miglioramento nell’osservazione del segnale (figura 7 – 8) che è tornato ad avere una forma sinusoidale non disturbata (figura 9).

(foto 3)  (foto 4)  (foto 5)
       
•	Commenti

Rispetto all’esercitazione di laboratorio dell’anno scorso effettuata con l’oscilloscopio analogico, abbiamo notato che utilizzando invece un oscilloscopio digitale si è potuto effettuare direttamente alcune misurazioni che invece con lo strumento analogico dovevano essere effettuate in modo alternativo (per esempio il calcolo del valore picco-picco di un segnale si poteva comodamente leggere sullo schermo del digitale utilizzando l’apposita funzione); inoltre si possono anche distinguere più chiaramente tracce di segnali diversi pur essendo esse sovrapposte, grazie alla distinzione dei colori che questo strumento permette.
Come già detto in precedenza, abbiamo incontrato qualche iniziale difficoltà (illustrata nel primo punto “valore efficace”) ed a causa di questo, abbiamo accumulato un po’ di ritardo che ci ha fatto risolvere un po’ frettolosamente l’ultima richiesta; nonostante ciò, siamo fortunatamente riusciti a concludere l’esperienza.

