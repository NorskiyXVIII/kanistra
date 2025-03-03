#pragma once

#include <iostream>
#include <cstdlib>
#include "types.h"

namespace kanistra {
    namespace type {
        template<typename T>
        class opt {
        private:
            T val;
            bool is_null = true;
        public:
            opt(const T& val) {
                set_val(val);
            }
            opt(const opt& val) {
                set_val(val);
            }
            opt(const char* val) {
                this->val = val;
                this->is_null = false;
            }
            opt() {}

            opt operator=(const T& val) {
                set_val(val);
                return *this;
            }
            opt operator=(const opt& val) {
                set_val(val);
                return *this;
            }

            void set_val(const T& val) {
                this->val = (T)val;
                this->is_null = false;
            }
            void set_val(const opt& val) {
                *this = val;
                this->is_null = false;
            }


            T get_val() const {
                if (!is_null) { return val; }
                
                std::fprintf(stderr, "Warning: using opt with null = true\n");
                return T();
            }
            
            operator T() const {
                if (is_null) std::fprintf(stderr, "Warning: using opt with null = true\n");
                return get_val();
            }

        };

        template<typename T>
        class sopt {
        private:
            T val;
            bool is_null = true;
        public:
            sopt(const T& val) {
                set_val(val);
            }
            sopt(const sopt& val) {
                set_val(val);
            }
            sopt(const char* val) {
                this->val = val;
                this->is_null = false;
            }
            sopt() {}

            sopt operator=(const T& val) {
                set_val(val);
                return *this;
            }
            sopt operator=(const sopt& val) {
                set_val(val);
                return *this;
            }

            void set_val(const T& val) {
                this->val = (T)val;
                this->is_null = false;
            }
            void set_val(const sopt& val) {
                *this = val;
                this->is_null = false;
            }


            T get_val() const {
                if (!is_null) { return val; }
                
                std::fprintf(stderr, "Error: using opt with null = true\n");
                exit(1); // kanistra::os::exit
                return T();
            }
            
            operator T() const {
                if (is_null) std::fprintf(stderr, "Error: using opt with null = true\n");
                exit(1); // kanistra::os::exit
                return get_val();
            }
        };

        template<typename T, u64 sz>
        class opt<T[sz]> {
        private:
            T val[sz];
            bool is_null = true;
        public:
            opt(const T (&val)[sz]) {
                set_val(val);
            }
            opt(const opt& val) {
                set_val(val);
            }
            opt() {}

            auto& operator[](size_t indx) const {
                return this->val[indx];
            }

            opt operator=(const T (&val)[sz]) {
                set_val(val);
                return *this;
            }
            opt operator=(const opt& val) {
                set_val(val);
                return *this;
            }

            void set_val(const T (&val)[sz]) {
                for (u64 i = 0; i < sz; i++) this->val[i] = val[i];
                this->is_null = false;
            }
            void set_val(const opt& val) {
                *this = val;
                this->is_null = false;
            }


            T get_val() const {
                if (!is_null) { return val; }
                
                std::fprintf(stderr, "Warning: using opt with null = true\n");
                return T();
            }
            
            operator T*() const {
                if (is_null) std::fprintf(stderr, "Warning: using opt with null = true\n");
                return *val;
            }

        };

        template<typename T, u64 sz>
        class sopt<T[sz]> {
        private:
            T val[sz];
            bool is_null = true;
        public:
            sopt(const T (&val)[sz]) {
                set_val(val);
            }
            sopt(const sopt& val) {
                set_val(val);
            }
            sopt() {}

            auto& operator[](size_t indx) const {
                return this->val[indx];
            }

            sopt operator=(const T (&val)[sz]) {
                set_val(val);
                return *this;
            }
            sopt operator=(const sopt& val) {
                set_val(val);
                return *this;
            }

            void set_val(const T (&val)[sz]) {
                for (u64 i = 0; i < sz; i++) this->val[i] = val[i];
                this->is_null = false;
            }
            void set_val(const sopt& val) {
                *this = val;
                this->is_null = false;
            }


            T get_val() const {
                if (!is_null) { return val; }
                
                std::fprintf(stderr, "Warning: using opt with null = true\n");
                return T();
            }
            
            operator T*() const {
                if (is_null) std::fprintf(stderr, "Warning: using opt with null = true\n");
                return *val;
            }

        };

        using optfault = int;
        constexpr optfault nullopt = 0;
    }
}
