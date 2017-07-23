
/****************************************************

File Name: tsuPod.cpp

Authors: L. Provvidente and V. Robertson
Date: February 20, 2015

This is the source file for the TsuPod.
In conjunction with the header and driver file,
it runs basic functions found in a music iPod.
It will add, remove, shuffle and display songs
that are stored in an array.

*****************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "tsuPod.h"

using namespace std;

const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

struct Song
{
   string title;
   string artist;
   int memorySize;
};

int songsAdded = 0;

Song songs[NUM_SONGS];

int remainingMemory();
int findEmptySpot();


void initTsuPod()
{
   Song s;
   s.title = " ";
   s.artist = " ";
   s.memorySize = 0;

   for (int i = 0; i < NUM_SONGS; i++)
      songs[i] = s;
}

/**************************************************
Function: findEmptySpot
Goes through array of songs and finds an empty spot
Returns int index of where the empty spot is.
**************************************************/

int findEmptySpot()
{
   int emptySpot = 0;

   for (int i = 0; i < NUM_SONGS; i++)
      if (songs[i].artist == " ")
         emptySpot = i;

   return emptySpot;

}

int addSong(string newTitle, string newArtist, int size)
{
   int index = findEmptySpot();

   if (newTitle == " ") {
      cout << "Error: Blank title." << endl;
      return -2; }
   else

      if (newArtist == " "){
         cout << "Error: Blank artist." << endl;
         return -2; }

      else

         if (size == 0) {
            cout << "Error: size must be grater than 0." << endl;
            return -2; }
         else

            if (remainingMemory() < size) { //There is not enough memory to store song
               cout << "Error: There is not enough memory in TsuPod for this song." << endl;
               return -1; }
            else

               if (songsAdded == NUM_SONGS) {
                  cout << "Error: Limit is 8 songs. " << endl;
                  return -2; }

               else

                  songs[index].title = newTitle;
                  songs[index].artist = newArtist;
                  songs[index].memorySize = size;

                  songsAdded++;

                  return 0;
}

int removeSong(string title)
{
   for (int i = 0; i < NUM_SONGS; i++)
   {
     if (songs[i].title==title)
      {
         songs[i].title = " ";
         songs[i].artist = " ";
         songs[i].memorySize = 0;

         songsAdded--;

         return 0;
      }
    }

   cout << "Error: there is no song with that title. " << endl;
   return -1;

}

void clearMemory()
{
   initTsuPod();
}
/********************************************
The function shows the list of available songs
********************************************/
void showSongList()
{
   Song s;
   int numberSong = 1;

   for (int i = 0; i < NUM_SONGS; i++)
   {
   cout << numberSong << ". ";
   cout << "Title: " << songs[i].title << " - ";
   cout << "Artist: " << songs[i].artist << " - ";
   cout << "Size: " << songs[i].memorySize << "MB" << endl;
   numberSong++;
   }
}
/******************************************
Function randomly shuffle the list of songs
******************************************/
void shuffle()
{
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);

    int rand1;
    int rand2;
    Song test;

    for (int i = 0; i < NUM_SONGS * 2; i++)
    {
       rand1 = rand() % NUM_SONGS;
       rand2 = rand() % NUM_SONGS;

       test = songs[rand1];
       songs[rand1] = songs[rand2];
       songs[rand2] = test;
    }

}

/***************************************************
Function: remainingMemory
Goes through array of songs and figures out how much
memory is left.
Returns int memory left in MG.
****************************************************/

int remainingMemory()
{
   int sumMemorySizes = 0;
   int remainingMemory = 0;

   for (int i = 0; i < NUM_SONGS; i++)
   {
   sumMemorySizes = sumMemorySizes + songs[i].memorySize;
   }

   remainingMemory = MEMORY_SIZE - sumMemorySizes;

   return remainingMemory;
}




