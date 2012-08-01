#if !defined(CETTY_CHANNEL_IPADDRESS_H)
#define CETTY_CHANNEL_IPADDRESS_H

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
/*
 * Copyright (c) 2010-2011 frankee zhou (frankee.zhou at gmail dot com)
 * Distributed under under the Apache License, version 2.0 (the "License").
 */

#include <string>
#include <boost/intrusive_ptr.hpp>

namespace cetty {
namespace channel {

class IpAddressImpl;
class IpAddressImplFactory;
typedef boost::intrusive_ptr<IpAddressImpl> IpAddressImplPtr;

/**
 * This class represents an internet (IP) host
 * address. The address can belong either to the
 * IPv4 or the IPv6 address family.
 *
 * Relational operators (==, !=, <, <=, >, >=) are
 * supported. However, you must not interpret any
 * special meaning into the result of these
 * operations, other than that the results are
 * consistent.
 *
 * Especially, an IPv4 address is never equal to
 * an IPv6 address, even if the IPv6 address is
 * IPv4 compatible and the addresses are the same.
 *
 * IPv6 addresses are supported only if the target platform
 * supports IPv6.
 */
class IpAddress {
public:
    static const IpAddress NULL_ADDRESS;

public:
    /**
     * Possible address families for IP addresses.
     */
    enum Family {
        IPv4,
        IPv6
    };

    IpAddress();

    /**
     * Creates a wildcard (zero) IpAddress for the
     * given address family.
     */
    explicit IpAddress(int family);

    /**
     * Creates an IpAddress from the string containing
     * an IP address in presentation format (dotted decimal
     * for IPv4, hex string for IPv6).
     *
     * Depending on the format of addr, either an IPv4 or
     * an IPv6 address is created.
     *
     * See toString() for details on the supported formats.
     *
     * Throws an InvalidAddressException if the address cannot be parsed.
     */
    explicit IpAddress(const std::string& addr);

    /**
     * Creates an IpAddress from the string containing
     * an IP address in presentation format (dotted decimal
     * for IPv4, hex string for IPv6).
     */
    IpAddress(const std::string& addr, int family);

    IpAddress(const IpAddressImplPtr& impl);

    /**
     * Creates an IpAddress by copying another one.
     */
    IpAddress(const IpAddress& addr);

    /**
     * Destroys the IpAddress.
     */
    ~IpAddress();

    /**
     * Assigns an IpAddress.
     */
    IpAddress& operator = (const IpAddress& addr);

    /**
     * Swaps the IpAddress with another one.
     */
    void swap(IpAddress& address);

    /**
     * Returns the address family (IPv4 or IPv6) of the address.
     */
    int family() const;

    /**
     * Returns a string containing a representation of the address
     * in presentation format.
     *
     * For IPv4 addresses the result will be in dotted-decimal
     * (d.d.d.d) notation.
     *
     * Textual representation of IPv6 address is one of the following forms:
     *
     * The preferred form is x:x:x:x:x:x:x:x, where the 'x's are the hexadecimal
     * values of the eight 16-bit pieces of the address. This is the full form.
     * Example: 1080:0:0:0:8:600:200A:425C
     *
     * It is not necessary to write the leading zeros in an individual field.
     * However, there must be at least one numeral in every field, except as described below.
     *
     * It is common for IPv6 addresses to contain long strings of zero bits.
     * In order to make writing addresses containing zero bits easier, a special syntax is
     * available to compress the zeros. The use of "::" indicates multiple groups of 16-bits of zeros.
     * The "::" can only appear once in an address. The "::" can also be used to compress the leading
     * and/or trailing zeros in an address. Example: 1080::8:600:200A:425C
     *
     * For dealing with IPv4 compatible addresses in a mixed environment,
     * a special syntax is available: x:x:x:x:x:x:d.d.d.d, where the 'x's are the
     * hexadecimal values of the six high-order 16-bit pieces of the address,
     * and the 'd's are the decimal values of the four low-order 8-bit pieces of the
     * standard IPv4 representation address. Example: ::FFFF:192.168.1.120
     */
    std::string toString() const;

    /**
     * check the IpAddress is not a NULL_ADDRESS.
     */
    bool validated() const { return impl; }

    /**
     * Returns true if the address is a wildcard (all zero)
     * address.
     */
    bool isWildcard() const;

    /**
     * Returns true if the address is a broadcast address.
     *
     * Only IPv4 addresses can be broadcast addresses. In a broadcast
     * address, all bits are one.
     *
     * For a IPv6 address, returns always false.
     */
    bool isBroadcast() const;

    /**
     * Returns true if the address is a loopback address.
     *
     * For IPv4, the loopback address is 127.0.0.1.
     *
     * For IPv6, the loopback address is ::1.
     */
    bool isLoopback() const;

    /**
     * Returns true if the address is a multicast address.
     *
     * IPv4 multicast addresses are in the
     * 224.0.0.0 to 239.255.255.255 range
     * (the first four bits have the value 1110).
     *
     * IPv6 multicast addresses are in the
     * FFxx:x:x:x:x:x:x:x range.
     */
    bool isMulticast() const;

    /**
     * Returns true if the address is a unicast address.
     *
     * An address is unicast if it is neither a wildcard,
     * broadcast or multicast address.
     */
    bool isUnicast() const;

