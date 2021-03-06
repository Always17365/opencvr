#pragma once

// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct CmnRetRsp {
 bool bRet;

explicit CmnRetRsp():bRet() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::CmnRetRsp > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< bool > handler_0;bool has_bRet;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "bRet";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_bRet = false;
    }

public:
    explicit SAXEventHandler( ::oapi::CmnRetRsp * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->bRet)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x62\x52\x65\x74", 4))
                         { state=0; has_bRet = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_bRet) set_missing_required("bRet");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();

    }
};

template < class Writerf123200ab834a9683ebd6c3de616322d858e1a124e699d0f279f0e89ae83a920 >
struct Serializer< Writerf123200ab834a9683ebd6c3de616322d858e1a124e699d0f279f0e89ae83a920, ::oapi::CmnRetRsp > {

    void operator()( Writerf123200ab834a9683ebd6c3de616322d858e1a124e699d0f279f0e89ae83a920& w, const ::oapi::CmnRetRsp& value) const
    {
        w.StartObject();

        w.Key("\x62\x52\x65\x74", 4, false); Serializer< Writerf123200ab834a9683ebd6c3de616322d858e1a124e699d0f279f0e89ae83a920, bool >()(w, value.bRet);

        w.EndObject(1);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct LoginReq {
 std::string User;
std::string Password;

explicit LoginReq():User(), Password() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::LoginReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< std::string > handler_0;
SAXEventHandler< std::string > handler_1;bool has_User;
bool has_Password;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "User";
case 1:
    return "Password";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_User = false;
has_Password = false;
    }

public:
    explicit SAXEventHandler( ::oapi::LoginReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->User)
, handler_1(&obj->Password)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x55\x73\x65\x72", 4))
                         { state=0; has_User = true; }
else if (utility::string_equal(str, length, "\x50\x61\x73\x73\x77\x6f\x72\x64", 8))
                         { state=1; has_Password = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_User) set_missing_required("User");
if (!has_Password) set_missing_required("Password");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();

    }
};

template < class Writer096720ae9e27bde8215be838880bfe91a4c84aef3ce14bad3f1c1f8a49a98fe2 >
struct Serializer< Writer096720ae9e27bde8215be838880bfe91a4c84aef3ce14bad3f1c1f8a49a98fe2, ::oapi::LoginReq > {

