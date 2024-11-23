/********************************** Modine Manufacturing Company ***********************************
 *                                                                                                  *
 *                          ##########                                                              *
 *                      ################                                                            *
 *                   ###         ########                                                           *
 *                 ##              ######                                                           *
 *               #                  #####                                                           *
 *             # MMMMMMM     MMMMMM     MMMMMMM     MMMMMMMMM      MMMM  MMMMMMM   MMMM  MMMMMMMMMM *
 *           #   MMMMMMM    MMMMMMM  MMMMMMMMMMMM   MMMMMMMMMMMM   MMMM  MMMMMMM   MMMM MMMMMMMMMMM *
 *               MMMMMMMM  MMM MMMM MMMMM    MMMMM MMMMM    MMMMM MMMMM MMMMMMMMM  MMM  MMMM        *
 *              MMMM MMMM MMM MMMM MMMMM     MMMMM MMMMM    MMMMM MMMM  MMMM MMMM MMMM  MMMMMMMMM   *
 *              MMMM MMMMMMM  MMMM MMMMM     MMMM  MMMM    MMMMM MMMMM  MMM  MMMMMMMMM MMMMM        *
 *              MMM   MMMMM   MMMM  MMMMMMMMMMMM  MMMMMMMMMMMMM  MMMMM MMMM   MMMMMMM  MMMMMMMMMM   *
 *             MMMM   MMMM   MMMM     MMMMMMM     MMMMMMMMMM     MMMM  MMMM   MMMMMMM  MMMMMMMMMM   *
 * 888888                  8                                                                        *
 * 888888               88                                                                          *
 * 88888888         888                                                                             *
 *  8888888888888888                                                                                *
 *    8888888888                                                                                    *
 *                                                                                                  *
 * *************************************************************************************************/

/********************************* Modine Confidentiality Notice: **********************************
 * This document may contain confidential information, including information protected by the       *
 * attorney/client privilege and/or attorney work product doctrine. Your handling of this           *
 * information may be subject to a legal agreement, law or regulation restricting your rights as    *
 * to use, duplication, and/or disclosure. Modine prohibits any unauthorized use, duplication, or   *
 * disclosure of this document and any associated files. If you received this file in error,        *
 * please advise the sender and permanently delete this document and any associated files.          *
 ***************************************************************************************************/

#include "../include/ProgressBar.hpp"

#include <math.h>

/* Constants */
const unsigned int START_INDEX = 2;
const unsigned int MAX_WIDTH = 200;
const char notDoneChar = ' ';
const char doneChar = '=';

/* Defining the constructor */
ProgressBar::ProgressBar(unsigned int totalWidth)
{
  /* Limit width */
  if(totalWidth > MAX_WIDTH)
  {
    width = MAX_WIDTH;
  }
  else
  {
    width = totalWidth;
  }

  setUpBar();
}

void ProgressBar::setUpBar()
{
  bar.clear();
  bar.push_back(' ');
  bar.push_back('[');

  progressBarBlocks = width         // total width that can be used
                      - START_INDEX // first characters
                      - 5;          // last bracket, space, percentage

  for(unsigned int i = START_INDEX; i < (progressBarBlocks + START_INDEX); i++)
  {
    bar.push_back(notDoneChar);
  }

  bar.push_back(']');
}

/* Defining setPercentage */
void ProgressBar::setPercentage(float pct)
{
  /* Update private variable */
  percent = pct;

  /* Calculate number of blocks to complete */
  float blocks_f = (pct / 100) * (float)progressBarBlocks;
  unsigned int blocks_i = (int)roundf(blocks_f);

  /* Limit to prevent overrun */
  if(blocks_i > progressBarBlocks)
  {
    blocks_i = progressBarBlocks;
  }

  /* Fill in bar */
  for(int i = 0; i < blocks_i; i++)
  {
    if((i == (blocks_i - 1)) && (i < (progressBarBlocks - 1)))
    {
      bar[START_INDEX + i] = '>';
    }
    else
    {
      bar[START_INDEX + i] = doneChar;
    }
  }

  /* Print whole vector */
  std::cout << '\r';
  for(int j = 0; j < bar.size(); j++)
  {
    std::cout << bar[j] << std::flush;
  }

  /* Display percentage label */
  std::cout << (int)percent << "%";

  /* Catch 100% */
  if(pct >= 100.0)
  {
    endAndReset();
  }
}

void ProgressBar::endAndReset()
{
  std::cout << std::endl;
  percent = 0;
  setUpBar();
}
