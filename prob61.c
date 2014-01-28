// Project Euler Problem: 61
// Goal: Find the sum of the six 4-digit integers that are either triangular, square,
// pentagonal, hexagonal, heptagonal and octagonal.
// Author: Cooper Bell

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NUMS 8999   /* size of polygonal arrays (9999 - 1000 to ensure proper size) */


/* functions */
void permutatedset(int a, int b, int c, int d, int e, int f, int cyclical[]);
bool isin(int n, int narr[], int len);
void numtochar(int num, char chararr[]);
int chartonum(char chararr[]);
void trifill(int triangles[]);
void squfill(int squares[]);
void penfill(int pentagonals[]);
void hexfill(int hexagonals[]);
void hepfill(int heptagonals[]);
void octfill(int octagonals[]);


main()
{
    /* arrays for 4-digit polygonal numbers */
    int poly[6][MAX_NUMS];
    
    /* fill with numbers */
    trifill(poly[0]);
    squfill(poly[1]);
    penfill(poly[2]);
    hexfill(poly[3]);
    hepfill(poly[4]);
    octfill(poly[5]);

    /* lengths of arrays */
    int i, j, len[6];
    for (i = 0; i < 6; i++) {
        while (poly[i][len[i]++] != '\0');
        --len[i];
    }

    /* permutated array of cyclical numbers */
    int cyc[6];
    permutatedset(81, 28, 82, 81, 21, 11, cyc);

    for (i = 0; i < 6; i++)
        printf("%d  ", cyc[i]);
    printf("\n");

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            int cyct = cyc[j], lent = len[j];
            printf("%s ", isin(cyct, poly[i], lent) ? "true " : "false");
        }
        printf("\n");
    }

    return 0;
}


/* permutatedset: takes in six 2-digit numbers, returns 6
   4-digit cyclical numbers composed of the set */
void permutatedset(int a, int b, int c, int d, int e, int f, int cyclical[]) {
    char ac[2], bc[2], cc[2], dc[2], ec[2], fc[2];
    char fst[4], scd[4], trd[4], fou[4], fth[4], six[4];

    numtochar(a, ac);
    numtochar(b, bc);
    numtochar(c, cc);
    numtochar(d, dc);
    numtochar(e, ec);
    numtochar(f, fc);

    /* cyclical numbers */
    strcat(fst, ac);
    strcat(fst, bc);

    strcat(scd, bc);
    strcat(scd, cc);

    strcat(trd, cc);
    strcat(trd, dc);

    strcat(fou, dc);
    strcat(fou, ec);

    strcat(fth, ec);
    strcat(fth, fc);

    strcat(six, fc);
    strcat(six, ac);

    cyclical[0] = chartonum(fst);
    cyclical[1] = chartonum(scd);
    cyclical[2] = chartonum(trd);
    cyclical[3] = chartonum(fou);
    cyclical[4] = chartonum(fth);
    cyclical[5] = chartonum(six);
}

/* isin: determines if a num 'n' is in array 'narr' */
bool isin(int n, int narr[], int len) {
    int i;
    for (i = 0; i < len; i++)
        if (narr[i] == n)
            return true;
    return false;
}

/* numtochar: returns the literal (not ascii) representation of a number */
void numtochar(int num, char chararr[]) {
    int digs = 1, temp = num;
    while ((temp /= 10) != 0)
        ++digs;

    int i, digarr[digs];
    for (i = 0; i < digs; i++) {
        digarr[i] = (num%10);
        num /= 10;
    }

    /* reverse the elements */
    int tmp[digs];
    for (i = 0; i < digs; i++)
        tmp[i] = digarr[i];
    for (i = 0; i < digs; i++)
        digarr[i] = tmp[digs-1-i];

    for (i = 0; i < digs; i++) {
        if (digarr[i] == 0)
            chararr[i] = '0';
        else if (digarr[i] == 1)
            chararr[i] = '1';
        else if (digarr[i] == 2)
            chararr[i] = '2';
        else if (digarr[i] == 3)
            chararr[i] = '3';
        else if (digarr[i] == 4)
            chararr[i] = '4';
        else if (digarr[i] == 5)
            chararr[i] = '5';
        else if (digarr[i] == 6)
            chararr[i] = '6';
        else if (digarr[i] == 7)
            chararr[i] = '7';
        else if (digarr[i] == 8)
            chararr[i] = '8';
        else
            chararr[i] = '9';
    }
}

/* chartonum: converts string to number */
int chartonum(char chararr[]) {
    int i, digs = strlen(chararr);

    int tmp[digs];
    for (i = 0; i < digs; i++) {
        if (chararr[i] == '0')
            tmp[i] = 0;
        else if (chararr[i] == '1')
            tmp[i] = 1;
        else if (chararr[i] == '2')
            tmp[i] = 2;
        else if (chararr[i] == '3')
            tmp[i] = 3;
        else if (chararr[i] == '4')
            tmp[i] = 4;
        else if (chararr[i] == '5')
            tmp[i] = 5;
        else if (chararr[i] == '6')
            tmp[i] = 6;
        else if (chararr[i] == '7')
            tmp[i] = 7;
        else if (chararr[i] == '8')
            tmp[i] = 8;
        else
            tmp[i] = 9;
    }

    int num = 0;
    for (i = 0; i < digs; i++) {
        num += tmp[i];
        num *= 10;
    }
    return num /= 10;
}

/* trifill: fills triangles with triangle numbers */
void trifill(int triangles[]) {
    int start = 45, 
        end = 141;

    int n;
    for (n = start; n < end; n++)
        triangles[n-start] = ( n*(n+1)/2 );
}

/* squfill: fills squares with square numbers */
void squfill(int squares[]) {
    int start = 32, 
        end = 100;

    int n;
    for (n = start; n < end; n++)
        squares[n-start] = ( n*n );
}

/* penfill: fills pentagonals with pentagonal numbers */
void penfill(int pentagonals[]) {
    int start = 26, 
        end = 82;
    
    int n;
    for (n = start; n < end; n++)
        pentagonals[n-start] = ( n*(3*n-1)/2 );
}

/* hexfill: fills hexagonals with hexagonal numbers */
void hexfill(int hexagonals[]) {
    int start = 23, 
        end = 71;
    
    int n;
    for (n = start; n < end; n++)
        hexagonals[n-start] = ( n*(2*n-1) );
}

/* hepfill: fills heptagonals with heptagonal numbers */
void hepfill(int heptagonals[]) {
    int start = 21, 
        end = 64;
    
    int n;
    for (n = start; n < end; n++)
        heptagonals[n-start] = ( n*(5*n-3)/2 );
}

/* octfill: fills octagonals with octagonal numbers */
void octfill(int octagonals[]) {
    int start = 19, 
        end = 59;
    
    int n;
    for (n = start; n < end; n++)
        octagonals[n-start] = ( n*(3*n-2) );
}
