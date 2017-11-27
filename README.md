# pyinitgen

This is a simple C program to take the files in a directory which is used for 
Python development and generate \_\_init\_\_.py on the fly.

## Building
As it is all written to be pure C99, there should be no problems building on 
other compilers. However as I didn't want to pull in autotools for such a 
simple build, there is no autodetection of compilers no operating systems.

### Building on Linux
`user ~> make`
`user ~# make install clean`

### Building on FreeBSD
`user ~> make clang`
`user ~# make install clean`

## Other features
There is also a `make test` target which does a build and subsequently 
generates an \_\_init\_\_.py based on the contents of the current directory and
concatenates the file to the standard output

## Usage
This is designed to accept files as string as input. 

Perhaps the simplest way to run this software is thusly;

`ls | xargs pyinitgen`



