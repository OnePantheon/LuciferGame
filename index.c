#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getChoice (int maxNumber, char* information) {
    int value = 0;
    
    do {
        printf("%s", information);
        fflush(stdin);
    } while (!(scanf("%d", &value) == 1 && value > 0 && value <= maxNumber));

    return value;
}

int min (int a, int b) {
    if (a > b) return b;
    return a;
}

int getRandomChoice (int max, int numberSticks) {
    int random = (rand() % max) + 1;
    return min(random, numberSticks);
}

int getNumberSticksTaken (int count, int numberPlayers, int numberSticks) {
    int turn = ((count % 2) + 1);
    
    if (turn == 2 && numberPlayers == 1) return getRandomChoice(3, numberSticks);
    return getChoice(min(numberSticks, 3), "Entrez le nombre d'allumettes que vous voulez récupérées : ");
}

// Returns the winning player
int playGame (int numberSticks, int numberPlayers) {
    int count = 0;

    do {
        printf("\n\nTour %d\n", count + 1);
        printf("Il reste %d allumettes !\n", numberSticks);

        int numberSticksTaken = getNumberSticksTaken(count, numberPlayers, numberSticks);

        printf("Le joueur %d a récupéré %d allumettes.\n", ((count % 2) + 1), numberSticksTaken);

        numberSticks -= numberSticksTaken;
        count++;
    } while(numberSticks > 0);

    return (count % 2) + 1;
}

int main() {
    srand(time(NULL));

    do {
        system("clear"); 
        system("cls 2> /dev/null");

        int numberSticks = getChoice(50, "Entrez le nombre d'allumettes : ");
        int numberPlayer = getChoice(2, "\nEntrez le nombre de joueurs (1 ou 2) : ");
        int winningPlayer = playGame(numberSticks, numberPlayer);

        printf("\nIl ne reste plus aucune allumette ! \nLe joueur %d a gagné !\n\n", winningPlayer); 
    } while(!(getChoice(2, "Que voulez-vous faire ?\n1 - Continuer\n2 - Arrêter\n") == 2));

    return 0;
}