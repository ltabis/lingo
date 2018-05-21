/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** prototypes
*/

#ifndef PROTO_H_
#define PROTO_H_

char *choose_random_word(char **);
void start_game_loop(char *);
void display_first_lines(char *);
int compare_same_letters(char *, char *, char *);
void check_letter(unsigned int, char, char *, char *);
int compare_strings(char *, char *);

#endif
