// 00447b80 FUN_00447b80 [Global]
// programa: gamma.dll

int __thiscall FUN_00447b80(int *param_1,undefined4 param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 7);
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x11] == 1) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7fffbffb;
  }
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,param_2,0,param_1[0xd],param_1[0xe],&DAT_0047801c);
  if ((param_3 != 0) && (-1 < iVar1)) {
    iVar1 = (**(code **)(*param_1 + 0x34))
                      (param_1,param_3,0,param_1[0xf],param_1[0x10],&DAT_0047801c);
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}


