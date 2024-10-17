#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

class Chair {
private:
    int legs;
    double* prices;

public:
    // Updated constructors
    Chair() {
        srand(time(NULL)); // Seed random number generator
        prices = new double[SIZE];
        legs = rand() % 2 + 3; // Randomly 3 or 4 legs
        for (int i = 0; i < SIZE; i++) {
            int randomPrice = rand() % (99999 - 10000 + 1) + 10000; // Random price between 10000 and 99999 cents
            prices[i] = randomPrice / 100.0; // Convert to dollars
        }
    }

    Chair(int l, double p[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

    // Existing methods unchanged for this segment...
};

int main() {
    cout << fixed << setprecision(2);

    // Testing default constructor
    Chair* chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    // Testing parameter constructor with data
    double prices[] = {525.25, 434.34, 252.52};
    Chair* livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    
}

int main() {
    // Continue from previous segment

    // Creating dynamic array of chair objects using default constructor
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }

    // Clean up
    delete[] collection;
    collection = nullptr;

    return 0;
}
