// 004066b0 FUN_004066b0 [Global]
// program: gamma.dll

undefined4 *
FUN_004066b0(undefined4 *param_1,int *param_2,void *param_3,byte param_4,int param_5,int param_6)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((int)param_3 + 0x30) & 0x4a;
  if (uVar1 == 8) {
    FUN_00406c20(param_1,param_2,param_3,param_4,param_5,param_6);
    return param_1;
  }
  if (uVar1 == 0x40) {
    FUN_00406890(param_1,param_2,param_3,param_4,param_5,param_6);
    return param_1;
  }
  FUN_00406a80(param_1,param_2,param_3,param_4,param_5,param_6);
  return param_1;
}


