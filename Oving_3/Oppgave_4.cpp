#include <iostream>
#include <string>

using namespace std;

int main(){
    // a)
    string word1, word2, word3;
    cout << "Skriv inn det første ordet: ";
    cin >> word1;
    cout<< "skriv inn det andre ordet: ";
    cin >> word2;
    cout << "Skriv inn det tredje ordet: ";
    cin >> word3;

    //b
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "Setning: " << sentence << endl;

    // c) Skriv ut lengden til hvert enkelt ord og setningen.
    cout << "Lengde av word1: " << word1.length() << endl;
    cout << "Lengde av word2: " << word2.length() << endl;
    cout << "Lengde av word3: " << word3.length() << endl;
    cout << "Lengde av sentence: " << sentence.length() << endl;

    // d) Lag en kopi av sentence.
    string sentence2 = sentence;

    // e) bytt ut tegn nr 10-12 i sentence 2 med x'er
    if(sentence2.length() > 12){
      sentence2.replace(10,3,"xxx");
    }

    cout << "Original setning: " << sentence << endl;
    cout << "Modifisert setning: " << sentence2 << endl;

    // f) Lagre de fem første tegnene i sentence.
    string sentence_start = "";
    if (sentence.length() >= 5) {
        sentence_start = sentence.substr(0, 5);
    }
    cout << "Original sentence: " << sentence << endl;
    cout << "Start av sentence: " << sentence_start << endl;

    // g) Finn ut om sentence inneholder ordet "hallo".
    if (sentence.find("hallo") != string::npos) {
        cout << "sentence inneholder 'hallo'." << endl;
    } else {
        cout << "sentence inneholder ikke 'hallo'." << endl;
    }


     // h) Finn alle forekomster i sentence av strengen "er".
    size_t pos = 0;
    int forekomst = 0;
    cout << "Forekomster av 'er' i sentence: ";
    while ((pos = sentence.find("er", pos)) != string::npos) {
        forekomst++;
        pos += 2;  // Hopp over den nåværende forekomsten for å finne den neste
    }
    cout << forekomst << endl;

    return 0;
}