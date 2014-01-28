// Project Euler Problem: 54
// Goal: Find the number of hands won by player one from the text file.
// Author: Cooper Bell

#include <stdio.h>
#include <stdbool.h>
#define HAND_LENGTH 5   /* number of cards in a hand */
#define MAXLINE 10000   /* maximum file size */


FILE *fr;  /* file pointer */

struct hand {   /* struct for dealt hand */
        char rank[HAND_LENGTH];
        char suit[HAND_LENGTH];
};

/* functions */
char winninghand(struct hand player_one, struct hand player_two);
bool royalflush(struct hand player);
bool straightflush(struct hand player);
bool fourofakind(struct hand player);
bool fullhouse(struct hand player);
bool flush(struct hand player);
bool straight(struct hand player);
bool threeofakind(struct hand player);
bool twopairs(struct hand player);
bool onepair(struct hand player);
char highcard(struct hand player);
char nexthighcard(struct hand player);
char compare(char one, char two);
int chartoint(char c);
char inttochar(int i);
char tie_break_onepair(struct hand player_one, struct hand player_two);
char tie_break_twopairs(struct hand player_one, struct hand player_two);
char tie_break_threeofakind(struct hand player_one, struct hand player_two);
char tie_break_straight(struct hand player_one, struct hand player_two);
char tie_break_flush(struct hand player_one, struct hand player_two);
char tie_break_fullhouse(struct hand player_one, struct hand player_two);
char tie_break_fourofakind(struct hand player_one, struct hand player_two);
char tie_break_straightflush(struct hand player_one, struct hand player_two);


