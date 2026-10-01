// 0041e2f0 FUN_0041e2f0 [Global]
// program: gamma.dll

undefined * __cdecl FUN_0041e2f0(int *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_004508c0(param_2,&DAT_0049cef0);
  if (iVar1 == 0) {
    DAT_0048966c = 0;
    *param_3 = DAT_0049cfb8;
    return &DAT_00489670;
  }
  iVar1 = FUN_004508c0(param_2,&DAT_0049cf54);
  if (iVar1 == 0) {
    DAT_0048966c = 1;
    *param_3 = DAT_0049cfbc;
    return &DAT_004932b0;
  }
  iVar1 = FUN_00403fc0(param_1,param_2);
  if (iVar1 == 0) {
    return (undefined *)0x0;
  }
  uVar2 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar1);
  if (40000 < (int)uVar2) {
    return (undefined *)0x0;
  }
  iVar3 = 1 - DAT_0048966c;
  DAT_0048966c = iVar3;
  (&DAT_0049cfb8)[iVar3] = uVar2;
  FUN_0044d6b0(&DAT_0049cef0 + iVar3 * 100,(char *)param_2);
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x2e0))(param_1,iVar1,0);
  FUN_0044df50((undefined4 *)(&DAT_00489670 + DAT_0048966c * 40000),puVar4,uVar2);
  (**(code **)(*param_1 + 0x300))(param_1,iVar1,puVar4,0);
  *param_3 = uVar2;
  return &DAT_00489670 + DAT_0048966c * 40000;
}


