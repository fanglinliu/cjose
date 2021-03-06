/*
 * Copyrights
 *
 * Portions created or assigned to Cisco Systems, Inc. are
 * Copyright (c) 2014-2016 Cisco Systems, Inc.  All Rights Reserved.
 */

/**
 * \file  util.h
 * \brief Utility functions and data structures for CJOSE.
 *
 */

#ifndef CJOSE_UTIL_H
#define CJOSE_UTIL_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * Typedef for memory allocator function.
 */
typedef void *(* cjose_alloc_fn_t)(size_t);

/**
 * Typedef for memory reallocator function.
 */
typedef void *(* cjose_realloc_fn_t)(void *, size_t);

/**
 * Typedef for memory deallocator function.
 */
typedef void (* cjose_dealloc_fn_t)(void *);

/**
 * Sets the allocator and deallocator functions.
 *
 * If <tt>alloc</tt> is NULL, any previously set allocator function is clared
 * and the the default allocator <tt>malloc()</tt>
 * is used.
 *
 * If <tt>dealloc</tt> is NULL, the default dallocator <tt>free()</tt>
 * is used.
 *
 * \param alloc [in] The custom allocator function to use.
 * \param realloc [in] The custom reallocator function to use.
 * \param dealloc [in] The custom deallocator function to use.
 */
void cjose_set_alloc_funcs(cjose_alloc_fn_t alloc,
                           cjose_realloc_fn_t realloc,
                           cjose_dealloc_fn_t dealloc);


/**
 * Retrieves the configured allocator function.  If an allocator function is
 * not set, this function returns a pointer to <tt>malloc()</tt>.
 *
 * \returns The configured allocator function
 */
cjose_alloc_fn_t cjose_get_alloc();

/**
 * Retrieve the configured reallocator function. If a reallocator function is
 * not set, this function retursn a pointer to <tt>realloc</tt>.
 *
 * \returns The configured reallocator function
 */
cjose_realloc_fn_t cjose_get_realloc();

/**
 * Retrieves the configured deallocator function.  If a deallocator function is
 * not set, this function returns a pointer to <tt>free()</tt>.
 *
 * \returns The configured deallocator function
 */
cjose_dealloc_fn_t cjose_get_dealloc();

#ifdef __cplusplus
}
#endif

#endif  // CJOSE_UTIL_H
