`gendef -f C:\Windows\System32\version.dll`

```sh
clang++ -std=c++20 -O3 -ffast-math -Wall -shared -m32  -IDetours/src desperadoo.cpp Detours/src/creatwth.cpp Detours/src/detours.cpp Detours/src/disasm.cpp Detours/src/image.cpp  Detours/src/modules.cpp -o version.dll -DUNICODE -D_WIN32_WINNT=0x0601
```
OR
```sh
git clone https://github.com/tsubakigal/desperadoo.git
cd desperadoo
git submodule update --init --recursive --depth 1
cmake -B build -A win32
cmake --build build --config Release
```

<!--
`dumpbin /EXPORTS version.dll >version.txt`
C:\Program Files\Microsoft Visual Studio\18\Insiders>
-->
