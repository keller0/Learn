public class Deck {
    public static int numberSuits = 4;
    public static int numberRank = 13;
    public static int numberCards = numberRank*numberSuits;

    private Card[][] cards;

    public Deck() {
        cards = new Card[numberSuits][numberRank];
        for(int suit = Card.DIAMONDS; suit <= Card.SPADES; suit++) {
            for(int rank = Card.ACE; rank <= Card.KING; rank ++) {
                cards[suit-1][rank-1] = new Card(rank,suit);
            }
        }
    }

    public Card getCard(int suit,int rank) {
        return cards[suit-1][rank-1];
    }

    public static void main(String[] args) {
        Deck d1 = new Deck();
        Card c1 = d1.getCard(1, 2);
        System.out.println(Card.suitToString(c1.getSuit()));
        System.out.println(Card.rankToString(c1.getRank()));

    }
}