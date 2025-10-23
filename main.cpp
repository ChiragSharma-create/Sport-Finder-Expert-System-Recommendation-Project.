#include <iostream>

/**
 * @brief Greets the user and explains what the program does.
 *
 * This function prints a welcome message and tells the user
 * what the Sport Finder program is about.
 */
void greeting();

/**
 * @brief Asks all sport preference questions and validates each one.
 *
 * This function prompts the user for their preferences on team vs solo,
 * indoor vs outdoor, endurance vs quick bursts, and contact vs no contact.
 * All input is validated to ensure only expected characters are accepted.
 *
 * @param team Reference to store team or solo choice (T/S).
 * @param place Reference to store indoor or outdoor choice (I/O).
 * @param energy Reference to store endurance or quick bursts choice (E/Q).
 * @param contact Reference to store contact or no contact choice (Y/N).
 */
void askQuestions(char &team, char &place, char &energy, char &contact);

/**
 * @brief Determines and displays a recommended sport based on user's answers.
 *
 * This function uses multiple if-else statements to match the user's
 * preferences with a suitable sport.
 *
 * @param team Team or Solo (T/S)
 * @param place Indoor or Outdoor (I/O)
 * @param energy Endurance or Quick bursts (E/Q)
 * @param contact Contact or No Contact (Y/N)
 */
void recommendSport(char team, char place, char energy, char contact);

int main() {

    char team, place, energy, contact;
    char tryAgain = 'Y';

    // Welcome the user
    greeting();

    // Main quiz loop
    do {
        askQuestions(team, place, energy, contact);
        recommendSport(team, place, energy, contact);

        // Ask if the user wants to try again
        std::cout << "Would you like to try again? (Y/N): ";
        std::cin >> tryAgain;

        // Validate repeat input
        while (!(tryAgain == 'Y' || tryAgain == 'y' || tryAgain == 'N' || tryAgain == 'n')) {
            std::cout << "Invalid input. Please enter Y or N: ";
            std::cin >> tryAgain;
        }

    } while (tryAgain == 'Y' || tryAgain == 'y');

    std::cout << "Thanks for using the Sport Finder!" << std::endl;
    return 0;
}

// Function Definitions.

void greeting() {
    std::cout << "Welcome to the Sport Finder!" << std::endl;
    std::cout << "Answer a few simple questions and I will suggest a sport for you." << std::endl;
}

void askQuestions(char &team, char &place, char &energy, char &contact) {

    // Ask team vs solo
    do {
        std::cout << "Do you like team sports or solo activities? (T/S): ";
        std::cin >> team;
        if (!(team == 'T' || team == 't' || team == 'S' || team == 's')) {
            std::cout << "Invalid input. Please enter T or S." << std::endl;
        }
    } while (!(team == 'T' || team == 't' || team == 'S' || team == 's'));

    // Ask indoor vs outdoor
    do {
        std::cout << "Do you prefer indoor or outdoor sports? (I/O): ";
        std::cin >> place;
        if (!(place == 'I' || place == 'i' || place == 'O' || place == 'o')) {
            std::cout << "Invalid input. Please enter I or O." << std::endl;
        }
    } while (!(place == 'I' || place == 'i' || place == 'O' || place == 'o'));

    // Ask endurance vs quick bursts
    do {
        std::cout << "Do you like endurance or quick bursts of energy? (E/Q): ";
        std::cin >> energy;
        if (!(energy == 'E' || energy == 'e' || energy == 'Q' || energy == 'q')) {
            std::cout << "Invalid input. Please enter E or Q." << std::endl;
        }
    } while (!(energy == 'E' || energy == 'e' || energy == 'Q' || energy == 'q'));

    // Ask contact vs no contact
    do {
        std::cout << "Do you enjoy physical contact in a game? (Y/N): ";
        std::cin >> contact;
        if (!(contact == 'Y' || contact == 'y' || contact == 'N' || contact == 'n')) {
            std::cout << "Invalid input. Please enter Y or N." << std::endl;
        }
    } while (!(contact == 'Y' || contact == 'y' || contact == 'N' || contact == 'n'));
}

void recommendSport(char team, char place, char energy, char contact) {

    std::cout << "Your recommended sport is: ";

    if ((team == 'T' || team == 't') && (place == 'O' || place == 'o') && (contact == 'Y' || contact == 'y')) {
        std::cout << "Soccer" << std::endl;
    }
    else if ((team == 'T' || team == 't') && (place == 'I' || place == 'i') && (contact == 'N' || contact == 'n')) {
        std::cout << "Basketball" << std::endl;
    }
    else if ((team == 'T' || team == 't') && (place == 'O' || place == 'o') && (contact == 'N' || contact == 'n')) {
        std::cout << "Beach Volleyball" << std::endl;
    }
    else if ((team == 'S' || team == 's') && (energy == 'E' || energy == 'e')) {
        std::cout << "Running" << std::endl;
    }
    else if ((team == 'S' || team == 's') && (energy == 'Q' || energy == 'q')) {
        std::cout << "Badminton" << std::endl;
    }
    else {
        std::cout << "E-sports" << std::endl;
    }
}
