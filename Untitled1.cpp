#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <stdio.h>
using namespace std;
/*
        Ogolne zmiany graficzne interfejsu
        
        CHANGELOG:
        1. Linie dialogowe miasta
        2. Linie dialogowe kowala
        3. Podwojne zakupy u kowala nie marnuja ci pieniedzy
        4. Zakup u kowala prowadzi z powrotem do kowala zamiast do miasta
        5. Usprawnienia walki
        6. Losowe iventy
*/
float gold=100,miasto,php=100,mphp=100,hp=0,pad=3,par=0,mana=0,pw=0,zakupy=0,zakupyn,klasztor,klasztorq,karczma,kowal,zbroja,bron,zbrojaskurzana,zbrojazelazna,mieczyk,miecz,patyk,rat=0,fox=0,quest=0,mon,ratt=0,revent;


void hpbar(float hp, float mhp) {
        cout<<"|";
    float bartemp=0;
    float divider=20;
    for (int hpbar=1; hpbar<divider; hpbar++) {
        if (hp>bartemp) {
            (bartemp=mhp*hpbar/divider);
            cout<<"/";
        }
        else cout<<" ";
        }
        cout<<"|";
}
void powrot() {
        system("cls");
        cout<<"Czarodziej stabilizuje zaklecie";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        system("cls");
        cout<<"Czarodziej stabilizuje zaklecie";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        system("cls");
}
void walka() {
        int walka=1;
        //general variables
        float maxphp=mphp;
        //loop variables
        float enehp=100, menehp=5, enead=5, enear=1,win,wingold=10,special=0;
        //choice
        int enetype=1;
        //hp bar
        float bartemp=0,divider=20;
        //enemies data
        start:
        (walka=1);
        (win=0);
    (bartemp=0);
    (divider=20);
    cout<<"|";
    for (int phpbar=1; phpbar<divider; phpbar++) {
        if (php>bartemp) {
            (bartemp=maxphp*phpbar/divider);
            cout<<"/";
        }
        else cout<<" ";
   }
    cout<<"|";
        cout<<" >"<<php<<endl<<endl;
        cout<<"Zlote cebuliony:"<<gold<<endl<<endl;
        cout<<"Almanach > wpisz 0;\n\n";
        cout<<"Powrot do miasta - wpisz 9\n\n";
        cout<<"Dostepni wrogowie: "<<endl;
    cout<<" 1. Szczur \n 2. Lis \n"; // 3. Dzik \n 4. Wilk \n 5. Niedzwiedz \n";
        cout<<"Wybor numer: ";
        cin>>enetype;
        cout<<endl;
        string enestr;
        if (enetype==9) {
                (walka=9);
                (win=9);
                goto end;
        }
        //enemies database
        if (enetype==0) {
                system("cls");
                cout<<"Oto baza wiedzy o zabitych potworach:\n";
                if (rat>0) cout<<" Wrog: Szczur\n HP:   5\n AD:   1\n AR:   0\n Zloto wygranej: 2\n\n";
                if (fox>0) cout<<" Wrog: Lis\n HP:   10\n AD:   2\n AR:   0\n Zloto wygranej: 5\n\n";
                if (rat>9) cout<<" Wrog: Horda Szczurow\n HP:  25\n AD:  5\n AR:  0\n Zloto wygranej: 11\n\n";
                system("pause");
                system("cls");
                goto start;
        }
        if (enetype==1) {
        (enead=1);
        (enehp=5);
        (enear=0);
        (enestr="Szczur");
        (wingold=2);
        (menehp=5);
        if (ratt==10) {
            (special=1);
            (enead=5);
            (enehp=25);
            (enear=0);
            (enestr="Grupa Szczurow");
            (wingold=11);
            (menehp=25);
            (ratt=0);
        }
        //(winexp=3);
        }
        if (enetype==2) {
        (enead=2);
        (enehp=10);
        (enear=0);
        (enestr="Lis");
        (wingold=5);
        (menehp=10);
        //(winexp=7);
        }
        system("cls");
        do {
        cout<<endl<<"|";
        (bartemp=0);
        (divider=20);
        for (int phpbar=1; phpbar<divider; phpbar++) {
                if (php>bartemp) {
                (bartemp=maxphp*phpbar/divider);
                cout<<"/";
            }
             else cout<<" ";
        }
        cout<<"|";
                cout<<" >"<<php<<endl;
                cout<<"Twoje AD: "<<pad+pw<<endl;
                cout<<"Twoj Ar:  "<<par<<endl;
                cout<<endl;
                cout<<"\n"<<enestr<<endl;
        cout<<endl<<"|";
        (bartemp=0);
        (divider=20);
        for (int ehpbar=1; ehpbar<divider; ehpbar++) {
                if (enehp>bartemp) {
                (bartemp=menehp*ehpbar/divider);
                cout<<"/";
            }
             else cout<<" ";
        }
        cout<<"|";
                cout<<" >"<<enehp<<endl;
                cout<<"AD wroga: "<<enead<<endl;
                cout<<"Ar wroga: "<<enear<<endl;
                cout<<endl<<"Atakujesz? (y=1/n=0)>";
                float attch;
                cin>>attch;
                cout<<endl;
                if (attch==1) {
                    if (special==0) {
                float ntemp=enead-par, mtemp=pad+pw-enear;
                if (ntemp<1) {
                    (ntemp=1);
                }
                if (mtemp<1) {
                    (mtemp=1);
                }
                (php=php-ntemp);
                (enehp=enehp-mtemp);
                    }
                    if (special==1) {
                if (enehp<=25) (enead=5);
                if (enehp<=20) (enead=4);
                if (enehp<=15) (enead=3);
                if (enehp<=10) (enead=2);
                if (enehp<=5) (enead=1);
                float ntemp=enead-par, mtemp=pad+pw-enear;
                if (ntemp<1) {
                    (ntemp=1);
                }
                if (mtemp<1) {
                    (mtemp=1);
                }
                (php=php-ntemp);
                (enehp=enehp-mtemp);
                    }
                }
                if (attch==0) {
                        cout<<"Bronisz sie"<<endl;
                        float ntemp=enead-5;
                        (ntemp=ntemp-par);
                        if (ntemp<1) {
                                (ntemp=1);
                        }
                        (php=php-ntemp);
                }
                //win or loose conditions
                if (php<1) {
            cout<<"Zdechles. Koniec przygody";
            (walka=2);
            (win=0);
            Sleep(1000);
        }
        if (enehp<1) {
            cout<< "Zwyciezyles. Brawo";
            (walka=2);
            (win=1);
            Sleep(1000);
        }
                system("cls");
        }while (walka<2);
        //aftermath text
        if (php<1) {
        (php=1);
    }
        if (win==1) {
                if (enetype==1) {
            (rat++);
            (ratt++);
                }
                if (enetype==2) (fox++);
        cout<<"Zdobywasz "<<wingold<<" golda"<<endl;
        Sleep(1500);
        (gold=gold+wingold);
        (mon++);
        system("cls");
        goto start;
        }
        if (win==0) {
        cout<<"Resztkami sil doczolgales sie do wyjscia\n"<<endl;
        Sleep(2000);
        cout<<"Zostales znaleziony i przeniesiony do miasta. Wkrotce sie obudzisz\n";
        Sleep(2000);
        system("cls");
        powrot();
        goto end;
        }
        end:
        if (walka==9) {
                powrot();
        }
}
int main(int argc, char** argv){


z:
    system("cls");
    (mon=rat+fox);
        (miasto=miasto+1);
        if(miasto==1){
                cout<<"Witaj w standardowym RPG-owym miescie\n";
                Sleep(1000);
                cout<<"Mozesz tu ulepszac ekwipunek i leczyc sie ";
                Sleep(1500);
                cout<<"oraz wykonywac rezte standardowych miejskich czynnosci RPG-owych"<<endl<<endl;
                Sleep(1500);
                cout<<"Ps zajrzyj do karczmy";
                Sleep (5000);
}
        else{
                cout<<"Witaj w miescie";
                Sleep (1000);
        }
                
                system("cls");
                
                
   	srand(time(NULL)); //to wczutujê czas z systemu           
	revent = rand()%100;
		if(revent==54){
				cout<<"Jej udalo ci sie znalezc 2 zlote cebuliony";
				(gold=gold+2);
				getchar();
				system("cls");
		}
        if(revent==53){
				cout<<"Jej udalo ci sie znalezc 2 zlote cebuliony";
				(gold=gold+2);
				getchar();
				system("cls");
		}
		if(revent==51){
				cout<<"Jej udalo ci sie znalezc 15 zlotych cebulionów";
				(gold=gold+2);
				getchar();
				system("cls");
		}
		if(revent==50){
				cout<<"Jej udalo ci sie znalezc 4 zlote cebuliony";
				(gold=gold+2);
				getchar();
				system("cls");
		}        


        if(gold<0){
                cout<<"Mafia jest niezadowolona"<<endl<<" masz u niej dlug";
                (php=php-8);
                Sleep (1000);
                system("cls");
        }


        x:
        system("cls");
        hpbar(php,mphp);
                cout<<" >"<<php<<" hp"<<endl<<pad<<" krzepy"<<endl<<par<<" pancerza"<<endl;
                cout<<"Sakiewka: "<<gold<<" zlotych cebulionow"<<endl<<endl;


                cout<<"Wybierz teraz miejsce, do ktorego chcesz sie udac:"<<endl<<" 1. Kuznia"<<endl<<" 2. Karczma"<<endl<<" 3. Klasztor"<<endl<<endl<<"0. Jesli chcesz wyruszyc na wyprawe\nTwoj wybor: ";
                cin>>zakupyn;
                system("cls");
                if(zakupyn==0){
                        walka();
                        goto z;
                }
                if(zakupyn==1){
                kowal:
                system("cls");
                cout<<"Witaj u kowala Wladka!"<<endl;
                Sleep(750);
                cout<<"Interesuja cie zbroje (1) czy bron (2)?\nA moze masz juz czego potrzebujesz (0)>:";
                cin>>kowal;
                cout<<endl;
                if (kowal==0) {
                        system("cls");
                        cout<<"Do zobaczenia nastepnym razem!";
                        Sleep(1500);
                        system("cls");
                        goto x;
                }
                if(kowal==1){
                        cout<<"W moim zakladzie oferuje"<<endl<<" 1. Zbroje skurzana - 50zc"<<endl<<"*obrazek"<<endl<<" 2.Zbroje zelazna - 300zc"<<endl<<"*obrazek"<<endl<<endl<<" 0. Jesli nic nie kupujesz "<<endl<<">:";
                        cin>>zbroja;
                        if(zbroja==0){
                                system("cls");
                                goto kowal;
                        }
                        if(zbroja==1){
                        if(gold>49){
                                (gold=gold-50);
                                (par=par+5);
                                (zbrojaskurzana++);
                        }
                        else{
                                cout<<"Nie masz wystarczajaco cebulionow";
                                Sleep (1500);
                        }
                        if(zbrojaskurzana>1){


                        cout<<"Phi! Dwie skorzane zbroje to na ciebie za duzo!";
                        Sleep (1500);
                        (par=par-5);
                        (gold=gold+50);
                        }
                }
                        if(zbroja==2){
                        if(gold>299){
                                (gold=gold-300);
                                (par=par+15);
                                (zbrojazelazna++);
                                cout<<"Interesy z toba to sama przyjemnosc";
                                Sleep(1500);
                        }
                        else{
                                cout<<"Nie masz wystarczajaco cebulionow";
                                Sleep (1500);
                        }
                        if(zbrojazelazna>1){


                        cout<<"Juz jedno takie zelastwo to dla ciebie za  duzo chuderlawcze";
                        (par=par-15);
                        (gold=gold+300);
                        Sleep (1500);
                        }
                }
                }
                if(kowal==2){
                        cout<<"Wsrod ostrzy mam:"<<endl<<" 1. Mieczyk - 50zc"<<endl<<"*obrazek"<<endl<<" 2. Miecz - 300zc"<<endl<<"*obrazek"<<endl<<" 3. Legendarny Patyk Krola Gowna - 10 000zc"<<endl<<"*obrazek"<<endl<<endl<<"Wyjscie(0)"<<endl;
                        cin>>bron;
                        if(bron==0){
                                goto kowal;
                        }
                        if(bron==1){
                        if(gold>49){
                                (gold=gold-50);
                                (pw=pw+5);
                                (mieczyk++);
                        }
                        else{
                                cout<<"niestac cie";
                                Sleep (1500);
                        }
                        if(mieczyk>1){
                        cout<<"A tak wlasciwie to po co ci dwa?";
                        (pw=pw-5);
                        (gold=gold+50);
                        Sleep (1500);
                        }
                }
                        if(bron==2){
                        if(gold>299){
                                (gold=gold-300);
                                (pw=pw+15);
                                (miecz++);
                        }
                        else{
                                cout<<"niestac cie";
                                Sleep (1500);
                        }
                        if(miecz>1){


                        cout<<"A tak wlasciwie to po co ci dwa?";
                        (pw=pw-15);
                        (gold=gold+300);
                        Sleep (1500);
                        }
                }
                        if(bron==3){
                        if(gold>9999){
                                (gold=gold-10000);
                                (pw=pw+9999999999999999);
                                (patyk++);
                        }
                        else{
                                cout<<"niestac cie";
                                Sleep (1500);
                        }
                        if(patyk>1){


                        cout<<"A tak wlasciwie to po co ci dwa?";
                        Sleep (1500);
                        (gold=gold+10000);
                        (pw=pw-9999999999999999);
                        }
                }
                }
                goto kowal;
                }
                if(zakupyn==2){
                        cout<<"witaj w karczmie chcesz poszukac roboty(1) czy napic sie piwka(2)?";
                        cin>>karczma;
                        if(karczma==1){
                                if(quest==0){
                                        if(rat<15){
                                                cout<<"quest testowy 1 15 szczurow"<<endl;
                                                Sleep (1000);
                                        }
                                        if(rat>14){
                                                cout<<"hura nast?pny"<<endl;
                                                Sleep (1000);
                                                (quest++);
                                                (mon=0);
                                        }
                                }
                                if(quest==1){
                                        if(fox<15){
                                                cout<<"quest testowy 2 15 lisow"<<endl;
                                                Sleep (1000);
                                        }
                                        if(fox>14){
                                                cout<<"hura nast?pny"<<endl;
                                                Sleep (1000);
                                                (quest++);
                                                (mon=0);
                                        }
                                }
                                        if(quest==2){
                                        if(mon<100){
                                                cout<<"quest testowy 3 100czegos"<<endl;
                                                Sleep (1000);
                                        }
                                        if(mon>99){
                                                cout<<"hura nastepny"<<endl;
                                                Sleep (1000);
                                                (quest++);
                                                (mon=0);
                                        }
                                
                        }
                        if(mon==0){
                                (rat=0);
                                (fox=0);
                        }
                }
                if(karczma==2){
                        cout<<"tu beda jaja wielkanocne";
                }
                                
                        Sleep (3000);
                goto x;
                }


                if(zakupyn==3){
                        cout<<"witaj w klasztorze siustr Nazaratanek jesli zlorzysz datek na swiatynie mozemy cie wyleczyc"<<endl<<"Czy chcesz zlozyc datek tak(1) lub nie (2)"<<endl;
                        cin>>klasztor;
                        if(klasztor==1){
                                cout<<"W jakiej wysokosci?"<<endl;
                                cin>>klasztorq;
                                if(gold<klasztorq){
                                        cout<<"nie masz tyle"<<endl;
                                        (php=php-1);
                                        Sleep (1000);
                                }
                                else{


                                (gold=gold-klasztorq);
                                if(klasztorq>5){
                                        (php=php);
                                }
                                if(klasztorq>10){
                                        (php=php+10);
                                }
                                if(klasztorq>15){
                                        (php=php+3);
                                }
                                if(klasztorq>30){
                                        (php=php+7);
                                }
                                if(klasztorq>50){
                                        (php=php+80);
                                }
                                if(php>mphp){
                                        (hp=php-mphp);
                                        (php=php-hp);
                                }
                        }
                }


                goto x;
                }
                if (zakupyn==4) {
                        system("cls");
                        cout<<"Witaj w moim labolatorioum. Czego ci potrzeba?";
                        
                }


        return 0;
                }

