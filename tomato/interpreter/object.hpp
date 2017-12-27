#ifndef TOMATO_RUNTIME_OBJECT_HPP
#define TOMATO_RUNTIME_OBJECT_HPP


#include <any>

#include "semantic/symtab.hpp"


namespace Tomato::Runtime
{
    class Object
    {
    public:
        explicit Object(Semantic::Symbol type);
        virtual ~Object() = default; // make Object polymorphic type

        Semantic::Symbol type;
    };

    template <typename T>
    class Scalar : public Object
    {
    public:
        Scalar(Semantic::Symbol type, const T &value);

        T value;
    };

    extern template class Scalar<int>;
    extern template class Scalar<float>;
    extern template class Scalar<bool>;
}


#endif //TOMATOLANG_OBJECT_HPP