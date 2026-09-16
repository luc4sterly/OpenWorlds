// 00406630 FUN_00406630 [Global]
// programa: gamma.dll

undefined4 * FUN_00406630(undefined4 *param_1,int *param_2,void *param_3,byte param_4,uint param_5)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((int)param_3 + 0x30) & 0x4a;
  if (uVar1 == 8) {
    FUN_00405c30(param_1,param_2,param_3,param_4,param_5);
    return param_1;
  }
  if (uVar1 == 0x40) {
    FUN_00405af0(param_1,param_2,param_3,param_4,param_5);
    return param_1;
  }
  FUN_00406970(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}


