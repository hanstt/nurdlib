/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2015-2021, 2023-2024
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

#include <ntest/ntest.h>
#include <nurdlib/config.h>
#include <nurdlib/crate.h>
#include <module/map/map.h>
#include <module/mesytec_madc32/internal.h>
#include <module/mesytec_madc32/offsets.h>

NTEST(DefaultConfig)
{
	char mem[MAP_SIZE];
	struct Crate *crate;
	struct MesytecMadc32Module *madc32;

	crate_setup();
	module_setup();
	map_setup();

	ZERO(mem);
	map_user_add(0x01000000, mem, sizeof mem);

	config_load("tests/mesytec_madc32/empty.cfg");
	crate = crate_create();

	madc32 = (void *)crate_module_find(crate, KW_MESYTEC_MADC32, 0);
	madc32->mxdc32.do_sleep = 0;

	crate_init(crate);

	NTRY_I(KW_MESYTEC_MADC32, ==, madc32->mxdc32.module.type);
	/* Cannot check event_max until after we know the firmware. */

	NTRY_I(0xffffffff, ==, madc32->mxdc32.channel_mask);

	crate_free(&crate);
	map_user_clear();
	map_shutdown();
	config_shutdown();
}

NTEST_SUITE(MESYTEC_MADC32)
{
	NTEST_ADD(DefaultConfig);
}
