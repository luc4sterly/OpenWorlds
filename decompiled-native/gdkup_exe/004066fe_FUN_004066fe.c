// 004066fe FUN_004066fe [Global]
// program: gdkup.exe

void __fastcall FUN_004066fe(undefined4 param_1,undefined4 param_2)

{
  (*(code *)PTR_FUN_00408b3c)(param_2,param_1);
  if (DAT_00408f2c == (HANDLE)0xffffffff) {
    DAT_00408f2c = CreateFileA(s_conin__004087dc,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                               (HANDLE)0x0);
  }
  if (DAT_00408f30 == (HANDLE)0xffffffff) {
    DAT_00408f30 = CreateFileA(s_conout__004087e3,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                               (HANDLE)0x0);
  }
  (*(code *)PTR_FUN_00408b40)();
  return;
}


