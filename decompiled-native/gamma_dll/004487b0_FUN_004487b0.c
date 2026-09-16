// 004487b0 FUN_004487b0 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_004487b0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  undefined4 uVar2;
  uint *this;
  int iVar3;
  int iStack_14;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1d);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = (int *)param_1[0x12];
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc4))(piVar1,param_2,param_3);
    LeaveCriticalSection(lpCriticalSection);
    return uVar2;
  }
  iStack_14 = 0;
  this = FUN_0044e010(0x48);
  if (this != (uint *)0x0) {
    iVar3 = (**(code **)(*param_1 + 0xb8))(0);
    if (iVar3 != 0) {
      iVar3 = iVar3 + 0xc;
    }
    FUN_004479d0(this,0,(undefined4 *)param_1[1],&iStack_14,iVar3);
  }
  param_1[0x12] = (int)this;
  piVar1 = (int *)param_1[0x12];
  if (piVar1 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0x8007000e;
  }
  if (iStack_14 < 0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xf4))(1);
    }
    param_1[0x12] = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0x80004002;
  }
  uVar2 = (**(code **)(*param_1 + 200))(param_2,param_3);
  LeaveCriticalSection(lpCriticalSection);
  return uVar2;
}


