#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getComputerChoice();
int getUserChoice();
void checkWinner(int userChoice, int computerChoice);
void checkChoise(int choice);

int main() {
  printf("Welcome to Rock, Paper, Scissors!\n");
  int userChoice = getUserChoice();
  int computerChoice = getComputerChoice();

  printf("You chose: ");
  checkChoise(userChoice);
  printf("Computer chose: ");
  checkChoise(computerChoice);

  checkWinner(userChoice, computerChoice);

  return 0;
}

int getComputerChoice() {
  srand(time(0));
  return rand() % 3;
}

int getUserChoice() {
  int choice;
  printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors: ");
  scanf("%d", &choice);
  return choice;
}

void checkWinner(int userChoice, int computerChoice) {
  if (userChoice == computerChoice) {
    printf("It's a tie!\n");
  } else if ((userChoice == 0 && computerChoice == 2) ||
             (userChoice == 1 && computerChoice == 0) ||
             (userChoice == 2 && computerChoice == 1)) {
    printf("You win!\n");
  } else {
    printf("Computer wins!\n");
  }
}

void checkChoise(int choice) {
  switch (choice) {
  case 0:
    printf("Rock\n");
    break;
  case 1:
    printf("Paper\n");
    break;
  case 2:
    printf("Scissors\n");
    break;
  default:
    printf("Invalid choice\n");
  }
}
