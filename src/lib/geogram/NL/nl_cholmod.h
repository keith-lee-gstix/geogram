/*
 *  Copyright (c) 2004-2010, Bruno Levy
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *  * Neither the name of the ALICE Project-Team nor the names of its
 *  contributors may be used to endorse or promote products derived from this
 *  software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *  If you modify this software, you should include a notice giving the
 *  name of the person performing the modification, the date of modification,
 *  and the reason for such modification.
 *
 *  Contact: Bruno Levy
 *
 *     levy@loria.fr
 *
 *     ALICE Project
 *     LORIA, INRIA Lorraine, 
 *     Campus Scientifique, BP 239
 *     54506 VANDOEUVRE LES NANCY CEDEX 
 *     FRANCE
 *
 */

#ifndef OPENNL_CHOLMOD_H
#define OPENNL_CHOLMOD_H

#include "nl_private.h"
#include "nl_matrix.h"

/**
 * \file geogram/NL/nl_cholmod.h
 * \brief Internal OpenNL functions that interfaces Cholmod.
 */

/**
 * \brief Solves the system in the current OpenNL 
 *   context using CHOLMOD.
 * \details This function should not be called directly by client code.
 *  To use CHOLMOD, first call nlInitExtension("CHOLMOD")
 *  then specify:
 *   - nlSolverParameteri(NL_SOLVER, NL_CHOLMOD_EXT) 
 * \retval NL_TRUE if solve was successful
 * \retval NL_FALSE otherwise
 */
NLAPI NLboolean NLAPIENTRY nlSolve_CHOLMOD(void);

/**
 * \brief Solves a linear system using Cholmod.
 * \details This function should not be called directly by client code.
 *  The CHOLMOD extension needs to be initialized, by first calling
 *   nlInitExtension("CHOLMOD")
 * \param[in] M the sparse matrix of the system. It needs to be square. 
 *  It will be compressed (transformed into CRS storage) if not already 
 *  compressed.
 * \param[out] x the solution of the system
 * \param[in] b the right-hand side of the system
 * \param[in] solver one of:
 *   - NL_CHOLMOD_EXT 
 * \param[in] clear_M NL_TRUE if M should be destroyed right before
 *   calling CHOLMOD (to leave more RAM to it), NL_FALSE to keep M
 *   unchanged.
 * \retval NL_TRUE if solve was successful
 * \retval NL_FALSE otherwise
 */                        
NLAPI NLboolean NLAPIENTRY nlSolve_system_with_CHOLMOD(
    NLSparseMatrix* M, double* x, const double* b, NLenum solver,
    NLboolean clear_M
);

/**
 * \brief Initializes the CHOLMOD extension
 * \details This dynamically loads the Cholmod 
 *  library available in the system (if available) and
 *  retreives the symbols in there. It supports Cholmod 3.x
 *  and Cholmod 4.x. 
 * \retval NL_TRUE if CHOLMOD could be successfully
 *   dynamically loaded and all functions could be
 *   found in it.
 * \retval NL_FALSE otherwise.
 * \note For now, only implemented under Linux in 
 *  dynamic libraries mode
 */
NLboolean nlInitExtension_CHOLMOD(void);


#endif