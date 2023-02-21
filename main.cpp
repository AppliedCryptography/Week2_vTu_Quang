#include <iostream>
#include <string>

using namespace std;

string vigenere_cipher_enc_v2(string key, string encrypted_message) {
	int n = encrypted_message.length(), n_key = key.length();
	string rs;
	for (int i = 0; i < n; i++) {
		rs += char((tolower(encrypted_message[i]) - 97 * 2 + tolower(key[i % n_key]) + 26) % 26 + 97);
	}
	return rs;
}

string vigenere_cipher_dec(string key, string encrypted_message) {
	int n = encrypted_message.length(), n_key = key.length();
	string rs;
	for (int i = 0; i < n; i++) {
		rs += char((tolower(encrypted_message[i]) - tolower(key[i % n_key]) + 26) % 26 + 97);
	}
	return rs;
}

int main() {
	string m = "thiseryptosystemisnotsecure", k = "cipher", c = "";
	cout << "original message: " << m << endl;
	c = vigenere_cipher_enc_v2(k, m);
	cout << "encrypted message: " << c << endl;
	m = vigenere_cipher_dec(k, c);
	cout << "decrypted message: " << m << endl;
	return 0;
}