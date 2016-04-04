#include "../includes/fdf.h"

void	print_segment_x(int x1, int y1, int x2, int y2, t_pixel_to_image *img)
{
	t_point	point;
	int dx, dy;
	int e;

	e = abs(x2 - x1);
	dx = abs(e * 2);
	dy = abs((y2 - y1) * 2);
	point.x = x1;
	point.y = y1;
	while (point.x <= x2)
	{
		ft_pixel_put_to_image(img);
		point.x++;
		if ((e = e - dy) <= 0)
		{
			point.y++;
			e = e + dx;
		}
	}
}

void	print_segment_y(int x1, int y1, int x2, int y2, t_pixel_to_image *img)
{
	t_point	point;
	int	dx;
	int	dy;
	int	e;

	e = abs(2 - y1);
	dy = abs(e * 2);
	dx = abs((x2 - x1) * 2);
	point.x = x1;
	point.y = y1;
	while (point.y != y2)
	{
		ft_pixel_put_to_image(img);
		if (point.y > y2)
			point.y--;
		else
			point.y++;
		if ((e -= dx) <= 0)
		{
			point.x++;
			e += dy;
		}
	}
	ft_pixel_put_to_image(img);
}

void	draw_x_or_y(int x1, int y1, int x2, int y2, t_pixel_to_image *img)
{
	int	dx;
	int	dy;

	dx = abs(x2 - x1) * 2;
	dy = abs(y2 - y1) * 2;
	if (dx > dy)
		print_segment_x(x1, y1, x2, y2, img);
	else
		print_segment_y(x1, y1, x2, y2, img);

}
