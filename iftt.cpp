#include <iostream>
int main() {
    int userAnswer;
    const int correctAnswer = 31; // Korrekte Anzahl der Tage im Oktober

    std::cout << "Wie viele Tage hat der Oktober? Geben Sie Ihre Antwort ein: ";
    std::cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        std::cout << "Yesss. Richtig! Der Oktober hat " << correctAnswer << " Tage." << std::endl;
    } else {
        std::cout << "Falsch du kek! Der Oktober hat " << correctAnswer << " Tage." << std::endl;
    }

    return 0;
}