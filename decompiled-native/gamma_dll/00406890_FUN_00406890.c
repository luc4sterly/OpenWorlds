// 00406890 FUN_00406890 [Global]
// program: gamma.dll

undefined4 *
FUN_00406890(undefined4 *param_1,int *param_2,void *param_3,byte param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int local_68;
  byte local_61;
  byte local_60;
  byte abStack_5f [43];
  int local_34 [2];
  undefined1 local_29;
  
  FUN_004049b0(param_3,local_34);
  local_29 = DAT_004890b4;
  piVar1 = (int *)FUN_00404a00(local_34);
  FUN_00404dc0(local_34);
  pbVar3 = &local_60;
  local_68 = 0;
  if ((param_6 == 0 && param_5 == 0) || ((*(ushort *)((int)param_3 + 0x30) & 0x200) != 0)) {
    local_60 = (**(code **)(*piVar1 + 0x14))(0x30);
    pbVar3 = abStack_5f;
    local_68 = 1;
  }
  if (param_6 != 0 || param_5 != 0) {
    iVar2 = FUN_00406d10(param_3,CONCAT44(param_6,param_5),pbVar3);
    local_68 = local_68 + iVar2;
  }
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_61,0,&local_60,local_68);
  return param_1;
}


