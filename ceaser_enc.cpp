#include<iostream>
#include<string>

using namespace std;

inline int mod(int a, int b) {
  const int result = a % b;
  return result >= 0 ? result : result + b;
}

string encrypt(string s, int key){
    string cipher;
    for(auto i=0;i<s.length();i++){
        if(int(s[i])>=65 && int(s[i])<=90) cipher += char(int((s[i]) + key - 65)%26 + 65);
        else if(int(s[i])>=97 && int(s[i])<=122) cipher += char(int((s[i]) + key - 97)%26 + 97);
        else cipher += char(int(s[i]));
    }
    return cipher;
}

string decrypt(string s, int key){
    string decipher;
    for(auto i=0;i<s.length();i++){
        if(int(s[i])>=65 && int(s[i])<=90) decipher += char(int(mod((s[i]) - key - 65,26) + 65));
        else if(int(s[i])>=97 && int(s[i])<=122) decipher += char(int(mod((s[i]) - key - 97,26) + 97));
        else decipher += char(int(s[i]));
    }
    return decipher;
}

int main(){
    string input,output;
    int key;
    cout << "Enter PlainText : ";
    getline(cin,input);
    cout << endl << "Enter Key Value : ";
    cin >> key;

    output = encrypt(input,key);
    cout << endl << "Encryption : " << output;
    cout << endl << "Decryption : " << decrypt(output,key);
}