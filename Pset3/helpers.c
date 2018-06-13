// Helper functions for music
// this is pretty messy :(

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // convert numerator and denominator into integers
    int numerator = fraction[0] - 48;
    int denominator = fraction[2]- 48;

    // multiply denominator and numerator by 2 until denom becomes = 8
    while (denominator != 8)
    {
        numerator = numerator * 2;
        denominator = denominator * 2;
    }

    return numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int ASCII_FIX = 48;
    // Parse the string into a note and its octave
    int notelength = strlen(note);
    int letter_note = note[0];
    int octave = note[notelength - 1] - ASCII_FIX;

    // find the hertz of the octave's A key
    float a_frequency = 440.0;
    if (octave > 4)
        a_frequency = pow(2, (octave - 4)) * a_frequency;
    else if (octave < 4)
        a_frequency = pow(2, -(4 - octave)) * a_frequency;
    // set the frequency (before accounting for sharps or flats)
    float letter_frequency;

    if (letter_note == 'A')
    {
        letter_frequency = a_frequency;
    }
    else if (letter_note == 'B')
    {
        letter_frequency = a_frequency * pow(2.0, (2.0/12.0));
    }
    else if (letter_note == 'C')
    {
        letter_frequency = a_frequency * pow(2.0, -(9.0/12.0));
    }
    else if (letter_note == 'D')
    {
        letter_frequency = a_frequency * pow(2.0, -(7.0/12.0));
    }
    else if (letter_note == 'E')
    {
        letter_frequency = a_frequency * pow(2.0, -(5.0/12.0));
    }
    else if (letter_note == 'F')
    {
        letter_frequency = a_frequency * pow(2.0, -(4.0/12.0));
    }
    else if (letter_note == 'G')
    {
        letter_frequency = a_frequency * pow(2.0, -(2.0/12.0));
    }

    //adjust for flats or sharps
    if(note[1] == '#')
    {
        letter_frequency = letter_frequency * pow(2.0, (1.0/12.0));
    }
    else if(note[1] == 'b')
    {
        letter_frequency = letter_frequency * pow(2.0, -(1.0/12.0));
    }

    return round(letter_frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "", 1))
        return false;
    else
        return true;
}
