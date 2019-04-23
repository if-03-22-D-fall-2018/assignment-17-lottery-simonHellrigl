/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "lottery.h"
#include <string.h>
#include <stdlib.h>

static FILE* stream;
static char separator;
static int drawing_of_numbers[TIP_SIZE];



bool init_lottery(const char *csv_file, char csv_separator)
{
    stream = fopen(csv_file, "r");
    if (stream == 0)
    {
        return false;
    }
    separator = csv_separator;
    return true;

}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
  if (tip_number < 0 || tip_number >= 44)
  {
    return false;
  }
      int count = 0;
      char line[MAX_LINE_LEN];
      while ( fgets(line, MAX_LINE_LEN, stream) != NULL)
      {
          if (count == tip_number)
          {
              count = 0;
              char str[2];
              str[0] = separator;
              str[1] = '\0';
              char* ptr = strtok(line, str);
              while(ptr != 0)
              {
                  ptr = strtok(0, str);
                  if (ptr == 0) break;
                  if (atoi(ptr) > 0 && atoi(ptr) <= 45)
                  {
                      tip[count] = atoi(ptr);
                  }
                  count++;
              }
              rewind(stream);
              return true;
          }
          count++;
      }
    return false;
}

bool set_drawing(int drawing_numbers[TIP_SIZE])
{
  for (int i = 0; i < TIP_SIZE; i++) {
    if (drawing_numbers[i] <= 0 || drawing_numbers[i] > 45) return false;
    else drawing_of_numbers[i] = drawing_numbers[i];
  }
  return true;
}

int get_tip_result(int tip_number)
{
    return -1;

}

int get_right_tips_count(int right_digits_count)
{
  return 0;

}
