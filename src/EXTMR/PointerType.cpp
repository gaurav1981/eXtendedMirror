/* 
 * File:   PointerType.cpp
 * Author: manuele
 * 
 * Created on May 2, 2013, 3:59 PM
 */

#include <EXTMR/ExtendedMirror.hpp>

using namespace extmr;
using namespace std;


PointerType::PointerType
(
        const std::string& name,
        std::size_t size,
        const std::type_info& cppType,
        Constructor* constructor,
        CopyConstructor* copyConstructor,
        Destructor* destructor,
        AssignOperator* assignOperator,
        const Type& pointedType
 )
    :
    Type
    (
        name,
        size,
        cppType,
        constructor,
        copyConstructor,
        destructor,
        assignOperator
    ),
    pointedType_(&pointedType)
{
    
}


Type::Category PointerType::getCategory() const
{
    return Type::Pointer;
}


const Type& PointerType::getPointedType() const
{
    return *pointedType_;
}


PointerType::~PointerType()
{
    
}
