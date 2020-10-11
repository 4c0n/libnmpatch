/*
    Nord Modular patch file format 3.03 parser
    Copyright (C) 2002 Marcus Andersson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef MODULESECTION_H
#define MODULESECTION_H

#include <list>

#include "nmpatch/module.h"
#include "nmpatch/cable.h"

namespace ppf {
  class Parser;
  class BoundBundle;
}

using namespace std;

class ModuleSectionListener;

class ModuleSection
{
 public:
  
  enum Type {
    COMMON = 0,
    POLY,
    MORPH
  };

  enum VoiceRetrigger {
    INACTIVE = 0,
    ACTIVE
  };

  typedef list<Module*> ModuleList;
  typedef list<Cable*> CableList;

  static void usePPFFile(string filename);

  ModuleSection();
  
  virtual ~ModuleSection();

  void setVoiceRetrigger(VoiceRetrigger);
  VoiceRetrigger getVoiceRetrigger();

  Module* newModule(ModuleType::TypeId, int = 0);
  ModuleList getModules() const;
  Module* getModule(int);
  void removeModule(Module*);
  
  Cable* newCable(Cable::Color,
		  int, ModuleType::Port, ModuleType::ConnectorType,
		  int, ModuleType::Port, ModuleType::ConnectorType);
  CableList getCables() const;
  void removeCable(Cable*);
  
  void addListener(ModuleSectionListener*);
  void removeListener(ModuleSectionListener*);

  void notifyListeners(Module*, int);

 private:
  
  typedef list<ModuleSectionListener*> ModuleSectionListenerList;

  static string ppfFile;
  static ppf::Parser* parser;
  static ppf::BoundBundle* moduleProperties;

  VoiceRetrigger voiceRetrigger;
  ModuleList modules;
  CableList cables;
  int nextIndex;
  ModuleSectionListenerList listeners;
};

#endif
