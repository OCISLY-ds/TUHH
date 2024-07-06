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
    if (size < 1 || data == nullptr) {
        throw std::invalid_argument("Invalid array size or null pointer.");
    }

    float max_val = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

/**
 * @brief Initialisiert das zwei-dimensionale Feld mit 0 für alle Elemente,
          falls der Parameter increase den Wert false hat. Falls increase den
          Wert true hat, wird das Feld mit aufsteigenden Werten in folgender
          Form initialisiert: 
            data[0][0]= 1,       data[0][1]= 2, ..., data[0][size2-1]=size2,
            data[1][0]= size2+1, ..., 
            ...
            ...                            data[size1-1][size2-1]= size1*size2.
 * @param data     Das zu bearbeitende zwei-dimensionale Feld
 * @param size1    Die Größe der ersten Dimension des Feldes.
 * @param size2    Die Größe der zweiten Dimension des Feldes.
 * @param increase Der oben genannte Parameter increase.
 */
/**
 * @brief Initializes the two-dimensional array with 0 for all elements, if
          parameter increase has the value false. If parameter increase has 
          the value true, the array is initialized with increasing values 
          according to the following scheme
            data[0][0]= 1,       data[0][1]= 2, ..., data[0][size2-1]=size2,
            data[1][0]= size2+1, ..., 
            ...
            ...                            data[size1-1][size2-1]= size1*size2.
 * @param data     The two-dimensional array of interest.
 * @param size1    The size of the first dimension of the array.
 * @param size2    The size of the second dimension of the array.
 * @param increase The parameter increase as explained above.
 */
void initialize_increase(float **data, int size1, int size2, bool increase) {
    if (increase) {
        int value = 1;
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                data[i][j] = value++;
            }
        }
    } else {
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                data[i][j] = 0;
            }
        }
    }
}
/**
 * @brief Invertiert (multipliziere mit -1) alle Elemente des Feldes.
 * @param data     Das zu bearbeitende zwei-dimensionale Feld
 * @param size1    Die Größe der ersten Dimension des Feldes.
 * @param size2    Die Größe der zweiten Dimension des Feldes.
 */
/**
 * @brief Inverts (multiply by -1) all elements of the two-dimensional 
          array.
 * @param data     The two-dimensional array of interest.
 * @param size1    The size of the first dimension of the array.
 * @param size2    The size of the second dimension of the array.
 */
void invert(float **data, int size1, int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            data[i][j] *= -1;
        }
    }
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
                     5  8  5  9  5
                     6  5  5  5  5
                     5  5  5  1  5
                     2  4  2  1  5
                     -------------
          numPairs:  0  1  2  0  3
 * @param data     Das zu bearbeitende zwei-dimensionale Feld
 * @param size1    Die Größe der ersten Dimension des Feldes.
 * @param size2    Die Größe der zweiten Dimension des Feldes.
 * @param numPairs Das Feld, in dem die gezählten Werte gespeichert werden.
 */
/**
 * @brief Finds the number of neighboring values 5 in each column and stores
          them in the passed numPairs parameter for each column. 
          For a column, the second dimension is stable while the first
          dimension changes.
          The array numPairs has already been allocated, only values need
          to be entered.
          Example:
                     5  8  5  9  5
                     6  5  5  5  5
                     5  5  5  1  5
                     2  4  2  1  5
                     -------------
          numPairs:  0  1  2  0  3
 * @param data     The two-dimensional array of interest.
 * @param size1    The size of the first dimension of the array.
 * @param size2    The size of the second dimension of the array.
 * @param numPairs The array storing the counts of pairs.
 */
void count_pairs(float **data, int size1, int size2, unsigned int numPairs[]) {
    for (int j = 0; j < size2; ++j) {
        numPairs[j] = 0;
        for (int i = 0; i < size1 - 1; ++i) {
            if (data[i][j] == 5 && data[i + 1][j] == 5) {
                ++numPairs[j];
            }
        }
    }
}

/**
 * @brief Die folgende Funktion implementiert den Pseudocode aus der 
          Aufgabenstellung.
 */
/**
 * @brief The following function implements the pseudocode from the info tab.
 */
float *down_sampling(float *data, int size, int M) {
    if (size < 1 || data == nullptr) {
        throw std::invalid_argument("Invalid array size or null pointer.");
    }

    int K = 5;
    float filter[K] = {0.05, 0.2, 0.5, 0.2, 0.05};
    int newSize = size / M;
    float *processed = new float[newSize];

    for (int i = 0; i < newSize; ++i) {
        float sample = 0;
        for (int j = 0; j < K; ++j) {
            if (i * M + j < size) {
                sample += data[i * M + j] * filter[j];
            }
        }
        processed[i] = sample;
    }

    return processed;
}
