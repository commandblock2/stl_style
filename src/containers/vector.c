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

#include "vector.h"

#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

vector *create_vector(size_t const elem_size)
{
    vector *new_vector = malloc(sizeof(vector));
    
    new_vector->__element_size = elem_size;
    new_vector->__element_count = 0;
    new_vector->__allocated_size = VECTOR_DEFAULT_SIZE;
    
    new_vector->__memory = malloc(elem_size * new_vector -> __element_count);
    
    new_vector->vtable = &__Default_vector_impl;
    
    return new_vector;
}

void destroy_vector(void* this_)
{
    vector *this = (vector*)this_;
    
    free(this->__memory);
    free(this_);
}

generic_iterator __vector_begin(void* this_)
{
    vector *this = (vector*)this_;
    return this->__memory;
}

generic_iterator __vector_end(void* this_)
{
    vector *this = (vector*)this_;
    return this->__memory + this->__element_count * this->__element_size;
}

size_t __vector_size(void* this_)
{
    vector *this = (vector*)this_;
    return this->__element_count;
}

size_t __vector_max_size(void* this_)
{
    // TODO: implement this by using free ram
    return INT_MAX;
}

generic_reference __vector_at(void* this_, size_t position)
{
    vector *this = (vector*)this_;
    
    // This implementation is UB since it would be problematic to use like this
    /*return this->__memory + position * this->__element_count;*/
    
    // Since uint 8 is the atomic unit (1 byte) then 
    // let's use that area as a u8*
    
    // TODO: decide if need bound checking
    // if (position > this->__element_count) return nullptr;
    
    uint8_t *memory = this->__memory;
    return memory + (this->__element_size * position);
}

generic_iterator __vector_iterator_next(generic_iterator this_, arbitrary_type_ptr closure)
{
    vector *v = closure;
    
    return (uint8_t *)this_ + v->__element_size;
}

generic_iterator __vector_iterator_prev(generic_iterator this_, arbitrary_type_ptr closure)
{
    vector *v = closure;
    
    return (uint8_t *)this_ - v->__element_size;
}

bool __vector_iterator_less_than(arbitrary_type_ptr lhs, arbitrary_type_ptr rhs)
{
    return (size_t)lhs < (size_t)rhs;
}

void no_check_shift_element_by(vector *this, generic_iterator begin, generic_iterator end, ptrdiff_t offset)
{
    // check if has overlap
    if ((uint8_t*) begin + offset > (uint8_t*)end)
        memcpy(begin + offset, begin, end - begin);
    else
    {
        void *temporary_mem = malloc(end - begin);
        
        memcpy(temporary_mem, begin, end - begin);
        memcpy(begin + offset, temporary_mem, end - begin);
        
        free(temporary_mem);
    }
}