    /**
     * Returns true if the address is a link local unicast address.
     *
     * IPv4 link local addresses are in the 169.254.0.0/16 range,
     * according to RFC 3927.
     *
     * IPv6 link local addresses have 1111 1110 10 as the first
     * 10 bits, followed by 54 zeros.
     */
    bool isLinkLocal() const;

    /**
     * Returns true if the address is a site local unicast address.
     *
     * IPv4 site local addresses are in on of the 10.0.0.0/24,
     * 192.168.0.0/16 or 172.16.0.0 to 172.31.255.255 ranges.
     *
     * IPv6 site local addresses have 1111 1110 11 as the first
     * 10 bits, followed by 38 zeros.
     */
    bool isSiteLocal() const;

    /**
     * Returns true if the address is IPv4 compatible.
     *
     * For IPv4 addresses, this is always true.
     *
     * For IPv6, the address must be in the ::x:x range (the
     * first 96 bits are zero).
     */
    bool isIPv4Compatible() const;

    /**
     * Returns true if the address is an IPv4 mapped IPv6 address.
     *
     * For IPv4 addresses, this is always true.
     *
     * For IPv6, the address must be in the ::FFFF:x:x range.
     */
    bool isIPv4Mapped() const;

    /**
     * Returns true if the address is a well-known multicast address.
     *
     * For IPv4, well-known multicast addresses are in the
     * 224.0.0.0/8 range.
     *
     * For IPv6, well-known multicast addresses are in the
     * FF0x:x:x:x:x:x:x:x range.
     */
    bool isWellKnownMC() const;

    /**
     * Returns true if the address is a node-local multicast address.
     *
     * IPv4 does not support node-local addresses, thus the result is
     * always false for an IPv4 address.
     *
     * For IPv6, node-local multicast addresses are in the
     * FFx1:x:x:x:x:x:x:x range.
     */
    bool isNodeLocalMC() const;

    /**
     * Returns true if the address is a link-local multicast address.
     *
     * For IPv4, link-local multicast addresses are in the
     * 224.0.0.0/24 range. Note that this overlaps with the range for well-known
     * multicast addresses.
     *
     * For IPv6, link-local multicast addresses are in the
     * FFx2:x:x:x:x:x:x:x range.
     */
    bool isLinkLocalMC() const;

    /**
     * Returns true if the address is a site-local multicast address.
     *
     * For IPv4, site local multicast addresses are in the
     * 239.255.0.0/16 range.
     *
     * For IPv6, site-local multicast addresses are in the
     * FFx5:x:x:x:x:x:x:x range.
     */
    bool isSiteLocalMC() const;

    /**
     * Returns true if the address is a organization-local multicast address.
     *
     * For IPv4, organization-local multicast addresses are in the
     * 239.192.0.0/16 range.
     *
     * For IPv6, organization-local multicast addresses are in the
     * FFx8:x:x:x:x:x:x:x range.
     */
    bool isOrgLocalMC() const;

    /**
     * Returns true if the address is a global multicast address.
     *
     * For IPv4, global multicast addresses are in the
     * 224.0.1.0 to 238.255.255.255 range.
     *
     * For IPv6, global multicast addresses are in the
     * FFxF:x:x:x:x:x:x:x range.
     */
    bool isGlobalMC() const;

    bool operator == (const IpAddress& addr) const;
    bool operator != (const IpAddress& addr) const;
    bool operator < (const IpAddress& addr) const;
    bool operator <= (const IpAddress& addr) const;
    bool operator > (const IpAddress& addr) const;
    bool operator >= (const IpAddress& addr) const;

    /**
     * Masks the IP address using the given netmask, which is usually
     * a IPv4 subnet mask. Only supported for IPv4 addresses.
     *
     * The new address is (address & mask).
     */
    void mask(const IpAddress& mask);

    /**
     * Masks the IP address using the given netmask, which is usually
     * a IPv4 subnet mask. Only supported for IPv4 addresses.
     *
     * The new address is (address & mask) | (set & ~mask).
     */
    void mask(const IpAddress& mask, const IpAddress& set);

    /**
     * Creates an IpAddress from the string containing
     * an IP address in presentation format (dotted decimal
     * for IPv4, hex string for IPv6).
     *
     * Depending on the format of addr, either an IPv4 or
     * an IPv6 address is created.
     *
     * See toString() for details on the supported formats.
     *
     * Throws an InvalidAddressException if the address cannot be parsed.
     */
    static IpAddress parse(const std::string& addr);

    /**
     * Tries to interpret the given address string as an
     * IP address in presentation format (dotted decimal
     * for IPv4, hex string for IPv6).
     *
     * Returns true and stores the IpAddress in result if the
     * string contains a valid address.
     *
     * Returns false and leaves result unchanged otherwise.
     */
    static bool tryParse(const std::string& addr, IpAddress& result);

    /**
     * Returns a wildcard IPv4 or IPv6 address (0.0.0.0).
     */
    static IpAddress wildcard(int family = IPv4);

    /**
     * Returns a broadcast IPv4 address (255.255.255.255).
     */
    static IpAddress broadcast();


    static void setFactory(IpAddressImplFactory* factory);
    static void resetFactory();
    static bool hasFactory();

private:
    IpAddressImplPtr impl;
    static IpAddressImplFactory* factory;
};

inline void swap(IpAddress& addr1, IpAddress& addr2) {
    addr1.swap(addr2);
}

}
}

#endif //#if !defined(CETTY_CHANNEL_IPADDRESS_H)

// Local Variables:
// mode: c++
// End:
