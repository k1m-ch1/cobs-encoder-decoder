import ctypes

cobs = ctypes.CDLL("./libcobs.so")
class Frame(ctypes.Structure):
    _fields_ = [
        ("framePtr", ctypes.POINTER(ctypes.c_uint8)),
        ("size", ctypes.c_uint32),
    ]

cobs.cobsEncode.argtypes = [Frame]
cobs.cobsEncode.restype = Frame

data = bytes([0x11, 0x22, 0x00, 0x33])
buffer = (ctypes.c_uint8*len(data)).from_buffer_copy(data)
print(type(buffer))
frame = Frame(
    buffer,
    len(data)
)

encoded = cobs.cobsEncode(frame)
print(encoded.size)
print(bytes(encoded.framePtr[:encoded.size]))


