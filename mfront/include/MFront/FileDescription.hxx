/*!
 * \file  mfront/include/MFront/FileDescription.hxx
 * \brief
 * \author Thomas Helfer
 * \brief 14 jun 2010
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONT_MFRONTFILEDESCRIPTION_HXX
#define LIB_MFRONT_MFRONTFILEDESCRIPTION_HXX

#include <string>
#include "MFront/MFrontConfig.hxx"

namespace mfront {

  /*!
   * \brief this class gathers some information about the MFront file being
   * treated
   */
  struct MFRONT_VISIBILITY_EXPORT FileDescription {
    //! \brief default constructor
    FileDescription();
    //! \brief move constructor
    FileDescription(FileDescription&&);
    //! \brief copy constructor
    FileDescription(const FileDescription&);
    //! \brief move assignement
    FileDescription& operator=(FileDescription&&);
    //! \brief standard assignement
    FileDescription& operator=(const FileDescription&);
    //! \brief destructor
    ~FileDescription();
    //! \brief name of the `MFront` file
    std::string fileName;
    //! \brief author of the `MFront` file
    std::string authorName;
    //! \brief date at which the `MFront` file has been written
    std::string date;
    //! \brief description of the `MFront` file
    std::string description;
  };  // end of struct FileDescription

  //! typedef provided for backward compatibility
  using GenericData = FileDescription;

}  // end of namespace mfront

#endif /* LIB_MFRONT_MFRONTFILEDESCRIPTION_HXX */
