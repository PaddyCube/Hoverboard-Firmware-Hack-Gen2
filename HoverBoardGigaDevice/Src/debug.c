#include <stdarg.h>
#include <stdio.h>
#include "defines.h"
#include "comms.h"
#include "debug.h"

// Support float in printf. Uses 22% memory of 32K
//asm(".global _printf_float");

uint32_t debug_port = USART_MASTERSLAVE;


void sendDebug(const char* buffer, size_t n) {
  if (!debug_port) { return; }
  SendBuffer(debug_port, buffer, n);
}

void debug_print(const char* buffer) {
  if (!debug_port) { return; }
  SendBuffer(debug_port, buffer, strlen(buffer));
}

void debug_println(const char* buffer) {
  if (!debug_port) { return; }
  SendBuffer(debug_port, buffer, strlen(buffer));
  SendBuffer(debug_port, "\r\n", 2);
}

size_t debug_printf(const char * format, ...) {
  if (!debug_port) { return 0; }
  char buffer[512];
  va_list args;
  va_start(args, format);
  size_t n = vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);
  SendBuffer(debug_port, buffer, n);
  return n;
}
