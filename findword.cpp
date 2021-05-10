#include <iostream>
#include <algorithm>
#include <cstring>

/*
Nama Anggota Kelompok : 
Dwi Kurniawan (2017051074)
Nur Setiowati (2017051013)
Satria Sapta Nugraha (2017051022)
                     
Link Github : https://github.com/dwikurniawan2074/ttspetruk/edit/main/findword.cpp
*/

using namespace std;
const int cols = 16, rows = 15;

 char words[rows][cols] = {"tgbwwinterwsesn",
                                "aaunttmmhfoodnb",
                                "jlwcqldzmpmvdmr",
                                "asagmquwvvbsohi",
                                "bwplotanadtpgnc",
                                "rewngodjcpnatnk",
                                "eeotwosbqharrsa",
                                "azcgeswewnaknpb",
                                "dinnerqodlwdcar",
                                "onopkwmparktzcc",
                                "qbfrogmamwpweey",
                                "lqzqnnmrzjjsclg",
                                "mosgzczetdbooto",
                                "pdcrzmsngrdnrpz",
                                "ohnkzwaterjgtra"};

char *getWordVertical(int a);    //nur
char *reverse(char *a );         //dwi
bool searchVertical(char *a );   //satria
bool searchHorizontal(char *a ); //satria


int main()
{
    char word[16];
    int n;
    cin>>n;
    cin.ignore(1,'\n');
    for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else
            cout << "Tidak Ada\n";
    }
    return 0;
}

//nur
char *getWordVertical(int a){
static char simpan [16];
for (int i = 0;i<16;i++){
    simpan [i] = words [i][a];
}
return simpan;
}

//dwi
char *reverse(char *a){
int panjang_huruf = strlen(a);
int nentuin = 0;
static char simpan_reverse[16];
for (int i = panjang_huruf-1; i>=0;i--){
    simpan_reverse[nentuin] = a[i];
    nentuin++;
}
return simpan_reverse;
}

//satria
bool searchVertical(char *a){
int n=0;
int boolean = 0;

while (n<=15){
    char *ngecek = strstr(getWordVertical(n),a);
    char *ngecekreverse = strstr(reverse(getWordVertical(n)),a);
    if (ngecek){
        boolean++;
    } else if (ngecekreverse){
    boolean++;
    }n++;

    }
return boolean;

}

//satria
bool searchHorizontal(char *a){
int n = 0;
int boolean = 0;
static char horizontal[16];

while (n<=15){
    char *ngecek = strstr(horizontal,a);
    char *ngecekreverse = strstr(reverse(horizontal),a);
    for (int i = 0;i<16;i++){
        horizontal [i] = words[n][i];
    }

    if (ngecek){
        boolean++;
    } else if (ngecekreverse){
    boolean++;
    }n++;

}
    return boolean;
}
