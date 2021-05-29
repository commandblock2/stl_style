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

#ifndef CONTAINER_VT
#define CONTAINER_VT

#include "../../concepts/other/EqualityComparable_VT.h"
#include "../../type/typedefs.h"

struct Container_VT;
typedef struct Container_VT iContainer;

struct Container_VT
{
    
    // TODO: i don't know
    void (*destroy) (void *data);
    
    // TODO: decide wether to use iterator with interface
    generic_iterator (*begin) (void *data);
    generic_iterator (*end) (void *data);
    
    iEqualityComparable equality_comparable;
    
    // TODO: consider swap()
    
    size_t (*size) (void *data);
    size_t (*max_size) (void *data);
    
    bool (*empty) (void *data);
};

#endif
