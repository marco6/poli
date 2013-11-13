### RELAZIONE DI LABORATORIO – ELETTRONICA
#### ESERCITAZIONE 2 – GENERATORE DI ONDA QUADRA E CONTATORE ASINCRONO 
**(Giovedì 24 Ottobre 2013)**

SQUADRA A06  – LED 9


o	**Elenco dei dispositivi:**
	
-	Oscilloscopio Digitale Agilent DSO3102A  (Figura 1)
-	Cavi coassiali (BNC-BNC)
-	Cavi coassiali (BNC-banana)
-	Cavi banana-banana
-	Sonde compensate Agilent N2862A
-	Resistenze
-	Condensatori
-	Piastra per montaggi sperimentale 
-	Generatore di funzioni Agilent 33220A (Figura 3)
-	Contatore asincrono
-	Comparatore di soglia
-	Schedina di LED con resistenza

o	**Scopo dell’esercitazione**

Gli obiettivi dell’esercitazione sono stati, in primo luogo, di realizzare un generatore di onde quadre con porte logiche e poi di modificare il circuito in modo da variare il duty-cycle.
Successivamente, dato un contatore asincrono, verificarne il comportamento e misurarne i ritardi. Infine si doveva decodificare uno stato di uscita e verificare la presenza di rimbalzo su contatti meccanici.

o	**Cenni di teoria**

Il generatore d'onda quadra è un circuito che fornisce in uscita un'onda quadra, senza che vi sia alcun segnale d'ingresso. E’ composto rete RC passa-basso, pilotata da un segnale binario, in cui la capacità C si carica e scarica attraverso la resistenza R verso il valore della tensione d’uscita in modo esponenziale, con costante di tempo τ = RC. Il confronto della tensione su C con il livello max e min avviene tramite un comparatore di isteresi. L’uscita può assumere solo due valori: : VoH e VoL , dette tensioni di saturazione, e la commutazione avviene quando la tensione sulla capacità uguaglia tali valori. Infine, l’uscita del compratore con isteresi, pilota la rete RC.       
 Sono previsti dei limiti operativi imposti dalla resistenza e dalla capacità: la resistenza, infatti, non può assumere valori troppo piccoli in quanto limiterebbe la dinamica di uscita, ma neanche troppo elevati perché deve permettere la circolazione di una corrente maggiore della corrente di ingresso del comparatore. La frequenza massima, infine, è anche limitata dallo slew rate dell’uscita. 
Viene definito contatore un circuito logico che genera sulle uscite una sequenza di conteggio binario, incrementata ad ogni colpo di Clock. Viene poi definito “asincrono” in quanto le uscite commutano con ritardi differenti, poiché il clock comanda solo il primo dei flip-flop posti in cascata, mentre i successivi ricevono il segnale dal flip-flop precedente, andando quindi a generare un ritardo finale composto dalla somma dei singoli contributi.
 
o	**DIARIO DELL’ESPERIENZA**

-	*PROGETTO DEL GENERATORE DI ONDA QUADRA E RISULTATI DELLE MISURE*

Per costruire il circuito abbiamo dovuto calcolare il valore del condensatore utilizzando le tensioni di soglia, prese dal datasheet (VT+ = 2,8 V e VT- = 1,9 V):

(formula 1)
 
Abbiamo in seguito misurato i valori delle soglie per controllare che corrispondessero, ottenendo come risultati VT+ = 3,20 V e VT- = 2,16 V, che sono risultati essere un po’ differenti ma all’interno dei limiti garantiti. Ci siamo successivamenti accorti che questo era effettivamente richiesto in uno dei punti seguenti, per questo motivo abbiamo utilizzato da subito questi ultimi risultati, ottenendo una C   1,2 nF.
Abbiamo quindi collegato il generatore di segnali (onda triangolare di ampiezza 4 V e offset 2,5 V) all’entrata del trigger Schmit ed all’oscilloscopio (CH1), mentrel’uscita del trigger al CH2 dell’oscilloscopio. Abbiamo poi misurato VT+ e VT- come il valore dell’onda triangolare nell’istante di commutazione.  (Figura 1)
Spento il generatore di segnali, abbiamo montato il circuito generatore di onda quadra (figura 2 - 3) e misurato la frequenza generata f = 9,57 kHz (ci aspettavamo circa 10 kHz) e calcolato l’incertezza:

