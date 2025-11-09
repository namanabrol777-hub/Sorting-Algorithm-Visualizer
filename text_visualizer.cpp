#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Simple delay function
void delay(int milliseconds) {
    for (int i = 0; i < milliseconds * 10000; i++) {}
}

// Function to print header
void printHeader() {
    system("cls");  // Clear screen
    cout << "\n";
    cout << "============================================================\n";
    cout << "              SORTING ALGORITHM VISUALIZER\n";
    cout << "                    Created by: ASMIT\n";
    cout << "               Computer Science - 3rd Year\n";
    cout << "============================================================\n";
    cout << "\n";
}

class TextVisualizer {
private:
    vector<int> array;
    int size;
    
public:
    TextVisualizer(int n = 8) : size(n) {
        generateNewArray();
    }
    
    void generateNewArray() {
        array.resize(size);
        for (int i = 0; i < size; i++) {
            array[i] = i + 1;
        }
        
        // Shuffle the array
        random_device rd;
        mt19937 g(rd());
        shuffle(array.begin(), array.end(), g);
        
        cout << ">>> Generated new random array!\n";
    }
    
    void displayBeautifulArray() {
        cout << "\n";
        cout << "+---";
        for (int i = 1; i < array.size(); i++) {
            cout << "----";
        }
        cout << "+\n";
        
        cout << "| ";
        for (int val : array) {
            cout << val << " | ";
        }
        
        cout << "\n+---";
        for (int i = 1; i < array.size(); i++) {
            cout << "----";
        }
        cout << "+\n";
    }
    
    void displayWithHighlight(int idx1, int idx2, const string& message) {
        cout << ">>> " << message << "\n";
        cout << "Array: ";
        for (int i = 0; i < array.size(); i++) {
            if (i == idx1) {
                cout << "(" << array[i] << ") ";  // Highlight first element
            } else if (i == idx2) {
                cout << "[" << array[i] << "] ";  // Highlight second element
            } else {
                cout << array[i] << " ";
            }
        }
        cout << "\n";
    }
    
    void bubbleSortWithVisualization() {
        printHeader();
        cout << "=== BUBBLE SORT VISUALIZATION ===\n";
        cout << "Strategy: Compare adjacent elements and swap if needed\n";
        cout << "Goal: Largest elements 'bubble up' to the end\n";
        delay(2000);
        
        int n = array.size();
        for (int i = 0; i < n-1; i++) {
            cout << "\n--- Pass " << (i+1) << " ---\n";
            cout << "Looking for the largest element in unsorted part...\n";
            
            for (int j = 0; j < n-i-1; j++) {
                displayWithHighlight(j, j+1, "Comparing adjacent elements:");
                
                if (array[j] > array[j+1]) {
                    cout << ">>> SWAPPING: " << array[j] << " and " << array[j+1] << " <<<\n";
                    swap(array[j], array[j+1]);
                    displayWithHighlight(j, j+1, "After swap:");
                } else {
                    cout << ">>> No swap needed - elements are in order\n";
                }
                
                delay(800);
            }
            
            cout << ">>> Element at position " << (n-i-1) << " is now in its final position!\n";
            delay(500);
        }
        
        cout << "\n=== BUBBLE SORT COMPLETE! ===\n";
        cout << "The array is now perfectly sorted!\n";
        displayBeautifulArray();
    }
    
    void selectionSortWithVisualization() {
        printHeader();
        cout << "=== SELECTION SORT VISUALIZATION ===\n";
        cout << "Strategy: Find minimum element and place it at beginning\n";
        cout << "Goal: Build sorted array one element at a time\n";
        delay(2000);
        
        int n = array.size();
        for (int i = 0; i < n-1; i++) {
            cout << "\n--- Pass " << (i+1) << " ---\n";
            cout << "Looking for minimum element in the unsorted part...\n";
            
            int minIndex = i;
            displayWithHighlight(minIndex, -1, "Current minimum element:");
            
            for (int j = i+1; j < n; j++) {
                displayWithHighlight(minIndex, j, "Comparing current minimum with next element:");
                
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                    cout << ">>> NEW MINIMUM FOUND: " << array[minIndex] << " <<<\n";
                    displayWithHighlight(minIndex, -1, "Updated minimum:");
                }
                
                delay(600);
            }
            
            if (minIndex != i) {
                cout << ">>> SWAPPING minimum " << array[minIndex] << " with " << array[i] << " <<<\n";
                swap(array[i], array[minIndex]);
                displayWithHighlight(i, minIndex, "After swap:");
            } else {
                cout << ">>> Minimum is already at correct position!\n";
            }
            
            cout << ">>> Element at position " << i << " is now in its final position!\n";
            delay(800);
        }
        
        cout << "\n=== SELECTION SORT COMPLETE! ===\n";
        cout << "The array is now perfectly sorted!\n";
        displayBeautifulArray();
    }
};

void printMenu() {
    cout << "\n=== MAIN MENU ===\n";
    cout << "1. Generate new random array\n";
    cout << "2. Display current array\n";
    cout << "3. Bubble Sort (with visualization)\n";
    cout << "4. Selection Sort (with visualization)\n";
    cout << "5. Exit\n";
    cout << "\nTip: Start with 8 elements to see clear visualization!\n";
}

int main() {
    TextVisualizer visualizer;
    int choice;
    
    do {
        printHeader();
        printMenu();
        
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                printHeader();
                visualizer.generateNewArray();
                visualizer.displayBeautifulArray();
                break;
            case 2:
                printHeader();
                visualizer.displayBeautifulArray();
                break;
            case 3:
                visualizer.bubbleSortWithVisualization();
                break;
            case 4:
                visualizer.selectionSortWithVisualization();
                break;
            case 5:
                printHeader();
                cout << "Thank you for using Sorting Visualizer!\n";
                cout << "Goodbye ASMIT!\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1-5.\n";
                delay(1000);
        }
        
        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while(choice != 5);
    
    return 0;
}