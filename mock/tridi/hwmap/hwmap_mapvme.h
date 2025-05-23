/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2024-2025
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

#ifndef MOCK_TRIDI_HWMAP_MAPVME_H
#define MOCK_TRIDI_HWMAP_MAPVME_H

typedef struct hwmap_opaque_t {
	int	dummy;
} hwmap_opaque;

volatile hwmap_opaque *hwmap_map_vme(char const *, uint32_t, uint32_t, const
    char *, void **);
void hwmap_unmap_vme(void *);

#endif
