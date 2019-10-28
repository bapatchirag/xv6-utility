#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{   
    if(argc != 2)
    {
        printf(2, "Syntax error: Use touch [FILENAME]\n");
        exit();
    }
    
    int fd = open(argv[1], O_CREATE);
    close(fd);
    exit();
}
