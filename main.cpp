/*
La bolletta dell'acqua: fatturare annualmente i consumi di acqua
*/
#include <iostream>

using namespace std;
// Stampa dati
void stampaDati(float qtVariabile,float qtFissa,int iva,float totale){
 cout<< "Quota variabile:" << qtVariabile<<endl;
 cout<< "Quota Fissa:" << qtFissa<<endl;
 cout<< "IVA:" << iva<<endl;
 cout<< "TOTALE:" << totale<<endl;
}
//Calcola tariffa Aziende
void calcolaTariffeAziende(float consumo,float tariffa,float qtFissa,int percIva){
    float qtVariabile=consumo*tariffa;
    float iva=(qtVariabile+qtFissa)*percIva/100;
    float totale=qtVariabile+qtFissa+iva;
    stampaDati(qtVariabile,qtFissa,iva,totale);
}
//Calcola tariffa Privati
void calcolaTariffePrivati(float consumo,int T1_FINOA,int T2_FINOA,float T1,float T2,float T3,float QFPRIVATI,int percIva){
    float qtVariabile;
    if (consumo<=T1_FINOA){
        qtVariabile=consumo*T1;
    }
    else if(consumo<=T2_FINOA){
        qtVariabile=T1*T1_FINOA + (consumo-T1_FINOA)*T2;
    }
    else{
        qtVariabile=(T1*T1_FINOA) + (T2_FINOA- T1_FINOA)*T2 + (consumo-T2_FINOA)*T3;
    }
    float iva=(qtVariabile+QFPRIVATI)*percIva/100;
    float totale=qtVariabile+QFPRIVATI+iva;
    stampaDati(qtVariabile,QFPRIVATI,iva,totale);
}

int main()
{
    const int PERC_IVA=10;
    // Tariffa aziende
    const float TARIFFA_A=1.25;     // prezzo unitario
    const float QF_AZIENDE=21;    // quota fissa annuale

    // Tariffa privati
    const int T1_FINOA=80;    //  Consumo primo scaglione
    const int T2_FINOA=120;   // Consumo secondo scaglione
    const float T1=0.31;        // Prezzo unitario primo scaglione
    const float T2=0.61;        // Prezzo unitario secondo scaglione
    const float T3=1.09;        // Prezzo unitario terzo scaglione
    const float QF_PRIVATI=14;  // quota fissa annuale

    float consumo;
    char tipoUtenza=' ';
    cout<<" inserisci il consumo:";
    cin >>consumo;
    cout<<" inserisci il tipo di utenza A=Aziende, P= Privati:";
    cin>>tipoUtenza;
    while (tipoUtenza!='A' && tipoUtenza!='P'){
        cout<< " il tipo di utenza deve essere (A  per Aziende, P per Privati) \n";
        cout<<" inserisci il tipo di utenza A=Aziende, P= Privati:";
        cin>>tipoUtenza;
    }
    if (tipoUtenza=='A'){
       calcolaTariffeAziende(consumo,TARIFFA_A,QF_AZIENDE,PERC_IVA);
    }
    else {
        calcolaTariffePrivati(consumo,T1_FINOA,T2_FINOA,T1,T2,T3,QF_PRIVATI,PERC_IVA);
    }

}
