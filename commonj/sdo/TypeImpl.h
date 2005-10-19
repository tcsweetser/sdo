/* 
+----------------------------------------------------------------------+
| (c) Copyright IBM Corporation 2005.                                  | 
| All Rights Reserved.                                                 |
+----------------------------------------------------------------------+ 
|                                                                      | 
| Licensed under the Apache License, Version 2.0 (the "License"); you  | 
| may not use this file except in compliance with the License. You may | 
| obtain a copy of the License at                                      | 
|  http://www.apache.org/licenses/LICENSE-2.0                          |
|                                                                      | 
| Unless required by applicable law or agreed to in writing, software  | 
| distributed under the License is distributed on an "AS IS" BASIS,    | 
| WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or      | 
| implied. See the License for the specific language governing         | 
| permissions and limitations under the License.                       | 
+----------------------------------------------------------------------+ 
| Author: Ed Slattery                                                  | 
+----------------------------------------------------------------------+ 

*/
/* $Id$ */

#ifndef _TYPEIMPL_H_
#define _TYPEIMPL_H_

#include <list>
#include <map>
#include <vector>
#include "commonj/sdo/DASType.h"
#include "commonj/sdo/PropertyImpl.h"
#include "commonj/sdo/SDODate.h"


#define MAX_LONG_SIZE 20 
#define MAX_FLOAT_SIZE 32
#define MAX_DOUBLE_SIZE 32
#define BOOL_SIZE 5
#define CHAR_SIZE 1
#define BYTE_SIZE 1

using namespace std;

namespace commonj{
namespace sdo{

class DataObject;
class PropertyList;
class MetadataGraph;

	///////////////////////////////////////////////////////////////////////////
    //A representation of the type of property} of a data object.
	///////////////////////////////////////////////////////////////////////////


#ifndef PROPERTY_LIST
	typedef std::list<PropertyImpl*> PROPERTY_LIST;
#endif


class TypeImpl : public DASType
{

public:

	
	 virtual ~TypeImpl();

	///////////////////////////////////////////////////////////////////////////
    // Converters for primitive types 
	///////////////////////////////////////////////////////////////////////////

	 
	 unsigned int convertDate(		void ** value, const SDODate i) const;
	 unsigned int convert(	void ** value,const char* s) const; 
	 unsigned int convert(	void ** value,const wchar_t* s, unsigned int len) const; 
	 unsigned int convert(	void ** value,const char* s, unsigned int len) const; 
	 unsigned int convert(			void ** value,const bool b) const; 
	 unsigned int convert(			void ** value,const char c) const; 
	 unsigned int convert(			void ** value,const wchar_t c) const; 
	 unsigned int convert(			void ** value,const short s) const; 
	 unsigned int convert(			void ** value,const long i) const; 
	 unsigned int convert(			void ** value,const int64_t l) const; 
	 unsigned int convert(			void ** value,const float f) const; 
	 unsigned int convert(			void ** value,const long double d) const; 
	 unsigned int convert(			void ** value,DataObject* dob) const; 

	 const char*          convertToCString(    void* value , char** inbuf, unsigned int len) const; 
	 const bool           convertToBoolean(   void* value, unsigned int len) const; 
	 const char           convertToByte(      void* value,unsigned int len ) const; 
	 unsigned int         convertToString( void* value , wchar_t* val, unsigned int len,
							unsigned int max) const; 
	 unsigned int         convertToBytes(     void* value , char* val, unsigned int len,
							unsigned int max) const; 
	 const wchar_t        convertToCharacter(  void* value ,unsigned int len) const; 
	 const short          convertToShort(     void* value ,unsigned int len) const; 
	 const long           convertToInteger(   void* value ,unsigned int len) const; 
	 const int64_t        convertToLong(      void* value ,unsigned int len) const; 
	 const float          convertToFloat(     void* value ,unsigned int len) const; 
	 const long double    convertToDouble(void* value ,unsigned int len) const; 
	 DataObject*		  convertToDataObject(void* value ,unsigned int len) const; 
	 const SDODate         convertToDate      (void* value ,unsigned int len) const; 

 	///////////////////////////////////////////////////////////////////////////
    // Equals 
 	///////////////////////////////////////////////////////////////////////////
	bool equals(const Type& t);

	///////////////////////////////////////////////////////////////////////////
    // Returns the name of the type.
	///////////////////////////////////////////////////////////////////////////
	const char* getName() const;
  
	///////////////////////////////////////////////////////////////////////////
    // Alias support.
    // @return nth alias
	///////////////////////////////////////////////////////////////////////////
	virtual const char* getAlias(unsigned int index = 0) const ;
	virtual unsigned int getAliasCount() const ;
	virtual void setAlias(const char* alias);

