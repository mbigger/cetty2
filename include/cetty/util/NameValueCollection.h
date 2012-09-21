#if !defined(CETTY_UTIL_NAMEVALUECOLLECTION_H)
#define CETTY_UTIL_NAMEVALUECOLLECTION_H

//
// NameValueCollection.h
//
// $Id: //poco/1.4/Net/include/Poco/Net/NameValueCollection.h#1 $
//
// Library: Net
// Package: Messages
// Module:  NameValueCollection
//
// Definition of the NameValueCollection class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#include <map>
#include <vector>
#include <boost/function.hpp>
#include <boost/algorithm/string/case_conv.hpp>

namespace cetty {
namespace util {

class NameValueCollection
    /// A collection of name-value pairs that are used in
    /// various internet protocols like HTTP and SMTP.
    ///
    /// The name is case-insensitive.
    ///
    /// There can be more than one name-value pair with the
    /// same name.
{
public:
    struct ILT {
        bool operator()(const std::string& s1, const std::string& s2) const {
            return boost::to_upper_copy(s1) < boost::to_upper_copy(s2);
        }
    };

    typedef std::multimap<std::string, std::string, ILT> HeaderMap;
    typedef HeaderMap::iterator Iterator;
    typedef HeaderMap::const_iterator ConstIterator;
    typedef boost::function<bool (const std::string&)> ValidateNameFunctor;

public:
    NameValueCollection();
    /// Creates an empty NameValueCollection.

    NameValueCollection(const NameValueCollection& nvc);
    /// Creates a NameValueCollection by copying another one.

    virtual ~NameValueCollection();
    /// Destroys the NameValueCollection.

    NameValueCollection& operator = (const NameValueCollection& nvc);
    /// Assigns the name-value pairs of another NameValueCollection to this one.

    void setValidateNameFunctor(const ValidateNameFunctor& functor);

    void swap(NameValueCollection& nvc);
    /// Swaps the NameValueCollection with another one.

    const std::string& operator [](const std::string& name) const;
    /// Returns the value of the (first) name-value pair with the given name.

    void set(const std::string& name, const std::string& value);
    /// Sets the value of the (first) name-value pair with the given name.

    template< class IteratorType>
    void set(const std::string& name, IteratorType from, const IteratorType& to) {
        for (; from != to; ++from) {
            set(name, *from);
        }
    }

    void add(const std::string& name, const std::string& value);
    /// Adds a new name-value pair with the given name and value.

    const std::string& get(const std::string& name) const;
    /// Returns the value of the first name-value pair with the given name.

    const std::string& get(const std::string& name, const std::string& defaultValue) const;
    /// Returns the value of the first name-value pair with the given name.
    /// If no value with the given name has been found, the defaultValue is returned.

    const int get(const std::string& name, std::vector<std::string>* values) const;

    const int getNames(std::vector<std::string>* names) const;

    bool has(const std::string& name) const;
    /// Returns true if there is at least one name-value pair
    /// with the given name.

    bool has(const std::string& name, const std::string& value) const;

    ConstIterator find(const std::string& name) const;
    /// Returns an iterator pointing to the first name-value pair
    /// with the given name.

    ConstIterator lowerBound(const std::string& name) const;

    ConstIterator upperBound(const std::string& name) const;

    ConstIterator begin() const;
    /// Returns an iterator pointing to the begin of
    /// the name-value pair collection.

    ConstIterator end() const;
    /// Returns an iterator pointing to the end of
    /// the name-value pair collection.

    bool empty() const;
    /// Returns true if the header does not have any content.

    int size() const;
    /// Returns the number of name-value pairs in the
    /// collection.

    void erase(const std::string& name);
    /// Removes all name-value pairs with the given name.

    void erase(const std::string& name, const std::string& value);
    /// Removes the name-value pair with the given name and value.

    void clear();
    /// Removes all name-value pairs and their values.

private:
    ValidateNameFunctor validateNameFunctor;
    HeaderMap _map;
};


//
// inlines
//
inline void swap(NameValueCollection& nvc1, NameValueCollection& nvc2) {
    nvc1.swap(nvc2);
}


}
} // namespace cetty::util


#endif //#if !defined(CETTY_UTIL_NAMEVALUECOLLECTION_H)

// Local Variables:
// mode: c++
// End:
