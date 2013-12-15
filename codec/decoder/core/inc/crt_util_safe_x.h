/*!
 * \copy
 *     Copyright (c)  2010-2013, Cisco Systems
 *     All rights reserved.
 *
 *     Redistribution and use in source and binary forms, with or without
 *     modification, are permitted provided that the following conditions
 *     are met:
 *
 *        * Redistributions of source code must retain the above copyright
 *          notice, this list of conditions and the following disclaimer.
 *
 *        * Redistributions in binary form must reproduce the above copyright
 *          notice, this list of conditions and the following disclaimer in
 *          the documentation and/or other materials provided with the
 *          distribution.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *     "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *     LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *     FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *     COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *     BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *     CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *     LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *     ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *     POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * \file	crt_util_safe_x.h
 *
 * \brief	Safe CRT like util for cross platfroms support
 *
 * \date	06/04/2010 Created
 *
 *************************************************************************************
 */
#ifndef WELS_CRT_UTIL_SAFE_CROSS_PLATFORMS_H__
#define WELS_CRT_UTIL_SAFE_CROSS_PLATFORMS_H__

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#if defined(_WIN32)
#include <windows.h>
#include <sys/types.h>
#include <sys/timeb.h>
#else
#include <sys/timeb.h>
#include <sys/time.h>
#include "typedefs.h"
#endif//_WIN32

#include "typedefs.h"

namespace WelsDec {

#ifdef __cplusplus
extern "C" {
#endif

#define     WELS_FILE_SEEK_SET           SEEK_SET
#define     WELS_FILE_SEEK_CUR           SEEK_CUR
#define     WESL_FILE_SEEK_END           SEEK_END

typedef      FILE  WelsFileHandle;

#ifdef _WIN32
typedef      struct _timeb     SWelsTime;
#else
typedef      struct timeb      SWelsTime;
#endif

int32_t   WelsSnprintf (str_t* buffer,  int32_t sizeOfBuffer,  const str_t* format, ...);
str_t*   WelsStrncpy (str_t* dest, int32_t sizeInBytes, const str_t* src, int32_t count);
str_t*   WelsStrcat (str_t* dest, int32_t sizeInBytes, str_t* src);
int32_t   WelsStrnlen (const str_t* str,  int32_t maxlen);
int32_t   WelsVsprintf (str_t* buffer, int32_t sizeOfBuffer, const str_t* format, va_list argptr);

WelsFileHandle*        WelsFopen (const str_t* filename,  const str_t* mode);
int32_t                WelsFclose (WelsFileHandle*   fp);
int32_t                WelsFread (void* buffer, int32_t size, int32_t count, WelsFileHandle* fp);
int32_t                WelsFwrite (const void* buffer, int32_t size, int32_t count, WelsFileHandle* fp);
int32_t                WelsFseek (WelsFileHandle* fp, int32_t offset, int32_t origin);
int32_t                WelsFflush (WelsFileHandle* fp);

int32_t                WelsGetTimeOfDay (SWelsTime* tp);
int32_t                WelsStrftime (str_t* buffer, int32_t size, const str_t* format, const SWelsTime* tp);
uint16_t               WelsGetMillsecond (const SWelsTime* tp);


#ifdef __cplusplus
}
#endif

} // namespace WelsDec

#endif//WELS_CRT_UTIL_SAFE_CROSS_PLATFORMS_H__
