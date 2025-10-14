#include <cassert>
#include <windows.h>
// Ensure `windows.h` is included before `detours.h`.
#include <detours.h>

static HMODULE hModule;

FARPROC WINAPI GetAddress(PCSTR lpProcName) {
    FARPROC fpAddress = GetProcAddress(hModule, lpProcName);
    assert(fpAddress);
    return fpAddress;
}

// Just for code folding :(
inline namespace {

inline namespace detour {

#define FORDETOUR(sar, b) ((PVOID *)&(sar)), ((PVOID)(b))

void Attach(PVOID *ppPointer, PVOID pDetour) {
    DetourUpdateThread(GetCurrentThread());
    DetourTransactionBegin();
    DetourAttach(ppPointer, pDetour);
    DetourTransactionCommit();
}

void Detach(PVOID *ppPointer, PVOID pDetour) {
    DetourUpdateThread(GetCurrentThread());
    DetourTransactionBegin();
    DetourDetach(ppPointer, pDetour);
    DetourTransactionCommit();
}

} // namespace detour

inline namespace version {

// clang-format off
#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=@ForwardGetFileVersionInfoA@0,@1")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=@ForwardGetFileVersionInfoByHandle@0,@2")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=@ForwardGetFileVersionInfoExA@0,@3")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=@ForwardGetFileVersionInfoExW@0,@4")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=@ForwardGetFileVersionInfoSizeA@0,@5")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=@ForwardGetFileVersionInfoSizeExA@0,@6")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=@ForwardGetFileVersionInfoSizeExW@0,@7")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=@ForwardGetFileVersionInfoSizeW@0,@8")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=@ForwardGetFileVersionInfoW@0,@9")
#pragma comment(linker, "/EXPORT:VerFindFileA=@ForwardVerFindFileA@0,@10")
#pragma comment(linker, "/EXPORT:VerFindFileW=@ForwardVerFindFileW@0,@11")
#pragma comment(linker, "/EXPORT:VerInstallFileA=@ForwardVerInstallFileA@0,@12")
#pragma comment(linker, "/EXPORT:VerInstallFileW=@ForwardVerInstallFileW@0,@13")
#pragma comment(linker, "/EXPORT:VerLanguageNameA=@ForwardVerLanguageNameA@0,@14")
#pragma comment(linker, "/EXPORT:VerLanguageNameW=@ForwardVerLanguageNameW@0,@15")
#pragma comment(linker, "/EXPORT:VerQueryValueA=@ForwardVerQueryValueA@0,@16")
#pragma comment(linker, "/EXPORT:VerQueryValueW=@ForwardVerQueryValueW@0,@17")
// clang-format on

static PVOID OriginGetFileVersionInfoA;
static PVOID OriginGetFileVersionInfoByHandle;
static PVOID OriginGetFileVersionInfoExA;
static PVOID OriginGetFileVersionInfoExW;
static PVOID OriginGetFileVersionInfoSizeA;
static PVOID OriginGetFileVersionInfoSizeExA;
static PVOID OriginGetFileVersionInfoSizeExW;
static PVOID OriginGetFileVersionInfoSizeW;
static PVOID OriginGetFileVersionInfoW;
static PVOID OriginVerFindFileA;
static PVOID OriginVerFindFileW;
static PVOID OriginVerInstallFileA;
static PVOID OriginVerInstallFileW;
static PVOID OriginVerLanguageNameA;
static PVOID OriginVerLanguageNameW;
static PVOID OriginVerQueryValueA;
static PVOID OriginVerQueryValueW;

extern "C" __declspec(naked) void __fastcall ForwardGetFileVersionInfoA() {
    __asm jmp OriginGetFileVersionInfoA
}
extern "C"
    __declspec(naked) void __fastcall ForwardGetFileVersionInfoByHandle() {
    __asm jmp OriginGetFileVersionInfoByHandle
}
extern "C" __declspec(naked) void __fastcall ForwardGetFileVersionInfoExA() {
    __asm jmp OriginGetFileVersionInfoExA
}
extern "C" __declspec(naked) void __fastcall ForwardGetFileVersionInfoExW() {
    __asm jmp OriginGetFileVersionInfoExW
}
extern "C" __declspec(naked) void __fastcall ForwardGetFileVersionInfoSizeA() {
    __asm jmp OriginGetFileVersionInfoSizeA
}
extern "C"
    __declspec(naked) void __fastcall ForwardGetFileVersionInfoSizeExA() {
    __asm jmp OriginGetFileVersionInfoSizeExA
}
extern "C"
    __declspec(naked) void __fastcall ForwardGetFileVersionInfoSizeExW() {
    __asm jmp OriginGetFileVersionInfoSizeExW
}
extern "C" __declspec(naked) void __fastcall ForwardGetFileVersionInfoSizeW() {
    __asm jmp OriginGetFileVersionInfoSizeW
}
extern "C" __declspec(naked) void __fastcall ForwardGetFileVersionInfoW() {
    __asm jmp OriginGetFileVersionInfoW
}
extern "C" __declspec(naked) void __fastcall ForwardVerFindFileA() {
    __asm jmp OriginVerFindFileA
}
extern "C" __declspec(naked) void __fastcall ForwardVerFindFileW() {
    __asm jmp OriginVerFindFileW
}
extern "C" __declspec(naked) void __fastcall ForwardVerInstallFileA() {
    __asm jmp OriginVerInstallFileA
}
extern "C" __declspec(naked) void __fastcall ForwardVerInstallFileW() {
    __asm jmp OriginVerInstallFileW
}
extern "C" __declspec(naked) void __fastcall ForwardVerLanguageNameA() {
    __asm jmp OriginVerLanguageNameA
}
extern "C" __declspec(naked) void __fastcall ForwardVerLanguageNameW() {
    __asm jmp OriginVerLanguageNameW
}
extern "C" __declspec(naked) void __fastcall ForwardVerQueryValueA() {
    __asm jmp OriginVerQueryValueA
}
extern "C" __declspec(naked) void __fastcall ForwardVerQueryValueW() {
    __asm jmp OriginVerQueryValueW
}

void forward() {
    OriginGetFileVersionInfoA = GetAddress("GetFileVersionInfoA");
    OriginGetFileVersionInfoByHandle = GetAddress("GetFileVersionInfoByHandle");
    OriginGetFileVersionInfoExA = GetAddress("GetFileVersionInfoExA");
    OriginGetFileVersionInfoExW = GetAddress("GetFileVersionInfoExW");
    OriginGetFileVersionInfoSizeA = GetAddress("GetFileVersionInfoSizeA");
    OriginGetFileVersionInfoSizeExA = GetAddress("GetFileVersionInfoSizeExA");
    OriginGetFileVersionInfoSizeExW = GetAddress("GetFileVersionInfoSizeExW");
    OriginGetFileVersionInfoSizeW = GetAddress("GetFileVersionInfoSizeW");
    OriginGetFileVersionInfoW = GetAddress("GetFileVersionInfoW");
    OriginVerFindFileA = GetAddress("VerFindFileA");
    OriginVerFindFileW = GetAddress("VerFindFileW");
    OriginVerInstallFileA = GetAddress("VerInstallFileA");
    OriginVerInstallFileW = GetAddress("VerInstallFileW");
    OriginVerLanguageNameA = GetAddress("VerLanguageNameA");
    OriginVerLanguageNameW = GetAddress("VerLanguageNameW");
    OriginVerQueryValueA = GetAddress("VerQueryValueA");
    OriginVerQueryValueW = GetAddress("VerQueryValueW");
}
} // namespace version

} // namespace

