#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <list>
#include <string>


using namespace std;

int GeneratePlateNumberSum() {
    int hundreds = rand() % 10;
    int tens = rand() % 10;
    int ones = rand() % 10;
    return (hundreds * 100 + tens * 10 + ones);
}

void PrintThreeDigitNumber(int num) {
	// Print "0" if there are no hundreds
	if (num < 100) {
		cout << "0";
	}
	// Print "0" if there are no tens either.
	if (num < 10) {
		cout << "0";
	}
	// Finally print the number;
	cout << num << "\n";
}

int main() {
    // Initialize random nuber generator
    srand (5);
    // Number of plates;
    int count = 0;
    // Sorted list of (1000 - GeneratePlateNumberSum()).
    std::list<int> plate_sums;
    int plate_num;
    while (1) {
        plate_num = GeneratePlateNumberSum();
        count++;
		cout << "Plate # " << count << " is xxx";
		PrintThreeDigitNumber(plate_num);
        if ((std::binary_search (plate_sums.begin(), plate_sums.end(), plate_num))) {
            // In the list of (1000 - plate_num) we found a match
            // to the number that was just generated - game end!
            break;
        }
        // No match yet, invert the number and insert it into the list;
        // keep the list without duplicates.
        int inversion = 1000 - plate_num;
        if (plate_sums.empty() || plate_num > plate_sums.back()) {
            plate_sums.push_back(inversion);
        } else if (inversion < plate_sums.front()) {
            plate_sums.push_front(inversion);
        } else {
            for (std::list<int>::iterator it = plate_sums.begin();
                 it != plate_sums.end(); it++) {
                    if (inversion > *it) {
                        continue;
                    } else if (inversion == *it) {
                        // We don't want duplicates in the list.
                        break;
                    } else {
                        plate_sums.insert(it, inversion);
                        break;
                    }
                }
        }
    }
	
	
	cout << "It took " << count << " cars to find the match:\n";
	cout << "First plate number is xxx";
	PrintThreeDigitNumber(plate_num);
	cout << "Second plate number is xxx";
	PrintThreeDigitNumber(1000 - plate_num);
	plate_sums.clear();
	return 0;
}