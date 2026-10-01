// 00432515 FUN_00432515 [Global]
// program: sfmain.exe

void __fastcall FUN_00432515(undefined4 param_1,undefined4 param_2)

{
  (*(code *)PTR_FUN_0043e7f0)(param_2,param_1);
  if (DAT_0043ead0 == (HANDLE)0xffffffff) {
    DAT_0043ead0 = CreateFileA(s_conin__00437b84,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                               (HANDLE)0x0);
  }
  if (DAT_0043ead4 == (HANDLE)0xffffffff) {
    DAT_0043ead4 = CreateFileA(s_conout__00437b8b,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                               (HANDLE)0x0);
  }
  (*(code *)PTR_FUN_0043e7f4)();
  return;
}


