//Copyright 2022 Anton Pavliukevich.

//terminal_dimensions is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//terminal_dimensions is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with terminal_dimensions.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pavliukevich.anton@gmail.com on 04.09.22
//

// built and tested on Darwin Kernel Version 21.6.0: Wed Aug 10 14:28:23 PDT 2022; root:xnu-8020.141.5~2/RELEASE_ARM64_T6000 arm64

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

  if (get_terminal_window_size(&s) != 0)
	  return (1);

  output_divider_line(1);
  /* output_empty_line(1); */

  printf("%i", s.ws_row);
  output_in_color(" rows by ");

  printf("%i ", s.ws_col);
  output_in_color("colomns\n");

  printf("%i ", s.ws_xpixel);
  output_in_color("pixels by ");

  printf("%i", s.ws_ypixel);
  output_in_color(" pixels\n");

  output_divider_line(1);
  /* output_empty_line(1); */

  return (0);
}
