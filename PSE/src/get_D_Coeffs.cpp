#include "get_D_Coeffs.hpp"
#include "Ax_b.hpp"
#include "factorial.hpp"
#include <cmath>
#include "print.hpp"

namespace PSE
{
    PetscInt get_D_Coeffs(
            PetscScalar s[],
            PetscInt n,
            Vec &output,
            PetscInt d 
            ){
        PetscErrorCode ierr;
        // create A dynamic 2d array of correct square shape
        PetscScalar **A=new PetscScalar*[n];
        for (int i=0; i<n; i++) A[i]=new PetscScalar[n];
        // create b dynamic 1d matrix
        PetscScalar *b=new PetscScalar[n];

        // set A matrix
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                A[i][j] = std::pow(s[j],i);
            }
        }
        // set b vector
        for (int i=0; i<n; i++) b[i]=0.;
        b[d]=factorial(d);

        // solve Ax=b problem in parallel using PSE::Ax_b
        ierr = Ax_b(A,output,b,n); CHKERRQ(ierr);
        printVec(output,n);
        



        // delete A and b matrix
        for (int i=0; i<n; i++) delete[] A[i];
        delete[] A;
        delete[] b;

        return 0;
    }
}
