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

#ifndef SEQUENCECONTAINER_VT
#define SEQUENCECONTAINER_VT

#include <stddef.h>
#include "../../concepts/containers/Container_VT.h"
#include "../../concepts/iterators/ForwardIterator_VT.h"
#include "../../type/typedefs.h"

struct SequenceContainer_VT;
typedef struct SequenceContainer_VT iSequenceContainer;

struct SequenceContainer_VT
{
    iContainer *container; // First it should be a container
    
    generic_iterator (*insert) (void *data, generic_iterator position_it, void *element);
    generic_iterator (*insert_n_copies) (void *data, generic_iterator position_it, size_t copies, void *element);
    generic_iterator (*insert_iter_range) (void *data, generic_iterator position_it, generic_iterator begin, generic_iterator end, iForwardIterator *iterator_vt);
    
    generic_iterator (*erase) (void *data, generic_iterator position_it, iForwardIterator *iterator_vt);
    generic_iterator (*erase_iter_range) (void *data, generic_iterator begin, generic_iterator end, iForwardIterator *iterator_vt);
    
    void (*clear) (void *data);
    
    void (*assign) (void *data, generic_iterator begin, generic_iterator end, iForwardIterator *iterator_vt);
    void (*assign_n_copies) (void *data, size_t copies, void *element);
    
    
    generic_iterator (*front) (void *data);
    generic_iterator (*back) (void *data);
    
    void (*push_front) (void *data, void *element);
    void (*push_back) (void *data, void *element);
    
    void (*pop_front) (void *data);
    void (*pop_back) (void *data);
    
    generic_reference (*reference_at) (void *data, size_t position);
};

#endif
