#ifndef GET_D_COEFFS_H
#define GET_D_COEFFS_H
#include <petscksp.h>

namespace PSE
{
    /** 
     * 
     * \brief Solve arbitrary stencil points s of length N with order of derivatives d<N
     * can be obtained from equation on MIT website
     * http://web.media.mit.edu/~crtaylor/calculator.html
     * where the accuracy is determined as the usual form O(h^(N-d))
     * 
     * ierr from Ax=b solver
     */
    PetscInt get_D_Coeffs(
            const PetscScalar s[],  ///< [in] array of stencil points e.g. [-3,-2,-1,0,1]
            const PetscInt &n,      ///< [in] size of stencil
            Vec &output,            ///< [out] output of coefficient values for the given stencil (uninitialized)
            const PetscInt &d=2     ///< [in] order of desired derivative (default=2)
            );
}
#endif