	///////////////////////////////////////////////////////////////////////////
    // Returns the namespace URI of the type.
	///////////////////////////////////////////////////////////////////////////
	const char* getURI() const;

	///////////////////////////////////////////////////////////////////////////
    // Returns the list of the properties of this type.
	///////////////////////////////////////////////////////////////////////////
	PropertyList  getProperties() const;

 	///////////////////////////////////////////////////////////////////////////
    //  add a property to a Type whilst building - this is for DAS 
	///////////////////////////////////////////////////////////////////////////
	void   addProperty(const char* name,
		                       const TypeImpl& t, bool many, bool rdonly, bool cont);
  
	///////////////////////////////////////////////////////////////////////////
    // Returns the property with the specified name.
	///////////////////////////////////////////////////////////////////////////
    const Property& getProperty(const char* propertyName) const ;
    const Property& getProperty(unsigned int index)  const ;

    PropertyImpl& getPropertyImpl(const char* propertyName) const ;
    PropertyImpl& getPropertyImpl(unsigned int index)  const ;

    unsigned int getPropertyIndex(const char* propertyName)  const ;

	///////////////////////////////////////////////////////////////////////////
    // Indicates if this Type specifies DataObjects.
 	///////////////////////////////////////////////////////////////////////////
	bool isDataObjectType() const;
  
	///////////////////////////////////////////////////////////////////////////
    // Indicates if this Type specifies Sequenced DataObjects.
	///////////////////////////////////////////////////////////////////////////
    bool isSequencedType() const;
	void setSequenced(bool set);

	///////////////////////////////////////////////////////////////////////////
    // Indicates if this Type allows any form of open content.  If false,
    // dataObject.getInstanceProperties() must be the same as 
    // DataObject.getType().getProperties().
	///////////////////////////////////////////////////////////////////////////
    bool isOpenType() const;
	void setOpen(bool set);

	///////////////////////////////////////////////////////////////////////////
    // Indicates if this type may not be instantiated.
	///////////////////////////////////////////////////////////////////////////
	bool isAbstractType() const;
	void setAbstract(bool set);

	///////////////////////////////////////////////////////////////////////////
    // Set the base type for inherited types
	///////////////////////////////////////////////////////////////////////////
    void setBaseType(const Type* tb);
	const Type* getBaseType() const;


	///////////////////////////////////////////////////////////////////////////
    // Indicates a non-object type
	///////////////////////////////////////////////////////////////////////////
	bool isDataType() const;

	///////////////////////////////////////////////////////////////////////////
    // Indicates a non-object type
	///////////////////////////////////////////////////////////////////////////
	Type::Types getTypeEnum() const;

	///////////////////////////////////////////////////////////////////////////
	// set this type as a change summary holder
	///////////////////////////////////////////////////////////////////////////
	void addChangeSummary();

	///////////////////////////////////////////////////////////////////////////
    // Say if this type is allowed to have a summary
	///////////////////////////////////////////////////////////////////////////
    bool isChangeSummaryType() const;

	///////////////////////////////////////////////////////////////////////////
    // Used by the DAS to resolve the base type properties list
	///////////////////////////////////////////////////////////////////////////
	void initCompoundProperties();

	///////////////////////////////////////////////////////////////////////////
    // Used by the DAS to chack for nested change summaries
	///////////////////////////////////////////////////////////////////////////
	void validateChangeSummary();

private:
	friend class DataFactoryImpl;

	bool changeSummaryType;

	void* newValue(void* v, int size) const;

	PROPERTY_LIST getCompoundProperties();

	void throwIfNestedChangeSummary() const;

    TypeImpl(const char* uri,const char* name, 
		bool isSeq= false, 
		bool isOp = false,
		bool isAbs = false, 
		bool isData = false);
	
    TypeImpl(const Type* base, const char* uri,const char* name, 
		bool isSeq = false, 
		bool isOp = false,
		bool isAbs = false,
		bool isData = false); 

    void TypeImpl::init(const char* uri, const char* inname, 
		 bool isSeq,
		 bool isOp,
		 bool isAbs,
		 bool isData);



	TypeImpl();
	TypeImpl(const TypeImpl& t);


	char* name;
	char* typeURI;


	bool isPrimitive;
	bool isSequenced;
	bool isOpen;
	bool isAbstract;

	// baseType properties included
	bool isResolved;
	// check for circular dependency
	bool isResolving;

	Types typeEnum;
	
	static char* types[num_types];

	// alias support

	std::vector<char*> aliases;


	PROPERTY_LIST props;

	// type inheritance
	TypeImpl* baseType;
	// says how many of the props are really in this data object type.
	unsigned int localPropsSize;

};

};
};

#endif //_TYPEIMPL_H_