// 0042b9b8 FUN_0042b9b8 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b9b8(void)

{
  uint in_EAX;
  uint uVar1;
  uint extraout_ECX;
  
  if (in_EAX != 0) {
    (*(code *)PTR_FUN_0043e808)();
    uVar1 = DAT_0043e524;
    if (((_DAT_004e57a4 == 0) || (in_EAX < _DAT_004e57a4)) ||
       (*(uint *)(_DAT_004e57a4 + 8) <= in_EAX)) {
      for (; (*(uint *)(uVar1 + 8) != 0 && ((in_EAX < uVar1 || (*(uint *)(uVar1 + 8) <= in_EAX))));
          uVar1 = *(uint *)(uVar1 + 8)) {
      }
    }
    FUN_0042d63a();
    if ((extraout_ECX < DAT_0043e528) && (DAT_0043e52c < *(uint *)(extraout_ECX + 0x14))) {
      DAT_0043e52c = *(uint *)(extraout_ECX + 0x14);
    }
    DAT_004e57b4 = 0;
    _DAT_004e57a4 = extraout_ECX;
    (*(code *)PTR_FUN_0043e810)();
  }
  return;
}


