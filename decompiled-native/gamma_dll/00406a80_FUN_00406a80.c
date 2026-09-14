// 00406a80 FUN_00406a80 [Global]
// programa: gamma.dll

undefined4 *
FUN_00406a80(undefined4 *param_1,int *param_2,void *param_3,byte param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int local_88;
  byte local_81;
  byte local_80 [40];
  int local_58 [2];
  int local_50 [2];
  undefined1 local_45;
  undefined1 local_29;
  
  local_88 = 0;
  iVar2 = param_6;
  if (param_6 == 0) {
    iVar2 = param_5;
  }
  if ((iVar2 < 0) || ((*(ushort *)((int)param_3 + 0x30) & 0x800) == 0)) {
    if ((param_6 != 0) && (param_6 < 0)) {
      local_88 = 1;
      FUN_004049b0(param_3,local_50);
      local_29 = DAT_004890b4;
      piVar1 = (int *)FUN_00404a00(local_50);
      local_81 = (**(code **)(*piVar1 + 0x14))(0x2d);
      FUN_00404dc0(local_50);
      bVar3 = param_5 != 0;
      param_5 = -param_5;
      param_6 = -(param_6 + (uint)bVar3);
    }
  }
  else {
    FUN_004049b0(param_3,local_58);
    local_45 = DAT_004890b4;
    piVar1 = (int *)FUN_00404a00(local_58);
    local_81 = (**(code **)(*piVar1 + 0x14))(0x2b);
    FUN_00404dc0(local_58);
    local_88 = 1;
  }
  iVar2 = FUN_00406d10(param_3,CONCAT44(param_6,param_5),local_80);
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_81,local_88,local_80,iVar2);
  return param_1;
}


