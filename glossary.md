## Bit

Simply a 1 or a 0

## Byte

A collection of 8 bits, therefore 2^8 or 256 possible values in base-10 from 00000000 to 11111111

## Compile / Compilation

Conversion of human-readable instructions into machine code (turns out the C++ compiler essentially converts to Assembly first matching the machine architecture first which is arguably human readable which is then converted to an executable binary) See https://stackoverflow.com/questions/137038/how-do-you-get-assembler-output-from-c-c-source-in-gcc

## Immutability / Mutability

Immutability just means that you can't modify the way in which the data is stored

## Memory Location

An indexed/referencable position in the memory of a device, for example, specified bytes in a sector of a hard drive formatted in FAT32 [The Cherno has a brilliant explanation on how pointers are literally just memory locations in C++ here](https://www.youtube.com/watch?v=DTxHyVn0ODg)

## RAM / Volatile Memory

Fast-access and Fast-write memory locations used by programs to store data at runtime

## Shallow and Deep Copies

Shallow Copies are pointers to the memory location of the actual data. Deep Copies use a new memory location to store the data instead which is completely dissociated from the original (allows you to modify the copy without affecting the original, but can take up significantly more space)

## Variable (noun)

A collection of memory that acts as a representation of data of some kind (a number, letter, word, boolean value, etc) which can be read and modified by programs
