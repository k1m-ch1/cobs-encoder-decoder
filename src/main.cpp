#include "COBS.h"
#include <stdio.h>

int main() {
  uint8_t b[256];
  for (uint16_t i = 0; i < 254; i++) {
    b[i] = i + 1;
  }
  Frame frame = {.framePtr = b, .size = 254};
  printf("decoded frame: \n");
  printFrame(frame);
  Frame encodedFrame = cobsEncode(frame);
  printf("encoded frame: \n");
  printFrame(encodedFrame);
  return 0;
}
