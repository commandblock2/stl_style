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

#ifndef VECTOR
#define VECTOR

#include "../type/typedefs.h"
#include "../concepts/containers/SequenceContainer_VT.h"
#include "../concepts/iterators/RandomAccessIterator_VT.h"

#define VECTOR_DEFAULT_SIZE 32;

struct _Vector;
typedef struct _Vector vector;

struct _Vector_VT;
typedef struct _Vector_VT ivector;

struct _Vector
{
    size_t __element_size;
    size_t __element_count;
    size_t __allocated_size;
    
    void *__memory;
    
    ivector *vtable;
};

vector *create_vector(size_t const elem_size);
void destroy_vector(void *this_);

generic_iterator __vector_begin(void *this_);
generic_iterator __vector_end(void *this_);

size_t __vector_size(void *this_);
size_t __vector_max_size(void *this_);

bool __vector_empty(void *this_);

static iContainer __Default_vector_container_impl = 
{
    .begin = __vector_begin,
    .end = __vector_end,
    
    .size = __vector_size,
    .max_size = __vector_max_size,
    
    .empty = __vector_empty
};

generic_iterator __vector_insert(void *this_, generic_iterator position_it, void *element);
generic_iterator __vector_insert_n_copies(void *this_, generic_iterator position_it, size_t copies, void *element);
generic_iterator __vector_insert_iter_range(void *this_, generic_iterator position_it, generic_iterator begin, generic_iterator end, iForwardIterator *iterator_vt);

generic_iterator __vector_erase(void *this_, generic_iterator position_it, iForwardIterator *iterator_vt);
generic_iterator __vector_erase_iter_range(void *this_, generic_iterator begin, generic_iterator end, iForwardIterator *iterator_vt);

void __vector_clear(void *this_);
void __vector_assign(void *this_, generic_iterator begin, generic_iterator end, iForwardIterator *iterator_vt);
void __vector_assign_n_copies(void *this_, size_t copies, void *element);
    

generic_iterator __vector_front(void *this_);
generic_iterator __vector_back(void *this_);
    
void  __vector_push_back(void *this_, void *element);
    ;
void  __vector_pop_back(void *this_);

generic_reference __vector_at(void *this_, size_t position);

static iSequenceContainer __Default_vector_sequence_container_impl = 
{
    .insert = __vector_insert,
    .insert_n_copies = __vector_insert_n_copies,
    .insert_iter_range = __vector_insert_iter_range,
    
    .erase = __vector_erase,
    .erase_iter_range = __vector_erase_iter_range,
    
    .clear = __vector_clear,
    
    .assign = __vector_assign,
    .assign_n_copies = __vector_assign_n_copies,
    
    .front = __vector_front,
    .back = __vector_back,
    
    .push_back = __vector_push_back,
    .push_front = nullptr, // no implementation
    
    .pop_back = __vector_pop_back,
    .pop_front = nullptr, // no implementation
    
    .reference_at = __vector_at,
    
    .container = &__Default_vector_container_impl
};

generic_iterator __vector_iterator_next(generic_iterator this_, arbitrary_type_ptr closure);
generic_iterator __vector_iterator_prev(generic_iterator this_, arbitrary_type_ptr closure);

bool __vector_iterator_less_than(arbitrary_type_ptr lhs, arbitrary_type_ptr rhs);

static iLessThanComparable __Default_vector_iterator_less_than_impl = 
{
    .less_than = __vector_iterator_less_than
};

static iForwardIterator
__Default_vector_forward_iterator_impl =
{
    .next = __vector_iterator_next
};

static iBidirectionalIterator
__Default_vector_bidirectional_iterator_impl = 
{
    .prev = __vector_iterator_prev,
    .forward_iterator = &__Default_vector_forward_iterator_impl,
};

static iRandomAccessIterator __Default_vector_iterator_impl =
{
    .less_than_comparable = &__Default_vector_iterator_less_than_impl,
    .bidrectional_iterator = &__Default_vector_bidirectional_iterator_impl,
};

void __vector_shrink_to_fit(vector *this);

void __vector_reserve(vector *this, size_t size);
size_t __vector_capacity(vector *this);

struct _Vector_VT
{
    iSequenceContainer *sequence_container;
    void (*shrink_to_fit) (vector *this);
    
    void (*reserve) (vector *this, size_t new_size);
    size_t (*capacity) (vector *this);
    
    
    // since the iterators should be a int sized thing so
    // the vt is moved in here
    
    iRandomAccessIterator *iterator_vt;
}
static __Default_vector_impl = 
{
    .shrink_to_fit = __vector_shrink_to_fit,
    
    .reserve = __vector_reserve,
    .capacity = __vector_capacity,
    
    .iterator_vt = &__Default_vector_iterator_impl,
    .sequence_container = &__Default_vector_sequence_container_impl
};


#endif
