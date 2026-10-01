// 0040dc70 _Java_NET_worlds_console_Window_dispose@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_dispose_8(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint extraout_EDX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  int local_18;
  uint local_14;
  
                    /* 0xdc70  78  _Java_NET_worlds_console_Window_dispose@8 */
  uVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_004891ac);
  uVar2 = (uint)((ulonglong)uVar5 >> 0x20);
  puVar1 = (undefined4 *)uVar5;
  if (DAT_0049ff1c == puVar1) {
    DAT_00489274 = DAT_00489278;
    if (DAT_00489278 != 0) {
      SendMessageA((HWND)*puVar1,0x8065,0,0);
      uVar2 = extraout_EDX;
    }
    local_14 = 0;
    local_18 = 0;
    do {
      uVar3 = *(uint *)(&DAT_0048927c + local_18 * 4);
      for (uVar4 = local_14; (int)uVar4 < (int)(local_14 + 0x20); uVar4 = uVar4 + 1) {
        if ((uVar3 & 1) != 0) {
          lVar6 = FUN_0040c440(puVar1,uVar2,0x101,uVar4,0);
          uVar2 = (uint)((ulonglong)lVar6 >> 0x20);
        }
        uVar3 = uVar3 >> 1;
      }
      local_18 = local_18 + 1;
      local_14 = local_14 + 0x20;
    } while (local_18 < 8);
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0040f4a0((int)puVar1);
    FUN_0044e100(puVar1);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_004891ac,0);
  return;
}


