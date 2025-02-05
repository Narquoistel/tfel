/*!
 * \file   InitNumpy.cxx
 * \brief
 * \author Thomas Helfer
 * \date   23/03/2020
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#include <numpy/ndarrayobject.h>
#include <boost/python/numpy.hpp>
#include "TFEL/Numpy/InitNumpy.hxx"

#if PY_MAJOR_VERSION == 2
static void wrapInitializeNumPy() { import_array(); }
#else
static void* wrapInitializeNumPy() {
  import_array();
  return nullptr;
}
#endif

namespace tfel::numpy {

  void initializeNumPy() {
    Py_Initialize();
    boost::python::numpy::initialize();
    ::wrapInitializeNumPy();
  }  // end of initializeNumPy

}  // end of namespace tfel::numpy
