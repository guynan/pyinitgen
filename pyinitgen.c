

#include "pyinitgen.h"


int main(int argc, char** argv)
{
        if(argc < 2){
                usage(argv[0]);
        }

        FILE* initf = openInitFile(__INITFILE__);

        if(!initf){
                printf("Cannot open init file for writing\n");
                exit(1);
        }

        writeHeader(initf, HEADER_STYLE);

        writeImports(initf, IMPORT_STYLE, argc, argv);

        fclose(initf);

        return 0;

}


void usage(char* prog)
{
        printf("usage: %s [ *.py ]\n", prog);
        exit(1);
}


FILE* openInitFile(const char* initfile)
{
        return fopen(initfile, "w");
}


void writeHeader(FILE* fp, const char* header)
{
        int32_t res = fprintf(fp, "%s\n\n", header);

        /* Probably unecessary */
        if(!res){
                printf("Cannot write to file\n");
                exit(1);
        }

        return;
}


/* Simply writes the import statement that is passed to the function and for
 * all arguments that are passed to the function checks if they are a valid
 * python file and writes their name --sans the python extension-- to file */
void writeImports(FILE* fp, const char* import, int argc, char** argv)
{
        /* i = 1 because we wish to ignore the file name */
        for(int32_t i = 1; i < argc; i++){
                char* pmodule = parsePymodule(argv[i]);

                if(!pmodule)
                        continue;

                fprintf(fp, "%s %s\n", import, pmodule);
        }

        /* Write \n at EOF badly designed tools don't shit themselves */
        fprintf(fp, "\n");

        return;

}


/* Parse the filename to check a few things; firstly, check whether or not
 * there is an extension. If so, check if the extension is a python extension. 
 * After that it does support passing in *.pyc files and also stupid naming 
 * conventions such as something.somethingelse.py. It doesn't support files 
 * that don't have an extension but have a python shebang because objectively 
 * speaking, one should never do such a thing. We also wish to ignore python
 * files that have the leading __ extensions */
char* parsePymodule(char* pymod)
{
        char* tmp = pymod;

        for(int32_t i = 0; tmp[i]; i++){

                if(i == 1){

                        if(tmp[0] == '_' && tmp[i] == '_'){
                                return NULL;
                        }
                }

                if(tmp[i] == '.' && isext(tmp + i, PY_EXTENSION)){
                      pymod[i] = '\0';  

                      return pymod;
                }

        }

        return NULL;

}


/* This function checks whether the extension that we get is the same as what
 * we expect. This means that we can pass in files that are not necessarily
 * Python files and still only write Python modules to the __init__.py. This
 * means that one can do a `ls | xargs ./argv[0]` and it will work.
 *
 * Note: This will ignore *.pyc files */
int isext(char* ext, const char* exp)
{
        return (0 == strcmp(ext, exp));
}

