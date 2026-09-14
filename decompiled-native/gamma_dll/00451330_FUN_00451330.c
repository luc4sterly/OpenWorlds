// 00451330 FUN_00451330 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00451330(char *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  
  iVar2 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_2 + 2) <= iVar2) {
      return 0;
    }
    uVar1 = FUN_00458cc0(param_1,*(char **)(param_2 + 0xc + iVar2 * 4),&local_14);
    if ((char)uVar1 != '\0') break;
    iVar2 = iVar2 + 1;
  }
  return 1;
}


