#include <iostream>
#include <string>
using namespace std;
// Funcion para cifrar o descifrar texto utilizando XOR
string xorEncryptDecrypt(const string& input, const string& key) {
    string output = input;
    // Iteramos sobre cada caracter del texto
    for (size_t i = 0; i < input.size(); ++i) {
        // Aplicamos la operacion XOR entre el caracter del texto y el caracter de la clave
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;
}
int main() {
    string text;
    string key;
    // Solicitamos al usuario que ingrese el texto a cifrar
    cout << "Ingrese el texto a cifrar: ";
    getline(cin, text);
    // Solicitamos al usuario que ingrese la clave de cifrado
    cout << "Ingrese la clave de cifrado: ";
    getline(cin, key);
    // Cifrado del texto
    string encryptedText = xorEncryptDecrypt(text, key);
    cout << "Texto cifrado: " << encryptedText << endl;
    // Descifrado del texto
    string decryptedText = xorEncryptDecrypt(encryptedText, key);
    cout << "Texto descifrado: " << decryptedText << endl;
    return 0;
}
