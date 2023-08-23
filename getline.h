#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*define macro*/
#define READ_SIZE 1024
#define READ_SIZE_INCREMENT 1024

/*prototypes*/
void init_buffer(char **buf_es, size_t *size);
ssize_t read_into_buffer(char *buf_es, size_t length, FILE *stream);
void expand_buffer(char **buf_es, size_t *length);
ssize_t perform_getline(char *buf_es, size_t len, size_t *index, ssize_t r);
ssize_t my_getline(char **buf_es, size_t *length, FILE *stream);

#endif /*GETLINE_H*/
