/*!
 * \file   tests/MetaProgramming/HasConstIterator.cxx
 * \brief
 * \author Thomas Helfer
 * \date   19 oct 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#include <cstdlib>
#include <vector>
#include <type_traits>
#include "TFEL/Metaprogramming/HasConstIterator.hxx"

/* coverity [UNCAUGHT_EXCEPT]*/
int main() {
  static_assert(tfel::meta::HasConstIterator<std::vector<double>>::value,
                "HasConstIterator failed");
  return EXIT_SUCCESS;
}
