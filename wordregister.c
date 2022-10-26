#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define WORDLENGTH 20+1
#define NR_OF_WORDS 10

void menuOfFunctions(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords);
bool checkIfDictionaryIsFull(int nrOfWords);
int registerNewWords(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords);
void printOutDictionary(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords);
int eraseAWord(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords);
void mixDictionary(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords);

int main(void)
{

  char ordbok[NR_OF_WORDS][WORDLENGTH];
  int nrOfWords = 0;

  menuOfFunctions(ordbok, nrOfWords);

  return 0;

}

void menuOfFunctions(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  int specifiedValue;

  printf("(1)Registrera (2)Skriva ut (3)Radera (4)Blanda (5)Avsluta: ");
  scanf("%d", &specifiedValue);

  switch (specifiedValue) {

    case 1:
      nrOfWords = registerNewWords(ordbok, nrOfWords);
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 2:
      printOutDictionary(ordbok, nrOfWords);
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 3:
      nrOfWords = eraseAWord(ordbok, nrOfWords);
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 4:
      mixDictionary(ordbok, nrOfWords);
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 5:
      printf("Avslutar\n");
      return;
    default:
      printf("Fel inmatning\n");
      menuOfFunctions(ordbok, nrOfWords);
      break;

  }


}

bool checkIfDictionaryIsFull(int nrOfWords) {

  if(nrOfWords == NR_OF_WORDS) {
    printf("ordboken ar full..\n");
    return true;
  }

  return false;

}

int registerNewWords(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  if(checkIfDictionaryIsFull(nrOfWords)) {
    return nrOfWords;
  }

  char newWord[WORDLENGTH];

  printf("Ange ord: ");
  scanf("%s%*c", newWord);

  //Ska detta tillhöra en funktion?
  if(strlen(newWord) < 0 || strlen(newWord) > 21) {
    printf("Ordet ska vara max 20 tecken\n");
    registerNewWords(ordbok, nrOfWords);
  }

  strcpy(ordbok[nrOfWords++], newWord);

  return nrOfWords;

}

void printOutDictionary(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  if(nrOfWords == 0) {
    printf("Registret tomt\n");
    return;
  }

  for(int i = 0; i < nrOfWords; i++) {
    printf("%s, ", ordbok[i]);
  }
  printf("\n");

}

int eraseAWord(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  if(nrOfWords == 0) {
    printf("Registret tomt\n");
    return nrOfWords;
  }

  int ordningsnummer;

  printf("Ange ordningsnummer att radera: ");
  scanf("%d", &ordningsnummer);

  if(ordningsnummer > nrOfWords || ordningsnummer < 1) {
    printf("Felaktigt nummer.\n");
    menuOfFunctions(ordbok, nrOfWords);
  }

  for(int i = ordningsnummer-1; i < nrOfWords - 1; i++) {
    strcpy(ordbok[i], ordbok[i+1]);
  }

  return --nrOfWords;

}

void mixDictionary(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  if(nrOfWords == 0) {
    printf("Registret tomt\n");
    return;
  }

  srand(time(NULL));
  char tmpString[1][WORDLENGTH];

  for(int i = 0; i < nrOfWords; i++) {

    for(int j = 0; j < nrOfWords; j++) {

      int rndmIndex = rand() % nrOfWords;

      strcpy(tmpString[0], ordbok[j]);
      strcpy(ordbok[j], ordbok[rndmIndex]);
      strcpy(ordbok[rndmIndex], tmpString[0]);

    }

  }

}