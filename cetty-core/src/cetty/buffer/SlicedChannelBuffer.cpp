/*
 * Copyright (c) 2010-2011 frankee zhou (frankee.zhou at gmail dot com)
 *
 * Distributed under under the Apache License, version 2.0 (the "License").
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include <cetty/buffer/SlicedChannelBuffer.h>
#include <cetty/buffer/Unpooled.h>

#include <cetty/util/Exception.h>
#include <cetty/util/StringUtil.h>
#include <cetty/util/StringPiece.h>

namespace cetty {
namespace buffer {

using namespace cetty::util;

SlicedChannelBuffer::SlicedChannelBuffer(const ChannelBufferPtr& buffer,
        int index,
        int length)
    : buffer(buffer), length(length), adjustment(index) {
    BOOST_ASSERT(buffer);

    if (index < 0 || index > buffer->capacity()) {
        throw RangeException("index out range");
    }

    if (index + length > buffer->capacity()) {
        throw RangeException("index + length out of range");
    }

    writerIndex(length);
}

const ChannelBufferPtr& SlicedChannelBuffer::unwrap() {
    return buffer;
}

int SlicedChannelBuffer::capacity() const {
    return length;
}

void SlicedChannelBuffer::capacity(int newCapacity) {
    throw UnsupportedOperationException("sliced buffer");
}

void SlicedChannelBuffer::readableBytes(StringPiece* bytes) {
    if (bytes) {
        int count;
        char* data = buffer->aheadWritableBytes(&count);

        bytes->set(data + readerIdx + adjustment, length - readerIdx);
    }
}

char* SlicedChannelBuffer::writableBytes(int* length) {
    return NULL;
}

char* SlicedChannelBuffer::aheadWritableBytes(int* length) {
    if (length) {
        int count;
        char* bytes = buffer->aheadWritableBytes(&count);

        *length = readerIdx;
        return bytes + adjustment;
    }

    return NULL;
}

int8_t SlicedChannelBuffer::getByte(int index) const {
    checkIndex(index);
    return buffer->getByte(index + adjustment);
}

int16_t SlicedChannelBuffer::getShort(int index) const {
    checkIndex(index, 2);
    return buffer->getShort(index + adjustment);
}

int32_t SlicedChannelBuffer::getInt(int index) const {
    checkIndex(index, 4);
    return buffer->getInt(index + adjustment);
}

int64_t SlicedChannelBuffer::getLong(int index) const {
    checkIndex(index, 8);
    return buffer->getLong(index + adjustment);
}

ChannelBufferPtr SlicedChannelBuffer::copy(int index, int length) const {
    checkIndex(index, length);
    return buffer->copy(index + adjustment, length);
}

ChannelBufferPtr SlicedChannelBuffer::slice(int index, int length) {
    checkIndex(index, length);

    if (length == 0) {
        return Unpooled::EMPTY_BUFFER;
    }

    return ChannelBufferPtr(
               new SlicedChannelBuffer(buffer, index + adjustment, length));
}

int SlicedChannelBuffer::slice(int index, int length, GatheringBuffer* gathering) {
    if (!gathering || length == 0) {
        return 0;
    }

    checkIndex(index, length);
    return buffer->slice(index + adjustment, length, gathering);
}

int SlicedChannelBuffer::getBytes(int index, const ChannelBufferPtr& dst, int dstIndex, int length) const {
    checkIndex(index, length);
    return buffer->getBytes(index + adjustment, dst, dstIndex, length);
}

int SlicedChannelBuffer::getBytes(int index, char* dst, int dstIndex, int length) const {
    checkIndex(index, length);
    return buffer->getBytes(index + adjustment, dst, dstIndex, length);
}

int SlicedChannelBuffer::getBytes(int index, OutputStream* out, int length) const {
    checkIndex(index, length);
    return buffer->getBytes(index + adjustment, out, length);
}

int SlicedChannelBuffer::setByte(int index, int value) {
    checkIndex(index);
    return buffer->setByte(index + adjustment, value);
}

int SlicedChannelBuffer::setShort(int index, int value) {
    checkIndex(index, 2);
    return buffer->setShort(index + adjustment, value);
}

int SlicedChannelBuffer::setInt(int index, int value) {
    checkIndex(index, 4);
    return buffer->setInt(index + adjustment, value);
}

int SlicedChannelBuffer::setLong(int index, int64_t value) {
    checkIndex(index, 8);
    return buffer->setLong(index + adjustment, value);
}

int SlicedChannelBuffer::setBytes(int index, const StringPiece& src, int srcIndex, int length) {
    checkIndex(index, length);
    return buffer->setBytes(index + adjustment, src, srcIndex, length);
}

int SlicedChannelBuffer::setBytes(int index, const ConstChannelBufferPtr& src, int srcIndex, int length) {
    checkIndex(index, length);
    return buffer->setBytes(index + adjustment, src, srcIndex, length);
}

int SlicedChannelBuffer::setBytes(int index, InputStream* in, int length) {
    checkIndex(index, length);
    return buffer->setBytes(index + adjustment, in, length);
}

void SlicedChannelBuffer::checkIndex(int index) const {
    if (index < 0 || index >= capacity()) {
        throw RangeException("SliceChannelBuffer range exception.");
    }
}

void SlicedChannelBuffer::checkIndex(int startIndex, int length) const {
    if (length < 0) {
        throw InvalidArgumentException(
            StringUtil::strprintf("length is negative: %d", length));
    }

    if (startIndex < 0) {
        throw RangeException("SlicedChannelBuffer startIndex is negative.");
    }

    if (startIndex + length > capacity()) {
        throw RangeException("SlicedChannelBuffer length is out of range.");
    }
}

ChannelBufferPtr SlicedChannelBuffer::newBuffer(int initialCapacity) {
    return buffer->newBuffer(initialCapacity);
}

}
}