struct sarcheck {
    char *name;
    void *mz;
    uint32_t size;
};

// Original
auto OriginVirtualAlloc = VirtualAlloc;
// Hooked
LPVOID
WINAPI
HookVirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType,
                 DWORD flProtect) {
    LPVOID result =
        OriginVirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);
    if ((uint32_t)lpAddress == 0x10000000) {
        uint32_t *ebp_now = 0;
        __asm {
        mov eax, ebp
        mov ebp_now, eax
        }
        // for `C6011` Warning
        if (ebp_now == 0) {
            return result;
        }
        if (!*ebp_now) {
            return result;
        }

        sarcheck *sar = *(sarcheck **)((*ebp_now) + 8);
        if (!sar) {
            return result;
        }
        void *base = sar->mz;
        if (!base) {
            return result;
        }
        IMAGE_DOS_HEADER *dos = (IMAGE_DOS_HEADER *)(base);
        IMAGE_NT_HEADERS *nt =
            (IMAGE_NT_HEADERS *)((BYTE *)base + dos->e_lfanew);
        WORD count = nt->FileHeader.NumberOfSections;

        IMAGE_SECTION_HEADER *section = IMAGE_FIRST_SECTION(nt);
        IMAGE_SECTION_HEADER *sec = &section[count - 1];
        DWORD size = sec->PointerToRawData;

        if (*(DWORD *)(size + (DWORD)base) == 0x5004EC83) {
            *(DWORD *)(size + (DWORD)base) = 0x90000CC2;
            Detach(FORDETOUR(OriginVirtualAlloc, HookVirtualAlloc));
        }
    }
    return result;
}

void load() {
    Attach(FORDETOUR(OriginVirtualAlloc, HookVirtualAlloc));
    wchar_t sysPath[MAX_PATH];
    UINT len = GetSystemDirectoryW(sysPath, MAX_PATH);
    lstrcatW(sysPath, L"\\version.dll");
    hModule = LoadLibraryW(sysPath);
    if (hModule) {
        forward();
    }
}

BOOL APIENTRY DllMain(HMODULE _hModule, DWORD fdwReason, LPVOID lpReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH: {
        load();
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH: {
        FreeLibrary(hModule);
        break;
    }
    }
    return TRUE;
}
