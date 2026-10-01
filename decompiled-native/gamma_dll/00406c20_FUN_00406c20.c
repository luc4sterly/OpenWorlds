// 00406c20 FUN_00406c20 [Global]
// program: gamma.dll

undefined4 *
FUN_00406c20(undefined4 *param_1,int *param_2,void *param_3,byte param_4,undefined4 param_5,
            undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_5c;
  byte local_57;
  undefined1 local_56;
  byte local_54 [32];
  int local_34 [2];
  undefined1 local_29;
  
  local_5c = 0;
  FUN_004049b0(param_3,local_34);
  local_29 = DAT_004890b4;
  piVar1 = (int *)FUN_00404a00(local_34);
  FUN_00404dc0(local_34);
  if ((*(ushort *)((int)param_3 + 0x30) & 0x200) != 0) {
    local_57 = (**(code **)(*piVar1 + 0x14))(0x30);
    if ((*(ushort *)((int)param_3 + 0x30) & 0x4000) == 0) {
      uVar3 = 0x78;
    }
    else {
      uVar3 = 0x58;
    }
    local_56 = (**(code **)(*piVar1 + 0x14))(uVar3);
    local_5c = 2;
  }
  iVar2 = FUN_00406d10(param_3,CONCAT44(param_6,param_5),local_54);
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_57,local_5c,local_54,iVar2);
  return param_1;
}


