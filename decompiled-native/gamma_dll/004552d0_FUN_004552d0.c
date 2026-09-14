// 004552d0 FUN_004552d0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004552d0(undefined4 *param_1,int param_2,int param_3)

{
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3;
  if ((((byte)(*(ushort *)(param_1 + 1) >> 7) & 7) == 1) && (*(char *)((int)param_1 + 0xd) == '\0'))
  {
    if ((*(byte *)(param_1 + 2) & 7) == 1) {
      iVar2 = FUN_004593d0(param_1,(undefined4 *)0x0);
      if (iVar2 != 0) {
        *(undefined1 *)((int)param_1 + 0xd) = 1;
        param_1[0xb] = 0;
        pvVar1 = FUN_00453ed0();
        *(undefined4 *)((int)pvVar1 + 4) = 0x23;
        return 0xffffffff;
      }
    }
    if (iVar3 == 1) {
      iVar3 = 0;
      iVar2 = FUN_00455230((int)param_1);
      param_2 = param_2 + iVar2;
    }
    if ((code *)param_1[0xf] != (code *)0x0) {
      iVar3 = (*(code *)param_1[0xf])(*param_1,&param_2,iVar3,param_1[0x13]);
      if (iVar3 != 0) {
        *(undefined1 *)((int)param_1 + 0xd) = 1;
        param_1[0xb] = 0;
        pvVar1 = FUN_00453ed0();
        *(undefined4 *)((int)pvVar1 + 4) = 0x23;
        return 0xffffffff;
      }
    }
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8;
    *(undefined1 *)(param_1 + 3) = 0;
    param_1[7] = param_2;
    param_1[0xb] = 0;
    return 0;
  }
  pvVar1 = FUN_00453ed0();
  *(undefined4 *)((int)pvVar1 + 4) = 0x23;
  return 0xffffffff;
}


