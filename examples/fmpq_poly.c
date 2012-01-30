/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2012 Sebastian Pancratz

******************************************************************************/

/*
    Simple example demonstrating the use of the fmpq_poly module.
 */

#include <stdlib.h>
#include <stdio.h>

#include "fmpq_poly.h"

int main(int argc, char* argv[])
{
    char *str, *strf, *strg;
    fmpq_poly_t f, g;

    fmpq_poly_init(f);
    fmpq_poly_init(g);
    fmpq_poly_set_str(f, "2  1/2 3/5");
    fmpq_poly_set_str(g, "4  1/3 2 3/2 -1/2");
    strf = fmpq_poly_get_str_pretty(f, "t");
    strg = fmpq_poly_get_str_pretty(g, "t");
    fmpq_poly_mul(f, f, g);
    str  = fmpq_poly_get_str_pretty(f, "t");
    printf("(%s) * (%s) = %s\n", strf, strg, str);
    free(str);
    free(strf);
    free(strg);
    fmpq_poly_clear(f);
    fmpq_poly_clear(g);

    return EXIT_SUCCESS;
}
