/* 
 * Copyright (c) 2007, 2010, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */
#ifndef _GUI_PLUGIN_BASE_H_
#define _GUI_PLUGIN_BASE_H_

#include "grt/grt_manager.h"

//! Base class with some utility stuff for gui plugins and others 
class WBPUBLICBACKEND_PUBLIC_FUNC GUIPluginBase
{
  grt::Module *_module;
  grt::GRT *_grt;

protected:
  bec::GRTManager *grtm() { return bec::GRTManager::get_instance_for(_grt); }
 
  boost::signals2::signal<void ()> _signal_closed;

public:
  GUIPluginBase(grt::Module *module);
  GUIPluginBase(grt::GRT *_grt);

  virtual ~GUIPluginBase();

  grt::Module *module() const { return _module; }
};


typedef GUIPluginBase* (*GUIPluginCreateFunction)(grt::Module *module, bec::GRTManager *grtm, grt::BaseListRef &args);

#endif /* _WB_PLUGIN_BASE_H_ */
