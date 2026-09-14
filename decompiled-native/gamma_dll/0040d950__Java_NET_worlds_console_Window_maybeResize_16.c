// 0040d950 _Java_NET_worlds_console_Window_maybeResize@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Window_maybeResize_16
               (int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
                    /* 0xd950  102  _Java_NET_worlds_console_Window_maybeResize@16 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_004891ac);
  if (param_3 < 2) {
    param_3 = 1;
  }
  if (param_4 < 2) {
    param_4 = 1;
  }
  uVar2 = param_3 + 3U & 0xfffffffc;
  if ((uVar2 != *(uint *)(iVar1 + 0x1c)) || (param_4 != *(int *)(iVar1 + 0x20))) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));
    *(uint *)(iVar1 + 0x1c) = uVar2;
    *(int *)(iVar1 + 0x20) = param_4;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));
  }
  return;
}


