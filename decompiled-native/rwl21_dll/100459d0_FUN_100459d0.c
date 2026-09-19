// 100459d0 FUN_100459d0 [Global]
// programa: RWL21.DLL

undefined4 __cdecl FUN_100459d0(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  int *piVar2;
  ulong *puVar3;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
    return 0xffffffff;
  }
  if (((DVar1 & 1) != 0) && ((param_2 & 2) != 0)) {
    piVar2 = FUN_100490e0();
    *piVar2 = 0xd;
    puVar3 = FUN_100490f0();
    *puVar3 = 5;
    return 0xffffffff;
  }
  return 0;
}


