//
// Generated file, do not edit! Created by nedtool 4.6 from QueryReply.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "QueryReply_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(QueryReply);

QueryReply::QueryReply(const char *name, int kind) : ::ApplPkt(name,kind)
{
    this->timeStamp_var = 0;
}

QueryReply::QueryReply(const QueryReply& other) : ::ApplPkt(other)
{
    copy(other);
}

QueryReply::~QueryReply()
{
}

QueryReply& QueryReply::operator=(const QueryReply& other)
{
    if (this==&other) return *this;
    ::ApplPkt::operator=(other);
    copy(other);
    return *this;
}

void QueryReply::copy(const QueryReply& other)
{
    this->replyBusinesses_var = other.replyBusinesses_var;
    this->timeStamp_var = other.timeStamp_var;
}

void QueryReply::parsimPack(cCommBuffer *b)
{
    ::ApplPkt::parsimPack(b);
    doPacking(b,this->replyBusinesses_var);
    doPacking(b,this->timeStamp_var);
}

void QueryReply::parsimUnpack(cCommBuffer *b)
{
    ::ApplPkt::parsimUnpack(b);
    doUnpacking(b,this->replyBusinesses_var);
    doUnpacking(b,this->timeStamp_var);
}

vecQueryReply& QueryReply::getReplyBusinesses()
{
    return replyBusinesses_var;
}

void QueryReply::setReplyBusinesses(const vecQueryReply& replyBusinesses)
{
    this->replyBusinesses_var = replyBusinesses;
}

simtime_t QueryReply::getTimeStamp() const
{
    return timeStamp_var;
}

void QueryReply::setTimeStamp(simtime_t timeStamp)
{
    this->timeStamp_var = timeStamp;
}

class QueryReplyDescriptor : public cClassDescriptor
{
  public:
    QueryReplyDescriptor();
    virtual ~QueryReplyDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(QueryReplyDescriptor);

QueryReplyDescriptor::QueryReplyDescriptor() : cClassDescriptor("QueryReply", "ApplPkt")
{
}

QueryReplyDescriptor::~QueryReplyDescriptor()
{
}

bool QueryReplyDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<QueryReply *>(obj)!=NULL;
}

const char *QueryReplyDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int QueryReplyDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int QueryReplyDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *QueryReplyDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "replyBusinesses",
        "timeStamp",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int QueryReplyDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "replyBusinesses")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStamp")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *QueryReplyDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "vecQueryReply",
        "simtime_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *QueryReplyDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int QueryReplyDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    QueryReply *pp = (QueryReply *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string QueryReplyDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    QueryReply *pp = (QueryReply *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getReplyBusinesses(); return out.str();}
        case 1: return double2string(pp->getTimeStamp());
        default: return "";
    }
}

bool QueryReplyDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    QueryReply *pp = (QueryReply *)object; (void)pp;
    switch (field) {
        case 1: pp->setTimeStamp(string2double(value)); return true;
        default: return false;
    }
}

const char *QueryReplyDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(vecQueryReply));
        default: return NULL;
    };
}

void *QueryReplyDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    QueryReply *pp = (QueryReply *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getReplyBusinesses()); break;
        default: return NULL;
    }
}


