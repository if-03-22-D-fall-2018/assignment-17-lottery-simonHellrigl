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

#define 	UUID_LEN   40
#define 	MAX_TIP_LEN   17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)

struct TestCase{
  const char* name;
  bool succes;
  void(* test_function)(struct TestCase *tc);

};
bool init_lottery(const char *csv_file, char csv_separator)
{
  /*if (&csv_file == "") {
    return false;
  }
  FILE* fd = fopen(“book.txt”, “r”);
  return true;*/


}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{

}

bool set_drawing(int drawing_numbers[TIP_SIZE])
{

}

int get_tip_result(int tip_number)
{

}

int get_right_tips_count(int right_digits_count)
{

}
