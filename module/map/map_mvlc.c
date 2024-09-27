/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2020-2024
 * Håkan T Johansson
 * Michael Munch
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

#include <module/map/internal.h>
#include <nurdlib/base.h>

#ifdef SICY_MVLC

#	include <mvlcc_wrap.h>
#	include <nurdlib/log.h>
#	include <nurdlib/config.h>
#	include <nurdlib/log.h>
#	include <util/string.h>
#	include <util/time.h>

static void	mvlcc_init(void);

int ec;
mvlcc_t mvlc;

void
mvlcc_init(void)
{
	LOGF(verbose)(LOGL, "mvlcc_init {");
	
	mvlc = mvlcc_make_mvlc("");
	ec = mvlcc_connect(mvlc);

	if (ec)
	{
		log_die(LOGL, "mvlcc_init failed with error code %d.", ec);
	}
	LOGF(verbose)(LOGL, "mvlcc_init }");
}

void
sicy_deinit()
{
	LOGF(verbose)(LOGL, "sicy_deinit {");
	if (NULL != mvlc) {
		mvlcc_disconnect(mvlc);
		mvlcc_free_mvlc(mvlc);
	}
	LOGF(verbose)(LOGL, "sicy_deinit }");
}

void
sicy_map(struct Map *a_map)
{
	(void)a_map;
	LOGF(verbose)(LOGL, "sicy_map {");
	mvlcc_init();
	LOGF(verbose)(LOGL, "sicy_map }");
}

uint32_t
sicy_r32(struct Map *a_map, size_t a_ofs)
{
	uint32_t u32;

	(void) a_map;
	(void) a_ofs;
	
	u32 = 0;
	
	ec = mvlcc_single_vme_read(mvlc, a_map->address + a_ofs, &u32, 32, 32);
	
	return u32;
}

uint16_t
sicy_r16(struct Map *a_map, size_t a_ofs)
{
	uint32_t u32;

	(void) a_map;
	(void) a_ofs;

	u32 = 0;

	ec = mvlcc_single_vme_read(mvlc, a_map->address + a_ofs, &u32, 32, 16);

	return (uint16_t)u32;
}


void
sicy_w32(struct Map *a_map, size_t a_ofs, uint32_t a_u32)
{
	(void) a_map;
	(void) a_ofs;
	(void) a_u32;
}

void
sicy_w16(struct Map *a_map, size_t a_ofs, uint16_t a_u16)
{
	(void) a_map;
	(void) a_ofs;
	(void) a_u16;
}

MAP_FUNC_EMPTY(sicy_setup);
MAP_FUNC_EMPTY(sicy_shutdown);
UNMAP_FUNC_EMPTY(sicy);

#ifdef POKE_MVLC

#define POKE(Mode, m, value) \
{ \
 (void)value; \
 (void)a_address; \
 (void)a_bits; \
 (void)a_ofs; \
}

void
poke_r(uint32_t a_address, uintptr_t a_ofs, unsigned a_bits)
POKE(Read, r, 0)

void
poke_w(uint32_t a_address, uintptr_t a_ofs, unsigned a_bits, uint32_t a_value)
POKE(Write, w, a_value)

#endif

#endif