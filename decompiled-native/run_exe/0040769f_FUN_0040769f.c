// 0040769f FUN_0040769f [Global]
// programa: run.exe

uint __cdecl FUN_0040769f(uint param_1)

{
  WCHAR WVar1;
  uint uVar2;
  size_t sVar3;
  undefined2 uVar4;
  WCHAR local_6;
  
  WVar1 = (WCHAR)param_1;
  if (WVar1 == L'\xffff') {
    return param_1;
  }
  if (DAT_0040bbc4 == 0) {
    if ((0x40 < (ushort)WVar1) && ((ushort)WVar1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((ushort)WVar1 < 0x100) {
      uVar2 = FUN_004079c3(WVar1,1);
      if (uVar2 == 0) {
        return param_1 & 0xffff;
      }
    }
    sVar3 = FUN_0040778a(DAT_0040bbc4,0x100,(LPCWSTR)&param_1,1,&local_6,1,0);
    uVar4 = (undefined2)(sVar3 >> 0x10);
    param_1 = CONCAT22(uVar4,(undefined2)param_1);
    if (sVar3 != 0) {
      param_1 = CONCAT22(uVar4,local_6);
    }
  }
  return param_1;
}


