// 00401750 _Java_NET_worlds_core_FastDataInput_close@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_FastDataInput_close_8(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
                    /* 0x1750  119  _Java_NET_worlds_core_FastDataInput_close@8 */
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1[1] != 0) {
      GlobalUnlock((HGLOBAL)*puVar1);
    }
    if ((HGLOBAL)*puVar1 != (HGLOBAL)0x0) {
      GlobalFree((HGLOBAL)*puVar1);
    }
    FUN_0044e100(puVar1);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489024,0);
  return;
}


