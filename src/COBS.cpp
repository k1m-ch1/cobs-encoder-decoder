#include "COBS.h"
#include <stdint.h>
#include <stdio.h>

void printFrame(Frame frame) {
  for (uint32_t i = 0; i < frame.size; i++) {
    printf("%02X ", *(frame.framePtr + i));
  }
  printf("\n");
}

Frame cobsEncode(Frame decodedFrame) {
  // we'll actually malloc a frame and then put it in the frame and send it back
  // out
  Frame encodedFrame = {};
  return encodedFrame;
}

Frame cobsDecode(Frame encodedFrame) {
  // if the decoded frame can't be decoded, I suppose we can return a nullptr to
  // say that we got an error
  Frame decodedFrame = {};
  return decodedFrame;
}
