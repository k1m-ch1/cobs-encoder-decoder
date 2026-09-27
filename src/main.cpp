#include "COBS.h"
#include <stdio.h>

int main() {
  uint8_t b[256];
  for (uint16_t i = 0; i < 255; i++) {
    b[i] = i + 3;
  }
  Frame frame = {.framePtr = b, .size = 255};

  // uint8_t b[256] = {0x11, 0x00, 0x00, 0x00};
  // Frame frame = {.framePtr = b, .size = 2};
  printf("decoded frame: \n");
  printFrame(frame);
  Frame encodedFrame = cobsEncode(frame);
  printf("encoded frame: \n");
  printFrame(encodedFrame);
  Frame decodedFrame = cobsDecode(encodedFrame);
  printf("decoded frame: \n");
  printFrame(decodedFrame);
  return 0;
}
