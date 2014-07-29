/******************************************************************************      
 *      Extended Mirror: Bind.hpp                                             *
 ******************************************************************************
 *      Copyright (c) 2012-2014, Manuele Finocchiaro                          *
 *      All rights reserved.                                                  *
 ******************************************************************************
 * Redistribution and use in source and binary forms, with or without         *
 * modification, are permitted provided that the following conditions         *
 * are met:                                                                   *
 *                                                                            *
 *    1. Redistributions of source code must retain the above copyright       *
 *       notice, this list of conditions and the following disclaimer.        *
 *                                                                            *
 *    2. Redistributions in binary form must reproduce the above copyright    *
 *       notice, this list of conditions and the following disclaimer in      *
 *       the documentation and/or other materials provided with the           *
 *       distribution.                                                        *
 *                                                                            *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"* 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE *
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  *
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        *
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF       *
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   *
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    *
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    *
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF     *
 * THE POSSIBILITY OF SUCH DAMAGE.                                            *
 *****************************************************************************/

#ifndef EXTMR_BIND_HPP
#define	EXTMR_BIND_HPP


#define EXTMR_MNP(member) #member, &ClassT::member
#define EXTMR_BIND_BASE(BaseT) bindBase<ClassT, BaseT>();
#define EXTMR_BIND_PASE(BaseT) bindPmBase<ClassT, BaseT>(); // polymorphic base

#include <EXTMR/BindGetNSetProperty.hpp>
#include <EXTMR/BindMethod.hpp>

namespace extmr{


template<class ClassT, class BaseT>
void bindBase()
{
    // ensure that base class is registered
    registerType<BaseT>();
    
    Class& clazz = const_cast<Class&>(getClass<ClassT>());
    Class& base = const_cast<Class&>(getClass<BaseT>());
    
    // bind them together
    clazz & base;
    
    // bind RefCaster to base
    clazz & *new RefCasterImpl<ClassT, BaseT>();
}


template<class ClassT, class BaseT>
void bindPmBase()
{
    bindBase<ClassT, BaseT>();
    
    // bind RefCast from BaseT to CassT
    const_cast<Class&>(getClass<BaseT>()) & *new RefCasterImpl<BaseT, ClassT>();
}


template<class ClassT, typename FieldT>
Property& bindProperty(const std::string& name, FieldT ClassT::* field)
{
    // ensure that the type is registered
    registerType<FieldT>();
    
    // build the Property  and add it to the Class
    return const_cast<Class&>(getClass<ClassT>())
            & *new PropertyField<ClassT, FieldT>(name, field);
}


template<class ClassT, typename FieldT, std::size_t size>
Property& bindProperty(const std::string& name,
        FieldT (ClassT::* field) [size])
{
    // ensure that the type is registered
    registerType<FieldT[size]>();
    
    // build the Property  and add it to the Class
    return const_cast<Class&>(getClass<ClassT>())
            & *new PropertyArrayField<ClassT, FieldT[size]>(name, field);
}


} // namespace extmr

#endif	/* EXTMR_BIND_HPP */

