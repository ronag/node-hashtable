#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <node.h>
#include <nan.h>
#include "v8_value_hasher.h"

typedef unordered_map<CopyablePersistent *, CopyablePersistent *, v8_value_hash, v8_value_equal_to> MapType;

class HashTable : public Nan::ObjectWrap {
public:
    static void init(v8::Local<v8::Object> target);

private:
    HashTable();
    HashTable(size_t buckets);
    ~HashTable();

    MapType map;

    // new HashTable() or new HashTable(buckets)
    static NAN_METHOD(Constructor);

    // hashTable.get(key) : value
    static NAN_METHOD(Get);

    // hashTable.has(key) : boolean
    static NAN_METHOD(Has);

    // hashTable.put(key, value) : hashtable
    static NAN_METHOD(Put);

    // hashTable.keys() : []
    static NAN_METHOD(Keys);

    // hashTable.remove(key) : boolean
    static NAN_METHOD(Remove);

    // hashTable.clear() : undefined
    static NAN_METHOD(Clear);

    // hashTable.size() : number of elements
    static NAN_METHOD(Size);

    // hashTable.rehash(buckets) : undefined
    static NAN_METHOD(Rehash);

    // hashTable.reserve(size) : undefined
    static NAN_METHOD(Reserve);

    // hashTable.max_load_factor() or hashTable.max_load_factor(factor) : current or old max_load_factor
    static NAN_METHOD(MaxLoadFactor);

    // hashTable.forEach(function (key, value) {...}, context) : undefined
    static NAN_METHOD(ForEach);

    // hashTable.find(function (key, value) {...}, context) : value
    static NAN_METHOD(Find);
};

#endif