    void operator()( Writer096720ae9e27bde8215be838880bfe91a4c84aef3ce14bad3f1c1f8a49a98fe2& w, const ::oapi::LoginReq& value) const
    {
        w.StartObject();

        w.Key("\x55\x73\x65\x72", 4, false); Serializer< Writer096720ae9e27bde8215be838880bfe91a4c84aef3ce14bad3f1c1f8a49a98fe2, std::string >()(w, value.User);
w.Key("\x50\x61\x73\x73\x77\x6f\x72\x64", 8, false); Serializer< Writer096720ae9e27bde8215be838880bfe91a4c84aef3ce14bad3f1c1f8a49a98fe2, std::string >()(w, value.Password);

        w.EndObject(2);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct LoginRsp {
 std::string Nonce;
bool bRetNonce;
bool bRet;

explicit LoginRsp():Nonce(), bRetNonce(), bRet() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::LoginRsp > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< std::string > handler_0;
SAXEventHandler< bool > handler_1;
SAXEventHandler< bool > handler_2;bool has_Nonce;
bool has_bRetNonce;
bool has_bRet;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "Nonce";
case 1:
    return "bRetNonce";
case 2:
    return "bRet";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_Nonce = false;
has_bRetNonce = false;
has_bRet = false;
    }

public:
    explicit SAXEventHandler( ::oapi::LoginRsp * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->Nonce)
, handler_1(&obj->bRetNonce)
, handler_2(&obj->bRet)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

case 2:
    return checked_event_forwarding(handler_2.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

case 2:
    return checked_event_forwarding(handler_2.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

case 2:
    return checked_event_forwarding(handler_2.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

case 2:
    return checked_event_forwarding(handler_2.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

case 2:
    return checked_event_forwarding(handler_2.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

case 2:
    return checked_event_forwarding(handler_2.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

case 2:
    return checked_event_forwarding(handler_2.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

case 2:
    return checked_event_forwarding(handler_2.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x4e\x6f\x6e\x63\x65", 5))
                         { state=0; has_Nonce = true; }
else if (utility::string_equal(str, length, "\x62\x52\x65\x74\x4e\x6f\x6e\x63\x65", 9))
                         { state=1; has_bRetNonce = true; }
else if (utility::string_equal(str, length, "\x62\x52\x65\x74", 4))
                         { state=2; has_bRet = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

case 2:
    return checked_event_forwarding(handler_2.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

case 2:
    return checked_event_forwarding(handler_2.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

case 2:
    return checked_event_forwarding(handler_2.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

case 2:
    return checked_event_forwarding(handler_2.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

case 2:
    return checked_event_forwarding(handler_2.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_Nonce) set_missing_required("Nonce");
if (!has_bRetNonce) set_missing_required("bRetNonce");
if (!has_bRet) set_missing_required("bRet");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;
case 2:
     handler_2.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();
handler_2.PrepareForReuse();

    }
};

template < class Writer6a3e68c6b888bcccbc7072a7e752707e0ac79a3ab45dfddbbc99e33317c8c760 >
struct Serializer< Writer6a3e68c6b888bcccbc7072a7e752707e0ac79a3ab45dfddbbc99e33317c8c760, ::oapi::LoginRsp > {

    void operator()( Writer6a3e68c6b888bcccbc7072a7e752707e0ac79a3ab45dfddbbc99e33317c8c760& w, const ::oapi::LoginRsp& value) const
    {
        w.StartObject();

        w.Key("\x4e\x6f\x6e\x63\x65", 5, false); Serializer< Writer6a3e68c6b888bcccbc7072a7e752707e0ac79a3ab45dfddbbc99e33317c8c760, std::string >()(w, value.Nonce);
w.Key("\x62\x52\x65\x74\x4e\x6f\x6e\x63\x65", 9, false); Serializer< Writer6a3e68c6b888bcccbc7072a7e752707e0ac79a3ab45dfddbbc99e33317c8c760, bool >()(w, value.bRetNonce);
w.Key("\x62\x52\x65\x74", 4, false); Serializer< Writer6a3e68c6b888bcccbc7072a7e752707e0ac79a3ab45dfddbbc99e33317c8c760, bool >()(w, value.bRet);

        w.EndObject(3);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct KeepAliveReq {
 unsigned int nTimeout;

explicit KeepAliveReq():nTimeout() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::KeepAliveReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< unsigned int > handler_0;bool has_nTimeout;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "nTimeout";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_nTimeout = false;
    }

public:
    explicit SAXEventHandler( ::oapi::KeepAliveReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->nTimeout)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x6e\x54\x69\x6d\x65\x6f\x75\x74", 8))
                         { state=0; has_nTimeout = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_nTimeout) set_missing_required("nTimeout");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();

    }
};

template < class Writer3584adabd563fed1229ddef7ad7094fe16b6ad7ed22fcd870a9744c81f8da691 >
struct Serializer< Writer3584adabd563fed1229ddef7ad7094fe16b6ad7ed22fcd870a9744c81f8da691, ::oapi::KeepAliveReq > {

    void operator()( Writer3584adabd563fed1229ddef7ad7094fe16b6ad7ed22fcd870a9744c81f8da691& w, const ::oapi::KeepAliveReq& value) const
    {
        w.StartObject();

        w.Key("\x6e\x54\x69\x6d\x65\x6f\x75\x74", 8, false); Serializer< Writer3584adabd563fed1229ddef7ad7094fe16b6ad7ed22fcd870a9744c81f8da691, unsigned int >()(w, value.nTimeout);

        w.EndObject(1);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct OAPICamera {
 std::string strId;
std::string strName;
unsigned int nType;
std::string strIP;
std::string strPort;
std::string strUser;
std::string strPasswd;
std::string strONVIFAddress;
unsigned int bProfileToken;
std::string strProfileToken1;
std::string strProfileToken2;
std::string strFile;
std::string strRTSPUrl;
unsigned int bHWaccel;
unsigned int bServerMotion;
unsigned int nConnectType;

explicit OAPICamera():strId(), strName(), nType(), strIP(), strPort(), strUser(), strPasswd(), strONVIFAddress(), bProfileToken(), strProfileToken1(), strProfileToken2(), strFile(), strRTSPUrl(), bHWaccel(), bServerMotion(), nConnectType() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::OAPICamera > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< std::string > handler_0;
SAXEventHandler< std::string > handler_1;
SAXEventHandler< unsigned int > handler_2;
SAXEventHandler< std::string > handler_3;
SAXEventHandler< std::string > handler_4;
SAXEventHandler< std::string > handler_5;
SAXEventHandler< std::string > handler_6;
SAXEventHandler< std::string > handler_7;
SAXEventHandler< unsigned int > handler_8;
SAXEventHandler< std::string > handler_9;
SAXEventHandler< std::string > handler_10;
SAXEventHandler< std::string > handler_11;
SAXEventHandler< std::string > handler_12;
SAXEventHandler< unsigned int > handler_13;
SAXEventHandler< unsigned int > handler_14;
SAXEventHandler< unsigned int > handler_15;bool has_strId;
bool has_strName;
bool has_nType;
bool has_strIP;
bool has_strPort;
bool has_strUser;
bool has_strPasswd;
bool has_strONVIFAddress;
bool has_bProfileToken;
bool has_strProfileToken1;
bool has_strProfileToken2;
bool has_strFile;
bool has_strRTSPUrl;
bool has_bHWaccel;
bool has_bServerMotion;
bool has_nConnectType;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "strId";
case 1:
    return "strName";
case 2:
    return "nType";
case 3:
    return "strIP";
case 4:
    return "strPort";
case 5:
    return "strUser";
case 6:
    return "strPasswd";
case 7:
    return "strONVIFAddress";
case 8:
    return "bProfileToken";
case 9:
    return "strProfileToken1";
case 10:
    return "strProfileToken2";
case 11:
    return "strFile";
case 12:
    return "strRTSPUrl";
case 13:
    return "bHWaccel";
case 14:
    return "bServerMotion";
case 15:
    return "nConnectType";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_strId = false;
has_strName = false;
has_nType = false;
has_strIP = false;
has_strPort = false;
has_strUser = false;
has_strPasswd = false;
has_strONVIFAddress = false;
has_bProfileToken = false;
has_strProfileToken1 = false;
has_strProfileToken2 = false;
has_strFile = false;
has_strRTSPUrl = false;
has_bHWaccel = false;
has_bServerMotion = false;
has_nConnectType = false;
    }

public:
    explicit SAXEventHandler( ::oapi::OAPICamera * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->strId)
, handler_1(&obj->strName)
, handler_2(&obj->nType)
, handler_3(&obj->strIP)
, handler_4(&obj->strPort)
, handler_5(&obj->strUser)
, handler_6(&obj->strPasswd)
, handler_7(&obj->strONVIFAddress)
, handler_8(&obj->bProfileToken)
, handler_9(&obj->strProfileToken1)
, handler_10(&obj->strProfileToken2)
, handler_11(&obj->strFile)
, handler_12(&obj->strRTSPUrl)
, handler_13(&obj->bHWaccel)
, handler_14(&obj->bServerMotion)
, handler_15(&obj->nConnectType)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

case 2:
    return checked_event_forwarding(handler_2.Null());

case 3:
    return checked_event_forwarding(handler_3.Null());

case 4:
    return checked_event_forwarding(handler_4.Null());

case 5:
    return checked_event_forwarding(handler_5.Null());

case 6:
    return checked_event_forwarding(handler_6.Null());

case 7:
    return checked_event_forwarding(handler_7.Null());

case 8:
    return checked_event_forwarding(handler_8.Null());

case 9:
    return checked_event_forwarding(handler_9.Null());

case 10:
    return checked_event_forwarding(handler_10.Null());

case 11:
    return checked_event_forwarding(handler_11.Null());

case 12:
    return checked_event_forwarding(handler_12.Null());

case 13:
    return checked_event_forwarding(handler_13.Null());

case 14:
    return checked_event_forwarding(handler_14.Null());

case 15:
    return checked_event_forwarding(handler_15.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

case 2:
    return checked_event_forwarding(handler_2.Bool(b));

case 3:
    return checked_event_forwarding(handler_3.Bool(b));

case 4:
    return checked_event_forwarding(handler_4.Bool(b));

case 5:
    return checked_event_forwarding(handler_5.Bool(b));

case 6:
    return checked_event_forwarding(handler_6.Bool(b));

case 7:
    return checked_event_forwarding(handler_7.Bool(b));

case 8:
    return checked_event_forwarding(handler_8.Bool(b));

case 9:
    return checked_event_forwarding(handler_9.Bool(b));

case 10:
    return checked_event_forwarding(handler_10.Bool(b));

case 11:
    return checked_event_forwarding(handler_11.Bool(b));

case 12:
    return checked_event_forwarding(handler_12.Bool(b));

case 13:
    return checked_event_forwarding(handler_13.Bool(b));

case 14:
    return checked_event_forwarding(handler_14.Bool(b));

case 15:
    return checked_event_forwarding(handler_15.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

case 2:
    return checked_event_forwarding(handler_2.Int(i));

case 3:
    return checked_event_forwarding(handler_3.Int(i));

case 4:
    return checked_event_forwarding(handler_4.Int(i));

case 5:
    return checked_event_forwarding(handler_5.Int(i));

case 6:
    return checked_event_forwarding(handler_6.Int(i));

case 7:
    return checked_event_forwarding(handler_7.Int(i));

case 8:
    return checked_event_forwarding(handler_8.Int(i));

case 9:
    return checked_event_forwarding(handler_9.Int(i));

case 10:
    return checked_event_forwarding(handler_10.Int(i));

case 11:
    return checked_event_forwarding(handler_11.Int(i));

case 12:
    return checked_event_forwarding(handler_12.Int(i));

case 13:
    return checked_event_forwarding(handler_13.Int(i));

case 14:
    return checked_event_forwarding(handler_14.Int(i));

case 15:
    return checked_event_forwarding(handler_15.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

case 2:
    return checked_event_forwarding(handler_2.Uint(i));

case 3:
    return checked_event_forwarding(handler_3.Uint(i));

case 4:
    return checked_event_forwarding(handler_4.Uint(i));

case 5:
    return checked_event_forwarding(handler_5.Uint(i));

case 6:
    return checked_event_forwarding(handler_6.Uint(i));

case 7:
    return checked_event_forwarding(handler_7.Uint(i));

case 8:
    return checked_event_forwarding(handler_8.Uint(i));

case 9:
    return checked_event_forwarding(handler_9.Uint(i));

case 10:
    return checked_event_forwarding(handler_10.Uint(i));

case 11:
    return checked_event_forwarding(handler_11.Uint(i));

case 12:
    return checked_event_forwarding(handler_12.Uint(i));

case 13:
    return checked_event_forwarding(handler_13.Uint(i));

case 14:
    return checked_event_forwarding(handler_14.Uint(i));

case 15:
    return checked_event_forwarding(handler_15.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

case 2:
    return checked_event_forwarding(handler_2.Int64(i));

case 3:
    return checked_event_forwarding(handler_3.Int64(i));

case 4:
    return checked_event_forwarding(handler_4.Int64(i));

case 5:
    return checked_event_forwarding(handler_5.Int64(i));

case 6:
    return checked_event_forwarding(handler_6.Int64(i));

case 7:
    return checked_event_forwarding(handler_7.Int64(i));

case 8:
    return checked_event_forwarding(handler_8.Int64(i));

case 9:
    return checked_event_forwarding(handler_9.Int64(i));

case 10:
    return checked_event_forwarding(handler_10.Int64(i));

case 11:
    return checked_event_forwarding(handler_11.Int64(i));

case 12:
    return checked_event_forwarding(handler_12.Int64(i));

case 13:
    return checked_event_forwarding(handler_13.Int64(i));

case 14:
    return checked_event_forwarding(handler_14.Int64(i));

case 15:
    return checked_event_forwarding(handler_15.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

case 2:
    return checked_event_forwarding(handler_2.Uint64(i));

case 3:
    return checked_event_forwarding(handler_3.Uint64(i));

case 4:
    return checked_event_forwarding(handler_4.Uint64(i));

case 5:
    return checked_event_forwarding(handler_5.Uint64(i));

case 6:
    return checked_event_forwarding(handler_6.Uint64(i));

case 7:
    return checked_event_forwarding(handler_7.Uint64(i));

case 8:
    return checked_event_forwarding(handler_8.Uint64(i));

case 9:
    return checked_event_forwarding(handler_9.Uint64(i));

case 10:
    return checked_event_forwarding(handler_10.Uint64(i));

case 11:
    return checked_event_forwarding(handler_11.Uint64(i));

case 12:
    return checked_event_forwarding(handler_12.Uint64(i));

case 13:
    return checked_event_forwarding(handler_13.Uint64(i));

case 14:
    return checked_event_forwarding(handler_14.Uint64(i));

case 15:
    return checked_event_forwarding(handler_15.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

case 2:
    return checked_event_forwarding(handler_2.Double(d));

case 3:
    return checked_event_forwarding(handler_3.Double(d));

case 4:
    return checked_event_forwarding(handler_4.Double(d));

case 5:
    return checked_event_forwarding(handler_5.Double(d));

case 6:
    return checked_event_forwarding(handler_6.Double(d));

case 7:
    return checked_event_forwarding(handler_7.Double(d));

case 8:
    return checked_event_forwarding(handler_8.Double(d));

case 9:
    return checked_event_forwarding(handler_9.Double(d));

case 10:
    return checked_event_forwarding(handler_10.Double(d));

case 11:
    return checked_event_forwarding(handler_11.Double(d));

case 12:
    return checked_event_forwarding(handler_12.Double(d));

case 13:
    return checked_event_forwarding(handler_13.Double(d));

case 14:
    return checked_event_forwarding(handler_14.Double(d));

case 15:
    return checked_event_forwarding(handler_15.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

case 2:
    return checked_event_forwarding(handler_2.String(str, length, copy));

case 3:
    return checked_event_forwarding(handler_3.String(str, length, copy));

case 4:
    return checked_event_forwarding(handler_4.String(str, length, copy));

case 5:
    return checked_event_forwarding(handler_5.String(str, length, copy));

case 6:
    return checked_event_forwarding(handler_6.String(str, length, copy));

case 7:
    return checked_event_forwarding(handler_7.String(str, length, copy));

case 8:
    return checked_event_forwarding(handler_8.String(str, length, copy));

case 9:
    return checked_event_forwarding(handler_9.String(str, length, copy));

case 10:
    return checked_event_forwarding(handler_10.String(str, length, copy));

case 11:
    return checked_event_forwarding(handler_11.String(str, length, copy));

case 12:
    return checked_event_forwarding(handler_12.String(str, length, copy));

case 13:
    return checked_event_forwarding(handler_13.String(str, length, copy));

case 14:
    return checked_event_forwarding(handler_14.String(str, length, copy));

case 15:
    return checked_event_forwarding(handler_15.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x73\x74\x72\x49\x64", 5))
                         { state=0; has_strId = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x4e\x61\x6d\x65", 7))
                         { state=1; has_strName = true; }
else if (utility::string_equal(str, length, "\x6e\x54\x79\x70\x65", 5))
                         { state=2; has_nType = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x49\x50", 5))
                         { state=3; has_strIP = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x50\x6f\x72\x74", 7))
                         { state=4; has_strPort = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x55\x73\x65\x72", 7))
                         { state=5; has_strUser = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x50\x61\x73\x73\x77\x64", 9))
                         { state=6; has_strPasswd = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x4f\x4e\x56\x49\x46\x41\x64\x64\x72\x65\x73\x73", 15))
                         { state=7; has_strONVIFAddress = true; }
else if (utility::string_equal(str, length, "\x62\x50\x72\x6f\x66\x69\x6c\x65\x54\x6f\x6b\x65\x6e", 13))
                         { state=8; has_bProfileToken = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x50\x72\x6f\x66\x69\x6c\x65\x54\x6f\x6b\x65\x6e\x31", 16))
                         { state=9; has_strProfileToken1 = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x50\x72\x6f\x66\x69\x6c\x65\x54\x6f\x6b\x65\x6e\x32", 16))
                         { state=10; has_strProfileToken2 = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x46\x69\x6c\x65", 7))
                         { state=11; has_strFile = true; }
else if (utility::string_equal(str, length, "\x73\x74\x72\x52\x54\x53\x50\x55\x72\x6c", 10))
                         { state=12; has_strRTSPUrl = true; }
else if (utility::string_equal(str, length, "\x62\x48\x57\x61\x63\x63\x65\x6c", 8))
                         { state=13; has_bHWaccel = true; }
else if (utility::string_equal(str, length, "\x62\x53\x65\x72\x76\x65\x72\x4d\x6f\x74\x69\x6f\x6e", 13))
                         { state=14; has_bServerMotion = true; }
else if (utility::string_equal(str, length, "\x6e\x43\x6f\x6e\x6e\x65\x63\x74\x54\x79\x70\x65", 12))
                         { state=15; has_nConnectType = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

case 2:
    return checked_event_forwarding(handler_2.Key(str, length, copy));

case 3:
    return checked_event_forwarding(handler_3.Key(str, length, copy));

case 4:
    return checked_event_forwarding(handler_4.Key(str, length, copy));

case 5:
    return checked_event_forwarding(handler_5.Key(str, length, copy));

case 6:
    return checked_event_forwarding(handler_6.Key(str, length, copy));

case 7:
    return checked_event_forwarding(handler_7.Key(str, length, copy));

case 8:
    return checked_event_forwarding(handler_8.Key(str, length, copy));

case 9:
    return checked_event_forwarding(handler_9.Key(str, length, copy));

case 10:
    return checked_event_forwarding(handler_10.Key(str, length, copy));

case 11:
    return checked_event_forwarding(handler_11.Key(str, length, copy));

case 12:
    return checked_event_forwarding(handler_12.Key(str, length, copy));

case 13:
    return checked_event_forwarding(handler_13.Key(str, length, copy));

case 14:
    return checked_event_forwarding(handler_14.Key(str, length, copy));

case 15:
    return checked_event_forwarding(handler_15.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

case 2:
    return checked_event_forwarding(handler_2.StartArray());

case 3:
    return checked_event_forwarding(handler_3.StartArray());

case 4:
    return checked_event_forwarding(handler_4.StartArray());

case 5:
    return checked_event_forwarding(handler_5.StartArray());

case 6:
    return checked_event_forwarding(handler_6.StartArray());

case 7:
    return checked_event_forwarding(handler_7.StartArray());

case 8:
    return checked_event_forwarding(handler_8.StartArray());

case 9:
    return checked_event_forwarding(handler_9.StartArray());

case 10:
    return checked_event_forwarding(handler_10.StartArray());

case 11:
    return checked_event_forwarding(handler_11.StartArray());

case 12:
    return checked_event_forwarding(handler_12.StartArray());

case 13:
    return checked_event_forwarding(handler_13.StartArray());

case 14:
    return checked_event_forwarding(handler_14.StartArray());

case 15:
    return checked_event_forwarding(handler_15.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

case 2:
    return checked_event_forwarding(handler_2.EndArray(length));

case 3:
    return checked_event_forwarding(handler_3.EndArray(length));

case 4:
    return checked_event_forwarding(handler_4.EndArray(length));

case 5:
    return checked_event_forwarding(handler_5.EndArray(length));

case 6:
    return checked_event_forwarding(handler_6.EndArray(length));

case 7:
    return checked_event_forwarding(handler_7.EndArray(length));

case 8:
    return checked_event_forwarding(handler_8.EndArray(length));

case 9:
    return checked_event_forwarding(handler_9.EndArray(length));

case 10:
    return checked_event_forwarding(handler_10.EndArray(length));

case 11:
    return checked_event_forwarding(handler_11.EndArray(length));

case 12:
    return checked_event_forwarding(handler_12.EndArray(length));

case 13:
    return checked_event_forwarding(handler_13.EndArray(length));

case 14:
    return checked_event_forwarding(handler_14.EndArray(length));

case 15:
    return checked_event_forwarding(handler_15.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

case 2:
    return checked_event_forwarding(handler_2.StartObject());

case 3:
    return checked_event_forwarding(handler_3.StartObject());

case 4:
    return checked_event_forwarding(handler_4.StartObject());

case 5:
    return checked_event_forwarding(handler_5.StartObject());

case 6:
    return checked_event_forwarding(handler_6.StartObject());

case 7:
    return checked_event_forwarding(handler_7.StartObject());

case 8:
    return checked_event_forwarding(handler_8.StartObject());

case 9:
    return checked_event_forwarding(handler_9.StartObject());

case 10:
    return checked_event_forwarding(handler_10.StartObject());

case 11:
    return checked_event_forwarding(handler_11.StartObject());

case 12:
    return checked_event_forwarding(handler_12.StartObject());

case 13:
    return checked_event_forwarding(handler_13.StartObject());

case 14:
    return checked_event_forwarding(handler_14.StartObject());

case 15:
    return checked_event_forwarding(handler_15.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

case 2:
    return checked_event_forwarding(handler_2.EndObject(length));

case 3:
    return checked_event_forwarding(handler_3.EndObject(length));

case 4:
    return checked_event_forwarding(handler_4.EndObject(length));

case 5:
    return checked_event_forwarding(handler_5.EndObject(length));

case 6:
    return checked_event_forwarding(handler_6.EndObject(length));

case 7:
    return checked_event_forwarding(handler_7.EndObject(length));

case 8:
    return checked_event_forwarding(handler_8.EndObject(length));

case 9:
    return checked_event_forwarding(handler_9.EndObject(length));

case 10:
    return checked_event_forwarding(handler_10.EndObject(length));

case 11:
    return checked_event_forwarding(handler_11.EndObject(length));

case 12:
    return checked_event_forwarding(handler_12.EndObject(length));

case 13:
    return checked_event_forwarding(handler_13.EndObject(length));

case 14:
    return checked_event_forwarding(handler_14.EndObject(length));

case 15:
    return checked_event_forwarding(handler_15.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_strId) set_missing_required("strId");
if (!has_strName) set_missing_required("strName");
if (!has_nType) set_missing_required("nType");
if (!has_strIP) set_missing_required("strIP");
if (!has_strPort) set_missing_required("strPort");
if (!has_strUser) set_missing_required("strUser");
if (!has_strPasswd) set_missing_required("strPasswd");
if (!has_strONVIFAddress) set_missing_required("strONVIFAddress");
if (!has_bProfileToken) set_missing_required("bProfileToken");
if (!has_strProfileToken1) set_missing_required("strProfileToken1");
if (!has_strProfileToken2) set_missing_required("strProfileToken2");
if (!has_strFile) set_missing_required("strFile");
if (!has_strRTSPUrl) set_missing_required("strRTSPUrl");
if (!has_bHWaccel) set_missing_required("bHWaccel");
if (!has_bServerMotion) set_missing_required("bServerMotion");
if (!has_nConnectType) set_missing_required("nConnectType");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;
case 2:
     handler_2.ReapError(errs); break;
case 3:
     handler_3.ReapError(errs); break;
case 4:
     handler_4.ReapError(errs); break;
case 5:
     handler_5.ReapError(errs); break;
case 6:
     handler_6.ReapError(errs); break;
case 7:
     handler_7.ReapError(errs); break;
case 8:
     handler_8.ReapError(errs); break;
case 9:
     handler_9.ReapError(errs); break;
case 10:
     handler_10.ReapError(errs); break;
case 11:
     handler_11.ReapError(errs); break;
case 12:
     handler_12.ReapError(errs); break;
case 13:
     handler_13.ReapError(errs); break;
case 14:
     handler_14.ReapError(errs); break;
case 15:
     handler_15.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();
handler_2.PrepareForReuse();
handler_3.PrepareForReuse();
handler_4.PrepareForReuse();
handler_5.PrepareForReuse();
handler_6.PrepareForReuse();
handler_7.PrepareForReuse();
handler_8.PrepareForReuse();
handler_9.PrepareForReuse();
handler_10.PrepareForReuse();
handler_11.PrepareForReuse();
handler_12.PrepareForReuse();
handler_13.PrepareForReuse();
handler_14.PrepareForReuse();
handler_15.PrepareForReuse();

    }
};

template < class Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879 >
struct Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, ::oapi::OAPICamera > {

    void operator()( Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879& w, const ::oapi::OAPICamera& value) const
    {
        w.StartObject();

        w.Key("\x73\x74\x72\x49\x64", 5, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strId);
w.Key("\x73\x74\x72\x4e\x61\x6d\x65", 7, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strName);
w.Key("\x6e\x54\x79\x70\x65", 5, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, unsigned int >()(w, value.nType);
w.Key("\x73\x74\x72\x49\x50", 5, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strIP);
w.Key("\x73\x74\x72\x50\x6f\x72\x74", 7, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strPort);
w.Key("\x73\x74\x72\x55\x73\x65\x72", 7, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strUser);
w.Key("\x73\x74\x72\x50\x61\x73\x73\x77\x64", 9, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strPasswd);
w.Key("\x73\x74\x72\x4f\x4e\x56\x49\x46\x41\x64\x64\x72\x65\x73\x73", 15, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strONVIFAddress);
w.Key("\x62\x50\x72\x6f\x66\x69\x6c\x65\x54\x6f\x6b\x65\x6e", 13, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, unsigned int >()(w, value.bProfileToken);
w.Key("\x73\x74\x72\x50\x72\x6f\x66\x69\x6c\x65\x54\x6f\x6b\x65\x6e\x31", 16, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strProfileToken1);
w.Key("\x73\x74\x72\x50\x72\x6f\x66\x69\x6c\x65\x54\x6f\x6b\x65\x6e\x32", 16, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strProfileToken2);
w.Key("\x73\x74\x72\x46\x69\x6c\x65", 7, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strFile);
w.Key("\x73\x74\x72\x52\x54\x53\x50\x55\x72\x6c", 10, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, std::string >()(w, value.strRTSPUrl);
w.Key("\x62\x48\x57\x61\x63\x63\x65\x6c", 8, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, unsigned int >()(w, value.bHWaccel);
w.Key("\x62\x53\x65\x72\x76\x65\x72\x4d\x6f\x74\x69\x6f\x6e", 13, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, unsigned int >()(w, value.bServerMotion);
w.Key("\x6e\x43\x6f\x6e\x6e\x65\x63\x74\x54\x79\x70\x65", 12, false); Serializer< Writer91ba8496c1e21b152cd5e401ac4c405a5e2c5dbe074adee1dd87a9ffdeff4879, unsigned int >()(w, value.nConnectType);

        w.EndObject(16);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct OAPICameraListReq {
 bool bAll;
unsigned int nId;

explicit OAPICameraListReq():bAll(), nId() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::OAPICameraListReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< bool > handler_0;
SAXEventHandler< unsigned int > handler_1;bool has_bAll;
bool has_nId;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "bAll";
case 1:
    return "nId";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_bAll = false;
has_nId = false;
    }

public:
    explicit SAXEventHandler( ::oapi::OAPICameraListReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->bAll)
, handler_1(&obj->nId)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x62\x41\x6c\x6c", 4))
                         { state=0; has_bAll = true; }
else if (utility::string_equal(str, length, "\x6e\x49\x64", 3))
                         { state=1; has_nId = true; }
            else {
                state = -1;
                return true;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_bAll) set_missing_required("bAll");
if (!has_nId) set_missing_required("nId");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();

    }
};

template < class Writer4fac81d98ce31b481a6452b58ca8d6da0dfa7f18992a2edf71fb62990e0c075b >
struct Serializer< Writer4fac81d98ce31b481a6452b58ca8d6da0dfa7f18992a2edf71fb62990e0c075b, ::oapi::OAPICameraListReq > {

    void operator()( Writer4fac81d98ce31b481a6452b58ca8d6da0dfa7f18992a2edf71fb62990e0c075b& w, const ::oapi::OAPICameraListReq& value) const
    {
        w.StartObject();

        w.Key("\x62\x41\x6c\x6c", 4, false); Serializer< Writer4fac81d98ce31b481a6452b58ca8d6da0dfa7f18992a2edf71fb62990e0c075b, bool >()(w, value.bAll);
w.Key("\x6e\x49\x64", 3, false); Serializer< Writer4fac81d98ce31b481a6452b58ca8d6da0dfa7f18992a2edf71fb62990e0c075b, unsigned int >()(w, value.nId);

        w.EndObject(2);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct OAPICameraListRsp {
 unsigned int Num;
std::vector<oapi::OAPICamera> list;

explicit OAPICameraListRsp():Num(), list() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::OAPICameraListRsp > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< unsigned int > handler_0;
SAXEventHandler< std::vector<oapi::OAPICamera> > handler_1;bool has_Num;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "Num";
case 1:
    return "list";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_Num = false;

    }

public:
    explicit SAXEventHandler( ::oapi::OAPICameraListRsp * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->Num)
, handler_1(&obj->list)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x4e\x75\x6d", 3))
                         { state=0; has_Num = true; }
else if (utility::string_equal(str, length, "\x6c\x69\x73\x74", 4))
                         { state=1;  }
            else {
                state = -1;
                return true;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_Num) set_missing_required("Num");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();

    }
};

template < class Writer6b6a8f09ce8d82cc3f600098ecbbf38b2b32076e787975f49e27159cb502621c >
struct Serializer< Writer6b6a8f09ce8d82cc3f600098ecbbf38b2b32076e787975f49e27159cb502621c, ::oapi::OAPICameraListRsp > {

    void operator()( Writer6b6a8f09ce8d82cc3f600098ecbbf38b2b32076e787975f49e27159cb502621c& w, const ::oapi::OAPICameraListRsp& value) const
    {
        w.StartObject();

        w.Key("\x4e\x75\x6d", 3, false); Serializer< Writer6b6a8f09ce8d82cc3f600098ecbbf38b2b32076e787975f49e27159cb502621c, unsigned int >()(w, value.Num);
w.Key("\x6c\x69\x73\x74", 4, false); Serializer< Writer6b6a8f09ce8d82cc3f600098ecbbf38b2b32076e787975f49e27159cb502621c, std::vector<oapi::OAPICamera> >()(w, value.list);

        w.EndObject(2);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct StartLiveViewReq {
 std::string strId;
unsigned int nStream;

explicit StartLiveViewReq():strId(), nStream() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::StartLiveViewReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< std::string > handler_0;
SAXEventHandler< unsigned int > handler_1;bool has_strId;
bool has_nStream;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "strId";
case 1:
    return "nStream";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_strId = false;
has_nStream = false;
    }

public:
    explicit SAXEventHandler( ::oapi::StartLiveViewReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->strId)
, handler_1(&obj->nStream)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x73\x74\x72\x49\x64", 5))
                         { state=0; has_strId = true; }
else if (utility::string_equal(str, length, "\x6e\x53\x74\x72\x65\x61\x6d", 7))
                         { state=1; has_nStream = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_strId) set_missing_required("strId");
if (!has_nStream) set_missing_required("nStream");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();

    }
};

template < class Writer3c3fe15275c9834cb49fcb6e4ea9f041c8fd676134b48328fb6e36e8eee45423 >
struct Serializer< Writer3c3fe15275c9834cb49fcb6e4ea9f041c8fd676134b48328fb6e36e8eee45423, ::oapi::StartLiveViewReq > {

    void operator()( Writer3c3fe15275c9834cb49fcb6e4ea9f041c8fd676134b48328fb6e36e8eee45423& w, const ::oapi::StartLiveViewReq& value) const
    {
        w.StartObject();

        w.Key("\x73\x74\x72\x49\x64", 5, false); Serializer< Writer3c3fe15275c9834cb49fcb6e4ea9f041c8fd676134b48328fb6e36e8eee45423, std::string >()(w, value.strId);
w.Key("\x6e\x53\x74\x72\x65\x61\x6d", 7, false); Serializer< Writer3c3fe15275c9834cb49fcb6e4ea9f041c8fd676134b48328fb6e36e8eee45423, unsigned int >()(w, value.nStream);

        w.EndObject(2);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct StopLiveViewReq {
 std::string strId;
unsigned int nStream;

explicit StopLiveViewReq():strId(), nStream() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::StopLiveViewReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< std::string > handler_0;
SAXEventHandler< unsigned int > handler_1;bool has_strId;
bool has_nStream;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "strId";
case 1:
    return "nStream";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_strId = false;
has_nStream = false;
    }

public:
    explicit SAXEventHandler( ::oapi::StopLiveViewReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->strId)
, handler_1(&obj->nStream)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x73\x74\x72\x49\x64", 5))
                         { state=0; has_strId = true; }
else if (utility::string_equal(str, length, "\x6e\x53\x74\x72\x65\x61\x6d", 7))
                         { state=1; has_nStream = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_strId) set_missing_required("strId");
if (!has_nStream) set_missing_required("nStream");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();

    }
};

template < class Writera67fc43c979b39f04c8d3de13a7465d2e2c058d8047e4f0843dfe6a9c31eccdf >
struct Serializer< Writera67fc43c979b39f04c8d3de13a7465d2e2c058d8047e4f0843dfe6a9c31eccdf, ::oapi::StopLiveViewReq > {

    void operator()( Writera67fc43c979b39f04c8d3de13a7465d2e2c058d8047e4f0843dfe6a9c31eccdf& w, const ::oapi::StopLiveViewReq& value) const
    {
        w.StartObject();

        w.Key("\x73\x74\x72\x49\x64", 5, false); Serializer< Writera67fc43c979b39f04c8d3de13a7465d2e2c058d8047e4f0843dfe6a9c31eccdf, std::string >()(w, value.strId);
w.Key("\x6e\x53\x74\x72\x65\x61\x6d", 7, false); Serializer< Writera67fc43c979b39f04c8d3de13a7465d2e2c058d8047e4f0843dfe6a9c31eccdf, unsigned int >()(w, value.nStream);

        w.EndObject(2);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct PlaybackReq {
 std::string strId;
unsigned int nPlayTime;

explicit PlaybackReq():strId(), nPlayTime() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::PlaybackReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< std::string > handler_0;
SAXEventHandler< unsigned int > handler_1;bool has_strId;
bool has_nPlayTime;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "strId";
case 1:
    return "nPlayTime";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_strId = false;
has_nPlayTime = false;
    }

public:
    explicit SAXEventHandler( ::oapi::PlaybackReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->strId)
, handler_1(&obj->nPlayTime)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

case 1:
    return checked_event_forwarding(handler_1.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

case 1:
    return checked_event_forwarding(handler_1.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

case 1:
    return checked_event_forwarding(handler_1.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

case 1:
    return checked_event_forwarding(handler_1.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

case 1:
    return checked_event_forwarding(handler_1.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

case 1:
    return checked_event_forwarding(handler_1.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

case 1:
    return checked_event_forwarding(handler_1.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x73\x74\x72\x49\x64", 5))
                         { state=0; has_strId = true; }
else if (utility::string_equal(str, length, "\x6e\x50\x6c\x61\x79\x54\x69\x6d\x65", 9))
                         { state=1; has_nPlayTime = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

case 1:
    return checked_event_forwarding(handler_1.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

case 1:
    return checked_event_forwarding(handler_1.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

case 1:
    return checked_event_forwarding(handler_1.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

case 1:
    return checked_event_forwarding(handler_1.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

case 1:
    return checked_event_forwarding(handler_1.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_strId) set_missing_required("strId");
if (!has_nPlayTime) set_missing_required("nPlayTime");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;
case 1:
     handler_1.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();
handler_1.PrepareForReuse();

    }
};

template < class Writer507d18937c354bd3b0ce5600968c7938e819382bb4fb3f18119cb78980c31ad2 >
struct Serializer< Writer507d18937c354bd3b0ce5600968c7938e819382bb4fb3f18119cb78980c31ad2, ::oapi::PlaybackReq > {

    void operator()( Writer507d18937c354bd3b0ce5600968c7938e819382bb4fb3f18119cb78980c31ad2& w, const ::oapi::PlaybackReq& value) const
    {
        w.StartObject();

        w.Key("\x73\x74\x72\x49\x64", 5, false); Serializer< Writer507d18937c354bd3b0ce5600968c7938e819382bb4fb3f18119cb78980c31ad2, std::string >()(w, value.strId);
w.Key("\x6e\x50\x6c\x61\x79\x54\x69\x6d\x65", 9, false); Serializer< Writer507d18937c354bd3b0ce5600968c7938e819382bb4fb3f18119cb78980c31ad2, unsigned int >()(w, value.nPlayTime);

        w.EndObject(2);
    }

};
}


// The MIT License (MIT)
//
// Copyright (c) 2014 Siyuan Ren (netheril96@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <autojsoncxx/autojsoncxx.hpp>

// The comments are reserved for replacement
// such syntax is chosen so that the template file looks like valid C++

namespace oapi { struct PlaybackSeekReq {
 unsigned int nPlayTime;

explicit PlaybackSeekReq():nPlayTime() {  }


 
}; }


namespace autojsoncxx {

template <>
class SAXEventHandler< ::oapi::PlaybackSeekReq > {
private:
    utility::scoped_ptr<error::ErrorBase> the_error;
    int state;
    int depth;

    SAXEventHandler< unsigned int > handler_0;bool has_nPlayTime;

    bool check_depth(const char* type)
    {
        if (depth <= 0) {
            the_error.reset(new error::TypeMismatchError("object", type));
            return false;
        }
        return true;
    }

    const char* current_member_name() const
    {
        switch (state) {
            case 0:
    return "nPlayTime";
        default:
            break;
        }
        return "<UNKNOWN>";
    }

    bool checked_event_forwarding(bool success)
    {
        if (!success)
            the_error.reset(new error::ObjectMemberError(current_member_name()));
        return success;
    }

    void set_missing_required(const char* name)
    {
        if (the_error.empty() || the_error->type() != error::MISSING_REQUIRED)
            the_error.reset(new error::RequiredFieldMissingError());

        std::vector<std::string>& missing =
            static_cast<error::RequiredFieldMissingError*>(the_error.get())->missing_members();

        missing.push_back(name);
    }

    void reset_flags()
    {
        has_nPlayTime = false;
    }

public:
    explicit SAXEventHandler( ::oapi::PlaybackSeekReq * obj)
        : state(-1)
        , depth(0)
        , handler_0(&obj->nPlayTime)
    {
        reset_flags();
    }

    bool Null()
    {
        if (!check_depth("null"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Null());

        default:
            break;
        }
        return true;
    }

    bool Bool(bool b)
    {
        if (!check_depth("bool"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Bool(b));

        default:
            break;
        }
        return true;
    }

    bool Int(int i)
    {
        if (!check_depth("int"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int(i));

        default:
            break;
        }
        return true;
    }

    bool Uint(unsigned i)
    {
        if (!check_depth("unsigned"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint(i));

        default:
            break;
        }
        return true;
    }

    bool Int64(utility::int64_t i)
    {
        if (!check_depth("int64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Int64(i));

        default:
            break;
        }
        return true;
    }

    bool Uint64(utility::uint64_t i)
    {
        if (!check_depth("uint64_t"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Uint64(i));

        default:
            break;
        }
        return true;
    }

    bool Double(double d)
    {
        if (!check_depth("double"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.Double(d));

        default:
            break;
        }
        return true;
    }

    bool String(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("string"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.String(str, length, copy));

        default:
            break;
        }
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy)
    {
        if (!check_depth("object"))
            return false;

        if (depth == 1) {
            if (0) {
            }
            else if (utility::string_equal(str, length, "\x6e\x50\x6c\x61\x79\x54\x69\x6d\x65", 9))
                         { state=0; has_nPlayTime = true; }
            else {
                state = -1;
                the_error.reset(new error::UnknownFieldError(str, length)); return false;
            }

        } else {
            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.Key(str, length, copy));

            default:
                break;
            }
        }
        return true;
    }

    bool StartArray()
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.StartArray());

        default:
            break;
        }
        return true;
    }

    bool EndArray(SizeType length)
    {
        if (!check_depth("array"))
            return false;

        switch (state) {

        case 0:
    return checked_event_forwarding(handler_0.EndArray(length));

        default:
            break;
        }
        return true;
    }

    bool StartObject()
    {
        ++depth;
        if (depth > 1) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.StartObject());

            default:
                break;
            }
        }
        return true;
    }

    bool EndObject(SizeType length)
    {
        --depth;
        if (depth > 0) {

            switch (state) {

            case 0:
    return checked_event_forwarding(handler_0.EndObject(length));

            default:
                break;
            }
        } else {
            if (!has_nPlayTime) set_missing_required("nPlayTime");
        }
        return the_error.empty();
    }

    bool HasError() const
    {
        return !this->the_error.empty();
    }

    bool ReapError(error::ErrorStack& errs)
    {
        if (this->the_error.empty())
            return false;

        errs.push(this->the_error.release());

        switch (state) {

        case 0:
     handler_0.ReapError(errs); break;

        default:
            break;
        }

        return true;
    }

    void PrepareForReuse()
    {
        depth = 0;
        state = -1;
        the_error.reset();
        reset_flags();
        handler_0.PrepareForReuse();

    }
};

template < class Writer95e9854e91469639b60cc7f92de9dc1e244cc7407de8d1b66fe8e9326742c044 >
struct Serializer< Writer95e9854e91469639b60cc7f92de9dc1e244cc7407de8d1b66fe8e9326742c044, ::oapi::PlaybackSeekReq > {

    void operator()( Writer95e9854e91469639b60cc7f92de9dc1e244cc7407de8d1b66fe8e9326742c044& w, const ::oapi::PlaybackSeekReq& value) const
    {
        w.StartObject();

        w.Key("\x6e\x50\x6c\x61\x79\x54\x69\x6d\x65", 9, false); Serializer< Writer95e9854e91469639b60cc7f92de9dc1e244cc7407de8d1b66fe8e9326742c044, unsigned int >()(w, value.nPlayTime);

        w.EndObject(1);
    }

};
}


