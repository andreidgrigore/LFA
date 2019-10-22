#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char M[50][50][5],c[5],cuvant[20];
int stari,tranzitii,stare_finala[5],n1,n2,nr,i,j,pozitie,numar_stari_finale;
ifstream f("automat.in");
int main()
{
    ///citirea automatului
    //cout <<"Introduceti numarul de noduri:";
    f>>stari;
    //cout<<"Introduceti numarul de tranzitii";
    f>>tranzitii;
    for(i=1;i<=tranzitii;i++){
        //cout<<"Introduceti nodul din care pleaca o litera si spre ce nod";
        f>>n1>>n2;
            //cout<<"Introduceti literele ce exista intre cele 2 noduri:";
            f>>c;
            strcat(M[n1][n2],c);
    }
    //cout<<"Introduceti starea finala";
    f>>numar_stari_finale;
    for(i=1;i<=numar_stari_finale;i++)
        f>>stare_finala[i];

    ///verificarea cuvantului
    cout<<"Introduceti cuvantul:";
    cin>>cuvant;
    bool ok=false;
    pozitie=1;
    int k=0;
    for(i=0;i<strlen(cuvant);i++)
    {
        ok=false;
        for(j=1;j<=stari;j++){
            if(strchr(M[pozitie][j],cuvant[i])){
                pozitie=j;
                ok=true;
                break;
            }
        }
        k++;
        if(ok==false)break;
    }
    if(ok!=false){
            ok=false;
    for(i=1;i<=numar_stari_finale;i++){
        if(pozitie==stare_finala[i]){ok=true;break;}
    }
    }
    if(ok==false)cout<<"NU";
    else cout<<"DA";

    return 0;
}
