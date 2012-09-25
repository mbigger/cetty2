#if !defined(CETTY_SHIRO_CRYPT_DIGESTENGINE_H)
#define CETTY_SHIRO_CRYPT_DIGESTENGINE_H
//
// DigestEngine.h
//
// $Id: //poco/1.4/Foundation/include/Poco/DigestEngine.h#1 $
//
// Library: Foundation
// Package: Crypt
// Module:  DigestEngine
//
// Definition of class DigestEngine.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
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

#include <vector>
#include <string>

namespace cetty {
namespace shiro {
namespace crypt {

/// This class is an abstract base class
/// for all classes implementing a message
/// digest algorithm, like MD5Engine
/// and SHA1Engine.
/// Call update() repeatedly with data to
/// compute the digest from. When done,
/// call digest() to obtain the message
/// digest.
class DigestEngine
{
public:
    typedef std::vector<unsigned char> Digest;

    DigestEngine();
    virtual ~DigestEngine();

    /// Updates the digest with the given data.
    void update(const void* data, int length);
    void update(char data);
    void update(const std::string& data);

    /// Returns the length of the digest in bytes.
    virtual int digestLength() const = 0;

    /// Resets the engine so that a new
    /// digest can be computed.
    virtual void reset() = 0;

    /// Finishes the computation of the digest and
    /// returns the message digest. Resets the engine
    /// and can thus only be called once for every digest.
    /// The returned reference is valid until the next
    /// time digest() is called, or the engine object is destroyed.
    virtual const Digest& digest() = 0;

    /// Converts a message digest into a string of hexadecimal numbers.
    static std::string digestToHex(const Digest& bytes);

    static void digestFromHex(const std::string& hex, std::string* out);

    static std::string digestToBase64(const Digest& bytes);

    static void digestFromBase64(const std::string& base64, std::string* out);

protected:
    /// Updates the digest with the given data. Must be implemented
    /// by subclasses.
    virtual void updateImpl(const void* data, unsigned int length) = 0;

private:
    DigestEngine(const DigestEngine&);
    DigestEngine& operator = (const DigestEngine&);
};


//
// inlines
//

inline void DigestEngine::update(const void* data, int length) {
    if (length > 0) {
        updateImpl(data, (unsigned int)length);
    }
}

inline void DigestEngine::update(char data) {
    updateImpl(&data, 1);
}

inline void DigestEngine::update(const std::string& data) {
    updateImpl(data.data(), (unsigned int) data.size());
}

}
}
}

#endif //#if !defined(CETTY_SHIRO_CRYPT_DIGESTENGINE_H)

// Local Variables:
// mode: c++
// End:
