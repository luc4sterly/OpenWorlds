// 0044dd00 FUN_0044dd00 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0044dd00(LPCSTR param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  DWORD dwShareMode;
  HANDLE pvVar3;
  DWORD dwCreationDisposition;
  uint uVar4;
  DWORD dwDesiredAccess;
  
  uVar4 = param_2 & 2;
  if ((char)(((param_2 & 1) != 0) + (uVar4 != 0) + ((param_2 & 4) != 0)) != '\x01') {
    return -1;
  }
  if ((uVar4 != 0) && ((param_2 & 0x800) != 0)) {
    return -1;
  }
  if (((param_2 & 0x400) != 0) && ((param_2 & 0x200) == 0)) {
    return -1;
  }
  iVar1 = FUN_004588d0();
  if (iVar1 == -1) {
    return -1;
  }
  puVar2 = FUN_00454a10(8);
  (&DAT_0049f448)[iVar1] = puVar2;
  if ((&DAT_0049f448)[iVar1] == 0) {
    return -1;
  }
  *(bool *)((&DAT_0049f448)[iVar1] + 4) = (param_2 & 0x8000) == 0;
  *(undefined1 *)((&DAT_0049f448)[iVar1] + 5) = 0;
  dwShareMode = 0;
  if (uVar4 == 0) {
    if ((param_2 & 4) == 0) {
      dwDesiredAccess = 0xc0000000;
    }
    else {
      dwDesiredAccess = 0x40000000;
    }
  }
  else {
    dwShareMode = 1;
    dwDesiredAccess = 0x80000000;
  }
  if ((param_2 & 0x200) == 0) {
    if ((param_2 & 0x800) == 0) {
      dwCreationDisposition = 3;
    }
    else {
      dwCreationDisposition = 5;
    }
  }
  else {
    dwCreationDisposition = 4;
    if ((param_2 & 0x800) != 0) {
      dwCreationDisposition = 2;
    }
    if ((param_2 & 0x400) != 0) {
      dwCreationDisposition = 1;
    }
  }
  pvVar3 = CreateFileA(param_1,dwDesiredAccess,dwShareMode,(LPSECURITY_ATTRIBUTES)0x0,
                       dwCreationDisposition,0,(HANDLE)0x0);
  *(HANDLE *)(&DAT_0049f448)[iVar1] = pvVar3;
  if (*(int *)(&DAT_0049f448)[iVar1] != -1) {
    if ((param_2 & 0x100) != 0) {
      FUN_0044da60(iVar1,0,2);
      *(undefined1 *)((&DAT_0049f448)[iVar1] + 5) = 1;
    }
    return iVar1;
  }
  FUN_00454a60((int *)(&DAT_0049f448)[iVar1]);
  (&DAT_0049f448)[iVar1] = 0;
  _DAT_0049ff4c = GetLastError();
  return -1;
}


