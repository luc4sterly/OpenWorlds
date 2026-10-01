// 004032aa FUN_004032aa [Global]
// program: run.exe

undefined4 __cdecl FUN_004032aa(int param_1)

{
  undefined **ppuVar1;
  
  DAT_0040ce60 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_0040ce60 != (HANDLE)0x0) {
    DAT_0040ce64 = FUN_00403162();
    if (DAT_0040ce64 == 3) {
      ppuVar1 = (undefined **)FUN_00403bc9(0x3f8);
    }
    else {
      if (DAT_0040ce64 != 2) {
        return 1;
      }
      ppuVar1 = FUN_00404710();
    }
    if (ppuVar1 != (undefined **)0x0) {
      return 1;
    }
    HeapDestroy(DAT_0040ce60);
  }
  return 0;
}


