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


-	**Scopo dell’esercitazione**

o Verificare il funzionamento di un convertitore D/A a 4 bit

o Individuare i punti critici per la nonlinearità differenziale

o Individuare i punti critici per i glitch

o Determinare gli errori di guadagno, offset, non linearità

o Verificare il funzionamento di un convertitore A/D a inseguimento


-	**Cenni di teoria**


 
-	**DIARIO DELL’ESPERIENZA**

o *VERIFICARE IL FUNZIONAMENTO DI UN CONVERTITORE D/A A 4 BIT*

Innanzitutto abbiamo alimentato il CD4029 e collegato a terra gli ingressi non utilizzati e ad alimentazione i piedini di up/down e bin/dec. 

Gli abbiamo quindi applicato, dopo i dovuti controlli con il muiltimetro, il segnale di clock verificando con l'oscilloscopio prima che le frequenze di commutazione delle singole uscite erano proporzionali alla frequenza dello strumento (in particolare la frequenza su ogni bit era la matà di quello precedente). 

Abbiamo poi montato il contatore come specificato, costruendo le resistenze da 20 k&Omega; e da 5 k&Omega; con due resistenze da 10 k&Omega; in serie ed in parallelo rispettivamente.

(schema 1)

Il segnale al terminale di uscita del convertitore (Vu) è una gradinata di 16 livelli equispaziati, come ci aspettavamo

(foto 1)

Con i cursori dell'oscilloscopio, abbiamo misurato il fondo scala ed il valore del LSB che ci risultavano essere rispettivamente 5,04 V e 352 mV. 

Collegando la basetta di LED abbiamo notato una riduzione del fondo scala da 5,04 V a 3,12 V e di conseguenza anche del LSB, da 352 mV a 220 mV. 

????????????????????????????????????????????? (punto 4)

(foto 2)

Abbiamo inserito a in serie a R1 una resistenza da 6,6 k&Omega; (circa il 15% della prima) ed abbiamo verificato che gli scalini dei bit corrispondenti a valori dispari, si erano rimpiccioliti. Ripetendo l'esperienza con R3 (questa volta con una resistenza da 1,8 k&Omega;) abbiamo notato che a variare era invece un bit ogni quattro, scecondo quello che ci aspetavamo. 

(foto 3)


o *INDIVIDUARE I PUNTI CRITICI PER LA NON LINEARITA' DIFFERENZIALE*

Per ottenere una non monotonicità, abbiamo calcolato il valore della resistenza da mettere in serie a R4:
 
(formula 1)

Il valore effettivo che abbiamo dovuto inserire per ottenere un errore apprezzabile, è stato di 3 k&Omega;.

(foto 4)


o *INDIVIDUARE I PUNTI CRITICI PER I GLITCH*

Per eseguire questo punto, abbiamo collegato tre condensatori da 0,5 nF in parallelo a Q1, Q3, Q4, verificando successivamente con l'oscilloscopio, la presenza di glitch.

(foto 5)

o *DETERMINARE GLI ERRORI DI GUADAGNO, OFFSET, NON LINEARITA'*



o *VERIFICARE IL FUNZIONAMENTO DI UN CONVERTITORE A/D A INSEGUIMENTO*





-	**Commenti**





