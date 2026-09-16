// 00449860 FUN_00449860 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00449860(void *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  MMRESULT MVar8;
  ulonglong uVar9;
  uint uStack_14;
  int iStack_10;
  
  if (((*(int *)((int)param_1 + 0x68) == 0) || (*(int *)((int)param_1 + 0x6c) != 0)) ||
     (*(int *)((int)param_1 + 0xb8) != 0)) {
    return 0;
  }
  piVar1 = *(int **)((int)param_1 + 0x18);
  if (piVar1 == (int *)0x0) {
    uVar6 = FUN_00449930(param_1);
    return uVar6;
  }
  uVar2 = *(uint *)((int)param_1 + 0xb0);
  iVar3 = *(int *)((int)param_1 + 0xb4);
  uVar4 = *(uint *)((int)param_1 + 0x1c);
  uVar7 = uVar2 + *(uint *)((int)param_1 + 0x1c);
  iVar5 = *(int *)((int)param_1 + 0x20);
  (**(code **)(*piVar1 + 0xc))(piVar1,&uStack_14);
  uVar9 = FUN_00453c30(uVar7 - uStack_14,
                       ((iVar3 + iVar5 + (uint)CARRY4(uVar2,uVar4)) - iStack_10) -
                       (uint)(uVar7 < uStack_14),10000,0);
  if ((int)(UINT)uVar9 < 0x32) {
    uVar6 = FUN_00449930(param_1);
    return uVar6;
  }
  MVar8 = timeSetEvent((UINT)uVar9,10,&LAB_004497f0,(DWORD_PTR)param_1,0);
  *(MMRESULT *)((int)param_1 + 0xb8) = MVar8;
  if (*(int *)((int)param_1 + 0xb8) == 0) {
    uVar6 = FUN_00449930(param_1);
    return uVar6;
  }
  return 0;
}


