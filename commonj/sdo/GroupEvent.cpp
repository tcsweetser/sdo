/*
 *
 *  Copyright 2005 The Apache Software Foundation or its licensors, as applicable.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/* $Rev: 395593 $ $Date$ */

#include "commonj/sdo/GroupEvent.h"
namespace commonj
{
    namespace sdo
    {
        GroupEvent::GroupEvent()
        {
        }
        
        GroupEvent::GroupEvent(
                const SDOXMLString& inlocalname,
                const SDOXMLString& inprefix,
                const SDOXMLString& inURI,
                const SAX2Namespaces& innamespaces,
                const SAX2Attributes& inattributes
            )
        {
            localname = inlocalname;
            prefix = inprefix;
            URI = inURI;
            namespaces = innamespaces;
            attributes = inattributes;
            isStartEvent = true;
        }

        GroupEvent::GroupEvent(
                const SDOXMLString& inlocalname,
                const SDOXMLString& inprefix,
                const SDOXMLString& inURI
            )
        {
            localname = inlocalname;
            prefix = inprefix;
            URI = inURI;
            isStartEvent = false;
        }

        GroupEvent::~GroupEvent()
        {
        }
        
    } // End - namespace sdo
} // End - namespace commonj
