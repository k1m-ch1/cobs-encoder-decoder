#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct {
  uint8_t *framePtr;
  uint32_t size; // i don't think we'll be sending more than 4 GB in one frame
} Frame;

void printFrame(Frame frame);

Frame cobsEncode(Frame decodedFrame);
Frame cobsDecode(Frame encodedFrame);
