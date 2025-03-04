#pragma once

#include "../core.h"

namespace kanistra {
    namespace net {
        enum class send_type : int {
            stream    = SOCK_STREAM,
            dgram     = SOCK_DGRAM,
            seqpacket = SOCK_SEQPACKET,
            RAW       = SOCK_RAW,
            RDM       = SOCK_RDM
        };

        class sntype {
        private:
            send_type tp;
        public:
            sntype(const sntype& tp) { *this = tp; }
            sntype(const send_type tp) { *this = tp; }

            sntype operator=(const sntype& tp) {
                set_type(tp);
                return *this;
            }
            sntype operator=(const send_type tp) {
                set_type(tp);
                return *this;
            }

            void set_type(const sntype& tp)   { this->tp = tp.tp; }
            void set_type(const send_type tp) { this->tp = tp; }
        
            operator send_type() { return tp; }
            operator int() { return (int)tp; }
        };

        enum class protocol_type : int {
            TCP = IPPROTO_TCP, 
            UDP = IPPROTO_UDP
        };

        class snproto {
            private:
            protocol_type proto;
        public:
            snproto(const sntype& proto) { *this = proto; }
            snproto(const send_type proto) { *this = proto; }

            snproto operator=(const sntype& tp) {
                set_type(tp);
                return *this;
            }
            snproto operator=(const send_type tp) {
                set_type(tp);
                return *this;
            }

            void set_type(const snproto& proto)      { this->proto = proto.proto; }
            void set_type(const protocol_type proto) { this->proto = proto; }
        
            operator protocol_type() { return proto; }
            operator int() { return (int)proto; }
        };
    }
}