(formula 2)
 
Il risultato è quindi compatibile!
Il duty-cycle ci aspettavamo fosse del 50% ed abbiamo verificato essere di circa 49,4%.

(foto 1)   (foto 2)   (circuito 1)

Avendo avanzato del tempo, abbiamo svolto anche la richiesta opzionale dopo aver modificato, sotto consiglio degli assistenti, il circuito utilizzando un potenziometro da 220 Ω e due diodi in parallelo e verso opposto. (schema circuito). 
Abbiamo verificato che il duty-cycle variava regolando il potenziometro. (foto 5-6)

(foto 3)   (foto 4)   (circuito 2)
         
-	*RISULTATI DELLE MISURE SUL CONTATORE ASINCRONO*

Abbiamo costruito il circuito utilizzando la scheda per montaggi sperimentali già usata nel punto precedente e il contatore asincrono dato (figura 7 - 8)
Successivamente abbiamo collegato al CH1 dell’oscilloscopio, l’uscita del trigger di Schmit, invece al CH2 l’uscita di uno dei bit del contatore, verificando quuindi che il periodo fosse multiplo intero di quello del segnale visualizzato sul CH1.  (figura 9) 
 
(circuito 3)  (foto 5)  (foto 6)

Per verificare il ritardo di commutazione, abbiamo misurato il ritardo di uscita su tre bit diversi: 
-	piedino 6 bit 3  ritardo di 137 ns
-	piedino 2 bit 6  ritardo di 212 ns
-	piedino 1 bit 12  ritardo 361 ns
considerando che oltre ai flip flop ci sono delle porte logiche iniziali, per calcolare il ritardo di un singolo stadio, con un ritardo iniziale di 62 ns, abbiamo deciso di usare la formula

(formula 3)

Per confermare questo valore, calcoliamo 61+(25 6) = 211 ns che corrisponde al risultato atteso (misura del ritardo del bit 6, ovvero 212 ns).
In seguito abbiamo scollegato dall’ingresso del contatore il generatore di onda quadra, collegato una resistenza di pull-up verso l’alimentazione e un interruttore verso massa comandato da noi tramite un filo volante. Abbiamo anche inserito una scheda LED nel circuito collegandola ad alcune uscite del contatore, la quale visualizzava i bit settati. Agendo manualmente sull’interruttore, abbiamo verificato le oscillazioni: il contatore non avanzava di un solo bit alla volta, ma di un numero apparentemente casuale (i LED “sfarfallavano” per poi stabilizzarsi dopo un certo periodo).
Colegando un filo lungo circa 10 cm e lasciato aperto, al posto del clock manuale (resistenza pull-up e switch manuale), il contatore riceveva segnali dall’ambiente e toccando lo schermo del pc abbiamo riscontrato un aumento nel disturbo ambientale ricevuto dall’antenna (il cavo). Ricollegando poi la resistenza di pull-up, i disturbi sono scomparsi quasi del tutto.
Avendo nuovamente concluso le precedenti richieste nei tempi stabiliti, siamo riusciti a svolgere anche alcuni dei punti opzionali.
Su consiglio dell’assistente di laboratorio, abbiamo montato il decodificatore seguendo lo schema in figura 10 (ricavando il circuito in figura 11).

(circuito 4)  (foto 7)

Purtroppo però non c’è stato tempo di compiere la verifica.

o	**Commenti**

Abbiamo incontrato alcune difficoltà 





