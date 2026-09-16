// 00459260 FUN_00459260 [Global]
// programa: gamma.dll

bool FUN_00459260(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_0044da00(param_1);
  if (iVar2 == -1) {
    return true;
  }
  if (param_1 != 0) {
    piVar3 = FUN_004590e0(param_1);
    if (piVar3 != (int *)0x0) {
      bVar1 = FUN_004592c0((LPCSTR)piVar3[1]);
      FUN_00454a60((undefined4 *)piVar3[1]);
      *piVar3 = 0;
      return bVar1;
    }
  }
  return false;
}


