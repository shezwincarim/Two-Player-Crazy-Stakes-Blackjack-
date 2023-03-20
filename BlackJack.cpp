#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using std::vector;
using std::string;

enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,TEN,JACK,QUEEN,KING,ACE};
enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};


struct Card {
	Rank rank;
	Suit suit;
	int num_suits = 4;
	int num_ranks = 12;
};
struct Deck {
	vector <Card> cards;
	string card_back;
	int max_deck_size = 52;
};

void initialize(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);
void shuffle(Deck&);
bool deal_cards(Deck&, vector<Card>&, int);
bool deal_cards2(Deck&, vector<Card>&, int);
bool deal_cards3(Deck&, vector<Card>&, int);
void print_hand(const vector<Card>&);

int main()
{
	char input;
	srand(time(nullptr));
	Deck my_deck;
	initialize(my_deck);
	std::cout << '\n';
	shuffle(my_deck);
	//print_deck(my_deck);
	

	vector<Card> hand_1;
	vector<Card> hand_2;
	vector<Card> hand_3;
	deal_cards(my_deck, hand_1, 1);
	deal_cards(my_deck, hand_2, 1);
	deal_cards(my_deck, hand_3, 1);
	

	
	//print_deck(my_deck);
}

void initialize(Deck& deck)
{
	Card card; 
	for (int suit = 0; suit < card.num_suits; suit++)
	{
		for (int rank = 0; rank < card.num_ranks; rank++)
		{
				card.suit = Suit(suit);
				card.rank = Rank(rank);
				deck.cards.push_back(card);
		}
	}
	
}

void print_deck(const Deck& deck)
{
	for (Card c : deck.cards)
	{
		print_card(c);
	}
}

void print_card(const Card& card)
{

	string rank_names[] = { "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };
	string suit_names[] = { "SPADES", "HEARTS", "DIAMONDS", "CLUBS" };
	

	std::cout << "Rank = " << rank_names[card.rank] << "  "
		<< "Suit = " << suit_names[card.suit] << '\n';
}

void shuffle(Deck& deck)
{
	Deck shuffled;
	while (!deck.cards.empty())
	{
		size_t rand_index = rand() % deck.cards.size();
		shuffled.cards.push_back(deck.cards[rand_index]);
		deck.cards.erase(deck.cards.begin() + rand_index);
	}

	deck = shuffled;
}

bool deal_cards(Deck& deck, vector<Card>& hand_1, int num_cards)
{
	if (deck.cards.size() < 2 * num_cards)
	{
		return false;
	}

	for (int card = 0; card < num_cards; card++)
	{
		hand_1.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());
		
	}

	return true;
}
bool deal_cards2(Deck& deck, vector<Card>& hand_2, int num_cards)
{
	if (deck.cards.size() < 2 * num_cards)
	{
		return false;
	}

	for (int card = 0; card < num_cards; card++)
	{
		hand_2.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());

	}

	return true;
}

bool deal_cards3(Deck& deck, vector<Card>& hand_3, int num_cards)
{
	if (deck.cards.size() < 2 * num_cards)
	{
		return false;
	}

	for (int card = 0; card < num_cards; card++)
	{
		hand_3.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());

	}

	return true;
}


void print_hand(const vector<Card>& hand)
{
	for (Card c : hand)
	{
		print_card(c);
	}
}
