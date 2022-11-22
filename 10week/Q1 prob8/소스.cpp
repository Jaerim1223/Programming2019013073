#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

#define MAX_PATH 256
char* getExt(char* filename)
{
    static char buf[MAX_PATH] = "";
    bool ret = false;
    char* ptr = NULL;

    ptr = strrchr(filename, '.');
    if (ptr == NULL)
        return NULL;

    strcpy(buf, ptr + 1);

    return buf;
}

int main()
{
    char path[256] = "C:/Document/Github/Test1/test.txt";
    char filename[256] = "";
    char* ptr = NULL;

#ifdef _GET_CURRENT_FILENAME
    ::GetModuleFileName(NULL, path, 256);
#endif


    if (ptr == NULL)
        strcpy(filename, path);
    else
        strcpy(filename, ptr + 1);
    printf("\n[파일명]=%s\n", filename);

    ptr = getExt(filename);
    printf("[파일의 확장자]=%s\n", ptr);



    return 0;

}