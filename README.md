# bolletta
Il problema della fatturazione dei consumi riguarda le aziende di erogazione di servizi pubblici in generale e, in particolare, le società che gestiscono il servizio idrico(acqua) e i fornitori di energia elettrica e gas.
La fatturazione è di solito periodica, con emissione di una bolletta di pagamento ogni 2 o 3 mesi, oppure anche con una sola bolletta annuale, come accade, in alcuni casi, per i consumi di acqua. In questo caso si prende in esame la fatturazione dei consumi di acqua, nell’ipotesi semplificativa di una sola fattura annuale.
Per i consumi di acqua l’unità di misura è il metro cubo (mc).
Le tariffe (qui presentate per valori esemplificativi) sono normalmente distinte tra Privati (uso domestico o clienti residenziali) e Aziende (uso diverso dal domestico). I valori sono immessi dall’utente all’inizio del programma.
Per le aziende il calcolo delle tariffe è semplice: si moltiplica il consumo in mc per il prezzo unitario al metro cubo (1,25 €).
Per i privati si suppone che esistano tre fasce di prezzo in base al consumo annuale, secondo la seguente tabella:
Tipo tariffa	Consumo annuo in mc	Prezzo unitario al mc
agevolata	fino a 80	0,31 €
Base	da 81 a 120	0,61 €
Eccedenza	oltre 120	1,09 €

Il calcolo è fatto a scaglioni: sui primi 80 mc si paga 0,31 €, sui consumi oltre gli 80 mc si paga 0,61 € e cosi via.
Per esempio, se il consumo annuo è stato di 90 mc, il costo è (80 * 0,31) + (10*0,61)=30,90 €.
Sia per l’azienda si per il privato, occorre aggiungere al risultato del calcolo dei consumi effettivi (quota variabile) una quota fissa annuale, che è indipendente dai consumi.
•	Per le aziende 21 €
•	Per i privati 14 €
Infine occorre applicare l’imposta IVA, secondo una percentuale che può essere considerata una costante, per esempio il 10%.
Nel caso generale di fatturazione periodica (non annuale), nel procedimento di calcolo si dovrebbe considerare, oltre al consumo annuo, anche il consumo del periodo e dividere la quota fissa annuale per il numero di mesi compresi dal periodo di fatturazione.
Poiché il problema è complesso si procede con il metodo di sviluppo top-down, individuando i seguenti sottoproblemi:
•	acquisizione dei dati
•	calcolo del totale da pagare (quota variabile + quota fissa + IVA)
•	visualizzazione dei risultati
Il secondo punto può essere ulteriormente scomposto in due sottoproblemi:
•	calcolo per le aziende
•	calcolo per i privati
Dati di input: 
il consumo, i mc da fatturare
Dati di output: 
qv, quota variabile
qf, quota fissa
iva, imposta IVA
totale, totale da pagare
