#include <iostream>
#include <fcntl.h>    // For open()
#include <unistd.h>   // For close()
#include <stdio.h>
#include <sys/types.h>
#include <streambuf>
#include <ios>
#include <stdlib.h>

int main()
{
	char *a = (char *)malloc(sizeof(ptrdiff_t));
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);


	dup2(fd, STDIN_FILENO);
	std::cin >> a;
	std::cout << a;
	write(2, "a", 1);
}