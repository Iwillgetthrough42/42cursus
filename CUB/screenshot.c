#include "lib.h"

void 	writeheader(int fd, t_all *all, int filesize)
{
	char header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(filesize);
	header[3] = (unsigned char)(filesize>>8);
	header[4] = (unsigned char)(filesize>>16);
	header[5] = (unsigned char)(filesize>>24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(all->data.resx);
	header[19] = (unsigned char)(all->data.resx>>8);
	header[20] = (unsigned char)(all->data.resx>>16);
	header[21] = (unsigned char)(all->data.resx>>24);
	header[22] = (unsigned char)(all->data.resy);
	header[23] = (unsigned char)(all->data.resy>>8);
	header[24] = (unsigned char)(all->data.resy>>16);
	header[25] = (unsigned char)(all->data.resy>>24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(all->img.bits);
	write(fd, header, 54);
}

void 	screenshot(t_all *all)
{
	int fd;
	int filesize;

	fd = open("screenshot.bmp", O_RDONLY | O_CREAT | O_RDWR);
	filesize = 54 + all->data.resx * all->data.resy * 4;
	writeheader(fd, all, filesize);
	write(fd, (char *)all->img.addr, all->data.resx * all->data.resy * 4);
}
