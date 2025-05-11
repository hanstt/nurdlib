/*
 * nurdlib, NUstar ReaDout LIBrary
 *
 * Copyright (C) 2015-2018, 2021, 2023-2025
 * Bastian Löher
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

#ifndef UTIL_PACKER_H
#define UTIL_PACKER_H

#include <util/queue.h>
#include <util/udp.h>

#define PACKER_CREATE_STATIC(packer, buf)\
	do {\
		(packer).data = buf;\
		(packer).bytes = sizeof buf;\
		(packer).ofs = 0;\
	} while (0)
#define PACKER_CREATE(packer, buf, bytes_)\
	do {\
		(packer).data = buf;\
		(packer).bytes = bytes_;\
		(packer).ofs = 0;\
	} while (0)
#define PACK(packer, bits, value, label) \
	do { \
		if (!pack##bits(&packer, value)) { \
			log_error(LOGL, "Packing " #value " failed."); \
			goto label; \
		} \
	} while (0)
#define PACK_LOC(packer, label) \
	do { \
		if (!pack_str(&packer, __FILE__) || \
		    !pack16(&packer, __LINE__)) { \
			log_error(LOGL, "Packing location failed."); \
			goto label; \
		} \
	} while (0)
#define PACKER_LIST_PACK(list, bits, value) \
	do { \
		struct Packer *packer_; \
		packer_ = packer_list_get(&list, bits); \
		if (!pack##bits(packer_, value)) { \
			/* TODO: Ugggggh... */ \
			log_die(LOGL, "Shouldn't happen!"); \
		} \
	} while (0)
#define PACKER_LIST_PACK_STR(list, str) \
	do { \
		struct Packer *packer_; \
		packer_ = packer_list_get(&list, (strlen(str) + 1) * 8); \
		if (!pack_str(packer_, str)) { \
			log_die(LOGL, "Shouldn't happen!"); \
		} \
	} while (0)
#define PACKER_LIST_PACK_LOC(list) \
	do { \
		PACKER_LIST_PACK_STR(list, __FILE__); \
		PACKER_LIST_PACK(list, 16, __LINE__); \
	} while (0)
#define PACKER_GET_PTR(packer) ((uint8_t *)(packer).data + (packer).ofs)

struct Packer {
	void	*data;
	size_t	bytes;
	size_t	ofs;
};
TAILQ_HEAD(PackerList, PackerNode);
struct PackerNode {
	struct	UDPDatagram dgram;
	struct	Packer packer;
	TAILQ_ENTRY(PackerNode)	next;
};

int		pack_is_empty(struct Packer const *) FUNC_RETURNS;
int		pack_str(struct Packer *, char const *) FUNC_RETURNS;
int		pack8(struct Packer *, uint8_t) FUNC_RETURNS;
int		pack16(struct Packer *, uint16_t) FUNC_RETURNS;
int		pack32(struct Packer *, uint32_t) FUNC_RETURNS;
int		pack64(struct Packer *, uint64_t) FUNC_RETURNS;
void		packer_list_free(struct PackerList *);
struct Packer	*packer_list_get(struct PackerList *, unsigned) FUNC_RETURNS;
char		*unpack_strdup(struct Packer *) FUNC_RETURNS;
int		unpack8(struct Packer *, uint8_t *) FUNC_RETURNS;
int		unpack16(struct Packer *, uint16_t *) FUNC_RETURNS;
int		unpack32(struct Packer *, uint32_t *) FUNC_RETURNS;
int		unpack64(struct Packer *, uint64_t *) FUNC_RETURNS;

#endif
