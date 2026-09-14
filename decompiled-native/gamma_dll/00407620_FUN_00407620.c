// 00407620 FUN_00407620 [Global]
// programa: gamma.dll

void FUN_00407620(void *param_1,int param_2,uint param_3,int *param_4)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_3c [2];
  int local_34;
  uint local_30;
  undefined1 local_29;
  
  FUN_004049b0(param_1,local_3c);
  local_29 = DAT_004890b4;
  piVar2 = (int *)FUN_00404a00(local_3c);
  FUN_00404dc0(local_3c);
  local_34 = param_2;
  local_30 = param_3;
  if ((param_3 & 0x7ff00000) == 0) {
    if (((param_3 & 0xfffff) == 0) && (param_2 == 0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = 5;
    }
  }
  else if ((param_3 & 0x7ff00000) == 0x7ff00000) {
    if (((param_3 & 0xfffff) == 0) && (param_2 == 0)) {
      iVar3 = 2;
    }
    else {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 4;
  }
  if (iVar3 == 1) {
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x6e);
    FUN_00408b00(param_4,1,uVar1);
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x61);
    FUN_004095f0(param_4,1,uVar1);
    uVar4 = 0x6e;
  }
  else {
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x69);
    FUN_00408b00(param_4,1,uVar1);
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x6e);
    FUN_004095f0(param_4,1,uVar1);
    uVar4 = 0x66;
  }
  uVar1 = (**(code **)(*piVar2 + 0x14))(uVar4);
  FUN_004095f0(param_4,1,uVar1);
  if ((*(ushort *)((int)param_1 + 0x30) & 0x4000) != 0) {
    iVar3 = FUN_004089f0(param_4);
    uVar4 = FUN_004088e0(param_4);
    (**(code **)(*piVar2 + 8))(uVar4,iVar3);
  }
  return;
}


