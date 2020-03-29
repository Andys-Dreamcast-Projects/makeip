/* IP creator (makeip)
 *
 * Copyright (C) 2000, 2001, 2002, 2019, 2020 The KOS Team and contributors.
 * All rights reserved.
 *
 * This code was contributed to KallistiOS (KOS) by Andress Antonio Barajas
 * (BBHoodsta). It was originally made by Marcus Comstedt (zeldin). Some
 * portions of code were made by Andrew Kieschnick (ADK/Napalm). Heavily
 * updated by SiZiOUS. Bootstrap replacement (IP.TMPL) was made by Jacob
 * Alberty (LiENUS).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "mr.h"

int
insert_mr(char *ip, char *fn_mr)
{
  int mr_size;
  char *mr_data;

  FILE *mr = fopen(fn_mr, "rb");

  if (mr == NULL) {
    log_error("can't open MR file \"%s\"\n", fn_mr);
    return 0;
  }
  
  fseek(mr, 0, SEEK_END);
  mr_size = ftell(mr);
  fseek(mr, 0, SEEK_SET);

  if (mr_size > 8192) {
    log_warn("MR data is larger than 8192 bytes and may corrupt bootstrap\n");
  }
  
  int result = 1;
  
  if (!mr_size) {
    log_error("MR file is empty\n");
    result = 0;	
  } else {

    mr_data = (char *)malloc(mr_size);  
    if (!fread(mr_data, mr_size, 1, mr)) {
      log_error("unable to read MR file\n");
      result = 0;
    }

    if (result) {
	  if (detect_file_type(mr_data) == MR) {	  
        memcpy(ip + 0x3820, mr_data, mr_size);
      } else {
        log_error("not a valid MR file\n");
      }
    }
	
    free(mr_data);	
  }

  fclose(mr);

  return result;
}
