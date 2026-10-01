// 00455230 FUN_00455230 [Global]
// program: gamma.dll

int __cdecl FUN_00455230(int param_1)

{
  char cVar1;
  char *pcVar2;
  LPVOID pvVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  iVar6 = 0;
  if (((byte)(((byte)(*(ushort *)(param_1 + 4) >> 7) & 7) - 1) < 2) &&
     (*(char *)(param_1 + 0xd) == '\0')) {
    bVar5 = *(byte *)(param_1 + 8) & 7;
    if (bVar5 == 0) {
      return *(int *)(param_1 + 0x1c);
    }
    iVar7 = *(int *)(param_1 + 0x28) - (int)*(char **)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x38) + iVar7;
    if (2 < bVar5) {
      iVar6 = bVar5 - 2;
      iVar4 = iVar4 - iVar6;
    }
    if ((*(byte *)(param_1 + 5) >> 4 & 1) == 0) {
      iVar7 = iVar7 - iVar6;
      pcVar2 = *(char **)(param_1 + 0x20);
      while (iVar7 != 0) {
        iVar7 = iVar7 + -1;
        pcVar8 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar8;
        if (cVar1 == '\n') {
          iVar4 = iVar4 + 1;
        }
      }
    }
    return iVar4;
  }
  pvVar3 = FUN_00453ed0();
  *(undefined4 *)((int)pvVar3 + 4) = 0x23;
  return -1;
}


