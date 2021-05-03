/*
 *	Author:	Dazhia Blassingame
 *	Date:	09/01/17
 *	Assignment:	Program 2 list-array implementation
 *	File:	List.cpp
 *	Description: Program will allow client to create a list and insert, delete, display, sort, average the lengths of the strings in the list,
 find the median of the strings in the list, shuffle through or just exit.
 */
#include "List.h"
#include <iostream>
#include <random>

List::List() { //create an empty list
    N=0;
    for(int i=0; i<MAX; i++){
        listArray[i] = "";
    }
}

bool List::Empty(){ //checks to see if the list is empty
    if(N==0) {
        return true;
    }else{
        return false;
    }
}

void List::InsertAtEnd(ElementType x){ // Insert a value x at the end of the list
    listArray[N] = x;
    N++;

}

void List::Delete(ElementType x){ // If value x is in the list, remove x (all instances)
    for(int i=0; i<MAX; i++){
        if(listArray[i].compare(x)==0){
           listArray[i] = "";
           for(int j=1; j<MAX; j++){
               listArray[i]=listArray[i+1];
           }
            i--;
            N--;
        }

    }
}

void List::Display() { // Display the data values in the list
    for(int i=0; i<N; i++){
        cout<<listArray[i]<<endl;
    }
}

void List::Sort() { // Sort the list of strings based on length (shortest to longest)
    for (int i=1 ;i<N; i++){
        string temp = listArray[i];
        int j = i - 1;
        while (j >= 0 && temp.length() < listArray[j].length()){
            listArray[j+1] = listArray[j];
            j--;
        }
        listArray[j+1] = temp;
    }
}

double List::Average() { // Compute amd return the average string length for the strings in the list
    double sum;
    double average;
    for(int i=0; i<N; i++){
        sum += listArray[i].length();
    }
    average = sum/N;
    return average;
}

double List::Median() { // Compute and return the median string length for the strings in the list
    Sort();
    double sum;
    double median;
    if((N % 2) == 0){
        sum = listArray[(N/2-1)].length() + listArray[(N/2)].length();
        median = sum/2;
        return median;
    }else{
        median = listArray[N/2].length();
        return median;
    }
}

void List::Shuffle() { // Shuffle the strings in the list around
    ElementType tempArray[MAX];

    random_device random;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(random()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0, N);

    for(int i=0; i<N; i++){
        int rdInt = dis(gen);
        if(listArray[rdInt]!= "") {
            tempArray[i] = listArray[rdInt];
            listArray[rdInt] = "";
        }
        else{
            i--;
        }
    }
    for(int j=0; j<N; j++){
        listArray[j] = tempArray[j];
    }
}