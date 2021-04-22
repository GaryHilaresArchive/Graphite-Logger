#include <vector>
#include <sstream>

namespace GraphiteLogger
{
    namespace __hidden__
    {
        template <int I> struct choice : choice<I+1> {};
        template <> struct choice<10> {};

        template <class T> std::string convertToString(T const& t);

        template <typename T>
        auto convertToStringHelper(T const& t, choice<0>) -> decltype(std::to_string(t))
        {
            return std::to_string(t);
        }
        template <class T>
        auto convertToStringHelper(T const& t, choice<1>) -> decltype(std::string(t))
        {
            return std::string(t);
        }
        template <class T, class A>
        std::string convertToStringHelper(std::vector<T,A> const& v, choice<2> )
        {
            if(v.empty())
                return "{}";
            if(convertToString(v[0]) == "Not representable")
                return "Not representable";
            std::string str;
            str += "{";
            for(unsigned int i = 0; i < v.size(); i++)
            {
                str += convertToString(v[i]);
                if(i != v.size() - 1)
                    str += ", ";
            }
            str += "}";
            std::ostringstream stream;
            return str;
        }
        template <class T>
        std::string convertToStringHelper(T* t, choice<3>)
        {
            if(t == nullptr)
                return "nullptr";
            std::stringstream ss;
            std::string str;
            ss << t;
            ss >> str;
            return str;
        }
        template<class T>
        std::string convertToStringHelper(T const& t, choice<4>)
        {
            std::ostringstream ss;
            ss << t;
            return ss.str();
        }
        template <class T>
        std::string convertToStringHelper(T const& t, choice<5>)
        {
            return "Not representable";
        }
        template <typename T>
        std::string convertToString(T const& t) {
            return convertToStringHelper(t, choice<0>{});
        }

    }
}
