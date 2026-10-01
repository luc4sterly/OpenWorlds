// 004039d7 FUN_004039d7 [Global]
// program: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_004039d7(PCNZWCH param_1,LPCWSTR param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  if (DAT_0040bbc0 == 0) {
    uVar1 = FUN_004066c9((ushort *)param_1,(ushort *)param_2,param_3);
    return uVar1;
  }
  iVar2 = FUN_004064ae(DAT_0040bbc0,0x1001,param_1,param_3,param_2,param_3,DAT_0040bbd8);
  if (iVar2 == 0) {
    _DAT_0040ba38 = 0x16;
    return 0x7fffffff;
  }
  return iVar2 - 2;
}


