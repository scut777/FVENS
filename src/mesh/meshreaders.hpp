/** \file
 * \brief Mesh readers
 *
 * This file is part of FVENS.
 *   FVENS is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   FVENS is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with FVENS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FVENS_MESHREADERS_H
#define FVENS_MESHREADERS_H

#include <string>
#include <vector>
#include "aconstants.hpp"
#include "utilities/aarray2d.hpp"

namespace fvens{

/// Data to be read from a file or trivially computed while reading the file
struct MeshData
{
	a_int npoin;                    ///< Number of nodes
	a_int nelem;                    ///< Number of elements
	a_int nface;                    ///< Number of boundary faces
	std::vector<int> nnode;         ///< number of nodes to an element, for each element
	int maxnnode;                   ///< Maximum number of nodes per element for any element
	std::vector<int> nfael;         ///< number of faces to an element for each element
	int maxnfael;                   ///< Maximum number of faces per element for any element
	int nnofa;                      ///< number of nodes in a face
	int nbtag;                      ///< number of tags for each boundary face
	int ndtag;                      ///< number of tags for each element

	/// Coordinates of nodes
	amat::Array2d<a_real> coords;

	/// Interconnectivity matrix: lists node numbers of nodes in each element
	amat::Array2d<a_int> inpoel;

	/// Physical boundary face data
	///  Lists nodes belonging to a boundary face and contains boundary markers
	amat::Array2d<a_int> bface;
};

/// Reads a mesh from a file
Meshdata readMesh(const std::string mfile);

}

#endif