
#include<bits/stdc++.h>
using namespace std;

int length(char input[]) {
    int len = 0;
    for (int i=0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}


int* getlps(char* T) {
    int tlen = length(T);
    int i = 1;
    int j = 0;
    int* lps = new int[tlen];
    lps[0] = 0;
    while(i < tlen) {
        if (T[i] == T[j]) {
            lps[i] = j+1;
            i++;
            j++;
        } else {
            if (j != 0)
                j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool findString(char S[], char T[]) {
    int slen = length(S);
    int tlen = length(T);
    
    int i=0;
    int j=0;
    int* lps = getlps(T);
    while(i < slen && j < tlen) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    
    return j ==  tlen ? true : false;
}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}
