# Scabler.cpp
This is your Scabler-buddy. It will help you in making the best word choices that earn you the most amount of points. ENJOY!

To test it out yourself download the zip file.

INPUT: The user can enter as many letters as they wish
OUTPUT: A list of valid scrabble words with their points

HOW IT WORKS?
-> When the user inputs the letters, they are validated and converted to lower cases.
-> Then the program runs the fetches all the valid words *starting* from that letter (via the .txt files) and pushes them on a vector
-> Then each word of that vector is checked. If the required letters for the word are present, then that word is pushed to the final
   output vector.
-> Once all the words starting from all the given *NON-Duplicate* letters are processed, the scores are computed (based on
   the official Scrabble guidelines.
-> Finally, all possible valid words are printed with their scores.


Funfac: This was designed and coded within 24 hours.
