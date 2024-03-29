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

#ifndef FORWARDITERATOR_VT
#define FORWARDITERATOR_VT

#include "../../type/typedefs.h"

typedef struct ForwardIterator_VT
{
    generic_iterator (*next) (generic_iterator this_, arbitrary_type_ptr closure);
    
} iForwardIterator;

#endif
