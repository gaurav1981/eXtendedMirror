/******************************************************************************      
 *      Extended Mirror: OtherMembers.hpp                                     *
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


#ifndef EXTMR_OTHERMEMBERS_HPP
#define	EXTMR_OTHERMEMBERS_HPP

namespace extmr {


class Constructor : public Member
{
public:
    Constructor(const Class& owner);
    virtual void init(Variant& var) const;
};


template<class C>
class ConstructorImpl : public Constructor
{
public:
    ConstructorImpl(const Class& owner) : Constructor(owner) {};
    void init(Variant& var) const
    {
        new (&var.as<C>()) C();
    }
};


class CopyConstructor : public Member
{
public:
    CopyConstructor(const Class& owner);
    virtual void copy(Variant& copy, const Variant& orig) const;
};


template<class C>
class CopyConstructorImpl : public CopyConstructor
{
public:
    CopyConstructorImpl(const Class& owner) : CopyConstructor(owner) {};
    void copy(Variant& copy, const Variant& orig) const
    {
        Variant& nc_orig = const_cast<Variant&>(orig);
        new (&copy.as<C>()) C(nc_orig.as<C>());
    }
};


class Destructor : Member
{
public:
    Destructor(const Class& owner);
    virtual void destroy(Variant& var) const;
};


template<typename C>
class DestructorImpl : public Destructor
{
public:
    DestructorImpl(const Class& owner) : Destructor(owner) {};
    void destroy(Variant& var) const
    {
        var.as<C>().~C();
    }
};


class AssignOperator : public Member
{
public:
    AssignOperator(const Class& owner);
    virtual void assign(Variant& lvar, const Variant& rvar) const;
};


template<typename C>
class AssignOperatorImpl : public AssignOperator
{
public:
    AssignOperatorImpl(const Class& owner) : AssignOperator(owner) {}
    void assign(Variant& lvar, const Variant& rvar) const
    {
        Variant& nc_rvar = const_cast<Variant&>(rvar);
        lvar.as<C>() = nc_rvar.as<C>();
    }
};

class AddressOfOperator : public Member
{
public:
    AddressOfOperator(const Class& owner);
    virtual void addressOf(Variant& lvar, const Variant& rvar) const;
};


template<typename C>
class AddressOfOperatorImpl : public AddressOfOperator
{
public:
    AddressOfOperatorImpl(const Class& owner) : AddressOfOperator(owner) {}
    void addressOf(Variant& lvar, const Variant& rvar) const
    {
        Variant& nc_rvar = const_cast<Variant&>(rvar);
        lvar.as<C*>() = &nc_rvar.as<C>();
    }
};

class DereferenceOperator : public Member
{
public:
    DereferenceOperator(const Class& owner);
    virtual void dereference(Variant& lvar, const Variant& rvar) const;
};


template<typename C>
class DereferenceOperatorImpl : public DereferenceOperator
{
public:
    DereferenceOperatorImpl(const Class& owner) : DereferenceOperator(owner) {}
    void dereference(Variant& lvar, const Variant& rvar) const
    {
        Variant& nc_rvar = const_cast<Variant&>(rvar);
        lvar.as<C>() = *nc_rvar.as<C*>();
    }
};


//TODO: Add all other operators

} // namespace extmr

#endif	/* EXTMR_OTHERMEMBERS_HPP */

