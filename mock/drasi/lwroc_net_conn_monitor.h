/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2024-2025
 * Hans Toshihide Törnqvist
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

#ifndef LWROC_NET_CONN_MONITOR_H
#define LWROC_NET_CONN_MONITOR_H

#define LWROC_MON_CHECK_COPY_CONN_MON_BLOCK(a, b)

typedef struct
{
	int	_aux_status;
} lwroc_monitor_conn_block;

typedef struct {
	lwroc_monitor_conn_block	_block;
	int	dummy;
} lwroc_net_conn_monitor;

#endif
