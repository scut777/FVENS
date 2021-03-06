/** \file
 * \brief Tests for gradient schemes
 * \author Aditya Kashi
 */

#ifndef FVENS_TESTS_GRADIENTS_H
#define FVENS_TESTS_GRADIENTS_H

#include <string>
#include "spatial/aspatial.hpp"

namespace fvens_tests {

using fvens::a_real;

/// A 'spatial discretization' that does nothing but carry out tests on gradient schemes etc
class TestSpatial : public fvens::Spatial<a_real,1>
{
public:
	TestSpatial(const fvens::UMesh2dh<a_real> *const mesh);

	virtual fvens::StatusCode assemble_residual(const Vec u, Vec residual, 
	                                     const bool gettimesteps, std::vector<a_real>& dtm) const
	{ return 0; }

	virtual fvens::StatusCode compute_jacobian(const Vec u, Mat A) const
	{ return 0; }

	virtual void getGradients(const fvens::MVector<a_real>& u,
	                          fvens::GradArray<a_real,1>& grads) const
	{ }

	virtual fvens::StatusCode initializeUnknowns(Vec u) const { return 0; }

	/// Test if weighted least-squares reconstruction is '1-exact'
	int test_oneExact(const std::string reconst_type) const;

protected:
	using fvens::Spatial<a_real,1>::m;
	using fvens::Spatial<a_real,1>::rc;
	using fvens::Spatial<a_real,1>::gr;
};

}
#endif
