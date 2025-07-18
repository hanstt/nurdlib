/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2024-2025
 * Håkan T Johansson
 * Hans Toshihide Törnqvist
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301  USA
 */

#ifndef F_USER_DAQ_H
#define F_USER_DAQ_H

uint32_t fud_get_max_event_length(void);

typedef void  (*lwroc_cmdline_usage)(void);
typedef int   (*lwroc_parse_cmdline_arg)(const char *);

struct lwroc_cmdline_functions
{
	lwroc_cmdline_usage             usage;
	lwroc_parse_cmdline_arg         parse_arg;
};

extern struct lwroc_cmdline_functions  _lwroc_fud_cmdline_fcns;

#endif
