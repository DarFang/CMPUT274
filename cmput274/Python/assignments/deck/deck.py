import sys


class Deck:
    """
    Stores playing cards
    """
    
    def __init__(self, cards):
        '''Initializes attribute for deck of cards
        
        Arguments:
            cards: list of two-character strings representing cards
        '''
        self.__deck = cards
        self.__size = len(cards)

    def __iter__(self):
        return self
        
    def deal(self):
        '''Deals one card from top of deck.
        
        Returns:
            Either the top card (first element in the deck list), or
            False if there are no cards left in the deck
        '''
        if len(self.__deck) > 0:
            return self.__deck.pop(0)  # Draws a card
        else:
            return False

    def validate(self):
        '''Checks whether the deck is a valid 52 card deck or not.
        
        Returns:
           (is_valid, msg): a tuple containing a Boolean value indicating whether
                            the deck is valid (True) or not (False), and a string
                            that is either empty (when deck is valid) or contains
                            information about why the deck is no valid
        '''
 
        val = True
        out = ""
        rank = list("AKQJT98765432")  # Possible ranks
        suite = list("SDCH")  # Possible suites
        card = ""

        i = 0
        while i < (self.__size):
            if (self.__deck[i][0] in rank) and (self.__deck[i][1] in suite):  # Is the card valid
                i += 1

            else:
                card = str(self.__deck[i])  # Card is invalid
                i = int(self.__size)
                val = False

        if val is False:
            out = "Card " + card + " is not a valid card"

        elif self.__size < 52:  # not enough cards
            out = "Incomplete deck"
            val = False

        else:
            check = []
            for i, j in self.__deck:
                k = (i + j)
                if k not in check:  # Is the card in the pile aready
                    check.append(k)

                else:
                    val = False
                    out = "Deck contains duplicae cards"

        return (val, out)  # Valid deck, string output

    def __str__(self):
        '''Creates custom string to represent deck object

        Returns:
           String representation of deck object
        '''

        return "-".join(self.__deck)
       

def openfile(fname):
    ''' opens the file of the deck

    Arguments:
        String fname, The argument from the terminal input

    Returns:
        list representing the deck
    '''

    rfile = open(fname, "r")
    deckL = rfile.read().upper().split()
    return deckL


def High_Card_Draw(deck):
    ''' The game high card draw where 2 cards are compared and outputs whoever wins that round

    Arguments:
        Object deck representing the deck of cards

    Returns:
        nothing, just outputs whoever won that rounf
    '''

    rank = list("23456789TJQKA")
    opp = deck.deal()  # Player gets a card
    deal = deck.deal()  # Dealer gets a card
    i = 0

    while opp is not False and deal is not False:
        i += 1

        if rank.index(deal[0]) > rank.index(opp[0]):  # Dealer has higher card
            print("Round " + str(i) + ": Dealer wins!")

        elif rank.index(deal[0]) < rank.index(opp[0]):  # Player has higher card
            print("Round " + str(i) + ": Player wins!")

        else:
            print("Round " + str(i) + ": Tie!")  # Tie
        opp = deck.deal()
        deal = deck.deal()


if __name__ == "__main__":
    deckL = openfile(sys.argv[1])  # Open file
    deckS = Deck(deckL)  # Creates a class
    (valid, string) = deckS.validate()  # If Valid deck, output String
    if valid is True:  # Valid deck
        High_Card_Draw(deckS)
    else:
        print(string)  # Not valid deck
    pass