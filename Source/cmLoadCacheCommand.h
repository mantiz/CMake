/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmLoadCacheCommand_h
#define cmLoadCacheCommand_h

/** \class cmLoadCacheCommand
 * \brief load a cache file
 *
 * cmLoadCacheCommand loads the non internal values of a cache file
 */
class cmLoadCacheCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone() 
    {
    return new cmLoadCacheCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * This determines if the command gets propagated down
   * to makefiles located in subdirectories.
   */
  virtual bool IsInherited() {return true;}

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "LOAD_CACHE";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "load in the values from another cache.";
    }
  
  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "LOAD_CACHE(pathToCacheFile [EXCLUDE entry1...] [INCLUDE_INTERNALS entry1...])\n"
      "LOAD_CACHE(pathToCacheFile READ_WITH_PREFIX prefix entry1...)\n"
      "Load in the values from another cache. This is useful for a project "
      "that depends on another project built in a different tree."
      "EXCLUDE option can be used to provide a list of entries to be excluded."
      "INCLUDE_INTERNALS can be used to provide a list of internal entries"
      "to be included. Normally, no internal entries are brougt in.\n"
      "The READ_WITH_PREFIX form will read the cache and store the requested "
      "entries in variables with their name prefixed with the given prefix.  "
      "This form only reads the values, and does not create local cache entries.";
    }
  
  cmTypeMacro(cmLoadCacheCommand, cmCommand);
protected:
  
  std::set<cmStdString> VariablesToRead;
  std::string Prefix;
  
  bool ReadWithPrefix(std::vector<std::string> const& args);
  void CheckLine(const char* line);
  bool ParseEntry(const char* entry, std::string& var, std::string& value);
};


#endif
