### RELAZIONE DI LABORATORIO – ELETTRONICA
#### ESERCITAZIONE 3 – CONVERTITORE D/A E A/D CON RETE DI PESO 
**(Giovedì 21 Novembre 2013)**

SQUADRA A06  – LED 9


-	**Elenco dei dispositivi:**
	
o	Oscilloscopio Digitale Agilent DSO3102A 

o	Cavi coassiali (BNC-BNC)

o	Cavi banana-banana

o	Sonde compensate Agilent N2862A

o	Resistenze

o	Condensatori

o	Piastra per montaggi sperimentale 

o	Generatore di funzioni Agilent 33220A

o	Contatore asincrono CD4029

o	Amplificatore operazionale (LM748, LM741)

o	Schedina di LED con resistenza

o	Multimetro digitale da banco Agilent 34401A

o	Porte logiche NAND (74LS00)


-	**Scopo dell’esercitazione**

o Verificare il funzionamento di un convertitore D/A a 4 bit

o Individuare i punti critici per la nonlinearità differenziale e per i glitch

o Verificare il funzionamento di un convertitore A/D a inseguimento

Determinando man mano gli errori di guadagno, offset, non linearità.


-	**Cenni di teoria**


 
-	**DIARIO DELL’ESPERIENZA**

o *VERIFICARE IL FUNZIONAMENTO DI UN CONVERTITORE D/A A 4 BIT*

Innanzitutto abbiamo alimentato il CD4029 e collegato a terra gli ingressi non utilizzati e ad alimentazione i piedini di up/down e bin/dec. 

Gli abbiamo quindi applicato, dopo i dovuti controlli con il muiltimetro, il segnale di clock verificando con l'oscilloscopio prima che le frequenze di commutazione delle singole uscite erano proporzionali alla frequenza dello strumento (in particolare la frequenza su ogni bit era la matà di quello precedente). 

Abbiamo poi montato il contatore come specificato, costruendo le resistenze da 20 k&Omega; e da 5 k&Omega; con due resistenze da 10 k&Omega; in serie ed in parallelo rispettivamente.

(schema 1)  ![](../Schemi/Lab4/circuito_1.png "")


Il segnale al terminale di uscita del convertitore (Vu) è una gradinata di 16 livelli equispaziati, come ci aspettavamo

(foto 1)

Con i cursori dell'oscilloscopio, abbiamo misurato il fondo scala ed il valore del LSB che ci risultavano essere rispettivamente 5,04 V e 352 mV. 

Collegando la basetta di LED abbiamo notato una riduzione dell'intervallo da 5,04 V a 3,12 V e l'introduzione di un errore di offset di 1,92 V. Di conseguenza anche il LSB risulta minore (220 mV).

(schema 2)

????????????????????????????????????????????? (punto 4)

(foto 2)

Abbiamo inserito a in serie a R1 una resistenza da 6,6 k&Omega; (circa il 15% della prima) ed abbiamo verificato che gli scalini dei bit corrispondenti a valori dispari, si erano rimpiccioliti. Ripetendo l'esperienza con R3 (questa volta con una resistenza da 1,8 k&Omega;) abbiamo notato che a variare era invece un bit ogni quattro, scecondo quello che ci aspetavamo. 

(foto 3)


o *INDIVIDUARE I PUNTI CRITICI PER LA NON LINEARITA' DIFFERENZIALE E PER I GLITCH*

Per ottenere una non monotonicità, abbiamo calcolato il valore della resistenza da mettere in serie a R4:
 
(formula 1)

Il valore effettivo che abbiamo dovuto inserire per ottenere un errore apprezzabile, è stato di 3 k&Omega;.

(foto 4)

Per eseguire questo punto, abbiamo collegato tre condensatori da 0,5 nF in parallelo a Q1, Q3, Q4, verificando successivamente con l'oscilloscopio, la presenza di glitch.

??????????????????????????????????????????????????????manca glitch su/giu
(foto 5) (schema 3)

Riducendo di molto la frequenza del clock (0,5 Hz), abbiamo verificato con il multimetro che gli scalini sono equispaziati e che l'intervallo tra gradini adiacenti corrisponde ad un LSB. Collegando i LED i gradini risultano ancora equispaziati, ma la tensione minima risulta 1,92 V, mentre quella massima rimane sostanzialmente invariara; a causa di questo restringimento dell'intervallo, la differenza tra due scalini adiacenti risulta minore (circa 220 mV). (vedere schema 2)

Utilizzando una restistenza di pull-up collegata al generatore ed un filo volante a massa come interruttore manuale.

(schema 4)

Questo interruttore, però, risultava instabile in quanto ad ogni commutazione generava dei rimbalzi che risultavano in un numero imprevedibile di impulsi. Per evitare questo comportamento abbiamo usato il componente 74LS00 montato come circuito antirimbalzo.

(schema 5)

Dovendo ottenere un fondo scala di -5 V, abbiamo iniziato a montare l'amplificatore di transresistenza (LM741). Dopo averlo alimentato, sotto consiglio dell'esercitatore abbiamo collegato il piedino di offset a quello di offset_null tramite un potenziometro, agendo su di esso per regolare la compensazione dell'offset: purtroppo non c'è stato un risultato apprezzabile.

(foto 6) (schema 6)

Dai nostri calcoli risulta che la resistenza di reazione deve essere di 2,66 k&Omega; che abbiamo approssimato con due resistenze da 5,6 k&Omega; ciascuna in parallelo. Montando quindi il circuito, il risultato non è stato, inizialmente, quello sperato. Con l'aiuto dell'esercitatore abbiamo scoperto che il malfunzionamento era causato da alcuni fili che non facevano contatto correttamente.

(foto 7) (foto 8)





o *VERIFICARE IL FUNZIONAMENTO DI UN CONVERTITORE A/D A INSEGUIMENTO*





-	**Commenti**





