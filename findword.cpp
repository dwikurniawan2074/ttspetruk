#include <iostream>
#include <cstring>

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

//char *getWordVertical(int);    //dwi
char *getWordVertical(int a){
static char simpan [16];
for (int i = 0;i<16;i++){
    simpan [i] = words [i][a];
}
return simpan;
}

//char *reverse(char *);         //nur
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

//bool searchVertical(char *);   //satria
bool searchVertical(char *a){
int n=0;
int boolean = 0;
char *ngecek = strstr(getWordVertical(n),a);
char *ngecekreverse = strstr(reverse(getWordVertical(n)),a);
while (n<=15){
    if (ngecek){
        boolean++;
    } else if (ngecekreverse){
    boolean++;
    }n++;
    return boolean;
    }
}

//bool searchHorizontal(char *); //satria
bool searchHorizontal(char *a){
int n = 0;
int boolean = 0;
static char horizontal[16];
char *ngecek = strstr(horizontal,a);
char *ngecekreverse = strstr(reverse(horizontal),a);
while (n<=15){
    for (int i = 0;i<16;i++){
        horizontal [i] = words[n][i];
    }

    if (ngecek){
        boolean++;
    } else if (ngecekreverse){
    boolean++;
    }n++;
    return boolean;
}

}



int main()
{
    char word[16];
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else 
            cout << "Tidak Ada\n";
    }
    return 0;
}
