// Project Euler Problem: 59
// Goal: Decrypt the cipher text and calculate the sum of the ascii characters of
// the resulting decrypted plain text file.
// Author: Cooper Bell

#include <stdio.h>
#define MAXLINE 10000   /* default file length */

FILE *text;    /* file pointer */


/* Functions */
void keyarray(int k[], int a, int b, int c, int count);
void decrypt(int c[], int dc[], int count, int key[]);
void inttochar(int c[], char ch[], int count);
int totalchar(char k[], int count);


main()
{
    /* scan in cipher text into array */
    text = fopen("cipher1.txt", "rt");

    int num;                /* number read in from text */
    char comma;             /* vessel for the commas in file */
    int count = 0;          /* counter for array */
    int crypt[MAXLINE];     /* array for cipher text */

    while(fscanf(text, "%d%c", &num, &comma) != EOF) {
        crypt[count++] = num;    
    }
    

    int key_min = 97;       /* min digit key 'a' */
    int key_max = 122;      /* max digit key 'z' */
    int a, b, c;            /* alternating three digit keys */
    int dcrypt[MAXLINE];    /* array for deciphered text */
    int keyarr[MAXLINE];    /* array of cyclic three char keys */
    char ctext[MAXLINE];    /* array for converted text */

    for (a=key_min; a<key_max+1; a++) {
        for (b=key_min; b<key_max+1; b++) {
            for (c=key_min; c<key_max+1; c++) {

                keyarray(keyarr, a, b, c, count);         
                decrypt(crypt, dcrypt, count, keyarr);
                inttochar(dcrypt, ctext, count);

                int i;
                for (i = 0; i < count; i++)
                    printf("%c", ctext[i]);
                printf("\n\nEnd of Text for key = %d %d %d\n\n", a, b, c);

                i = 0;
            }
        }
    }

    /* Solution printout */
    keyarray(keyarr, 103, 111, 100, count);         
    decrypt(crypt, dcrypt, count, keyarr);
    inttochar(dcrypt, ctext, count);

    int j;
    for (j = 0; j < count; j++)
        printf("%c", ctext[j]);

    printf("\n\nTotal Length: %d\n", totalchar(ctext, count));

    return 0;
}


/* keyarray: creates a key array from three values */
void keyarray(int k[], int a, int b, int c, int count) {
    int i = 0;
    while (i < count) {
        k[i] = a;
        k[i+1] = b;
        k[i+2] = c;
        i += 3;
    }
    k[i-2] = '\0';
}

/* decrypt: decrypts a xor encrypted file */
void decrypt(int c[], int dc[], int count, int key[]) {
    int i;
    for (i = 0; i < count; i++)
        dc[i] = c[i] ^ key[i];
}

/* inttochar: converts an array of integers to an array of characters */
void inttochar(int c[], char ch[], int count) {
    int i;
    for (i = 0; i < count; i++)
        ch[i] = c[i];
}

/* totalchar: calculate ascii equivalent of deciphered text */
int totalchar(char k[], int count) {
    int i, sum = 0;
    for (i = 0; i < count; i++)
        sum += k[i];
    return sum;
}
