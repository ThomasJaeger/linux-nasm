%ifndef __NASMX_WSOCK32_INC__
%define __NASMX_WSOCK32_INC__

IMPORT AcceptEx, 32
IMPORT EnumProtocolsA, 12
IMPORT EnumProtocolsW, 12
IMPORT GetAcceptExSockaddrs, 32
IMPORT GetAddressByNameA, 40
IMPORT GetAddressByNameW, 40
IMPORT GetNameByTypeA, 12
IMPORT GetNameByTypeW, 12
IMPORT GetServiceA, 28
IMPORT GetServiceW, 28
IMPORT GetTypeByNameA, 8
IMPORT GetTypeByNameW, 8
IMPORT MigrateWinsockConfiguration, 12
IMPORT NPLoadNameSpaces, 12
IMPORT SetServiceA, 24
IMPORT SetServiceW, 24
IMPORT TransmitFile, 28
IMPORT WEP, 0
IMPORT WSAAsyncGetHostByAddr, 28
IMPORT WSAAsyncGetHostByName, 20
IMPORT WSAAsyncGetProtoByName, 20
IMPORT WSAAsyncGetProtoByNumber, 20
IMPORT WSAAsyncGetServByName, 24
IMPORT WSAAsyncGetServByPort, 24
IMPORT WSAAsyncSelect, 16
IMPORT WSACancelAsyncRequest, 4
IMPORT WSACancelBlockingCall, 0
IMPORT WSACleanup, 0
IMPORT WSAGetLastError, 0
IMPORT WSAIsBlocking, 0
IMPORT WSARecvEx, 16
IMPORT WSASetBlockingHook, 4
IMPORT WSASetLastError, 4
IMPORT WSAStartup, 8
IMPORT WSAUnhookBlockingHook, 0
IMPORT __WSAFDIsSet, 8
IMPORT accept, 12
IMPORT bind, 12
IMPORT closesocket, 4
IMPORT connect, 12
IMPORT dn_expand, 20
IMPORT gethostbyaddr, 12
IMPORT gethostbyname, 4
IMPORT gethostname, 8
IMPORT getnetbyname, 4
IMPORT getpeername, 12
IMPORT getprotobyname, 4
IMPORT getprotobynumber, 4
IMPORT getservbyname, 8
IMPORT getservbyport, 8
IMPORT getsockname, 12
IMPORT getsockopt, 20
;IMPORT htonl, 4
;IMPORT htons, 4
IMPORT inet_addr, 4
IMPORT inet_network, 4
IMPORT inet_ntoa, 4
IMPORT ioctlsocket, 12
IMPORT listen, 8
IMPORT ntohl, 4
IMPORT ntohs, 4
IMPORT rcmd, 24
IMPORT recv, 16
IMPORT recvfrom, 24
IMPORT rexec, 24
IMPORT rresvport, 4
IMPORT s_perror, 8
IMPORT select, 20
IMPORT send, 16
IMPORT sendto, 24
IMPORT sethostname, 8
IMPORT setsockopt, 20
IMPORT shutdown, 8
IMPORT socket, 12

%ifdef UNICODE

%define EnumProtocols EnumProtocolsW
%define GetAddressByName GetAddressByNameW
%define GetNameByType GetNameByTypeW
%define GetService GetServiceW
%define GetTypeByName GetTypeByNameW
%define SetService SetServiceW

%else  ;// ANSI

%define EnumProtocols EnumProtocolsA
%define GetAddressByName GetAddressByNameA
%define GetNameByType GetNameByTypeA
%define GetService GetServiceA
%define GetTypeByName GetTypeByNameA
%define SetService SetServiceA

%endif  ;// UNICODE

%endif  ;// __NASMX_WSOCK32_INC__