main()
{
    struct hand player_one;     /* hand struct for player one */
    struct hand player_two;     /* hand struct for player two */
    int player_one_wins = 0;    /* wins by player one */
    int player_two_wins = 0;    /* wins by player two */
    int count = 0;              /* character count */
    char c;                     /* char from the file */
    int onecountrank = 0;       /* count for first array */
    int onecountsuit = 0;       /* count for first array */
    int twocountrank = 0;       /* count for second array */
    int twocountsuit = 0;       /* count for second array */

    /* text file of poker hands */
    fr = fopen("poker.txt", "rt");
   
    while ((c = getc(fr)) != EOF) {
        /* divide line into two hand with rank suit */
        if (c != '\n') {
            if (count < 15) {
                if ((count % 3) == 0)
                    player_one.rank[onecountrank++] = c;
                else if (((count-1) % 3) == 0)
                    player_one.suit[onecountsuit++] = c;
            } else {
                if ((count % 3) == 0)
                    player_two.rank[twocountrank++] = c;
                else if (((count-1) % 3) == 0)
                    player_two.suit[twocountsuit++] = c;
            }
            ++count;
        } else {
            count = onecountrank = onecountsuit = twocountrank = twocountsuit = 0;
            if (winninghand(player_one, player_two) == '1') {
                ++player_one_wins;
                
                /* DBUG PRINTING BEGIN */
                #ifndef DBUG
                printf("player one wins\n");
                #endif 
                /* DBUG PRINTING BEGIN */
            } else {
                ++player_two_wins;

                /* DBUG PRINTING BEGIN */
                #ifndef DBUG
                printf("player two wins\n");
                #endif
                /* DBUG PRINTING BEGIN */
            }

            /* DBUG PRINTING BEGIN */
            #ifndef DBUG
            printf("player one: %c%c %c%c %c%c %c%c %c%c\t",player_one.rank[0]
                                                           ,player_one.suit[0]
                                                           ,player_one.rank[1]
                                                           ,player_one.suit[1]
                                                           ,player_one.rank[2]
                                                           ,player_one.suit[2]
                                                           ,player_one.rank[3]
                                                           ,player_one.suit[3]
                                                           ,player_one.rank[4]
                                                           ,player_one.suit[4]);

            printf("player two: %c%c %c%c %c%c %c%c %c%c\n",player_two.rank[0]
                                                           ,player_two.suit[0]
                                                           ,player_two.rank[1]
                                                           ,player_two.suit[1]
                                                           ,player_two.rank[2]
                                                           ,player_two.suit[2]
                                                           ,player_two.rank[3]
                                                           ,player_two.suit[3]
                                                           ,player_two.rank[4]
                                                           ,player_two.suit[4]);
            printf("\n");
            #endif /* prints all of the hands by each player + who won and the particular
                      hand played (see 'winninghand' function below */
            /* DBUG PRINTING END */
        }
    }

    printf("player one wins: %d\nplayer two wins: %d", player_one_wins, player_two_wins);

    return 0;
}


/* winninghand: determines the winning hand of two dealt hands */
char winninghand(struct hand player_one, struct hand player_two) {
    int i, one_hand = -1, two_hand = -1;

    bool player_one_hand[9] = { onepair(player_one),
                                twopairs(player_one),
                                threeofakind(player_one),
                                straight(player_one),
                                flush(player_one),
                                fullhouse(player_one),
                                fourofakind(player_one),
                                straightflush(player_one),
                                royalflush(player_one) };

    bool player_two_hand[9] = { onepair(player_two),
                                twopairs(player_two),
                                threeofakind(player_two),
                                straight(player_two),
                                flush(player_two),
                                fullhouse(player_two),
                                fourofakind(player_two),
                                straightflush(player_two),
                                royalflush(player_two) };

    
    /* DBUG PRINTING BEGIN */
    #ifndef DBUG
    const char *names[9] = { "one pair",
                             "two pairs",
                             "three of a kind",
                             "straight",
                             "flush",
                             "full house",
                             "four of a kind",
                             "straight flush",
                             "royal flush" };
    #endif
    /* DBUG PRINTING END */



    /* checks for true valuesin 'check' array, assumes that
     * higher values are the real hand played (i.e. a full house is
     * also shown to be a three of a kind as well */
    for (i = 0; i < 9; i++) {
        if (player_one_hand[i] == true)
            one_hand = i;
        if (player_two_hand[i] == true)
            two_hand = i;
    }
    


    /* DBUG PRINTING BEGIN */
    #ifndef DBUG
    if (one_hand == -1)
        printf("player one: high hand\t\t");
    else
        printf("player one: %s\t\t", names[one_hand]);
    if (two_hand == -1)
        printf("player two: high hand\n");
    else
        printf("player two: %s\n", names[two_hand]);
    #endif
    /* DBUG PRINTING END */


    if (one_hand > two_hand)
        return '1';
    else if (one_hand < two_hand)
        return '2';
    
    /* if hands are the same, check for tie break */
    else if ((one_hand == two_hand) && (one_hand != -1)) {
        if (one_hand == 0)
            tie_break_onepair(player_one, player_two);
        else if (one_hand == 1)
            tie_break_twopairs(player_one, player_two);
        else if (one_hand == 2)
            tie_break_threeofakind(player_one, player_two);
        else if (one_hand == 3)
            tie_break_straight(player_one, player_two);
        else if (one_hand == 4)
            tie_break_flush(player_one, player_two);
        else if (one_hand == 5)
            tie_break_fullhouse(player_one, player_two);
        else if (one_hand == 6)
            tie_break_fourofakind(player_one, player_two);
        else if (one_hand == 7)
            tie_break_straightflush(player_one, player_two);

    } else { /* tie break between two high hands */
        char one = highcard(player_one), 
             two = highcard(player_two); 

        int intone = chartoint(one),
            inttwo = chartoint(two);

        if (intone < inttwo)
            return '2';
        else if (intone > inttwo)
            return '1';
        else { /* both have the same high card */
            intone = chartoint(nexthighcard(player_one));
            inttwo = chartoint(nexthighcard(player_two));
            if (intone < inttwo)
                return '2';
            if (intone > inttwo)
                return '1';

            /* no functionality yet for when both
             * highest and next highest cards in
             * the hand are the same */
        }
    }
}

/* royalflush: checks if a hand is a royal flush */
bool royalflush(struct hand player) {
    int i, matches = 0;
    for (i = 0; i < HAND_LENGTH; i++)
        if (player.suit[i] == player.suit[i-1])
            ++matches;


    if (matches == 4) { /* check if all the same suit */
        bool ten   = false, 
             jack  = false,
             queen = false,
             king  = false,
             ace   = false;

        for (i = 0; i < HAND_LENGTH; i++) { /* if so, check for T, J, Q, K & A */
            if (player.rank[i] == 'T')
                ten = true;
            else if (player.rank[i] == 'J')
                jack = true;
            else if (player.rank[i] == 'Q')
                queen = true;
            else if (player.rank[i] == 'K')
                king = true;
            else if (player.rank[i] == 'A')
                ace = true;
        }
        
        if ((ten && jack && queen && king && ace) == true)
            return true;

    } else {
        return false;
    }
}

/* straightflush: checks if a hand is a straight flush */
bool straightflush(struct hand player) {
    int i, j, k, matches = 0;
    for (i = 0; i < HAND_LENGTH; i++)
        if (player.suit[i] == player.suit[i-1])
            ++matches;


    if (matches == 4) { /* check for suits out of 'poss_hands' */
        char poss_hands[13][HAND_LENGTH] = { {'1', '2', '3', '4', '5'},
                                             {'2', '3', '4', '5', '6'},
                                             {'3', '4', '5', '6', '7'},
                                             {'4', '5', '6', '7', '8'},
                                             {'5', '6', '7', '8', '9'},
                                             {'6', '7', '8', '9', 'T'},
                                             {'7', '8', '9', 'T', 'J'},
                                             {'8', '9', 'T', 'J', 'Q'},
                                             {'9', 'T', 'J', 'Q', 'K'},
                                             /* skip the royal flush */
                                             {'J', 'Q', 'K', 'A', '1'},
                                             {'Q', 'K', 'A', '1', '2'},
                                             {'K', 'A', '1', '2', '3'},
                                             {'A', '1', '2', '3', '4'} };

        for (j = 0; j < 13; j++) { /* loop through possible hands */
            bool check[HAND_LENGTH] = {false, false, false, false, false};
            char curr[HAND_LENGTH]  = {'0', '0', '0', '0', '0'};

            for (i = 0; i < HAND_LENGTH; i++)           /* loop through hand of 'player' */
                for (k = i+1; k < HAND_LENGTH; k++)     /* determine if current 'poss_hand' is 'player' hand */
                    if (player.rank[i] == poss_hands[j][k]) {
                        curr[i] = player.rank[i];
                        check[i] = true;
                    }

            if ((check[0] && check[1] && check[2] && check[3] && check[4]) == true) {
                int l, m;
                for (l = 0; l < HAND_LENGTH; l++)
                    for (m = l+1; m < HAND_LENGTH; m++)
                        if (curr[l] == curr[m])
                            return false;
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

/* fourofakind: checks if a hand is a four of a kind */
bool fourofakind(struct hand player) {
    int i, j;
    for (i = 0; i < HAND_LENGTH; i++) { /* compare hand against itself for matches */
        int count = 0;  /* number of identical cards */
        for (j = i+1; j < HAND_LENGTH; j++) {
            if (player.rank[j] == player.rank[i])
                ++count;
        }
        if (count == 3)
            return true;
    }
    return false;
}

/* fullhouse: checks if a hand is a full house */
bool fullhouse(struct hand player) {
    if (threeofakind(player) == true) {
        int i, j;
        for (i = 0; i < HAND_LENGTH; i++) {
            int count = 0;
            for (j = 0; j < HAND_LENGTH; j++) {
                if (player.rank[j] == player.rank[i])
                    ++count;
            }
            if (count == 2) 
                return true;
        }
        return false;
    }
}

/* flush: checks if a hand is a flush */
bool flush(struct hand player) {
    int i, matches = 0;
    for (i = 0; i < HAND_LENGTH; i++)
        if (player.suit[i] == player.suit[i-1])
            ++matches;
    if (matches == 4) 
        return true;
    return false;
}

/* straight: checks if a hand is a straight */
bool straight(struct hand player) {
    int i, j, k;
    char poss_hands[14][HAND_LENGTH] = { {'1', '2', '3', '4', '5'},
                                         {'2', '3', '4', '5', '6'},
                                         {'3', '4', '5', '6', '7'},
                                         {'4', '5', '6', '7', '8'},
                                         {'5', '6', '7', '8', '9'},
                                         {'6', '7', '8', '9', 'T'},
                                         {'7', '8', '9', 'T', 'J'},
                                         {'8', '9', 'T', 'J', 'Q'},
                                         {'9', 'T', 'J', 'Q', 'K'},
                                         {'T', 'J', 'Q', 'K', 'A'},
                                         {'J', 'Q', 'K', 'A', '1'},
                                         {'Q', 'K', 'A', '1', '2'},
                                         {'K', 'A', '1', '2', '3'},
                                         {'A', '1', '2', '3', '4'} };

    for (j = 0; j < 14; j++) { /* loop through possible hands */
        bool check[HAND_LENGTH] = {false, false, false, false, false};
        char curr[HAND_LENGTH]  = {'0', '0', '0', '0', '0'};

        for (i = 0; i < HAND_LENGTH; i++)       /* loop through hand of 'player' */
            for (k = 0; k < HAND_LENGTH; k++)   /* determine if current 'poss_hand' is 'player' hand */
                if (player.rank[i] == poss_hands[j][k]) {
                    check[i] = true;
                    curr[i] = player.rank[i];
                }
    
        if ((check[0] && check[1] && check[2] && check[3] && check[4]) == true) {
            /* check for duplicates */
            int l, m;
            for (l = 0; l < HAND_LENGTH; l++)
                for (m = l+1; m < HAND_LENGTH; m++)
                    if (curr[l] == curr[m])
                        return false;
            return true;
        }
    }
}

/* threeofakind: checks if a hand is a three of a kind */
bool threeofakind(struct hand player) {
    int i, j;
    bool three = false;
    for (i = 0; i < HAND_LENGTH; i++) {
        int count = 0;
        for (j = 0; j < HAND_LENGTH; j++) {
            if (player.rank[j] == player.rank[i])
                ++count;
        }
        if (count == 3)
            return true;
    }
    return false;
}

/* twopairs: checks if a hand has two pairs */
bool twopairs(struct hand player) {
    int i, j, pair = 0;
    for (i = 0; i < HAND_LENGTH; i++) {
        int count = 0;
        for (j = i+1; j < HAND_LENGTH; j++) {
            if (player.rank[j] == player.rank[i])
                ++count;
        }
        if (count == 1)
            ++pair;
    }
    if (pair == 2)
        return true;
    return false;
}

/* onepair: checks if a hand has one pair */
bool onepair(struct hand player) {
    int i, j;
    for (i = 0; i < HAND_LENGTH; i++) {
        int count = 0;
        for (j = i+1; j < HAND_LENGTH; j++) {
            if (player.rank[j] == player.rank[i])
                ++count;
        }
        if (count == 1)
            return true;
    }
    return false;
}

/* highcard: returns a hand's highest card */
char highcard(struct hand player) {
    int i, j,  
        high = chartoint(player.rank[0]);
    for (i = 1; i < HAND_LENGTH; i++) {
        int temp = chartoint(player.rank[i]);
        if (high < temp)
            high = temp;
    }
    return inttochar(high);
}

/* nexthighcard: returns a hand's next highest card */
char nexthighcard(struct hand player) {
    int i, j, high;
    char highcrd = highcard(player);
    if (compare(player.rank[0], highcrd) == '2')
        high = chartoint(player.rank[0]);
    else {
        for (j = 1; j < HAND_LENGTH; j++) {
            if (compare(player.rank[j], highcrd) != '0') {
                high = chartoint(player.rank[j]);
                break;
            }
        }
    }

    for (i = 1; i < HAND_LENGTH; i++) {
        int temp = chartoint(player.rank[i]);
        if (compare(temp, highcrd) != '0') {
            if (high < temp)
                high = temp;
        }
    }
    return inttochar(high);
}

/* compare: compares two cards and produces the highest */
char compare(char one, char two) {
    int intone = chartoint(one),
        inttwo = chartoint(two);
    
    /* check for highest value */
    if (intone < inttwo)
        return '2';
    else if (intone > inttwo)
        return '1';
    else /* values are equal */
        return '0';
}

/* chartoint: converts a card's char representation to an int for comparison */
int chartoint(char c) {
    int ace   = 62,
        king  = 61,
        queen = 60,
        jack  = 59,
        ten   = 58;

    int i;
    if (c == 'A')
        i = ace;
    else if (c == 'K')
        i = king;
    else if (c == 'Q')
        i = queen;
    else if (c == 'J')
        i = jack;
    else if (c == 'T')
        i = ten;
    else
        i = c;

    return i;
}

/* inttochar: converts an integer to its correct card representation */
char inttochar(int i) {
    int ace   = 62,
        king  = 61,
        queen = 60,
        jack  = 59,
        ten   = 58;

    char c;
    if (i == ace)
        c = 'A';
    else if (i == king)
        c ='K';
    else if (i == queen)
        c = 'Q';
    else if (i == jack)
        c = 'J';
    else if (i == ten)
        c = 'T';
    else
        c = i;
    return c;
}

/* tie_break_onepair: breaks ties between two hands with pairs */
char tie_break_onepair(struct hand player_one, struct hand player_two) {
    int i, j;
    char one, two;
    for (i = 0; i < HAND_LENGTH; i++) {
        for (j = i+1; j < HAND_LENGTH; j++) {
            if (player_one.rank[j] == player_one.rank[i])
                one = player_one.rank[i];
            if (player_two.rank[j] == player_two.rank[i])
                two = player_two.rank[i];
        }
    }
    if (compare(one, two) == '1')
        return '1';
    else if (compare(one, two) == '2')
        return '2';
    else {
        if (compare(highcard(player_one), highcard(player_two)) == '1')
            return '1';
        else
            return '2';
    }
}

/* tie_break_twopairs: breaks ties between two hands with two pairs */
char tie_break_twopairs(struct hand player_one, struct hand player_two) {
    int i, j;
    char highone, hightwo;
    for (i = 0; i < HAND_LENGTH; i++) {
        for (j = i+1; j < HAND_LENGTH; j++) {
            if ((player_one.rank[j] == player_one.rank[i]) &&
                (compare(player_one.rank[j], highone) == '1'))
                    highone = player_one.rank[j];
            if ((player_two.rank[j] == player_two.rank[i]) &&
                (compare(player_two.rank[j], hightwo) == '1'))
                    hightwo = player_two.rank[j];
        }
    }
    if (compare(highone, hightwo) == '1')
        return '1';
    else if (compare(highone, hightwo) == '2')
        return '2';
    else {
        if (compare(highcard(player_one), highcard(player_two)) == '1')
            return '1';
        else
            return '2';
    }
}

/* tie_break_threeofakind: breaks ties between two hands with three of a kind */
char tie_break_threeofakind(struct hand player_one, struct hand player_two) {
    int i, j;
    int onecount = 0, 
        twocount = 0;
    char one, two;
    for (i = 0; i < HAND_LENGTH; i++) {
        for (j = i+1; j < HAND_LENGTH; j++) {
            if (player_one.rank[j] == player_one.rank[i]) {
                ++onecount;
                if (onecount == 3)
                    one = player_one.rank[j];
            }
            if (player_two.rank[j] == player_two.rank[i]) {
                ++twocount;
                if (twocount == 3)
                    two = player_two.rank[j];
            }
        }
    }
    if (compare(one, two) == '1')
        return '1';
    else if (compare(one, two) == '2')
        return '2';
    else {
        if (compare(highcard(player_one), highcard(player_two)) == '1')
            return '1';
        else
            return '2';
    }
}

/* tie_break_straight: breaks ties between two hands with straights */
char tie_break_straight(struct hand player_one, struct hand player_two) {
    char one = highcard(player_one),
         two = highcard(player_two);

    if (compare(one, two) == '1')
        return '1';
    else
        return '2';
}

/* tie_break_flush: breaks ties between two hands with flushs */
char tie_break_flush(struct hand player_one, struct hand player_two) {
    /* simply returns highcard */
    return tie_break_straight(player_one, player_two);
}

/* tie_break_fullhouse: breaks ties between two hands with full houses */
char tie_break_fullhouse(struct hand player_one, struct hand player_two) {
    return tie_break_threeofakind(player_one, player_two);
}

/* tie_break_fourofakind: breaks ties between two hands with four of a kind */
char tie_break_fourofakind(struct hand player_one, struct hand player_two) {
    int i, j;
    int onecount = 0, 
        twocount = 0;
    char one, two;
    for (i = 0; i < HAND_LENGTH; i++) {
        for (j = i+1; j < HAND_LENGTH; j++) {
            if (player_one.rank[j] == player_one.rank[i]) {
                ++onecount;
                if (onecount == 4)
                    one = player_one.rank[j];
            }
            if (player_two.rank[j] == player_two.rank[i]) {
                ++twocount;
                if (twocount == 4)
                    two = player_two.rank[j];
            }
        }
    }
    printf("%c %c\n", one, two);
    if (compare(one, two) == '1')
        return '1';
    else if (compare(one, two) == '2')
        return '2';
    else {
        if (compare(highcard(player_one), highcard(player_two)) == '1')
            return '1';
        else
            return '2';
    }
}

/* tie_break_straightflush: breaks ties between two hands with straight flushs */
char tie_break_straightflush(struct hand player_one, struct hand player_two) {
    return tie_break_straight(player_one, player_two);
}
