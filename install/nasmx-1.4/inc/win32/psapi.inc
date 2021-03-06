%ifndef __NASMX_PSAPI_INC__
%define __NASMX_PSAPI_INC__

IMPORT EmptyWorkingSet, 4
IMPORT EnumDeviceDrivers, 12
IMPORT EnumPageFilesA, 8
IMPORT EnumPageFilesW, 8
IMPORT EnumProcessModules, 16
IMPORT EnumProcesses, 12
IMPORT GetDeviceDriverBaseNameA, 12
IMPORT GetDeviceDriverBaseNameW, 12
IMPORT GetDeviceDriverFileNameA, 12
IMPORT GetDeviceDriverFileNameW, 12
IMPORT GetMappedFileNameA, 16
IMPORT GetMappedFileNameW, 16
IMPORT GetModuleBaseNameA, 16
IMPORT GetModuleBaseNameW, 16
IMPORT GetModuleFileNameExA, 16
IMPORT GetModuleFileNameExW, 16
IMPORT GetModuleInformation, 16
IMPORT GetPerformanceInfo, 8
IMPORT GetProcessImageFileNameA, 12
IMPORT GetProcessImageFileNameW, 12
IMPORT GetProcessMemoryInfo, 12
IMPORT GetWsChanges, 12
IMPORT InitializeProcessForWsWatch, 4
IMPORT QueryWorkingSet, 12
IMPORT QueryWorkingSetEx, 12

%ifdef UNICODE

%define EnumPageFiles EnumPageFilesW
%define GetDeviceDriverBaseName GetDeviceDriverBaseNameW
%define GetDeviceDriverFileName GetDeviceDriverFileNameW
%define GetMappedFileName GetMappedFileNameW
%define GetModuleBaseName GetModuleBaseNameW
%define GetModuleFileNameEx GetModuleFileNameExW
%define GetProcessImageFileName GetProcessImageFileNameW

%else  ;// ANSI

%define EnumPageFiles EnumPageFilesW
%define GetDeviceDriverBaseName GetDeviceDriverBaseNameW
%define GetDeviceDriverFileName GetDeviceDriverFileNameW
%define GetMappedFileName GetMappedFileNameW
%define GetModuleBaseName GetModuleBaseNameW
%define GetModuleFileNameEx GetModuleFileNameExW
%define GetProcessImageFileName GetProcessImageFileNameW

%endif  ;// UNICODE

%endif  ;// __NASMX_PSAPI_INC__
