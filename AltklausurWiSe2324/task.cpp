#include "task.hpp"
  /*
   * HINWEIS:
   *
   * Ergänzende Informationen und Hinweise sind im Info-Tab der Aufgabe zu finden.
   *
   * REMARK:
   *
   * Additional information and remarks can be found in the information tab of the task.
   */
  /**
   * @brief Liefert den maximalen Wert aus dem übergebenen ein-dimensionalen Feld zurück.
   *
   * @param data Das zu bearbeitende ein-dimensionale Feld.
   * @param size Die Größe des Feldes.
   * @throws std::invalid_argument Wenn die Größe kleiner als
   *             1 ist oder das Feld dem nullptr entspricht.
   */
  /**
   * @brief Returns the maximal value contained in the passed one-dimensional array.
   *
   * @param data The array of interest.
   * @param size The size of the array.
   * @param height The height of the image.
   * @throws std::invalid_argument If the given size is smaller than one
   *   or the array is the nullptr.
   */
  float get_maximum(float *data, int size) {
    return -18;
}
  /**
   * @brief Initialisiert das zwei-dimensionale Feld mit 0 für alle Elemente,
            falls der Parameter increase den Wert false hat. Falls increase den
            Wert true hat, wird das Feld mit aufsteigenden Werten in folgender
            Form initialisiert:
data[0][0]= 1,       data[0][1]= 2, ..., data[0][size2-1]=size2,
data[1][0]= size2+1, ...,
...
...
                        data[size1-1][size2-1]= size1*size2.
Das zu bearbeitende zwei-dimensionale Feld
* @param data
* @param size1
* @param size2
* @param increase Der oben genannte Parameter increase.
*/
Die Größe der ersten Dimension des Feldes.
Die Größe der zweiten Dimension des Feldes.
/**
 * @brief Initializes the two-dimensional array with 0 for all elements, if
          parameter increase has the value false. If parameter increase has
          the value true, the array is initialized with increasing values
          according to the following scheme
data[0][0]= 1,       data[0][1]= 2, ..., data[0][size2-1]=size2,
data[1][0]= size2+1, ...,
...
...
                        data[size1-1][size2-1]= size1*size2.
The two-dimensional array of interest.
* @param data
* @param size1
* @param size2
* @param increase The parameter increase as explained above.
*/
The size of the first dimension of the array.
The size of the second dimension of the array.
void initialize_increase(float **data, int size1, int size2, bool increase) {
}
/**
 * @brief Invertiert (multipliziere mit -1) alle Elemente des Feldes.
* @param data
* @param size1
* @param size2
*/
Das zu bearbeitende zwei-dimensionale Feld
Die Größe der ersten Dimension des Feldes.
Die Größe der zweiten Dimension des Feldes.
/**
 * @brief Inverts (multiply by -1) all elements of the two-dimensional
          array.
 * @param data     The two-dimensional array of interest.
 * @param size1    The size of the first dimension of the array.
 *    * @param size2    The size of the second dimension of the array.
   */
  void invert(float **data, int size1, int size2) {
  }
  /**
   * @brief Zählt die Anzahl der benachbarten Elemente mit dem Wert 5 je Spalte
            und speichert die Anzahl im übergebenen Parameter numPairs
            je Spalte.
            In einer Spalte ist die zweite Dimension fest, während die erste
            sich ändert.
            Das Feld numPairs wurde bereits allokiert, es müssen nur Werte
            eingetragen werden.
            Beispiel:
58595 65555 55515 24215 -------------
            numPairs:  0  1  2  0  3
* @param data
* @param size1
* @param size2
* @param numPairs Das Feld, in dem die gezählten Werte gespeichert werden.
*/
Das zu bearbeitende zwei-dimensionale Feld
Die Größe der ersten Dimension des Feldes.
Die Größe der zweiten Dimension des Feldes.
/**
 * @brief Finds the number of neighboring values 5 in each column and stores
          them in the passed numPairs parameter for each column.
          For a column, the second dimension is stable while the first
          dimension changes.
          The array numPairs has already been allocated, only values need
          to be entered.
          Example:
58595 65555 55515 24215 -------------
          numPairs:  0  1  2  0  3
* @param data
* @param size1
* @param size2
* @param numPairs The array storing the counts of pairs.
*/
The two-dimensional array of interest.
The size of the first dimension of the array.
The size of the second dimension of the array.
void count_pairs(float **data, int size1, int size2, unsigned int numPairs[]) {
}
/**
 * @brief Die folgende Funktion implementiert den Pseudocode aus der
          Aufgabenstellung.
*/ /**
 * @brief The following function implements the pseudocode from the info tab.
 */
float *down_sampling(float *data, int size, int M) {
  return nullptr;
}
