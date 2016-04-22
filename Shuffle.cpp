#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

string AllCards[52] = {"Spades(A)", "Spades(2)", "Spades(3)", "Spades(4)", "Spades(5)", "Spades(6)",
                       "Spades(7)", "Spades(8)", "Spades(9)", "Spades(10)", "Spades(J)", "Spades(Q)",
                       "Spades(K)",
    
                       "Hearts(A)", "Hearts(2)", "Hearts(3)", "Hearts(4)", "Hearts(5)", "Hearts(6)",
                       "Hearts(7)", "Hearts(8)", "Hearts(9)", "Hearts(10)", "Hearts(J)", "Hearts(Q)",
                       "Hearts(K)",
    
                       "Diamonds(A)", "Diamonds(2)", "Diamonds(3)", "Diamonds(4)", "Diamonds(5)", "Diamonds(6)",
                       "Diamonds(7)", "Diamonds(8)", "Diamonds(9)", "Diamonds(10)", "Diamonds(J)", "Diamonds(Q)",
                       "Diamonds(K)",

                       "Clubs(A)", "Clubs(2)", "Clubs(3)", "Clubs(4)", "Clubs(5)", "Clubs(6)",
                       "Clubs(7)", "Clubs(8)", "Clubs(9)", "Clubs(10)", "Clubs(J)", "Clubs(Q)",
                       "Clubs(K)"};

void prompt(string[]);
void shuffle(string[]);

int main() {
    
    string Deck[52];
    prompt(Deck);
    
    return 0;
}


void prompt(string deck[]) {
    
    char ans = 'Y';
    
    cout << "Do you want to shuffle the cards?";
    cout << "\nEnter [Y/N]\t";
    
    cin.get(ans);
    cin.ignore();
    
    while (toupper(ans) != 'Y' && toupper(ans) != 'N') {
        cout << "Invalid input [Enter Y/N]\t";
        cin.get(ans);
        cin.ignore();
    }
    
    if (toupper(ans) == 'Y') {
        shuffle(deck);
    } else cout << "Thank you and goodbye....." << endl;
}


void shuffle(string deck[]) {
    
    int check;
    int uniquenessCheck[56] = {0};
    const int MIN_VAL = 0, MAX_VAL = 51;
    
    unsigned seed = time(0);
    srand(seed);
    
    for (int i = 0; i < 52; i++) {
        
        do {
            check = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL; //check format
        } while (uniquenessCheck[check] == 1);
        cout << check << " ";
        uniquenessCheck[check] = 1;
        deck[i] = AllCards[check];
    }
}