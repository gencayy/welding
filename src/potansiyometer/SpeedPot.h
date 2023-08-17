#ifndef SPEED_POT 
#define SPEED_POT 

#define POTANS_PIN A5

// Quick sort ile ilgili fonskiyonlar
void swap(int &a, int &b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
float calculateMedianMean(int arr[], int size);

// Potansiyometre ile ilgili fonksiyonlar
float readPotVaules();


#endif