/*
 * Extended Mirror
 * 
 * Copyright (c) 2012-2013 Manuele Finocchiaro (m4nu3lf@gmail.com)
 * 
 */

#ifndef EXTMR_NOTFOUNDEXCEPTIONS_HPP
#define	EXTMR_NOTFOUNDEXCEPTIONS_HPP


namespace extmr{

    
class TypeNotFoundException : public std::exception
{
public:
    TypeNotFoundException(const std::string& name) throw();
    
    const char* what() const throw();
    
    ~TypeNotFoundException() throw();
    
private:
    std::string name_;
};


class TemplateNotFoundException : public std::exception
{
public:
    TemplateNotFoundException(const std::string& name) throw();
    
    const char* what() const throw();
    
    ~TemplateNotFoundException() throw();
    
private:
    std::string name_;
};


class PropertyNotFoundException : public std::exception
{
public:
    PropertyNotFoundException(const std::string& propertyName,
            const std::string& className) throw();
    
    const char* what() const throw();
    
    ~PropertyNotFoundException() throw();
    
private:
    std::string propertyName_;
    std::string className_;
};


class Method;

class MethodNotFoundException : public std::exception
{
public:
    MethodNotFoundException(const std::string& methodName,
            const std::string& className) throw();
    MethodNotFoundException(const Method& method, const std::string& className)
             throw();
    
    const char* what() const throw();
    
    ~MethodNotFoundException() throw();
    
private:
    const Method* method_;
    std::string className_;
    bool deleteMethod_;
};


} // namespace extmr

#endif	/* EXTMR_NOTFOUNDEXCEPTIONS_HPP */

