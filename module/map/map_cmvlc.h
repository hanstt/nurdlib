/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2025
 * Håkan T Johansson
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

#ifndef MODULE_MAP_CMVLC_H
#define MODULE_MAP_CMVLC_H

/* This file has two purposes:
 *
 * - Provide the global cmvlc handle g_cmvlc.
 *
 * - Include the extra cmvlc include files needed to set up MVLC
 *   sequencer stacks.
 */

#include "nconf/module/map/map.h"

#if NCONF_mMAP_bCMVLC
# include "cmvlc.h"
/*#include "../src/mvlc_const.h"*/
# include "cmvlc_stackcmd.h"
# include "cmvlc_supercmd.h"

extern struct cmvlc_client *g_cmvlc;
#endif

#endif
