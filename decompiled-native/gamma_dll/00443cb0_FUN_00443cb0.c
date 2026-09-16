// 00443cb0 FUN_00443cb0 [Global]
// programa: gamma.dll

undefined4 FUN_00443cb0(int *param_1,ushort *param_2,undefined4 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xd];
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*param_1 + 0xb4))();
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      piVar2 = (int *)(**(code **)(*param_1 + 0xb8))(iVar5);
      iVar3 = FUN_0044b300((ushort *)piVar2[5],param_2);
      if (iVar3 == 0) {
        piVar4 = piVar2;
        if (piVar2 != (int *)0x0) {
          piVar4 = piVar2 + 3;
        }
        *param_3 = piVar4;
        (**(code **)(*piVar2 + 0x80))(piVar2);
        LeaveCriticalSection(lpCriticalSection);
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  *param_3 = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0x80040216;
}


