#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_zone
{
	int width;
	int height;
	char bg;
}				t_zone;

typedef struct 	s_cir
{
	char 	ch;
	float	x;
	float	y;
	float	R;
	char 	bg;
}				t_cir;

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

int		checkrec(t_cir *cir)
{
	return ((cir->ch == 'C' || cir->ch == 'c') && cir->R > 0);
}

int 	incircle(float x, float y, t_cir *cir)
{
	float dist;

	dist = sqrtf((x - cir->x) * (x - cir->x) + (y - cir->y) * (y - cir->y));
	if (dist <= cir->R)
	{
		if ((cir->R - dist) < 1)
			return (2);
		return (1);
	}
	return (0);
}

void 	drawc(t_zone *zone, char **draw, t_cir *cir)
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
			ret = incircle(j, i, cir);
			if ((cir->ch == 'c' && ret == 2) || (cir->ch == 'C' && ret))
				draw[i][j] = cir->bg;
			j++;
		}
		i++;
	}

}

int 	drawcircle(FILE *fop, char **draw, t_zone *zone, t_cir *cir)
{
	int ret;

	while ((ret = (fscanf(fop, "%c %f %f %f %c\n", &cir->ch, &cir->x, &cir->y, &cir->R, &cir->bg))) == 5)
	{
		if (!checkrec(cir))
			return (0);
		drawc(zone, draw, cir);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void 	ft_free(FILE *fop, char **draw, t_zone *zone)
{
	int i;

	i = 0;
	fclose(fop);
	if (draw)
	{
		while (i < zone->height)
		{
			free(draw[i]);
			i++;
		}
		free(draw);
	}
}

int		mic(char *file)
{
	t_zone 	zone;
	t_cir	cir;
	FILE 	*fop;
	char 	**draw;

	if (!(fop = fopen(file, "r")))
	{
		return(0);
	}
	if (!getzone(fop, &zone))
		return(0);
	if (!(draw = drawzone(&zone)))
	{
		ft_free(fop, draw, &zone);
		return (2);
	}
	if (!(drawcircle(fop, draw, &zone, &cir)))
	{
		ft_free(fop, draw, &zone);
		return (0);
	}
	printzone(draw, &zone);
	ft_free(fop, draw, &zone);
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
