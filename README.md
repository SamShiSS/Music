# Music

/songs: This folder contains text files of music notes of multiple songs.

note.c: In this file is a program that prints the frequencies (in Hz) of all of the notes in an octave, and outputs a WAV file (an audio file) via which you can hear those same notes.

synthesize.c: In this file is a program that synthesizes a song from a sequence of notes.

wav.h/wav.c: In these two files are the functions that implement support for WAV files plus a few others, used by both notes.c and synthesize.c.

helpers.h/helpers.c: In these two files are the declaration and implementation for three helper functions (used by synthesize.c and note.c): duration, frequency, and is_rest
