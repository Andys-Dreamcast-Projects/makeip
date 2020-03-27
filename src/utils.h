/* IP Creator (makeip)
 * 
 * Copyright (C) 2000, 2001, 2002, 2019, 2020 KallistiOS Team and contributors.
 * All rights reserved.
 * 
 * This code was contributed to KallistiOS by Andress Antonio Barajas 
 * (BBHoodsta). It was originally made by Marcus Comstedt (zeldin). Some
 * portions were made by Andrew Kieschnick (ADK/Napalm). Heavily updated by
 * SiZiOUS. Bootstrap replacement (IP.TMPL) was made by Jacob Alberty (LiENUS).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libgen.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>

#define MAX_YR 9999
#define MIN_YR 1900

char *program_name;

void trim(char *str);

void set_program_name(char *argv0);

void verbose_enable();

void log_notice(const char *format, ...);
void log_warn(const char *format, ...);
void log_error(const char *format, ...);

void halt(const char *format, ...);

int long_parse(char *str, long *result);
int substr_long_parse(char *str, int start, int length, long *result);

int is_valid_date(char *str);
int is_valid_hex(char *str);
int is_strict_bool(char c);

int is_file_exist(char *filename);

#endif /* __UTILS_H__ */
