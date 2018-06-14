// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return 8 * (fraction[0] - '0') / (fraction[2] - '0');
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    float n = 0.0;  // number of semitones from A4
    // adjust n according to natural key position shift from A
    switch (note[0])
    {
        case 'A':
            break;

        case 'B':
            n += 2;
            break;

        case 'C':
            n -= 9;
            break;

        case 'D':
            n -= 7;
            break;

        case 'E':
            n -= 5;
            break;

        case 'F':
            n -= 4;
            break;

        case 'G':
            n -= 2;
    }
    // handle note in XY format
    if (strlen(note) == 2)
    {
        // adjust n according to the number of octaves from the 4th octave
        n += 12 * (((note[1]) - '0') - 4);
    }
    // handle note in XYZ format
    else
    {
        // adjust n according to the accidental shifts
        switch (note[1])
        {
            case '#':
                n++;
                break;

            case 'b':
                n--;
        }
        // adjust n according to the number of octaves from the 4th octave
        n += 12 * (((note[2]) - '0') - 4);
    }
    return round(pow(2, n / 12) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    return false;
}