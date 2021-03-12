#include<iostream>
#include<string>

using namespace std;

int find(char a, char key[], bool isLower){
    int i;
    if(!isLower) a = char(int(a) - 32);
    for(i=0;i<25;i++){
        if(a == key[i]){
            if(isLower) return (i + 97);
            else return (i + 65);
        }
    }
}

string encrypt(string s, char key[]){
    string cipher;
    for(int i=0;i<s.length();i++){
        if(int(s[i])>=65 && int(s[i])<=90) cipher +=  char(int(key[int(s[i]) - 65])-32);
        else if(int(s[i])>=97 && int(s[i])<=122) cipher += char(key[int(int(s[i]) - 97)]);
        else cipher += char(int(s[i]));
    }
    cout << cipher;
    return cipher;
}

string decrypt(string s, char key[]){
    string decipher;
    for(int i=0;i<s.length();i++){
        if(int(s[i])>=65 && int(s[i])<=90) decipher += char(find(char(s[i]),key,false));
        else if(int(s[i])>=97 && int(s[i])<=122) decipher += char(find(char(s[i]),key,true));
        else decipher += char(int(s[i]));
    }
    return decipher;
}

int main(){
    char key[26];
    string input;
    string output;
    cout << "Plain text : ";
    getline(cin,input);

    cout << "Enter key alphabetic substitution for every letter with space in lowercase" << endl;
    cout << "a b c d e f g h i j k l m n o p q r s t u v w x y z" << endl;
    for(int i=0;i<26;i++) cin >> key[i];
    output = encrypt(input, key);
    cout << endl << "Encryption : " << output;
    cout << endl << "Decryption : " << decrypt(output,key);
}