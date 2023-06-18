
static int	julia(int x, int y, double zx, double zy)
{
	int		n;
	double	sx;
	double	sy;
	double	tx;

	n = 0;
	tx = 0.0;
	sx = (double)x / (WIDTH / 7.0) - 2.0;
	sy = (double)y / (HEIGHT / 7.0) - 2.0;
	while (((zx * zx) + (zy * zy) < 4) && (n < ITERATION))
	{	
		tx = (zx * zx) - (zy * sx);
		zy = (2.0 * zx * zy) + sy;
		zx = tx + sy;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n);
}
