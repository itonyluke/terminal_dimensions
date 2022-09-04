#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>

#define GREY "\033[2m"
#define DEFAULT "\033[0m"

void output_in_color(const char* str)
{
  printf("%s", GREY);
  printf("%s", str);
  printf("%s", DEFAULT);
}

void output_empty_line(unsigned int n)
{
	for (unsigned int i = 0; i < n; ++i)
  		printf("\n");
}

void output_divider_line(unsigned int n)
{
	for (unsigned int i = 0; i < n; ++i)
		output_in_color("*****************************************\n");
}

unsigned int get_terminal_window_size(struct winsize* s)
{
  int		return_value;

  return_value = ioctl(0, TIOCGWINSZ, s);
  if (return_value == -1)
  {
	  perror("Error ");
	  return (1);
  }
  return (0);
}

int main(void)
{
  struct	winsize s;

  output_divider_line(1);
  /* output_empty_line(1); */

  if (get_terminal_window_size(&s) != 0)
	  return (1);

  printf("%i ", s.ws_col);
  output_in_color("colomns by ");

  printf("%i", s.ws_row);
  output_in_color(" rows\n");

  printf("%i ", s.ws_xpixel);
  output_in_color("pixels by ");

  printf("%i", s.ws_ypixel);
  output_in_color(" pixels\n");

  output_divider_line(1);
  /* output_empty_line(1); */

  return (0);
}
