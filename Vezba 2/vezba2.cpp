#include <iostream>
#include <vector>
#include <ctime>

// Elena Desanoska INKI 767

using namespace std;

enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES}; // enumeracija na cetirite simboli
const string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"}; // iminja na simbolite

class Card {
public:
    Card(int value, Suit suit) : m_value(value), m_suit(suit) {}

    // funkcija za dobivanje na valutata i simbolot na kartata
    int getValue() const { return m_value; }
    Suit getSuit() const { return m_suit; }

   // funkcija za pecatenje na valutata i simbolot na kartata
    void printCard() const {
        if (m_value == 0) {
            if (m_suit == HEARTS) {
                cout << "Red Joker" << endl;
            } else if (m_suit == SPADES) {
                cout << "Black Joker" << endl;
            } else {
                cout << "Invalid joker" << endl;
            }
        } else {
            cout << getValueName() << " of " << getSuitName() << endl;
        }
    }

private:
    int m_value; // vrednost na kartata (1-13 ili 0 za jokerite)
    Suit m_suit; // simbolot na kartata

    // privatna pomosna funkcija za pretvaranje na valutata i simbolot na kartata vo stringovi citlivi za covek
    string getValueName() const {
        switch(m_value) {
            case 1: return "Ace";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Jack";
            case 12: return "Queen";
            case 13: return "King";
            default: return "";
        }
    }

    string getSuitName() const {
        return suits[m_suit];
    }
};

class Deck {
public:
    Deck() {
        
        // kreira standarden spil od 52 karti
        for (int i = 1; i <= 13; i++) {
            for (int j = 0; j < 4; j++) {
                m_cards.push_back(Card(i, static_cast<Suit>(j)));
            }
        }

        // gi dodava jokerite
        m_cards.push_back(Card(0, HEARTS)); // crven joker
        m_cards.push_back(Card(0, SPADES)); // crn joker
    }

    void shuffle() {
        srand(time(NULL)); // postavuvanje na generatorot po slucaen broj so tekovnoto vreme
        int n = m_cards.size();

        for (int i = n - 1; i > 0; i--) {
            
            // odbira slucaen index od 0 do i
            int j = rand() % (i + 1);

            // zamenuva m_cards[i] so m_cards[j]
            Card temp = m_cards[i];
            m_cards[i] = m_cards[j];
            m_cards[j] = temp;
        }
    }

    void printDeck() const {
        for (auto card : m_cards) {
            card.printCard();
        }
    }

private:
    vector<Card> m_cards; // vector za drzenje na kartite vo spilot
};

int main() {
    Deck deck;
    cout << "Printing deck before shuffling: " << endl;
    deck.printDeck(); // go pecati spilot pred mesanje
    deck.shuffle(); // go mesa spilot
    cout << "Printing deck after shuffling: " << endl;
    deck.printDeck(); // go pecati spilot posle mesanje
    return 0;
}
