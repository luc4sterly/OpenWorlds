// 00406970 FUN_00406970 [Global]
// programa: gamma.dll

undefined4 * FUN_00406970(undefined4 *param_1,int *param_2,void *param_3,byte param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  int local_78;
  byte local_6d;
  byte local_6c [20];
  int local_58 [2];
  int local_50 [2];
  undefined1 local_45;
  undefined1 local_29;
  
  local_78 = 0;
  if (((int)param_5 < 0) || ((*(ushort *)((int)param_3 + 0x30) & 0x800) == 0)) {
    if ((int)param_5 < 0) {
      local_78 = 1;
      FUN_004049b0(param_3,local_50);
      local_29 = DAT_004890b4;
      piVar1 = (int *)FUN_00404a00(local_50);
      local_6d = (**(code **)(*piVar1 + 0x14))(0x2d);
      FUN_00404dc0(local_50);
      param_5 = -param_5;
    }
  }
  else {
    FUN_004049b0(param_3,local_58);
    local_45 = DAT_004890b4;
    piVar1 = (int *)FUN_00404a00(local_58);
    local_6d = (**(code **)(*piVar1 + 0x14))(0x2b);
    FUN_00404dc0(local_58);
    local_78 = 1;
  }
  iVar2 = FUN_00405ee0(param_3,param_5,local_6c);
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_6d,local_78,local_6c,iVar2);
  return param_1;
}


