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
      else if (tip != 0)
      {
        int counter = 0;
        char line[MAX_LINE_LEN];
        while ( fgets(line, MAX_LINE_LEN, stream) != NULL)
        {
            if (tip_number == counter)
            {
                counter = 0;
                char string[2];
                string[0] = separator;
                string[1] = '\0'; //end of string
                char* split = strtok(line, string);

                while(split != 0)
                {
                    split = strtok(0, string);
                    if (split == 0)
                    {
                      break;
                    }
                    else if (atoi(split) > 0 && atoi(split) <= 45)  //makes string to int
                    {
                        tip[counter] = atoi(split);
                    }
                    counter++;
                }
                rewind(stream);
                return true;
            }
            else
            {
                counter++;
            }
        }
      }
    return false;
}

bool set_drawing(int drawing_numbers[TIP_SIZE])
{
  if (drawing_numbers != 0)
  {
    for (int i = 0; i < TIP_SIZE; i++)
    {
      if (drawing_numbers[i] <= 0 || drawing_numbers[i] > 45)
      {
         return false;
      }
      else
      {
        drawing_of_numbers[i] = drawing_numbers[i];
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

int iterate_threw_array(int counter, int tip[TIP_SIZE])
{
  for (int i = 0; i < TIP_SIZE; i++) //iterates throw drawing_of_numbers
  {
    for (int j = 0; j < TIP_SIZE; j++)
    {
      if (drawing_of_numbers[i] == tip[j])
      {
         counter++;
      }
    }
  }
  return counter;
}

  int get_tip_result(int tip_number)
  {
    bool empty;
    if (tip_number < 0 || tip_number >= 44)
    {
       return -2;

       //checks if drawing_of_numbers array is empty
       for (int i = 0; i < TIP_SIZE; ++i)
       {
           if (drawing_of_numbers[i] != 0)
           {
             empty = false;
           }
       }
       empty = true;
    }
    else if (empty)
    {
      return -1;
    }

    int tip[TIP_SIZE];
    int counter = 0;

    get_tip(tip_number,tip);

    counter = iterate_threw_array(counter, tip);
    return counter;



  }

int get_right_tips_count(int right_digits_count)
{
  return 0;

}
