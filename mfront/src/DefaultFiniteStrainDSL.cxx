/*!
 * \file   mfront/src/DefaultFiniteStrainDSL.cxx
 * \brief
 * \author Thomas Helfer
 * \date   08 nov 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#include <string>
#include <fstream>
#include <stdexcept>

#include "MFront/AbstractBehaviourInterface.hxx"
#include "MFront/BehaviourInterfaceFactory.hxx"
#include "MFront/DefaultFiniteStrainDSL.hxx"

namespace mfront {

  DefaultFiniteStrainDSL::DefaultFiniteStrainDSL(const DSLOptions& opts)
      : DefaultDSLBase(opts) {
    this->mb.setDSLName("DefaultFiniteStrain");
    this->mb.declareAsAFiniteStrainStandardBehaviour(false);
  }

  std::string DefaultFiniteStrainDSL::getDescription() {
    return "this parser is the most generic one as it does not make any "
           "restriction "
           "on the behaviour or the integration method that may be used";
  }  // end of DefaultFiniteStrainDSL::getDescription

  std::string DefaultFiniteStrainDSL::getName() {
    return "DefaultFiniteStrainDSL";
  }

  void DefaultFiniteStrainDSL::writeBehaviourParserSpecificIncludes(
      std::ostream& os) const {
    DefaultDSLBase::writeBehaviourParserSpecificIncludes(os);
    os << "#include\"TFEL/Math/tensor.hxx\"\n";
  }  // end of DefaultFiniteStrainDSL::writeBehaviourParserSpecificIncludes

  BehaviourDSLDescription DefaultFiniteStrainDSL::getBehaviourDSLDescription()
      const {
    auto d = mfront::getDefaultFiniteStrainBehaviourDSLDescription();
    d.integrationScheme = IntegrationScheme::USERDEFINEDSCHEME;
    d.typicalCodeBlocks = {BehaviourData::ComputePredictionOperator,
                           BehaviourData::Integrator,
                           BehaviourData::ComputeTangentOperator};
    d.minimalMFrontFileBody = "@Integrator{}\n\n";
    return d;
  }  // end of DefaultFiniteStrainDSL::getBehaviourDSLDescription

  DefaultFiniteStrainDSL::~DefaultFiniteStrainDSL() = default;

}  // end of namespace mfront
