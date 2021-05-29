// SPDX-License-Identifier: AGPL-3.0-only
/*
 * This file is part of stl_style (https://github.com/commandblock2/stl_style)
 * 
 * stl_style is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. 
 * 
 * stl_style is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 */

#ifndef RANDOMACCESSITERATOR_VT
#define RANDOMACCESSITERATOR_VT

#include "../../concepts/other/LessThanComparable_VT.h"
#include "../../concepts/iterators/BidirectionalIterator_VT.h"

typedef struct RandomAccessIterator_VT
{
    
    iBidirectionalIterator *bidrectional_iterator;
    iLessThanComparable *less_than_comparable;
    
} iRandomAccessIterator;

#endif
