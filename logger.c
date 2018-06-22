/**
 * Original code from Varun Gubpta.
 *
 * Modified by Matheus Carnelutt
 */

#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fp;
static int SESSION_TRACKER;  // Keeps track of session

char *print_time() {
  int size = 0;
  time_t t;
  char *buf;

  t = time(NULL); /* get current calendar time */

  char *timestr = asctime(localtime(&t));

  timestr[strlen(timestr) - 1] = 0;  // Getting rid of \n

  size = strlen(timestr) + 1 + 2;  // Additional +2 for square braces
  buf  = (char *) malloc(size);

  memset(buf, 0x0, size);
  snprintf(buf, size, "[%s]", timestr);

  return buf;
}
void log_print(char *filename, int line, char *fmt, ...) {
  va_list list;
  char *time_string;

  if (SESSION_TRACKER > 0)
    fp = fopen("log.txt", "a");
  else
    fp = fopen("log.txt", "w");

  time_string = print_time();
  fprintf(fp, "%s ", time_string);
  free(time_string);

  fprintf(fp, "[%s:%d] ", filename, line);

  va_start(list, fmt);
  vfprintf(fp, fmt, list);
  va_end(list);

  fputc('\n', fp);

  SESSION_TRACKER++;

  fclose(fp);
}