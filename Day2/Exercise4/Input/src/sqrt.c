/*
   Copyright (c) 2012,2013   Axel Kohlmeyer <akohlmey@gmail.com>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   * Redistributions of source code must retain the above copyright
	 notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
	 notice, this list of conditions and the following disclaimer in the
		  documentation and/or other materials provided with the distribution.
   * Neither the name of the <organization> nor the
	 names of its contributors may be used to endorse or promote products
	 derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "fastermath.h"
#include "fm_internal.h"
#include <math.h>
#include <stdio.h>

float invsqrt(float number) {
	float y;
	y = 1.0 / sqrtf(number);
	return y;
}

float Q_rsqrt(float number) {
	// 32 bit solution
	/* float x2, y; */
	/* long i; */
	/* const float threehalfs = 1.5F; */
	/* x2 = number * 0.5F; */
	/* y = number; */
	/* i = *(long*)&y; */
	/* i = 0x5f3759df - (i >> 1); */
	/* y = *(float*)&i; */

	// 64 bit solution
	int64_t i;
	double x2, y;
	const double threehalfs = 1.5;
	x2 = number * 0.5;
	y = number;
	i = *(int64_t*)&y;
	i = 0x5fe6eb50c7b537a9 - (i >> 1);		// magic number for 64 bits
	y = *(double*)&i;
	y = y * (threehalfs - (x2 * y * y));	// NR - 1st iteration
	y = y * (threehalfs - (x2 * y * y));	// NR - 2nd iteration
	return y;
}

/*
 * Local Variables:
 * mode: c
 * compile-command: "make -C .."
 * c-basic-offset: 4
 * fill-column: 76
 * indent-tabs-mode: nil
 * End:
 */
