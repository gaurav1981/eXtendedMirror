
/******************************************************************************      
 *      Extended Mirror: BindMethod.hpp                                       *
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

/* WARNING: This file has been autogenerated. do not modify it directly! */

#ifndef EXTMR_BINDMETHOD_HPP
#define	EXTMR_BINDMETHOD_HPP


#define EXTMR_METHOD_PARAM_MAX 7


namespace extmr{



template
<
    class ClassT,
    typename RetT
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_0_Params
        <
            ClassT,
            RetT
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_0_Params
        <
            ClassT,
            RetT
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_1_Params
        <
            ClassT,
            RetT,
            ParamT0
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_1_Params
        <
            ClassT,
            RetT,
            ParamT0
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_2_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0,
                ParamT1
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_2_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_3_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0,
                ParamT1,
                ParamT2
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_3_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_4_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0,
                ParamT1,
                ParamT2,
                ParamT3
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_4_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_5_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0,
                ParamT1,
                ParamT2,
                ParamT3,
                ParamT4
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_5_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_6_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0,
                ParamT1,
                ParamT2,
                ParamT3,
                ParamT4,
                ParamT5
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_6_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5
        >
        (
            name,
            method_nc,
            true
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5,
    typename ParamT6
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5,
        ParamT6
    ) 
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();
    registerType<ParamT6>();
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_7_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5,
            ParamT6
        >
        (
            name,
            method,
            false
        );
}



template
<
    class ClassT,
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5,
    typename ParamT6
>
Method& bindMethod
(
    const std::string& name,
    RetT (ClassT::*method)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5,
        ParamT6
    ) const
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();
    registerType<ParamT6>();
    
    // remove the constness from the method
    RetT (ClassT::*method_nc)() =
        reinterpret_cast
        <
            RetT (ClassT::*)
            (
                ParamT0,
                ParamT1,
                ParamT2,
                ParamT3,
                ParamT4,
                ParamT5,
                ParamT6
            )
        >(method);
    
    // create the proper Method
    return const_cast<Class&>(getClass<ClassT>())
        & *new MethodImpl_7_Params
        <
            ClassT,
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5,
            ParamT6
        >
        (
            name,
            method_nc,
            true
        );
}



} // namespace extmr

#endif	/* EXTMR_BINDMETHOD_HPP */