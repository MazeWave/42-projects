static int	mandelbrot(int x, int y, double zx, double zy)
{
	int		n;
	double	sx;
	double	sy;
	double	tx;

	n = 0;
	tx = 0.0;
	sx = (double)x / (WIDTH / 1.0) - 1.5;
	sy = (double)y / (HEIGHT / 1.0) - 0.5;
	while (((zx * zx) + (zy * zy)) <= 4 && n < ITERATION)
	{
		tx = (zx * zx) - (zy * zy) + sx;
		zy = (2.0 * zx * zy) + sy;
		zx = tx;
		n++;
	}
	if (n == ITERATION)
		return (-1);
	return (n);
}
