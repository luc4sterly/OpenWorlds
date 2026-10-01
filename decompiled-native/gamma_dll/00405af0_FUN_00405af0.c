// 00405af0 FUN_00405af0 [Global]
// program: gamma.dll

undefined4 * FUN_00405af0(undefined4 *param_1,int *param_2,void *param_3,byte param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int local_58;
  byte local_4d;
  byte local_4c;
  byte abStack_4b [23];
  undefined4 *local_34;
  int *local_30;
  undefined1 local_11;
  
  FUN_004049b0(param_3,&local_34);
  local_11 = DAT_004890b4;
  piVar1 = (int *)FUN_00404a00((int *)&local_34);
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
    if (local_34 != (undefined4 *)0x0) {
      FUN_00404e60((int)local_34);
      FUN_0044e100(local_34);
    }
    FUN_0044e100(local_30);
  }
  pbVar3 = &local_4c;
  local_58 = 0;
  if ((param_5 == 0) || ((*(ushort *)((int)param_3 + 0x30) & 0x200) != 0)) {
    local_4c = (**(code **)(*piVar1 + 0x14))(0x30);
    pbVar3 = abStack_4b;
    local_58 = 1;
  }
  if (param_5 != 0) {
    iVar2 = FUN_00405ee0(param_3,param_5,pbVar3);
    local_58 = local_58 + iVar2;
  }
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_4d,0,&local_4c,local_58);
  return param_1;
}


