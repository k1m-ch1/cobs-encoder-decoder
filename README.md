# Theory

So a COBS encoder essentially works by specifying the following:

- we want to save one byte out of the 256 possible bytes to act as a delimiter (standard choice is `0x00` because it's simple and it probably wastes less bytes)
- this delimiter will always be present at the end to signify the end of a frame (in our API, we shouldn't add the delimiter before sending it)

Essentially, we first start with an overhead byte specifying where the next `0x00` in the data is.

Then what follows, in the worst case scenario when we have a bunch of `0xFF` is something like this:

```
0xFF 0xFF 0xFF 0xFF 0xFF ... 0xFF 0xFF ...
 ^                            ^
 |                            |
this is overhead             this is overhead
                            and at max,
                            the block is 0xFF - 1 = 254 bytes wide
```

So if we have a frame of size `n`, we say that in the worst case scenario, every 254 bytes, we include an overhead byte.

So it's like:

```
[1 byte][254 byte][1 byte][254 byte]...[1 byte][n%254 byte]
```

So, we can safely initialize an upperbound of `n + (n / 254) + 1`

# Usage

So we can create a frame by initializing an array of bytes, and then specifying the amount of bytes. We can then encode it to get an encoded frame, which can be decoded to get a decoded frame.

Initialize the frame as such:

```c
#include <stdint.h>

uint8_t b[8] = {
  0x00,
  0x01,
  0x02,
  0x03,
  0x04,
  0x05,
  0x06,
  0x07
}

Frame frame = {
  .framePtr = b;
  .size = 8;
}

// encode the frame as such:
Frame encodedFrame = cobsEncode(frame);

Frame decodedFrame = cobsDecode(encodedFrame);
```
