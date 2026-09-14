// 0040e680 _Java_NET_worlds_console_Window_getHiddenCursorDelta@8 [Global]
// programa: gamma.dll

int _Java_NET_worlds_console_Window_getHiddenCursorDelta_8(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0xe680  88  _Java_NET_worlds_console_Window_getHiddenCursorDelta@8 */
  iVar1 = (**(code **)(*param_1 + 0x2cc))(param_1,2);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
    puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x2ec))(param_1,iVar1,0);
    *puVar2 = DAT_00489234;
    puVar2[1] = DAT_00489238;
    (**(code **)(*param_1 + 0x30c))(param_1,iVar1,puVar2,0);
    DAT_00489234 = 0;
    DAT_00489238 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
  }
  return iVar1;
}


