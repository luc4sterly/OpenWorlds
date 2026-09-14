// 0044acc0 FUN_0044acc0 [Global]
// programa: gamma.dll

undefined4 __thiscall
FUN_0044acc0(void *this,uint param_1,int *param_2,uint param_3,int param_4,uint param_5,uint param_6
            )

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 0x74);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0x18) == 0) {
    *param_2 = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if ((int)param_1 < 2) {
    *param_2 = 0;
  }
  else {
    uVar2 = FUN_0044b370(param_5,param_6,param_5,param_6,param_1,(int)param_1 >> 0x1f,0,0);
    uVar3 = FUN_00453c30(param_3 - (uint)uVar2,
                         (param_4 - (int)((ulonglong)uVar2 >> 0x20)) - (uint)(param_3 < (uint)uVar2)
                         ,param_1 - 1,(int)(param_1 - 1) >> 0x1f);
    iVar1 = FUN_0044ac50((int)uVar3);
    *param_2 = iVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


