/*!
 * \file  mfront/include/MFront/Castem/CastemInterfaceExceptions.hxx
 * \brief
 * \author Thomas Helfer
 * \brief 30 janv. 2013
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONT_CASTEM_CASTEMINTERFACEEXCEPTIONS_HXX
#define LIB_MFRONT_CASTEM_CASTEMINTERFACEEXCEPTIONS_HXX

#include <string>

#include "TFEL/Exception/TFELException.hxx"
#include "TFEL/Material/MaterialException.hxx"

#include "MFront/Castem/Castem.hxx"
#include "MFront/Castem/CastemTraits.hxx"
#include "MFront/Castem/CastemConfig.hxx"
#include "MFront/Castem/CastemException.hxx"

namespace castem {

  /*!
   * This structure is called when we fall in a case that the castem
   * interface is not able to handle. Normally, this case shall have
   * been handled during the code generation (see the
   * CastemInterface class).
   */
  struct MFRONT_CASTEM_VISIBILITY_EXPORT CastemUnSupportedCaseHandler {
    /*!
     * \brief throw an exception
     */
    [[noreturn]] static void exe(const CastemReal *const,
                                 const CastemReal *const,
                                 CastemReal *const,
                                 const CastemReal *const,
                                 const CastemReal *const,
                                 const CastemReal *const,
                                 const CastemReal *const,
                                 const CastemReal *const,
                                 const CastemInt *const,
                                 const CastemReal *const,
                                 const CastemReal *const,
                                 CastemReal *const,
                                 const CastemInt *const,
                                 CastemReal *const,
                                 const StressFreeExpansionHandler &);
  };  // end of struct CastemUnSupportedCaseHandler

  /*!
   * \class  CastemInterfaceExceptions
   * \brief  Base class for castem interfaces
   * \author Thomas Helfer
   * \date   12/12/2011
   */
  struct MFRONT_CASTEM_VISIBILITY_EXPORT CastemInterfaceExceptions {
    /*!
     * \brief throw an CastemException. This method shall be called when
     * the number of materials properties declared by the beahviour and the
     * number of  materials properties declared by the interface does not
     * match.
     * \param[in] b  : behaviour name
     * \param[in] n1 : number of material properties declared by the behaviour
     * \param[in] n2 : number of material properties declared by the interface
     */
    [[noreturn]] static void throwUnMatchedNumberOfMaterialProperties(
        const std::string &, const unsigned short n1, const CastemInt n2);

    /*!
     * \brief throw an CastemException. This method shall be called when
     * the number of state variables declared by the beahviour and the
     * number of state variables declared by the interface does not
     * match.
     * \param[in] b  : behaviour name
     * \param[in] n1 : number of state variables declared by the behaviour
     * \param[in] n2 : number of state variables declared by the interface
     */
    [[noreturn]] static void throwUnMatchedNumberOfStateVariables(
        const std::string &, const unsigned short n1, const CastemInt n2);

    /*!
     * \brief display the error message out of an CastemException to the
     * standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the CastemException to be treated
     */
    static void treatCastemException(const std::string &,
                                     const CastemException &);

    /*!
     * \brief display the error message out of a material exception to the
     * standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the material exception to be treated
     */
    static void treatMaterialException(
        const std::string &, const tfel::material::MaterialException &);

    /*!
     * \brief display the error message out of a generic tfel
     * exception to the standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the exception to be treated
     */
    static void treatTFELException(const std::string &,
                                   const tfel::exception::TFELException &);

    /*!
     * \brief display the error message out of a generic standard
     * exception to the standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the exception to be treated
     */
    static void treatStandardException(const std::string &,
                                       const std::exception &);

    /*!
     * \brief display the error message when an unknown exception is caught
     * \param[in] b : behaviour name
     */
    static void treatUnknownException(const std::string &);

    /*!
     * \brief throw an CastemException if the time step is negative
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwNegativeTimeStepException(
        const std::string &);

    /*!
     * \brief throw an CastemException if the behaviour integration
     * failed
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwBehaviourIntegrationFailedException(
        const std::string &);

    /*!
     * \brief throw an CastemException if the maximum number of sub
     * stepping has been reached
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwMaximumNumberOfSubSteppingReachedException(
        const std::string &);

    /*!
     * \brief throw an CastemException if the maximum number of sub
     * stepping has been reached
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void
    throwPlaneStressMaximumNumberOfIterationsReachedException(
        const std::string &);
    /*!
     * \brief throw an CastemException if the DDSDDE parameter is invalid
     * \param[in] b : behaviour name
     * \param[in] v : DDSDDE value
     */
    [[noreturn]] static void throwInvalidDDSDDEException(const std::string &,
                                                         const CastemReal);
    /*!
     * \brief throw an CastemException when a tanget operator is
     * requested in the generic plane stress handler
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void
    throwTangentOperatorNotAvailableThroughGenericPlaneStressHandler(
        const std::string &);
    /*!
     * \brief throw an AsterException if the prediction computation
     * failed
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwPredictionComputationFailedException(
        const std::string &);
    /*!
     * \brief throw an AsterException if the a consistent tangent
     * operator has to been requested and that the behaviour does not
     * provide one.
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwConsistentTangentOperatorIsNotAvalaible(
        const std::string &);
    /*!
     * \brief throw an AsterException if the a prediction operator has
     * to been requested and that the behaviour does not provide one.
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwPredictionOperatorIsNotAvalaible(
        const std::string &);
    /*!
     * \brief throw an error message if the value of the NTENS
     * parameter is not valid
     * \param[in] NTENS : NTENS value
     * \param[in] s     : expected size
     */
    static void checkNTENSValue(const CastemInt, const unsigned short);
    /*!
     * \brief throw an error message if the behaviour type is not supported for
     * the given hypothesis \param[in] type : behaviour type \param[in] H    :
     * hypothesis
     */
    [[noreturn]] static void throwInvalidBehaviourTypeAndModellingHypothesis(
        const CastemBehaviourType, const std::string &);
    /*!
     * \brief display an error message if the behaviour shall handle
     * stress free expansion and that the castem interface can't
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwUnsupportedStressFreeExpansionException(
        const std::string &);
    /*!
     * \brief display an error message if the thermal expansion is not
     * null
     * \param[in] b : behaviour name
     */
    [[noreturn]] static void throwThermalExpansionCoefficientShallBeNull(
        const std::string &);
    /*!
     * \brief display an error message if the value of the NDI
     * parameter is not valid
     */
    static void displayInvalidModellingHypothesisErrorMessage();

  };  // end of struct CastemInterfaceExceptions

}  // end of namespace castem

#endif /* LIB_MFRONT_CASTEM_CASTEMINTERFACEEXCEPTIONS_HXX */
