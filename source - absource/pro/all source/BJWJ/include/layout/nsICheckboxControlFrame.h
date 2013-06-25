/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef nsICheckControlFrame_h___
#define nsICheckControlFrame_h___

#include "nsISupports.h"
class nsPresContext;

// 1e616b1d-e2c0-4456-bbec-399f72f7e9ad
#define NS_ICHECKBOXCONTROLFRAME_IID \
{ 0x1e616b1d, 0xe2c0, 0x4456,        \
  { 0xbb, 0xec, 0x39, 0x9f, 0x72, 0xf7, 0xe9, 0xad } }

/** 
  * nsICheckboxControlFrame: additional interfaces exposed by
  * a check-box control.
  * @see nsFormControlFrame and its base classes for more info
  */
class nsICheckboxControlFrame : public nsISupports {

public:
  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHECKBOXCONTROLFRAME_IID)

  /**
   * Called by content when checkbox "checked" changes
   */
  NS_IMETHOD OnChecked(nsPresContext* aPresContext, PRBool aChecked) = 0;
};

NS_DEFINE_STATIC_IID_ACCESSOR(nsICheckboxControlFrame,
                              NS_ICHECKBOXCONTROLFRAME_IID)

#endif

