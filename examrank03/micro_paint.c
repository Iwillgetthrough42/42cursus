#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
	int width;
	int height;
	char bg;
}				t_zone;

typedef struct 	s_rec
{
	char 	ch;
	double	x;
	double	y;
	double	width;
	double 	height;
	char 	bg;
}				t_rec;

int 	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	printzone(char **draw, t_zone *zone)
{
	int i;
	int j;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			write(1, &draw[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	**drawzone(t_zone *zone)
{
	char **draw;
	int i;
	int j;

	if (!(draw = (char **)malloc(sizeof(char *) * zone->height)))
		return (0);
	i = 0;
	while (i < zone->height)
	{
		if (!(draw[i] = (char *)malloc(sizeof(char) * zone->width)))
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j <zone->width)
		{
			draw[i][j] = zone->bg;
			j++;
		}
		i++;
	}
	return (draw);
}

int 	getzone(FILE *fop, t_zone *zone)
{
	if ((fscanf(fop, "%d %d %c\n", &zone->width, &zone->height, &zone->bg) != 3))
		return (0);
	if (!((zone->width > 0 && zone->width <= 300) && (zone->height > 0 && zone->height <= 300)))
		return (0);
	return (1);
}

int		checkrec(t_rec *rec)
{
	return ((rec->ch == 'R' || rec->ch == 'r') && rec->width > 0 && rec->height > 0);
}

int 	inrectangle(double x, double y, t_rec *rec)
{
	if (x < rec->x || x > rec->x + rec->width || y < rec->y || y > rec->y + rec->height)
		return (0);
	if (x - rec->x < 1 || (rec->x + rec->width) - x < 1 || y - rec->y < 1 || (rec->y + rec->height) - y < 1)
		return (2);
	return (1);
}

void 	drawr(t_zone *zone, char **draw, t_rec *rec)
{
	int ret;
	int i;
	int j;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			ret = inrectangle(j, i, rec);
			if ((rec->ch == 'r' && ret == 2) || (rec->ch == 'R' && ret))
				draw[i][j] = rec->bg;
			j++;
		}
		i++;
	}

}

int 	drawrec(FILE *fop, char **draw, t_zone *zone, t_rec *rec)
{
	int ret;

	while ((ret = (fscanf(fop, "%c %lf %lf %lf %lf %c\n", &rec->ch, &rec->x, &rec->y, &rec->width, &rec->height, &rec->bg))) == 6)
	{
		if (!checkrec(rec))
			return (0);
		drawr(zone, draw, rec);
	}
	if (ret != -1)
		return (0);
	return (1);
}

int		mic(char *file)
{
	t_zone 	zone;
	t_rec	rec;
	FILE 	*fop;
	char 	**draw;

	if (!(fop = fopen(file, "r")))
	{
		return(0);
	}
	if (!getzone(fop, &zone))
		return(0);
	if (!(draw = drawzone(&zone)))
		return (2);
	if (!(drawrec(fop, draw, &zone, &rec)))
		return (0);
	printzone(draw, &zone);
	return (1);
}

int		main(int argc, char **argv)
{
	char *msg;
	int  ret;

	msg = "Error: Operation file corrupted\n";
	if (argc != 2)
	{
		write(1, "Error: argument", 15);
		write(1, "\n", 1);
		return (1);
	}
	ret = mic(argv[1]);
	if (ret == 0)
	{
		write(1, msg, 32);
		return (1);
	}
	else if (ret == 2)
		return (1);
	return (0);
}
