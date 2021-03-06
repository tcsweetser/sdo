/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 *   
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/* $Rev: 241789 $ $Date: 2007-08-25 00:50:26 +0930 (Sat, 25 Aug 2007) $ */

#ifndef _SDO_DASValue_H_
#define _SDO_DASValue_H_


#include "commonj/sdo/export.h"
#include "commonj/sdo/SDOString.h"
#include "string"


namespace commonj
{
    namespace sdo
    {
        
/** 
 * DASValue is a class to hold information required by data 
 * access services but not required by the data factory.
 */        
        class DASValue
        {
        public:
            SDO_API DASValue();
            SDO_API DASValue(const char* value);
            SDO_API DASValue(const SDOString& value);
            SDO_API virtual ~DASValue();
            SDO_API const char* getValue() const;

        private:
          SDOString value;
        
        };
        
    }
}
#endif //_SDO_DASValue_H_
