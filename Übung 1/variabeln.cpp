#include <iostream>

int main() {
    // Variablen für Länge und Breite des Rechtecks
    double length, width;

    // Benutzereingabe für Länge und Breite
    std::cout << "Geben Sie die Länge des Rechtecks ein: ";
    std::cin >> length;

    std::cout << "Geben Sie die Breite des Rechtecks ein: ";
    std::cin >> width;

    // Berechnung des Umfangs und Flächeninhalts
    double perimeter = 2 * (length + width);
    double area = length * width;

    // Ausgabe der Ergebnisse
    std::cout << "Umfang des Rechtecks: " << perimeter << std::endl;
    std::cout << "Flächeninhalt des Rechtecks: " << area << std::endl;

    return 0;
}