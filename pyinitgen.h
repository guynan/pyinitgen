
#ifndef         __PYINITGEN_H__
#define         __PYINITGEN_H__


/* All python file arguments to this program will be written to a new
 * __init__.py. Note that this will overwrite existing __init__ files. 
 *
 * For correct usage of this program it is recommended that you pipe the output
 * of all Python files (that you want to include in the init file) into this
 * program. This can be done thusly:
 *
 * user ~> ls *.py
 * f.py k.py etc.py 
 * user ~> ls *.py | xargs initGen
 * user ~> ls
 * f.py k.py etc.py __init__.py
 *
 * NOTE: Does NOT support unicode python files */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


/* Definitions - compile time contants */

#define         __INITFILE__            "__init__.py"
#define         HEADER_STYLE            "# -*- coding: utf-8 -*-"
#define         IMPORT_STYLE            "from . import"
#define         PY_EXTENSION            ".py"


/* Function prototypes */
void writeImports(FILE* fp, const char* import, int argc, char** argv);
void writeHeader(FILE* fp, const char* header);
FILE* openInitFile(const char* initfile);
int isext(char* ext, const char* exp);
char* parsePymodule(char* pymod);
int main(int argc, char** argv);
void usage(char* prog);


#endif
