def extract_strings(filepath):
    collected = []
    start_collecting = False
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            line = line.rstrip('\n') 
            stripped_line = line.strip()
            if stripped_line == "EXPORTS":
                start_collecting = True
                continue

            if start_collecting:
                if " " in line:
                    part = line.split(" ")[0]
                else:
                    part = stripped_line
                if part:
                    collected.append(part)
    return collected

input_file = "version.def" 
result = extract_strings(input_file)
pragma=[]
extern=[]
static=[]
forwards=[]

for i, s in enumerate(result, start=1):
    # __stdcall Forward(void* v ,char c) ==== _Forward{s}@8
    # __cdecl Forward()   ==== _Forward{s}
    #__fastcall Forward() ==== @Forward{s}@0
    comment=f'#pragma comment(linker, "/EXPORT:{s}=@Forward{s}@0,@{i}")\n'
    declspec=f'extern "C" __declspec(naked) void __fastcall Forward{s}(){{ __asm jmp Origin{s} }}\n'
    stat=f'static PVOID Origin{s};\n'
    forward=f'Origin{s} = GetAddress("{s}");\n'
    pragma.append(comment)
    extern.append(declspec)
    static.append(stat)
    forwards.append(forward)
with open("forward.txt", "w", encoding="utf-8") as f:
    f.write("\n// clang-format off\n")
    for i in pragma:
        f.write(i)
    f.write("// clang-format on\n\n")
    for i in static:
        f.write(i)
    f.write("\n")
    for i in extern:
        f.write(i)
    f.write("\nvoid forward() {\n")
    for i in forwards:
        f.write(i)
    f.write("}")
    