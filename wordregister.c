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

//Funktionen är en meny som leder till andra funktioner
void menuOfFunctions(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  int specifiedValue;

  //Skriver ut alternativen och fråga efter en input (integer) från 1-5
  printf("(1)Registrera (2)Skriva ut (3)Radera (4)Blanda (5)Avsluta: ");
  scanf("%d", &specifiedValue);

  //Det alternativ du valde kommer calla ett case
  switch (specifiedValue) {

    case 1:
      nrOfWords = registerNewWords(ordbok, nrOfWords);
      //Sen ska alternativen visas upp igen och att du anger en input
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 2:
      printOutDictionary(ordbok, nrOfWords);
      //Sen ska alternativen visas upp igen och att du anger en input
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 3:
      nrOfWords = eraseAWord(ordbok, nrOfWords);
      //Sen ska alternativen visas upp igen och att du anger en input
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 4:
      mixDictionary(ordbok, nrOfWords);
      //Sen ska alternativen visas upp igen och att du anger en input
      menuOfFunctions(ordbok, nrOfWords);
      break;
    case 5:
      printf("Avslutar\n");
      return;
    default:
      //Du skrev något annat än ett nummer från 1 till 5
      printf("Fel inmatning\n");
      //Sen ska alternativen visas upp igen och att du anger en input
      menuOfFunctions(ordbok, nrOfWords);
      break;

  }


}

//Kollar ifall nrOfWords har använt alla index i arrayn
bool checkIfDictionaryIsFull(int nrOfWords) {

  if(nrOfWords == NR_OF_WORDS) {
    printf("ordboken ar full..\n");
    return true;
  }

  return false;

}

//Du ska skriva in ett ord och funktionen returnera nrOfWords
int registerNewWords(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  //Kollar om den är full
  if(checkIfDictionaryIsFull(nrOfWords)) {
    return nrOfWords;
  }

  char newWord[WORDLENGTH];

  //Skriver ut och frågar efter en input (string)
  printf("Ange ord: ");
  scanf("%s%*c", newWord);

  //Kollar om den angivna strängen inte överstiger 20 karaktärer
  if(strlen(newWord) < 0 || strlen(newWord) > 21) {
    printf("Ordet ska vara max 20 tecken\n");
    registerNewWords(ordbok, nrOfWords);
  }

  //Kopierar datan från "newWord" till "ordbok" i en plats i arrayn.
  strcpy(ordbok[nrOfWords++], newWord);

  //Returnerar nrOfWords så nästa gång man vill skriva in ett nytt ord kommer den hamna på platsen efter
  return nrOfWords;

}

//Skriver ut alla ord som finns i ordboken med nrOfWords som stop condition
void printOutDictionary(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  //Det finns inget i arrayn
  if(nrOfWords == 0) {
    printf("Registret tomt\n");
    return;
  }

  //Skriver ut alla ord efter varandra
  for(int i = 0; i < nrOfWords; i++) {
    printf("%s, ", ordbok[i]);
  }
  printf("\n");

}

//Du ska ange ett ordningsnummer som ska tas bort från ordbok och returnerar nrOfWords
int eraseAWord(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  //Det finns inget i arrayn
  if(nrOfWords == 0) {
    printf("Registret tomt\n");
    return nrOfWords;
  }

  int ordningsnummer;

  //Skriver ut och frågar efter en input (integer)
  printf("Ange ordningsnummer att radera: ");
  scanf("%d", &ordningsnummer);

  //Om ordningsnummer inte finns ska man bli frågad igen med ett nytt värde
  if(ordningsnummer > nrOfWords || ordningsnummer < 1) {
    printf("Felaktigt nummer.\n");
    menuOfFunctions(ordbok, nrOfWords);
  }

  //Kopierar alla ord som kommer efter ordningsnummer
  for(int i = ordningsnummer - 1; i < nrOfWords - 1; i++) {
    strcpy(ordbok[i], ordbok[i+1]);
  }

  //Returnerar nrOfWords - 1 eftersom vi har minskat med en plats
  return --nrOfWords;

}

//Blanda orderns index så dom hamnar på en annan plats
void mixDictionary(char ordbok[NR_OF_WORDS][WORDLENGTH], int nrOfWords) {

  //Det finns inget i arrayn
  if(nrOfWords == 0) {
    printf("Registret tomt\n");
    return;
  }

  //Skapar nya slumptal
  srand(time(NULL));

  char tmpString[1][WORDLENGTH];

  //Den kommer blanda i 3 omgångar, varje omgång går man ingenom alla ord med denns nya index som man får från rndmIndex.
  for(int i = 0; i < nrOfWords; i++) {

    for(int j = 0; j < nrOfWords; j++) {

      int rndmIndex = rand() % nrOfWords;

      strcpy(tmpString[0], ordbok[j]);
      strcpy(ordbok[j], ordbok[rndmIndex]);
      strcpy(ordbok[rndmIndex], tmpString[0]);

    }

  }

}