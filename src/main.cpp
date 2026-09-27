#include "COBS.h"

int main() {
  uint8_t b[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
  Frame frame = {.framePtr = b, .size = 8};
  printFrame(frame);
  return 0;
}
