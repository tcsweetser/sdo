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

#include "commonj/sdo/DataObjectInstance.h"
using commonj::sdo::CopyHelper;



namespace commonj
{
    namespace sdo
    {        
        // ============
        // Constructors
        // ============    
        DataObjectInstance::DataObjectInstance()
        {
        }

        DataObjectInstance::DataObjectInstance(const DataObjectPtr& theDO)
        {
            dataObject = CopyHelper::copy(theDO);
        }
        
        // ==========
        // Destructor
        // ==========
        DataObjectInstance::~DataObjectInstance()
        {
        }

        // ===================================
        // Copy constructor: deep copy the DO
        // ===================================
        DataObjectInstance::DataObjectInstance(const DataObjectInstance& doi)
        {
            dataObject = CopyHelper::copy(doi.dataObject);
        }
        
        // =============================
        // operator= : deep copy the DO
        // =============================
        DataObjectInstance& DataObjectInstance::operator=(const DataObjectInstance& doi)
        {
            if (this != &doi)
            {
                dataObject = CopyHelper::copy(doi.dataObject);
            }
            return *this;
        }

    } // End namespace sca
} // End namespace osoa
