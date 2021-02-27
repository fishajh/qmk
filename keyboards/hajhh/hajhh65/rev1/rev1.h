/* Copyright 2020 zvecr <git@zvecr.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#define LAYOUT( \
                        KA01, KA02, KA03, KA04, KA05, KA06, KA07, KA08, KA09, KA10, KA11, KA12, KA13, KA14, KA15, KA16, \
	KB14 ,KD13,     KB01, KB02, KB03, KB04, KB05, KB06, KB07, KB08, KB09, KB10, KB11, KB12, KB13,       KB15, KB16, \
	KC13 ,KC14,     KC01, KC02, KC03, KC04, KC05, KC06, KC07, KC08, KC09, KC10, KC11, KC12,             KC15, KC16, \
	KE09 ,KE10,     KD01, KD02, KD03, KD04, KD05, KD06, KD07, KD08, KD09, KD10, KD11, KD12,       KD14, KD15, KD16, \
	KE04 ,KE05,     KE01, KE02, KE03,             KE06, KE07, KE08,             KE11, KE12, KE13, KE14, KE15, KE16  \
) { \
	{  KA01 , KA02 , KA03 , KA04 , KA05 , KA06 , KA07 , KA08 , KA09 , KA10 , KA11 , KA12 , KA13 , KA14 , KA15 , KA16 }, \
	{  KB01 , KB02 , KB03 , KB04 , KB05 , KB06 , KB07 , KB08 , KB09 , KB10 , KB11 , KB12 , KB13 , KB14 , KB15 , KB16 }, \
	{  KC01 , KC02 , KC03 , KC04 , KC05 , KC06 , KC07 , KC08 , KC09 , KC10 , KC11 , KC12 , KC13 , KC14 , KC15 , KC16 }, \
	{  KD01 , KD02 , KD03 , KD04 , KD05 , KD06 , KD07 , KD08 , KD09 , KD10 , KD11 , KD12 , KD13 , KD14 , KD15 , KD16 }, \
	{  KE01 , KE02 , KE03 , KE04 , KE05 , KE06 , KE07 , KE08 , KE09 , KE10 , KE11 , KE12 , KE13 , KE14 , KE15 , KE16 } \
	}
