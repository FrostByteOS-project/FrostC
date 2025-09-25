# FrostC
A fairly lightweight standard C library for FrostByteOS
Contains a subset of POSIX C headers with a bit of extensions.

# Building
Just run:
```bash
make
```
it will output a file 'libc.so.1' in the current working directory,
binaries can use in FrostByteOS if you place it in the '/lib' directory

# Implemented headers
- unistd.h
- time.h
- string.h

# TODO
- stdio.h
- signal.h
- math.h
- stdlib.h

# License
Licensed under GPLv3
