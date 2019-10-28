#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf(2, "Syntax error: Use wc [FILENAME]\n");
        exit();
    }
    
    int fd;
    if((fd = open(argv[1], O_RDONLY)) < 0)
    {
        printf(2, "open() Error: File doesn't exist\n");
        exit();
    }
    struct stat st;
    fstat(fd, &st);
    
    int num_newline = 0, num_words = 0, file_size = st.size, n;
    char buf[1] = {'\0'};
    while((n = read(fd, buf, 1)) > 0)
    {
        if(buf[0] == '\n')
        {
            num_newline += 1;
        }
        else if(buf[0] == ' ')
        {
            num_words += 1;
        }
    }
    if(buf[0] != ' ')
    {
        num_words += 1;
    }
    if(n < 0)
    {
        printf(2, "read() Error\n");
        exit();
    }
    printf(1, "%d\t%d\t%d\t%s\n", num_newline, num_words, file_size, argv[1]);
    
    close(fd);
    exit();
}
