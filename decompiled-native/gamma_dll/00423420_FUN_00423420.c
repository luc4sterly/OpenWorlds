// 00423420 FUN_00423420 [Global]
// program: gamma.dll

int __cdecl
FUN_00423420(int *param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int local_1c;
  int local_14;
  
  local_14 = 0;
  if (param_3 != (undefined4 *)0x0) {
    iVar1 = 0;
    if (0 < param_4) {
      do {
        if (param_3[iVar1] == 0) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_4);
    }
    if (iVar1 == param_4) {
      local_14 = (**(code **)(*param_1 + 0x2b0))(param_1,param_4,DAT_0049d188,0);
      if ((local_14 != 0) && (local_1c = 0, 0 < param_4)) {
        do {
          iVar1 = FUN_00415a40(param_1,DAT_0049d188,DAT_0049d1bc);
          if (iVar1 != 0) {
            (**(code **)(*param_1 + 0x1b4))(param_1,iVar1,DAT_0049d190,param_3[local_1c]);
            (**(code **)(*param_1 + 0x1b4))(param_1,iVar1,DAT_0049d194,param_5);
            (**(code **)(*param_1 + 0x1b4))(param_1,iVar1,DAT_0049d198,param_6);
            (**(code **)(*param_1 + 0x1b4))(param_1,iVar1,DAT_0049d1a0,local_1c);
            (**(code **)(*param_1 + 0x1a0))(param_1,iVar1,DAT_0049d19c,param_2);
          }
          (**(code **)(*param_1 + 0x2b8))(param_1,local_14,local_1c,iVar1);
          local_1c = local_1c + 1;
        } while (local_1c < param_4);
      }
    }
    else {
      iVar1 = 0;
      if (0 < param_4) {
        do {
          FUN_00421690(param_3[iVar1]);
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_4);
      }
    }
    FUN_00451780(param_3);
  }
  return local_14;
}


