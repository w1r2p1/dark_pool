// Copyright (c) 2001-2010 quickfixengine.org  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in
//    the documentation and/or other materials provided with the
//    distribution.
//
// 3. The end-user documentation included with the redistribution,
//    if any, must include the following acknowledgment:
//      "This product includes software developed by
//       quickfixengine.org (http://www.quickfixengine.org/)."
//   Alternately, this acknowledgment may appear in the software itself,
//   if and wherever such third-party acknowledgments normally appear.
//
// 4. The names "QuickFIX" and "quickfixengine.org" must
//    not be used to endorse or promote products derived from this
//    software without prior written permission. For written
//    permission, please contact ask@quickfixengine.org
//
// 5. Products derived from this software may not be called "QuickFIX",
//    nor may "QuickFIX" appear in their name, without prior written
//    permission of quickfixengine.org
//
// THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.  IN NO EVENT SHALL QUICKFIXENGINE.ORG OR
// ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#ifndef FIX50SP2_BUSINESSMESSAGEREJECT_H
#define FIX50SP2_BUSINESSMESSAGEREJECT_H

#include "Message.h"

namespace FIX50SP2
{

  class BusinessMessageReject : public Message
  {
  public:
    BusinessMessageReject() : Message(MsgType()) {}
    BusinessMessageReject(const FIX::Message& m) : Message(m) {}
    BusinessMessageReject(const Message& m) : Message(m) {}
    BusinessMessageReject(const BusinessMessageReject& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("j"); }

    BusinessMessageReject(
      const FIX::RefMsgType& aRefMsgType,
      const FIX::BusinessRejectReason& aBusinessRejectReason )
    : Message(MsgType())
    {
      set(aRefMsgType);
      set(aBusinessRejectReason);
    }

    FIELD_SET(*this, FIX::RefSeqNum);
    FIELD_SET(*this, FIX::RefMsgType);
    FIELD_SET(*this, FIX::BusinessRejectRefID);
    FIELD_SET(*this, FIX::BusinessRejectReason);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
    FIELD_SET(*this, FIX::RefApplVerID);
    FIELD_SET(*this, FIX::RefApplExtID);
    FIELD_SET(*this, FIX::RefCstmApplVerID);
  };

}

#endif