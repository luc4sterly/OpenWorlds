// 00405c30 FUN_00405c30 [Global]
// programa: gamma.dll

undefined4 * FUN_00405c30(undefined4 *param_1,int *param_2,void *param_3,byte param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_4c;
  byte local_47;
  undefined1 local_46;
  byte local_44 [16];
  undefined4 *local_34;
  int *local_30;
  undefined1 local_11;
  
  local_4c = 0;
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
  if ((*(ushort *)((int)param_3 + 0x30) & 0x200) != 0) {
    local_47 = (**(code **)(*piVar1 + 0x14))(0x30);
    if ((*(ushort *)((int)param_3 + 0x30) & 0x4000) == 0) {
      uVar3 = 0x78;
    }
    else {
      uVar3 = 0x58;
    }
    local_46 = (**(code **)(*piVar1 + 0x14))(uVar3);
    local_4c = 2;
  }
  iVar2 = FUN_00405ee0(param_3,param_5,local_44);
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_47,local_4c,local_44,iVar2);
  return param_1;
}


