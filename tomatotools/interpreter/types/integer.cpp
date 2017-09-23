#include "integer.hpp"
#include "float.hpp"
#include "bool.hpp"
#include "interpreter/interpreter.hpp"

#include <cmath>


using namespace Tomato;


int ipow(int base, int exp)
{
    if (exp < 0)
        throw InterpretationError("Negative integer exponentiation.");

    int pow = 1;

    for (int i = 0; i < exp; ++i)
    {
        pow *= base;
    }

    return pow;
}

Integer::Integer(int value) : value(value) {}


void Integer::assign(const Object &object)
{
    if (!object.is_instance<Integer>())
    {
        auto type_name = typeid(object).name();
        throw TypeError(CodePoint(), "Integer expected, got "s + type_name + " instead"s);
    }

    value = object.as<Integer>().value;
}


std::string Integer::str()
{
    return std::to_string(value);
}


Object::Ref Integer::add(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Integer>(value + object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Float>(value + object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::sub(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Integer>(value - object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Float>(value - object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::mul(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Integer>(value * object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Float>(value * object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::div(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Float>(float(value) / object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Float>(value / object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::exp(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Integer>(ipow(value, object.as<Integer>().value));

    else if (object.is_instance<Float>())
        return std::make_shared<Float>(std::pow(float(value), object.as<Float>().value));

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::un_minus()
{
    return std::make_shared<Integer>(-value);
}


Object::Ref Integer::un_plus()
{
    return std::make_shared<Integer>(+value);
}


Object::Ref Integer::lt(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Bool>(value < object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Bool>(value < object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::gt(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Bool>(value > object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Bool>(value > object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::le(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Bool>(value <= object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Bool>(value <= object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::ge(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Bool>(value >= object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Bool>(value >= object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::eq(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Bool>(value == object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Bool>(value == object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}


Object::Ref Integer::ne(const Object &object)
{
    if (object.is_instance<Integer>())
        return std::make_shared<Bool>(value != object.as<Integer>().value);

    else if (object.is_instance<Float>())
        return std::make_shared<Bool>(value != object.as<Float>().value);

    else
        throw TypeError(CodePoint(), "");
}