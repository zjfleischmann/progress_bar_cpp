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

#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class ProgressBar
{
public:
  /* Takes in a char for filling up the bar and the width of the bar */
  ProgressBar(unsigned int totalWidth);

  /* Fills the bar upto a given number */
  void setPercentage(float pct);

  /* Optional - Resets the progress bar */
  void endAndReset();

private:
  unsigned int width = 0;         // total character width in bar, includes label and brackets
  unsigned int progressBarBlocks; // number of blocks dedicated to the progress bar itself
  float percent;                  // Actual percent progress
  std::vector<char> bar;          // The entire bar is stored in a vector
  void setUpBar();                // used for initial bar setup
};
