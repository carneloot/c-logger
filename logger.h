#ifndef __LOGGER_H__
#define __LOGGER_H__

void log_print(char *filename, int line, char *fmt, ...);

#define LOG_PRINT(...) log_print(__FILE__, __LINE__, __VA_ARGS__)

#endif /* __LOGGER_H__ */
