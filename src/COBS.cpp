#include "COBS.h"
#include <cstdlib>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void printFrame(Frame frame) {
  for (uint32_t i = 0; i < frame.size; i++) {
    printf("%02X ", frame.framePtr[i]);
  }
  printf("\n");
}

Frame cobsEncode(Frame decodedFrame) {
  // we'll actually malloc a frame and then put it in the frame and send it back
  // out
  Frame encodedFrame = {};
  encodedFrame.framePtr = (uint8_t *)calloc(
      decodedFrame.size + (decodedFrame.size / 254) + 1, sizeof(uint8_t));
  // we'll now loop through the decodedFrame
  uint32_t offset = 1;
  uint32_t traversedBytes = 0;
  for (uint32_t i = 0; i < decodedFrame.size; i++) {
    traversedBytes++;
    if (traversedBytes == 0xFF) {
      // TODO: fix this
      encodedFrame.framePtr[i + offset - traversedBytes] = traversedBytes;
      offset++;
      traversedBytes = 1;
    }

    if (decodedFrame.framePtr[i] == 0x00) {
      // TODO: fix off-by-one error
      encodedFrame.framePtr[i + offset - traversedBytes] = traversedBytes;
      traversedBytes = 0;
      continue;
    }

    encodedFrame.framePtr[i + offset] = decodedFrame.framePtr[i];
  }

  // wrap it up when we reach the end, essentially, we can assume that there
  // is an imaginary 0x00 at the end of the decodedFrame
  traversedBytes++;
  encodedFrame.framePtr[decodedFrame.size + offset - traversedBytes] =
      traversedBytes;

  // at the end, the size should just be decodedFrame.size + offset
  encodedFrame.size = decodedFrame.size + offset;
  return encodedFrame;
}

Frame cobsDecode(Frame encodedFrame) {
  // if the decoded frame can't be decoded, I suppose we can return a nullptr to
  // say that we got an error
  Frame decodedFrame = {};
  return decodedFrame;
}
